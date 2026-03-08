
/*
* 文件名: disable_file_redirection.cpp
* 作者: geshan@hotmail.com
* 创建日期: 2023-12-25
* 描述: CDisableFsRedirection类实现，用于关闭文件重定向
*/

#include <Windows.h>
#include "disable_file_redirection.h"

using namespace JwUtility;

CDisableFsRedirection::CDisableFsRedirection()
{
	is_restore = false;

	m_fnWow64DisableWow64FsRedirection = (FnWow64DisableWow64FsRedirection)GetProcAddress( GetModuleHandleA("kernel32"), "Wow64DisableWow64FsRedirection" ); 
	m_fnWow64RevertWow64FsRedirection = (FnWow64RevertWow64FsRedirection)GetProcAddress( GetModuleHandleA("kernel32"), "Wow64RevertWow64FsRedirection" );

	if(NULL != m_fnWow64DisableWow64FsRedirection)
	{
		m_fnWow64DisableWow64FsRedirection(&m_pOldValue);
	}
}

CDisableFsRedirection::~CDisableFsRedirection()
{
	if (!is_restore)
	{
		if(NULL != m_fnWow64RevertWow64FsRedirection)
		{
			m_fnWow64RevertWow64FsRedirection(m_pOldValue);
		}
	}
}

void CDisableFsRedirection::restore()
{
	if (!is_restore)
	{
		if(NULL != m_fnWow64RevertWow64FsRedirection)
		{
			is_restore = true;
			m_fnWow64RevertWow64FsRedirection(m_pOldValue);
		}
	}
}
