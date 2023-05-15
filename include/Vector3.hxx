#pragma once

struct Vector3
{
    union
    {
        float data[3];
        float x, y, z;
    };
};
