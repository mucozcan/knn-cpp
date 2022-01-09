#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <map>
#include <string>

class Sample {
  
  friend std::ostream& operator<<(std::ostream&, const Sample&);


public:
  Sample(const int, const double, const double, int classId = -1);
  /* Sample(const int, const double, const double); */
  ~Sample();

  int getClassId() const;
  int getIndex() const;
  double getX() const;
  double getY() const;

private:
  int const index;
  int const classId; // -1 classId means it is a test data.
  double const x;
  double const y;
};

#endif
