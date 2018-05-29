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
#include <xstring>
#include <cstdlib>

namespace asterix 
{
	namespace sys
	{
		namespace types
		{
			/*
			Формат ввода-вывода шестидесятеричного представления угловых величин
			*/
			class sexagesimal_frmt
			{
				//
				// Constants
				// 
				// symbols of formating sexagesimal output and input
				//
				const char*		SYM_POS_SGN = "+";					// сивлол положительных значений
				const char*		SYM_NEG_SNG = "-";					// символ отрицательных значений
				const char*		SYM_H = "hHhourshrsHRS";			// символы часов
				const char*		SYM_D = "dDdegDEGDegree°";			// символы градусов
				const char*		SYM_M = "mMminminute′";				// символы минут
				const char*		SYM_S = "sSsecsecond″";				// символы секунд
				const char*		SYM_NORD = "nNord";					// сивлолы положительных значений (север)
				const char*		SYM_SOUTH = "sSouth";				// символы отрицательных значений (юг)
				const char*		SYM_EAST = "eEast";					// сивлолы положительных значений (восток)
				const char*		SYM_WEST = "wWest";					// сивлолы отрицательных значений (запад)
				const char*		SYM_DELIM = " :";					// символы разделителя

				//
				// Format flags
				//
				const char*		FLAG_UPPER_CASE = "%u+";			// флаг включения заглавных символов
				const char*		FLAG_DOWN_CASE = "%u-";				// флаг выключения заглавных символов
				const char*		FLAG_SYMBOL = "%s";					// флаг включения символов (°,′,″)
				const char*		FLAG_SHORT_NAME = "%n";				// флаг буквенного обозначения (h(d), m, s)
				const char*		FLAG_MIDDLE_NAME = "%nn";			// флаг короткого слова в обозначениях (hrs(deg), min, sec)
				const char*		FLAG_LONG_NAME = "%nnn";			// флаг короткого слова в обозначениях (hour(degree), minute, second)
				const char*		FLAG_FULL_NAME = "%NNN";			// не документировано
				const char*		FLAG_POS_SGN_ON = "%+";				// флаг включения отображения знака положительного значения
				const char*		FLAG_POS_SGN_OFF = "%p-";			// флаг выключения отображения знака положительного значения
				const char*		FLAG_SGN_OFF = "%s-";				// флаг выключения отображения знака 
				const char*		FLAF_SEP_PREC = "%s=";				// флаг длинны отображения десятичной части секунд
				const char*		FLAG_NULL_PLACEHOLDER_ON = "%N+";	// флаг включения отображения нулей
				const char*		FLAG_NULL_PLACEHOLDER_OFF = "%N+";	// флаг выключения отображения нулей
				const char*		FLAG_SPACE_DELIM_ON = "%D+";		// флаг включения отображения знака разделителя
				const char*		FLAG_SPACE_DELIM_OFF = "%D+";		// флаг выключения отображения знака разделителя

				//
				// Дефолтная маска
				//
				const std::string default_mask; //TODO: n impl
				//
				// Переменные
				//
				std::string		_m_input_format;					// входной формат
				std::string		_m_output_format;					// выходной формат
				std::string		_m_format_mask;						// маска формата


			public:

				sexagesimal_frmt() noexcept {}
				//
				// Методы
				//		
				void __cdecl set_format(const char* mask, const char* flags, ...) noexcept;

				std::string __cdecl parse(const std::string& _in_str_) noexcept;
				
				void __cdecl add_custom_mask(const std::string& mask) noexcept;
			};
		}
	}
}