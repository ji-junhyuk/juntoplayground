#include "stage.h"

CStage::CStage()
{
}

CStage::~CStage()
{
}

bool CStage::init()
{
	memset(m_stage, 0, STAGE_WIDTH * STAGE_HEIGHT);
	return true;
}

void CStage::render()
{
	for (int idx = 0; idx < STAGE_HEIGHT + 1; ++idx)
	{
		for (int jdx = 0; jdx < STAGE_WIDTH + 2; ++jdx)
		{
			if (idx == 0 && (jdx == 0 || jdx == STAGE_WIDTH + 1))
				cout << "■";
			else if (jdx == 0)
				cout << "■";
			else if (idx == STAGE_HEIGHT)
				cout << "■";
			else if (jdx == STAGE_WIDTH + 1)
				cout << "■";
			else
				cout << " ";
		}
		cout << '\n';
	}
}
