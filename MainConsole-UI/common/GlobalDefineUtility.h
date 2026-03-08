#ifndef GLOBALDEFINE_H
#define GLOBALDEFINE_H
#include <iostream>
#include <map>


//检测维度（创建与被创建进程）
class ProcessInfoTypeUtility {
public:

    enum class ProcessInfoType {
        UNKNOW = -1,               // 未知
        PROCESS_NAME = 0,          // 进程名称
        PROCESS_PATH = 1,          // 进程路径
        PROCESS_COMMAND_LINE = 2,  // 进程命令行
        FILE_DIGEST = 3,           // 文件摘要
        PROCESS_FEATURES = 4,      // 进程特征
        COMPANY_NAME = 5,          // 公司名称
        VERSION_INFO = 6,          // 版本信息
        SIGNATURE_NAME = 7,        // 签名名称
        PRODUCT_NAME = 8,          // 产品名称
        FILE_DESCRIPTION = 9,      // 文件描述
        SIGNATURE_NUMBER = 10,     // 签名序号
        SOURCE_FILE_NAME = 12,     // 源文件名
        FILE_VERSION = 13          // 文件版本
    };
public:
    static std::string K2V(const int &key){
        return K2V((ProcessInfoType)key);
    }
    static std::string K2V(const ProcessInfoType& key){
        switch (key) {
        case ProcessInfoType::PROCESS_NAME: return "进程名称";
        case ProcessInfoType::PROCESS_PATH: return "进程路径";
        case ProcessInfoType::PROCESS_COMMAND_LINE: return "进程命令行";
        case ProcessInfoType::FILE_DIGEST: return "文件摘要";
        case ProcessInfoType::PROCESS_FEATURES: return "进程特征";
        case ProcessInfoType::COMPANY_NAME: return "公司名称";
        case ProcessInfoType::VERSION_INFO: return "版本信息";
        case ProcessInfoType::SIGNATURE_NAME: return "签名名称";
        case ProcessInfoType::PRODUCT_NAME: return "产品名称";
        case ProcessInfoType::FILE_DESCRIPTION: return "文件描述";
        case ProcessInfoType::SIGNATURE_NUMBER: return "签名序号";
        case ProcessInfoType::SOURCE_FILE_NAME: return "源文件名";
        case ProcessInfoType::FILE_VERSION: return "文件版本";
        default: return "";
        }
    }

    static int V2K2(const std::string & value){
        return (int)V2K(value);
    }
    static ProcessInfoType V2K(const std::string & value){
        if (value == "进程名称") return ProcessInfoType::PROCESS_NAME;
        else if (value == "进程路径") return ProcessInfoType::PROCESS_PATH;
        else if (value == "进程命令行") return ProcessInfoType::PROCESS_COMMAND_LINE;
        else if (value == "文件摘要") return ProcessInfoType::FILE_DIGEST;
        else if (value == "进程特征") return ProcessInfoType::PROCESS_FEATURES;
        else if (value == "公司名称") return ProcessInfoType::COMPANY_NAME;
        else if (value == "版本信息") return ProcessInfoType::VERSION_INFO;
        else if (value == "签名名称") return ProcessInfoType::SIGNATURE_NAME;
        else if (value == "产品名称") return ProcessInfoType::PRODUCT_NAME;
        else if (value == "文件描述") return ProcessInfoType::FILE_DESCRIPTION;
        else if (value == "签名序号") return ProcessInfoType::SIGNATURE_NUMBER;
        else if (value == "源文件名") return ProcessInfoType::SOURCE_FILE_NAME;
        else if (value == "文件版本") return ProcessInfoType::FILE_VERSION;
        else return ProcessInfoType::UNKNOW;
    }
};



//处理方式
class ProcessActionUtility {
public:
    enum class ProcessAction {
        UNKNOW = -1,                       // 未知
        INTERCEPT = 0,                     // 拦截
        ALLOW = 1,                         // 放行
        TERMINATE_CHILD_PROCESS = 2,       // 结束子进程
        SUSPEND_CHILD_PROCESS = 3,         // 挂起子进程
        INTERCEPT_AND_TERMINATE_PARENT = 4,// 拦截并结束父进程
        INTERCEPT_AND_SUSPEND_PARENT = 5,  // 拦截并挂起父进程
        INTERCEPT_AND_TERMINATE_THREAD = 6,// 拦截并结束父线程
        INTERCEPT_AND_SUSPEND_THREAD = 7   // 拦截并挂起父线程
    };
public:
    static std::string K2V(const int &key){
        return K2V((ProcessAction)key);
    }
    static std::string K2V(ProcessAction action){
        switch(action){
        case ProcessAction::INTERCEPT: return "拦截";
        case ProcessAction::ALLOW: return "放行";
        case ProcessAction::TERMINATE_CHILD_PROCESS: return "结束子进程";
        case ProcessAction::SUSPEND_CHILD_PROCESS: return "挂起子进程";
        case ProcessAction::INTERCEPT_AND_TERMINATE_PARENT: return "拦截并结束父进程";
        case ProcessAction::INTERCEPT_AND_SUSPEND_PARENT: return "拦截并挂起父进程";
        case ProcessAction::INTERCEPT_AND_TERMINATE_THREAD: return "拦截并结束父线程";
        case ProcessAction::INTERCEPT_AND_SUSPEND_THREAD: return "拦截并挂起父线程";
        default: return "";
        }
    }

    static int V2K2(const std::string & value){
        return (int)V2K(value);
    }
    static ProcessAction V2K(const std::string & value){
        if (value == "拦截") return ProcessAction::INTERCEPT;
        else if (value == "放行") return ProcessAction::ALLOW;
        else if (value == "结束子进程") return ProcessAction::TERMINATE_CHILD_PROCESS;
        else if (value == "挂起子进程") return ProcessAction::SUSPEND_CHILD_PROCESS;
        else if (value == "拦截并结束父进程") return ProcessAction::INTERCEPT_AND_TERMINATE_PARENT;
        else if (value == "拦截并挂起父进程") return ProcessAction::INTERCEPT_AND_SUSPEND_PARENT;
        else if (value == "拦截并结束父线程") return ProcessAction::INTERCEPT_AND_TERMINATE_THREAD;
        else if (value == "拦截并挂起父线程") return ProcessAction::INTERCEPT_AND_SUSPEND_THREAD;
        else return ProcessAction::UNKNOW;
    }

};


//操作系统
class WindowsVersionUtility {
public:
    enum class WindowsVersion {
        UNKNOW = -1,     // 未知
        WINDOWS_7 = 1,   // Windows 7
        WINDOWS_10 = 2,  // Windows 10
        WINDOWS_11 = 3   // Windows 11
    };
public:
    static std::string K2V(const int &key){
        return K2V((WindowsVersion)key);
    }
    static std::string K2V(const WindowsVersion & key){
        switch(key){
        case WindowsVersion::WINDOWS_7: return "Windows7";
        case WindowsVersion::WINDOWS_10: return "Windows10";
        case WindowsVersion::WINDOWS_11: return "Windows11";
        default: return "";
        }
    }

    static int V2K2(const std::string & value){
        return (int)V2K(value);
    }
    static WindowsVersion V2K(const std::string & value){
        if (value == "Windows 7") return WindowsVersion::WINDOWS_7;
        else if (value == "Windows 10") return WindowsVersion::WINDOWS_10;
        else if (value == "Windows 11") return WindowsVersion::WINDOWS_11;
        else return WindowsVersion::UNKNOW;
    }
};


//规则开关
class RuleStateUtility {
public:
    enum class RuleState {
        UNKNOW = -1,        // 未知
        RULE_DISABLE = 0,   // 关闭状态
        RULE_ENABLE = 1     // 开启状态
    };
public:
    static std::string K2V(const int &key){
        return K2V((RuleState)key);
    }
    static std::string K2V(const RuleState& key) {
        switch (key) {
        case RuleState::RULE_DISABLE: return "关闭状态";
        case RuleState::RULE_ENABLE: return "开启状态";
        default: return "";
        }
    }

    static int V2K2(const std::string & value){
        return (int)V2K(value);
    }
    static RuleState V2K(const std::string& value) {
        if (value == "关闭状态") return RuleState::RULE_DISABLE;
        else if (value == "开启状态") return RuleState::RULE_ENABLE;
        else return RuleState::UNKNOW;
    }
};

//日志开关
class LogStateUtility {
public:
    enum class LogState {
        UNKNOW = -1,      // 未知
        LOG_OFF = 0,      // 关闭状态
        LOG_ON = 1        // 记录日志
    };
public:
    static std::string K2V(const int &key){
        return K2V((LogState)key);
    }
    static std::string K2V(const LogState& key) {
        switch (key) {
        case LogState::LOG_OFF: return "关闭状态";
        case LogState::LOG_ON: return "记录日志";
        default: return "";
        }
    }

    static int V2K2(const std::string & value){
        return (int)V2K(value);
    }
    static LogState V2K(const std::string& value) {
        if (value == "关闭状态") return LogState::LOG_OFF;
        else if (value == "记录日志") return LogState::LOG_ON;
        else return LogState::UNKNOW;
    }
};


class ThreadActionUtility {
public:
    enum class ThreadAction {
        UNKNOW = -1, //未知
        BLOCK = 0, //阻止
        ALLOW = 1, //放行
        DECEIVE = 2, //欺骗
        COLLECT = 3 //采集
    };

public:
    static std::string K2V(const int &key) {
        return K2V(static_cast<ThreadAction>(key));
    }

    static std::string K2V(const ThreadAction &key) {
        switch(key) {
        case ThreadAction::BLOCK: return "阻止";
        case ThreadAction::ALLOW: return "放行";
        case ThreadAction::DECEIVE: return "欺骗";
        case ThreadAction::COLLECT: return "采集";
        default: return "";
        }
    }

    static int V2K2(const std::string &value) {
        return static_cast<int>(V2K(value));
    }

    static ThreadAction V2K(const std::string &value) {
        if (value == "阻止") return ThreadAction::BLOCK;
        else if (value == "放行") return ThreadAction::ALLOW;
        else if (value == "欺骗") return ThreadAction::DECEIVE;
        else if (value == "采集") return ThreadAction::COLLECT;
        else return ThreadAction::UNKNOW;
    }
};

class ThreadCheckTypeUtility {
public:
    enum class ThreadCheckType {
        UNKNOW = -1,       //未知
        OPCODE = 0,        //指令码
        MACHINE_CODE = 1   //机器码
    };

public:
    static std::string K2V(const int &key) {
        return K2V(static_cast<ThreadCheckType>(key));
    }

    static std::string K2V(const ThreadCheckType &key) {
        switch (key) {
        case ThreadCheckType::OPCODE: return "指令码";
        case ThreadCheckType::MACHINE_CODE: return "机器码";
        default: return "";
        }
    }

    static int V2K2(const std::string &value) {
        return static_cast<int>(V2K(value));
    }

    static ThreadCheckType V2K(const std::string &value) {
        if (value == "指令码") return ThreadCheckType::OPCODE;
        else if (value == "机器码") return ThreadCheckType::MACHINE_CODE;
        else return ThreadCheckType::UNKNOW;
    }
};


class FileCheckTypeUtility {
public:
    enum class FileCheckType {
        UNKNOW = -1,
        CREATE_FILE = 0x01,
        OPEN_FILE = 0x02,
        DELETE_FILE = 0x04,
        READ_FILE = 0x08,
        WRITE_FILE = 0x10,
        EXECUTE_FILE = 0x20,
        RENAME_FILE = 0x40,
        QUERY_FILE_INFO = 0x80
    };

public:
    static std::string K2V(const int &key) {
        return K2V(static_cast<FileCheckType>(key));
    }

    static std::string K2V(FileCheckType action) {
        switch (action) {
        case FileCheckType::CREATE_FILE: return "创建文件";
        case FileCheckType::OPEN_FILE: return "打开文件";
        case FileCheckType::DELETE_FILE: return "删除文件";
        case FileCheckType::READ_FILE: return "读取文件";
        case FileCheckType::WRITE_FILE: return "写入文件";
        case FileCheckType::EXECUTE_FILE: return "执行文件";
        case FileCheckType::RENAME_FILE: return "重命名文件";
        case FileCheckType::QUERY_FILE_INFO: return "查询文件信息";
        default: return "";
        }
    }

    static int V2K2(const std::string &value) {
        return static_cast<int>(V2K(value));
    }

    static FileCheckType V2K(const std::string &value) {
        if (value == "创建文件") return FileCheckType::CREATE_FILE;
        else if (value == "打开文件") return FileCheckType::OPEN_FILE;
        else if (value == "删除文件") return FileCheckType::DELETE_FILE;
        else if (value == "读取文件") return FileCheckType::READ_FILE;
        else if (value == "写入文件") return FileCheckType::WRITE_FILE;
        else if (value == "执行文件") return FileCheckType::EXECUTE_FILE;
        else if (value == "重命名文件") return FileCheckType::RENAME_FILE;
        else if (value == "查询文件信息") return FileCheckType::QUERY_FILE_INFO;
        else return FileCheckType::UNKNOW;  // 默认为创建文件，如果输入不被识别
    }
};

class FileActionUtility {
public:
    enum class FileAction {
        UNKNOW = -1,
        INTERCEPT = 0,                       // 拦截
        ALLOW = 1,                           // 放行
        INTERCEPT_AND_TERMINATE_PROCESS = 2, // 拦截并结束当前进程
        INTERCEPT_AND_SUSPEND_PROCESS = 3,   // 拦截并挂起当前进程
        INTERCEPT_AND_TERMINATE_THREAD = 4,  // 拦截并结束当前线程
        INTERCEPT_AND_SUSPEND_THREAD = 5,    // 拦截并挂起当前线程
        FILE_REDIRECT = 8                    // 文件转向
    };

public:
    static std::string K2V(const int &key) {
        return K2V(static_cast<FileAction>(key));
    }

    static std::string K2V(FileAction action) {
        switch (action) {
        case FileAction::INTERCEPT: return "拦截";
        case FileAction::ALLOW: return "放行";
        case FileAction::INTERCEPT_AND_TERMINATE_PROCESS: return "拦截并结束当前进程";
        case FileAction::INTERCEPT_AND_SUSPEND_PROCESS: return "拦截并挂起当前进程";
        case FileAction::INTERCEPT_AND_TERMINATE_THREAD: return "拦截并结束当前线程";
        case FileAction::INTERCEPT_AND_SUSPEND_THREAD: return "拦截并挂起当前线程";
        case FileAction::FILE_REDIRECT: return "文件转向";
        default: return "";
        }
    }

    static int V2K2(const std::string &value) {
        return static_cast<int>(V2K(value));
    }

    static FileAction V2K(const std::string &value) {
        if (value == "拦截") return FileAction::INTERCEPT;
        else if (value == "放行") return FileAction::ALLOW;
        else if (value == "拦截并结束当前进程") return FileAction::INTERCEPT_AND_TERMINATE_PROCESS;
        else if (value == "拦截并挂起当前进程") return FileAction::INTERCEPT_AND_SUSPEND_PROCESS;
        else if (value == "拦截并结束当前线程") return FileAction::INTERCEPT_AND_TERMINATE_THREAD;
        else if (value == "拦截并挂起当前线程") return FileAction::INTERCEPT_AND_SUSPEND_THREAD;
        else if (value == "文件转向") return FileAction::FILE_REDIRECT;
        else return FileAction::UNKNOW;
    }
};


class ModuleInfoTypeUtility {
public:
    enum class ModuleInfoType {
        UNKNOW = -1,             // 未知
        MODULE_NAME = 0,         // 模块名称
        MODULE_PATH = 1,         // 模块路径
        MODULE_SUMMARY = 2,      // 模块摘要
        MODULE_FEATURE = 3,      // 模块特征
        SIGNATURE_OWNER = 4,     // 签名归属
        SIGNATURE_NUMBER = 5,    // 签名序号
        FILE_DESCRIPTION = 6,    // 文件说明
        FILE_VERSION = 7,        // 文件版本
        PRODUCT_NAME = 8,        // 产品名称
        PRODUCT_VERSION = 9,     // 产品版本
        COMPANY_NAME = 10        // 公司名称
    };

public:
    static std::string K2V(const int &key) {
        return K2V(static_cast<ModuleInfoType>(key));
    }

    static std::string K2V(ModuleInfoType type) {
        switch (type) {
        case ModuleInfoType::MODULE_NAME: return "模块名称";
        case ModuleInfoType::MODULE_PATH: return "模块路径";
        case ModuleInfoType::MODULE_SUMMARY: return "模块摘要";
        case ModuleInfoType::MODULE_FEATURE: return "模块特征";
        case ModuleInfoType::SIGNATURE_OWNER: return "签名归属";
        case ModuleInfoType::SIGNATURE_NUMBER: return "签名序号";
        case ModuleInfoType::FILE_DESCRIPTION: return "文件说明";
        case ModuleInfoType::FILE_VERSION: return "文件版本";
        case ModuleInfoType::PRODUCT_NAME: return "产品名称";
        case ModuleInfoType::PRODUCT_VERSION: return "产品版本";
        case ModuleInfoType::COMPANY_NAME: return "公司名称";
        default: return "";
        }
    }

    static int V2K2(const std::string &value) {
        return static_cast<int>(V2K(value));
    }

    static ModuleInfoType V2K(const std::string &value) {
        if (value == "模块名称") return ModuleInfoType::MODULE_NAME;
        else if (value == "模块路径") return ModuleInfoType::MODULE_PATH;
        else if (value == "模块摘要") return ModuleInfoType::MODULE_SUMMARY;
        else if (value == "模块特征") return ModuleInfoType::MODULE_FEATURE;
        else if (value == "签名归属") return ModuleInfoType::SIGNATURE_OWNER;
        else if (value == "签名序号") return ModuleInfoType::SIGNATURE_NUMBER;
        else if (value == "文件说明") return ModuleInfoType::FILE_DESCRIPTION;
        else if (value == "文件版本") return ModuleInfoType::FILE_VERSION;
        else if (value == "产品名称") return ModuleInfoType::PRODUCT_NAME;
        else if (value == "产品版本") return ModuleInfoType::PRODUCT_VERSION;
        else if (value == "公司名称") return ModuleInfoType::COMPANY_NAME;
        else return ModuleInfoType::UNKNOW;
    }
};


class KernelInfoTypeUtility {
public:
    enum class KernelInfoType {
        UNKNOW = -1,             // 未知
        DRIVER_NAME = 0,         // 驱动名称
        DRIVER_PATH = 1,         // 驱动路径
        DRIVER_SUMMARY = 2,      // 驱动摘要
        DRIVER_FEATURE = 3,      // 驱动特征
        SIGNATURE_OWNER = 4,     // 签名归属
        SIGNATURE_NUMBER = 5,    // 签名序号
        FILE_DESCRIPTION = 6,    // 文件说明
        FILE_VERSION = 7,        // 文件版本
        PRODUCT_NAME = 8,        // 产品名称
        PRODUCT_VERSION = 9,     // 产品版本
        COMPANY_NAME = 10        // 公司名称
    };

public:
    static std::string K2V(const int &key) {
        return K2V(static_cast<KernelInfoType>(key));
    }

    static std::string K2V(KernelInfoType type) {
        switch (type) {
        case KernelInfoType::DRIVER_NAME: return "驱动名称";
        case KernelInfoType::DRIVER_PATH: return "驱动路径";
        case KernelInfoType::DRIVER_SUMMARY: return "驱动摘要";
        case KernelInfoType::DRIVER_FEATURE: return "驱动特征";
        case KernelInfoType::SIGNATURE_OWNER: return "签名归属";
        case KernelInfoType::SIGNATURE_NUMBER: return "签名序号";
        case KernelInfoType::FILE_DESCRIPTION: return "文件说明";
        case KernelInfoType::FILE_VERSION: return "文件版本";
        case KernelInfoType::PRODUCT_NAME: return "产品名称";
        case KernelInfoType::PRODUCT_VERSION: return "产品版本";
        case KernelInfoType::COMPANY_NAME: return "公司名称";
        default: return "";
        }
    }

    static int V2K2(const std::string &value) {
        return static_cast<int>(V2K(value));
    }

    static KernelInfoType V2K(const std::string &value) {
        if (value == "驱动名称") return KernelInfoType::DRIVER_NAME;
        else if (value == "驱动路径") return KernelInfoType::DRIVER_PATH;
        else if (value == "驱动摘要") return KernelInfoType::DRIVER_SUMMARY;
        else if (value == "驱动特征") return KernelInfoType::DRIVER_FEATURE;
        else if (value == "签名归属") return KernelInfoType::SIGNATURE_OWNER;
        else if (value == "签名序号") return KernelInfoType::SIGNATURE_NUMBER;
        else if (value == "文件说明") return KernelInfoType::FILE_DESCRIPTION;
        else if (value == "文件版本") return KernelInfoType::FILE_VERSION;
        else if (value == "产品名称") return KernelInfoType::PRODUCT_NAME;
        else if (value == "产品版本") return KernelInfoType::PRODUCT_VERSION;
        else if (value == "公司名称") return KernelInfoType::COMPANY_NAME;
        else return KernelInfoType::UNKNOW;
    }
};

class KernelActionUtility {
public:
    enum class KernelAction {
        UNKNOW     =  -1,                //未知
        INTERCEPT_LOAD = 0,              // 拦截加载
        INTERCEPT_FUNCTIONALITY = 1,     // 拦截功能
        ALLOW = 2,                       // 放行
        CALLBACK_REMOVAL = 3,            // 回调摘除
        CALLBACK_REMOVAL_TERMINATE_THREAD = 4  // 回调摘除+结束线程
    };

public:
    static std::string K2V(const int &key) {
        return K2V(static_cast<KernelAction>(key));
    }

    static std::string K2V(KernelAction action) {
        switch (action) {
        case KernelAction::INTERCEPT_LOAD: return "拦截加载";
        case KernelAction::INTERCEPT_FUNCTIONALITY: return "拦截功能";
        case KernelAction::ALLOW: return "放行";
        case KernelAction::CALLBACK_REMOVAL: return "回调摘除";
        case KernelAction::CALLBACK_REMOVAL_TERMINATE_THREAD: return "回调摘除+结束线程";
        default: return "";
        }
    }

    static int V2K2(const std::string &value) {
        return static_cast<int>(V2K(value));
    }

    static KernelAction V2K(const std::string &value) {
        if (value == "拦截加载") return KernelAction::INTERCEPT_LOAD;
        else if (value == "拦截功能") return KernelAction::INTERCEPT_FUNCTIONALITY;
        else if (value == "放行") return KernelAction::ALLOW;
        else if (value == "回调摘除") return KernelAction::CALLBACK_REMOVAL;
        else if (value == "回调摘除+结束线程") return KernelAction::CALLBACK_REMOVAL_TERMINATE_THREAD;
        else return KernelAction::UNKNOW;
    }
};


class NetWorkActionUtility {
public:
    enum class NetWorkAction {
        UNKNOW = -1,          //未知
        INTERCEPT = 0,                             // 拦截
        ALLOW = 1,                                 // 放行
        INTERCEPT_AND_TERMINATE_CURRENT_PROCESS = 2,       // 拦截并结束当前进程
        INTERCEPT_AND_SUSPEND_CURRENT_PROCESS = 3,         // 拦截并挂起当前进程
        INTERCEPT_AND_TERMINATE_CURRENT_THREAD = 4,        // 拦截并结束当前线程
        INTERCEPT_AND_SUSPEND_CURRENT_THREAD = 5          // 拦截并挂起当前线程
    };

public:
    static std::string K2V(const int &key) {
        return K2V(static_cast<NetWorkAction>(key));
    }

    static std::string K2V(NetWorkAction action) {
        switch (action) {
            case NetWorkAction::INTERCEPT: return "拦截";
            case NetWorkAction::ALLOW: return "放行";
            case NetWorkAction::INTERCEPT_AND_TERMINATE_CURRENT_PROCESS: return "拦截并结束当前进程";
            case NetWorkAction::INTERCEPT_AND_SUSPEND_CURRENT_PROCESS: return "拦截并挂起当前进程";
            case NetWorkAction::INTERCEPT_AND_TERMINATE_CURRENT_THREAD: return "拦截并结束当前线程";
            case NetWorkAction::INTERCEPT_AND_SUSPEND_CURRENT_THREAD: return "拦截并挂起当前线程";
            default: return "";
        }
    }

    static int V2K2(const std::string &value) {
        return static_cast<int>(V2K(value));
    }

    static NetWorkAction V2K(const std::string &value) {
        if (value == "拦截") return NetWorkAction::INTERCEPT;
        else if (value == "放行") return NetWorkAction::ALLOW;
        else if (value == "拦截并结束当前进程") return NetWorkAction::INTERCEPT_AND_TERMINATE_CURRENT_PROCESS;
        else if (value == "拦截并挂起当前进程") return NetWorkAction::INTERCEPT_AND_SUSPEND_CURRENT_PROCESS;
        else if (value == "拦截并结束当前线程") return NetWorkAction::INTERCEPT_AND_TERMINATE_CURRENT_THREAD;
        else if (value == "拦截并挂起当前线程") return NetWorkAction::INTERCEPT_AND_SUSPEND_CURRENT_THREAD;
        else return NetWorkAction::UNKNOW;  // 默认为拦截，如果输入不被识别
    }
};

class ProtectTypeUtility {
public:
    enum class ProtectType {
        END_PROCESS_PROTECTION = 0,       // 防结束保护
        INJECTION_PROTECTION = 1          // 防注入保护
    };

public:
    static std::string K2V(const int &key) {
        return K2V(static_cast<ProtectType>(key));
    }

    static std::string K2V(ProtectType type) {
        switch (type) {
            case ProtectType::END_PROCESS_PROTECTION: return "防结束保护";
            case ProtectType::INJECTION_PROTECTION: return "防注入保护";
            default: return "";
        }
    }

    static int V2K2(const std::string &value) {
        return static_cast<int>(V2K(value));
    }

    static ProtectType V2K(const std::string &value) {
        if (value == "防结束保护") return ProtectType::END_PROCESS_PROTECTION;
        else if (value == "防注入保护") return ProtectType::INJECTION_PROTECTION;
        else return ProtectType::END_PROCESS_PROTECTION;  // 默认为防结束保护，如果输入不被识别
    }
};

#endif // GLOBALDEFINE_H
