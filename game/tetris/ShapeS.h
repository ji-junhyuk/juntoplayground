#pragma once
#include "Shape.h"
class ShapeS :
    public Shape
{
public:
    ShapeS();
    ~ShapeS();
public:
    virtual bool Init();
    virtual void Rotation();
};

