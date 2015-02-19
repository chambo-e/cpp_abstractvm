//
// Cpu.hpp for  in /home/chambo_e/epitech/cpp_abstractvm
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.net>
//
// Started on  Wed Feb 18 00:09:46 2015 Emmanuel Chambon
// Last update Thu Feb 19 05:10:46 2015 Emmanuel Chambon
//

#ifndef CPU_HPP_
# define CPU_HPP_

#include "IOperand.hpp"
#include "VMException.hpp"
#include "Memory.hpp"
#include "Operand.hpp"
#include <stdint.h>
#include <iostream>
#include <sstream>

class Cpu
{
private:
  Cpu() {};
  ~Cpu() {};
  Cpu &operator=(const Cpu &);

public:
  static Cpu		&getInstance() {return _inst;};

public:
  void			add();
  void			sub();
  void			mul();
  void			div();
  void			mod();
  void			pop();
  void			dump() const;
  void			print() const;
  void			push(const eOperandType, const std::string &);
  void			assert(const eOperandType, const std::string &);

private:
  IOperand		*createOperand(eOperandType, const std::string &);

private:
  static Cpu		_inst;
  Memory		_ram;
};

#endif
