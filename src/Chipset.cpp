//
// Chipset.cpp for  in /home/chambo_e/epitech/cpp_abstractvm
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.net>
//
// Started on  Tue Feb 17 17:32:28 2015 Emmanuel Chambon
// Last update Thu Feb 19 00:11:21 2015 Emmanuel Chambon
//

#include "Chipset.hpp"

Chipset::Chipset(int ac, char **av) : _cac(ac), _cav(av), _exit(false)
{

}

Chipset::~Chipset()
{
}

void		Chipset::read()
{
  std::stringstream	stream;
  std::string		line;

  if (_cac == 1) {
    while (std::getline(std::cin, line)) {
      if (line == ";;")
	break;
      if ((line = epur_line(line)).empty() == false)
	stream << line << "\n";
    }
    if (line != ";;")
      throw VMException("\";;\" code is missing.");
    if (_exit == false)
      throw VMException("\"exit\" instruction is missing.");
    try {
      parse(stream);
    } catch (std::exception &e) {
      throw VMException("std::cin" + std::string(e.what()));
    }
  } else {
    for (int i = 1; _cav[i] ; i++) {
      std::fstream	file;

      if (file.is_open())
	while (std::getline(file, line) && _exit == false) {
	  if ((line = epur_line(line)).empty() == false)
	    stream << line << "\n";
	}
      else
	throw VMException(std::string("avm: error: ") + std::string(_cav[i]) + std::string(": No such file or directory"));
      if (_exit == false)
	throw VMException("\"exit\" instruction is missing.");
      try {
	parse(stream);
      } catch (std::exception &e) {
	throw VMException(std::string(_cav[i]) + std::string(e.what()));
      }
    }
  }
}

std::string	 Chipset::epur_line(std::string stream)
{
  size_t pos;

  while ((pos = stream.find(";")) != std::string::npos)
    stream.erase(pos, stream.length() - pos);

  if (stream == "exit") {
    _exit = true;
    return std::string();
  }

  return stream;
}

void		Chipset::setInstr()
{
  _instr.insert(Instr::value_type("pop", &Cpu::pop));
  _instr.insert(Instr::value_type("add", &Cpu::add));
  _instr.insert(Instr::value_type("sub", &Cpu::sub));
  _instr.insert(Instr::value_type("mul", &Cpu::mul));
  _instr.insert(Instr::value_type("div", &Cpu::div));
  _instr.insert(Instr::value_type("mod", &Cpu::mod));
  _constInstr.insert(ConstInstr::value_type("dump", &Cpu::dump));
  _constInstr.insert(ConstInstr::value_type("print", &Cpu::print));
  _type.insert(Type::value_type("int8", ::Int8));
  _type.insert(Type::value_type("int16", ::Int16));
  _type.insert(Type::value_type("int32", ::Int32));
  _type.insert(Type::value_type("float", ::Float));
  _type.insert(Type::value_type("double", ::Double));
}

eOperandType	Chipset::getOperandType(std::string value)
{
  size_t	pos;
  size_t	pos2;

  if (((pos = value.find("(")) == std::string::npos)
      || ((pos2 = value.find(")")) == std::string::npos)
      || pos > pos2)
    throw VMException("VALUE syntax error");
  value.erase(pos, value.length() - pos);
  Type::iterator i = _type.find(value);
  if (i != _type.end())
    return i->second;
  throw VMException("Unknow type");
}

std::string	Chipset::getOperandValue(std::string value)
{
  size_t	pos;
  size_t	pos2;
  std::string	buff;

  if (((pos = value.find("(")) == std::string::npos)
      || ((pos2 = value.find(")")) == std::string::npos)
      || pos > pos2)
    throw VMException("VALUE syntax error");
  pos++;
  buff = value.substr(pos, pos2 - pos);
  if (buff.empty() == false)
    return (buff);
  throw VMException("Invalid Value");
}

void		Chipset::parse(std::stringstream &input)
{
  std::stringstream	error;
  std::string		line;
  size_t		ln = 1;

  setInstr();

  while (getline(input, line)) {
    std::istringstream	line_stream(line);
    std::string		args;
    std::string		instr;

    if (line_stream >> instr >> std::ws) {
      line_stream >> args;
      std::transform(instr.begin(), instr.end(), instr.begin(), ::tolower);
      std::transform(args.begin(), args.end(), args.begin(), ::tolower);
      if (args.empty() == false) {
	try {
	  if (instr == "push")
	    _cpu.push(getOperandType(args), getOperandValue(args));
	  else if (instr == "assert")
	    _cpu.assert(getOperandType(args), getOperandValue(args));
	} catch (std::exception &e) {
	  error << ":" << ln << ": " << e.what() << std::endl << "~>   " << line;
	  throw VMException(error.str());
	}
      }
      else {
	Instr::iterator i = _instr.find(instr);
	if (i != _instr.end()) {
	  void(Cpu::*ptr)() = i->second;
	  (_cpu.*ptr)();
	}
	else {
	  ConstInstr::iterator i = _constInstr.find(instr);
	  if (i != _constInstr.end()) {
	    void(Cpu::*ptr)() const = i->second;
	    (_cpu.*ptr)();
	  }
	  else {
	    error << ":" << ln << ": Unknow instruction type" << std::endl << "~>   " << line_stream;
	    throw VMException(error.str());
	  }
	}
      }
    }
    ln++;
  }
}
