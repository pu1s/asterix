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

//#include "diagnostic.h"




namespace asx
{
	namespace sys
	{
		namespace types
		{

			struct iPrintable
			{
			public:
				virtual std::string ToString() = 0;
			};

			
			template<typename T>
			struct point_atomic : public iPrintable
			{
			private:
				T* m_atomic;
			public:
				point_atomic() noexcept
				{
					m_atomic = new T();
				}
				point_atomic(const T& val) noexcept
				{
					m_atomic = new T(val);
				}
				point_atomic(T&& val) noexcept
				{
					m_atomic = new T();
					*m_atomic = val;
				}
				// Унаследовано через iPrintable
				virtual std::string ToString() override
				{
					return std::to_string(*m_atomic);
				}
				virtual ~point_atomic()
				{
					delete m_atomic;
				}
				virtual void operator=(const T& val) noexcept
				{
					*m_atomic = static_cast<T>(val);
				}
				virtual point_atomic& operator()(point_atomic& rv) noexcept
				{
					*m_atomic = rv.m_atomic;
					return (*this);
				}
				virtual T GetValue() noexcept
				{
					return *m_atomic;
				}
				virtual void Clear() const
				{
					*m_atomic = T();
				}
			};

			template<typename T>
			struct point
			{
				typedef point_atomic<T> PTUNIT;
			};
		}
	}
}


#include "atomic.template"
 