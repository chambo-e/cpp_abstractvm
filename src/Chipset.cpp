//
// Chipset.cpp for  in /home/chambo_e/epitech/cpp_abstractvm
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.net>
//
// Started on  Tue Feb 17 17:32:28 2015 Emmanuel Chambon
// Last update Sun Mar  1 19:52:15 2015 Emmanuel Chambon
//

#include "Chipset.hpp"

Chipset::Chipset(int ac, char **av) : _cac(ac), _cav(av),_cpu(Cpu::getInstance())
{}

void			Chipset::readFiles()
{
  std::stringstream	stream;
  std::string		line;

  for (int i = 1; _cav[i]; i++) {
    try {
      std::fstream	file;
      std::string	fl(_cav[i]);

      if (fl.substr(fl.find_last_of(".") + 1) != "avm")
	throw VMException("Not an avm file");
      _exit = false;
      file.open(_cav[i]);
      if (file.is_open() == true) {
	while (std::getline(file, line) && _exit == false) {
	  stream << epur_line(line) << "\n";
	}
      } else throw VMException("No such file or directory");
      if (_exit == false) throw VMException("\"exit\" instruction is missing.");
      parse(stream);
      stream.clear();
      stream.str(std::string());
      _cpu.clear();
    } catch (std::exception &e) {
      if (_cav[i + 1]) {
	std::cout << std::string(_cav[i]) << ": "<< e.what() << std::endl;
	stream.clear();
	stream.str(std::string());
	_cpu.clear();
      } else throw VMException(std::string(_cav[i]) + ": "  + std::string(e.what()));
    }
  }
}

void			Chipset::read()
{
  std::stringstream	stream;
  std::string		line;

  if (_cac == 1) {
    try {
      while (std::getline(std::cin, line)) {
	if (line == ";;") break;
	stream << epur_line(line) << "\n";
      }
      if (line != ";;") throw VMException("\";;\" code is missing.");
      if (_exit == false) throw VMException("\"exit\" instruction is missing.");
      parse(stream);
    } catch (std::exception &e) {
      throw VMException("std::cin: " + std::string(e.what()));
    }
  } else
    readFiles();
}

std::string		Chipset::epur_line(std::string &stream)
{
  size_t		pos;

  while ((pos = stream.find(";")) != std::string::npos)
    stream.erase(pos, stream.length() - pos);

  if (stream == "exit") {
    _exit = true;
    return std::string();
  }

  return stream;
}

void			Chipset::setInstr()
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

eOperandType		Chipset::getOperandType(const std::string &value) const
{
  size_t		pos;
  size_t		pos2;
  std::string		buff(value);

  if (((pos = buff.find("(")) == std::string::npos)
      || ((pos2 = buff.find(")")) == std::string::npos)
      || pos > pos2)
    throw VMException("   TYPE syntax error");
  buff.erase(pos, buff.length() - pos);
  Type::const_iterator i = _type.find(buff);
  if (i != _type.end())
    return i->second;
  throw VMException("   Unknow TYPE");
}

bool			Chipset::isNumeric(const std::string &str) const
{
  std::string		base("0123456789.");
  return (str.find_first_not_of("0123456789.", 11) == std::string::npos);
}

std::string const	Chipset::getOperandValue(const std::string &value) const
{
  size_t		pos;
  size_t		pos2;
  std::string		buff;

  if (((pos = value.find("(")) == std::string::npos)
      || ((pos2 = value.find(")")) == std::string::npos)
      || pos > pos2)
    throw VMException("   VALUE syntax error");
  pos++;
  buff = value.substr(pos, pos2 - pos);
  if (buff.empty() == false && isNumeric(buff) == true)
    return (buff);
  throw VMException("   Invalid VALUE");
}

void			Chipset::parse(std::stringstream &input)
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
	  if (instr == "push") _cpu.push(getOperandType(args), getOperandValue(args));
	  else if (instr == "assert") _cpu.assert(getOperandType(args), getOperandValue(args));
	  else throw VMException("   Unknow instruction type");
	} catch (std::exception &e) {
	  error << ln << ": " << "\t\"" << RED << line << RESET << "\"" << std::endl << e.what();
	  throw VMException(error.str());
	}
      }
      else {
	Instr::const_iterator	i = _instr.find(instr);
	try {
	  if (i != _instr.end()) {
	    void	(Cpu::*ptr)() = i->second;
	    (_cpu.*ptr)();
	  }
	  else {
	    ConstInstr::const_iterator i = _constInstr.find(instr);
	    if (i != _constInstr.end()) {
	      void	(Cpu::*ptr)() const = i->second;
	      (_cpu.*ptr)();
	    }
	    else throw VMException("   Unknow instruction type");
	  }
	} catch (std::exception &e) {
	  error << ln << ": " << "\t\"" << RED << line << RESET << "\"" << std::endl << "   " << e.what();
	  throw VMException(error.str());
	}

      }
    }
    ln++;
  }
}
