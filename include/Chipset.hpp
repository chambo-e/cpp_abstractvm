//
// Chipset.hpp for  in /home/chambo_e/epitech/cpp_abstractvm
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.net>
//
// Started on  Tue Feb 17 17:22:29 2015 Emmanuel Chambon
// Last update Wed Feb 18 00:59:10 2015 Emmanuel Chambon
//

#ifndef CHIPSET_HPP_
# define CHIPSET_HPP_

# include <map>
# include <string>
# include <fstream>
# include <iostream>
# include <sstream>
# include "Cpu.hpp"
# include "VMException.hpp"

class Chipset
{
public:
  Chipset(int, char **);
  ~Chipset();

private:
  int						_cac;
  char						**_cav;
  Cpu						_cpu;
  bool						_exit;

private:
  // std::map<std::string, void(Cpu::*)()>		_instr;
  // std::map<std::string, void(Cpu::*)() const>	_constInstr;

public:
  void						read();

private:
  std::string					epur_line(std::string);
  void					       	parse(std::stringstream &);
  void						setInstr();
};

#endif
