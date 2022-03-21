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
private:
	HANDLE		m_hConsole;
	bool		m_bLoop;

public:
	bool Init();
	void Run();
	void SetConsolePos(short x, short y);
	void End() { m_bLoop = false; }
};
