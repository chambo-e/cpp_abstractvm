//
// Operand.cpp for  in /home/chambo_e/epitech/cpp_abstractvm
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.net>
//
// Started on  Thu Feb 19 19:17:50 2015 Emmanuel Chambon
// Last update Sat Feb 21 23:49:51 2015 Emmanuel Chambon
//

#include "Operand.hpp"

template<typename T>
Operand<T>::Operand(eOperandType t, std::string const &value) : _type(t), _str(value), _cpu(Cpu::getInstance())
{
  std::stringstream	cv(value);

  if (!(cv >> _value))
    throw VMException(std::string("Underflow or Overflow on ") + value);
  initOperand();
}

template<typename T>
void				Operand<T>::initOperand()
{
  _operand.insert(Op::value_type(::Int8, &Cpu::createInt8));
  _operand.insert(Op::value_type(::Int16, &Cpu::createInt16));
  _operand.insert(Op::value_type(::Int32, &Cpu::createInt32));
  _operand.insert(Op::value_type(::Int64, &Cpu::createInt64));
  _operand.insert(Op::value_type(::Float, &Cpu::createFloat));
  _operand.insert(Op::value_type(::Double, &Cpu::createDouble));
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
IOperand			*Operand<T>::operator+(const IOperand &s) const
{
  double			a;
  double			b;
  std::stringstream		ss;
  std::stringstream		sa;

  sa << s.toString();
  sa >> b;
  a = _value + b;
  ss << a;
  if (_type >= s.getPrecision()) {
    if (a < std::numeric_limits<T>::min() || a > std::numeric_limits<T>::max())
      throw VMException(std::string("Underflow or Overflow on ") + _str + std::string(" + ") + s.toString());
    return new Operand<T>(_type, ss.str());
  }
  Op::const_iterator i = _operand.find(s.getType());
  std::cout << s.getPrecision() << std::endl;
  IOperand *(Cpu::*ptr)(const std::string &) = i->second;
  return (_cpu.*ptr)(ss.str());
}

template<typename T>
IOperand			*Operand<T>::operator-(const IOperand &s) const
{
  double			a;
  double			b;
  std::stringstream		ss;
  std::stringstream		sa;

  sa << s.toString();
  sa >> b;
  a = _value - b;
  ss << a;
  if (_type >= s.getPrecision()) {
    if (a < std::numeric_limits<T>::min() || a > std::numeric_limits<T>::max())
      throw VMException(std::string("Underflow or Overflow on ") + _str + std::string(" - ") + s.toString());
    return new Operand<T>(_type, ss.str());
  }
  Op::const_iterator i = _operand.find(s.getType());
  IOperand *(Cpu::*ptr)(const std::string &) = i->second;
  return (_cpu.*ptr)(ss.str());
}

template<typename T>
IOperand			*Operand<T>::operator*(const IOperand &s) const
{
  double			a;
  double			b;
  std::stringstream		ss;
  std::stringstream		sa;

  sa << s.toString();
  sa >> b;
  a = _value * b;
  ss << a;
  if (_type >= s.getPrecision()) {
    if (a < std::numeric_limits<T>::min() || a > std::numeric_limits<T>::max())
      throw VMException(std::string("Underflow or Overflow on ") + _str + std::string(" * ") + s.toString());
    return new Operand<T>(_type, ss.str());
  }
  Op::const_iterator i = _operand.find(s.getType());
  IOperand *(Cpu::*ptr)(const std::string &) = i->second;
  return (_cpu.*ptr)(ss.str());
}

template<typename T>
IOperand			*Operand<T>::operator/(const IOperand &s) const
{
  double			a;
  double			b;
  std::stringstream		ss;
  std::stringstream		sa;

  sa << s.toString();
  sa >> b;
  a = _value / b;
  ss << a;
  if (_type >= s.getPrecision()) {
    if (a < std::numeric_limits<T>::min() || a > std::numeric_limits<T>::max())
      throw VMException(std::string("Underflow or Overflow on ") + _str + std::string(" / ") + s.toString());
    return new Operand<T>(_type, ss.str());
  }
  Op::const_iterator i = _operand.find(s.getType());
  IOperand *(Cpu::*ptr)(const std::string &) = i->second;
  return (_cpu.*ptr)(ss.str());
}

template<typename T>
IOperand			*Operand<T>::operator%(const IOperand &s) const
{
  double			a;
  double			b;
  double			c;
  std::stringstream		ss;
  std::stringstream		si;
  std::stringstream		sa;

  sa << s.toString();
  si << toString();
  sa >> b;
  si >> c;
  a = fmod(c, b);
  ss << a;
  if (_type >= s.getPrecision()) {
    if (a < std::numeric_limits<T>::min() || a > std::numeric_limits<T>::max())
      throw VMException(std::string("Underflow or Overflow on ") + _str + std::string(" % ") + s.toString());
    return new Operand<T>(_type, ss.str());
  }
  Op::const_iterator i = _operand.find(s.getType());
  IOperand *(Cpu::*ptr)(const std::string &) = i->second;
  return (_cpu.*ptr)(ss.str());
}

template class Operand<int8_t>;
template class Operand<int16_t>;
template class Operand<int32_t>;
template class Operand<int64_t>;
template class Operand<float>;
template class Operand<double>;
