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
			struct point_atom : public iPrintable
			{
			private:
				T* m_atom;
			public:
				// ������������ ����� iPrintable
				virtual std::string ToString() override
				{
					return std::to_string(*m_atom);
				}

			};

			template<typename T>
			struct point
			{
				point_atom<T> X;
			};
		}
	}
}


#include "atom.template"
 