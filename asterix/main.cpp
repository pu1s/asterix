#include <iostream>
#include <cstdlib>
#include "../libs/libasterix/src/libasterix.h"
#pragma comment(lib, "libasterix.lib") 

using namespace std;
using namespace asterix::sys::types;
//using namespace asterix::sys::util;
int main()
{
	double rad = TO_RAD(56.5);
	double grad = TO_GRAD(0.9);
	asx_sexigesimal_arcdata_t t;
	sexagesimal_tag* ff = new sexagesimal_tag();
	ff->SetRad(0.9987);
	ff->SetGrad(98.6);
	double aaa1 = ff->GradValue();
	//asx_sexagesimal_util::asx_util_set_sexadesimal(10.00, &ff);
	//asx_sexagesimal_format_tag sgft;
	//wcscpy(sgft.deg_hrs, L"020111222");
	//cout << sizeof(asx_sexagesimal_format_tag);
	cout << "Hello CMake." << aaa1 << endl;
#ifdef _WIN32
	system("pause");
#endif
	return 0;
}