#include "core.h"

/*
   50 x 10 맵을 만든다.
   stage 클래스 init함수에서 이 맵을 만들고
   stage 클래스에 render함수를 만들어서 이 맵을 출력하는 코드를 작성하라.
   그 후에 map 관리자 클래스의 run함수에서 해당 스테이지를 출력하라.
   (Render 함수 호출하라는 의미)
*/

int main(void)
{
	if (!CCore::get_inst()->init())
	{
		cout << "게임 초기화 실패!!" << '\n';
		CCore::destroy_inst();
