#ifndef _ACTIVATION_FUNCTIONS_HPP_
#define _ACTIVATION_FUNCTIONS_HPP_

  #include <math.h>

  namespace ActFunction
  {
    double BinaryStep(double scalar_product);
    double Linear(double scalar_product);
    double Sigmoid(double scalar_product);
    double DerivativeSigmoid(double scalar_product);
    double Tanh(double scalar_product);
    double DerivativeTanh(double scalar_product);
    double ReLU(double scalar_product);

  } // Activation
  

#endif // _ACTIVATION_FUNCTIONS_HPP_