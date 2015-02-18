//
// Cpu.hpp for  in /home/chambo_e/epitech/cpp_abstractvm
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.net>
//
// Started on  Wed Feb 18 00:09:46 2015 Emmanuel Chambon
// Last update Wed Feb 18 23:51:55 2015 Emmanuel Chambon
//

#ifndef CPU_HPP_
# define CPU_HPP_

#include "IOperand.hpp"
#include <iostream>

class Cpu
{
public:
  Cpu() {};
  ~Cpu() {};

public:
  void		pop() {};
  void		add() {};
  void		sub() {};
  void		mul() {};
  void		div() {};
  void		mod() {};
  void		dump() const {};
  void		print() const {};
  void		push(eOperandType, std::string) {};
  void		assert(eOperandType, std::string) {};
};

#endif
