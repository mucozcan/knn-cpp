#include <iostream>
#include <string>
#include <vector>

#include "Visualizer.h"
/* #include "matplot/matplot.h" */
/* #include <matplot/matplot.h> */

Visualizer::Visualizer(ClusterSet &clusters) { initialize(clusters); }

Visualizer::~Visualizer() {}

std::vector<double> Visualizer::getXCoords() { return xCoords; }
std::vector<double> Visualizer::getYCoords() { return yCoords; }
std::vector<double> Visualizer::getColors() { return colors; }

void Visualizer::initialize(ClusterSet &clusters) {

  for (ClusterSet::iterator clusterIter = clusters.begin();
       clusterIter != clusters.end(); ++clusterIter) {
    xCoords.push_back(clusterIter->first.first);
    yCoords.push_back(clusterIter->first.second);
    colors.push_back(clusterIter->second);
  }
}
/*  */
/* void Visualizer::plot(bool save, std::string filename) { */
/*   auto l = matplot::scatter(getXCoords(), getYCoords(), 6.0, getColors()); */
/*   l->marker_face(true); */
/*   matplot::show(); */
/*   if (save) { */
/*     matplot::save(filename); */
/*     std::cout << "Result is saved to: " << filename << std::endl; */
/*   } */
/* } */
