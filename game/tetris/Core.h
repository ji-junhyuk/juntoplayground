#pragma once

#include "value.h"

class Core
{
private:
	Core();
	~Core();
private:
	static Core* m_pInst;
public:
	static Core* GetInst()
	{
		if (!m_pInst)
			m_pInst = new Core;
		return m_pInst;
	}
	static void DestroyInst()
	{
		SAFE_DELETE(m_pInst);
	}
public:
	bool Init();
	void Run();
};

