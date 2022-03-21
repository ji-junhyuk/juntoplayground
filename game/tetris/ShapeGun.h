#pragma once
#include "Shape.h"
class ShapeGun :
    public Shape
{
public:
    ShapeGun();
    ~ShapeGun();
public:
    virtual bool Init();
    virtual void Rotation();
};

