#ifndef _MATH_VECTORS_HPP_
#define _MATH_VECTORS_HPP_

  #include <vector>
  #include <concepts>
  #include <ostream>
  #include <stdexcept>

  template <typename T>
  concept Number = std::integral<T> || std::floating_point<T>;

  template <Number num>
  class MathVect : public std::vector<num>
  {
    public:
      using std::vector<num>::vector;

      friend MathVect operator+(const MathVect& lhs, const MathVect& rhs)
      {
        MathVect<num> vect;

        size_t lhs_length = lhs.size();
        if(lhs_length == rhs.size() && lhs_length > 0)
        {
          for (size_t i = 0; i < lhs_length; i++)
          {
            vect.push_back(lhs.at(i) + rhs.at(i));
          }
        }
        else
        {
          throw std::runtime_error("[calculation failed]: Vectors have an invalid size!");
        }

        return vect;
      }

      friend MathVect operator-(const MathVect& lhs, const MathVect& rhs)
      {
        MathVect<num> vect;

        size_t lhs_length = lhs.size();
        if(lhs_length == rhs.size() && lhs_length > 0)
        {
          for (size_t i = 0; i < lhs_length; i++)
          {
            vect.push_back(lhs.at(i) - rhs.at(i));
          }
        }
        else
        {
          throw std::runtime_error("[calculation failed]: Vectors have an invalid size!");
        }

        return vect;
      }

      MathVect& operator+=(const MathVect& rhs)
      {
        size_t this_length = this->size();
        if(this_length == rhs.size() && this_length > 0)
        {
          for (size_t i = 0; i < this_length; i++)
          {
            this->at(i) += rhs.at(i);
          }
        }
        else
        {
          throw std::runtime_error("[calculation failed]: Vectors have an invalid size!");
        }

        return *this;
      }

      MathVect& operator-=(const MathVect& rhs)
      {
        size_t this_length = this->size();
        if(this_length == rhs.size() && this_length > 0)
        {
          for (size_t i = 0; i < this_length; i++)
          {
            this->at(i) -= rhs.at(i);
          }
        }
        else
        {
          throw std::runtime_error("[calculation failed]: Vectors have an invalid size!");
        }

        return *this;
      }

      template<Number scalar_num>
      friend MathVect operator*(const MathVect& lhs, const scalar_num& scalar)
      {
        MathVect<num> vect;

        size_t lhs_length = lhs.size();
        for (size_t i = 0; i < lhs_length; i++)
        {
          vect.push_back(lhs.at(i) * scalar);
        }

        return vect;
      }

      template<Number scalar_num>
      friend MathVect operator*(const scalar_num& scalar, const MathVect& lhs)
      {
        return (lhs * scalar);
      }

      template<Number scalar_num>
      MathVect& operator*=(const scalar_num& scalar)
      {
        size_t this_length = this->size();
        for (size_t i = 0; i < this_length; i++)
        {
          this->at(i) *= scalar;
        }

        return *this;
      }
    
      friend std::ostream& operator<<(std::ostream& out, const MathVect& rhs)
      {
        out << "{ ";

        auto rhs_iter = rhs.begin();
        out << std::to_string(*(rhs_iter++));

        while (rhs_iter != rhs.end())
        {
          out << ", " << std::to_string(*(rhs_iter++));
        }
        out << " }";

        return out;
      }
  };


#endif // _MATH_VECTORS_HPP_