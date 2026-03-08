#include "GlobalDefineUtility.h"


const std::vector<std::pair<ProcessInfoTypeUtility::ProcessInfoType, std::string>> ProcessInfoTypeUtility::processInfoTypeItems = {
	{ProcessInfoTypeUtility::ProcessInfoType::PROCESS_NAME, "进程名称"},
	{ProcessInfoTypeUtility::ProcessInfoType::PROCESS_PATH, "进程路径"},
	{ProcessInfoTypeUtility::ProcessInfoType::PROCESS_COMMAND_LINE, "进程命令行"},
	{ProcessInfoTypeUtility::ProcessInfoType::FILE_DIGEST, "进程文件摘要"},
	{ProcessInfoTypeUtility::ProcessInfoType::PROCESS_FEATURES, "进程特征"},
	{ProcessInfoTypeUtility::ProcessInfoType::COMPANY_NAME, "进程公司名称"},
	{ProcessInfoTypeUtility::ProcessInfoType::VERSION_INFO, "进程版本信息"},
	{ProcessInfoTypeUtility::ProcessInfoType::SIGNATURE_NAME, "进程签名"},
	{ProcessInfoTypeUtility::ProcessInfoType::PRODUCT_NAME, "进程产品名称"},
	{ProcessInfoTypeUtility::ProcessInfoType::FILE_DESCRIPTION, "进程文件描述"},
	{ProcessInfoTypeUtility::ProcessInfoType::SIGNATURE_NUMBER, "进程签名序列号"},
	{ProcessInfoTypeUtility::ProcessInfoType::SOURCE_FILE_NAME, "进程原始文件名"},
	{ProcessInfoTypeUtility::ProcessInfoType::FILE_VERSION, "进程文件版本"}
};


const std::vector<std::pair<ProcessActionUtility::ProcessAction, std::string>> ProcessActionUtility::processActionItems = {
	{ProcessAction::INTERCEPT, "拦截子进程"},
	{ProcessAction::ALLOW, "放行子进程"},
	{ProcessAction::TERMINATE_CHILD_PROCESS, "结束子进程"},
	{ProcessAction::SUSPEND_CHILD_PROCESS, "挂起子进程"},
	{ProcessAction::INTERCEPT_AND_TERMINATE_PARENT, "拦截并结束父进程"},
	{ProcessAction::INTERCEPT_AND_SUSPEND_PARENT, "拦截并挂起父进程"},
	{ProcessAction::INTERCEPT_AND_TERMINATE_THREAD, "拦截并结束父线程"},
	{ProcessAction::INTERCEPT_AND_SUSPEND_THREAD, "拦截并挂起父线程"}
};

const std::vector<std::pair<WindowsVersionUtility::WindowsVersion, std::string>> WindowsVersionUtility::windowsVersionItems = {
	{WindowsVersionUtility::WindowsVersion::WINDOWS_ALL, "任意系统"},
	{WindowsVersionUtility::WindowsVersion::WINDOWS_7, "Windows 7"},
	{WindowsVersionUtility::WindowsVersion::WINDOWS_10, "Windows 10"},
	{WindowsVersionUtility::WindowsVersion::WINDOWS_11, "Windows 11"}
};

const std::vector<std::pair<RuleStateUtility::RuleState, std::string>> RuleStateUtility::ruleStateItems = {
	{RuleStateUtility::RuleState::RULE_DISABLE, "关闭状态"},
	{RuleStateUtility::RuleState::RULE_ENABLE, "开启状态"}
};

const std::vector<std::pair<LogStateUtility::LogState, std::string>> LogStateUtility::logStateItems = {
	{LogStateUtility::LogState::LOG_OFF, "关闭状态"},
	{LogStateUtility::LogState::LOG_ON, "记录日志"}
};

const std::vector<std::pair<ThreadActionUtility::ThreadAction, std::string>> ThreadActionUtility::threadActionItems = {
	{ThreadActionUtility::ThreadAction::BLOCK, "拦截线程"},
	{ThreadActionUtility::ThreadAction::ALLOW, "放行线程"},
	{ThreadActionUtility::ThreadAction::DECEIVE, "拦截线程功能"},
	{ThreadActionUtility::ThreadAction::COLLECT, "采集线程信息"}
};

const std::vector<std::pair<ThreadCheckTypeUtility::ThreadCheckType, std::string>> ThreadCheckTypeUtility::threadCheckTypeItems = {
	{ThreadCheckTypeUtility::ThreadCheckType::OPCODE, "入口汇编"},
	{ThreadCheckTypeUtility::ThreadCheckType::MACHINE_CODE, "机器码"}
};



const std::vector<std::pair<FileCheckTypeUtility::FileCheckType, std::string>> FileCheckTypeUtility::fileCheckTypeItems = {
	{FileCheckTypeUtility::FileCheckType::FILE_NAME, "文件名称"},
	{FileCheckTypeUtility::FileCheckType::FILE_PATH, "文件路径"}
};

const std::vector<std::pair<FilePrivilegetility::FilePrivilegeType, std::string>> FilePrivilegetility::filePrivilegeTypeItems = {
	{FilePrivilegetility::FilePrivilegeType::CREATE_FILE, "创建文件"},
	{FilePrivilegetility::FilePrivilegeType::OPEN_FILE, "打开文件"},
	{FilePrivilegetility::FilePrivilegeType::DELETE_FILE, "删除文件"},
	{FilePrivilegetility::FilePrivilegeType::READ_FILE, "读取文件"},
	{FilePrivilegetility::FilePrivilegeType::WRITE_FILE, "写入文件"},
	{FilePrivilegetility::FilePrivilegeType::EXECUTE_FILE, "执行文件"},
	{FilePrivilegetility::FilePrivilegeType::RENAME_FILE, "重命名文件"},
	{FilePrivilegetility::FilePrivilegeType::QUERY_FILE_INFO, "查询文件信息"}
};

const std::vector<std::pair<FileActionUtility::FileAction, std::string>> FileActionUtility::fileActionItems = {
	{FileActionUtility::FileAction::INTERCEPT, "拦截"},
	{FileActionUtility::FileAction::ALLOW, "放行"},
	{FileActionUtility::FileAction::INTERCEPT_AND_TERMINATE_PROCESS, "拦截并结束源进程"},
	{FileActionUtility::FileAction::INTERCEPT_AND_SUSPEND_PROCESS, "拦截并挂起源进程"},
	{FileActionUtility::FileAction::INTERCEPT_AND_TERMINATE_THREAD, "拦截并结束源线程"},
	{FileActionUtility::FileAction::INTERCEPT_AND_SUSPEND_THREAD, "拦截并挂起源线程"},
	{FileActionUtility::FileAction::FILE_REDIRECT, "文件转向"}
};


const std::vector<std::pair<ModuleActionUtility::ModuleAction, std::string>> ModuleActionUtility::moduleActionItems = {
	{ModuleActionUtility::ModuleAction::INTERCEPT, "拦截"},
	{ModuleActionUtility::ModuleAction::ALLOW, "放行"},
	{ModuleActionUtility::ModuleAction::INTERCEPT_AND_TERMINATE_PROCESS, "拦截并结束源进程"},
	{ModuleActionUtility::ModuleAction::INTERCEPT_AND_SUSPEND_PROCESS, "拦截并挂起源进程"},
	{ModuleActionUtility::ModuleAction::INTERCEPT_AND_TERMINATE_THREAD, "拦截并结束源线程"},
	{ModuleActionUtility::ModuleAction::INTERCEPT_AND_SUSPEND_THREAD, "拦截并挂起源线程"}
};

const std::vector<std::pair<ModuleInfoTypeUtility::ModuleInfoType, std::string>> ModuleInfoTypeUtility::moduleInfoTypeItems = {
	{ModuleInfoTypeUtility::ModuleInfoType::MODULE_NAME, "模块名称"},
	{ModuleInfoTypeUtility::ModuleInfoType::MODULE_PATH, "模块路径"},
	{ModuleInfoTypeUtility::ModuleInfoType::MODULE_SUMMARY, "模块摘要"},
	{ModuleInfoTypeUtility::ModuleInfoType::MODULE_FEATURE, "模块特征"},
	{ModuleInfoTypeUtility::ModuleInfoType::COMPANY_NAME, "公司名称"},
	{ModuleInfoTypeUtility::ModuleInfoType::PRODUCT_VERSION, "产品版本"},
	{ModuleInfoTypeUtility::ModuleInfoType::PRODUCT_NAME, "产品名称"},
	{ModuleInfoTypeUtility::ModuleInfoType::FILE_DESCRIPTION, "文件说明"},
	{ModuleInfoTypeUtility::ModuleInfoType::SIGNATURE_OWNER, "签名归属"},
	{ModuleInfoTypeUtility::ModuleInfoType::SIGNATURE_NUMBER, "签名序号"},
	{ModuleInfoTypeUtility::ModuleInfoType::FILE_MD5, "文件MD5"},
	{ModuleInfoTypeUtility::ModuleInfoType::FILE_ORIGINAL_NAME, "文件原始名称"},
	{ModuleInfoTypeUtility::ModuleInfoType::FILE_VERSION, "文件版本"}
};

const std::vector<std::pair<KernelInfoTypeUtility::KernelInfoType, std::string>> KernelInfoTypeUtility::kernelInfoTypeItems = {
	{KernelInfoTypeUtility::KernelInfoType::KERNEL_NAME, "内核名称"},
	{KernelInfoTypeUtility::KernelInfoType::KERNEL_PATH, "内核路径"},
	{KernelInfoTypeUtility::KernelInfoType::KERNEL_SUMMARY, "内核摘要"},
	{KernelInfoTypeUtility::KernelInfoType::KERNEL_FEATURE, "内核特征"},
	{KernelInfoTypeUtility::KernelInfoType::COMPANY_NAME, "公司名称"},
	{KernelInfoTypeUtility::KernelInfoType::PRODUCT_VERSION, "产品版本"},
	{KernelInfoTypeUtility::KernelInfoType::PRODUCT_NAME, "产品名称"},
	{KernelInfoTypeUtility::KernelInfoType::FILE_DESCRIPTION, "文件说明"},
	{KernelInfoTypeUtility::KernelInfoType::SIGNATURE_OWNER, "签名归属"},
	{KernelInfoTypeUtility::KernelInfoType::SIGNATURE_NUMBER, "签名序号"},
	{KernelInfoTypeUtility::KernelInfoType::FILE_ORIGINAL_NAME, "文件原始名称"},
	{KernelInfoTypeUtility::KernelInfoType::FILE_VERSION, "文件版本"}
};

const std::vector<std::pair<KernelActionUtility::KernelAction, std::string>> KernelActionUtility::kernelActionItems = {
	{KernelActionUtility::KernelAction::INTERCEPT_LOAD, "拦截加载"},
	{KernelActionUtility::KernelAction::INTERCEPT_FUNCTIONALITY, "拦截功能"},
	{KernelActionUtility::KernelAction::ALLOW, "放行"},
	{KernelActionUtility::KernelAction::CALLBACK_REMOVAL, "回调摘除"},
	{KernelActionUtility::KernelAction::CALLBACK_REMOVAL_TERMINATE_THREAD, "回调摘除+结束线程"}
};

const std::vector<std::pair<NetWorkActionUtility::NetWorkAction, std::string>> NetWorkActionUtility::netWorkActionItems = {
	{NetWorkActionUtility::NetWorkAction::INTERCEPT, "拦截"},
	{NetWorkActionUtility::NetWorkAction::ALLOW, "放行"},
	{NetWorkActionUtility::NetWorkAction::INTERCEPT_AND_TERMINATE_CURRENT_PROCESS, "拦截并结束源进程"},
	{NetWorkActionUtility::NetWorkAction::INTERCEPT_AND_SUSPEND_CURRENT_PROCESS, "拦截并挂起源进程"},
	{NetWorkActionUtility::NetWorkAction::INTERCEPT_AND_TERMINATE_CURRENT_THREAD, "拦截并结束源线程"},
	{NetWorkActionUtility::NetWorkAction::INTERCEPT_AND_SUSPEND_CURRENT_THREAD, "拦截并挂起源线程"}
};

const std::vector<std::pair<RegisterActionUtility::RegisterAction, std::string>> RegisterActionUtility::registerActionItems = {
	{RegisterActionUtility::RegisterAction::INTERCEPT, "拦截"},
	{RegisterActionUtility::RegisterAction::ALLOW, "放行"},
	{RegisterActionUtility::RegisterAction::INTERCEPT_AND_TERMINATE_PROCESS, "拦截并结束源进程"},
	{RegisterActionUtility::RegisterAction::INTERCEPT_AND_SUSPEND_PROCESS, "拦截并挂起源进程"},
	{RegisterActionUtility::RegisterAction::INTERCEPT_AND_TERMINATE_THREAD, "拦截并结束源线程"},
	{RegisterActionUtility::RegisterAction::INTERCEPT_AND_SUSPEND_THREAD, "拦截并挂起源线程"}
};

const std::vector<std::pair<RegisterPrivilegetility::RegisterPrivilegeType, std::string>> RegisterPrivilegetility::regPrivilegeTypeItems = {
	{RegisterPrivilegetility::RegisterPrivilegeType::READ_REG, "读取"},
	{RegisterPrivilegetility::RegisterPrivilegeType::WRITE_REG, "写入"},
	{RegisterPrivilegetility::RegisterPrivilegeType::DELETE_REG, "删除"},
};


const std::vector<std::pair<ProProtectionActionUtility::ProProtectionAction, std::string>> ProProtectionActionUtility::proProcessActionItems = {
	{ProProtectionActionUtility::ProProtectionAction::INTERCEPT, "拦截"},
	{ProProtectionActionUtility::ProProtectionAction::ALLOW, "放行"},
	{ProProtectionActionUtility::ProProtectionAction::TERMINATE_SOURCE_PROCESS, "结束源进程"},
	{ProProtectionActionUtility::ProProtectionAction::SUSPEND_SOURCE_PROCESS, "挂起源进程"},
	{ProProtectionActionUtility::ProProtectionAction::TERMINATE_SOURCE_THREAD, "结束源线程"},
	{ProProtectionActionUtility::ProProtectionAction::SUSPEND_SOURCE_THREAD, "挂起源线程"}
};

const std::vector<std::pair<ProtectTypeUtility::ProtectType, std::string>> ProtectTypeUtility::protectTypeItems = {
	{ProtectTypeUtility::ProtectType::END_PROCESS_PROTECTION, "防结束保护"},
	{ProtectTypeUtility::ProtectType::INJECTION_PROTECTION, "防注入保护"}
};

const std::vector<std::pair<int, std::string>> PriorityUtility::priorityItems = {
	{1, "1"},
	{2, "2"},
	{3, "3"},
	{4, "4"},
	{5, "5"},
	{6, "6"},
	{7, "7"},
	{8, "8"},
	{9, "9"},
	{10, "10"},
	{11, "11"},
	{12, "12"},
	{13, "13"},
	{14, "14"},
	{15, "15"},
	{16, "16"},
	{17, "17"},
	{18, "18"},
	{19, "19"},
	{20, "20"},
	{21, "21"},
	{22, "22"},
	{23, "23"},
	{24, "24"},
	{25, "25"},
	{26, "26"},
	{27, "27"},
	{28, "28"},
	{29, "29"},
	{30, "30"},
	{31, "31"},
	{32, "32"},
	{33, "33"},
	{34, "34"},
	{35, "35"},
	{36, "36"},
	{37, "37"},
	{38, "38"},
	{39, "39"},
	{40, "40"},
	{41, "41"},
	{42, "42"},
	{43, "43"},
	{44, "44"},
	{45, "45"},
	{46, "46"},
	{47, "47"},
	{48, "48"},
	{49, "49"},
	{50, "50"}
};

