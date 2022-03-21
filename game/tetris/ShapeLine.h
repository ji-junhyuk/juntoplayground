#pragma once
#include "Shape.h"
class ShapeLine :
    public Shape
{
public:
    ShapeLine();
    ~ShapeLine();
public:
    virtual bool Init();
    virtual void Rotation();
};

