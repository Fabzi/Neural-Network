#include "ActFunction.hpp"

namespace ActFunction
{
  double heaviside(double scalar_product)
  {
    return (scalar_product >= 0 ? 1 : 0);
  }

  double Linear(double scalar_product)
  {
    return scalar_product;
  }

  double Sigmoid(double scalar_product)
  {
    return ( 1 / ( 1 + exp(-scalar_product) ) );
  }

  double DerivativeSigmoid(double scalar_product)
  {
    double sigmoid = Sigmoid(scalar_product);
    return ( sigmoid * ( 1 - sigmoid ) );
  }

  double Tanh(double scalar_product)
  {
    return tanh(scalar_product);
  }

  double DerivativeTanh(double scalar_product)
  {
    return pow(tanh(scalar_product), 2);
  }

  double ReLU(double scalar_product)
  {
    return ( scalar_product > 0 ? scalar_product : 0 );
  }

} // Activation
