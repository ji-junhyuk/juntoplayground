#pragma once
#include "CScene.h"

class CSceneStart :
    public CScene
{
public:
    virtual void update();
    virtual void Enter();
    virtual void Exit();
public:
    CSceneStart();
    ~CSceneStart();
};

