#ifndef _VECTOR_CALCULATIONS_HPP_
#define _VECTOR_CALCULATIONS_HPP_

  #include "MathVect.hpp"
  #include <math.h>

  namespace VectorCalc
  {
    template <Number num1, Number num2>
    double calcScalarProduct(const MathVect<num1>& vect1, const MathVect<num2>& vect2)
    {
      MathVect<double> vect;
      double sum = 0;

      size_t vect1_length = vect1.size();
      if(vect1_length == vect2.size() && vect1_length > 0)
      {
        for (size_t i = 0; i < vect1_length; i++)
        {
          vect.push_back(static_cast<double>(vect1.at(i)) * static_cast<double>(vect2.at(i)));
        }

        for(auto& value : vect)
        {
          sum += value;
        }
      }
      else
      {
        throw std::runtime_error("[calculation failed]: Vectors have an invalid size!");
      }

      return sum;
    }

    template <Number num>
    double calcVectorLength(const MathVect<num>& vect)
    {
      return sqrt(calcScalarProduct(vect, vect));
    }

    template <Number num>
    double calcExpOfVector(const MathVect<num>& vect)
    {
      return 1.0;
    }
  }

#endif // _VECTOR_CALCULATIONS_HPP_
