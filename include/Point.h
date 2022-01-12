#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <map>
#include <string>

class Point {
  
  friend std::ostream& operator<<(std::ostream&, const Point&);


public:
  Point( int, double, double, int classId = -1);
  ~Point();

  int getClassId() const;
  int getIndex() const;
  double getF1() const;
  double getF2() const;

  void setClassId(int);

private:
  // can't declare data members as 'const' since it causes error in std::sort(in KNN.cpp)
  int index;
  int classId; // -1 classId indicates that it is a test data.
  double f1; //feature 1
  double f2; //feature 2
};

#endif
