#include "stdafx.h"
#include <iostream>
# define MAX 6
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	char name[MAX];
	int age;

	cout << "name: ";
	cin >> name;
	cout << "age: ";
	cin >> age;
	cout << "나의 이름은 " << name << "이고, " << age << "살입니다." << '\n';
	return (0);
}
