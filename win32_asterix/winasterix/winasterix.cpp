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
	basic_point2<float> p2(12.0f, 45.6f);
	cout << p2.to_str();
	
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

