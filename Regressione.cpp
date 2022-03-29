#include "Regressione.hpp"

Result fit(Regression const &reg) {  
      return reg.fit();
}

void Regression::add(double x, double y) { //se le sposti qua invece, non serve inline, sono dichiarate solo qua
    ++N_;
    sium_x_ += x;
    sium_y_ += y;
    sium_x2_ += x * x;
    sium_xy_ += x * y;
}