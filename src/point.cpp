#include <iomanip>
#include <iostream>

#include "Point.h"
std::ostream &operator<<(std::ostream &output, const Point &point) {
  output << "feature1: " << std::setprecision(8) << point.f1 << "\t"
         << "feature2: " << std::setprecision(8) << point.f2 << "\t"
         << "class: " << point.classId << "\t"
         << "index: " << point.index;

  return output;
}

Point::Point(int index, double f1, double f2, int classId)
    : index(index), classId(classId), f1(f1), f2(f2) {}

Point::~Point() {}

int Point::getIndex() const { return index; }
int Point::getClassId() const { return classId; }
double Point::getF1() const { return f1; }
double Point::getF2() const { return f2; }
void Point::setClassId(int classId) { this->classId = classId; }
