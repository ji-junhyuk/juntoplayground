#pragma once

class CCollisionMgr
{
	SINGLE(CCollisionMgr)
private:
public:
	void init();
	void update();
	void CheckGroup(GROUP_TYPE _eLeft, GROUP_TYPE _eRight);
};

