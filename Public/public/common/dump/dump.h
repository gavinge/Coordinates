/*
* 文件名: dump.h
* 作者: geshan@hotmail.com
* 创建日期: 2023-12-25
* 描述: CDump类头文件，用于完成数据内存的转储操作
*/

#ifndef __UTILITY_DUMP_H__
#define __UTILITY_DUMP_H__
#include <iostream>

namespace JwUtility
{
	/* *
	 * @brief	把一段buffer打印为16进制
	 * */
	class CDump
	{
		public:
			enum EC
			{
				EC_SUCCESS = 0,		/*执行成功*/
				EC_PARAM_ERROR,		/*参数错误*/
				EC_ALLOC_MEM_ERROR,	/*分配内存失败*/
			};

			/* *
			 * @brief			把一个buf打印成十六进制，并输出到标准输出
			 * @param buf		输入参数，待dump的buffer
			 * @param len		输入参数，buf的长度
			 * @return			成功返回EC_SUCCESS, 否则返回对应的错误码
			 * */
			static int dump(char * buf, size_t len);

			/* *
			 * @brief			把一个buf打印成十六进制，并输出到指定文件
			 * @param stream	输入参数, 打开的文件
			 * @param buf		输入参数，待dump的buffer
			 * @param len		输入参数，buf的长度
			 * @return			成功返回EC_SUCCESS, 否则返回对应的错误码
			 * */
			static int fdump(FILE * stream, char * buf, size_t len);

			/* *
			 * @brief			把一个buf打印成十六进制，并输出到一个buf中
			 * @param str		输出参数，输出dump出来的内容
			 * @param size		输入参数，指定str的最大大小
			 * @param buf		输入参数，待dump的buffer
			 * @param len		输入参数，buf的长度
			 * @return			成功返回EC_SUCCESS, 否则返回对应的错误码
			 * */
			static int sndump(char * str, size_t size, char * buf, size_t len);

			/* *
			 * @brief			设置每行dump的字节数
			 * @param max_line	输入参数，m_max_line的新值	
			 * */
			static void setmaxline(size_t max_line);

			/* *
			 * @brief			获得每行dump的字节数
			 * @return			返回m_max_line的值	
			 * */
			static size_t getmaxline();

			private:
			static size_t m_max_line;		/*每行要dump的字节数, 默认是16*/
			
	};
}

#endif //!__UTILITY_DUMP_H__

