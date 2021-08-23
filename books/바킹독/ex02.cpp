#include <iostream>
using namespace std;
void func(int a)
{
    a = 5;
}

void func2(int arr[])
{
    arr[0] = 10;
}

struct pt{
    int x, y;
};

void func3(pt a)
{
    a.x = 10;
}

int main()
{
    int t = 0;
    func(t);
    cout << t;

    int arr[3] = {1, 2, 3};
    func2(arr);
    cout << arr[0];

    pt tmp = {0, 0};
    func3(tmp);
    cout << tmp.x;
}
