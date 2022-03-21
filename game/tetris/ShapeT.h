#pragma once
#include "Shape.h"
class ShapeT :
    public Shape
{
public:
    ShapeT();
    ~ShapeT();
public:
    virtual bool Init();
    virtual void Rotation();
};

