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

#ifndef NDEBUG
#define NDEBUG
#include<cassert>
#endif // !NDEBUG
#include <string>
#include <cstdlib>
#include <cmath>

namespace asterix
{
	namespace sys
	{
		namespace types
		{
			typedef struct
			{
				wchar_t			sign[2];
				wchar_t			deg_hrs[4];
				wchar_t			deg_hrs_symbol[10];
				wchar_t			min[3];
				wchar_t			min_symbol[10];
				wchar_t			sec[14];
				wchar_t			sec_symbol[10];
				wchar_t			suff[2];
				bool			space_enabled;
				unsigned short	sec_precision;
				bool			null_placeholder;
			} asx_sexagesimal_format_tag;


			typedef struct asx_sexagesimal_data_tag
			{
				struct angle_and_time_tag
				{
					signed angle;
					signed time;
				}deg_hrs;
				unsigned			min;
				double				sec;
			}asx_sexigesimal_data_t;


			typedef class sexagesimal_tag
			{
				double					_m_value;
				asx_sexigesimal_data_t  _m_data;
				bool					_m_is_calculated;
			public:
				
				sexagesimal_tag()
				{
					this->_m_value = double();
					this->_m_data.deg_hrs.angle = signed();
					this->_m_data.deg_hrs.time = signed();
					this->_m_data.min = unsigned();
					this->_m_data.sec = double();
					this->_m_is_calculated = false;
				}

				sexagesimal_tag(const double& val) : sexagesimal_tag()
				{
					this->_m_value = double(val);
					this->_m_is_calculated = this->_calculate(_m_value, &_m_data);
				}
			private:
				inline void _double_to_hms_dms(const double& val, asx_sexigesimal_data_t* data)
				{
					// TODO: n impl
				}
				inline bool _calculate(const double& val, asx_sexigesimal_data_t* data) noexcept
				{
					assert(data != nullptr);
					// TODO: n impl
					return true;
				}
			public:
				double Value(void) noexcept
				{
					return _m_value;
				}
				friend std::ostream& operator<<(std::ostream& os, sexagesimal_tag& sg) noexcept
				{
					// TODO: n impl
					return os;
				}
				std::string ToString() noexcept
				{
					// TODO: n impl
				}
				std::string ToString(const asx_sexagesimal_format_tag& frmt) noexcept
				{
					// TODO: n impl
				}
			}sexagesimal_t;

		}
		namespace util
		{

		
		class asx_sexagesimal_util
		{
		public:
			static void asx_util_set_sexadesimal(const double& val, asterix::sys::types::sexagesimal_t* sg) noexcept
			{
				return;
			}
		};
		}
	}
}





