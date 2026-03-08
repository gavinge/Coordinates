#ifndef __XMLDOM_H__
#define	__XMLDOM_H__

#include <string>

typedef class IXmlNode		IXmlNode;

class CLiteXmlException
{
public:

	CLiteXmlException(const int nErrCode, char* szErrMess);

	virtual ~CLiteXmlException();

	const int errorCode() { return mnErrCode; }

	const char* errorMessage() { return mpszErrMess; }

private:
	int mnErrCode;
	char* mpszErrMess;
};

class IXmlNodeList
{
public:
	virtual IXmlNode* get_item(int index) = 0;
	virtual int get_length() = 0;
	virtual void release() = 0;
};

class IXmlNode
{
public:
	virtual const char*		get_name() = 0;
	virtual IXmlNode*		get_parent() = 0;

	virtual IXmlNode*		get_child(const char* name) = 0;
	virtual int				get_child_count() = 0;

	virtual IXmlNode*		get_firstchild() = 0;
	virtual IXmlNode*		get_lastchild() = 0;
	virtual IXmlNode*		get_prev() = 0;
	virtual IXmlNode*		get_next() = 0;

	virtual std::string		get_value() = 0;
	virtual int				set_value(const char* value) = 0;

	virtual std::string		get_text() = 0;
	virtual int				set_text(const char* text) = 0;

	virtual IXmlNode*		get_attributes() = 0;


	virtual IXmlNode*		create_attribute(const char* name, const char* value) = 0;
	virtual int				remove_attribute(const char* name) = 0;
	virtual int				set_attribute_value(const char* name, const char* value) = 0;
	virtual std::string		get_attribute_value(const char* name) = 0;


	virtual std::string		get_xml() = 0;

	virtual int				remove_child(IXmlNode* child) = 0;
	virtual int				replace_child(IXmlNode* oldChild, IXmlNode* newChild) = 0;

	virtual int				append_child(IXmlNode* child) = 0;
	virtual int				insert_before(IXmlNode* inserted) = 0;
	virtual int				insert_after(IXmlNode* after) = 0;

	virtual IXmlNode*		clone() = 0;
	virtual IXmlNodeList*	select_nodes(const char* xpath) = 0;
	virtual IXmlNode*		select_singlenode(const char* xpath) = 0;
	virtual void			release() = 0;
};


class IXmlDocument
{
public:
	virtual int load(const char* file) = 0;
	virtual int load_xml(const char* xml) = 0;

	
	virtual IXmlNode* get_docelement() = 0;
	virtual IXmlNode* create_node(const char* name) = 0;
	
	virtual int save(const char* file) = 0;
	virtual void release() = 0;

	virtual IXmlNode* create_cdata_node(const char* value) = 0;
};

#ifdef	__cplusplus
extern "C" 
#endif
IXmlDocument* newXmlDocument();



template<typename T>
class COncePtr
{
public:
	operator T*()
	{
		return this->_ptr;
	}

	T* operator ->()
	{
		return this->_ptr;
	}
public:
	COncePtr(T* ptr = 0) :_ptr(ptr)
	{

	}

	~COncePtr()
	{
		if (this->_ptr)this->_ptr->release();
	}
private:
	T*			_ptr;
};

typedef		COncePtr<IXmlNode>				XmlNode;
typedef		COncePtr<IXmlNodeList>			XmlNodeList;
typedef		COncePtr<IXmlDocument>			XmlDocument;


#endif // !__XMLDOM_H__
