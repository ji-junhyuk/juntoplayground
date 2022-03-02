#include "../ch01/stdafx.h"
#include <iostream>

using namespace std;

class CMyPoint
{
	public:
		CMyPoint(int x)
		{
			cout << "CMyPoint(int)" << '\n';
			if (x > 100)
				x = 100;
			m_i_x = 100;
		}
		CMyPoint(int x, int y)
			:CMyPoint(x)
		{
			cout << "CMyPoint(int, int)" << '\n';
			if (y > 200)
				y = 200;
			m_i_y = 200;
		}
		void print()
		{
			cout << "x: " << m_i_x << '\n';
			cout << "y: " << m_i_y << '\n';
		}
	private:
		int m_i_x = 0;
		int m_i_y = 0;
};

int _tmain(int argc, _TCHAR *argv[])
{
	CMyPoint pt_begin(110);
	pt_begin.print();

	CMyPoint pt_end(50, 250);
	pt_end.print();
	return (0);
}
