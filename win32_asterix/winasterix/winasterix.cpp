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
	
	asx_footer::asx_footer_print();
	
	point<int> i;
	
	
	
	
	 
#ifdef _WIN32
	system("pause");
#endif // WIN32

    return 0;
}




