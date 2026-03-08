
/*
* 文件名: disable_file_redirection.h
* 作者: geshan@hotmail.com
* 创建日期: 2023-12-25
* 描述: CDisableFsRedirection类头文件，用于关闭文件重定向
*/

#ifndef _INCLUDE_PUBLIC_DISABLE_FILE_REDIRECTION_H_
#define _INCLUDE_PUBLIC_DISABLE_FILE_REDIRECTION_H_

namespace JwUtility
{
	/**
	* @brief 定义此对象的时候将会关闭文件重定向，此对象析构时将恢复文件重定向
	*/

	typedef BOOL (WINAPI *FnWow64DisableWow64FsRedirection)(PVOID*); 
	typedef BOOL (WINAPI *FnWow64RevertWow64FsRedirection)(PVOID); 
	
	class CDisableFsRedirection
	{
	public:
		CDisableFsRedirection();

		~CDisableFsRedirection();

	public:
		void restore();

	private:
		FnWow64DisableWow64FsRedirection  m_fnWow64DisableWow64FsRedirection; 
		FnWow64RevertWow64FsRedirection   m_fnWow64RevertWow64FsRedirection;
		PVOID m_pOldValue;
		bool is_restore;
	};
}


#endif //_INCLUDE_PUBLIC_DISABLE_FILE_REDIRECTION_H_