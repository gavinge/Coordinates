

/***************************************************************************************
Created:	   2024年01月12日
Filename: 	   CppSQLiteEx.h
File ext:	   h
CXX_STANDARD:  11
Platform:      支持Windows\Linux
Purpose:	   扩展一个CppSQLite的功能
Author:        geshan@hotmail.com
***************************************************************************************/

#ifndef __CPPSQLite3Ex_H__
#define __CPPSQLite3Ex_H__

#pragma once

#include "CppSQLite3.h"
#include "log\logger_helper.h"

class CppSQLiteEx {
public:
	CppSQLiteEx() {};
	~CppSQLiteEx() {};

private:
	CppSQLite3DB db;

public:

	/// <summary> checkbd 是否已经打开 这个函数功能有点模糊，但这个</summary>
	/// <params>  </params>
	/// <returns> true:存在  false: 不存在 </returns>
	bool checkdb() {
		return db.checkdb();
	}

	bool tableExists(const char* szTable) {
		return db.tableExists(szTable);
	}

	/// <summary> open 打开数据库 </summary>
	/// <params>  char* 数据库文件路径</params>
	/// <returns> true:成功  false: 失败 </returns>
	virtual bool open(const char* szFile) {
	
		bool bret = true;
		try {
			db.open(szFile);
			LOGGER_INFO("open file [%s] successful!" << szFile);
		}
		catch (CppSQLite3Exception& e) {
			LOGGER_INFO("open err!" << szFile << "   !!!SQLite exception: " << e.errorCode() << " - " << e.errorMessage() << std::endl);
			bret = false;
		}
		return bret;
	}


	/// <summary> 执行sql语句 </summary>
	/// <params>  szSQL 将要执行的sql语句</params>
	/// <returns>  -1： 未知致命失败  0:成功  >0: 错误（详见sqlite3.h 的418~449行） </returns>
	virtual int execDML(const char* szSQL) {

		int nret = 0;/*SQLITE_OK*/
		try {
			nret = db.execDML(szSQL);
			//LOGGER_INFO("exesql successful!");
		}
		catch (CppSQLite3Exception& e) {
			LOGGER_INFO("execDML err!" << szSQL << "   !!!SQLite exception: " << e.errorCode() << " - " << e.errorMessage() << std::endl);
			nret = -1;
		}
		return nret;
	}


	/// <summary> 执行查询语句 </summary>
	/// <params>  szSQL 将要执行的sql语句   queryResult 查询出来的结果</params>
	/// <returns> true:成功  false: 失败 </returns>
	virtual bool execQuery(const char* szSQL, CppSQLite3Query & queryResult) {

		bool bret = true;/*SQLITE_OK*/
		try {
			queryResult = db.execQuery(szSQL);
			//LOGGER_INFO("execQuery successful!");
		}
		catch (CppSQLite3Exception& e) {
			LOGGER_INFO("execQuery err!" << szSQL << "   !!!SQLite exception: " << e.errorCode() << " - " << e.errorMessage() << std::endl);
			bret = false;
		}
		return bret;
	}

	/// <summary> 统计sql </summary>
	/// <params>  szSQL 将要统计执行的sql语句 </params>
	/// <returns> 统计个数 </returns>
	int execScalar(const char* szSQL) {
		try {

			return db.execScalar(szSQL, 0);
			//LOGGER_INFO("execScalar successful!");
		}
		catch (CppSQLite3Exception& e) {
			LOGGER_INFO("execScalar err!" << "   !!!SQLite exception: " << e.errorCode() << " - " << e.errorMessage() << std::endl);
		}
		return 0;
	}

	/// <summary> 关闭sql </summary>
	/// <params>  无 </params>
	/// <returns> true:成功  false: 失败 </returns>
	virtual bool close() {

		bool bret = true;/*SQLITE_OK*/
		try {
			db.close();
			//LOGGER_INFO("close successful!");
		}
		catch (CppSQLite3Exception& e) {
			LOGGER_INFO("close err!" << "   !!!SQLite exception: " << e.errorCode() << " - " << e.errorMessage() << std::endl);
			bret = false;
		}
		return bret;
	}
};


#endif // 