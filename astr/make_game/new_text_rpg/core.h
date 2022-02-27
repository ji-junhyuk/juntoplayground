#pragma once

#include "value.h"

class CCore
{
	public:
		bool init();
		void run();
	private:
		int output_menu();
	DECLARE_SINGLE(CCore)
};
