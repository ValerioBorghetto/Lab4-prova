#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Regressione.hpp"
//compilando i due cpp insieme, è come se li concateni


TEST_CASE("Testing Regression") {
  Regression
      reg;  
  reg.add(0., 0.);
  reg.add(1., 1.);

  auto result = reg.fit(); //se invece di fare reg.fit richiamavi il fit(Regression cont& reg), definita solo in regressione.cpp, non funzionava
  CHECK(result.A == doctest::Approx(0));
  CHECK(result.B == doctest::Approx(1));
}