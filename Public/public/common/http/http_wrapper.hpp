/*
* 文件名: win_tools.hpp
* 作者: geshan@hotmail.com
* 创建日期: 2023-12-25
* 描述: 使用CURL库 http请求数据
*/

#ifndef _CURL_HTTP_REQUEST_HEAD_
#define _CURL_HTTP_REQUEST_HEAD_

#ifdef _WIN32
#define CURL_STATICLIB
#pragma comment(lib, "ws2_32.lib" )
#pragma comment(lib, "wldap32.lib")
#pragma comment(lib, "libcrypto.lib")
#pragma comment(lib, "libssl.lib")
#endif

#include "curl/curl.h"
#include <string>
#include "win_tools/win_tools.hpp"


static int g_connect_local_port = -2;

namespace JwUtility
{
	inline size_t curl_http_request_process_data(void *buffer, size_t size, size_t nmemb, void *user_p)
	{
		std::string* result = (std::string*)user_p;

		std::string tmp((char*)buffer, size * nmemb);

		result->append(tmp);

		return size * nmemb;
	}

	// CURL请求数据
	inline CURLcode curl_http_request(
		const std::string& url,				// 请求地址
		const std::string& dns_server,		// 自定义dns地址
		const std::string& post_data,		// 提交数据，可为空，则为Get请求
		std::string& result,				// 返回结果
		const int connect_timeout = 20,     // 连接超时时间
		const int recv_timeout = 20,        // 接收数据超时时间
		unsigned int* http_code = NULL)     // HTTP响应码
	{
		CURLcode return_code = CURLE_OK;

		result.clear();

		CURL *easy_handle = curl_easy_init();
		if (NULL == easy_handle)
			return CURLE_FAILED_INIT;

		struct curl_slist *headerlist = NULL;

		do 
		{
			curl_easy_setopt(easy_handle, CURLOPT_URL, url.c_str());
			if (!post_data.empty())
			{
				headerlist = curl_slist_append(headerlist, "Expect:");
				curl_easy_setopt(easy_handle, CURLOPT_HTTPHEADER, headerlist);
			}
			curl_easy_setopt(easy_handle, CURLOPT_WRITEFUNCTION, curl_http_request_process_data);
			curl_easy_setopt(easy_handle, CURLOPT_WRITEDATA, &result);
			curl_easy_setopt(easy_handle, CURLOPT_SSL_VERIFYPEER, 0L);
			curl_easy_setopt(easy_handle, CURLOPT_SSL_VERIFYHOST, 0L);
			curl_easy_setopt(easy_handle, CURLOPT_CONNECTTIMEOUT, connect_timeout ); 
			curl_easy_setopt(easy_handle, CURLOPT_TIMEOUT, recv_timeout );

			curl_easy_setopt(easy_handle, CURLOPT_NOSIGNAL, 1);
			curl_easy_setopt(easy_handle, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);

			if (!dns_server.empty())
				curl_easy_setopt(easy_handle, CURLOPT_DNS_SERVERS, dns_server.c_str() );

			if (!post_data.empty())
				curl_easy_setopt(easy_handle, CURLOPT_POSTFIELDS, post_data.c_str()); 
			
//			curl_easy_setopt(easy_handle, CURLOPT_VERBOSE, 1);
			
			// add by Zhiguo, 2019-07-23
			// 显式地将CURLOPT_PROXY属性设置为空, 禁止libcurl检查并使用环境变量来使用代理
			curl_easy_setopt(easy_handle, CURLOPT_PROXY, "");

			// 
			// 未获取过, 获取local_port
			// -2表示g_connect_local_port未初始化
			// -1表示没有设置connect_local_port


			///以下代码表示，可指定只出的端口，不用系统指定的随机的端口
			//if (g_connect_local_port == -2)
			//{
			//	std::string connect_local_port;
			//	//std::string config_xml =  "/config.xml";
			//	//utility::CXmlEx::read_xml_attribute(config_xml, "//Data/var[@name='connect_local_port']", "value", connect_local_port);
			//	if (!connect_local_port.empty())
			//	{
			//		g_connect_local_port = atoi(connect_local_port.c_str());
			//	}
			//	else
			//	{
			//		g_connect_local_port = -1;
			//	}
			//}
			//
			//// 如果有获取到connect_local_port, 则设置curlopt
			//if (g_connect_local_port >= 0)
			//{
			//	curl_easy_setopt(easy_handle, CURLOPT_LOCALPORT, g_connect_local_port+1);
			//	curl_easy_setopt(easy_handle, CURLOPT_LOCALPORTRANGE, 10);
			//}
			// add end

			return_code = curl_easy_perform(easy_handle);

			if (http_code)
				curl_easy_getinfo(easy_handle, CURLINFO_RESPONSE_CODE, http_code);

		}while(false);

		curl_easy_cleanup(easy_handle);

		if(headerlist)
			curl_slist_free_all (headerlist);

		return return_code;
	}
}

#endif