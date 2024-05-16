//! @file point.cpp
#include <cmath>
#include "Point.hpp"

namespace svg
{
    Point Point::translate(const Point &t) const
    {
        return {x + t.x, y + t.y};
    }

    Point Point::rotate(const Point &origin, int degrees) const
    {
        double angle = 3.1415926 * degrees / 180.0;
        double dx = x - origin.x;
        double dy = y - origin.y;
        double s = ::sin(angle);
        double c = ::cos(angle);
        int rx = (int)::lround(c * dx - s * dy);
        int ry = (int)::lround(s * dx + c * dy);
        return {origin.x + rx, origin.y + ry};
    }

    Point Point::scale(const Point &origin, int v) const
    {
        return {origin.x + (x - origin.x) * v,
                origin.y + (y - origin.y) * v};
    }

}
