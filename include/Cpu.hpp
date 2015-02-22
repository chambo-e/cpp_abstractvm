//
// Cpu.hpp for  in /home/chambo_e/epitech/cpp_abstractvm
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.net>
//
// Started on  Wed Feb 18 00:09:46 2015 Emmanuel Chambon
// Last update Sun Feb 22 01:11:43 2015 Emmanuel Chambon
//

#ifndef CPU_HPP_
# define CPU_HPP_

# include <stdint.h>
# include <iostream>
# include <sstream>
# include "Colors.hpp"
# include "VMException.hpp"
# include "Memory.hpp"

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

public:
  IOperand		*createOperand(eOperandType, const std::string &);
  IOperand		*createInt8(const std::string &);
  IOperand		*createInt16(const std::string &);
  IOperand		*createInt32(const std::string &);
  IOperand		*createInt64(const std::string &);
  IOperand		*createFloat(const std::string &);
  IOperand		*createDouble(const std::string &);

private:
  static Cpu		_inst;
  Memory		_ram;
};

#endif
