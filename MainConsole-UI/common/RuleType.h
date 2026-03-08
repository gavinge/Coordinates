#ifndef RULETYPE_H
#define RULETYPE_H

///规则类型
enum class RuleType {
    ProcessRuleType = 1, //进程
    FileRuleType    = 2, //文件
    ModuleRuleType  = 3, //模块
    KernelRuleType  = 4, //内核模块
    NetworkRuleType = 5, //网络
    DomainRuleType = 9,  //域名
    WindowRuleType = 10,      //窗口
    RegistryRuleType = 6, //注册表
    ProtectionRuleType=11,//保护？？？？？
    ThreadRuleType  = 14, //线程
};



///内部规则分类
enum class InnerRuleClassify {
    All = 0,            //所有类型
    Accounting  = 1,    //计费类
    DiskLess    = 2,    //无盘类
    Marketing   = 3,    //营销类
    Entertainment  = 4, //文娱类
    Security = 5,       //安全类
    Comprehensive = 6,  //综合类
};


#endif // RULETYPE_H
