#pragma once
#include "Space.h"


class SpaceImpl : public Space {
public:

    void create(unsigned int dimensions);
    unsigned int dimensions() const;

private:
    unsigned int dimensionsCount;
    std::vector<Point> points;
};