/*
MIT License

Copyright(c) 2018 pu1s

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#pragma once

#include "sexagesimal_common.h"
#include "sexagesimal_common.c"
#include "basic"

#include <string>

using namespace asterix::sys::types;

template<typename _Value_Trait, typename ... _Content_Traits>
class asx_basic_three_cont_t 
{
	const int variadic_count = sizeof...(_Content_Traits);
};

template<typename _Value_Type, typename _Content_1_Type, typename _Content_2_Type>
class asx_basic_cont_t : asx_basic_three_cont_t<_Value_Type, _Content_1_Type, _Content_2_Type>
{
private:
	_Value_Type			_value;
	_Content_1_Type		_content_1;
	_Content_2_Type		_content_2;
public:
	_Value_Type asx_get_value(void) noexcept
	{
		return _value;
	}
	void asx_set_value(const _Value_Type& _val) noexcept
	{
		_value = _val;
	}
	_Content_1_Type asx_get_content1(void) noexcept
	{
		return _content_1;
	}
	_Content_2_Type asx_get_content2(void) noexcept
	{
		return _content_2;
	}
};

template<typename _Symbol>
class asx_basic_format_t
{
};


template<typename _Value_Type>
class asx_basic_sexagesimal_t : public asx_basic_cont_t<_Value_Type, HMS, DMS>
{

};

using sexagesimal = asx_basic_sexagesimal_t<float>;

