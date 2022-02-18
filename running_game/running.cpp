#include "core.h"

int main(void)
{
	if (!CCore::get_inst()->init())
	{
		cout << "게임 초기화 실패!!" << '\n';
		CCore::destroy_inst();
		return (0);
	}
	CCore::get_inst()->run();
	CCore::destroy_inst();
	return (0);
}
