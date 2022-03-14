#pragma once
#include "CObject.h"
class CMissile :
    public CObject
{
private:
    float       m_fTheta;
    Vec2        m_vDir;
public:
    void SetDir(float _fTheta) { m_fTheta = _fTheta; }
    void SetDir(Vec2 _vDir) 
    { 
        m_vDir = _vDir; 
        m_vDir.Normalize();
    }
public:
    virtual void update();
    virtual void render(HDC _dc);

public:
    virtual void OnCollisionEnter(CCollider* _pOther);
public:
    CMissile();
    ~CMissile();
};

