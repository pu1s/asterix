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

#include <string>
#include <iostream>
#include <algorithm>

namespace asx
{
	namespace sys
	{
		namespace diagnostic
		{
			enum class asx_diagnostic_function_type
			{
				ctor,
				dtor,
				function,
			};
			void __cdecl asx_global_diagnostic_message(
				const char* custom_message,
				const int func_type = 0
			) noexcept
			{
				auto __FOOTER__ = [](void) -> void
				{
					std::cout << __TIME__ << " " __FILE__ << " " << __LINE__ << " " << __FUNCTION__;
				};
				switch (func_type)
				{
				case 0:
				{
					__FOOTER__();
					std::cout << "Constructor: " <<  "is work!" << std::endl;
				}
				break;
				case 1:
				{
					__FOOTER__();
					std::cout << "Destructor: " << "is work!" << std::endl;
					break;
				}
				default:
				{
					__FOOTER__();
					std::cout << "Function: " << "is work!" << std::endl;
					break;
				}
				}
			}
		}
	}
}