//
// Operand.cpp for  in /home/chambo_e/epitech/cpp_abstractvm
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.net>
//
// Started on  Thu Feb 19 19:17:50 2015 Emmanuel Chambon
// Last update Sun Feb 22 01:02:51 2015 Emmanuel Chambon
//

#include "Operand.hpp"

template class Operand<int8_t>;
template class Operand<int16_t>;
template class Operand<int32_t>;
template class Operand<int64_t>;
template class Operand<float>;
template class Operand<double>;

template<typename T>
Operand<T>::Operand(eOperandType t, std::string const &value) : _type(t), _str(value), _cpu(Cpu::getInstance())
{
  std::stringstream	cv(value);
  T			v;

  if (!(cv >> v))
    throw VMException(std::string("Underflow or Overflow on ") + value + std::string(" for type: ") +
		      std::string(::cOperandType[_type]));
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
double				Operand<T>::convertToPrec(std::string const &str) const
{
  std::stringstream		s(str);
  double			x;

  s >> x;
  return x;
}

template<typename T>
std::string			Operand<T>::convertFromPrec(double const a) const
{
  std::stringstream		s;

  s << a;
  return s.str();
}

template<typename T>
IOperand			*Operand<T>::operator+(const IOperand &s) const
{
  double			a;
  double			b;
  double			c;

  a = convertToPrec(_str);
  b = convertToPrec(s.toString());
  c = a + b;
  if (_type >= s.getPrecision()) {
    if ((std::numeric_limits<T>::has_denorm == std::denorm_absent)
	&& (c < std::numeric_limits<T>::min() || c > std::numeric_limits<T>::max())) {
      throw VMException(std::string("Underflow or Overflow on ") + _str + std::string(" + ") + s.toString()
			+ std::string(" for type: ") + std::string(::cOperandType[_type]));
    }
    else if (c < -(std::numeric_limits<T>::max()) || c > std::numeric_limits<T>::max())
      throw VMException(std::string("Underflow or Overflow on ") + _str + std::string(" + ") + s.toString()
			+ std::string(" for type: ") + std::string(::cOperandType[_type]));
    return _cpu.createOperand(_type, convertFromPrec(c));
  }
  return _cpu.createOperand(s.getType(), convertFromPrec(c));
}

template<typename T>
IOperand			*Operand<T>::operator-(const IOperand &s) const
{
  double			a;
  double			b;
  double			c;

  a = convertToPrec(_str);
  b = convertToPrec(s.toString());
  c = a - b;
  if (_type >= s.getPrecision()) {
    if ((std::numeric_limits<T>::has_denorm == std::denorm_absent)
	&& (c < std::numeric_limits<T>::min() || c > std::numeric_limits<T>::max())) {
      throw VMException(std::string("Underflow or Overflow on ") + _str + std::string(" - ") + s.toString()
			+ std::string(" for type: ") + std::string(::cOperandType[_type]));
    }
    else if (c < -(std::numeric_limits<T>::max()) || c > std::numeric_limits<T>::max())
      throw VMException(std::string("Underflow or Overflow on ") + _str + std::string(" - ") + s.toString()
			+ std::string(" for type: ") + std::string(::cOperandType[_type]));
    return _cpu.createOperand(_type, convertFromPrec(c));
  }
  return _cpu.createOperand(s.getType(), convertFromPrec(c));
}

template<typename T>
IOperand			*Operand<T>::operator*(const IOperand &s) const
{
  double			a;
  double			b;
  double			c;

  a = convertToPrec(_str);
  b = convertToPrec(s.toString());
  c = a * b;
  if (_type >= s.getPrecision()) {
    if ((std::numeric_limits<T>::has_denorm == std::denorm_absent)
	&& (c < std::numeric_limits<T>::min() || c > std::numeric_limits<T>::max())) {
      throw VMException(std::string("Underflow or Overflow on ") + _str + std::string(" * ") + s.toString()
			+ std::string(" for type: ") + std::string(::cOperandType[_type]));
    }
    else if (c < -(std::numeric_limits<T>::max()) || c > std::numeric_limits<T>::max())
      throw VMException(std::string("Underflow or Overflow on ") + _str + std::string(" * ") + s.toString()
			+ std::string(" for type: ") + std::string(::cOperandType[_type]));
    return _cpu.createOperand(_type, convertFromPrec(c));
  }
  return _cpu.createOperand(s.getType(), convertFromPrec(c));
}

template<typename T>
IOperand			*Operand<T>::operator/(const IOperand &s) const
{
  double			a;
  double			b;
  double			c;

  a = convertToPrec(_str);
  b = convertToPrec(s.toString());
  if (b == 0.0f)
    throw VMException(std::string("Error: Divison by zero"));
  c = a / b;
  if (_type >= s.getPrecision()) {
    if ((std::numeric_limits<T>::has_denorm == std::denorm_absent)
	&& (c < std::numeric_limits<T>::min() || c > std::numeric_limits<T>::max())) {
      throw VMException(std::string("Underflow or Overflow on ") + _str + std::string(" / ") + s.toString()
			+ std::string(" for type: ") + std::string(::cOperandType[_type]));
    }
    else if (c < -(std::numeric_limits<T>::max()) || c > std::numeric_limits<T>::max())
      throw VMException(std::string("Underflow or Overflow on ") + _str + std::string(" / ") + s.toString()
			+ std::string(" for type: ") + std::string(::cOperandType[_type]));
    return _cpu.createOperand(_type, convertFromPrec(c));
  }
  return _cpu.createOperand(s.getType(), convertFromPrec(c));
}

template<typename T>
IOperand			*Operand<T>::operator%(const IOperand &s) const
{
  double			a;
  double			b;
  double			c;

  a = convertToPrec(_str);
  b = convertToPrec(s.toString());
  if (b == 0.0f)
    throw VMException(std::string("Error: Modulo by zero"));
  c = fmod(a, b);
  if (_type >= s.getPrecision()) {
    if ((std::numeric_limits<T>::has_denorm == std::denorm_absent)
	&& (c < std::numeric_limits<T>::min() || c > std::numeric_limits<T>::max())) {
      throw VMException(std::string("Underflow or Overflow on ") + _str + std::string(" % ") + s.toString()
			+ std::string(" for type: ") + std::string(::cOperandType[_type]));
    }
    else if (c < -(std::numeric_limits<T>::max()) || c > std::numeric_limits<T>::max())
      throw VMException(std::string("Underflow or Overflow on ") + _str + std::string(" % ") + s.toString()
			+ std::string(" for type: ") + std::string(::cOperandType[_type]));
    return _cpu.createOperand(_type, convertFromPrec(c));
  }
  return _cpu.createOperand(s.getType(), convertFromPrec(c));
}
