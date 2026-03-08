
#ifndef  __INC_PUBLIB_UTILITY_XML_H__
#define  __INC_PUBLIB_UTILITY_XML_H__

#include <vector>
#include <string>
#include "xml_ec.h"
#include "xml_element.h"


namespace xercesc_3_0
{
	class XercesDOMParser ;
	class DOMDocument;
	class DOMXPathResult;
}

namespace JwUtility
{
	class CXml
	{


		public:

			CXml( void );
			~CXml( void );
			/**
			 * @brief		初始化
			 * */
			XmlEC::XEC init();

			/**
			 * @brief		释放
			 * */
			void release();


			/**
			 * @brief 读取配置脚本
			 *
			 * @param  strFilePath:文件路径
			 *
			 */
			XmlEC::XEC load( const std::string &strFilePath );

			/**
			 * @brief 保存配置脚本的修改
			 *
			 *
			 */
			XmlEC::XEC save( void );

			/**
			 * @brief 另存配置脚本的修改
			 *
			 * @param strFilePath:IN 保存XML的文件路径
			 *
			 */
			XmlEC::XEC save_as( const std::string &strFilePath );

			/**
			 *@brief 获得加载文档的根节点
			 *@param rootElement
			 */
			XmlEC::XEC get_root_element( CElement &rootElement );

			/**
			 * @brief 获得所有名为strName的元素节点,对于特殊值"*"将会返回所有的元素结点
			 *
			 * @param  strName:获得元素的名
			 * @param  vElement:所有此名的结点
			 *
			 * @return 返回值说明
			 */
			XmlEC::XEC search_element( const std::string &strName, std::vector< CElement > &vElement);

			/**
			 * @brief 获得指定路径下名为strPathName的节点,如果此路径下有多个同名元素，返回所有同名元素
			 * @details 
			 * <a>
			 *  <b> 
			 * 	  <front />
			 *    <c>aaaa</c>
			 *    <c>bbbb</c>
			 *    <back />
			 *  </b>
			 *  <b>
			 *    <front />
			 *    <c>cccc</c>
			 *    <back />
			 * </a> 	
			 * 要获得c节点，则写法为"/a/b/c",将返回所有"/a/b/c"的c节点,上面同有3个
			 *
			 * @param strPathName:元素节点路径
			 * @param vElement:所有指定路径下的元素
			 *
			 * @return 返回值说明
			 */
			XmlEC::XEC get_xpath_element( const std::string &strPathName, std::vector< CElement > &vElement);

			/**
			 *@brief 获得路径元素下的文本内容，如果文本路径存在多个同名
			 *		元素,则只返回第一个元素的文本内容
			 *@param strPathName 输入参数 元素路径写法如上
			 *@param strText 参数出参数 获得的文本内容
			 */
			XmlEC::XEC get_xpath_text( const std::string &strPathName, std::string &strText);

			/**
			 *@brief 获得路径元素下的文本内容，如果文本路径存在多个同名
			 *		元素,则只修改第一个元素的文本内容,如果此元素没有文本
			 *		内容，则将新文本内容插入
			 *@param strPathName 输入参数, 文本路径
			 *@param strText	 输入参数，文本内容
			 */
			XmlEC::XEC set_xpath_text( const std::string &strPathName, const std::string &strText);


			/**
			 *@brief 创建一个新元素
			 *@param strName 输入参数 新元素名
			 *@param newElement 输出参数 成功后返回会元素
			 */
			XmlEC::XEC create_element( const std::string &strName, CElement &newElement );

		private:


			/**
			 *@brief 获得xpath路径解析元素，如果返回非空，使用完后
			 *		调用release施放
			 *@param strXpath 输入参数 元素路径
			 *@param 非空指针 成功， 空指针 失败
			 */
			xercesc_3_0::DOMXPathResult *get_xpath_result( const std::string &strXpath);	

		private:
			xercesc_3_0::XercesDOMParser *m_pDOMXmlParser;				//XML对象解析器
			xercesc_3_0::DOMDocument	 *m_pDomDoc;					//解析XML文件后的文档树
			std::string 			  		m_strFilePath;				//XML保存的文件路径

			static int m_init_count;
	};

}

#endif // ! __INC_PUBLIB_UTILITY_XML_H__

