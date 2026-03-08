/***********************************************************
	Created:	   2024年01月10日 16:40
	Filename: 	   json_util.hpp
	File ext:	   hpp
	CXX_STANDARD:  11
	Platform:      支持Windows/Linux平台
	Purpose:	   主进程用到的所有和路径相关的信息.用类
	Author:        geshan@hotmail.com
***********************************************************/


#ifndef __JSON_UTIL_H__
#define __JSON_UTIL_H__

#include <iostream>
#include <sstream>
#include "base\check_class_function_template.hpp"
#include <jsoncpp/json.h>

namespace JwUtility {

	namespace JsonUtility {
		
		/// 下面两类函数有空可以写个宏，既可以支持不同类型的函数
		/// <summary>
		/// 辅助函数模板，用于检查是否有成员函数toJson
		/// </summary>
		//template <typename T>
		//constexpr auto has_member_function_toJson_impl(int) -> decltype(std::declval<T>().toJson(), true) {
		//	return true;
		//}

		//template <typename T>
		//constexpr bool has_member_function_toJson_impl(...) {
		//	return false;
		//}

		////对外检测toJson函数
		//template <typename T>
		//constexpr bool has_member_function_toJson() {
		//	return has_member_function_toJson_impl<T>(0);
		//}


		///// <summary>
		///// 辅助函数模板，用于检查是否有成员函数fromJson
		///// </summary>
		//template <typename T>
		//constexpr auto has_member_function_fromJson_impl(int) -> decltype(std::declval<T>().fromJson(), true) {
		//	return true;
		//}

		//template <typename T>
		//constexpr bool has_member_function_fromJson_impl(...) {
		//	return false;
		//}

		////对外检测fromJson函数
		//template <typename T>
		//constexpr bool has_member_function_fromJson() {
		//	return has_member_function_fromJson_impl<T>(0);
		//}
		

		/// <summary>
		/// 将结构体转换为 JSON 字符串的函数
		/// </summary>
		/*template<typename T>
		std::string structToJson(const T& data) {
		Json::Value root(Json::objectValue);
		data.toJson(root);

		Json::FastWriter writer;
		return writer.write(root);
		}*/

		template<typename T>
		bool objectToJson(const T& data, std::string & jsonString) {
			Json::Value root(Json::objectValue);
			data.toJson(root);

			Json::FastWriter writer;
			jsonString = writer.write(root);
			return true;
		}



		/// <summary>
		/// 将 JSON 字符串转换为结构体的函数
		/// </summary>
		/*template<typename T>
		T jsonToStruct(const std::string& jsonString) {
			T data;

			Json::Value root;
			Json::Reader reader;
			if (!reader.parse(jsonString, root)) {
				throw std::runtime_error("Failed to parse JSON");
			}

			data.fromJson(root);

			return data;
		}*/

		template<typename T>
		bool jsonToObject(const std::string& jsonString, T & data) {
			bool bret = false;
			do
			{
				Json::Value root;
				Json::Reader reader;
				if (!reader.parse(jsonString, root)) {
					break;
				}
				data.fromJson(root);
				bret = true;
			} while (false);
			return bret;
		}



		/// <summary>
		/// 将结构体数组转换为 JSON 字符串的函数
		/// </summary>
		/*template<typename T>
		std::string arrayStructToJson(const std::vector<T>& dataArray) {
			Json::Value root(Json::arrayValue);

			for (const auto& data : dataArray) {
				Json::Value obj(Json::objectValue);
				data.toJson(obj);
				root.append(obj);
			}

			Json::FastWriter writer;
			return writer.write(root);
		}*/


		template<typename T>
		bool arrayObjectToJson(const std::vector<T>& dataArray, std::string & jsonString) {
			Json::Value root(Json::arrayValue);
			jsonString = "";

			for (const auto& data : dataArray) {
				Json::Value obj(Json::objectValue);
				data.toJson(obj);
				root.append(obj);
			}

			Json::FastWriter writer;
			jsonString = writer.write(root);
			return true;
		}




		/// <summary>
		/// 将 JSON 字符串转换为结构体数组的函数
		/// </summary>
		/*template<typename T>
		std::vector<T> jsonToArrayStruct(const std::string& jsonString) {
			std::vector<T> dataArray;

			Json::Value root;
			Json::Reader reader;
			if (!reader.parse(jsonString, root) || !root.isArray()) {
				throw std::runtime_error("Failed to parse JSON array");
			}

			for (const auto& item : root) {
				T data;
				data.fromJson(item);
				dataArray.push_back(data);
			}
			return dataArray;
		}*/

		template<typename T>
		bool jsonToArrayObject(const std::string& jsonString, std::vector<T> & dataArray) {

			bool bret = false;
			dataArray.clear();

			do
			{
				Json::Value root;
				Json::Reader reader;

				if (!reader.parse(jsonString, root) || !root.isArray()) {
					break;
				}

				for (const auto& item : root) {
					T data;
					data.fromJson(item);
					dataArray.push_back(data);
				}

				bret = true;
			} while (false);

			return bret;
		}
	}
}

#endif //__JSON_UTIL_H__