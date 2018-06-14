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
//
// Define global constant & function
//
#define PI	3.14159265358979323846
#define TO_RAD(GRAD) ((double)((GRAD)*(PI))/180)
#define TO_GRAD(RAD) ((double)((RAD)*180)/(PI))

#ifndef API_EXPORT
#define API_EXPORT
//
// Exports
//
//
// Export function
// 
// Source: Explicitly exporting shared library functions in Linux
// https://stackoverflow.com/questions/2164827/explicitly-exporting-shared-library-functions-in-linux/2164962
//
#if defined(_MSC_VER) //  Microsoft 

#ifdef API_EXPORT
#define __asx__api__ __declspec(dllexport)
#else
#define __asx__api__ __declspec(dllimport)
#endif
#elif defined(__GNUC__) //  GCC

#if (__GNUC__ >= 4)
#ifdef API_EXPORT
#define __asx__api__ __attribute__((visibility("default")))
#else
#define __asx__api__
#endif 
#elseif(__GNUC__ < 4)
#ifdef API_EXPORT
#define __asx__api__ extern "C"
#else
#define __asx__api__
#endif
#endif
#else
	//  do nothing and hope for the best?
#define ASX_EXPORT
#define ASX_IMPORT
#pragma warning Unknown dynamic link import/export semantics.
#endif
#endif // !EXPORT



#define __export__ ASX_EXPORT
#define __import__ ASX_IMPORT
//
// cdecl definition
//
#if defined __GNUC__
#define __cdecl__ __attribute__((__cdecl__))
#else 
#define __cdecl__ __cdecl
#endif


#include <cstdio>
#include <iostream>


