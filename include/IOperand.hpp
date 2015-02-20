//
// IOperand.hpp for  in /home/chambo_e/epitech/cpp_abstractvm
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.net>
//
// Started on  Wed Feb 18 18:50:23 2015 Emmanuel Chambon
// Last update Thu Feb 19 19:48:33 2015 Emmanuel Chambon
//

#ifndef IOPERAND_HPP_
# define IOPERAND_HPP_

#include <string>
#include "eOperandType.hpp"

class IOperand
{
public:

  virtual std::string const & toString() const = 0; // Renvoie une string reprensentant l’instance

  virtual int getPrecision() const = 0; // Renvoie la precision du type de l’instance
  virtual eOperandType getType() const = 0; // Renvoie le type de l’instance. Voir plus bas

  virtual IOperand * operator+(const IOperand &rhs) const = 0; // Somme
  virtual IOperand * operator-(const IOperand &rhs) const = 0; // Difference
  virtual IOperand * operator*(const IOperand &rhs) const = 0; // Produit
  virtual IOperand * operator/(const IOperand &rhs) const = 0; // Quotient
  virtual IOperand * operator%(const IOperand &rhs) const = 0; // Modulo

  virtual ~IOperand() {}
};

#endif
