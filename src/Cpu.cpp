//
// Cpu.cpp for  in /home/chambo_e/epitech/cpp_abstractvm
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.net>
//
// Started on  Thu Feb 19 00:55:31 2015 Emmanuel Chambon
// Last update Fri Feb 20 01:04:19 2015 Emmanuel Chambon
//

#include "Cpu.hpp"
#include "cOperandType.hpp"
#include "Operand.hpp"

Cpu Cpu::_inst = Cpu();

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
    throw VMException(std::string(RED) + std::string("   Invalid type: ") + std::string(RESET) + std::string(::_cOperandType[top->getType()])
		      + std::string("\n\tOnly Int8 values can be printed"));
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
    throw VMException(std::string("   Assert not verified.\n\t") + std::string(::_cOperandType[t]) +
		      std::string(" .vs. ") + std::string(::_cOperandType[top->getType()]) + std::string("\n\t") +
		      value + std::string(" .vs. ") + top->toString());
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

IOperand	*Cpu::createInt8(const std::string &value)
{
  return new Operand<signed char>(::Int8, value);
}

IOperand	*Cpu::createInt16(const std::string &value)
{
  return new Operand<int16_t>(::Int16, value);
}

IOperand	*Cpu::createInt32(const std::string &value)
{
  return new Operand<int32_t>(::Int32, value);
}

IOperand	*Cpu::createInt64(const std::string &value)
{
  return new Operand<int64_t>(::Int64, value);
}

IOperand	*Cpu::createFloat(const std::string &value)
{
  return new Operand<float>(::Float, value);
}

IOperand	*Cpu::createDouble(const std::string &value)
{
  return new Operand<double>(::Double, value);
}

IOperand	*Cpu::createOperand(eOperandType t, const std::string &value)
{
  if (t == ::Int8)
    return createInt8(value);
  else if (t == ::Int16)
    return createInt16(value);
  else if (t == ::Int32)
    return createInt32(value);
  else if (t == ::Int64)
    return createInt64(value);
  else if (t == ::Float)
    return createFloat(value);
  else if (t == ::Double)
    return createDouble(value);
  return 0;
}
