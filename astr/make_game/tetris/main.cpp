#include "core.h"

int main()
{
	if (!CCore::get_inst()->init())
	{
		CCore::destroy_inst();
		return (0);
	}
	CCore::get_inst()->run();
	CCore::destroy_inst();
	return (0);
}
