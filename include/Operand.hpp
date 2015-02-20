//
// Operand.hpp for  in /home/chambo_e/epitech/cpp_abstractvm
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.net>
//
// Started on  Thu Feb 19 04:30:49 2015 Emmanuel Chambon
// Last update Fri Feb 20 00:31:54 2015 Emmanuel Chambon
//

#ifndef OPERAND_HPP_
# define OPERAND_HPP_

#include "IOperand.hpp"
#include "eOperandType.hpp"
#include "Cpu.hpp"
#include <sstream>

template <typename T>
class Operand : public IOperand
{
public:
  explicit Operand(eOperandType, const std::string &);
  ~Operand() {};

public:
  std::string const	&toString() const;
  int			getPrecision() const;
  eOperandType		getType() const;

  IOperand		*operator+(const IOperand &) const;
  IOperand		*operator-(const IOperand &) const;
  IOperand		*operator*(const IOperand &) const;
  IOperand		*operator/(const IOperand &) const;
  IOperand		*operator%(const IOperand &) const;

private:
  eOperandType		_type;
  std::string		_str;
  Cpu			&_cpu;
  T			_value;
};

#endif
