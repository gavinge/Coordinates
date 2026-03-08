
/*
* 文件名: dump.cpp
* 作者: geshan@hotmail.com
* 创建日期: 2023-12-25
* 描述: CDump类实现，用于完成数据内存的转储操作
*/

#include "dump.h"
#include "../log/log.h"
#include <stdio.h>

#include <string.h>
using namespace JwUtility;

#ifdef _WIN32
#define snprintf _snprintf
#endif

size_t CDump::m_max_line = 16;		/*每行要dump的字节数*/

/* *
 * @brief			把一个buf打印成十六进制，并输出到标准输出
 * @param buf		输入参数，待dump的buffer
 * @param len		输入参数，buf的长度
 * @return			成功返回EC_SUCCESS, 否则返回对应的错误码
 * */
int CDump::dump(char * buf, size_t len)
{
	return fdump(stdout, buf, len);
}

/* *
 * @brief			把一个buf打印成十六进制，并输出到指定文件
 * @param stream	输入参数, 打开的文件
 * @param buf		输入参数，待dump的buffer
 * @param len		输入参数，buf的长度
 * @return			成功返回EC_SUCCESS, 否则返回对应的错误码
 * */
int CDump::fdump(FILE * stream, char * buf, size_t len)
{
	int rt = EC_SUCCESS;
	char * hexbuf = NULL;
	char * chrbuf = NULL;
	do{
		int hexsize;	/*hexbuf的大小*/
		int chrsize;	/*chrbuf的大小*/
		size_t i;		/*循环参数*/
		size_t j;

		/*检查参数*/
		if(stream == NULL || buf == NULL)
		{
			LOG_ERROR(("参数错误\n"));
			rt = EC_PARAM_ERROR;
			break;
		}

		hexsize = m_max_line * 3 + 1;
		chrsize = m_max_line * 2 + 1;

		hexbuf = new(std::nothrow) char[hexsize];
		if(hexbuf == NULL)
		{
			LOG_ERROR(("分配内存失败\n"));
			rt = EC_ALLOC_MEM_ERROR;
			break;
		}

		memset(hexbuf, 0x00, sizeof(char)*hexsize);

		chrbuf = new(std::nothrow) char[chrsize];
		if(chrbuf == NULL)
		{
			LOG_ERROR(("分配内存失败\n"));
			rt = EC_ALLOC_MEM_ERROR;
			break;
		}

		memset(chrbuf, 0x00, sizeof(char)*chrsize);

		/*把buf的内容按字节以16进制和字符型写到文件里面*/
		for( i = 0; i< len; i++)
		{
			j = i % m_max_line;

			snprintf(hexbuf + j*3, 4, "%02X ", (unsigned char)buf[i]);

			/*注意，这里buf[i]必须转化为unsigned char，否则在windows下会出错*/
			if(isgraph((unsigned char)buf[i]))
			{
				snprintf(chrbuf + j*2, 3, "%c ", (unsigned char)buf[i]);
			}else
			{
				/*不可打印字符，用.代替*/
				snprintf(chrbuf + j*2, 3, ". ");
			}
			if(j == m_max_line - 1)
			{
				fprintf(stream, "%s %s\n", hexbuf, chrbuf);
				memset(hexbuf, 0x00, sizeof(char)*hexsize);
				memset(chrbuf, 0x00, sizeof(char)*chrsize);
			}
		}

		/*处理在hexbuf,chrbuf中，但还没有写到文件里的内容*/
		j = i % m_max_line;
		for(; j < m_max_line;j ++)
		{
			snprintf(hexbuf + j*3, 4, "   ");
		}
		fprintf(stream, "%s %s\n", hexbuf, chrbuf);
	}while(0);
	if(hexbuf != NULL)
	{
		delete [] hexbuf;
	}
	if(chrbuf != NULL)
	{
		delete [] chrbuf;
	}
	return rt;
}

/* *
 * @brief			把一个buf打印成十六进制，并输出到一个buf中
 * @param str		输出参数，输出dump出来的内容
 * @param size		输入参数，指定str的最大大小
 * @param buf		输入参数，待dump的buffer
 * @param len		输入参数，buf的长度
 * @return			成功返回EC_SUCCESS, 否则返回对应的错误码
 * */
int CDump::sndump(char * str, size_t size, char * buf, size_t len)
{
	int rt = EC_SUCCESS;
	char * hexbuf = NULL;
	char * chrbuf = NULL;
	do{
		int hexsize;	/*hexbuf的大小*/
		int chrsize;	/*chrbuf的大小*/
		size_t i;		/*循环参数*/
		size_t j;
		size_t nwrite = 0;	/*已经写入str的字符数*/
		size_t nwr;			/*一次写入str中的字节数*/

		/*检查参数*/
		if(str == NULL || buf == NULL)
		{
			LOG_ERROR(("参数错误\n"));
			rt = EC_PARAM_ERROR;
			break;
		}

		hexsize = m_max_line * 3 + 1;
		chrsize = m_max_line * 2 + 1;

		hexbuf = new(std::nothrow) char[hexsize];
		if(hexbuf == NULL)
		{
			LOG_ERROR(("分配内存失败\n"));
			rt = EC_ALLOC_MEM_ERROR;
			break;
		}

		memset(hexbuf, 0x00, sizeof(char)*hexsize);

		chrbuf = new(std::nothrow) char[chrsize];
		if(chrbuf == NULL)
		{
			LOG_ERROR(("分配内存失败\n"));
			rt = EC_ALLOC_MEM_ERROR;
			break;
		}

		memset(chrbuf, 0x00, sizeof(char)*chrsize);

		/*把buf的内容按字节以16进制和字符型写到字符串里面*/
		for( i = 0; i< len; i++)
		{
			j = i % m_max_line;

			snprintf(hexbuf + j*3, 4, "%02X ", (unsigned char)buf[i]);
			if(isgraph((unsigned char)buf[i]))
			{
				snprintf(chrbuf + j*2, 3, "%c ", (unsigned char)buf[i]);
			}else
			{
				snprintf(chrbuf + j*2, 3, ". ");
			}
			if(j == m_max_line - 1)
			{
				nwr = snprintf(str + nwrite, size - nwrite, "%s %s\n", hexbuf, chrbuf);
				nwrite += nwr;
				if(nwrite >= size -1)
				{
					break;
				}
				memset(hexbuf, 0x00, sizeof(char)*hexsize);
				memset(chrbuf, 0x00, sizeof(char)*chrsize);
			}
		}

		/*处理在hexbuf,chrbuf中还没有写道str的内容*/
		for(j = i % m_max_line; j < m_max_line; j ++)
		{
			snprintf(hexbuf + j*3, 4, "   ");
		}
		snprintf(str + nwrite, size - nwrite, "%s %s\n", hexbuf, chrbuf);

	}while(0);
	if(hexbuf != NULL)
	{
		delete [] hexbuf;
	}
	if(chrbuf != NULL)
	{
		delete [] chrbuf;
	}
	return rt;
}

/* *
 * @brief			设置每行dump的字节数
 * @param max_line	输入参数，m_max_line的新值	
 * */
void CDump::setmaxline(size_t max_line)
{
	m_max_line = max_line;
}

/* *
 * @brief			获得每行dump的字节数
 * @return			返回m_max_line的值	
 * */
size_t CDump::getmaxline()
{
	return m_max_line;
}

