#ifndef DATASET_H
#define DATASET_H

#include <iostream>
#include <vector>
#include "Point.h"

class Dataset {
public:
  Dataset();
  ~Dataset();

  void initializeTrainData(double, double, int, int);
  void initializeTestData(double, double, int);
  void printTrainData();
  void printTestData();

  std::vector<Point> getTrainData() const;
  std::vector<Point> getTestData() const;

private:
  static int dataIndex; 

  double random(double const, double const);



  std::vector<Point> trainData;
  std::vector<Point> testData;
};

#endif // !DATASET_H
