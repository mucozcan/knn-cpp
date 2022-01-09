#ifndef DATASET_H
#define DATASET_H

#include <iostream>
#include <vector>
#include "Point.h"

class Dataset {
public:
  Dataset();
  /* Dataset(int const, double const, double const, int const, int const, bool);
   */
  ~Dataset();
  // TODO outstream operator <<

  void initializeTrainData(double, double, int, int);
  void initializeTestData(double, double, int);
  void printTrainData();
  void printTestData();

  std::vector<Point> getTrainData() const;
  std::vector<Point> getTestData() const;

private:
  static int dataIndex; // holds the current index TODO might be unnecessary

  double random(double const, double const);

  /* bool isTrain; */
  /* int const sampleCount; */
  /* double const lowerBound; */
  /* double const upperBound; */
  /* int const classCount; */
  /* int const dataPerClass; */

  std::vector<Point> trainData;
  std::vector<Point> testData;
};

#endif // !DATASET_H
