// winasterix.cpp: определяет точку входа для консольного приложения.
//

#include "..\..\lib\libasterix\src\libasterix.h"
#include "asx_footer.h"
#include <iostream>
#include <cstdlib>
#include <iterator>

using namespace std;
using namespace asterix::sys::types;




int main()
{
	asx_footer::asx_footer_print();
	basic_point2<float> p2(12.0f, 45.6f);
	cout << p2.to_str();
	basic_point_prototype pp1;
	cout << pp1.to_str(1);
	
#ifdef _WIN32
	system("pause");
#endif // WIN32

    return 0;
}




