#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "Point.h"

class Visualizer {

public:
  Visualizer(std::vector<Point> &, std::vector<Point> &);
  ~Visualizer();

  void plot(bool, std::string);
private:
  void initialize(std::vector<Point> &, std::vector<Point> &);
  std::vector<double> feat1;
  std::vector<double> feat2;

  std::vector<int> classes;
  std::vector<int> sizes; // figure sizes
};

#endif
