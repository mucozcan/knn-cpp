#include <iostream>
#include <string>
#include <vector>

#include "Dataset.h"
#include "Visualizer.h"
#include "KNN.h"

bool argParser(int argc, char **argv, int& K, int& iter, std::string& filename){
  if (argc < 4) {
    std::cout << "USAGE:" << std::endl;
    std::cout << "./main [K] [ITERATION] [DATA_FILE]" << std::endl;
    std::cout << "Ex: ./main 2 3 data/20.txt" << std::endl;
    return false;
  }
  
  try{
    
    K = std::stoi(argv[1]);
    iter = std::stoi(argv[2]);
    filename = argv[3];
    return true;

  }catch(...){
    std::cout << "Invalid arguments." <<std::endl;
    return false;
  } 

}

int main(int argc, char **argv) {

/*   int K, iter; */
/*   std::string filename; */
/*  */
/*   if(!argParser(argc, argv, K, iter,filename)){ */
/*     return -1; */
/*   } */
/*   try{ */
/*   kMeans.readData(filename); */
/*   }catch(std::invalid_argument& e){ */
/*     std::cout << e.what() <<std::endl; */
/*     return -1; */
/*   } */
/*   kMeans.run(iter); */
/*   ClusterSet clusters = kMeans.getClusters(); */
/*   Visualizer vis(clusters); */
/*   std::cout << argc << std::endl; */
/*  */
/*   vis.plot(true, "../results/clusters.png"); */

  Dataset dataset;
  dataset.initializeTrainData(-5.0, 5.0, 3, 10);
  dataset.printTrainData();

  dataset.initializeTestData(-5.0, 5.0, 10);
  dataset.printTestData();

  KNN knn(3, dataset);
  knn.run();
  return 0;
}
