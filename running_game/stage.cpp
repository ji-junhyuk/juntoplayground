#include "stage.h"
#include "file_stream.h"

CStage::CStage()
{
}

CStage::~CStage()
{
}

bool CStage::init()
{
	return true;
}

bool CStage::init(char *p_file_name)
{
	CFileStream file;
	if (!file.open(p_file_name, "rt"))
		return false;
	for (int idx = 0; idx < 10; ++idx)
	{
		int i_size = 0;
		file.read_line(m_c_stage[idx], i_size);
		for (int jdx = 0; jdx < 50; ++jdx)
			cout << m_c_stage[idx][jdx];
		cout << '\n';
	}
	cout << '\n' << '\n';
	return true;
}
