// winasterix.cpp: определяет точку входа для консольного приложения.
//

#include "..\..\lib\libasterix\src\libasterix.h"
#include <iostream>

using namespace std;
using namespace asterix::sys::types;

int main()
{
	asx_point2d d2;
	d2.X = 25.0;
	d2.Y = 46.0;
	cout << d2.to_str("s%s%s") << endl;
    return 0;
}

