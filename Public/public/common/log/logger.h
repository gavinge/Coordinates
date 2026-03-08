

#ifndef CFLEXIBLE_LOG_H_
#define CFLEXIBLE_LOG_H_
#include <string>
#include <fstream>
#include <sstream>

#include <filesystem>
#include <thread>
#include <mutex>

#ifdef WIN32
#include <windows.h>
#include <io.h>
#define  access _access
#else
#include <unistd.h>
#endif

namespace log_utils {
// 最大滚存日志数量
static const int krotating_files = 2;
// 写入文件数据大小阀值
static const unsigned long long kmax_file_size_ = 10 * 1024 * 1024;
// 最大写入大小门限，防错处理，避免文件无限增大
static const unsigned long long kfile_max_size_guard = 50 * 1024 * 1024;
// 清空文件重试次数
static const int kopen_tries = 5;
// 清空文件重试间隔, ms
static const unsigned int kopen_interval = 10;
// 命名失败重试间隔
static const unsigned int krename_retry_interval = 100;

class logger
{
public:
    logger() : name_(std::string()), file_size_(0){};
    virtual ~logger() {
        if (ofs_.is_open()) {
            ofs_.close();
        }
    };

public:
    // 初始化
    bool init(const std::string& file_name)
    {
        std::lock_guard<std::mutex> lck(mtx_);
        bool result = false;
        name_ = file_name;
        do {
            if (name_.empty()) {
                break;
            }

            if (access(name_.c_str(), 0) == 0) {
                // 存在文件，获取文件大小
                try
                {
					file_size_ = std::experimental::filesystem::file_size(name_);
                } catch (...) {
                    // 获取文件大小失败的情况下，就不要往日志文件里面写了，避免文件无限增大的风险
                    break;
                }
            }

            // 打开文件
            ofs_.open(name_.c_str(), std::ios::app);
            result = ofs_.is_open();
        } while (false);
        return result;
    }

    // 记录日志
    void write_log(const std::string& msg)
    {
        std::lock_guard<std::mutex> lck(mtx_);
        if (!ofs_.is_open()) {
            return;
        }
        // 容错
        if (file_size_ > kfile_max_size_guard) {
            return;
        }
        file_size_ += msg.size();
        ofs_ << msg << std::endl;
        if (file_size_ >= kmax_file_size_) {
            ofs_.flush();
            // 滚存成功， 如果这个地方一直不成功(什么情况会这样？ 被独占?)，则file_size_会一直增加，最终走到容错
            if (rotating()) {
                file_size_ = 0;
            }
        }
    }

private:
    // 滚存
    bool rotating()
    {
        ofs_.close();
        sleep_for_millis(krename_retry_interval);
        for (int i = krotating_files; i > 0; --i) {
            std::ostringstream oss_src_file_name;
            if ((i - 1) > 0) {
                oss_src_file_name << name_ << "." << (i - 1);
            } else {
                oss_src_file_name << name_;
            }
            if (access(oss_src_file_name.str().c_str(), 0) == -1) {
                continue;
            }
            std::ostringstream oss_dst_file_name;
            oss_dst_file_name << name_ << "." << i;
            if (0 != rename_file(oss_src_file_name.str(), oss_dst_file_name.str())) {
                // 失败重试
                sleep_for_millis(krename_retry_interval);
                if (0 != rename_file(oss_src_file_name.str(), oss_dst_file_name.str())) {
                    // 清空文件，避免文件无限制的增长
                    truncate();
                    file_size_ = 0;
                }
            }
        }
        // 重新打开文件
        ofs_.open(name_.c_str(), std::ios::trunc);
        return ofs_.is_open();
    }

    // 清空文件
    void truncate()
    {
        for (int tries = 0; tries < kopen_tries; ++tries) {
#ifdef WIN32
            FILE* fp = ::_fsopen((name_.c_str()), "wb", _SH_DENYNO);
#else // unix
            FILE* fp = ::fopen((name_.c_str()), "wb");
#endif
            if (NULL != fp) {
                fclose(fp);
            }
            sleep_for_millis(kopen_interval);
        }
    }

    // 文件重命名
    int rename_file(const std::string& src_name, const std::string& dst_name)
    {
        (void)std::remove(dst_name.c_str());
        return std::rename(src_name.c_str(), dst_name.c_str());
    }

    // sleep ms
    void sleep_for_millis(unsigned int milliseconds)
    {
#ifdef WIN32
        Sleep(milliseconds);
#elif linux
        usleep(milliseconds * 1000);
#endif // WIN32
    }

private:
    // 文件名
    std::string name_;
    // 文件操作对象
    std::ofstream ofs_;
    // 文件操作锁
    std::mutex mtx_;
    // 写入文件大小
    unsigned long long file_size_;
};
};

#endif

