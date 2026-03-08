
#ifndef LOGGER_HELPER_H__
#define LOGGER_HELPER_H__


#include <string>
#include <sstream>
#include <map>
#include <algorithm>
#include <memory>

//#include "boost\thread.hpp"
//#include "boost\atomic.hpp"
//#include "boost\filesystem.hpp"
//#include "boost\shared_ptr.hpp"
//#include "boost\make_shared.hpp"

#include <thread>
#include <atomic>
#include <filesystem>


//#include "xml\xml_self.h"
#include "logger.h"

#ifdef WIN32
#include <Windows.h>
#include <time.h>
#include "win_tools\win_tools.hpp"
#else
#include <unistd.h>
#include <pthread.h>
#include <sys/syscall.h>
#include "publib/utility/unix_tools.h"
#define YUNSUO_INSTALL_PATH utility::CUnixTools::get_yunsuo_path()
#endif

#define B2S(v) ((v) ? "true" : "false")

// 禁止编译到静态库里面，避免被链接出去
#ifdef DISABLE_COMPLIE_CUSTOM_LOG
#error "Static library, cannot use logger_helper.h"
#endif

 /**
  * @desc:               日志打印类，禁止导出，每个动态库独立使用，会在每个动态库生成独立的实例
  * @                    在每个动态库 先调用REGISTER_LOGGER(log_dir, file_name)注册
  * @                    使用LOGGER_DEBUG LOGGER_INFO LOGGER_WARN LOGGER_ERROR 输出日志信息
  * @                    Sample:
  * @                    REGISTER_LOGGER("asset", "app_identify.log");
  * @                    LOGGER_DEBUG("this is asset log" << "Jowto");
  **/
template <class T>
#ifdef WIN32
class LoggerHelper {
#else
class __attribute__((visibility("hidden"))) LoggerHelper {
#endif // !WIN32
public:
    /**
     * @desc:               获取日志操作对象实例，每个动态库一个实例，禁止导出
     * @return:             日志操作对象实例地址
     **/
    static LoggerHelper* get_instance();

    /**
     * @desc:               初始化日志文件
     * @dir:                相对于runlog的目录名字，比如在runlog下建一个asset目录，则传入asset, 可传多级目录
     * @file_name:          输出的日志文件的名字
     * @return:             初始化结果true:成 false:失败
     **/
    bool init(const std::string& dir, const std::string& file_name);

    /**
     * @desc:               初始化日志文件
     * @dir:                用户自定义日志输出目录
     * @file_name:          输出的日志文件的名字
     * @return:             初始化结果true:成 false:失败
     **/
    bool init_v2(const std::string& dir, const std::string& file_name);

    /**
     * @desc:               日志开关是否打开，每隔5min刷新一次，避免停机开日志导致场景丢失
     * @return:             true:打开 false:关闭
     **/
    bool is_debug_on();

    /**
     * @desc:               日志类初始化结果
     * @return:             初始化结果true:成 false:失败
     **/
    bool is_inited();

    /**
     * @desc:               输出日志使用
     * @info:               要输出的日志信息
     * @return:             void
     **/
    void log(const std::string& info);

    /**
     * @desc:               获取当前cpp文件名字
     * @full_path:          __FILE__
     * @return:             当前cpp文件名字
     **/
    std::string get_file_name(const std::string& full_path);

    /**
     * @desc:               获取当前进程PID
     * @return:             当前进程PID
     **/
    uint64_t get_current_proc_pid();

    /**
     * @desc:               获取当前时间字符串，精确到毫秒
     * @return:             当前时间字符串
     **/
    std::string get_current_time_with_milliseconds();

    /**
     * @desc:               获取当前线程ID
     * @return:             当前线程ID(linux 为0)
     **/
    uint64_t get_thread_id();

    /**
     * @desc:               获取当前进程名
     * @return:             当前进程名
     **/
    std::string get_current_proc_name();

private:

    LoggerHelper();
    virtual ~LoggerHelper();

    /**
     * @desc:               禁止拷贝构造
     **/
    LoggerHelper(const LoggerHelper &obj) {}

    /**
     * @desc:               禁止赋值
     **/
    LoggerHelper& operator = (const LoggerHelper& other) {}

    /**
     * @desc:               根据当前进程映射日志文件头，防止多个进程访问同一个文件
     **/
    std::string mapping_log_prefix(std::string& current_proc_name);

public:
    /**
     * @desc:               debug开关是否打开
     **/
    bool debug_;

    /**
     * @desc:               标记是否初始化成功
     **/
    std::atomic_bool inited_;

    /**
     * @desc:               进程pid
     **/
    uint64_t pid_;

    /**
     * @desc:               日志操作对象
     **/
    T logger_;

    /**
     * @desc:               日志文件对象
     **/
    std::map<std::string, std::string>  map_log_files_;

    /**
     * @desc:               日志对象创建锁
     **/
    static std::mutex log_instance_mtx_;

    /**
     * @desc:               日志对象实例地址
     **/
    static LoggerHelper* log_instance_;
};

template <class T>
std::mutex LoggerHelper<T>::log_instance_mtx_;

template <class T>
LoggerHelper<T>* LoggerHelper<T>::log_instance_ = NULL;

template <class T>
LoggerHelper<T>::LoggerHelper(): debug_(false), pid_(0)
{
    inited_.store(false);
#ifndef WIN32
#else
    map_log_files_.insert(std::make_pair<std::string, std::string>("cseeserver.exe", "seeserver_"));
    map_log_files_.insert(std::make_pair<std::string, std::string>("cseeserverd.exe", "seeserverd_"));
#endif // !WIN32
}

template <class T>
LoggerHelper<T>::~LoggerHelper()
{
    std::lock_guard<std::mutex> lck(LoggerHelper<T>::log_instance_mtx_);
    if (NULL != LoggerHelper<T>::log_instance_) {
        delete LoggerHelper<T>::log_instance_;
        LoggerHelper<T>::log_instance_ = NULL;
    }
}

template <class T>
LoggerHelper<T>* LoggerHelper<T>::get_instance()
{
    if (NULL == LoggerHelper<T>::log_instance_) {
        std::lock_guard<std::mutex> lck(LoggerHelper<T>::log_instance_mtx_);
        if (NULL == LoggerHelper<T>::log_instance_) {
            LoggerHelper<T>::log_instance_ = new (std::nothrow) LoggerHelper();
        }
    }
    return LoggerHelper<T>::log_instance_;
}

template <class T>
bool LoggerHelper<T>::init(const std::string& dir, const std::string& file_name)
{
    std::lock_guard<std::mutex> lck(LoggerHelper<T>::log_instance_mtx_);
    if (inited_.load()) {
        return true;
    }

#ifdef WIN32
    pid_ = static_cast<uint64_t>(GetCurrentProcessId());
#else
    pid_ = static_cast<uint64_t>(getpid());
#endif

    // 获取输出日志前缀，避免多个进程使用同一个动态库，写入同一个文件
    std::string current_proc_name = get_current_proc_name();
    std::transform(current_proc_name.begin(), current_proc_name.end(), current_proc_name.begin(), ::tolower);
    std::string log_prefix = mapping_log_prefix(current_proc_name);
    if (log_prefix.empty()) {
        return false;
    }

    std::string yunsuo_install_path = YUNSUO_INSTALL_PATH;
    if (yunsuo_install_path.empty()) {
        return false;
    }

    // 创建日志输出目录
    std::string asset_run_log_output_dir = yunsuo_install_path + "/runlog/" + dir;
    try {
        (void)std::filesystem::create_directories(asset_run_log_output_dir.c_str());
        if (!std::filesystem::exists(asset_run_log_output_dir.c_str())) {
            return false;
        }
    } catch (...) {
        return false;
    }

    // 初始化日志对象
    std::string log_file_name = log_prefix + file_name;
    if (!logger_.init((asset_run_log_output_dir + "/" + log_file_name))) {
        return false;
    }
    inited_.store(true);
    return true;
}

template <class T>
bool LoggerHelper<T>::init_v2(const std::string& dir, const std::string& file_name)
{
    std::lock_guard<std::mutex> lck(LoggerHelper<T>::log_instance_mtx_);
    if (inited_.load()) {
        return true;
    }

    std::string log_out_put_dir = dir;
#ifdef WIN32
    pid_ = static_cast<uint64_t>(GetCurrentProcessId());
#else
    pid_ = static_cast<uint64_t>(getpid());
#endif

    size_t dir_len = log_out_put_dir.length();
    if (dir_len == 0) {
        return false;
    }
    if (log_out_put_dir[dir_len - 1] == '\\' || log_out_put_dir[dir_len - 1] == '/') {
        log_out_put_dir.erase(dir_len - 1, 1);
    }

    // 获取输出日志前缀，避免多个进程使用同一个动态库，写入同一个文件
    /*std::string current_proc_name = get_current_proc_name();
    std::transform(current_proc_name.begin(), current_proc_name.end(), current_proc_name.begin(), ::tolower);
    std::map<std::string, std::string>::iterator itr = map_log_files_.find(current_proc_name);
    if (itr == map_log_files_.end()) {
        return false;
    }*/
	std::string log_prefix = ""; // itr->second;

	/*log_prefix = itr->second;
    if (log_prefix.empty()) {
        return false;
    }*/

    // 创建日志输出目录
    try {
        (void)std::experimental::filesystem::create_directories(dir);
        if (!std::experimental::filesystem::exists(dir)) {
            return false;
        }
    } catch (...) {
        return false;
    }
    // 初始化日志对象
    std::string log_file_name = log_prefix + file_name;
    if (!logger_.init((log_out_put_dir + "/" + log_file_name))) {
        return false;
    }
    inited_.store(true);
    return true;
}

template <class T>
bool LoggerHelper<T>::is_debug_on()
{
    // 刷新配置间隔, 180s
    static const int REFRESH_CONFIGURATION_INTERVAL = 180;
    static time_t last_fresh_time = 0;
    time_t now = time(NULL);
    time_t diff_time = 0;
    if (now >= last_fresh_time) {
        diff_time = now - last_fresh_time;
    } else {
        diff_time = last_fresh_time - now;
    }
    // 距离上次刷新配置不到5min, 直接返回
    if (diff_time <= REFRESH_CONFIGURATION_INTERVAL) {
        return debug_;
    }

    last_fresh_time = now;
	/*static std::string config_xml = "";
    std::string value;
	bool ret = JwUtility::CXmlEx::read_xml_attribute(config_xml, "//Data/var[@name='debug_log']", "value", value);
    debug_ = (value == "1");*/
    return debug_ = 1;
}

template <class T>
bool LoggerHelper<T>::is_inited()
{
    return inited_.load();
}

template <class T>
void LoggerHelper<T>::log(const std::string& info)
{
    logger_.write_log(info);
}

template <class T>
std::string LoggerHelper<T>::get_file_name(const std::string& full_path)
{
#ifdef WIN32
    size_t pos = full_path.rfind("\\");
#else
    size_t pos = full_path.rfind("/");
#endif
    if (pos != std::string::npos) {
        return full_path.substr(pos + 1);
    }
    return full_path;
}

template <class T>
uint64_t LoggerHelper<T>::get_current_proc_pid()
{
    return pid_;
}

template <class T>
uint64_t LoggerHelper<T>::get_thread_id()
{
#ifdef WIN32
    return static_cast<uint64_t>(GetCurrentThreadId());
#else
    return static_cast<uint64_t>(syscall(SYS_gettid));
#endif
}

template <class T>
std::string LoggerHelper<T>::get_current_proc_name()
{
    std::string current_proc_name;
    static const int kproc_path_max_len = 1024;
    char process_full_path[kproc_path_max_len] = { 0 };
#ifdef WIN32
    if (GetModuleFileNameA(NULL, process_full_path, (kproc_path_max_len - 1)) == 0) {
        return current_proc_name;
    }
#else
    if (readlink("/proc/self/exe", process_full_path, (kproc_path_max_len - 1)) == -1) {
        return current_proc_name;
    }
#endif
    try {
        std::experimental::filesystem::path full_path(process_full_path);
        current_proc_name = full_path.filename().string();
    } catch (...) {
        current_proc_name = "";
    }
    return current_proc_name;
}

template <class T>
std::string LoggerHelper<T>::get_current_time_with_milliseconds()
{
#ifdef WIN32
    static const int ktime_str_buf_size = 32;
    SYSTEMTIME st = { 0 };
    char szBuf[ktime_str_buf_size + 1] = { 0 };
    GetLocalTime(&st);
    int fmt_size = _snprintf(szBuf, ktime_str_buf_size, "%d/%02d/%02d %02d:%02d:%02d.%03d",
        st.wYear,
        st.wMonth,
        st.wDay,
        st.wHour,
        st.wMinute,
        st.wSecond,
        st.wMilliseconds);

    if (fmt_size > 0) {
        return szBuf;
    } else {
        return "";
    }
#else
    static const int ktime_str_buf_size = 32;
    struct timeval tv;
    if (gettimeofday(&tv, NULL) != 0) {
        return "";
    }
    struct tm* t = localtime(&tv.tv_sec);
    if (t == NULL) {
        return "";
    }
    char strTime[ktime_str_buf_size + 1] = { 0 };
    int fmt_size = snprintf(strTime, ktime_str_buf_size, "%d/%02d/%02d %02d:%02d:%02d.%03d",
        1900 + t->tm_year, 1 + t->tm_mon, t->tm_mday,
        t->tm_hour, t->tm_min, t->tm_sec, tv.tv_usec / 1000);
    if (fmt_size > 0) {
        return std::string(strTime);
    } else {
        return "";
    }
#endif // WIN32
}

/**
 * @desc:               根据当前进程映射日志文件头，防止多个进程访问同一个文件
 **/
template <class T>
std::string LoggerHelper<T>::mapping_log_prefix(std::string& current_proc_name)
{
    std::string log_prefix = "";
    std::map<std::string, std::string>::iterator itr = map_log_files_.find(current_proc_name);
    if (itr != map_log_files_.end()) {
        log_prefix = itr->second;
    } else {
        log_prefix = "df_";
    }
    return log_prefix;
}

static std::string get_pretty_function_name(const std::string& in_pretty_func)
{
    std::string pretty_func = in_pretty_func;
    size_t pos = pretty_func.find('(');
    if (pos != std::string::npos) {
        pretty_func = pretty_func.substr(0, pos);
    }
    pos = pretty_func.rfind(' ');
    if (pos != std::string::npos) {
        pretty_func = pretty_func.substr(pos + 1);
    }
    return pretty_func;
}

#ifndef WIN32
#define __YUNSUO_FUNCTION__ get_pretty_function_name(__PRETTY_FUNCTION__)
#else
#define __YUNSUO_FUNCTION__ __FUNCTION__
#endif

/**
 * @desc                禁止静态库调用，注册日志对象， 每个动态库入口注册调用一次
 * @class_name          实例化模板日志类
 * @log_dir:            要输出的日志目录，相对runlog的， 可以写多级目录如:asset/error 或 asset/info 等
 * @file_name           日志文件名
 **/
#define REGISTER_LOGGER(log_dir, file_name) \
do{\
    LoggerHelper<log_utils::logger>* instance = LoggerHelper<log_utils::logger>::get_instance(); \
    if (instance && !instance->is_inited()) {\
        instance->init(log_dir, file_name);\
    }\
} while (false);

 /**
  * @desc                禁止静态库调用，注册日志对象， 每个动态库入口注册调用一次
  * @class_name          实例化模板日志类
  * @log_dir:            自定义要输出的日志目录
  * @file_name           日志文件名
  **/
#define REGISTER_CUSTOM_LOGGER(log_dir, file_name) \
do{\
    LoggerHelper<log_utils::logger>* instance = LoggerHelper<log_utils::logger>::get_instance(); \
    if (instance && !instance->is_inited()) {\
        instance->init_v2(log_dir, file_name);\
    }\
} while (false);

 /**
  * @desc                格式化日志输出内容 记录时间 [进程ID,线程ID][日志级别]  日志内容 [调用函数][日志对象地址](文件名:行号 编译时间)
  *                      注: Linux没有输出线程ID, 相关API数据的结果不太理想
  * @plogger             日志对象实例地址
  * @level:              日志级别
  * @info                日志内容
  **/
#define FMT_LOG_OUTPUT(plogger,level, info) \
do {\
    std::ostringstream oss; \
    oss.setf(std::ios::fixed); \
    oss.precision(6); \
    oss << plogger->get_current_time_with_milliseconds() ;\
    oss << " [" << plogger->get_current_proc_pid() << "," << plogger->get_thread_id() << "]";\
    oss << "[" << level << "]  ";\
    oss << info << " [" << __YUNSUO_FUNCTION__ << "]"; \
    oss << "[" << plogger << "]"; \
    oss << "(" << plogger->get_file_name(__FILE__) << ":" << __LINE__; \
    oss << " @CT:" << std::string(__DATE__) << " " << std::string(__TIME__) << ")"; \
    plogger->log(oss.str()); \
} while (false);

 /**
  * @desc                输出DEBUG日志，需要打开config.xml中的debug开关
  **/
#define LOGGER_DEBUG(info) \
do {\
    LoggerHelper<log_utils::logger>* instance = LoggerHelper<log_utils::logger>::get_instance();\
    if (instance && instance->is_inited() && instance->is_debug_on()) {\
        FMT_LOG_OUTPUT(instance, "DEBUG", info);\
    }\
} while (false);

 /**
  * @desc                输出INFO日志
  **/
#define LOGGER_INFO(info) \
do {\
    LoggerHelper<log_utils::logger>* instance = LoggerHelper<log_utils::logger>::get_instance();\
    if (instance && instance->is_inited()) {\
        FMT_LOG_OUTPUT(instance, "INFO", info);\
    }\
} while (false);

 /**
  * @desc                输出WARN日志
  **/
#define LOGGER_WARN(info) \
do {\
    LoggerHelper<log_utils::logger>* instance = LoggerHelper<log_utils::logger>::get_instance();\
    if (instance && instance->is_inited()) {\
        FMT_LOG_OUTPUT(instance, "WARN", info);\
    }\
} while (false);

 /**
  * @desc                输出ERROR日志
  **/
#define LOGGER_ERROR(info) \
do {\
    LoggerHelper<log_utils::logger>* instance = LoggerHelper<log_utils::logger>::get_instance();\
    if (instance && instance->is_inited()) {\
        FMT_LOG_OUTPUT(instance, "ERROR", info);\
    }\
} while (false);

class ClogGuard {
public:
    ClogGuard(const std::string& func, int64_t ret = 0) : func_name_(func), m_ret_(ret) {}
    ~ClogGuard() {LOGGER_DEBUG("exit func " << func_name_ << " m_ret_ = " << m_ret_);}

public:
    std::string func_name_;
    int64_t m_ret_;

private:
    ClogGuard() {}
};

#define I_AM_FUNC_WITH_LOG \
std::shared_ptr<ClogGuard> log_guard = std::make_shared<ClogGuard>(__YUNSUO_FUNCTION__);\
LOGGER_DEBUG("enter func " << __YUNSUO_FUNCTION__);

#define RET log_guard->m_ret_
#define RETCODE int64_t
#define RETURN_WHEN_ERROR \
do {\
    if (log_guard->m_ret_ != 0) {\
        LOGGER_ERROR("log_guard->m_ret_ = " << log_guard->m_ret_ << " return.");\
        return log_guard->m_ret_;\
    }\
} while (false);

#define BREAK_WHEN_ERROR \
if (log_guard->m_ret_ != 0) {\
    LOGGER_ERROR("log_guard->m_ret_ = " << log_guard->m_ret_ << " break.");\
    break;\
}
#endif // !LOGGER_HELPER_H__

