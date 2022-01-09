#ifndef KNN_H
#define KNN_H

#include <iostream>
#include <map>

#include "Dataset.h"
#include "Point.h"

typedef std::multimap<double, int, std::less<double>> Neighbors;
class KNN {

public:
  KNN(int const, const Dataset &);
  ~KNN();

  void run();
  void printResults();

private:
  double eucledianDistance(Point, Point);

  int const K;

  std::vector<Point> trainData;
  std::vector<Point> testData;
  // TODO take train and test as param, not dataset
  /* std::vector<Point> const trainData; */
  /* std::vector<Point> const testData; */
  Dataset const dataset;

  Neighbors neighbors; // TODO check if it sorts properly
  /* std::multimap<double, int, std::less<double>> nearestNeighbors; */
  std::map<int, int> nearestNeighbors;
};

#endif // !KNN_H
