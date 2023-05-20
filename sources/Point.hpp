#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>
#include <sstream>

class Point
{
private:
    double x;
    double y;
public:
    // Point ();
    Point(double x = 0, double y = 0);
    double distance(const Point &other) const;
    std::string print();
    static Point moveTowards(const Point &source,const Point &destination, double distance);
    double getX();
    double getY();
};

#endif /* POINT_HPP */
