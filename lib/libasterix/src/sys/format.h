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
#include <vector>
#include <cassert>

#define CUCHR const unsigned char


namespace asx
{
	typedef
	enum formatter_parameters_tag : int
	{
		FRMT_PARAM_SHOWPOS	= 0x0001,
		FRMT_PARAM_SHOWFIL	= 0x0002,
		FRMT_PARAM_DEFAULT	= 0x0004,
	}FRMT_PARAM;

	typedef
	struct formatter
	{
	private: 
		unsigned int*	m_format_precision;
		unsigned int*	m_format_parameters;
	public:
		formatter() noexcept : m_format_parameters(new unsigned int()), m_format_precision(new unsigned int()) {}
		explicit formatter(unsigned int params, const unsigned int& precision) noexcept : formatter()
		{
			m_format_parameters = (unsigned int*)&params;
			m_format_precision = (unsigned int*)&precision;
		}

	}FORMATTER, *formatter_ptr;
}