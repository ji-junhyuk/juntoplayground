#include <iostream>
#include <vector>
using namespace std;

/*
vector <int> v(100); // int 타입의 0으로 초기화된 100칸 짜리 v배열 선언
v[20] = 10;
v[60] = -4;
*/

void func1(vector<int> v) 
{
    v[10] = 7;
}

int main()
{
    vector<int> v(100);
    func1(v);
    cout << v[10];
}
//0이 출력된다. 복사본을 만들어서 보내기에 func1함수에서 바꾼건 원본에 영향을 주지 않음

//*------------------------------------*//
bool cmp1(vector<int> v1, vector<int> v2, int idx)
{
    return v1[idx] > v2[idx];
}
// 시간복잡도는 O(1)이 아니라 O(N)이 된다. 원본을 복사하는 비용이 들기 때문이다.'

bool cmp2(vector<int>& v1, vector<int>& v2, int idx)
{
    return v1[idx] > v2[idx];
}
