
/*
* 文件名:  win_file.cpp
* 作者: geshan@hotmail.com
* 创建日期: 2023-12-25
* 描述: CWinFile类实现，Windows平台下常用文件操作
*/

#include "../log/log.h"
#include "win_file.h"
#include <string>
#include <fstream>
#include <vector>
#include <windows.h>
#include <Shellapi.h>
#include "../redirection/disable_file_redirection.h"

#pragma warning(disable:4996)

namespace JwUtility
{
	//获取可使用磁盘配额功能的磁盘		by Zhiguo
	int CWinFile::get_quota_disk(const std::string &pathname, const SubType &st, const std::string  &wildcard, FILE_CALLBACK file_deal, void *param)
	{
		std::vector<JwUtility::CWinFile::WIN_FILE_DATA> temp;
		std::vector<JwUtility::CWinFile::WIN_FILE_DATA>::iterator it;
		unsigned long ul_ret = 0;
		unsigned long ul_volname_size = MAX_PATH + 1;
		unsigned long ul_fsname_size  = MAX_PATH + 1;
		unsigned long ul_fs_flags = 0;
		
		std::vector<std::string>* pvector = reinterpret_cast<std::vector<std::string>*>(((char**)param)[1]);

		CWinFile::get_sub_item("/",CWinFile::ST_DRIVE,"",file_deal,&temp);
		it = temp.begin();
		while (it != temp.end())
		{
			ul_ret = GetVolumeInformation(it->name.c_str(),
										NULL,
										ul_volname_size,
										NULL,
										NULL,
										&ul_fs_flags,
										NULL,
										ul_fsname_size);
			if (ul_ret)
			{
				if (ul_fs_flags & FILE_VOLUME_QUOTAS)
				{
					//可以使用磁盘配额功能
					pvector->push_back(it->name);
				}
				else
				{
					//不可以使用磁盘配额功能
					/*do nothing*/
				}
			}

			it++;
		}
		
		return EC_SUCCESS;
	}

	int CWinFile::get_sub_item(const std::string &pathname, const SubType &st, const std::string  &wildcard, FILE_CALLBACK file_deal, void *param)
	{
		JwUtility::CDisableFsRedirection disableFsRedirection;

		int rt = EC_SUCCESS;
		do 
		{
			//参数检查
			if ( pathname.empty() || NULL == file_deal)
			{
				LOG_ERROR(("参数错误"));
				rt = EC_PATH_NULL_ERROR;
				break;
			}

			// 若pathname的值为"/",则获取当前磁盘列表
			if ( pathname.compare("/") == 0 )
			{//遍历驱动
				//得到驱动器列表
				std::vector<std::string> drvlist;
				get_drive_list( drvlist );
				if ( drvlist.empty() )
				{
					LOG_ERROR(("获得驱动列表为空"));
					rt = EC_GET_DIRLIST_ERROR;
					break;
				}

				//将列表返回
				WIN_FILE_DATA sfd;
				sfd.size_high_32b = 0;
				sfd.size_low_32b = 0;
				sfd.type = SubType::ST_DRIVE;
				sfd.att = 0;
				std::vector<std::string>::iterator it;
				for( it = drvlist.begin(); it != drvlist.end(); ++it)
				{
					int type = GetDriveType((*it).c_str());  //取得磁盘符类型
					if ( (type == DRIVE_FIXED) || (type == DRIVE_REMOTE) )
					{
						sfd.name = *it;
						sfd.has_sub_item = has_subitem( *it);
						sfd.ctime = "";
						sfd.mtime = "";

						if ( 0 != file_deal( param, sfd))
						{
							LOG_ERROR(("回调函数调用失败"));
							rt =  EC_CALLBACK_ERROR;
							break;
						}
					}
				}
				if ( EC_SUCCESS != rt )
				{
					break;
				}
			}
			else
			{//遍历文件

				//为了查找文件,item进行处理
				std::string find_path;
				std::string temp_path;
				if ( pathname[pathname.size()-1] != '\\')
				{
					find_path = pathname + "\\*.*";
					temp_path = pathname + "\\";
				}
				else
				{
					find_path = pathname + "*.*";
					temp_path = pathname;
				}

				//得到文件信息列表
				WIN32_FIND_DATA data;
				HANDLE handle = FindFirstFile( find_path.c_str(), &data);
				if ( INVALID_HANDLE_VALUE == handle)
				{
					LOG_ERROR(("获得文件系统失败，windows系统错误码[%d]", ::GetLastError()));
					rt = EC_ILLEGAL_PATH_ERROR;
					break;
				}

				WIN_FILE_DATA sfd;
				do
				{
					// 跳过特殊文件
					if ( ( 0 == strcmp( data.cFileName, "." ) ) || ( 0 == strcmp( data.cFileName, ".." ) ) )
					{
						continue;
					}

					//得到文件详细信息
					if ( data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY )
					{ 
						//如果为目录
						if ( (SubType::ST_DIR == st) || (SubType::ST_ALL == st))
						{ 
							//设置目录大小 
							sfd.size_high_32b = 0;
							sfd.size_low_32b = 0;

							//设置目录类型
							sfd.type = SubType::ST_DIR;

							//设置是否有子文件
							sfd.has_sub_item = has_subitem( temp_path  + data.cFileName);

							//设置目录属性
							sfd.att = data.dwFileAttributes;

							//设置目录名
							sfd.name = data.cFileName;

							//设置目录的创建时间
							sfd.ctime = format_file_time( data.ftCreationTime);

							//设置目录的最后修改时间
							sfd.mtime = format_file_time( data.ftLastWriteTime);

							//调用回调函数
							if ( 0 != file_deal( param, sfd))
							{
								LOG_ERROR(("回调函数失败"));
								rt = EC_CALLBACK_ERROR;
								break;
							}
						}//end if( (SubType::ST_DIR == st) || (SubType::ST_ALL == st))
					}
					else
					{
						//如果为文件
						if ( (SubType::ST_FILE == st) || (SubType::ST_ALL == st))
						{

							std::string strTail;  //用来存取文件后缀名

							if ( !wildcard.empty() )  //判断后缀名是否为空，如果不是将后缀名保存为现有的后缀类型
							{

								strTail = data.cFileName;

								//获取文件后缀名,无后缀名的不做处理  
								std::string::size_type nPos = strTail.rfind( "." );

								if ( nPos != std::string::npos )
								{
									strTail = strTail.substr( nPos+1 );
								}
							}
							else
							{
								strTail = wildcard;
							}

							if ( stricmp(strTail.c_str(), wildcard.c_str()) == 0 )  //stricmp不区分后缀名的大小写
							{
								//设置文件的大小 
								sfd.size_high_32b = data.nFileSizeHigh;
								sfd.size_low_32b = data.nFileSizeLow;

								//设置文件的类型
								sfd.type = SubType::ST_FILE;

								//设置文件没有子文件
								sfd.has_sub_item = HasSubItem::HSI_NULL;

								//设置文件属性
								sfd.att = data.dwFileAttributes;

								//设置文件名
								sfd.name = data.cFileName;

								//设置文件创建时间
								sfd.ctime = format_file_time( data.ftCreationTime);

								//设置最后修改时间 
								sfd.mtime = format_file_time( data.ftLastWriteTime);

								//调用回调函数
								if ( 0 != file_deal( param, sfd ))
								{
									LOG_ERROR(("调用回调函数失败"));
									rt = EC_CALLBACK_ERROR;
									break;
								}
							}//end  if( stricmp(.....))
						}//end if ( (SubType::ST_FILE == st) || (SubType::ST_ALL == st))
					}//end if(){}else{}
					
				}while ( FindNextFile( handle, &data) );
				
				if( INVALID_HANDLE_VALUE != handle )
				{
					FindClose( handle );	
				}
				if ( EC_SUCCESS != rt )
				{
					break;
				}

			}//end if ( pathname.compare("/") == 0 ) {...} else{....}

		} while (false);

		return rt;
	}

	
	int CWinFile::create_item(const std::string &filename, SubType st)
	{
		JwUtility::CDisableFsRedirection disableFsRedirection;

		int rt = EC_SUCCESS;			//返回值

		do 
		{
			//参数检查
			if ( filename.empty() )
			{
				LOG_ERROR(("参数错误"));
				rt = EC_PATH_NULL_ERROR;
				break;
			}

			/*
			*	根据创建类型来创建不同的项目
			*/
			DWORD word = 0;
			
			switch( st ) 
			{
				case ST_DIR:
					{
						BOOL bCreateSuccess = CreateDirectory( filename.c_str(), NULL ); 
						// 创建失败,返回失败原因
						if( !bCreateSuccess )
						{
							LOG_ERROR(("创建文件夹失败，windows系统错误码[%d]", ::GetLastError()));
							rt = EC_CREATE_DIR_ERROR; 	
						}
					}

					break;
				case ST_FILE:		
					{
						HANDLE handle = CreateFile( filename.c_str(), 
												GENERIC_WRITE,
												0,NULL,CREATE_ALWAYS,
												FILE_ATTRIBUTE_NORMAL,
												NULL);
						word = GetLastError();
						if ( word == ERROR_ALREADY_EXISTS  )
						{
							LOG_ERROR(("同名文件已经存在,windows系统错误码[%d]", ::GetLastError()));
							rt = EC_FILE_EXIST_ERROR;

							CloseHandle(handle);
							break;
						}

						if ( handle == INVALID_HANDLE_VALUE )	
						{
							LOG_ERROR(("创建文件失败,Windows系统错误码[%D]", ::GetLastError()));
							rt = EC_CREATE_FILE_ERROR;
							break;
						}

						CloseHandle(handle);
					}
					break;
				case ST_DRIVE:

					LOG_ERROR(("无法创建驱动器"));
					rt = EC_CREATE_ERROR; 
					break;
				default:
					LOG_ERROR(("创建未知的文件类型，st[%d]", st));
					rt = EC_CREATE_ERROR;
					break;
				}//end switch

		} while (false);
		return rt;
	}

	int CWinFile::delete_item( const std::string  &item)
	{
		JwUtility::CDisableFsRedirection disableFsRedirection;

		int  rt = EC_SUCCESS;		//返回值
		do 
		{
			//参数检查
			if ( item.empty() )
			{
				LOG_ERROR(("参数错误"));
				rt = EC_PATH_NULL_ERROR;
				break;
			}

			//去除文件尾部的"\\"
			std::string strDeleteFile = item;
			std::string::size_type iPos = item.find_last_not_of("\\");
			if( std::string::npos != iPos)
			{
				strDeleteFile = item.substr(0, iPos + 1 );
			}

			SHFILEOPSTRUCT   fo;   
			strDeleteFile   +=   '\0';   //见下面的说明，注意不是   "\0"   
			memset(&fo,   0,   sizeof(fo));   
			fo.fFlags   =   FOF_SILENT |  FOF_NOCONFIRMATION;   
			fo.wFunc   =   FO_DELETE;   
			fo.pFrom   =   strDeleteFile.c_str();   //必须是2个0字符结尾   
			if( 0 != SHFileOperation(&fo) )
			{
				LOG_ERROR(("删除文件失败, error[%d]", GetLastError() ));	
				rt = EC_DELFILE_ERROR;
				break;
			}

		} while (false);

		return rt;
	}

	int CWinFile::rename_item( const std::string  &oldname, const std::string  &newname)
	{
		JwUtility::CDisableFsRedirection disableFsRedirection;

		int  rt = EC_SUCCESS;			//返回值
		do 
		{
			//参数检查 
			if ( (oldname.empty() ) || (newname.empty()) )
			{
				LOG_ERROR(("参数错误"));
				rt = EC_PATH_NULL_ERROR;
				break;
			}

			BOOL bRet = MoveFile(oldname.c_str(), newname.c_str());
			if ( bRet == FALSE )
			{
				LOG_ERROR(("文件重命名失败, window系统错误码[%d]", ::GetLastError()));
				rt = EC_RENAME_ERROR;
				break;
			}

		} while (false);

		return rt;
	}

	int CWinFile::is_existed_file(const std::string &filename)
	{
		JwUtility::CDisableFsRedirection disableFsRedirection;

		int rt = EC_SUCCESS;			//返回值
		do 
		{
			//参数检查
			if (filename.empty() )
			{
				LOG_ERROR(("参数错误"));
				rt = EC_PATH_NULL_ERROR;
				break;
			}
			
			//打开文件 
			std::ifstream hFileRead( filename.c_str(), std::ios::in);
			if ( !hFileRead.is_open() )
			{ 
				rt = EC_EXIST_ERROR;
				break;
			} 

			hFileRead.close();

		} while (false);

		return rt;
	}

	int CWinFile::has_file_attr(const std::string &filename, unsigned int attr)
	{
		JwUtility::CDisableFsRedirection disableFsRedirection;

		int  rt = EC_SUCCESS;					//返回值
		HANDLE hSearch = INVALID_HANDLE_VALUE;	//文件句柄
		do 
		{
			//参数检查
			if ( filename.empty() )
			{
				LOG_ERROR(("文件路径无效,路径[%s]", filename.c_str()));
				rt = EC_PATH_NULL_ERROR;
				break;
			}

			//读取文件属性
			WIN32_FIND_DATA FileData;
			hSearch = FindFirstFile(filename.c_str(), &FileData); 
			if (hSearch == INVALID_HANDLE_VALUE) 
			{ 
				LOG_ERROR(("读取文件的信息失败，window的系统错误码[%d]", ::GetLastError()));
				rt = EC_ILLEGAL_PATH_ERROR;
				break;
			}

			//判断是否有指定的属性
			if ( !(FileData.dwFileAttributes & attr ))
			{
				LOG_ERROR(("文件没有指定的属性, 属性[0x%x]", attr));
				rt = EC_FILE_ATTR_ERROR;
				break;
			}

		} while (false);

		if( INVALID_HANDLE_VALUE != hSearch )
		{
			FindClose(hSearch);
		}
		return rt;
	}


	bool CWinFile::is_valid_file_name( const std::string &filename)
	{
		if( filename.empty() )
			return false;	

		if( ( filename.find("/") != std::string::npos ) ||
			(filename.find("*") != std::string::npos ) ||
			(filename.find("?") != std::string::npos ) ||
			(filename.find(":") != std::string::npos ) ||
			(filename.find("\"") != std::string::npos ) ||
			(filename.find("<") != std::string::npos ) ||
			(filename.find(">") != std::string::npos ) ||
			(filename.find("|") != std::string::npos ) ||
			(filename.find("\\") != std::string::npos ) )
		{
			return false;
		}

		return true;
	}

	bool CWinFile::is_valid_file_path(const std::string &filepath)
	{	
		//参数检查
		if( filepath.empty() )
		{
			return false;
		}

		//去掉尾部的"\\"
		std::string strTempPath = filepath;
		std::string::size_type iLastIndex = strTempPath.length() - 1;
		if(  strTempPath[ iLastIndex ] == '\\')
		{
			strTempPath[ iLastIndex ] = '\0';
		}

		//判断文件的最小路径长度
		if( strTempPath.length() < MIN_FILE_PATH_LEN -1 )
		{
			return false;
		}

		//判断路径的头两个字母是否是有效的驱动器路径
		if( 0 == isalpha( strTempPath[ 0 ] ))
		{
			return false;	
		}
		if( ':' != strTempPath[1] )
		{
			return false;
		}

		//如果文件路径大于最小路径，判断驱动器后面的路径是否存在非法字符
		if( strTempPath.length() > MIN_FILE_PATH_LEN )
		{
		 	strTempPath.erase(0, MIN_FILE_PATH_LEN);

			if( (strTempPath.find("/") != std::string::npos ) ||
				(strTempPath.find("*") != std::string::npos ) ||
				(strTempPath.find("?") != std::string::npos ) ||
				(strTempPath.find(":") != std::string::npos ) ||
				(strTempPath.find("\"") != std::string::npos ) ||
				(strTempPath.find("<") != std::string::npos ) ||
				(strTempPath.find(">") != std::string::npos ) ||
				(strTempPath.find("|") != std::string::npos ) ||
				(strTempPath.find("\\\\") != std::string::npos) )
			{
				return false;
			}
		}//end if( strTempPath.length() > MIN_FILE_PATH_LEN )

		return true;
	}

	inline void CWinFile::get_drive_list( std::vector<std::string> &drvlist)
	{
		size_t szAllDriveStrings = GetLogicalDriveStrings(0, NULL);

		char *pDriveStrings = new(std::nothrow) char[szAllDriveStrings+1];
		if ( pDriveStrings ==NULL )
		{
			return;
		}
		memset( pDriveStrings, 0x00, szAllDriveStrings + 1);
		char *p = pDriveStrings;
		GetLogicalDriveStrings(szAllDriveStrings,pDriveStrings);
		size_t szDriveString = strlen(pDriveStrings);

		while( szDriveString > 0 ) 
		{ 
			if (DRIVE_FIXED == GetDriveType(p))
			{
				drvlist.push_back(p);
			}

			//移动4个字节到下个盘符
			p += 4; 

			szDriveString = strlen(p);
		} 
		delete [] pDriveStrings;
	}

	inline CWinFile::HasSubItem CWinFile::has_subitem(const std::string &filepath)
	{
		HasSubItem rt = CWinFile::HSI_NULL;			//返回值

		std::string strPath = filepath;
		if ( strPath[strPath.size() -1] != '\\')
		{
			strPath += "\\*.*";
		}
		else
		{
			strPath += "*.*";
		}


		WIN32_FIND_DATA data;
		HANDLE handle = FindFirstFile( strPath.c_str(), &data);
		if ( INVALID_HANDLE_VALUE == handle)
		{
			return rt;
		}
		do
		{
			// 跳过特殊文件
			if ( ( 0 == strcmp( data.cFileName, "." ) ) || 
				( 0 == strcmp( data.cFileName, ".." ) ) )
			{
				continue;
			}

			//如果同时有文件和文件夹
			if ( (rt & CWinFile::HSI_DIR) && (rt & CWinFile::HSI_FILE))
			{
				break;
			}

			//确认文件或文件夹属性
			if ( data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) 
			{ 
				rt =(CWinFile::HasSubItem) (rt | CWinFile::HSI_DIR);
			}
			else
			{
				rt = (CWinFile::HasSubItem) (rt | CWinFile::HSI_FILE);
			}

		}while ( FindNextFile( handle, &data) );

		if( INVALID_HANDLE_VALUE != handle )
		{
			FindClose( handle );		
		}

		return rt;
	}



	std::string CWinFile::format_file_time( const FILETIME &file_time)
	{
			SYSTEMTIME tm = {0};
			::FileTimeToSystemTime( &file_time, &tm);
			char *buf = new( std::nothrow) char[MAX_TIME_LINE];
			if( NULL == buf )
			{
				return "";
			}

			memset( buf, 0x00, MAX_TIME_LINE);
			_snprintf( buf, MAX_TIME_LINE - 1,
						"%04d-%02d-%02d %02d:%02d:%02d",
						tm.wYear, tm.wMonth, tm.wDay,
						tm.wHour, tm.wMinute, tm.wSecond);
			std::string strTime = buf;
			delete []buf;
	
			return strTime;
	}

}


