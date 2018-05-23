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
#include <map>

using namespace asterix::sys::types;

template<typename _Char_Traits>
class asx_basic_format_t
{
};



template<typename _Value_Type, typename _Content_1_Type, typename _Content_2_Type>
class asx_basic_sexagesimal_content_t : asx_basic_content_t<_Value_Type, _Content_1_Type, _Content_2_Type>
{
protected:
	_Value_Type				_m_value;
	_Content_1_Type			_m_content_1;
	_Content_2_Type			_m_content_2;

	inline _Value_Type asx_get_value(void) noexcept
	{
		return _m_value;
	}
	inline void asx_set_value(const _Value_Type& _val) noexcept
	{
		_m_value = _val;
	}
	inline _Content_1_Type asx_get_content1(void) noexcept
	{
		return _m_content_1;
	}
	inline _Content_2_Type asx_get_content2(void) noexcept
	{
		return _m_content_2;
	}
};




template<typename _Value_Type>
class asx_basic_sexagesimal_t : public asx_basic_sexagesimal_content_t<_Value_Type, HMS, DMS>
{
	 bool _m_is_calculated = false;
public:
	asx_basic_sexagesimal_t() noexcept 
	{
		this->_m_value = _Value_Type();
		this->_m_content_1 = HMS();
		this->_m_content_2 = DMS();
		_m_is_calculated = false;
	}
	
	HMS asx_get_hms() noexcept 
	{
		return this->asx_get_content1();
	}
	DMS asx_get_dms() noexcept
	{
		return this->asx_get_content2();
	}
	const bool asx_is_calculated() const noexcept
	{
		return _m_is_calculated;
	}
};


using sexagesimal = asx_basic_sexagesimal_t<float>;

