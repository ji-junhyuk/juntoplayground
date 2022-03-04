#include "../ch01/stdafx.h"

class CMyObject
{
	public:
		CMyObject() { cout << "CMyObject()" << '\n'; }
		virtual ~CMyObject() { }
};

class CMyImage : virtual public CMyObject
{
	public:
		CMyImage() { cout << "CMyImage(int, int)" << '\n'; }
};

class CMyShape : virtual public CMyObject
{
	public:
		CMyShape() { cout << "CMyShape(int)" << '\n'; }
};

class CMyPicture : public CMyImage, public CMyShape
{
	public:
		CMyPicture() { cout << "CMyPicture()" << '\n'; }
};
	
int _tmain(int argc, _TCHAR *argv[])
{
	CMyPicture a;
}
