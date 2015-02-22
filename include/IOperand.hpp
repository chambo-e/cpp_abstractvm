//
// IOperand.hpp for  in /home/chambo_e/epitech/cpp_abstractvm
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.net>
//
// Started on  Wed Feb 18 18:50:23 2015 Emmanuel Chambon
// Last update Sun Feb 22 01:11:27 2015 Emmanuel Chambon
//

#ifndef IOPERAND_HPP_
# define IOPERAND_HPP_

#include <string>
#include "eOperandType.hpp"

class IOperand
{
public:
  virtual std::string const	&toString() const = 0;
  virtual int			getPrecision() const = 0;
  virtual eOperandType		getType() const = 0;

  virtual IOperand		*operator+(const IOperand &) const = 0;
  virtual IOperand		*operator-(const IOperand &) const = 0;
  virtual IOperand		*operator*(const IOperand &) const = 0;
  virtual IOperand		*operator/(const IOperand &) const = 0;
  virtual IOperand		*operator%(const IOperand &) const = 0;

  virtual ~IOperand() {}
};

#endif
