//
// Chipset.hpp for  in /home/chambo_e/epitech/cpp_abstractvm
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.net>
//
// Started on  Tue Feb 17 17:22:29 2015 Emmanuel Chambon
// Last update Sat Feb 28 22:44:19 2015 Emmanuel Chambon
//

#ifndef CHIPSET_HPP_
# define CHIPSET_HPP_

# include <map>
# include <string>
# include <fstream>
# include <iostream>
# include <sstream>
# include <algorithm>
# include "Cpu.hpp"
# include "VMException.hpp"
# include "IOperand.hpp"
# include "Colors.hpp"

class Chipset
{
public:
  Chipset(int, char **);
  ~Chipset() {};

private:
  int							_cac;
  char							**_cav;
  bool							_exit;

private:
  typedef std::map<std::string, void(Cpu::*)()>		Instr;
  typedef std::map<std::string, void(Cpu::*)() const>	ConstInstr;
  typedef std::map<std::string, eOperandType>		Type;
  Instr							_instr;
  ConstInstr						_constInstr;
  Type							_type;
  Cpu							&_cpu;

public:
  void							read();

private:
  void							readFiles();
  void						       	parse(std::stringstream &);
  void							setInstr();
  std::string						epur_line(std::string &);
  std::string const 					getOperandValue(const std::string &) const;
  eOperandType						getOperandType(const std::string &) const;
};

#endif
