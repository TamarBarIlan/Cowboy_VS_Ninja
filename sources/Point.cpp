#include "Point.hpp"

Point::Point(double x, double y) : x(x), y(y)
{
}
double Point::distance(Point &other)
{
    return std::sqrt(std::pow(other.x - this->x, 2) + std::pow(other.y - this->y, 2));
}
std::string Point::print()
{
    std::stringstream ss;
    ss << "(" << this->x << ", " << this->y << ")";
    return ss.str();
}

Point Point::moveTowards(Point &source, Point &destination, double distance)
{
    if (distance < 0)
    {
        throw std::invalid_argument("Distance cannot be negative");
    }
    double totalDistance = source.distance(destination);

    if (totalDistance <= distance)
    {
        return destination;
    }
    else
    {
        double ratio = distance / totalDistance;
        double newX = source.x + (destination.x - source.x) * ratio;
        double newY = source.y + (destination.y - source.y) * ratio;
        return Point(newX, newY);
    }
}
double Point::getX()
{
    return this->x;
}
double Point::getY()
{
    return this->y;
}