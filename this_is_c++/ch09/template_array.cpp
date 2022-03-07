#include "../ch01/stdafx.h"

template<typename T>
class CMyArray
{
	public:
		explicit CMyArray(int i_size) : m_i_size(i_size)
	{
		m_p_data = new T[i_size];
	}
		~CMyArray() { delete[] m_p_data; }
		CMyArray(const CMyArray &rhs)
		{
			m_p_data = new T[rhs.m_i_size];
			memcpy(m_p_data, rhs.m_p_data, sizeof(T) * rhs.m_i_size);
			m_i_size = rhs.m_i_size;
		}
		CMyArray &operator=(const CMyArray &rhs)
		{
			if (this == &rhs)
				return *this;
			delete m_p_data;
			m_p_data = new T[rhs.m_i_size];
			memcpy(m_p_data, rhs.m_p_data, sizeof(T) * rhs.m_i_size);
			m_i_size = rhs.m_i_size;
			return *this;
		}
		CMyArray(CMyArray &&rhs)
		{
			operator = (rhs);
		}
		CMyArray& operator=(const CMyArray &&rhs)
		{
			m_p_data = rhs.m_p_data;
			m_i_size = rhs.m_i_size;
			rhs.m_p_data = nullptr;
			rhs.m_i_size = 0;
		}
		T& operator[](int i_index)
		{
			if (i_index < 0 || i_index >= m_i_size)
			{
				cout << "ERROR: 배열의 경계를 벗어난 접근입니다." << '\n';
				exit(1);
			}
			return m_p_data[i_index];
		}
		T& operator[](int i_index) const
		{
			return operator[](i_index);
		}
		int get_size() { return m_i_size; }
	private:
		T *m_p_data = nullptr;
		int m_i_size = 0;
};

int _tmain(int argc, _TCHAR *argv[])
{
	CMyArray<int> arr(5);
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 40;
	arr[4] = 50;
	for (int idx = 0; idx < 5; ++idx)
		cout << arr[idx] << ' ';
	cout << '\n';
	CMyArray<int> arr2(3);
	arr2 = arr;
	for (int idx = 0; idx < 5; ++idx)
		cout << arr2[idx] << ' ';
	cout << '\n';
}
