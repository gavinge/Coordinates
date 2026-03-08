
/*
* 文件名:  stringhelper.h
* 作者: geshan@hotmail.com
* 创建日期: 2024-05-28
* 描述: 字符串相关帮助函数
*/

#ifndef __STRING_HELPER_H__
#define __STRING_HELPER_H__
#include <iostream>

namespace JwUtility
{

	class CStringHelper
	{
	public:
		static int getUTF8CharSize(unsigned char c) {
			if ((c & 0x80) == 0)        // 0xxxxxxx, 1 byte
				return 1;
			else if ((c & 0xE0) == 0xC0) // 110xxxxx, 2 bytes
				return 2;
			else if ((c & 0xF0) == 0xE0) // 1110xxxx, 3 bytes (most CJK characters)
				return 3;
			else if ((c & 0xF8) == 0xF0) // 11110xxx, 4 bytes
				return 4;
			return 1; // default to 1 byte if unrecognized
		}

		// 计算含有中午字符串的長度
		static int calChineseLength(const std::string& str) {
			int length = 0;
			for (size_t i = 0; i < str.size(); ) {
				int charSize = getUTF8CharSize(static_cast<unsigned char>(str[i]));
				length++;
				i += charSize; // 跳过整个字符
			}
			return length;
		}
	};

}



#endif //__CHECK_FUNCTION_TEMPLATE_H