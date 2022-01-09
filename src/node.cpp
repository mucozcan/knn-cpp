#include <iomanip>
#include <iostream>

#include "Node.h"
std::ostream &operator<<(std::ostream& output, const Sample& sample) {
  output << "x: " << std::setprecision(8) << sample.x << "\t"
         << "y: " << std::setprecision(8) << sample.y << "\t"
         << "class: " << sample.classId << "\t"
         << "index: " << sample.index;

  return output;
}

Sample::Sample(const int index, const double x, const double y,
               int const classId)
    : index(index), classId(classId), x(x), y(y) {

  /* std::cout << "Train Sample initialized:\n" */
  /*           << "Index: " << index << "\t" */
  /*           << "ID:" << classId << "\t" */
  /*           << "X: " << std::setprecision(8) << x << "\t" */
  /*           << "Y:" << std::setprecision(8) << y << std::endl; */
}

/* Sample::Sample(const int index, const double x, const double y) */
/*     : index(index), x(x), y(y) { */
/*  */
/*   std::cout << "Test Sample initialized:\n" */
/*             << "Index: " << index << "\t" */
/*             << "X: " << std::setprecision(12) << x << "\t" */
/*             << "Y:" << y << std::endl; */
/*     } */

Sample::~Sample() {}

int Sample::getIndex() const { return index; }
int Sample::getClassId() const { return classId; }
double Sample::getX() const { return x; }
double Sample::getY() const { return y; }
