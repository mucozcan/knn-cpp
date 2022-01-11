#include <iomanip>
#include <iostream>

#include "Point.h"
std::ostream &operator<<(std::ostream &output, const Point &point) {
  output << "x: " << std::setprecision(8) << point.x << "\t"
         << "y: " << std::setprecision(8) << point.y << "\t"
         << "class: " << point.classId << "\t"
         << "index: " << point.index;

  return output;
}

Point::Point(int index, double x, double y, int classId)
    : index(index), classId(classId), x(x), y(y) {}

Point::~Point() {}

int Point::getIndex() const { return index; }
int Point::getClassId() const { return classId; }
double Point::getX() const { return x; }
double Point::getY() const { return y; }
void Point::setClassId(int classId) { this->classId = classId; }
