#ifndef GLOBALAGENTGROUPMENUITEMENUM_H
#define GLOBALAGENTGROUPMENUITEMENUM_H

///Agent分组菜单响应标记
enum class AgentGroupMenuItemEnum {
    Separator = 2000,             //分割线
    SubMenu   = 2001,             //子菜单
    CustomDefineGroupBase = 2002, //自定义菜单基础
    AddGroup = CustomDefineGroupBase + 1,        //增加分组
    DelGroup = CustomDefineGroupBase + 2,        //删除分组
    RenameGroup = CustomDefineGroupBase + 3,     //重命名分组
};

#endif // GLOBALAGENTGROUPMENUITEMENUM_H
