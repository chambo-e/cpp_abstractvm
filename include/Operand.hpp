//
// Operand.hpp for  in /home/chambo_e/epitech/cpp_abstractvm
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.net>
//
// Started on  Thu Feb 19 04:30:49 2015 Emmanuel Chambon
// Last update Sat Feb 21 23:39:35 2015 Emmanuel Chambon
//

#ifndef OPERAND_HPP_
# define OPERAND_HPP_

#include "IOperand.hpp"
#include "eOperandType.hpp"
#include "Cpu.hpp"
#include <sstream>
#include <math.h>
#include <map>
#include <string>
#include <limits>

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
  void			initOperand();

private:
  typedef std::map<eOperandType, IOperand *(Cpu::*)(const std::string &)>	Op;
  Op									 _operand;
  eOperandType								_type;
  std::string								_str;
  Cpu									&_cpu;
  T									_value;
};

#endif
