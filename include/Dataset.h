#ifndef DATASET_H
#define DATASET_H

#include <iostream>
#include <vector>
#include "Node.h"

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

private:
  static int dataIndex; // holds the current index TODO might be unnecessary

  double random(double const, double const);

  /* bool isTrain; */
  /* int const sampleCount; */
  /* double const lowerBound; */
  /* double const upperBound; */
  /* int const classCount; */
  /* int const dataPerClass; */

  std::vector<Sample> trainData;
  std::vector<Sample> testData;
};

#endif // !DATASET_H
