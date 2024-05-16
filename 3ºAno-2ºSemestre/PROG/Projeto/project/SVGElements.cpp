#include "SVGElements.hpp"
#include <vector>

namespace svg
{

    Circle::Circle(const Color &fill,
                   const Point &center,
                   const Point &radius)
        : Ellipse(fill, center, radius) {}
    void Circle::draw(PNGImage &img) const
    {
        img.draw_ellipse(center, radius, fill);
    }

    polyline::polyline(const Color &fill,
                       const std::vector<Point> &points)
        : fill(fill), points(points) {}

    void polyline::draw(PNGImage &img) const
    {
        for (size_t i = 0; i < points.size() - 1; i++)
        {
            img.draw_line(points[i], points[i + 1], fill);
        }
    }

    void polyline::translate(float dx, float dy)
    {
        // Translate each point of the polyline
        for (Point &point : points)
        {
            point.x += dx;
            point.y += dy;
        }
    }

    void polyline::rotate(float angle, const Point &center)
    {
        // Translate each point of the polyline to the origin, rotate, and then translate back
        float radianAngle = angle * 3.1415926 / 180.0; // Convert degrees to radians
        float cosTheta = cos(radianAngle);
        float sinTheta = sin(radianAngle);

        for (Point &point : points)
        {
            // Translate to the origin
            float translatedX = point.x - center.x;
            float translatedY = point.y - center.y;

            // Perform rotation
            float rotatedX = translatedX * cosTheta - translatedY * sinTheta;
            float rotatedY = translatedX * sinTheta + translatedY * cosTheta;

            // Translate back
            point.x = rotatedX + center.x;
            point.y = rotatedY + center.y;
        }
    }

    void polyline::scale(float sx, float sy)
    {
        // Scale each point of the polyline
        for (Point &point : points)
        {
            point.x *= sx;
            point.y *= sy;
        }
    }

    line::line(const Point &start,
               const Point &end,
               const Color &fill)
        : polyline(fill, std::vector<Point>{start, end}), start(start), end(end) {}

    void line::draw(PNGImage &img) const
    {
        img.draw_line(start, end, fill);
    }

    polygon::polygon(const Color &fill,
                     const std::vector<Point> &points)
        : fill(fill), points(points) {}
    void polygon::draw(PNGImage &img) const
    {
        img.draw_polygon(points, fill);
    }
    void polygon::translate(float dx, float dy)
    {
        // Translate each point of the polygon
        for (Point &point : points)
        {
            point.x += dx;
            point.y += dy;
        }
    }

    void polygon::rotate(float angle, const Point &center)
    {
        // Translate each point of the polygon to the origin, rotate, and then translate back
        float radianAngle = angle * 3.1415926 / 180.0; // Convert degrees to radians
        float cosTheta = cos(radianAngle);
        float sinTheta = sin(radianAngle);

        for (Point &point : points)
        {
            // Translate to the origin
            float translatedX = point.x - center.x;
            float translatedY = point.y - center.y;

            // Perform rotation
            float rotatedX = translatedX * cosTheta - translatedY * sinTheta;
            float rotatedY = translatedX * sinTheta + translatedY * cosTheta;

            // Translate back
            point.x = rotatedX + center.x;
            point.y = rotatedY + center.y;
        }
    }

    void polygon::scale(float sx, float sy)
    {
        // Scale each point of the polygon
        for (Point &point : points)
        {
            point.x *= sx;
            point.y *= sy;
        }
    }

    rect::rect(const Color &fill, const Point &upper_left_corner,
               const int &width,
               const int &height)
        : polygon(fill, std::vector<Point>{
                            upper_left_corner,
                            {upper_left_corner.x + width, upper_left_corner.y},
                            {upper_left_corner.x + width, upper_left_corner.y + height},
                            {upper_left_corner.x, upper_left_corner.y + height}}) {}

    void rect::draw(PNGImage &img) const
    {
        img.draw_polygon(points, fill);
    }

    void rect::translate(float dx, float dy)
    {
        upper_left_corner.x += dx;
        upper_left_corner.y += dy;
        for (auto &point : points)
        {
            point.x += dx;
            point.y += dy;
        }
    }

    void rect::rotate(float angle, const Point &center)
    {
        float radians = angle * 3.1415926 / 180.0f;
        for (auto &point : points)
        {
            float x_new = center.x + (point.x - center.x) * cos(radians) - (point.y - center.y) * sin(radians);
            float y_new = center.y + (point.x - center.x) * sin(radians) + (point.y - center.y) * cos(radians);
            point.x = x_new;
            point.y = y_new;
        }
    }

    void rect::scale(float sx, float sy)
    {
        for (auto &point : points)
        {
            point.x = upper_left_corner.x + (point.x - upper_left_corner.x) * sx;
            point.y = upper_left_corner.y + (point.y - upper_left_corner.y) * sy;
        }
    }

    Group::Group(std::vector<SVGElement *> &elements, const std::string &id)
        : elements(elements), id_(id)
    {
    }

    void Group::draw(PNGImage &img) const
    {
        for (const SVGElement *element : elements)
        {
            element->draw(img);
        }
    }

    void Group::translate(float dx, float dy)
    {
        // Translate each element in the group
        for (SVGElement *element : elements)
        {
            element->translate(dx, dy);
        }
    }

    void Group::rotate(float angle, const Point &center)
    {
        // Rotate each element in the group around the specified center point
        for (SVGElement *element : elements)
        {
            element->rotate(angle, center);
        }
    }

    void Group::scale(float sx, float sy)
    {
        // Scale each element in the group
        for (SVGElement *element : elements)
        {
            element->scale(sx, sy);
        }
    }
}
