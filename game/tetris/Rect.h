#pragma once
#include "Shape.h"
class Rect :
    public Shape
{
public:
    Rect();
    ~Rect();
public:
    virtual bool Init();
};

