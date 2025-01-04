#include "flyweight.h"

int main() {
  FlyweightFactory *factory =
      new FlyweightFactory({{"Chevrolet", "Camaro2018", "pink"},
                            {"Mercedes Benz", "C300", "black"},
                            {"Mercedes Benz", "C500", "red"},
                            {"BMW", "M5", "red"},
                            {"BMW", "X6", "white"}});
  factory->ListFlyweights();

  AddCarToPoliceDatabase(*factory, "CL234IR", "James Doe", "BMW", "M5", "red");
  AddCarToPoliceDatabase(*factory, "CL234IR", "James Doe", "BMW", "X1", "red");
  factory->ListFlyweights();
  delete factory;

  return 0;
}
