#include <iomanip>
#include <iostream>

#include "Point.h"
std::ostream &operator<<(std::ostream& output, const Point& point) {
  output << "x: " << std::setprecision(8) << point.x << "\t"
         << "y: " << std::setprecision(8) << point.y << "\t"
         << "class: " << point.classId << "\t"
         << "index: " << point.index;

  return output;
}

Point::Point(const int index, const double x, const double y,
               int const classId)
    : index(index), classId(classId), x(x), y(y) {

  /* std::cout << "Train Point initialized:\n" */
  /*           << "Index: " << index << "\t" */
  /*           << "ID:" << classId << "\t" */
  /*           << "X: " << std::setprecision(8) << x << "\t" */
  /*           << "Y:" << std::setprecision(8) << y << std::endl; */
}

/* Point::Point(const int index, const double x, const double y) */
/*     : index(index), x(x), y(y) { */
/*  */
/*   std::cout << "Test Point initialized:\n" */
/*             << "Index: " << index << "\t" */
/*             << "X: " << std::setprecision(12) << x << "\t" */
/*             << "Y:" << y << std::endl; */
/*     } */

Point::~Point() {}

int Point::getIndex() const { return index; }
int Point::getClassId() const { return classId; }
double Point::getX() const { return x; }
double Point::getY() const { return y; }
void Point::setClassId(int classId){this->classId = classId;}
