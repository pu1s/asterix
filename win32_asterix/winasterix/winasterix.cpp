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
	point2f p2(12.0f, 45.6f);
	cout << p2.to_str() <<endl;
	dynamic_pair<int, string> dp(10, "ddd");
	
	 //B<int, int> b{ {10, 11} };
#ifdef _WIN32
	system("pause");
#endif // WIN32

    return 0;
}




