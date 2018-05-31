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

#include "sexagesimal_frmt.hpp"

asterix::sys::types::sexagesimal_frmt & asterix::sys::types::sexagesimal_frmt::init() noexcept
{

	return(*this);
}
void asterix::sys::types::sexagesimal_frmt::reset_format() noexcept
{
	_m_format_mask = default_mask;
	_m_format_state = asx_sexagesimal_frmt_state_t::default;
}
std::wstring & asterix::sys::types::sexagesimal_frmt::parse(std::wstring & _in_str_) const noexcept
{
	std::wstring tmp(_in_str_);
	tmp.append(L"aaaappp");

	 _in_str_.clear();
	 _in_str_.assign(tmp);
	 return _in_str_;
}