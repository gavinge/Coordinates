
#ifndef __INC_PUBLIB_UTILITY_XML_EC_H__
#define __INC_PUBLIB_UTILITY_XML_EC_H__

struct XmlEC
{
	//错误码
	enum XEC
	{
		XEC_SUCCESS = 0,				//成功
		XEC_INIT_FAIL,					//初始化失败
		XEC_MALLOC_XML_PARSER_FAIL,		//创建XML脚本解析对象失败
		XEC_MALLOC_MEM_FAIL,			//申请内存失败
		XEC_PARSE_XML_FAIL,				//解析XML失败
		XEC_SAVE_XML_FILE_FAIL,			//保存XML文件异常
		XEC_ELEMENT_NAME_EMPTY,			//获得元素的名为空
		XEC_CREATE_ELEMENT_FAIL,		//创建元素失败
		XEC_DOM_NODE_LIST_NULL,			//获得DOMNodeList的指针为空
		XEC_ELEMENT_NODE_NULL,			//无效的元素节点
		XEC_PARAM_FAIL,					//参数无效
		XEC_INSERT_CHILD_TEXT_FAIL,		//添加文本子节点异常
		XEC_REMOVE_CHILD_ELEMENT_FAIL,	//删除子节点异常
		XEC_INSERT_PRE_CHILD_ELEMENT_FAIL,//插入前驱子节点失败
		XEC_INSERT_NEXT_CHILD_ELEMENT_FAIL,//插入后继子节点失败
		XEC_GET_PARENT_ELEMENT_FAIL,		//获得父元素节点失败
		XEC_NO_EXIST_ATTR,				//不存在的属性
		XEC_ATTR_MAP_NULL,				//获得的DOMNamedNodeMap指针为空
		XEC_REMOVE_ATTR_FAIL,			//移除指定名属性异常
		XEC_REMOVE_ATTR_NODE_FAIL,		//移除属性对象异常
		XEC_EXIST_NAME_ATTR,			//同名属性节点已经存在
		XEC_NO_EXIST_NAME_ATTR,			//不存在属性节点已经存在
		XEC_SET_ATTR_OBJ_FAIL,			//设置属性对象异常
		XEC_SET_ATTR_NAME_VALUE_FAIL,	//设置属性名，值异常
		XEC_TEXT_NODE_NULL,				//DOM文本元素节点无效
		XEC_SET_TEXT_FAIL,				//设置文本节点值时异常
		XEC_GET_XPATH_ELEMENT_FAIL,		//获得Xpath路径下的所有文件异常
		XEC_DOM_EXPRESSION_NULL,		//创建Xpath表达式失败
		XEC_DOM_EVALUATE_NULL,			//计算Xpath表达式失败
		XEC_REMOVE_CHILD_NODE_FAIL,		//删除元素的子节点异常
		XEC_INSERT_FRONT_CHILD_FAIL,	//插入一个新子元素到所有子节点前面时异常
		XEC_INSERT_BACK_CHILD_FAIL,		//插入一个新子元素到所有子节点前面时异常
		XEC_DOM_DOC_NULL,				//解析脚本后的文档树为空
		XEC_CHILD_ELEMENT_EXIST,		//插入的文本节点位置已经存在元素节点
		XEC_NOT_TEXT_NODE_FAIL,			//未找到文本节点
		XEC_GET_ELEMENT_FAIL,			//获得元素失败
		XEC_ATTR_NODE_FAIL,				//属性节点无效
		XEC_CREATE_ATTR_FAIL			//创建属性节点异常
	};
};

#endif // ! __INC_PUBLIB_UTILITY_XML_EC_H__
