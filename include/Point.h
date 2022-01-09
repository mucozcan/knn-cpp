#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <map>
#include <string>

class Point {
  
  friend std::ostream& operator<<(std::ostream&, const Point&);


public:
  Point(const int, const double, const double, int classId = -1);
  /* Point(const int, const double, const double); */
  ~Point();

  int getClassId() const;
  int getIndex() const;
  double getX() const;
  double getY() const;

  void setClassId(int);

private:
  int const index;
  int classId; // -1 classId means it is a test data.
  double const x;
  double const y;
};

#endif
