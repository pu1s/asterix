// winasterix.cpp: определяет точку входа для консольного приложения.
//

#include "..\..\lib\libasterix\src\libasterix.h"
#include "asx_footer.h"
#include <iostream>
#include <cstdlib>
#include <iterator>

using namespace std;
using namespace asx::sys::types;




int main()
{
	asx::formatter_flag s;
	s = asx::formatter_flag::FRMT_PARAM_SHOWFIL;
	asx_footer::asx_footer_print();
	point<int> i;
	point_atomic<float> aa(0.88f);
	aa.Clear();
	aa = 0.7f;
#ifdef _WIN32
	system("pause");
#endif // WIN32

    return 0;
}




