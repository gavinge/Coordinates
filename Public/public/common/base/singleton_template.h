
/***************************************************************************************
	Created:	   2024年01月11日 
	Filename: 	   singleton_template.h
	File ext:	   h
	CXX_STANDARD:  11
	Platform:      支持Windows/Linux平台
	Purpose:	   通用单模模板，考虑到全局内存中生命周期问题，这里暂没做release的函数
	Author:        geshan@hotmail.com
***************************************************************************************/

#ifndef SINGLETON_TEMPLATE_H
#define SINGLETON_TEMPLATE_H

#include <memory>
#include <mutex>


namespace public_common {

	template <typename T>
	class Singleton
	{
	public:
		static std::unique_ptr<T>& GetInstance() {
			std::call_once(onceFlag, [&]() { instance_ptr.reset(new T()/*std::make_unique<T>() c++ 版本支持*/); });
			return instance_ptr;
		}
	protected:
		Singleton() {}
		~Singleton() {}
		Singleton(Singleton const&) = delete;
		Singleton& operator=(Singleton const&) = delete;

	private:
		static std::unique_ptr<T> instance_ptr;
		static std::once_flag onceFlag;
	};

	template <class T>
	std::unique_ptr<T> Singleton<T>::instance_ptr;

	template <class T>
	std::once_flag Singleton<T>::onceFlag;

	///定义一个宏全局，可以用这个宏生成相关单模实例类，使用如下。
	//***************************************************************************************************
	#define SINGLETON_MAKER(class)			public_common::Singleton<class>::GetInstance()
	//***************************************************************************************************



	//以下为模板使用方法说明
	//*----------------------------------------------------------------------------------------
	/*class Logger :public Singleton<Logger>
	{
		friend class Singleton<Logger>;
	private:
		Logger() {};


	public:
		~Logger() {};
		void print(void) { std::cout << "hello logger...." << std::endl; }
	};

	//使用方法eg:
    //①. #define g_logger		SINGLETON_MAKER(Logger)*/
	//②. g_logger->print();           
	//----------------------------------------------------------------------------------------*/

}  // namespace public_common
#endif //SINGLETON_TEMPLATE_H