// winasterix.cpp: определяет точку входа для консольного приложения.
//

#include "..\..\lib\libasterix\src\libasterix.h"
#include <iostream>
#include <cstdlib>

using namespace std;
using namespace asterix::sys::types;


void print_footer();

int main()
{
	print_footer();

	asx_point2<float> p2;
	
	cout << p2[0] << p2[1] << endl;
	cout << p2.to_str() << endl;
	/*asx_point2d d2;
	d2.X = 25.0;
	d2.Y = 46.0;
	cout << d2.to_str("s%s%s") << endl;*/
#ifdef _WIN32
	system("pause");
#endif // WIN32

    return 0;
}

void print_footer()
{
	cout << "++++++++++++++++++++++++++++++++++++" << endl;
	cout << "| This ASTERIX Console Application |" << endl;
	cout << "++++++++++++++++++++++++++++++++++++" << endl;
}

