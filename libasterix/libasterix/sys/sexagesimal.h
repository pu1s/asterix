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


			typedef class global_settings
			{
				
			}asx_gs;
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


			typedef class sexagesimal_tag
			{
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
				inline void _asx_from_dgrad(
					const double& arcgrad,							// ссылка на значение в градусах дуги
					asx_sexigesimal_arcdata_t* data					// указатель на заполняемую структуру данных
				) noexcept
				{
					//
					// объявляем переменные
					//
					double	sgn;									//знак
					double	mod;									//модуль
					double	intpart;								//целая часть 
					double	frcpart;								//дробная часть
					//
					// присваиваем значение элементу структуры
					//
					data->arcgrad = arcgrad;
					//
					// вычисляем значение в радианах
					//
					//data->arcrad = TO_RAD(arcgrad);
					data->arcrad = (arcgrad*PI) / 180;
					//
					// вычисляем знак
					//
					sgn = arcgrad > 0 ? 1.0 : -1.0;
					//
					// вычисляем модуль
					//
					mod = abs(data->arcgrad);
					//
					// разделяем число на целую и дробную части
					frcpart = modf(mod, &intpart);
					//
					// вычисляем значение угла и времени
					//
					data->deg_hrs.arcdeg = (int)(intpart * sgn);
					data->deg_hrs.archrs = (int)(intpart / 15) * sgn;
					//
					// вычисляем значение минут
					//
					data->arcmin = (int)(frcpart * 60);
					//
					// обновляем значение дробной части
					//
					//frcpart = (frcpart * 60) - data->arcmin;
					frcpart = (frcpart * 60) - (int)(frcpart * 60); //fixed 26/05/2018
																	//
																	// вычисляем значение секунд
																	//
					data->arcsec = frcpart * 60;
					//
					// устанавливаем флаг вычисления в истину
					//
					_m_is_calculated = true;
				}
				
				/*
				Пересчет из натурального числа в угловые величины
				*/
				inline void _asx_from_drad(
					const double& arcrad,							// ссылка на значение в радианах дуги
					asx_sexigesimal_arcdata_t* data					// указатель на заполняемую структуру данных
				) noexcept
				{
					//
					// объявляем переменные
					//
					double	sgn;									//знак
					double	mod;									//модуль
					double	intpart;								//целая часть 
					double	frcpart;								//дробная часть
					//
					// присваиваем значение элементу структуры
					//
					data->arcrad = arcrad;
					//
					// вычисляем значение в радианах
					//
					//data->arcgrad = TO_GRAD(arcrad);
					//
					data->arcgrad = ((arcrad * 180) / PI);
					//
					// вычисляем знак
					//
					sgn = arcrad > 0 ? 1.0 : -1.0;
					//
					// вычисляем модуль
					//
					mod = abs(data->arcgrad);
					//
					// разделяем число на целую и дробную части
					frcpart = modf(mod, &intpart);
					//
					// вычисляем значение угла и времени
					//
					data->deg_hrs.arcdeg = (int)(intpart * sgn);
					data->deg_hrs.archrs = (int)(intpart / 15) * sgn;
					//
					// вычисляем значение минут
					//
					data->arcmin = (int)(frcpart * 60);
					//
					// обновляем значение дробной части
					//
					//frcpart = (frcpart * 60) - data->arcmin;
					frcpart = (frcpart * 60) - (int)(frcpart * 60); // fixed 26/05/2018
																	//
																	// вычисляем значение секунд
																	//
					data->arcsec = frcpart * 60;
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
					if (_m_arcdata.arcrad != std::nan("a1"))
					{
						return _m_arcdata.arcrad;
					}
					else
					{
						return ASX_SEXAGESIMAL_NO_RESULT;
					}
				}

				std::string ToString() noexcept
				{
					// TODO: n impl
				}
				std::string ToString(const asx_sexagesimal_format_tag& frmt) noexcept
				{
					// TODO: n impl
				}
				friend std::ostream& operator<<(std::ostream& os, sexagesimal_tag& sg) noexcept
				{
					// TODO: n impl
					return os;
				}
				sexagesimal_tag& SetGrad(const double& arcgrad) noexcept
				{
					_asx_from_dgrad(arcgrad, &_m_arcdata);
					return *this;
				}


				sexagesimal_tag& SetRad(const double& arcrad) noexcept
				{
					_asx_from_drad(arcrad, &_m_arcdata);
					return *this;
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





