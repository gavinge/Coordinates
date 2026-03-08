

#ifndef __INC_PUBLIB_UTILITY_XML_ELEMENT_H__
#define __INC_PUBLIB_UTILITY_XML_ELEMENT_H__

#include <string>
#include "xml_ec.h"
#include <vector>

namespace xercesc_3_0
{
	class DOMElement;
	class DOMNode;
	class DOMDocument;
}


namespace JwUtility
{
	class CXml;
	class CElement
	{
		public:
			CElement( void );
			CElement( xercesc_3_0::DOMDocument *pDomDocument, xercesc_3_0::DOMElement *pDomElement);

			/**
			 *@brief 获得元素节点的名称
			 *
			 */
			std::string get_element_name();

			/**
			 *@brief 获得当前节点的父元素节点
			 *@param parentElement 输出参数 父元素节点
			 *@return 
			 */
			XmlEC::XEC get_parent_element( CElement &parentElement ) ;

			/**
			 *@brief 获得当前节点的文本内容,文本内容为空或失败时返回空串
			 *
			 *@return 获得的文本串
			 */
			std::string get_text( void );
			

			/**
			*@brief 获得子节点的内容,文本内容为空或失败时返回空串
			*@param parentElement 输入参数 子节点的名称
			*
			*@return 获得的子文本串
			*/
			std::string get_child_text(const std::string &strchild);


			/**
			 *@brief 添加文本,如果当前元素已经有文本
			 *		此操作，则文本内容添加到尾部，如果不存在文本
			 *		则插入新的文本内容
			 *
			 *@param strText 输入参数:文件内容
			 *@return 
			 */
			XmlEC::XEC insert_text( const std::string &strText);

			/**
			 *@brief 设置当前元素文本文本内容
			 *		如果当前元素无文本内容，则插入文本内容
			 *@param strText 输入参数设置的文本内容
			 *@return 
			 */
			XmlEC::XEC set_text( const std::string &strText);


			/**
			 *@brief 删除当前文本的子节点
			 *		如果没有文本内容或文本删除成功返回成功
			 *@return 
			 */
			XmlEC::XEC remove_text( void );


			/**
			 * @brief 获得当前元素节点的下一个元素节点
			 * @param nextElemnt 输出参数 下一个新元素
			 * @return 
			 */
			XmlEC::XEC get_next_element( CElement &nextElement );

			/**
			 * @brief 获得当前元素节点的下一个节点
			 * @param strName  输入参数 获得下一个名为name的兄弟节点
			 * @param nextElement 输出参数 下一个元素节点
			 * @return 
			 */
			XmlEC::XEC get_next_element( const std::string &strName, CElement &nextElement);

			/**
			 * @brief 获得当前元素节点的前驱元素节点
			 * @param preElement 输出参数  前驱兄弟元素
			 * @return 
			 */
			XmlEC::XEC get_pre_element( CElement &preElement );


			/**
			 * @brief 获得当前元素节点的前一个指定名的元素
			 * @param strName 输入参数  前驱兄弟元素名
			 * @param preElement 输出参数 前驱兄弟元素
			 * @return 
			 */
			XmlEC::XEC get_pre_element( const std::string &strName, CElement &preElement);

			/**
			 *@brief 获得当前节点的第一个子元素节点
			 *@param childElement 输出参数 子元素节点
			 *@return 
			 */
			XmlEC::XEC get_first_child_element( CElement &childElement );

			/**
			 *@brief 获得当前节点的第一个元素节点
			 *@param strName in 获得第一个名为strName的子元素
			 *@return 
			 */
			XmlEC::XEC get_first_child_element( const std::string &strName, CElement &childElement );

			/**
			 * @brief 获得当前元素节点的最后一个子元素节点
			 * @param childElement 输出参数 最后一个子元素
			 * @return 
			 */
			XmlEC::XEC get_last_child_element( CElement &childElement );


			/**
			 * @brief 获得的所有名为strChildName的子节点,如果没有strChildName同样返回成功
			 *
			 * @param strChild in :子节点的名
			 * @param vElement out: 名为strChildName的子节点
			 *
			 */
			XmlEC::XEC get_child_element( const std::string &strChildName, std::vector<CElement> &vElement); 


			/**
			 * @brief 获得当前节点的所有元素子节点
			 *
			 * @param  vElement: out  所有元素节点
			 *
			 */
			XmlEC::XEC get_all_child_element( std::vector<CElement> &vElement);

			/**
			 *@brief 插入一个新的孩子元素节点,到当前所有孩子节点的前面,
			 *		如果当前元素已经存于树中，首先会被移除
			 *@param childElement in 新孩子元素
			 */

			XmlEC::XEC insert_front_child( const CElement &childElement);

			/**
			 *@brief 插入一个新的孩子元素节点到当前所有孩子节点的后面
			 *		如果当前节点已经存于树中，则首先移除
			 *@param childElement in新的孩子元素
			 */
			XmlEC::XEC insert_back_child( const CElement &childElement );

			/**
			 *@brief 在现有子元素nextChildElement 之前插入新元素节点newChildElement
			 *			newChildElement已经存在于树中，则首先移除它。
			 *@param nextChildElement 输入参数 新插入元素的后继节点
			 *@param newChildElement 输入参数 新插入的子元素
			 *@return 
			 */
			XmlEC::XEC insert_pre_child_element( const CElement &nextChildElement, const CElement &newChildElement);

			/**
			 *@brief 在现有子元素preChildElement 之后插入新元素节点newChildElement。
			 *		newChildElement已经存在于树中，则首先移除它
			 *@param preChildElement 输入参数 新插入元素的后继节点
			 *@param newChildElement 输入参数 新插入的子元素
			 *@return 
			 */
			XmlEC::XEC insert_next_child_element( CElement &preChildElement, const CElement &newChildElement);

			/**
			 *@brief 插入前驱兄弟元素节点
			 *@param preElement 输入参数 插入前驱兄弟元素节点
			 */
			XmlEC::XEC insert_pre_element( const CElement &preElement);

			/**
			 *@brief 插入后继兄弟元素节点
			 *@param nextElement in 后继兄弟节点
			 */
			XmlEC::XEC insert_next_element( const CElement &nextElement);

			/**
			 *@brief 删除子元素
			 *@param pChildElement:被删除的节点
			 */
			XmlEC::XEC remove_child_element( const CElement &childElement);


			/**
			 *@brief 是否有指定名的子元素
			 *@param strName in 节点名
			 */
			bool has_child_element( const std::string &strName);

			/**
			 *@brief 根据属性名获得属性值
			 *@param strName in 属性名
			 *@param strValue out 对应的值
			 *@return 
			 */
			XmlEC::XEC get_attr(const std::string &strName, std::string &strValue);


			/**
			 *@brief 获得当前的元素的所有属性节点std::pair.first 属性名
			 *		std::pair.second 属性值
			 *@param vAttr out 获得所有属性
			 *@return 
			 */
			XmlEC::XEC get_attr( std::vector< std::pair<std::string, std::string> > &vAttr);

			/**
			 *@brief 当前元素节点是否有指定名的属性节点
			 *@param strName  in 节点名
			 */
			bool has_attr( const std::string &strName );


			/**
			 *@brief 删除指定名的属性节点,如果没有此名的属性
			 *		或属性删除成功，则返回成功，
			 *@param strName in  属性名
			 */
			XmlEC::XEC remove_attr( const std::string &strName );

			/**
			 *@brief 添加新属性对象 ,如果同名属性已经存在，返回失败
			 *@param strName in  属性名
			 *@param strValue in 属性值
			 */
			XmlEC::XEC insert_attr( const std::string &strName,  const std::string &strValue);

			/**
			 *@brief 设置属性,如果不存在此名属性添加此属性，找到替换此属性
 			 *		 值
			 *@param strName in  属性名
			 *@param strValue in 属性值
			 *@return 
			 */
			XmlEC::XEC set_attr( const std::string &strName,  const std::string &strValue);	

			/**
			*@brief 该方法将复制并返回调用它的节点的副本。如果传递
 			*	 给它的参数是 true，它还将递归复制当前节点的所有
 			*	 子孙节点。否则，它只复制当前节点。返回的节点不属于文档树
 			*	它的 parentNode 属性为 null
 			*
 			*@param bDeep:克隆深度 true:包括子节点一起克隆，false 不包括子节点,只克隆当前元素节点及其属性节点
 			*@param newElement 输出参数，克隆后的新元素
 			*/
			XmlEC::XEC clone(bool bDeep, CElement &newElement );

			~CElement( void );

		private:

			/**
			 *@brief 移除子节点(元素节点或文本节点)
			 *@param pNode in 移除的DOM节点
			 *
			 */
			XmlEC::XEC remove_child_node( xercesc_3_0::DOMNode *pNode );

		private:
			friend class CXml;
			xercesc_3_0::DOMElement *m_pDomElement;		//元素结点
			xercesc_3_0::DOMDocument *m_pDomDocument;	//文档树
	};

}

#endif // !__INC_PUBLIB_UTILITY_XML_ELEMENT_H__

