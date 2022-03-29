#ifndef REGRESSIONE_HPP 
#define REGRESSIONE_HPP
#include <cassert>
//REGRESSIONE_HPP è un nome inventato, è una macro del preprocessore e si riferisce comunque a questo hpp

struct Result {  
  double A{};  
  double B{};
};

class Regression {
 private:
  int N_{};          
  double sium_x_{};  
  double sium_y_{};
  double sium_x2_ = 0;
  double sium_xy_ = 0;

 public:
  void add(double x, double y);  
  
  Result fit() const  
  {

      assert(sium_x_!= 0 && N_>1 ); 
    double Q = (sium_y_ * sium_x2_ - sium_x_ * sium_xy_) /
               (N_ * sium_x2_ - sium_x_ * sium_x_);
    double M = (N_ * sium_xy_ - sium_x_ * sium_y_) /
               (N_ * sium_x2_ - sium_x_ * sium_x_);
     Result ciao{Q,M};       
    return ciao;
  }
};

/* se le dichiaravi qua e non su Regressione.cpp:
inline auto fit(Regression const &reg) {  //se non metti inline, fit, non essendo dentro la classe, sarà definita sia su regressione lineare.cpp sia su regressione.cpp. if not def fa solo in modo che nella 
//stessa traslation unit (quindi nello stesso file cpp che include lo stesso hpp più volte) se viene incluso lo stesso hpp più volte non dia errore
      return reg.fit();
  }

inline void Regression::add(double x, double y) { //qua senza inline da lo stesso errore, essendo fuori dalla classe viene definita due volte
    ++N_;
    sium_x_ += x;
    sium_y_ += y;
    sium_x2_ += x * x;
    sium_xy_ += x * y;
} */

Result fit(Regression const &reg); // per far sì che la funzione fit(Regressione const& reg) possa essere usata su Regressione-lineare.cpp, puoi dichiararla qua e 
//e definirla poi su regressione.cpp, non puoi mettere però auto, ma il tipo giusto (in questo caso Result)

#endif