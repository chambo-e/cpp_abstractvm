//
// Chipset.hpp for  in /home/chambo_e/epitech/cpp_abstractvm
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.net>
//
// Started on  Tue Feb 17 17:22:29 2015 Emmanuel Chambon
// Last update Wed Feb 18 20:58:20 2015 Emmanuel Chambon
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

class Chipset
{
public:
  Chipset(int, char **);
  ~Chipset();

private:
  int							_cac;
  char							**_cav;
  Cpu							_cpu;
  bool							_exit;

private:
  typedef std::map<std::string, void(Cpu::*)()>		Instr;
  typedef std::map<std::string, void(Cpu::*)() const>	ConstInstr;
  typedef std::map<std::string, eOperandType>		Type;
  Instr							_instr;
  ConstInstr						_constInstr;
  Type							_type;

public:
  void						read();

private:
  std::string					epur_line(std::string);
  void					       	parse(std::stringstream &);
  void						setInstr();
  std::string					getOperandValue(std::string);
  eOperandType					getOperandType(std::string);
};

#endif
