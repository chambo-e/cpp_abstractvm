//
// Chipset.cpp for  in /home/chambo_e/epitech/cpp_abstractvm
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.net>
//
// Started on  Tue Feb 17 17:32:28 2015 Emmanuel Chambon
// Last update Wed Feb 18 01:12:13 2015 Emmanuel Chambon
//

#include "Chipset.hpp"

Chipset::Chipset(int ac, char **av) : _cac(ac), _cav(av), _exit(false)
{

}

Chipset::~Chipset()
{
  // if (_instr)
  //   delete _instr;
  // if (_constInstr)
  //   delete _constInstr;
}

void		Chipset::read()
{
  std::stringstream	stream;
  std::string		line;

  if (_cac == 1) {
    while (std::getline(std::cin, line) && _exit == false) {
      if (line == ";;")
	break;
      if ((line = epur_line(line)).empty() == false)
	stream << line << "\n";
    }
  } else {
    for (int i = 1; _cav[i] ; i++) {
      std::fstream	file;

      file.open(_cav[i]);
      if (file.is_open())
	while (std::getline(file, line) && _exit == false)
	  if ((line = epur_line(line)).empty() == false)
	    stream << line << "\n";
    }
  }
  if (_exit == false)
    throw VMException("\"exit\" instruction is missing.");
  parse(stream);
}

std::string	 Chipset::epur_line(std::string stream)
{
  size_t pos;

  while ((pos = stream.find(";")) != std::string::npos)
    stream.erase(pos, stream.length() - pos);

  if (stream == "exit")
    _exit = true;

  return stream;
}

void		Chipset::setInstr()
{
  // _instr.insert(_instr::value_type("pop", &Cpu::pop));
  // _instr.insert(_instr::value_type("add", &Cpu::add));
  // _instr.insert(_instr::value_type("sub", &Cpu::sub));
  // _instr.insert(_instr::value_type("mul", &Cpu::mul));
  // _instr.insert(_instr::value_type("div", &Cpu::div));
  // _instr.insert(_instr::value_type("mod", &Cpu::mod));
  // _constInstr.insert(_instr::value_type("dump", &Cpu::dump));
  // _constInstr.insert(_instr::value_type("print", &Cpu::print));
}

void		Chipset::parse(std::stringstream &input)
{
  std::string		line;

  setInstr();

  while (getline(input, line)) {
    std::istringstream	line_stream(line);
    std::string		args;
    std::string		instr;

    if (line_stream >> instr >> std::ws) {
      line_stream >> args;
      std::cout << instr << std::endl;
      if (args.empty() == false)
	std::cout << args << std::endl;
    }
  }
}
