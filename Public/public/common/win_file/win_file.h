/*
* 文件名:  win_file.h
* 作者: geshan@hotmail.com
* 创建日期: 2023-12-25
* 描述: CWinFile 头文件，Windows平台下常用文件操作
*/


#ifndef __UTILITY_FILE_H__
#define __UTILITY_FILE_H__
#include <windows.h>
#include <string>
#include <vector>

namespace JwUtility
{

	/*
	 * @brief	常用文件操作
	 * */
	class CWinFile
	{
		public:

			enum EC
			{
				EC_SUCCESS = 0,			/*成功*/
				EC_PATH_NULL_ERROR,		/*路径为空*/
				EC_GET_DIRLIST_ERROR,	/*获得磁盘列表失败*/
				EC_CALLBACK_ERROR,		/*调用回调函数失败*/
				EC_ILLEGAL_PATH_ERROR,	/*错误的路径*/
				EC_DIREXIST_ERROR,		/*目录已经存在*/
				EC_FILE_EXIST_ERROR,		/*文件已经存在*/
				EC_CREATE_FILE_ERROR,	/*创建文件失败*/
				EC_CREATE_DIR_ERROR,		/*创建文件夹失败*/
				EC_CREATE_ERROR,			/*创建失败*/
				EC_DELFILE_ERROR,		/*删除文件失败*/
				EC_DELDIR_ERROR,			/*删除目录失败*/
				EC_RENAME_ERROR,			/*重命名失败*/
				EC_SETMODE_ERROR,		/*修改文件属性失败*/
				EC_ILLEGAL_FILE_ERROR,	/*非法的文件*/
				EC_FILE_ATTR_ERROR,		/*文件没有指定的属性*/
				EC_EXIST_ERROR,			/*文件不存在*/
				EC_MALLOC_ERROR			/*申请内存失败*/
			};

			/**
			* 枚举类型SubType用于标识不同的枚举类型
			*/
			enum SubType
			{
				ST_DIR = 0,		/*文件夹*/
				ST_FILE,		/*文件*/
				ST_DRIVE,		/*驱动器*/
				ST_ALL,			/*所有类型*/
			};

			/**
			* 是否有某些子项
			*/
			enum HasSubItem
			{
				HSI_NULL = 0,	/*没有*/
				HSI_DIR = 0x01,	/*文件夹*/
				HSI_FILE = (0x01 << 1)/*文件*/
			};

			/**
			* 枚举类型,用于常量
			*/
			enum
			{
				MIN_FILE_PATH_LEN = 3,			/*最小文件长*/
				MAX_TIME_LINE = 30				/*时间最大串长*/
			};

			//结构体WIN_FILE_DATA的定义
			struct WIN_FILE_DATA
			{
				DWORD size_high_32b;			/*文件大小高位*/
				DWORD size_low_32b;				/*文件大小低位*/
				SubType type;					/*文件类型*/
				DWORD att;						/*文件属性*/
				HasSubItem has_sub_item;		/*子项*/
				std::string name;				/*文件名*/
				std::string ctime;				/*文件创建时间*/
				std::string mtime;				/*文件最后修改时间*/
			};

			/**
			 *@brief 回调函数说明
			 *@parma param 返回给回调的参数，可为任意值
			 *@param file_data  文件信息，具体可参考WIN_FILE_DATA 的定义
			 *@@reuturn 0 表示回调成功，非0回调失败
			 */
			typedef int (* FILE_CALLBACK)( void *param, const WIN_FILE_DATA &file_data);

			/**
			* @brief				获得可使用磁盘配额的所有磁盘,如果调用回调返回败，将会立即返回
			* @param pathname		输入参数, 待查询的目录
			* @param st				要取得目录/文件/全部, ST_DIR为目录, ST_FILE为文件, ST_ALL为所有
			* @param wildcard		扩展名,如果为空,则不做过滤
			* @param file_deal		回调函数,回调函数返回0时结束
			* @param param		用来传给回调函数的参数
			* @return				成功返回EC_SUCCESS, 失败返回对应的错误码
			*/	
			static int get_quota_disk(const std::string &pathname, const SubType &st, const std::string  &wildcard, FILE_CALLBACK file_deal, void *param);

			/**
			* @brief				获得一个目录下的子项,如果调用回调返回败，将会立即返回
			* @param pathname		输入参数, 待查询的目录
			* @param st				要取得目录/文件/全部, ST_DIR为目录, ST_FILE为文件, ST_ALL为所有
			* @param wildcard		扩展名,如果为空,则不做过滤
			* @param file_deal		回调函数,回调函数返回0时结束
			* @param param		    用来传给回调函数的参数
			* @return				成功返回EC_SUCCESS, 失败返回对应的错误码
			*/
			static int get_sub_item(const std::string &pathname, const SubType &st, const std::string  &wildcard, FILE_CALLBACK file_deal, void *param);

			/**
			 * @brief				创建一个文件
			 * @param	filename	输入参数，待创建的文件名
			 * @param	st			输入参数，创建的文件类型
			 * @return				成功返回EC_SUCCESS, 失败返回对应的错误码
			 */
			static int create_item(const std::string &filename, SubType mode);

			/**
			 * @brief				删除一个文件
			 * @param item			输入参数，待删除的文件名
			 * @return				成功返回EC_SUCCESS, 失败返回对应的错误码
			 */
			static int delete_item( const std::string  &item);

			/**
			 * @brief				重命名一个文件
			 * @param	oldname		输入参数，旧的文件的文件名
			 * @param	newname		输入参数，新的文件名
			 * @return				成功返回EC_SUCCESS, 失败返回对应的错误码
			 */
			static int rename_item( const std::string  &oldname, const std::string  &newname);

//			/**
//			 * @brief				修改一个文件的访问属性
//			 * @param item			输入参数，待修改文件的文件名
//			 * @param mode			输入参数，文件的访问属性
//			 */
//			static int mod_mode( const std::string  &item, FileMode mode);

			/**
			 * @brief				判断一个文件是否存在
			 * @param filename		输入参数， 待判断的文件名
			 * @return				文件存在返回EC_SUCCESS, 否则返回对应的错误码
			 */
			static int is_existed_file(const std::string &filename);

			/**
			 * @brief				判断一个文件是否有某项属性,可以同时判断多个属性
			 * @param filename		输入参数， 待判断的文件完整路径
			 * @param attr			要判断的属性
			 * @return				文件返回EC_SUCCESS,表示有指定的属性, 否则返回对应的错误码
			 */
			static int has_file_attr(const std::string &filename, unsigned int attr );


			/**
			 * @brief				整判断一个文件名是否是一个有效的文件名
			 * @param filename		输入参数，待检查的文件名
			 * @return				true 文件名有效, false 无效
			 */
			static bool is_valid_file_name(const std::string &filename);

			/**
			* @brief	判断文件路径是否为合法路径,文件路径可以"\\"结尾
			*
			* @param filepath	文件路径
			*
			* @return 	返回true表示成功, 返回false表示失败
			*/
			static bool is_valid_file_path(const std::string &filepath);
			
			/**
			* @brief 判断用户指定的文件路径下是否有文件和文件夹
			*
			* @param  filepath 用户指定的文件路径
			*
			*/
			static HasSubItem has_subitem(const std::string &filepath);

		private:

			/**
			 *@brief 将FILETIME 的时间转换成类似 "2009-02-01 13:01:01"格式的字符串
			 *@param file_time 系统时间
			 *@return 格式化后的时间
			 */
			static std::string format_file_time( const FILETIME &file_time);

			/**
			* @brief 获取磁盘列表
			*
			* @param  drvlist 存放磁盘符的数组
			*
			*/
			static void get_drive_list( std::vector<std::string> &drvlist);
	};
}
#endif

