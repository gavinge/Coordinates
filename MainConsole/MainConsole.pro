QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    about/aboutwidget.cpp \
    agent_man/AgentManAddGroupWidget.cpp \
    agent_man/AgentManDelGroupWidget.cpp \
    agent_man/AgentManDisableChargeWidget.cpp \
    agent_man/AgentManRenameGroupWidget.cpp \
    agent_man/agent_man_custom_listwidget_item.cpp \
    agent_man/agentmanwidget.cpp \
    common/MessageBoxWidget.cpp \
    common/custom_menu.cpp \
    custom_rule/customrulewidget.cpp \
    custom_rule/domain/DomainRuleDetailWidget.cpp \
    custom_rule/file/FileRuleDetailWidget.cpp \
    custom_rule/kernel/KernelRuleDetailWidget.cpp \
    custom_rule/module/ModuleRuleDetailWidget.cpp \
    custom_rule/network/NetWorkRuleDetailWidget.cpp \
    custom_rule/process/ProcessRuleDetailWidget.cpp \
    custom_rule/protect/ProtectionRuleDetailWidget.cpp \
    custom_rule/register/RegisterRuleDetailWidget.cpp \
    custom_rule/rule_center/CustomRuleCenterWidget.cpp \
    custom_rule/rule_center/domain_detail/DomainRuleEditDetailWidget.cpp \
    custom_rule/rule_center/file_detail/FileRuleEditDetailWidget.cpp \
    custom_rule/rule_center/kernel_detail/KernelRuleEditDetailWidget.cpp \
    custom_rule/rule_center/module_detail/ModuleRuleEditDetailWidget.cpp \
    custom_rule/rule_center/network_detail/NetWorkRuleEditDetailWidget.cpp \
    custom_rule/rule_center/process_detail/ProcessRuleEditDetailWidget.cpp \
    custom_rule/rule_center/protect_detail/ProtectionRuleEditDetailWidget.cpp \
    custom_rule/rule_center/register_detail/RegisterRuleEditDetailWidget.cpp \
    custom_rule/rule_center/thread_detail/ThreadRuleEditDetailWidget.cpp \
    custom_rule/rule_center/window_detail/WindowRuleEditDetailWidget.cpp \
    custom_rule/thread/ThreadRuleDetailWidget.cpp \
    custom_rule/window/WindowRuleDetailWidget.cpp \
    home/homewidget.cpp \
    inner_rule/innerrulewidget.cpp \
    main.cpp \
    run_app/runappwidget.cpp \
    setting/settingwidget.cpp \
    widget.cpp

HEADERS += \
    about/aboutwidget.h \
    agent_man/AgentManAddGroupWidget.h \
    agent_man/AgentManDelGroupWidget.h \
    agent_man/AgentManDisableChargeWidget.h \
    agent_man/AgentManRenameGroupWidget.h \
    agent_man/agent_man_custom_listwidget_item.h \
    agent_man/agentmanwidget.h \
    common/GlobalAgentGroupMenuItemEnum.h \
    common/GlobalDefineUtility.h \
    common/ItemDelegate.h \
    common/MessageBoxWidget.h \
    common/RuleType.h \
    common/custom_menu.h \
    custom_rule/CustomRuleUtility.h \
    custom_rule/customrulewidget.h \
    custom_rule/domain/DomainRuleDetailWidget.h \
    custom_rule/file/FileRuleDetailWidget.h \
    custom_rule/kernel/KernelRuleDetailWidget.h \
    custom_rule/module/ModuleRuleDetailWidget.h \
    custom_rule/network/NetWorkRuleDetailWidget.h \
    custom_rule/process/GlobalDefineUtility.h \
    custom_rule/process/ProcessRuleDetailWidget.h \
    custom_rule/protect/ProtectionRuleDetailWidget.h \
    custom_rule/register/RegisterRuleDetailWidget.h \
    custom_rule/rule_center/CustomRuleCenterWidget.h \
    custom_rule/rule_center/domain_detail/DomainRuleEditDetailWidget.h \
    custom_rule/rule_center/file_detail/FileRuleEditDetailWidget.h \
    custom_rule/rule_center/kernel_detail/KernelRuleEditDetailWidget.h \
    custom_rule/rule_center/module_detail/ModuleRuleEditDetailWidget.h \
    custom_rule/rule_center/network_detail/NetWorkRuleEditDetailWidget.h \
    custom_rule/rule_center/process_detail/ProcessRuleEditDetailWidget.h \
    custom_rule/rule_center/protect_detail/ProtectionRuleEditDetailWidget.h \
    custom_rule/rule_center/register_detail/RegisterRuleEditDetailWidget.h \
    custom_rule/rule_center/thread_detail/ThreadRuleEditDetailWidget.h \
    custom_rule/rule_center/window_detail/WindowRuleEditDetailWidget.h \
    custom_rule/thread/ThreadRuleDetailWidget.h \
    custom_rule/window/WindowRuleDetailWidget.h \
    home/homewidget.h \
    inner_rule/innerrulewidget.h \
    run_app/runappwidget.h \
    setting/settingwidget.h \
    widget.h

FORMS += \
    about/aboutwidget.ui \
    agent_man/AgentManAddGroupWidget.ui \
    agent_man/AgentManCustomListWidgetItem.ui \
    agent_man/AgentManDelGroupWidget.ui \
    agent_man/AgentManDisableChargeWidget.ui \
    agent_man/AgentManRenameGroupWidget.ui \
    agent_man/agentmanwidget.ui \
    common/MessageBoxWidget.ui \
    custom_rule/customrulewidget.ui \
    custom_rule/domain/DomainRuleDetailWidget.ui \
    custom_rule/file/FileRuleDetailWidget.ui \
    custom_rule/kernel/KernelRuleDetailWidget.ui \
    custom_rule/module/ModuleRuleDetailWidget.ui \
    custom_rule/network/NetWorkRuleDetailWidget.ui \
    custom_rule/process/ProcessRuleDetailWidget.ui \
    custom_rule/protect/ProtectionRuleDetailWidget.ui \
    custom_rule/register/RegisterRuleDetailWidget.ui \
    custom_rule/rule_center/CustomRuleCenterWidget.ui \
    custom_rule/rule_center/domain_detail/DomainRuleEditDetailWidget.ui \
    custom_rule/rule_center/file_detail/FileRuleEditDetailWidget.ui \
    custom_rule/rule_center/kernel_detail/KernelRuleEditDetailWidget.ui \
    custom_rule/rule_center/module_detail/ModuleRuleEditDetailWidget.ui \
    custom_rule/rule_center/network_detail/NetWorkRuleEditDetailWidget.ui \
    custom_rule/rule_center/process_detail/ProcessRuleEditDetailWidget.ui \
    custom_rule/rule_center/protect_detail/ProtectionRuleEditDetailWidget.ui \
    custom_rule/rule_center/register_detail/RegisterRuleEditDetailWidget.ui \
    custom_rule/rule_center/thread_detail/ThreadRuleEditDetailWidget.ui \
    custom_rule/rule_center/window_detail/WindowRuleEditDetailWidget.ui \
    custom_rule/thread/ThreadRuleDetailWidget.ui \
    custom_rule/window/WindowRuleDetailWidget.ui \
    home/homewidget.ui \
    inner_rule/innerrulewidget.ui \
    run_app/runappwidget.ui \
    setting/settingwidget.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc \
    qss.qrc
