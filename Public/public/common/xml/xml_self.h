

#ifndef _UTILITY_SELF_XML
#define _UTILITY_SELF_XML

#include "xmldom.h"
#include <string>
#include <vector>
#include <map>

namespace JwUtility
{
	class CXmlEx
	{

	public:
		static bool write_xml_attribute(const std::string& path, const std::string& xpath,  const std::string& name, const std::string& value);
		static bool write_xml_node(const std::string& path, const std::string& xpath,  const std::string& value);

		static bool read_xml_attribute(const std::string& path, const std::string& xpath,  const std::string& name, std::string& value);
		static bool read_xml_node(const std::string& path, const std::string& xpath, std::string& value);
	
		static bool add_xml_xpath_node(const std::string &path, const std::string &xpath);

		static bool del_xml_xpath_node(const std::string& path, const std::vector<std::string>& xpath_vec);
		static bool replace_xml_cdata_node(const std::string& path, const std::map<std::string, std::string>& cdata_value_map);
	};
}

#endif
