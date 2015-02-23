//
// Cpu.hpp for  in /home/chambo_e/epitech/cpp_abstractvm
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.net>
//
// Started on  Wed Feb 18 00:09:46 2015 Emmanuel Chambon
// Last update Mon Feb 23 18:12:14 2015 Emmanuel Chambon
//

#ifndef CPU_HPP_
# define CPU_HPP_

# include <stdint.h>
# include <iostream>
# include <sstream>
# include <map>
# include "Colors.hpp"
# include "VMException.hpp"
# include "Memory.hpp"

class Cpu
{
private:
  Cpu();
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

public:
  IOperand		*createOperand(eOperandType, const std::string &);
private:
  IOperand		*createInt8(const std::string &);
  IOperand		*createInt16(const std::string &);
  IOperand		*createInt32(const std::string &);
  IOperand		*createInt64(const std::string &);
  IOperand		*createFloat(const std::string &);
  IOperand		*createDouble(const std::string &);

private:
  typedef std::map<eOperandType, IOperand *(Cpu::*)(const std::string &)> Op;
  Op			_operand;
  static Cpu		_inst;
  Memory		_ram;
};

#endif
