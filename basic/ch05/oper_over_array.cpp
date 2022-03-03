#include "../ch01/stdafx.h"

class CIntArray
{
	public:
		CIntArray(int i_size)
		{
			m_p_i_data = new int[i_size];
			memset(m_p_i_data, 0, sizeof(int) * i_size);
		}
		~CIntArray() { delete m_p_i_data; }
		int operator[](int i_index) const
		{
			cout << "operator[] const" << '\n';
			return m_p_i_data[i_index];
		}
		int &operator[](int i_index)
		{
			cout << "operator[]" << '\n';
			return m_p_i_data[i_index];
		}
	private:
		int *m_p_i_data;
		int m_i_size;
};

void test_func(const CIntArray &arr_param)
{
	cout << "test_func()" << '\n';
	cout << arr_param[3] << '\n';
}

int _tmain(int argc, _TCHAR *argv[])
{
	CIntArray arr(5);	
	for (int idx = 0; idx < 5; ++idx)
		arr[idx] = idx * 10;
	test_func(arr);
	return 0;
}
