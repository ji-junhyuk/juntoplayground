#pragma once
#include "Shape.h"
class ShapeRGun :
    public Shape
{
public:
    ShapeRGun();
    ~ShapeRGun();
public:
    virtual bool Init();
    virtual void Rotation();
};

