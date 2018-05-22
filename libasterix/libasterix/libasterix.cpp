// libasterix.cpp: определяет точку входа для приложения.
//

#include "libasterix.h"


using namespace std;

int main()
{
	hms_t _hms;
	DMS _dms;
	_dms.deg = 10;
	_dms.min = 30;
	make_hms(10, 20, 20.5, &_hms);
	cout << _hms.hrs << endl;
	print_hms(NULL); // TODO: ограничить
	print_dms(&_dms);
	asx_basic_sexagesimal_t<float>* f = new asx_basic_sexagesimal_t<float>();
	float ff = f->asx_get_value();
	HMS hms = f->asx_get_content1();
	sexagesimal *sg = new sexagesimal();
	cout << "Hello CMake." << endl;
	return 0;
}
