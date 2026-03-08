/*
* 文件名:  os_info.h
* 作者: geshan@hotmail.com
* 创建日期: 2023-12-25
* 描述: COS_info类头文件，Windows平台下操作系统相关信息
*/

#ifdef WIN32
#include <windows.h>
#include <strsafe.h>

#include "../win_reg/win_reg.h"
#pragma warning(disable:4996)
#endif

#ifndef __UTILITY_OS_INFO_H__
#define __UTILITY_OS_INFO_H__ 

#include <string>

namespace JwUtility
{

	union os_version
	{
		int version;

#ifdef WIN32  /* x86架构平台小端，内存最低位先存 */
		struct
		{
			unsigned int wProcessorArchitecture : 5; //处理器架构 (32 or 64)
			unsigned int wSuiteMask : 5;      // 位掩码，识别操作系统套件
			unsigned int wProductType : 5;    // 产品类型
			unsigned int dwMinorVersion : 5;  // 次版本号
			unsigned int dwMajorVersion : 5;  // 主版本号
			unsigned int dwPlatformId : 5;    // 操作系统类型
			unsigned int dwReserve : 2;
		};

#endif

#ifdef _AIX  /* power架构平台大端，内存最高位先存 */
		struct
		{
			unsigned int dwReserve : 2;
			unsigned int dwPlatformId : 5;    // 操作系统类型
			unsigned int dwMajorVersion : 5;  // 主版本号
			unsigned int dwMinorVersion : 5;  // 次版本号
			unsigned int wProductType : 5;    // 产品类型
			unsigned int wSuiteMask : 5;      // 位掩码，识别操作系统套件
			unsigned int wProcessorArchitecture : 5; //处理器架构 (32 or 64)
		};
#endif

#ifdef linux  /* power架构平台大端，内存最高位先存 */

		struct
		{
			unsigned int wProcessorArchitecture : 5; //处理器架构 (32 or 64)
			unsigned int wSuiteMask : 5;      // 位掩码，识别操作系统套件
			unsigned int wProductType : 5;    // 产品类型
			unsigned int dwMinorVersion : 5;  // 次版本号
			unsigned int dwMajorVersion : 5;  // 主版本号
			unsigned int dwPlatformId : 5;    // 操作系统类型
			unsigned int dwReserve : 2;
		};


#endif

#ifdef __sun__ /* sparc架构平台大端，内存最高位先存 */

#ifdef __sparc__
		struct
		{
			unsigned int dwReserve : 2;
			unsigned int dwPlatformId : 5;    // 操作系统类型
			unsigned int dwMajorVersion : 5;  // 主版本号
			unsigned int dwMinorVersion : 5;  // 次版本号
			unsigned int wProductType : 5;    // 产品类型
			unsigned int wSuiteMask : 5;      // 位掩码，识别操作系统套件
			unsigned int wProcessorArchitecture : 5; //处理器架构 (32 or 64)
		};

#else

		struct
		{
			unsigned int wProcessorArchitecture : 5; //处理器架构 (32 or 64)
			unsigned int wSuiteMask : 5;      // 位掩码，识别操作系统套件
			unsigned int wProductType : 5;    // 产品类型
			unsigned int dwMinorVersion : 5;  // 次版本号
			unsigned int dwMajorVersion : 5;  // 主版本号
			unsigned int dwPlatformId : 5;    // 操作系统类型
			unsigned int dwReserve : 2;
		};

#endif

#endif

#ifdef __hpux__ /* parisc架构平台大端，内存最高位先存 */
		struct
		{
			unsigned int dwReserve : 2;
			unsigned int dwPlatformId : 5;    // 操作系统类型
			unsigned int dwMajorVersion : 5;  // 主版本号
			unsigned int dwMinorVersion : 5;  // 次版本号
			unsigned int wProductType : 5;    // 产品类型
			unsigned int wSuiteMask : 5;      // 位掩码，识别操作系统套件
			unsigned int wProcessorArchitecture : 5; //处理器架构 (32 or 64)
		}hp_info;
#endif

	};

	enum PlantformID
	{
		ePLANTFORM_WINDOWS = 0,
		ePLANTFORM_LINUX,
		ePLANTFORM_AIX,
		ePLANTFORM_SOLARIS,
		ePLANTFORM_HPUX,
		ePLANTFORM_FREEBSD,
	};

	enum ProcessorArchitecture
	{
		ePROCESSORARCHITECTURE_X32 = 0,
		ePROCESSORARCHITECTURE_X64,
		ePROCESSORARCHITECTURE_IA64,
		ePROCESSORARCHITECTURE_POWER32,
		ePROCESSORARCHITECTURE_POWER64,
		ePROCESSORARCHITECTURE_SPARC32,
		ePROCESSORARCHITECTURE_SPARC64,
		ePROCESSORARCHITECTURE_PARISC,
		ePROCESSORARCHITECTURE_ARM,
	};

	class COS_info
	{
	public:

		enum EC
		{
			EC_SUCCESS = 0,				// 成功
			EC_PARAM_ERROR,             // 参数错误
			EC_GETVERSION_ERROR,        // 获取版本号失败
		};


		/**
		* @brief			获取操作系统版本
		* @param os_vesion	输出参数，返回一个包含标识操作系统版本的32位整数
		* @return			成功返回EC_SUCCESS
		* 					否则返回对应的错误码
		**/
		static int get_os_vesion(int& os_vesion);

		/**
		* @param rt			输出参数，返回一个操作系统字符串(如：windows 7 Ultimate)
		* @return			成功返回EC_SUCCESS
		* 					否则返回对应的错误码
		**/
		static bool get_os_vesion_str(std::string& s_os_vesion);

		/**
		* @brief			获取win操作系统版本详细信息
		* @ver_desc_str		系统版本（文字描述 如：）
		* @ver_num_str		系统版本（数字值 如：）
		* @return			是否成功
		**/
		static bool get_os_version_detail(std::string& ver_desc_str, std::string& ver_num_str);

#ifdef WIN32
		/**
		* @return			如果是64位操作系统，返回真
		* 					否则返回假
		**/
		static BOOL is_wow64process();
		static std::string get_ProductName();
#endif
	};

}

#endif //PUBLIB_UTILITY_OS_INFO_H__ 
