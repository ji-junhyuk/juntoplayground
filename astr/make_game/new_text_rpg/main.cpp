#include "core.h"

int main(void)
{
	if (!GET_SINGLE(CCore)->init())
	{
		DESTROY_SINGLE(CCore);
		return 0;
	}
	GET_SINGLE(CCore)->run();
	DESTROY_SINGLE(CCore);
	return 0;
}
