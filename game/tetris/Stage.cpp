#include "Stage.h"

Stage::Stage()
{
}

Stage::~Stage()
{
}

bool Stage::Init()
{
	memset(m_Stage, 0, STAGE_WIDTH * STAGE_HEIGHT);
	return true;
}

void Stage::Render()
{
	for (int idx = 0; idx < STAGE_HEIGHT + 1; ++idx)
	{
		for (int jdx = 0; jdx < STAGE_WIDTH + 2; ++jdx)
		{
			if (idx == 0 && (jdx == 0 || jdx == STAGE_WIDTH + 1))
				cout << "бс";
			else if (jdx == 0)
				cout << "бс";
			else if (idx == STAGE_HEIGHT)
				cout << "бс";
			else if (jdx == STAGE_WIDTH + 1)
				cout << "бс";
			else
				cout << "  ";
		}
		cout << '\n';
	}
}
