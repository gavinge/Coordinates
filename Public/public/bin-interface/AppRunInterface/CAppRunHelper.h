
#pragma once

#include "IAppRun.h"


class CAppRunHelper  
{
public:
	CAppRunHelper()
	{
		m_hModule        = NULL;
		m_p = NULL;
	};
public:
	inline IAppRun* LoadDll(PCHAR lpDllPath)
	{
		BOOL bRet = TRUE;
		m_p = NULL;

		if (!PathFileExistsA(lpDllPath))
		{
			return FALSE;
		}

		//这里根据要求做相关要求做校验判断
		m_hModule = ::LoadLibraryA( lpDllPath );

		if( NULL == m_hModule )
		{
			return FALSE;
		}

		if( bRet == TRUE )
		{
			typedef BOOL (__stdcall *fun_CreateInstance)(IAppRun**);
			fun_CreateInstance pfunCreate = (fun_CreateInstance)GetProcAddress(m_hModule, "CreateInstance");
			if (pfunCreate)
			{
				pfunCreate(&m_p);
				if (NULL == m_p)
				{
					bRet = FALSE;
				}
			}
			else
			{
				bRet = FALSE;
			}
		}

		if( TRUE != bRet )
		{
			FreeLibrary( m_hModule );
			m_hModule = NULL;
			m_p = NULL;
		}

		return m_p;
	};


	///如果不调用这个函数，有内存泄露!!! (有全局生命周期的就不用考虑了)
	///如果不想这么用，可以直接显示的调用Release释放就行，也不会有内存泄露
	inline void FreeDll()
	{		
		if (!m_hModule)
		{
			return;
		}

		if (m_p)
		{
			m_p->Release();
			m_p = NULL;
		}

		if (m_hModule)
		{            
			FreeLibrary(m_hModule);
			m_hModule = NULL;
		}
	};
private:
	IAppRun* m_p; 
	HMODULE m_hModule; 
};
