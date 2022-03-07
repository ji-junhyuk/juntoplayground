#include "../ch01/stdafx.h"

template<typename T, int i_size>
class CMyArray
{
	public:
		CMyArray() { m_p_data = new T[i_size]; }
		~CMyArray() { delete[] m_p_data; }
		T& operator[](int i_index)
		{
			if (i_index < 0 || i_index >= i_size)
			{
				cout << "ERROR: 배열의 경게를 벗어난 접근입니다." << '\n';
				exit(1);
			}
		return m_p_data[i_index];
		}

		T& operator[](int i_index) const { return operator[](i_index); }
		int get_size() { return i_size; }
	private:
		T *m_p_data = nullptr;
};

int _tmain(int argc, _TCHAR *argv[])
{
	CMyArray<int, 3>arr;
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	for (int idx = 0; idx < 3; ++idx)
		cout << arr[idx] << '\n';
	return (0);
}
