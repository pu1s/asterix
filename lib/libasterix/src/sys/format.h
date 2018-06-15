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

#define FRMT_VAL_LIMIT	const unsigned
#define FRMT_KEY_FLAGS	const char*
#define FRMT_FLAG_EMPTY	"";
namespace asx
{
	struct formatter
	{
	private:
		FRMT_VAL_LIMIT DEF_PREC_MIN				= 0;
		FRMT_VAL_LIMIT DEF_PREC_MAX				= 10;
		FRMT_VAL_LIMIT DEF_PREC_VAL				= 5;
		FRMT_KEY_FLAGS KEY_SHOW_POS				= "%s";
		FRMT_KEY_FLAGS KEY_SHOW_FILL			= "%f";
		FRMT_KEY_FLAGS KEY_SHOW_PREC			= "%p=";
		typedef std::vector<const char*>* key_list;

	private:
		const char* _frmt;
		key_list _key_list;

	public:
		
		formatter() noexcept : _frmt(""), _key_list(new std::vector<const char*>())
		{
			
		}
	};
}