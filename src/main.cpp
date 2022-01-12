#include <iostream>
#include <string>
#include <vector>

#include "Dataset.h"
#include "Visualizer.h"
#include "KNN.h"


int main(int argc, char **argv) {


  Dataset dataset;
  dataset.initializeTrainData(-5.0, 5.0, 3, 10);
  dataset.printTrainData();

  dataset.initializeTestData(-5.0, 5.0, 10);
  dataset.printTestData();

  KNN knn(3, dataset);
  knn.run();


  std::vector<Point> trainData = knn.getTrainData();
  std::vector<Point> testData = knn.getTestData();
  Visualizer vis(trainData, testData);

  vis.plot(true, "../results/classification.png");
  return 0;
}
