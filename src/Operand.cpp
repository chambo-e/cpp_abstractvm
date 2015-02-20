//
// Operand.cpp for  in /home/chambo_e/epitech/cpp_abstractvm
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.net>
//
// Started on  Thu Feb 19 19:17:50 2015 Emmanuel Chambon
// Last update Fri Feb 20 00:37:09 2015 Emmanuel Chambon
//

#include "Operand.hpp"

template<typename T>
Operand<T>::Operand(eOperandType t, std::string const &value) : _type(t), _str(value), _cpu(Cpu::getInstance())
{
  std::stringstream	cv(value);

  cv >> _value;
}

template<typename T>
std::string const		&Operand<T>::toString() const
{
  return _str;
}

template<typename T>
int				Operand<T>::getPrecision() const
{
  return _type;
}

template<typename T>
eOperandType			Operand<T>::getType() const
{
  return _type;
}

template<typename T>
IOperand			*Operand<T>::operator+(const IOperand __attribute__((unused))&s) const
{
  return 0;
}

template<typename T>
IOperand			*Operand<T>::operator-(const IOperand __attribute__((unused))&s) const
{
  return 0;
}

template<typename T>
IOperand			*Operand<T>::operator*(const IOperand __attribute__((unused))&s) const
{
  return 0;
}

template<typename T>
IOperand			*Operand<T>::operator/(const IOperand __attribute__((unused))&s) const
{
  return 0;
}

template<typename T>
IOperand			*Operand<T>::operator%(const IOperand __attribute__((unused))&s) const
{
  return 0;
}

template class Operand<int8_t>;
template class Operand<int16_t>;
template class Operand<int32_t>;
template class Operand<int64_t>;
template class Operand<float>;
template class Operand<double>;
