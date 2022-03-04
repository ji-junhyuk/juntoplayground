#include "../ch01/stdafx.h"

class CMyImage
{
	public:
		CMyImage(int i_height, int i_width)
			: m_i_height(i_height), m_i_width(i_width)
		{
			cout << "CMyImage(int, int)" << '\n';
		}
		int get_height() const { return m_i_height; }
		int get_width() const { return m_i_width; }
		int get_size() const { return 0; }
	protected:
		int m_i_height;
		int m_i_width;
};

class CMyShape
{
	public:
		CMyShape(int i_type) : m_i_type(i_type)
	{
		cout << "CMyShape(int)" << '\n';
	}
		int get_type() const { return m_i_type; }
		int get_size() const { return 0; }
	protected:
		int m_i_type;
};

class CMyPicture : public CMyImage, public CMyShape
{
	public:
		CMyPicture() : CMyImage(200, 120), CMyShape(1)
	{
		cout << "CMyPicture()" << '\n';
	}
};

int _tmain(int argc, _TCHAR *argv[])
{
	CMyPicture a;
	cout << a.get_width() << '\n';
	cout << a.get_height() << '\n';
	cout << a.get_type() << '\n';
//	cout << a.get_size() << '\n';
	cout << a.CMyImage::get_size() << '\n';
	return 0;
}
