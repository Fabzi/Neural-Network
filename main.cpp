#include "MathVect/MathVect.hpp"
#include <iostream>


int main()
{
  MathVect<float> myVect1{ 5, 3 };
  MathVect<float> myVect2{ 6, 7 };

  std::cout << "Scalar product Vect1 & Vect2: " << myVect1 * myVect2 << std::endl;
  std::cout << std::endl;
  std::cout << "Length Vect1: " << myVect1.getLength() << std::endl;
  std::cout << std::endl;
  std::cout << "Vect1: " << myVect1 << std::endl;
  std::cout << "Vect2: " << myVect2 << std::endl;
  return 0;
}
