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

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>




namespace asx
{
	namespace sys
	{
		namespace types
		{

			struct basic_point_prototype
			{
			public:
				virtual std::string to_str() noexcept = 0;
				//virtual std::string to_str(const std::ios::fmtflags& fl) noexcept = 0;
			};

			template<typename _Tv, typename _Tk, typename _Value = _Tv, typename _Key = _Tk>
			struct basic_dynamic_pair
			{
			private:
				_Key*		_key;
				_Value*		_value;
			public:
				basic_dynamic_pair() noexcept;
				
				/*basic_dynamic_pair(const _Key& key, const _Value& value) noexcept;
				
				~basic_dynamic_pair();
				
				void set(const _Key& key, const _Value& value) noexcept;
				
				basic_dynamic_pair& get() noexcept;
				
				_Key& get_key() noexcept;
				
				_Value& get_value() noexcept;

				basic_dynamic_pair& operator =(const basic_dynamic_pair& other) noexcept;

				bool operator ==(const basic_dynamic_pair& left) const noexcept;

				bool operator !=(const basic_dynamic_pair& left) const noexcept;*/
			};

			template<template<typename T, typename U = std::string, typename _Key_Name = U, typename _Key_Value = T> class _Pair = basic_dynamic_pair>
			struct dynamic_pair
			{
				
			};

			struct basic_dynamic_point_prototype
			{
				virtual std::string to_str() noexcept = 0;
			};

			/*
			Basic representation on 2D point <STL variant>
			*/
			template<typename _Ty>
			struct basic_point2 : public basic_point_prototype
			{
				_Ty X; // X
				_Ty Y; // Y

				/*
				Ctor
				*/
				basic_point2()  noexcept
				{
					X = _Ty();
					Y = _Ty();
				}

				/*
				Ctor with params
				*/
				basic_point2(const _Ty& x, const _Ty& y) noexcept
				{
					X = x;
					Y = y;
				}

				/*
				To string
				*/
				std::string to_str() noexcept override
				{
					std::string x_str = std::to_string(X);
					std::string y_str = std::to_string(Y);
					std::string s("");
					s.append("X= ");
					s.append(x_str.c_str());
					s.append(" ");
					s.append("Y= ");
					s.append(y_str.c_str());
					s.append("\r\n");
					return s;
				}
			};

			/*
			Representation on 2D point with float value
			*/
			typedef  basic_point2<float> point2f;

			/*
			Representation on 2D point with double value
			*/
			typedef  basic_point2<double> point2d;

			/*
			Basic representation on 3D point <STL variant>
			*/
			template<typename _Ty>
			struct basic_point3 : public basic_point_prototype
			{
				_Ty X;
				_Ty Y;
				_Ty Z;

				/*
				Ctor
				*/
				basic_point3() noexcept
				{
					_Ty X = _Ty();
					_Ty Y = _Ty();
					_Ty Z = _Ty();
				}

				/*
				Ctor with params
				*/
				basic_point3(const _Ty& x, const _Ty& y, const _Ty z) noexcept
				{
					_Ty X = x;
					_Ty Y = y;
					_Ty Z = z;
				}

				/*
				To string
				*/
				std::string to_str() noexcept override
				{
					std::string x_str = std::to_string(X);
					std::string y_str = std::to_string(Y);
					std::string z_str = std::to_string(Z);
					std::string s("");
					s.append("X= ");
					s.append(x_str.c_str());
					s.append(" ");
					s.append("Y= ");
					s.append(y_str.c_str());
					s.append("Z= ");
					s.append(z_str.c_str());
					s.append("\r\n");
					return s;
				}
			};
		}
	}
}

#include "atom.template"



namespace asx
{
	typedef sys::types::basic_dynamic_pair<std::string, float>  __asx__api__ dynamic_pair_f;
	typedef sys::types::basic_dynamic_pair<std::string, double> __asx__api__ dynamic_pair_d;
	typedef sys::types::dynamic_pair<asx::sys::types::basic_dynamic_pair> __asx__api__ _dynamic_pair;
}
