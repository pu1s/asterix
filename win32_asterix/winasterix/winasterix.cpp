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

	//basic_point_prototype pp1;
	//cout << pp1.to_str(1);
	std::string strdd("ats");
	//dynamic_pair_d pair;
	//pair.set("sts", 20);
	cout << endl;
 	basic_dynamic_pair<std::string, double> f1, f2;
	f1.set("123", 123.4);
	f2 = f1;
	//dyn_pair fff;
	/*auto dd = fff.getd();
	auto df = fff.getf();
	cout << dd->get_value() << endl;
	cout << df->get_value() << endl;*/
#ifdef _WIN32
	system("pause");
#endif // WIN32

    return 0;
}




