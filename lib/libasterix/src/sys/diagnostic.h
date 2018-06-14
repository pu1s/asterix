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

#include "global.h"
enum class asx_function_type
{
	function,
	ctor,
	dtor,
};

inline void asx_debug_message(
	const char* custom_message, 
	const asx_function_type& func_type = asx_function_type::function
) noexcept
{
	std::cout << __DATE__ << " " << __TIME__ << " " << __FILE__ << " " << __LINE__ << " " <<  __FUNCTION__ << " ";
	switch (func_type)
	{
	case asx_function_type::ctor:
	{
		std::cout << "is Constructor... ";
		break;
	}
	case asx_function_type::dtor:
		std::cout << "is Destructor... ";
		break;
	default:
		std::cout << "is Function... ";
		break;
	}
	if (custom_message == nullptr) return;
	std::cout << custom_message << " ";
}

#define DEBUG_MESSAGE(message, type_func)\
{\
	asx_debug_message((message), (type_func)); \
}