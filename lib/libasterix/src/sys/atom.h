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

#include "diagnostic.h"




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

			template<typename _Value_Type, typename _Key_Type>
			struct basic_dynamic_pair
			{
			protected:
				_Key_Type *		_key;
				_Value_Type*	_value;
			public:

				basic_dynamic_pair() noexcept
				{
					_key = new _Key_Type();
					_value = new _Value_Type();

				}
					

				basic_dynamic_pair(const _Value_Type& value, const _Key_Type& key) noexcept
				{
					_key = new _Key_Type(key);
					_value = new _Value_Type(value);
					
				}
				
				~basic_dynamic_pair()
				{
#ifdef _DEBUG
					std::cout << "basic_dynamic_pair " << "is deleted!" << std::endl;
#endif // _DEBUG
					delete _key;
					delete _value;
				}
				
				
				/*void set(const _Value_Type& value, const _Key_Type& key) noexcept;
				
				basic_dynamic_pair& get() noexcept;
				
				_Key_Type& get_key() noexcept;
				
				_Value_Type& get_value() noexcept;


				basic_dynamic_pair& operator =(const basic_dynamic_pair& other) noexcept;

				bool operator ==(const basic_dynamic_pair& left) const noexcept;

				bool operator !=(const basic_dynamic_pair& left) const noexcept;
*/
			};

			template<typename T, typename U, template<class, class> class pair = basic_dynamic_pair>
			struct dynamic_pair
			{
				typedef pair<T, U> dynamic_pair_t;
				std::pair<int, int> p;
			private:
				dynamic_pair_t* _pair_data;
			public:
				dynamic_pair() noexcept
				{
					_pair_data = new dynamic_pair_t();
#ifdef _DEBUG
					std::cout << "dynamic_pair " << "is work!" << std::endl;
#endif // _DEBUG
				}

				dynamic_pair(const T & val, const U& key) noexcept
				{
					_pair_data = new dynamic_pair_t(val, key);
				}
				~dynamic_pair()
				{
					//DEBUG_MESSAGE("aaa", asx::sys::diagnostic::asx_diagnostic_function_type::dtor);
#ifdef _DEBUG
					std::cout << "dynamic_pair " << "is deleted!" << std::endl;
#endif // _DEBUG
				}
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






template<typename T, typename U>
struct A
{
	T x;
	U z;
};

template<typename T, typename U, template<class, class> class C = A>
struct B
{
	C<T, U> y;
};


 

 