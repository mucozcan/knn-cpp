#ifndef KNN_H
#define KNN_H

#include <iostream>
#include <map>

#include "Dataset.h"
#include "Point.h"

double eucledianDistance(Point p1, Point p2);

class KNN {

public:
  KNN(int const, const Dataset &);
  ~KNN();

  void run();
  void printResults();

private:

  int const K;

  std::vector<Point> trainData;
  std::vector<Point> testData;

  Dataset const dataset;

  std::map<int, int> nearestNeighbors;
};

#endif // !KNN_H
