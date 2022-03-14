#pragma once
#include "CScene.h"
class CSceneTool :
    public CScene
{
private:
public:
    virtual void update();
    virtual void Enter();
    virtual void Exit();

public:
    CSceneTool();
    ~CSceneTool();
};

