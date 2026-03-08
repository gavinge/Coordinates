/*
* 文件名: win_reg.h
* 作者: geshan@hotmail.com
* 创建日期: 2023-12-25
* 描述: CWinReg 头文件，Windows平台下常用注册表操作
*/
#ifndef	__UTILITY_REG_H__
#define __UTILITY_REG_H__
#include <windows.h>
#include <string>
#include <vector>

namespace JwUtility
{
	/*
	* @brief	常用注册表操作
	* */
	class CWinReg
	{
	public:
		enum EC
		{
			EC_SUCCESS = 0,					/*成功*/
			EC_PARAM_ERROR,					/*参数错误*/
			EC_REG_PATH_ERROR,				/*非法的路径*/
			EC_QUERY_INFO_KEY_ERROR,		/*查询键信息失败*/
			EC_NEW_MEM_ERROR,				/*申请内存失败*/
			EC_REG_KEY_EXIST_ERROR,			/*key已经存在*/
			EC_REG_SET_VALUE_ERROR,			/*设置键值时出现错误*/
			EC_ENUM_KEY_ERROR,				/*枚举子键失败*/
			EC_REG_DELETE_KEY_ERROR,		/*删除注册表键失败*/
			EC_REG_DELETE_VALUE_ERROR,		/*删除键值失败*/
			EC_REG_QUERY_VALUE_ERROR,		/*查询值信息失败*/
			EC_REG_VALUE_EXIST_ERROR,		/*新名键值已经存在*/
			EC_REG_SAVE_KEY_ERROR,			/*保存注册表项失败*/
			EC_REG_CREATE_KEY_ERROR,		/*创建key失败*/
			EC_REG_RESTORE_KEY_ERROR,		/*恢复注册表项失败*/
			EC_GET_ROOT_HKEY_ERROR,			/*获得根节点失败*/
			EC_REG_OPEN_KEY_ERROR,			/*打开key失败*/
			EC_CALLBACK_ERROR,				/*回调函数调用结束*/
			EC_REG_EXIST_ERROR,				/*指定的注册表值已存在*/
		};

		//结构体WIN_KEY_REG_DATA的定义
		struct WIN_KEY_REG_DATA
		{
			std::string name;				/*健名*/
			int sub_key_num;				/*是否有子健*/
			int sub_value_num;				/*值的数目*/
		};

		//结构体WIN_VALUE_REG_DATA的定义
		struct WIN_VALUE_REG_DATA
		{
			DWORD type;						/*值项类型*/
			std::string name;				/*值项名*/
			std::vector< unsigned char> data;/*值项的数据*/
		};

		/**
		 * @brief 获得每一项注册键处理的回调函数
		 * @param param  输入参数 回调函数的默认第一个参数
		 * @param reg_data 输入参数 注册表数据处理
		 *
		 * @return 0表示回调成功，非0回调失败
		 */
		typedef int (* KEY_REG_CALLBACK)( void *param, const WIN_KEY_REG_DATA &reg_key_data);

		/**
		 * @brief 获得每一项注册值处理的回调函数
		 * @param param  输入参数 回调函数的默认第一个参数
		 * @param reg_data 输入参数 注册表数据处理
		 *
		 * @return 0表示回调成功，非0回调失败
		 */
		typedef int (* VALUE_REG_CALLBACK)( void *param, const WIN_VALUE_REG_DATA &reg_value_data);

		/**
		* @brief				获得一个目录下的所有key
		* @param path			输入参数, 待查询的目录
		* @param key_data_deal	回调函数,如果回调函数返回非0时将会结束调用
		* @param param			用来传给回调函数的参数
		* @return				成功返回EC_SUCCESS, 失败返回对应的错误码
		*/
		static int get_subitem_key( const std::string &path, KEY_REG_CALLBACK key_data_deal, void *param, bool is_64_key = false);

		/**
		* @brief				获得一个key下的所有值
		* @param path			输入参数, 待查询的key
		* @param value_data_deal 输入参数,用于处理KEY下的每一个注册表值
		* @param parma 			输入参数，默认传给回调函数的参数
		* @return				成功返回EC_SUCCESS, 失败返回对应的错误码
		*/
		static int get_subitem_values( const std::string &path, VALUE_REG_CALLBACK value_data_deal, void *param, bool is_64_key = false);

		/**
		* @brief				获得一个key下指定节点的值
		* @return				成功返回EC_SUCCESS, 失败返回对应的错误码
		*/
		static int get_subitem_value( const std::string &path, const std::string &item, DWORD& type, std::string& value, bool is_64_key = false);


		/**
		* @brief				获得一个key下指定DWORD节点的值
		* @return				成功返回EC_SUCCESS, 失败返回对应的错误码
		*/
		static int get_subitem_dword_value(const std::string &path, const std::string &item, DWORD& value, bool is_64_key = false);
		static int set_subitem_dword_value(const std::string &path, const std::string &item, DWORD& value, bool is_64_key = false);
		static int get_subitem_string_value(const std::string &path, const std::string &item, std::string& value, bool is_64_key = false);
		static int set_subitem_string_value(const std::string &path, const std::string &item, const std::string& value, bool is_64_key = false);
		/**
		* @brief				创建一个key
		* @param path			输入参数, 要创建的key所在的路径
		* @param kname			输入参数,要创建的key名称
		* @return				成功返回EC_SUCCESS, 失败返回对应的错误码
		*/
		static int create_subitem_key( const std::string  &path, const std::string  &kname, bool is_64_key = false);

		/**
		* @brief				创建value
		* @param path			输入参数, 要创建的value所属的key
		* @param vrd			输入参数,要创建的value名称
		* @return				成功返回EC_SUCCESS, 失败返回对应的错误码
		*/
		static int create_subitem_values( const std::string  &path, const WIN_VALUE_REG_DATA &vrd, bool is_64_key = false);

		/**
		* @brief				删除一个key
		* @param path			输入参数, 要删除的key路径
		* @return				成功返回EC_SUCCESS, 失败返回对应的错误码
		*/
		static int del_subitem_key( const std::string  &path, bool is_64_key = false);

		/**
		* @brief				删除一个value
		* @param path			输入参数, 要删除的value所在的key路径
		* @param name			输入参数，要删除的value名
		* @return				成功返回EC_SUCCESS, 失败返回对应的错误码
		*/
		static int del_subitem_values( const std::string  &path, const std::string  &name, bool is_64_key = false);

		/**
		* @brief				重命名一个value
		* @param path			输入参数, 待重命名的value所在的key路径
		* @param old_name		输入参数，value的原名
		* @param new_name		输入参数，value的新名
		* @return				成功返回EC_SUCCESS, 失败返回对应的错误码
		*/
		static int rename_subitem_values( const std::string  &path, const std::string  &old_name, const std::string  &new_name, bool is_64_key = false);

		/**
		* @brief				重命名一个key
		* @param path			输入参数, 待重命名的key路径
		* @param old_name		输入参数，key的原名
		* @param new_name		输入参数，key的新名
		* @return				成功返回EC_SUCCESS, 失败返回对应的错误码
		*/
		static int rename_subitem_key( const std::string  &path, const std::string  &old_name, const std::string  &new_name, bool is_64_key = false);

		/**
		* @brief 打开注册表键
		*
		* @param  path 注册表键的路径
		* @param  sub	注册表子键
		* @param  hkey 注册表子键的句柄
		* @param  h_root 注册表根键的句柄
		* 
		* @return 
		*/
		static int open_reg_key(const std::string & path, std::string & sub, HKEY & hkey, HKEY & h_root, bool is_64_key/* = false*/,REGSAM samDesired = KEY_ALL_ACCESS);

	private:

		//常数定义
		enum
		{
			ITEM_NAME_MAXLEN = 256,			/*表示子键字符串的长度*/
			ITEM_VALUE_MAXLEN = 512,		/*表示键值的长度*/
			ITEM_NUMBER_MAXLEN = 1024,		/*表示键值的数目*/
		};

		//字符串数量定义
		static const char* strHKCR() { return "HKEY_CLASSES_ROOT"; } 
		static const char* strHKLM() { return "HKEY_LOCAL_MACHINE"; } 
		static const char* strHKCU() { return "HKEY_CURRENT_USER"; } 
		static const char* strHKU() { return "HKEY_USERS"; } 
		static const char* strHKCC() { return "HKEY_CURRENT_CONFIG"; } 
		static const char* strRegFile() { return "regtmp.txt"; } 

		/**
		* @brief				获取注册表根键信息
		* @param c				回调函数,回调函数返回0时结束
		* @param param		用来传给回调函数的参数
		* @return 
		*/
		static int get_root_key_list(KEY_REG_CALLBACK key_data_deal, void * param);

		static BOOL RestorePrivilege( BOOL bEnable );
		
		static BOOL BackupPrivilege( BOOL  bEnable );


		/**
		* @brief 根据当前操作系统确定一个准确的操作权限
		*
		* @return
		*/
		static void AppendRegSam(REGSAM& samDesired, const std::string& key_path, bool is_64_key/* = false*/);
	};

}

#endif // ! __UTILITY_REG_H__



