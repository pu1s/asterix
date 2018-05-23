// libasterix.cpp: определяет точку входа для приложения.
//

#include "libasterix.h"
#include <vector>

using namespace std;
using namespace asterix::sys::types;

int main()
{
	hms_t _hms;
	DMS _dms;
	sexagesimal ssg;
	_hms = ssg.asx_get_hms();
	bool c = ssg.asx_is_calculated();
	_dms = ssg.asx_get_dms();
	
	make_hms(10, 20, 20.5, &_hms);
	cout << _hms.hrs << endl;
	print_hms(NULL); // TODO: ограничить
	dms_out(&_dms);
	asx_basic_sexagesimal_t<float>* f = new asx_basic_sexagesimal_t<float>();
	/*float ff = f->asx_get_value();
	HMS hms = f->asx_get_content1();*/
	sexagesimal *sg = new sexagesimal();
	cout << "Hello CMake." << endl;
	return 0;
}
