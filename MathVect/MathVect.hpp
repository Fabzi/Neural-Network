#ifndef _MATH_VECTORS_HPP_
#define _MATH_VECTORS_HPP_

  #include <vector>
  #include <numeric>
  #include <concepts>

  template<typename T>
    concept arithmetic = std::integral<T> or std::floating_point<T>;

  template<typename T> 
    requires arithmetic<T>
  class MathVect : public std::vector<T>
  {
    private:
      /* data */
    public:
      MathVect(/* args */);
      ~MathVect();
  };


#endif // _MATH_VECTORS_HPP_