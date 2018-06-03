#include <iostream>
#include <cstdlib>
#include <string>
#include "../libs/libasterix/src/libasterix.h"
#include "sys/basic.h"
#ifdef _WIN32
#pragma comment(lib, "asterix0.lib") 
#else
#pragma comment(lib, "libasterix0.lib") 
#endif // _WIN32

#pragma comment(lib, "asterix0.lib") 

using namespace std;
using namespace asterix::sys::types;
//using namespace asterix::sys::util;
int main()
{
	asterix::sys::types::basic_point_2<float> aaa2;
	asterix::sys::types::basic_point_3<double> aaa3;

	double rad = TO_RAD(56.5);
	double grad = TO_GRAD(0.9);
	asx_sexigesimal_arcdata_t t;
	sexagesimal_tag* ff = new sexagesimal_tag();
	ff->set_radian(0.9987);
	ff->set_grad(98.6);
	double aaa1 = ff->get_grad_value();
	//asx_sexagesimal_util::asx_util_set_sexadesimal(10.00, &ff);
	//asx_sexagesimal_format_tag sgft;
	//wcscpy(sgft.deg_hrs, L"020111222");
	sexagesimal_frmt fffff;
	fffff.init();
	fffff.reset_format();
	auto d = fffff.parse(wstring(L"asssddffffffffff"));
	//cout << fffff.parse("").c_str();
	//cout << sizeof() <<endl;
	//cout << sizeof() <<endl;
	cout << "Hello CMake." << aaa1 << endl;
	wcout << d << endl;
#ifdef _WIN32
	system("pause");
#endif
	return 0;
}