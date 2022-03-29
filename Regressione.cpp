#include "Regressione.hpp"

Result fit(Regression const &reg) {  
      return reg.fit();
}

void Regression::add(double x, double y) { 
    points_.push_back(Point{x,y});
}