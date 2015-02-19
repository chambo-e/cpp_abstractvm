//
// Cpu.cpp for  in /home/chambo_e/epitech/cpp_abstractvm
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.net>
//
// Started on  Thu Feb 19 00:55:31 2015 Emmanuel Chambon
// Last update Thu Feb 19 05:09:03 2015 Emmanuel Chambon
//

#include "Cpu.hpp"

Cpu Cpu::_inst = Cpu();

static const char *_cOperandType[6] = {
  "Int8",
  "Int16",
  "Int32",
  "Int64",
  "Float",
  "Double"
};

Cpu		&Cpu::operator=(const Cpu &cpu)
{
  return cpu.getInstance();
}

void		Cpu::pop()
{
  _ram.pop();
}

void		Cpu::dump() const
{
  _ram.dump();
}

void		Cpu::print() const
{
  IOperand		*top = _ram.popless();
  std::stringstream	out(top->toString());
  char			c;

  if (top->getType() != ::Int8)
    throw VMException(std::string("Invalid type : ") + std::string(::_cOperandType[top->getType()])
		      + std::string("Only Int8 values can be printed"));
  out >> c;
  std::cout << c << std::endl;
}

void		Cpu::push(eOperandType t, const std::string &value)
{
  _ram.push(createOperand(t, value));
}

void		Cpu::assert(eOperandType t, const std::string &value)
{
  IOperand	*top = _ram.popless();

  if (top->toString() != value
      || top->getType() != t)
    throw VMException(std::string("Assert not verified.\n   ") + std::string(::_cOperandType[t]) +
		      std::string(" .vs. ") + std::string(::_cOperandType[top->getType()]) + std::string("\n   ") +
		      value + std::string(" .vs .") + top->toString());
  std::cout << top->toString() << std::endl;
}

void		Cpu::add()
{

}

void		Cpu::sub()
{

}

void		Cpu::mul()
{

}

void		Cpu::div()
{

}

void		Cpu::mod()
{

}

IOperand	*Cpu::createOperand(eOperandType t, const std::string &value)
{
  if (t == ::Int8)
    return new Operand<int8_t>(value, t);
  else if (t == ::Int16)
    return new Operand<int16_t>(value, t);
  else if (t == ::Int32)
    return new Operand<int32_t>(value, t);
  else if (t == ::Int64)
    return new Operand<int64_t>(value, t);
  else if (t == ::Float)
    return new Operand<float>(value, t);
  else if (t == ::Double)
    return new Operand<double>(value, t);
  return 0;
}
