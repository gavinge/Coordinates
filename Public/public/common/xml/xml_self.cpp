

#include "xml_self.h"



using namespace JwUtility;

bool CXmlEx::write_xml_attribute(const std::string& path, const std::string& xpath,  const std::string& name, const std::string& value)
{	
	bool rt = false;

	XmlDocument doc = newXmlDocument();

	do 
	{
		try
		{
			if(!doc->load(path.c_str()))
				break;

			XmlNode root = doc->get_docelement();
			XmlNode node =  root->select_singlenode(xpath.c_str());
			if (NULL == node)
				break;

			node->set_attribute_value(name.c_str(), value.c_str());
			if(doc->save(path.c_str()) <= 0)
				break;

			rt = true;

		}
		catch (CLiteXmlException& e)
		{
			return false;
		}

	}while(false);

	return rt;
}

bool CXmlEx::write_xml_node(const std::string& path, const std::string& xpath,  const std::string& value)
{
	bool rt = false;

	XmlDocument doc = newXmlDocument();

	do 
	{
		try
		{
			if(!doc->load(path.c_str()))
				break;

			XmlNode root = doc->get_docelement();
			XmlNode node =  root->select_singlenode(xpath.c_str());
			if (NULL == node)
				break;

			node->set_text(value.c_str());
			if(doc->save(path.c_str()) <= 0)
				break;

			rt = true;
		}
		catch (CLiteXmlException& e)
		{
			return false;
		}

	}while(false);

	return rt;
}


bool CXmlEx::read_xml_attribute(const std::string& path, const std::string& xpath,  const std::string& name, std::string& value)
{
	bool rt = false;

	XmlDocument doc = newXmlDocument();

	do 
	{
		try
		{
			if(!doc->load(path.c_str()))
				break;

			XmlNode root = doc->get_docelement();
			XmlNode node =  root->select_singlenode(xpath.c_str());
			if (NULL == node)
				break;

			value = node->get_attribute_value(name.c_str());

			rt = true;
		}
		catch (CLiteXmlException& e)
		{
			return false;
		}

	}while(false);

	return rt;
}

bool CXmlEx::read_xml_node(const std::string& path, const std::string& xpath, std::string& value)
{
	bool rt = false;

	XmlDocument doc = newXmlDocument();

	do 
	{
		try
		{
			if(!doc->load(path.c_str()))
				break;

			XmlNode root = doc->get_docelement();
			XmlNode node =  root->select_singlenode(xpath.c_str());
			if (NULL == node)
				break;

			value = node->get_text();

			rt = true;
		}
		catch (CLiteXmlException& e)
		{
			return false;
		}

	}while(false);

	return rt;
}


bool CXmlEx::add_xml_xpath_node(const std::string &path, const std::string &xpath)
{
	bool rt = false;

	XmlDocument doc = newXmlDocument();

	try
	{
		do
		{
			if (!doc->load(path.c_str()))
			{
				break;
			}

			XmlNode root = doc->get_docelement();

			// check xpath is exist
			if (root->select_singlenode(xpath.c_str()) != NULL)
			{
				// xpath is exist, return true;
				break;
			}

			size_t pos = xpath.find_last_of('/');
			std::string sub_xpath = xpath.substr(0, pos);
			std::string new_node_name = xpath.substr(pos+1);

			XmlNode new_node = doc->create_node(new_node_name.c_str());

			XmlNode father_node = root->select_singlenode(sub_xpath.c_str());
			father_node->append_child(new_node);

			if(doc->save(path.c_str()) <= 0)
			{
				break;
			}

		} while (0);

		rt = true;
	}
	catch (CLiteXmlException &e) {}

	return rt;
}

bool CXmlEx::del_xml_xpath_node(const std::string& path, const std::vector<std::string>& xpath_vec)
{
	bool ret = false;

	XmlDocument doc = newXmlDocument();

	try {
		do {
			if (!doc->load(path.c_str())) {
				break;
			}

			XmlNode root = doc->get_docelement();

			for (unsigned int i = 0; i < xpath_vec.size(); i++) {
				const std::string& xpath = xpath_vec[i];
				XmlNode del_node = root->select_singlenode(xpath.c_str());

				if (del_node) {
					// 删除所有子节点
					std::string all_child_xpath = xpath + "/*";
					XmlNodeList del_child_nodes = del_node->select_nodes(all_child_xpath.c_str());
					if (del_child_nodes) {
						for (int j = 0; j < del_child_nodes->get_length(); j++) {
							del_node->remove_child(del_child_nodes->get_item(j));
						}
					}
					
					// 删除所有本节点
					XmlNode parent = del_node->get_parent();
					if (parent) {
						parent->remove_child(del_node);
					}	
				}
			}

			if(doc->save(path.c_str()) <= 0) {
				break;
			}

			ret = true;
		} while (0);
	}
	catch (CLiteXmlException &e) {}

	return ret;
}

bool CXmlEx::replace_xml_cdata_node(const std::string& path, const std::map<std::string, std::string>& cdata_value_map)
{
	bool ret = false;

	XmlDocument doc = newXmlDocument();

	try {
		do {
			if (!doc->load(path.c_str())) {
				break;
			}

			XmlNode root = doc->get_docelement();

			std::map<std::string, std::string>::const_iterator it = cdata_value_map.begin();
			for (it; it != cdata_value_map.end(); it++) {
				XmlNode old_rule_node = root->select_singlenode(it->first.c_str());
				if (!old_rule_node) {
					continue;
				}

				XmlNode parent = old_rule_node->get_parent();
				if (!parent) {
					continue;
				}

				XmlNode new_rule_node = doc->create_node("rule");
				XmlNode cdata_node = doc->create_cdata_node(it->second.c_str());
				if (!new_rule_node || !cdata_node) {
					continue;
				}

				new_rule_node->append_child(cdata_node);
				parent->replace_child(old_rule_node, new_rule_node);
			}

			if(doc->save(path.c_str()) <= 0) {
				break;
			}

			ret = true;
		} while (0);
	}
	catch (CLiteXmlException &e) {}

	return ret;	
}
