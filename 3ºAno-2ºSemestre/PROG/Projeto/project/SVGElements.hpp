//! @file SVGElements.hpp
#ifndef __svg_SVGElements_hpp__
#define __svg_SVGElements_hpp__

#include "Color.hpp"
#include "Point.hpp"
#include "PNGImage.hpp"
#include <vector>
#include <cmath>

namespace svg
{

    class SVGElement
    {
    public:
        SVGElement();
        virtual ~SVGElement();
        virtual void draw(PNGImage &img) const = 0;
        virtual void translate(float dx, float dy) = 0;
        virtual void rotate(float angle, const Point &center) = 0;
        virtual void scale(float sx, float sy) = 0;

    protected:
        Color fill_;
        std::string id_;
    };

    void readSVG(const std::string &svg_file,
                 Point &dimensions,
                 std::vector<SVGElement *> &svg_elements);
    void convert(const std::string &svg_file,
                 const std::string &png_file);

    class Ellipse : public SVGElement
    {
    public:
        Ellipse(const Color &fill, const Point &center, const Point &radius);
        void draw(PNGImage &img) const override;
        void translate(float dx, float dy) override;
        void rotate(float angle, const Point &center) override;
        void scale(float sx, float sy) override;

    protected:
        Color fill;
        Point center;
        Point radius;
    };

    class Circle : public Ellipse
    {
    public:
        Circle(const Color &fill, const Point &center, const Point &radius);
        void draw(PNGImage &img) const override;
    };

    class polyline : public SVGElement
    {
    public:
        polyline(const Color &fill, const std::vector<Point> &points);
        void draw(PNGImage &img) const override;
        void translate(float dx, float dy) override;
        void rotate(float angle, const Point &center) override;
        void scale(float sx, float sy) override;

    protected:
        Color fill;
        std::vector<Point> points;
    };

    class line : public polyline
    {
    public:
        line(const Point &start, const Point &end, const Color &fill);
        void draw(PNGImage &img) const override;

    protected:
        Point start;
        Point end;
        Color fill;
    };

    class polygon : public SVGElement
    {
    public:
        polygon(const Color &fill, const std::vector<Point> &points);
        void draw(PNGImage &img) const override;
        void translate(float dx, float dy) override;
        void rotate(float angle, const Point &center) override;
        void scale(float sx, float sy) override;

    protected:
        Color fill;
        std::vector<Point> points;
    };

    class rect : public polygon
    {
    public:
        rect(const Color &fill, const Point &upper_left_corner, const int &width, const int &height);
        void draw(PNGImage &img) const override;
        void translate(float dx, float dy) override;
        void rotate(float angle, const Point &center) override;
        void scale(float sx, float sy) override;

    protected:
        Point upper_left_corner;
        int width;
        int height;
    };

    class Group : public SVGElement
    {
    public:
        Group(std::vector<SVGElement *> &elements, const std::string &id);
        void draw(PNGImage &img) const override;
        void translate(float dx, float dy) override;
        void rotate(float angle, const Point &center) override;
        void scale(float sx, float sy) override;

    protected:
        std::vector<SVGElement *> &elements;
        const std::string &id_;
    };
};
#endif
