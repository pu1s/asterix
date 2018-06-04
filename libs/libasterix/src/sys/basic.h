/*
MIT License

Copyright (c) 2018 Alexander Gorin pu1s@outlook.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#pragma once

//#if defined(_MSC_VER)
////  Microsoft 
//#define ASX_EXPORT __declspec(dllexport)
//#define ASX_IMPORT __declspec(dllimport)
//#elif defined(__GNUC__)
////  GCC
//#if (__GNUC__ >= 4)
//#define ASX_EXPORT __attribute__((visibility("default")))
//#define ASX_IMPORT
//#else
//#define ASX_EXPORT extern "C"
//#define ASX_IMPORT
//#endif
//#else
////  do nothing and hope for the best?
//#define ASX_EXPORT
//#define ASX_IMPORT
//#pragma warning Unknown dynamic link import/export semantics.
//#endif

#include <sys/basic>
#include <stdio.h>
#include <iostream>

namespace asterix
{
	namespace sys
	{
		namespace types
		{
			class sys_utility
			{
			public:
				
			};
			template<typename T>
			struct basic_point
			{
				
			};

			template<typename T>
			struct basic_point_3 : public basic_point<T>, public sys_utility
			{
				T X;
				T Y;
				T Z;
				basic_point_3<T>()
				{
					X = T();
					Y = T();
					Z = T();
				}
				friend std::ostream& CDECL operator <<(std::ostream& os, basic_point_3<T>& bp) noexcept
				{
					os << "X=" << std::to_string(bp.X) << std::endl;
					os << "Y=" << std::to_string(bp.Y) << std::endl;
					os << "Z=" << std::to_string(bp.Z) << std::endl;		
					return os;
				}
			};

			template<typename T>
			struct basic_point_2 : public basic_point<T>
			{
				T X;
				T Y;
				basic_point_2<T>()
				{
					X = T();
					Y = T();
				}
			};
			
			typedef basic_point_2<float>	asx_point2f;
			typedef basic_point_2<double>	asx_point2d;
			typedef basic_point_3<float>	asx_point3f;
			typedef basic_point_3<double>	asx_point3d;
		}
	}
}