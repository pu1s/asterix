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
#include <map>
#include <cstdlib>
#include <thread> 
#include "basic.h"



namespace asterix
{
	namespace sys
	{
		namespace types
		{
			typedef enum class sexagesimal_frmt_state
			{
				DEFAULT,
				CUSTOM
			}asx_sexagesimal_frmt_state_t;
			/*
			Формат ввода-вывода шестидесятеричного представления угловых величин
			*/
			typedef class sexagesimal_frmt
			{
				//
				// Constants
				// 
				// symbols of formating sexagesimal output and input
				//
				ASX_WSTRP SYM_POS_SGN = L"+";					// сивлол положительных значений
				ASX_WSTRP SYM_NEG_SNG = L"-";					// символ отрицательных значений
				ASX_WSTRP SYM_H = L"hHhourshrsHRS";				// символы часов
				ASX_WSTRP SYM_D = L"dDdegDEGDegree°";			// символы градусов
				ASX_WSTRP SYM_M = L"mMminminute′";				// символы минут
				ASX_WSTRP SYM_S = L"sSsecsecond″";				// символы секунд
				ASX_WSTRP SYM_NORD = L"nNord";					// сивлолы положительных значений (север)
				ASX_WSTRP SYM_SOUTH = L"sSouth";				// символы отрицательных значений (юг)
				ASX_WSTRP SYM_EAST = L"eEast";					// сивлолы положительных значений (восток)
				ASX_WSTRP SYM_WEST = L"wWest";					// сивлолы отрицательных значений (запад)
				ASX_WSTRP SYM_DELIM = L" :";					// символы разделителя

				//
				// Format keys
				//
				ASX_WSTRP	KEY_UPPER_CASE = L"%u+";			// ключ включения заглавных символов
				ASX_WSTRP	KEY_DOWN_CASE = L"%u-";				// ключ выключения заглавных символов
				ASX_WSTRP	KEY_SYMBOL = L"%s";					// ключ включения символов (°,′,″)
				ASX_WSTRP	KEY_SHORT_NAME = L"%n";				// ключ буквенного обозначения (h(d), m, s)
				ASX_WSTRP	KEY_MIDDLE_NAME = L"%nn";			// ключ короткого слова в обозначениях (hrs(deg), min, sec)
				ASX_WSTRP	KEY_LONG_NAME = L"%nnn";			// ключ длинного слова в обозначениях (hour(degree), minute, second)
				ASX_WSTRP	KEY_FULL_NAME = L"%NNN";			// не документировано
				ASX_WSTRP	KEY_POS_SGN_ON = L"%+";				// ключ включения отображения знака положительного значения
				ASX_WSTRP	KEY_POS_SGN_OFF = L"%p-";			// ключ выключения отображения знака положительного значения
				ASX_WSTRP	KEY_SGN_OFF = L"%s-";				// ключ выключения отображения знака 
				ASX_WSTRP	KEY_SEP_PREC = L"%s=";				// ключ длинны отображения десятичной части секунд
				ASX_WSTRP	KEY_NULL_PLACEHOLDER_ON = L"%N+";	// ключ включения отображения нулей
				ASX_WSTRP	KEY_NULL_PLACEHOLDER_OFF = L"%N+";	// ключ выключения отображения нулей
				ASX_WSTRP	KEY_SPACE_DELIM_ON = L"%D+";		// ключ включения отображения знака разделителя
				ASX_WSTRP	KEY_SPACE_DELIM_OFF = L"%D+";		// ключ выключения отображения знака разделителя

				//
				// Format tags
				//
				ASX_BOOL	TAG_CASE;							// тег включения заглавных символов
				ASX_BOOL	TAG_SYMBOL;							// тег включения символов (°,′,″)
				ASX_UINT	TAG_NAME;							// тег буквенного обозначения (h(d), m, s), короткого слова в обозначениях (hrs(deg), min, sec), длинного слова в обозначениях (hour(degree), minute, second)
				ASX_BOOL	TAG_POS_SGN;						// тег включения отображения знака положительного значения
				ASX_BOOL	TAG_SGN;							// тег выключения отображения знака 
				ASX_UINT	TAG_SEP_PREC;						// тег длинны отображения десятичной части секунд
				ASX_BOOL	TAG_NULL_PLACEHOLDER;				// тег включения отображения нулей
				ASX_BOOL	TAG_SPACE_DELIM;					// тег включения отображения знака разделителя

				//
				// Дефолтная маска
				//
				const std::wstring default_mask = L"s_S_0000h_00m_00,0000000000s_S"; 
				//
				// Переменные
				//
				std::string						_m_format_input;					// входной формат
				std::string						_m_format_output;					// выходной формат
				std::wstring					_m_format_mask;						// маска формата
				asx_sexagesimal_frmt_state_t	_m_format_state;

			public:
				//
				// Ctor
				//
				CDECL sexagesimal_frmt() noexcept;
				//
				// Dtor
				~sexagesimal_frmt();
				//
				// Методы
				//	
				sexagesimal_frmt& CDECL init() noexcept;

			private:
				//
				// 
				//
				inline void CDECL _initialize() noexcept;
			public:

				void CDECL set_format(const char* flags, ...) noexcept;

				void CDECL set_format(const std::string& flags, ...) noexcept;

				std::wstring& CDECL parse(std::wstring& _in_str_) const noexcept;

				void CDECL add_custom_mask(const std::string& custom_mask) noexcept;

				void CDECL reset_format() noexcept;

			}asx_sexagesimal_frmt_t;
		}
	}
}