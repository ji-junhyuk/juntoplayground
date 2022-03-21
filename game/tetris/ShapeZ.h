#pragma once
#include "Shape.h"
class ShapeZ :
    public Shape
{
public:
    ShapeZ();
    ~ShapeZ();
public:
    virtual bool Init();
    virtual void Rotation();
};

