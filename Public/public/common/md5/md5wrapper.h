/*
 *	This is my wrapper-class to create
 *	a MD5 Hash from a string and a file.
 *
 *	This code is completly free, you 
 *	can copy it, modify it, or do 
 *	what ever you want with it.
 *
 *	Feb. 2005
 *	Benjamin Grüdelbach
 *
 */

//include protection
#ifndef _INC_PUBLIB_UTILITY_MD5WRAPPER_H_
#define _INC_PUBLIB_UTILITY_MD5WRAPPER_H_

//basic includes
#include <string>

namespace JwUtility
{

	//forwards
	class MD5;

	class md5wrapper
	{
		public:
			//constructor
			md5wrapper();

			//destructor
			~md5wrapper();

			/*
			 * creates a MD5 hash from
			 * "text" and returns it as
			 * string
			 */	
			std::string getHashFromString(const std::string& text);

			/*
			 * creates a MD5 hash from
			 * a file specified in "filename" and 
			 * returns it as string
			 */	
			std::string getHashFromFile(const std::string& filename);
#ifdef WIN32
			std::string getHashFromFile(const std::wstring& filename);
#endif
		private:
			MD5 *md5;

			/*
			 * internal hash function, calling
			 * the basic methods from md5.h
			 */	
			std::string hashit(const std::string& text);

			/*
			 * converts the numeric giets to
			 * a valid std::string
			 */
			std::string convToString(unsigned char *bytes);

	};

} //end utility


//include protection
#endif // !_INC_PUBLIB_UTILITY_MD5WRAPPER_H_

/*
 * EOF
 */

