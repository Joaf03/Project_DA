#include <iostream>
#include <sstream>
#include "SVGElements.hpp"
#include "external/tinyxml2/tinyxml2.h"
#include "Color.hpp"

using namespace std;
using namespace tinyxml2;

namespace svg
{
    void readSVG(const string &svg_file, Point &dimensions, vector<SVGElement *> &svg_elements)
    {
        XMLDocument doc;
        XMLError r = doc.LoadFile(svg_file.c_str());
        if (r != XML_SUCCESS)
        {
            throw runtime_error("Unable to load " + svg_file);
        }
        XMLElement *xml_elem = doc.RootElement();

        dimensions.x = xml_elem->IntAttribute("width");
        dimensions.y = xml_elem->IntAttribute("height");

        // Dar traverse aos XML child nodes
        XMLElement *child = xml_elem->FirstChildElement();
        while (child != nullptr)
        {
            // Criar SVGElement de acordo com o nome do node
            const char *name = child->Name();
            if (strcmp(name, "rect") == 0)
            {
                // Dar parse aos atributos do retângulo e criar rect
                int x = child->IntAttribute("x");
                int y = child->IntAttribute("y");
                int width = child->IntAttribute("width");
                int height = child->IntAttribute("height");
                string fill = child->Attribute("fill");
                Color color = parse_color(fill);
                svg_elements.push_back(new rect(color, {x, y}, width, height));
            }
            else if (strcmp(name, "circle") == 0)
            {
                // Dar parse aos atributos do círculo e criar Circle
                int cx = child->IntAttribute("cx");
                int cy = child->IntAttribute("cy");
                int r = child->IntAttribute("r");
                string fill = child->Attribute("fill");
                Color color = parse_color(fill);
                svg_elements.push_back(new Circle(color, {cx, cy}, {r, r}));
            }
            else if (strcmp(name, "line") == 0)
            {
                // Dar parse aos atributos da linha e criar line
                int x1 = child->IntAttribute("x1");
                int y1 = child->IntAttribute("y1");
                int x2 = child->IntAttribute("x2");
                int y2 = child->IntAttribute("y2");
                string stroke = child->Attribute("stroke");
                Color color = parse_color(stroke);
                svg_elements.push_back(new line({x1, y1}, {x2, y2}, color));
            }
            else if (strcmp(name, "ellipse") == 0)
            {
                // Dar parse aos atributos da elipse e criar Ellipse
                int cx = child->IntAttribute("cx");
                int cy = child->IntAttribute("cy");
                int rx = child->IntAttribute("rx");
                int ry = child->IntAttribute("ry");
                string fill = child->Attribute("fill");
                Color color = parse_color(fill);
                svg_elements.push_back(new Ellipse(color, {cx, cy}, {rx, ry}));
            }

            else if (strcmp(name, "polyline") == 0)
            {
                // Dar parse aos atributos do polyline e criar polyline
                string points_str = child->Attribute("points");
                vector<Point> points;
                istringstream iss(points_str);
                int x, y;
                char comma;
                while (iss >> x >> comma >> y)
                {
                    Point p;
                    p.x = x;
                    p.y = y;
                    points.push_back(p);
                }
                string fill = child->Attribute("fill");
                Color color = parse_color(fill);
                svg_elements.push_back(new polyline(color, points));
            }

            if (strcmp(name, "polygon") == 0)
            {
                // Dar parse aos atributos do polígono e criar polygon
                string points_str = child->Attribute("points");
                vector<Point> points;
                istringstream iss(points_str);
                int x, y;
                char comma;
                while (iss >> x >> comma >> y)
                {
                    Point p;
                    p.x = x;
                    p.y = y;
                    points.push_back(p);
                }
                string fill = child->Attribute("fill");
                Color color = parse_color(fill);
                svg_elements.push_back(new polygon(color, points));
            }

            else if (strcmp(name, "g") == 0)
            {
                const char *id = child->Attribute("id");
                vector<SVGElement *> group_elements;

                XMLElement *group_child = child->FirstChildElement();

                while (group_child != nullptr)
                {
                    const char *group_child_name = group_child->Name();

                    if (strcmp(name, "rect") == 0)
                    {
                        // Dar parse aos atributos do retângulo e criar rect
                        int x = child->IntAttribute("x");
                        int y = child->IntAttribute("y");
                        int width = child->IntAttribute("width");
                        int height = child->IntAttribute("height");
                        string fill = child->Attribute("fill");
                        Color color = parse_color(fill);
                        svg_elements.push_back(new rect(color, {x, y}, width, height));
                    }
                    else if (strcmp(name, "circle") == 0)
                    {
                        // Dar parse aos atributos do círculo e criar Circle
                        int cx = child->IntAttribute("cx");
                        int cy = child->IntAttribute("cy");
                        int r = child->IntAttribute("r");
                        string fill = child->Attribute("fill");
                        Color color = parse_color(fill);
                        svg_elements.push_back(new Circle(color, {cx, cy}, {r, r}));
                    }
                    else if (strcmp(name, "line") == 0)
                    {
                        // Dar parse aos atributos da linha e criar line
                        int x1 = child->IntAttribute("x1");
                        int y1 = child->IntAttribute("y1");
                        int x2 = child->IntAttribute("x2");
                        int y2 = child->IntAttribute("y2");
                        string stroke = child->Attribute("stroke");
                        Color color = parse_color(stroke);
                        svg_elements.push_back(new line({x1, y1}, {x2, y2}, color));
                    }
                    else if (strcmp(name, "ellipse") == 0)
                    {
                        // Dar parse aos atributos da elipse e criar Ellipse
                        int cx = child->IntAttribute("cx");
                        int cy = child->IntAttribute("cy");
                        int rx = child->IntAttribute("rx");
                        int ry = child->IntAttribute("ry");
                        string fill = child->Attribute("fill");
                        Color color = parse_color(fill);
                        svg_elements.push_back(new Ellipse(color, {cx, cy}, {rx, ry}));
                    }

                    else if (strcmp(name, "polyline") == 0)
                    {
                        // Dar parse aos atributos do polyline e criar polyline
                        string points_str = child->Attribute("points");
                        vector<Point> points;
                        istringstream iss(points_str);
                        int x, y;
                        char comma;
                        while (iss >> x >> comma >> y)
                        {
                            Point p;
                            p.x = x;
                            p.y = y;
                            points.push_back(p);
                        }
                        string fill = child->Attribute("fill");
                        Color color = parse_color(fill);
                        svg_elements.push_back(new polyline(color, points));
                    }

                    if (strcmp(name, "polygon") == 0)
                    {
                        // Dar parse aos atributos do polígono e criar polygon
                        string points_str = child->Attribute("points");
                        vector<Point> points;
                        istringstream iss(points_str);
                        int x, y;
                        char comma;
                        while (iss >> x >> comma >> y)
                        {
                            Point p;
                            p.x = x;
                            p.y = y;
                            points.push_back(p);
                        }
                        string fill = child->Attribute("fill");
                        Color color = parse_color(fill);
                        svg_elements.push_back(new polygon(color, points));
                    }
                    group_child = group_child->NextSiblingElement();
                }
                svg_elements.push_back(new Group(group_elements, id));
            }

            // Avançar para o próximo child node
            child = child->NextSiblingElement();
        }
    }
}
