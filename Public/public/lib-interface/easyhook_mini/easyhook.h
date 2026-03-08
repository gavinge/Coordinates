/*
    EasyHook - The reinvention of Windows API hooking
 
    Copyright (C) 2009 Christoph Husse

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

    Please visit http://www.codeplex.com/easyhook for more information
    about the project and latest updates.
*/

#ifndef _EASYHOOK_H_
#define _EASYHOOK_H_


#define NTDDI_VERSION           NTDDI_WIN2KSP4
#define _WIN32_WINNT            0x500
#define _WIN32_IE_              _WIN32_IE_WIN2KSP4

#include <windows.h>
#include <winnt.h>
#include <winternl.h>



#ifdef __cplusplus
extern "C"{
#endif

#define EASYHOOK_API					__stdcall
#define DRIVER_SHARED_API(type, decl)	EXTERN_C type EASYHOOK_API decl

/* 
    This is the typical sign that a defined method is exported...

    Methods marked with this attribute need special attention
    during parameter validation and documentation.
*/
#define EASYHOOK_NT_EXPORT          EXTERN_C NTSTATUS EASYHOOK_API
#define EASYHOOK_BOOL_EXPORT        EXTERN_C BOOL EASYHOOK_API

#define MAX_HOOK_COUNT              128
#define MAX_ACE_COUNT               128
#define MAX_THREAD_COUNT            128
#define MAX_PASSTHRU_SIZE           1024 * 64

typedef struct _LOCAL_HOOK_INFO_* PLOCAL_HOOK_INFO;

typedef struct _HOOK_TRACE_INFO_
{
    PLOCAL_HOOK_INFO        Link;
}HOOK_TRACE_INFO, *TRACED_HOOK_HANDLE;


BOOL init_api_hook_lib(void* context);
void uninit_api_hook_lib(void* context);


DRIVER_SHARED_API(NTSTATUS, RtlGetLastError());

DRIVER_SHARED_API(PWCHAR, RtlGetLastErrorString());

DRIVER_SHARED_API(NTSTATUS, LhGetOldEntryPoint(
		TRACED_HOOK_HANDLE InTracedHandle,
		void** OldEntryPoint
));

DRIVER_SHARED_API(NTSTATUS, LhSetSelfAgent(
		TRACED_HOOK_HANDLE InTracedHandle
));


DRIVER_SHARED_API(NTSTATUS, LhInstallHook(
            void* InEntryPoint,
            void* InHookProc,
            void* InCallback,
            TRACED_HOOK_HANDLE OutHandle));

DRIVER_SHARED_API(NTSTATUS, LhUninstallAllHooks());

DRIVER_SHARED_API(NTSTATUS, LhUninstallHook(TRACED_HOOK_HANDLE InHandle));

DRIVER_SHARED_API(NTSTATUS, LhWaitForPendingRemovals());

/*
    The following barrier methods are meant to be used in hook handlers only!

    They will all fail with STATUS_NOT_SUPPORTED if called outside a
    valid hook handler...
*/
DRIVER_SHARED_API(NTSTATUS, LhBarrierGetCallback(PVOID* OutValue));

DRIVER_SHARED_API(NTSTATUS, LhBarrierGetReturnAddress(PVOID* OutValue));

DRIVER_SHARED_API(NTSTATUS, LhBarrierGetAddressOfReturnAddress(PVOID** OutValue));

DRIVER_SHARED_API(NTSTATUS, LhBarrierBeginStackTrace(PVOID* OutBackup));

DRIVER_SHARED_API(NTSTATUS, LhBarrierEndStackTrace(PVOID InBackup));

typedef struct _MODULE_INFORMATION_* PMODULE_INFORMATION;

typedef struct _MODULE_INFORMATION_
{	
	PMODULE_INFORMATION		Next;
	UCHAR*					BaseAddress;
	ULONG					ImageSize;
	CHAR					Path[256];
	PCHAR					ModuleName;
}MODULE_INFORMATION;

EASYHOOK_NT_EXPORT LhUpdateModuleInformation();

DRIVER_SHARED_API(NTSTATUS, LhBarrierPointerToModule(
			PVOID InPointer,
			MODULE_INFORMATION* OutModule));

DRIVER_SHARED_API(NTSTATUS, LhEnumModules(
			HMODULE* OutModuleArray, 
            ULONG InMaxModuleCount,
            ULONG* OutModuleCount));

DRIVER_SHARED_API(NTSTATUS, LhBarrierGetCallingModule(MODULE_INFORMATION* OutModule));

DRIVER_SHARED_API(NTSTATUS, LhBarrierCallStackTrace(
            PVOID* OutMethodArray, 
            ULONG InMaxMethodCount,
            ULONG* OutMethodCount));

#ifdef __cplusplus
};
#endif

#endif