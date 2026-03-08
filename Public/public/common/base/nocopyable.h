/***********************************************************
	Created:	   2024年01月10日 15:49
	Filename: 	   nocopyable.h
	File ext:	   h
	CXX_STANDARD:  11
	Platform:      支持Windows/Linux平台
	Purpose:	   通用不能被拷贝基类
	Author:        geshan@hotmail.com
***********************************************************/


#ifndef NOCOPYABLE_H
#define NOCOPYABLE_H

namespace public_common {
	class NoCopyable {
	protected:
		NoCopyable() = default;
		~NoCopyable() = default;

		NoCopyable(const NoCopyable&) = delete;
		NoCopyable& operator=(const NoCopyable) = delete;
	};

	//以下为测试代码
	/*-------------------------------------------------
	class nocopy : public_common::NoCopyable {
	};
	nocopy no1;
	nocopy no2 = no1; //can not ...
	-------------------------------------------------*/

}  // namespace public_common

#endif //NOCOPYABLE_H