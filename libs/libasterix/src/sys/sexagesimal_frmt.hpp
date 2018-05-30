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
				// Format keys
				//
				const char*		KEY_UPPER_CASE = "%u+";				// ключ включения заглавных символов
				const char*		KEY_DOWN_CASE = "%u-";				// ключ выключения заглавных символов
				const char*		KEY_SYMBOL = "%s";					// ключ включения символов (°,′,″)
				const char*		KEY_SHORT_NAME = "%n";				// ключ буквенного обозначения (h(d), m, s)
				const char*		KEY_MIDDLE_NAME = "%nn";			// ключ короткого слова в обозначениях (hrs(deg), min, sec)
				const char*		KEY_LONG_NAME = "%nnn";				// ключ длинного слова в обозначениях (hour(degree), minute, second)
				const char*		KEY_FULL_NAME = "%NNN";				// не документировано
				const char*		KEY_POS_SGN_ON = "%+";				// ключ включения отображения знака положительного значения
				const char*		KEY_POS_SGN_OFF = "%p-";			// ключ выключения отображения знака положительного значения
				const char*		KEY_SGN_OFF = "%s-";				// ключ выключения отображения знака 
				const char*		KEY_SEP_PREC = "%s=";				// ключ длинны отображения десятичной части секунд
				const char*		KEY_NULL_PLACEHOLDER_ON = "%N+";	// ключ включения отображения нулей
				const char*		KEY_NULL_PLACEHOLDER_OFF = "%N+";	// ключ выключения отображения нулей
				const char*		KEY_SPACE_DELIM_ON = "%D+";			// ключ включения отображения знака разделителя
				const char*		KEY_SPACE_DELIM_OFF = "%D+";		// ключ выключения отображения знака разделителя

				//
				// Format tags
				//
				bool			TAG_CASE;							// тег включения заглавных символов
				bool			TAG_SYMBOL;							// тег включения символов (°,′,″)
				int				TAG_NAME;							// тег буквенного обозначения (h(d), m, s), короткого слова в обозначениях (hrs(deg), min, sec), длинного слова в обозначениях (hour(degree), minute, second)
				bool			TAG_POS_SGN;						// тег включения отображения знака положительного значения
				bool			TAG_SGN;							// тег выключения отображения знака 
				int				TAG_SEP_PREC;						// тег длинны отображения десятичной части секунд
				bool			TAG_NULL_PLACEHOLDER;				// тег включения отображения нулей
				bool			TAG_SPACE_DELIM;					// тег включения отображения знака разделителя
		
				//
				// Дефолтная маска
				//
				const std::string default_mask = "s_S_0000h_00m_00,000000s_S"; // sec prec 6
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

				void __cdecl set_format(const std::string& mask, const std::string& flags, ...) noexcept;

				std::string __cdecl parse(const std::string& _in_str_) noexcept;
				
				void __cdecl add_custom_mask(const std::string& mask) noexcept;

				void __cdecl reset_format() noexcept;

			};
		}
	}
}