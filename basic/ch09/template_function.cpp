#include "../ch01/stdafx.h"

template<typename T>
T add(T a, T b) { return a + b; }

template< >
char *add(char *p_size_left, char *p_size_right)
{
	int i_len_left = strlen(p_size_left);
	int i_len_right = strlen(p_size_right);
	char *p_size_result = new char[i_len_left + i_len_right + 1];

	strcpy_s(p_size_result, i_len_left + 1, p_size_left);
	strcpy_s(p_size_result + i_len_left, i_len_right + 1, p_size_right);
	return p_size_result;
}

int _tmain(int argc, _TCHAR *argv[])
{
	int i_result = add<int>(3, 4);
	cout << i_result << '\n';

	char *p_size_result = add<char *>("Hello", "World");
	cout << p_size_result << '\n';
	delete[] p_size_result;
}
