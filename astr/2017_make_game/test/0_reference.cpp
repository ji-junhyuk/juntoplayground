#include <iostream>
using namespace std;

int main(void)
{
	int i_number = 100;
	int i_number2 = 5000;
	int &i_ref_num = i_number;
	i_ref_num = 1234;
	i_ref_num = i_number2;
	cout << i_number << '\n';
	cout << sizeof(i_ref_num) << '\n';
}
