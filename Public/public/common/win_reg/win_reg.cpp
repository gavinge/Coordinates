
/*
* 文件名: win_reg.cpp
* 作者: geshan@hotmail.com
* 创建日期: 2023-12-25
* 描述: CWinReg类实现，Windows平台下常用注册表操作
*/

#include "../log/log.h"
#include "win_reg.h"

#pragma comment(lib, "advapi32")




namespace JwUtility
{
	int CWinReg::get_subitem_key( const std::string &path, KEY_REG_CALLBACK key_data_deal, void * param, bool is_64_key/* = false*/)
	{
		int rt = EC_SUCCESS;					//返回值
		HKEY key = NULL;						//KEY句柄
		TCHAR *lpName = NULL;					//键名

		do 
		{
			//参数有效性判断
			if ( path.empty() || NULL == key_data_deal )
			{
				LOG_ERROR(("参数错误, path[%s], key_data_deal[0x%x]", path.c_str(), (long)((int*)key_data_deal)));
				rt = EC_PARAM_ERROR;
				break;
			}

			//得到根键列表
			if ( path.compare("/") == 0 )
			{
				rt = get_root_key_list( key_data_deal, param );
				break;
			}

			//得到子键信息
			std::string sub;			//子键的路径
			HKEY rootKey = NULL;		//根键
			rt = open_reg_key( path, sub, key, rootKey, is_64_key, KEY_READ);
			if ( EC_SUCCESS != rt )
			{
				break;
			}

			//查询子键的最大长度
			DWORD maxlen = 0;			//子键的最大长度
			if ( ::RegQueryInfoKey( key, NULL, NULL, NULL, NULL, &maxlen,
									NULL, NULL, NULL, NULL, NULL, NULL) != ERROR_SUCCESS )
			{
				LOG_ERROR(("调用查询键信息API失败,windows系统错误码[%d]", ::GetLastError()));
				rt = EC_QUERY_INFO_KEY_ERROR;
				break;
			}

			//枚举所有子键
			maxlen += ITEM_NAME_MAXLEN;
			DWORD dwIndex = 0;
			lpName = new(std::nothrow) TCHAR[ITEM_NAME_MAXLEN + 1];
			if (lpName == NULL)
			{
				LOG_ERROR(("申请内存失败, lpName[0x%00]"));
				rt = EC_NEW_MEM_ERROR;
				break;
			}
			memset( lpName, 0, sizeof( TCHAR ) * (ITEM_NAME_MAXLEN + 1));
			HKEY sub_key = NULL;
			DWORD len = ITEM_NAME_MAXLEN;		//键名的最大长度
			WIN_KEY_REG_DATA rkd;				//键的数据信息
			DWORD sub_keys_count;				//子项的数目
			DWORD sub_values_count;				//值的数目
			FILETIME mod_time;					//键的修改时间
			while ( ::RegEnumKeyEx( key, dwIndex++, lpName, &len
				, NULL, NULL, NULL, NULL ) == ERROR_SUCCESS )
			{

				std::string next_sub;
				if ( sub.empty() )
				{
					next_sub = lpName;
				}
				else
				{
					next_sub = (sub+"\\"+lpName);
				}
				rkd.name = lpName;			//保存键名

				//查询是否有子键,查询失败，默认返回0
				do
				{
					sub_keys_count = 0;
					sub_values_count = 0;

					REGSAM samDesired = KEY_READ;
					AppendRegSam(samDesired, next_sub, is_64_key);

					if ( ::RegOpenKeyEx( rootKey, next_sub.c_str()
						, 0, samDesired, &sub_key ) != ERROR_SUCCESS )
					{
						LOG_ERROR(("调用打开键API失败,windows系统错误码[%d]", ::GetLastError()));
						break;
					}
					if ( ERROR_SUCCESS != RegQueryInfoKey( sub_key, NULL, NULL, NULL, &sub_keys_count
							, NULL, NULL, &sub_values_count, NULL, NULL, NULL, &mod_time))
					{

						LOG_ERROR(("调用查询键API失败,windows系统错误码[%d]", ::GetLastError()));
						break;
					}
						
				}while( false);

				rkd.sub_key_num = sub_keys_count;
				rkd.sub_value_num = sub_values_count;

				//调用回调函数
				if ( 0 != key_data_deal( param, rkd))
				{
					LOG_ERROR(("调用回调函数失败"));
					rt = EC_CALLBACK_ERROR;
					break;
				}

				  len = ITEM_NAME_MAXLEN;

			}//end while

			if( EC_SUCCESS != rt )
			{
				break;	
			}
			
		} while (false);

		if (lpName != NULL)
		{
			delete [] lpName;
		}
		if (key != NULL)
		{
			::RegCloseKey( key );
		}
		return rt;
	}

	int CWinReg::get_subitem_values( const std::string  &path, VALUE_REG_CALLBACK value_data_deal, void *param, bool is_64_key/* = false*/)
	{
		int rt = EC_SUCCESS;			//返回值
		HKEY key = NULL;				//打开的注册表键
		TCHAR *lpValueName = NULL;		//值项名
		BYTE *lpData = NULL;			//值项的数据

		do 
		{
			//参数效性判断
			if ( path.empty() || NULL == value_data_deal )
			{
				LOG_ERROR(("参数错误, path[%s], value_data_deal[0x%x]", path.c_str(), (long)((int*)value_data_deal)));
				rt = EC_PARAM_ERROR;
				break;
			}

			//打开注册表键
			HKEY rootKey = NULL;		//根键值
			std::string sub;			//子键路径
			rt = open_reg_key( path, sub, key, rootKey, is_64_key,KEY_READ );
			if ( EC_SUCCESS != rt )
			{
				break;
			}

			//查询此键值的名和值的最大长度
			DWORD vn_maxlen = 0;
			DWORD v_maxlen = 0;
			if ( ::RegQueryInfoKey( key, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
									&vn_maxlen, &v_maxlen, NULL, NULL) != ERROR_SUCCESS )
			{
				LOG_ERROR(("调用查询注册表键信息API失败，windows系统错误码[%d]", ::GetLastError()));
				rt = EC_QUERY_INFO_KEY_ERROR;
				break;
			}
			vn_maxlen += ITEM_NUMBER_MAXLEN;
			v_maxlen += ITEM_VALUE_MAXLEN;

			//枚举所有值
			DWORD dwIndex = 0;
			lpValueName = new(std::nothrow) TCHAR[vn_maxlen + 1];
			if (lpValueName == NULL)
			{
				LOG_ERROR(("申请内存失败, lpValueName[0x00]"));
				rt = EC_NEW_MEM_ERROR;
				break;
			}
			memset( lpValueName, 0, sizeof( TCHAR ) * (vn_maxlen + 1 ));

			DWORD dwValueLen = vn_maxlen;
			DWORD lpType = 0;
			lpData = new(std::nothrow) BYTE[v_maxlen + 1 ];
			if (lpData == NULL)
			{
				LOG_ERROR(("申请内存失败, lpData[0x00]"));
				rt = EC_NEW_MEM_ERROR;
				break;
			}
			memset( lpData, 0, v_maxlen + 1);

			DWORD dwDataLen = v_maxlen;
			LONG iRegRt = ::RegEnumValue( key, dwIndex, lpValueName, &dwValueLen, NULL,
									&lpType, lpData, &dwDataLen);

			while ( ERROR_SUCCESS == iRegRt )
			{
				WIN_VALUE_REG_DATA values;
				values.name = lpValueName;			//值名
				values.data.clear();
				values.data.insert( values.data.begin(), lpData, lpData+ dwDataLen );		//值数据
				values.type = lpType;				//值类型
				if( 0 != value_data_deal( param, values) )
				{
					LOG_ERROR(("回调函数处理失败"));	
					rt = EC_CALLBACK_ERROR;
					break;
				}

				dwValueLen = vn_maxlen;
				memset( lpValueName, 0, vn_maxlen + 1);
				dwDataLen = v_maxlen;
				memset( lpData, 0, v_maxlen + 1);

				iRegRt = ::RegEnumValue( key, ++dwIndex, lpValueName, &dwValueLen, NULL,
									&lpType, lpData, &dwDataLen);
			}
		} while (false);
		if ( lpData != NULL )
		{
			delete [] lpData;
		}
		if ( lpValueName != NULL )
		{
			delete [] lpValueName;
		}
		if ( key != NULL )
		{
			::RegCloseKey( key);
		}
		return rt;
	}

	int CWinReg::get_subitem_value( const std::string &path, const std::string &item, DWORD& type, std::string& value, bool is_64_key/* = false*/)
	{
		int rt = EC_SUCCESS;
		HKEY key = NULL;				//打开的注册表键
		do 
		{
			//参数效性判断
			if ( path.empty())
			{
				LOG_ERROR(("参数错误, path[%s]", path.c_str()));
				rt = EC_PARAM_ERROR;
				break;
			}

			// 打开注册表键
			HKEY rootKey = NULL;		//根键值
			std::string sub;			//子键路径
			rt = open_reg_key( path, sub, key, rootKey, is_64_key,KEY_READ);
			if ( EC_SUCCESS != rt )
			{
				rt = EC_REG_OPEN_KEY_ERROR;
				break;
			}

			// 获取信息
			DWORD BufferSize = 128;
			DWORD BYTEINCREMENT = 128;
			unsigned char* lpData = new unsigned char[BufferSize];
			memset(lpData, 0, BufferSize);
			DWORD cbData = BufferSize;
			rt = RegQueryValueEx(key, item.c_str(), NULL, &type, (LPBYTE)lpData, &cbData);
			while( rt == ERROR_MORE_DATA )
			{
				delete []lpData; lpData = NULL;
				BufferSize += BYTEINCREMENT;
				lpData = new unsigned char[BufferSize];
				memset(lpData, 0, BufferSize);
				cbData = BufferSize;

				rt = RegQueryValueEx(key, item.c_str(), NULL, &type, (LPBYTE)lpData, &cbData);
			}

			if( rt != ERROR_SUCCESS )
			{
				rt = EC_REG_QUERY_VALUE_ERROR;
			}
			else
			{
				if (REG_SZ == type)
				{
					value = (char*)lpData;
				}
				else
				{
					value.assign((const char*)lpData, cbData);
				}
			}
			delete []lpData; lpData = NULL;
			
		} while (false);

		if ( key != NULL )
		{
			::RegCloseKey( key);
		}

		return rt;
	}

	int CWinReg::set_subitem_string_value(const std::string &path, const std::string &item, const std::string& value, bool is_64_key)
	{
		int rt = EC_SUCCESS;
		HKEY key = NULL;				//打开的注册表键
		do
		{
			//参数效性判断
			if (path.empty())
			{
				LOG_ERROR(("参数错误, path[%s]", path.c_str()));
				rt = EC_PARAM_ERROR;
				break;
			}

			// 打开注册表键
			HKEY rootKey = NULL;		//根键值
			std::string sub;			//子键路径
			rt = open_reg_key(path, sub, key, rootKey, is_64_key);
			if (EC_SUCCESS != rt)
			{
				rt = EC_REG_OPEN_KEY_ERROR;
				break;
			}

			// 获取信息
			DWORD type = REG_SZ;
			DWORD cbData = value.length();
			rt = RegSetValueEx(key, item.c_str(), NULL, type, (LPBYTE)&value, cbData);
			if (rt != ERROR_SUCCESS)
			{
				rt = EC_REG_SET_VALUE_ERROR;
			}

		} while (false);

		if (key != NULL)
		{
			::RegCloseKey(key);
		}

		return rt;
	}

	int CWinReg::set_subitem_dword_value(const std::string &path, const std::string &item, DWORD& value, bool is_64_key)
	{
		int rt = EC_SUCCESS;
		HKEY key = NULL;				//打开的注册表键
		do
		{
			//参数效性判断
			if (path.empty())
			{
				LOG_ERROR(("参数错误, path[%s]", path.c_str()));
				rt = EC_PARAM_ERROR;
				break;
			}

			// 打开注册表键
			HKEY rootKey = NULL;		//根键值
			std::string sub;			//子键路径
			rt = open_reg_key(path, sub, key, rootKey, is_64_key);
			if (EC_SUCCESS != rt)
			{
				rt = EC_REG_OPEN_KEY_ERROR;
				break;
			}

			// 获取信息
			DWORD type = REG_DWORD;
			DWORD cbData = sizeof(DWORD);
			rt = RegSetValueEx(key, item.c_str(), NULL, type, (LPBYTE)&value, cbData);
			if (rt != ERROR_SUCCESS)
			{
				rt = EC_REG_SET_VALUE_ERROR;
			}

		} while (false);

		if (key != NULL)
		{
			::RegCloseKey(key);
		}

		return rt;
	}

	int CWinReg::get_subitem_string_value(const std::string &path, const std::string &item, std::string& value, bool is_64_key)
	{
		DWORD type = REG_SZ;
		return JwUtility::CWinReg::get_subitem_value(path,item,type,value,is_64_key);
	}

	int CWinReg::get_subitem_dword_value(const std::string &path, const std::string &item, DWORD& value, bool is_64_key/* = false*/)
	{
		int rt = EC_SUCCESS;
		HKEY key = NULL;				//打开的注册表键
		do
		{
			//参数效性判断
			if (path.empty())
			{
				LOG_ERROR(("参数错误, path[%s]", path.c_str()));
				rt = EC_PARAM_ERROR;
				break;
			}

			// 打开注册表键
			HKEY rootKey = NULL;		//根键值
			std::string sub;			//子键路径
			rt = open_reg_key(path, sub, key, rootKey, is_64_key,KEY_READ);
			if (EC_SUCCESS != rt)
			{
				rt = EC_REG_OPEN_KEY_ERROR;
				break;
			}

			// 获取信息
			value = 0;
			DWORD type = REG_DWORD;
			DWORD cbData = sizeof(DWORD);

			if(item.size())
				rt = RegQueryValueEx(key, item.c_str(), NULL, &type, (LPBYTE)&value, &cbData);
			else
				rt = RegQueryValueEx(key, NULL, NULL, &value, NULL, NULL);

			if (rt != ERROR_SUCCESS)
			{
				rt = EC_REG_QUERY_VALUE_ERROR;
			}

		} while (false);

		if (key != NULL)
		{
			::RegCloseKey(key);
		}

		return rt;
	}

	int CWinReg::create_subitem_key( const std::string  &path, const std::string  &kname, bool is_64_key/* = false*/)
	{
		int rt = EC_SUCCESS;			//返回值
		HKEY key = NULL;				//打开的注册表键
		HKEY hCreateKey = NULL;			//新创建的注册表键
		HKEY hKeyDestination = NULL;	//查询的注册表键

		do 
		{
			//参数检查
			if ( path.empty() || kname.empty() )
			{
				LOG_ERROR(("参数错误"));
				rt = EC_PARAM_ERROR;
				break;
			}

			//获得根键
			HKEY rootKey = NULL;
			std::string sub,tmp_sub;
			rt = open_reg_key( path, sub, key, rootKey, is_64_key);
			if ( EC_SUCCESS != rt )
			{
				break;
			}

			//判断此键是否已经存在
			std::string new_path = path + "\\" +kname;
			int irtTmp  = open_reg_key( new_path, tmp_sub, hKeyDestination, rootKey, is_64_key);
			if ( EC_SUCCESS == irtTmp )
			{
				LOG_ERROR(("存在同名的键, new_path[%s]", new_path.c_str()));
				rt = EC_REG_KEY_EXIST_ERROR;
				break;
			}

			std::string kname_path;			//注册表键的路径
			std::string::size_type ipos = path.find_first_of('\\');
			if( ipos != std::string::npos )
			{
				kname_path = path.substr( ipos + 1);
				kname_path += "\\";
				kname_path += kname;
			}
			else
			{
				kname_path = kname;
			}

			REGSAM samDesired = KEY_ALL_ACCESS;
			AppendRegSam(samDesired, kname_path, is_64_key);

			//创建注册表项
			LONG iRegRt = ::RegCreateKeyEx( rootKey, kname_path.c_str(), 0, NULL, REG_OPTION_NON_VOLATILE, samDesired, NULL, &hCreateKey, NULL);
			if ( iRegRt != ERROR_SUCCESS )
			{
				LOG_ERROR(("调用创建注册表项API失败，windows系统错误码[%d]", ::GetLastError()));
				rt = EC_REG_CREATE_KEY_ERROR;
				break;
			}
		} while (false);

		if (key != NULL)
		{
			::RegCloseKey( key );
		}
		
		if( hCreateKey != NULL )
		{
			::RegCloseKey( hCreateKey );
		}

		if (hKeyDestination != NULL)
		{
			::RegCloseKey( hKeyDestination );
		}
		return rt;
	}

	int CWinReg::create_subitem_values( const std::string  &path, const WIN_VALUE_REG_DATA &vrd, bool is_64_key/* = false*/)
	{
		int rt = EC_SUCCESS;			//返回值
		HKEY key = NULL;				//打开的注册表键
		BYTE *buf = NULL;

		do 
		{
			//参数检查
			if ( path.empty()  )
			{
				LOG_ERROR(("参数错误, path[\"\"]"));
				rt = EC_PARAM_ERROR;
				break;
			}

			//打开注表项，获得子项路径
			HKEY rootKey = NULL;	//根键
			std::string sub;		//子键路径
			rt = open_reg_key( path, sub, key, rootKey, is_64_key);
			if ( EC_SUCCESS != rt )
			{
				break;
			}
			//if(RegQueryValueEx(key,vrd.name.c_str(),NULL,NULL,NULL,NULL)!=2)
			//{
				//rt = EC_REG_EXIST_ERROR;
				//break;
			//}
			//写入值
			size_t buflen = 0;
			//将数据拷贝到缓冲
			if ( buflen < vrd.data.size())
			{
				if( NULL != buf )
				{
					delete [] buf;
					buf = NULL;
				}
				buflen = vrd.data.size() + 1;
				buf = new(std::nothrow) BYTE[ buflen];
				if (buf == NULL)
				{
					LOG_ERROR(("申请内存失败, buf[0x00]"));
					rt = EC_NEW_MEM_ERROR;
					break;
				}
				memset( buf, 0x00, buflen);
			}
			std::copy( vrd.data.begin(), vrd.data.end(), buf);

			//设置注册表键的值
			if ( ERROR_SUCCESS != ::RegSetValueEx( key, vrd.name.c_str(), 0, vrd.type, buf, vrd.data.size()))
			{
				LOG_ERROR(("调用设置注册表值API失败，windows系统错误码[%d]", ::GetLastError()));
				rt = EC_REG_SET_VALUE_ERROR;
				break;
			}

		} while (false);
		if ( buf != NULL )
		{
			delete [] buf;
		}
		if ( key != NULL )
		{
			::RegCloseKey( key);
		}
	
		return rt;
	}

	int CWinReg::del_subitem_key( const std::string  &path, bool is_64_key/* = false*/)
	{
		int rt = EC_SUCCESS;			//返回值
		HKEY key = NULL;				//打开的注册表
		char * itemName = NULL;
		HKEY tmp_key = NULL;

		do 
		{
			//参数的有效性检查
			if( path.empty()) 
			{
				LOG_ERROR(("参数错误"));
				rt = EC_PARAM_ERROR;	
				break;	
			}
			HKEY rootKey = NULL;
			HKEY tmp_key = NULL;
			std::string sub,tmp_sub,tmp_path,keyname_del;

			std::string::size_type k = 0;
			k = path.rfind("\\");
			if ( k == std::string::npos )
			{
				LOG_ERROR(("注册表鍵的路径错误, path[%s]", path.c_str()));
				rt = EC_REG_PATH_ERROR;
				break;
			}
			tmp_path = path.substr(0, k);
			keyname_del = path.substr( k+1 );

			rt = open_reg_key( path, sub, key, rootKey, is_64_key );
			if ( EC_SUCCESS != rt )
			{
				break;
			}

			//查得当前键下的子键项数
			DWORD	numSubKey = 0;		//查得子键的项数
			if ( ::RegQueryInfoKey( key, NULL, NULL, NULL, &numSubKey, NULL, NULL, NULL
				, NULL,NULL, NULL, NULL) != ERROR_SUCCESS )
			{
				LOG_ERROR(("调用查询键信息API失败, windows系统错误码[%d]", ::GetLastError()));
				rt = EC_QUERY_INFO_KEY_ERROR;
				break;
			}

			DWORD i = numSubKey;
			itemName = new(std::nothrow) char[ITEM_NAME_MAXLEN + 1];
			if ( NULL == itemName)
			{
				LOG_ERROR(("申请内存失败"));
				rt = EC_NEW_MEM_ERROR;
				break;
			}
			memset(itemName, 0, ITEM_NAME_MAXLEN + 1);

			while( i != 0 )
			{ 
				//枚举子键
				LONG result = ::RegEnumKey(key, i-1, itemName, ITEM_NAME_MAXLEN);

				if(result != ERROR_SUCCESS)
				{
					if(result != ERROR_NO_MORE_ITEMS)			//遍历结束
					{
						LOG_ERROR(("调用枚举键API失败,windows系统错误码[%d]", ::GetLastError()));
						rt = EC_ENUM_KEY_ERROR;
					}
					//枚举子键失败
					break;
				}

				std::string next_name = path;
				next_name +="\\";
				next_name += itemName;
				del_subitem_key(next_name, is_64_key);
				--i; 
			}//end while

			if( EC_SUCCESS != rt )
			{
				break;
			}
			
			rt = open_reg_key( tmp_path, tmp_sub, tmp_key, rootKey, is_64_key );
			if( EC_SUCCESS != rt )
			{
				break;
			}
			
			REGSAM samDesired = KEY_ALL_ACCESS;
			AppendRegSam(samDesired, tmp_path, is_64_key );

			//LONG irt = RegDeleteKey(tmp_key,keyname_del.c_str()); 此法无法删除64位注册表键值

			typedef LONG (WINAPI* FnRegDeleteKeyEx)(HKEY, LPCTSTR, REGSAM, DWORD);
			
			FnRegDeleteKeyEx fnRegDeleteKeyEx = (FnRegDeleteKeyEx)GetProcAddress(GetModuleHandle("advapi32.dll"), "RegDeleteKeyExA");
			if (fnRegDeleteKeyEx)
			{
				LONG irt = fnRegDeleteKeyEx(tmp_key, keyname_del.c_str(), samDesired, 0);
				if ( irt !=  ERROR_SUCCESS )
				{
					LOG_ERROR(("调用删除注册表API失败，windows系统错误码[%d]", ::GetLastError()));
					rt = EC_REG_DELETE_KEY_ERROR;
					break;
				}
			}
			else
			{
				LONG irt = RegDeleteKey(tmp_key, keyname_del.c_str());
				if ( irt !=  ERROR_SUCCESS )
				{
					LOG_ERROR(("调用删除注册表API失败，windows系统错误码[%d]", ::GetLastError()));
					rt = EC_REG_DELETE_KEY_ERROR;
					break;
				}
			}

		} while (false);
		if ( itemName != NULL )
		{
			delete [] itemName;
		}
		if ( key != NULL )
		{
			::RegCloseKey( key);
		}
		if ( tmp_key != NULL )
		{
			::RegCloseKey( tmp_key);
		}
		return rt;
	}

	int CWinReg::del_subitem_values( const std::string  &path, const std::string  &name, bool is_64_key/* = false*/)
	{
		int rt = EC_SUCCESS;			//返回值
		HKEY key = NULL;				//打开注册表键

		do 
		{
			//参数检查
			if( path.empty() || name.empty() )
			{
				LOG_ERROR(("参数错误"));
				rt = EC_PARAM_ERROR;
				break;	
			}

			//获得注册表的KEY句柄
			HKEY rootKey = NULL;
			std::string sub;
			rt = open_reg_key( path, sub, key, rootKey, is_64_key);
			if ( EC_SUCCESS != rt )
			{
				break;
			}

			//删除指定的值
			if ( RegDeleteValue(key, name.c_str()) != ERROR_SUCCESS )
			{
				LOG_ERROR(("调用删除指定注册表值API失败,windows系统错误码[%d]",  ::GetLastError()));
				rt = EC_REG_DELETE_VALUE_ERROR;
				break;
			}
		} while (false);

		if( key != NULL)
		{
			RegCloseKey(key);
		}
		return rt;
	}

	int CWinReg::rename_subitem_values( const std::string  &path, const std::string  &old_name, const std::string  &new_name, bool is_64_key/* = false*/)
	{
		int rt = EC_SUCCESS;			//返回值
		HKEY key = NULL;				//打开的注册表项
		char* pValue = NULL;			//注册表的值名

		do 
		{
			//参数检查
			if( path.empty() || old_name.empty() || new_name.empty() )
			{
				LOG_ERROR(("参数错误"));
				rt = EC_PARAM_ERROR;
				break;	
			}

			//打开指定路径的KEY句柄
			HKEY rootKey = NULL;
			std::string sub;
			rt = open_reg_key( path, sub, key, rootKey, is_64_key);
			if ( EC_SUCCESS != rt )
			{
				break;
			}
			
			//查询指定路径KEY的信息
			DWORD  v_maxlen = 0;
			if ( ::RegQueryInfoKey( key, NULL, NULL, NULL, NULL, NULL, NULL, NULL
				, NULL, &v_maxlen, NULL, NULL) != ERROR_SUCCESS )
			{
				LOG_ERROR(("调用查询注册表信息API失败,windows系统错误码[%d]", ::GetLastError()));
				rt = EC_QUERY_INFO_KEY_ERROR;
				break;
			}

			v_maxlen += ITEM_VALUE_MAXLEN;
			pValue = new(std::nothrow) char [v_maxlen + 1];
			if (pValue == NULL)
			{
				LOG_ERROR(("申请内存失败, pValue[0x00]"));
				rt = EC_NEW_MEM_ERROR;
				break;
			}
			memset(pValue, 0, v_maxlen + 1);
			DWORD type;

			//获取旧键值信息
			if ( RegQueryValueEx(key, old_name.c_str(), 0, &type, (unsigned char *)pValue,&v_maxlen) != ERROR_SUCCESS )
			{
				LOG_ERROR(("调用查询注册表值API失败，windows系统错误码[%d]", ::GetLastError()));
				rt = EC_REG_QUERY_VALUE_ERROR;
				break;
			}

			//判断新名键值是否已经存在，存在则返回键值名已存在的错误
			if ( RegQueryValueEx(key,new_name.c_str(), 0, 0, 0, 0) == ERROR_SUCCESS )
			{
				LOG_ERROR(("调用查询注册表值API失败，windows系统错误码[%d]", ::GetLastError()));
				rt = EC_REG_VALUE_EXIST_ERROR;
				break;
			}

			//添加新的注册表值
			LONG i = ::RegSetValueEx( key,new_name.c_str(), 0, type , (unsigned char *)pValue, v_maxlen);
			if ( ERROR_SUCCESS != i )
			{
				LOG_ERROR(("调用设置注册表值API失败，windows系统错误码[%d]", i));
				rt = EC_REG_SET_VALUE_ERROR;
				break;
			}
			
			//删除旧的注册表值
			if ( RegDeleteValue(key,old_name.c_str()) != ERROR_SUCCESS )
			{
				LOG_ERROR(("调用删除注册表值API失败，windows系统错误码[%d]", ::GetLastError()));
				rt = EC_REG_DELETE_VALUE_ERROR;
				break;
			}

		} while (false);
		if ( pValue != NULL )
		{
			delete [] pValue;
		}
		if ( key != NULL )
		{
			::RegCloseKey(key);
		}
		
		return rt;
	}

	int CWinReg::rename_subitem_key( const std::string  &path, const std::string  &old_name, const std::string  &new_name, bool is_64_key/* = false*/)
	{
		int rt = EC_SUCCESS;			//返回值
		HKEY hKeySource = NULL;
		HKEY hKeyDestination = NULL;
		HKEY key = NULL;
		std::string strfilename;

		do 
		{
			//参数检查
			if( path.empty() || old_name.empty() || new_name.empty())
			{
				LOG_ERROR(("参数错误"));
				rt = EC_PARAM_ERROR;
				break;		
			}

			//查询新建的注册表项是否存在
			HKEY rootKey = NULL;
			std::string tmp_path,tmp_sub;
			strfilename = strRegFile();
			DeleteFile(strfilename.c_str());
			BOOL brt = RestorePrivilege(TRUE);
			brt = BackupPrivilege(TRUE);
			std::string new_path = path + "\\" +new_name;
			rt = open_reg_key( new_path, tmp_sub, hKeyDestination, rootKey, is_64_key);
			if ( EC_SUCCESS == rt )
			{
				LOG_ERROR(("新键的注册表键已经存在, new_path[%s]", new_path.c_str()));
				rt = EC_REG_KEY_EXIST_ERROR;
				break;
			}

			//打开原来的注册表的项
			tmp_path = path + "\\" + old_name;
			rt = open_reg_key( tmp_path, tmp_sub, hKeySource, rootKey, is_64_key);
			if ( EC_SUCCESS != rt )
			{
				break;
			}

			//将旧的注册表项的值保存到指定文件中
			LONG iRegRt = 0;
			iRegRt = RegSaveKey(hKeySource, strfilename.c_str(), NULL);
			if ( iRegRt != ERROR_SUCCESS )
			{
				LOG_ERROR(("调用保存注册表键API失败,windows系统错误码[%d]", GetLastError()));
				rt = EC_REG_SAVE_KEY_ERROR;
				break;
			}

			//打印创建注册表路径下的项
			std::string sub;
			rt = open_reg_key( path, sub, key, rootKey, is_64_key);
			if ( EC_SUCCESS != rt )
			{
				break;
			}

			//创建新的注册表项
			REGSAM samDesired = KEY_ALL_ACCESS;
			AppendRegSam(samDesired, path, is_64_key);

			iRegRt = ::RegCreateKeyEx( key, new_name.c_str(), 0, NULL, REG_OPTION_NON_VOLATILE, samDesired, NULL, &hKeyDestination, NULL);
			if ( iRegRt != ERROR_SUCCESS ) 
			{
				LOG_ERROR(("调用创建注册表键API失败,windows系统错误码[%d]", GetLastError()));
				rt = EC_REG_CREATE_KEY_ERROR;
				break;
			}

			//将原注册表的键值设置到新项当中
			iRegRt = ::RegRestoreKey(hKeyDestination,strfilename.c_str(),REG_FORCE_RESTORE);
			if (  iRegRt != ERROR_SUCCESS )
			{
				LOG_ERROR(("调用创建注册表键值恢复API失败,windows系统错误码[%d]", GetLastError()));
				rt = EC_REG_RESTORE_KEY_ERROR;
				break;
			}

			//删除旧的注册表项
			rt = del_subitem_key(tmp_path, is_64_key);	
			if ( EC_SUCCESS != rt )
			{
				break;
			}
		} while (false);

		DeleteFile(strfilename.c_str());
		if ( key != NULL )
		{
			::RegCloseKey(key);
		}
		if ( hKeySource != NULL )
		{
			::RegCloseKey(hKeySource);
		}
		if ( hKeyDestination != NULL )
		{
			::RegCloseKey(hKeyDestination);
		}

		//权限恢复
		RestorePrivilege(FALSE);
		BackupPrivilege(FALSE);

		return rt;
	}

	int CWinReg::open_reg_key(const std::string & path, std::string & sub, HKEY & hkey, HKEY & h_root, bool is_64_key, REGSAM samDesired)
	{
		////将根键和子键分开
		std::string::size_type k = 0;
		k = path.find_first_of( '\\' ); 
		//path只有根路径时
		if ( std::string::npos == k )
		{
			if ( path.compare( strHKCR() ) == 0 )
			{
				h_root = HKEY_CLASSES_ROOT;
			}
			else if ( path.compare( strHKLM() ) == 0 )
			{
				h_root = HKEY_LOCAL_MACHINE;
			}
			else if ( path.compare( strHKCU()) == 0 )
			{
				h_root = HKEY_CURRENT_USER;
			}
			else if ( path.compare( strHKU() ) == 0 )
			{
				h_root = HKEY_USERS;
			}
			else if ( path.compare( strHKCC() ) == 0 )
			{
				h_root = HKEY_CURRENT_CONFIG;
			}
			else 
			{
				LOG_ERROR(("根键名错误, path[%s]", path.c_str()));
				return EC_GET_ROOT_HKEY_ERROR;
			}

		}
		else
		{
			std::string root = path.substr( 0, k );
			sub = path.substr( k+1 );

			////确定根键句柄
			if ( root.compare( strHKCR() ) == 0 )
			{
				h_root = HKEY_CLASSES_ROOT;
			}
			else if ( root.compare( strHKLM() ) == 0 )
			{
				h_root = HKEY_LOCAL_MACHINE;
			}
			else if ( root.compare( strHKCU() ) == 0 )
			{
				h_root = HKEY_CURRENT_USER;
			}
			else if ( root.compare( strHKU() ) == 0 )
			{
				h_root = HKEY_USERS;
			}
			else if ( root.compare( strHKCC() ) == 0 )
			{
				h_root = HKEY_CURRENT_CONFIG;
			}

		}

		AppendRegSam(samDesired, sub, is_64_key);

		if ( ::RegOpenKeyEx( h_root, sub.c_str(), 0, samDesired, &hkey ) != ERROR_SUCCESS )
		{
			LOG_ERROR(("调用打开注册表键API失败，windows系统错误码[%d]", ::GetLastError()));
			return EC_REG_OPEN_KEY_ERROR;
		}

		return EC_SUCCESS;
	}

	int CWinReg::get_root_key_list(KEY_REG_CALLBACK key_data_deal, void * param)
	{
		int rt = EC_SUCCESS;			//返回值
		do 
		{
			//参数检查
			if( NULL == key_data_deal )
			{
				LOG_ERROR(("参数错误, key_data_deal[0x00]"));
				rt = EC_PARAM_ERROR;
				break;	
			}

			WIN_KEY_REG_DATA rkd;
			DWORD sub_keys_count;
			DWORD sub_values_count;
			FILETIME mod_time;
			//HKEY_CLASSES_ROOT
			if ( ERROR_SUCCESS != RegQueryInfoKey( HKEY_CLASSES_ROOT, NULL, NULL, NULL, &sub_keys_count
				, NULL, NULL, &sub_values_count, NULL, NULL, NULL, &mod_time))
			{
				LOG_ERROR(("调用查询键信息API失败,windows系统错误码[%d]", ::GetLastError()));
				rt = EC_QUERY_INFO_KEY_ERROR;
				break;
			}

			rkd.sub_key_num = sub_keys_count;
			rkd.sub_value_num = sub_values_count;
			rkd.name = strHKCR();
			if( 0 != key_data_deal(param, rkd) )
			{
				LOG_ERROR(("调用回调函数失败"));
				rt = EC_CALLBACK_ERROR;
				break;
			}

			//HKEY_CURRENT_USER
			if ( ERROR_SUCCESS != RegQueryInfoKey( HKEY_CURRENT_USER, NULL, NULL, NULL, &sub_keys_count
				, NULL, NULL, &sub_values_count, NULL, NULL, NULL, &mod_time))
			{
				LOG_ERROR(("调用查询键信息API失败,windows系统错误码[%d]", ::GetLastError()));
				rt = EC_QUERY_INFO_KEY_ERROR;
				break;
			}

			rkd.sub_key_num = sub_keys_count;
			rkd.sub_value_num = sub_values_count;
			rkd.name = strHKCU();
			if( 0 != key_data_deal(param, rkd) )
			{
				LOG_ERROR(("调用回调函数失败"));
				rt = EC_CALLBACK_ERROR;
				break;
			}

			//HKEY_LOCAL_MACHINE
			if ( ERROR_SUCCESS != RegQueryInfoKey( HKEY_LOCAL_MACHINE, NULL, NULL, NULL, &sub_keys_count
				, NULL, NULL, &sub_values_count, NULL, NULL, NULL, &mod_time))
			{
				LOG_ERROR(("调用查询键信息API失败,windows系统错误码[%d]", ::GetLastError()));
				rt = EC_QUERY_INFO_KEY_ERROR;
				break;
			}
			rkd.sub_key_num = sub_keys_count;
			rkd.sub_value_num = sub_values_count;
			rkd.name = strHKLM();
			if( 0 != key_data_deal(param, rkd) )
			{
				LOG_ERROR(("调用回调函数失败"));
				rt = EC_CALLBACK_ERROR;
				break;
			}

			//HKEY_USERS
			if ( ERROR_SUCCESS != RegQueryInfoKey( HKEY_USERS, NULL, NULL, NULL, &sub_keys_count
				, NULL, NULL, &sub_values_count, NULL, NULL, NULL, &mod_time))
			{
				LOG_ERROR(("调用查询键信息API失败,windows系统错误码[%d]", ::GetLastError()));
				rt = EC_QUERY_INFO_KEY_ERROR;
				break;
			}

			rkd.sub_key_num = sub_keys_count;
			rkd.sub_value_num = sub_values_count;
			rkd.name = strHKU();
			if( 0 != key_data_deal(param, rkd) )
			{
				LOG_ERROR(("调用回调函数失败"));
				rt = EC_CALLBACK_ERROR;
				break;
			}

			if ( ERROR_SUCCESS != RegQueryInfoKey( HKEY_CURRENT_CONFIG, NULL, NULL, NULL, &sub_keys_count
				, NULL, NULL, &sub_values_count, NULL, NULL, NULL, &mod_time))
			{
				LOG_ERROR(("调用查询键信息API失败,windows系统错误码[%d]", ::GetLastError()));
				rt = EC_QUERY_INFO_KEY_ERROR;
				break;
			}

			rkd.sub_key_num = sub_keys_count;
			rkd.sub_value_num = sub_values_count;
			rkd.name = strHKCC();
			if( 0 != key_data_deal(param, rkd) )
			{
				LOG_ERROR(("调用回调函数失败"));
				rt = EC_CALLBACK_ERROR;
				break;
			}
		} while (false);

		return rt;
	}

	BOOL CWinReg::RestorePrivilege(BOOL bEnable)
	{
		BOOL              bResult = TRUE;
		HANDLE            hToken = NULL ;
		TOKEN_PRIVILEGES  TokenPrivileges;

		if(OpenProcessToken(GetCurrentProcess(),TOKEN_QUERY | TOKEN_ADJUST_PRIVILEGES,&hToken) == 0)
		{
			return FALSE;
		}
		TokenPrivileges.PrivilegeCount           = 1;
		TokenPrivileges.Privileges[0].Attributes = bEnable ? SE_PRIVILEGE_ENABLED : 0;
		BOOL brt = LookupPrivilegeValue(NULL,SE_RESTORE_NAME,&TokenPrivileges.Privileges[0].Luid);
		brt = AdjustTokenPrivileges(hToken,FALSE,&TokenPrivileges,sizeof(TOKEN_PRIVILEGES),NULL,NULL);

		DWORD i = GetLastError();
		if( i != ERROR_SUCCESS)
		{
			bResult = FALSE;
		}
		CloseHandle(hToken);

		return bResult;
	}

	BOOL CWinReg::BackupPrivilege(BOOL bEnable)
	{
		BOOL              bResult = TRUE;
		HANDLE            hToken = NULL;
		TOKEN_PRIVILEGES  TokenPrivileges;

		if(OpenProcessToken(GetCurrentProcess(),TOKEN_QUERY | TOKEN_ADJUST_PRIVILEGES,&hToken) == 0)
		{
			return FALSE;
		}
		TokenPrivileges.PrivilegeCount           = 1;
		TokenPrivileges.Privileges[0].Attributes = bEnable ? SE_PRIVILEGE_ENABLED : 0;
		BOOL brt = LookupPrivilegeValue(NULL,SE_BACKUP_NAME,&TokenPrivileges.Privileges[0].Luid);
		brt = AdjustTokenPrivileges(hToken,FALSE,&TokenPrivileges,sizeof(TOKEN_PRIVILEGES),NULL,NULL);

		DWORD i = GetLastError();
		if( i != ERROR_SUCCESS)
		{
			bResult = FALSE;
		}
		CloseHandle(hToken);

		return bResult;
	}

	void CWinReg::AppendRegSam(REGSAM& samDesired, const std::string& key_path, bool is_64_key/* = false*/)
	{
		if (is_64_key)
		{
			BOOL bIsWow64 = FALSE;
			typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS)(HANDLE, PBOOL);
			LPFN_ISWOW64PROCESS fnIsWow64Process;
			fnIsWow64Process = (LPFN_ISWOW64PROCESS)GetProcAddress(GetModuleHandle(TEXT("kernel32")), "IsWow64Process");

			if (NULL != fnIsWow64Process)
			{
				fnIsWow64Process(GetCurrentProcess(),&bIsWow64);
				if (bIsWow64) 
				{
					// 如果当前操作的键不是Wow6432Node，才需要新增标识
					if (std::string::npos == key_path.find("Wow6432Node"))
					{
						samDesired |= KEY_WOW64_64KEY;
					}
				}
			}
		}
	}
}

