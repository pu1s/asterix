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

#include "sexagesimal_common.h"
#include "sexagesimal_common.c"
#include "basic"

#ifndef NDEBUG
#define NDEBUG
#include<cassert>
#endif // !NDEBUG
#include <string>
#include <xstring>
#include <cstdlib>
#include <cmath>

#define ASX_GLOBAL_LIMIT_HRS_MIN		-9999
#define ASX_GLOBAL_LIMIT_HRS_MAX		9999
#define ASX_GLOBAL_LIMIT_DEG_MIN		-9999
#define ASX_GLOBAL_LIMIT_DEG_MAX		9999
#define ASX_GLOBAL_LIMIT_DAD_MIN		-9999
#define ASX_GLOBAL_LIMIT_RAD_MAX		9999
#define ASX_SEXAGESIMAL_NO_RESULT		0.0


#pragma warning (push)
#pragma warning(disable : 4244)


namespace asterix
{
	namespace sys
	{
		namespace types
		{
			
			class sexagesimal_format
			{
				
				std::string _input_format;
				std::string _output_format;
				
			};
			//template<typename _Char_Traits>
			//struct ASX_EXPORT sexagesimal_format_tag
			//{
			//	_Char_Traits			psn_symbol[01];			// Символы, обозначающие знак
			//	_Char_Traits			nsn_symbol[01];			// Символы, обозначающие знак
			//	_Char_Traits			prf_symbol[10];			// Символы, обозначающие знак
			//	_Char_Traits			deg_symbol[10];			// Символы, обзначающие градусы
			//	_Char_Traits			hrs_symbol[10];			// Символы, обзначающие часы
			//	_Char_Traits			min_symbol[10];			// Символы, обзначающие минуты
			//	_Char_Traits			sec_symbol[10];			// Символы, обзначающие секунды 
			//	_Char_Traits			suf_symbol[10];
			//	bool					space_enabled;
			//	unsigned short			sec_precision;
			//	bool					null_placeholder;
			//};

			//template<typename _Char_Traits>
			//void ASX_EXPORT __cdecl asx_init_format(
			//	_Char_Traits * sgn_,
			//	_Char_Traits * deg_hrs_symbol_,
			//	_Char_Traits * min_symbol_,
			//	_Char_Traits * sec_symbol_,
			//	_Char_Traits * suff_,
			//	const bool& space_enabled_,
			//	const unsigned short& sec_precision_,
			//	const bool& null_placeholder_,
			//	sexagesimal_format_tag* frmt
			//) noexcept
			//{

			//}
			
			typedef struct sexagesimal_arcdata_tag
			{
				struct angle_and_time_tag
				{
					signed						arcdeg;				// угол в градусах (знаковое целое)
					signed						archrs;				// угол во временных единицах (знаковое целое)
				}deg_hrs;
				unsigned						arcmin;				// минуты дуги (беззнаковое целое)
				double							arcsec;				// секунды дуги (вещественное)
				double							arcrad;				// угол в радианах (вещественное)
				double							arcgrad;			// угол в градусах (вещественное)
			}asx_sexigesimal_arcdata_t;


			typedef class ASX_EXPORT sexagesimal_tag
			{
				typedef
				enum class arcdata_type_t
				{
					grad = 0,
					rad = 1
				}asx_arcdata_type_t;

				asx_sexigesimal_arcdata_t		_m_arcdata;			// 
				bool							_m_is_calculated;	// флаг, полноты вычисления структуры
				
			public:

				sexagesimal_tag()
				{
					this->_m_arcdata.arcgrad		= double();
					this->_m_arcdata.arcrad			= double();
					this->_m_arcdata.deg_hrs.arcdeg = signed();
					this->_m_arcdata.deg_hrs.archrs = signed();
					this->_m_arcdata.arcmin			= unsigned();
					this->_m_arcdata.arcsec			= double();
					this->_m_is_calculated			= false;
				}
			private:
				/*
				Пересчет из натурального числа в угловые величины
				*/
				inline void _asx_swap_arcdata(
					const double& _in_val,
					const asx_arcdata_type_t _in_arcdata_type
				) noexcept
				{
					_m_is_calculated = false;
					//
					// объявляем переменные
					//
					double arcgrad, arcrad;
					double	sgn;									//знак
					double	mod;									//модуль
					double	intpart;								//целая часть 
					double	frcpart;								//дробная часть


					//
					switch (_in_arcdata_type)
					{
					case asx_arcdata_type_t::grad:
						arcgrad = _in_val;
						arcrad = TO_RAD(_in_val);
						break;
					default:
						arcgrad = TO_GRAD(_in_val);
						arcrad = _in_val;
						break;
					}
					//
					_m_arcdata.arcgrad = arcgrad;
					_m_arcdata.arcrad = arcrad;
					//
					// вычисляем значение в радианах
					//
					
					//
					// вычисляем знак
					//
					sgn = arcgrad > 0 ? 1.0 : -1.0;
					//
					// вычисляем модуль
					//
					mod = abs(arcgrad);
					//
					// разделяем число на целую и дробную части
					frcpart = modf(mod, &intpart);
					//
					// вычисляем значение угла и времени
					//
					_m_arcdata.deg_hrs.arcdeg = (int)(intpart * sgn);
					_m_arcdata.deg_hrs.archrs = (int)(intpart / 15) * sgn;
					//
					// вычисляем значение минут
					//
					_m_arcdata.arcmin = (int)(frcpart * 60);
					//
					// обновляем значение дробной части
					//
					//frcpart = (frcpart * 60) - data->arcmin;
					frcpart = (frcpart * 60) - (int)(frcpart * 60); /*fixed 27/05/2018*/
					//
					// вычисляем значение секунд
					//
					_m_arcdata.arcsec = frcpart * 60;
					//
					// устанавливаем флаг вычисления в истину
					//
					_m_is_calculated = true;
				}
				
				

			public:
				double GradValue(void) noexcept {
					if (_m_arcdata.arcgrad != std::nan("a1"))
					{
						return _m_arcdata.arcgrad;
					}
					else
					{
						return ASX_SEXAGESIMAL_NO_RESULT;
					}
				}

				double RadValue(void) noexcept
				{
					return ASX_SEXAGESIMAL_NO_RESULT;
				}

				std::string ToString() noexcept
				{
					return "";
					// TODO: n impl
				}
				//std::string ToString(const asx_sexagesimal_format_tag& frmt) noexcept
				//{
					// TODO: n impl
				//}
				//friend std::ostream& operator<<(std::ostream& os, sexagesimal_tag& sg) noexcept
				//{
					// TODO: n impl
				//	return os;
				//}
				void SetGrad(const double& arcgrad) noexcept
				{
					_asx_swap_arcdata(arcgrad, asx_arcdata_type_t::grad);
				}


				void SetRad(const double& arcrad) noexcept
				{
					_asx_swap_arcdata(arcrad, asx_arcdata_type_t::rad);
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
#pragma warning( pop ) 





