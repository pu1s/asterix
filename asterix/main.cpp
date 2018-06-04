#include <iostream>
#include <cstdlib>
#include <string>
#include "../libs/libasterix/src/libasterix.h"
#include "../libs/libasterix/src/sys/basic.h"
#ifdef _WIN32
#pragma comment(lib, "libasterix.lib") 
#else
#pragma comment(lib, "libasterix_st.lib") 
#endif // _WIN32

//#pragma comment(lib, "asterix0.lib") 

using namespace std;
using namespace asterix::sys::types;
//using namespace asterix::sys::util;
int main()
{
	asterix::sys::types::asx_point2f aaa2;
	asterix::sys::types::basic_point_3<double> aaa3;
	
	
	
	cout << "Hello CMake." << aaa3 << endl;
	
#ifdef _WIN32
	system("pause");
#endif
	return 0;
}