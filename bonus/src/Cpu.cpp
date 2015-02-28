//
// Cpu.cpp for  in /home/chambo_e/epitech/cpp_abstractvm
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.net>
//
// Started on  Thu Feb 19 00:55:31 2015 Emmanuel Chambon
// Last update Sat Feb 28 02:08:24 2015 Emmanuel Chambon
//

#include "Cpu.hpp"
#include "cOperandType.hpp"
#include "Operand.hpp"
#include <cstdio>

Cpu			Cpu::_inst = Cpu();

Cpu::Cpu()
{
  _operand.insert(Op::value_type(::Int8, &Cpu::createInt8));
  _operand.insert(Op::value_type(::Int16, &Cpu::createInt16));
  _operand.insert(Op::value_type(::Int32, &Cpu::createInt32));
  _operand.insert(Op::value_type(::Int64, &Cpu::createInt64));
  _operand.insert(Op::value_type(::Float, &Cpu::createFloat));
  _operand.insert(Op::value_type(::Double, &Cpu::createDouble));
  _operand.insert(Op::value_type(::Auto, &Cpu::createAuto));
}

Cpu			&Cpu::operator=(const Cpu &cpu)
{
  return cpu.getInstance();
}

void			Cpu::pop()
{
  _ram.del();
}

void			Cpu::dump() const
{
  _ram.dump();
}
void			Cpu::print() const
{
  IOperand		*top = _ram[0];
  std::stringstream	out(top->toString());
  int			c;

  if (top->getType() != ::Int8)
    throw VMException(std::string("Invalid type: ") + std::string(::cOperandType[top->getType()])
		      + std::string("\n\tOnly Int8 values can be printed"));
  out >> c;
  std::cout << static_cast<char>(c) << std::endl;
}

void			Cpu::push(eOperandType t, const std::string &value)
{
  _ram.push(createOperand(t, value));
}

void			Cpu::assert(eOperandType t, const std::string &value)
{
  IOperand		*top = _ram[0];

  if (top->toString() != value
      || top->getType() != t)
    throw VMException(std::string("Assert not verified.\n\t") + std::string(::cOperandType[t]) +
		      std::string(" .vs. ") + std::string(::cOperandType[top->getType()]) + std::string("\n\t") +
		      value + std::string(" .vs. ") + top->toString());
}

void			Cpu::add()
{
  IOperand		*a;
  IOperand		*b;
  IOperand		*c;

  a = _ram.pop();
  b = _ram.pop();
  c = (*a) + (*b);
  _ram << c;
  delete a;
  delete b;
}

void			Cpu::sub()
{
  IOperand		*a;
  IOperand		*b;
  IOperand		*c;

  a = _ram.pop();
  b = _ram.pop();
  c = (*a) - (*b);
  _ram << c;
  delete a;
  delete b;
}

void			Cpu::mul()
{
  IOperand		*a;
  IOperand		*b;
  IOperand		*c;

  a = _ram.pop();
  b = _ram.pop();
  c = (*a) * (*b);
  _ram << c;
  delete a;
  delete b;
}

void			Cpu::div()
{
  IOperand		*a;
  IOperand		*b;
  IOperand		*c;

  a = _ram.pop();
  b = _ram.pop();
  c = (*a) / (*b);
  _ram << c;
  delete a;
  delete b;
}

void			Cpu::mod()
{
  IOperand		*a;
  IOperand		*b;
  IOperand		*c;

  a = _ram.pop();
  b = _ram.pop();
  c = (*a) % (*b);
  _ram << c;
  delete a;
  delete b;
}

IOperand		*Cpu::createInt8(const std::string &value)
{
  return new Operand<signed char>(::Int8, value);
}

IOperand		*Cpu::createInt16(const std::string &value)
{
  return new Operand<int16_t>(::Int16, value);
}

IOperand		*Cpu::createInt32(const std::string &value)
{
  return new Operand<int32_t>(::Int32, value);
}

IOperand		*Cpu::createInt64(const std::string &value)
{
  return new Operand<int64_t>(::Int64, value);
}

IOperand		*Cpu::createFloat(const std::string &value)
{
  return new Operand<float>(::Float, value);
}

IOperand		*Cpu::createDouble(const std::string &value)
{
  return new Operand<double>(::Double, value);
}

IOperand		*Cpu::createAuto(const std::string &value)
{
  std::stringstream             s(value);
  double                        x;

  s >> x;
  if (value.find(".") != std::string::npos) {
    if (((x >= -(std::numeric_limits<float>::max())) && x <= std::numeric_limits<float>::max()))
      return createFloat(value);
    else if (((x >= -(std::numeric_limits<double>::max())) && x <= std::numeric_limits<double>::max()))
      return createDouble(value);
  }
  if ((x >= std::numeric_limits<int8_t>::min() && x <= std::numeric_limits<int8_t>::max()))
    return createInt8(value);
  else if ((x >= std::numeric_limits<int16_t>::min() && x <= std::numeric_limits<int16_t>::max()))
    return createInt16(value);
  else if ((x >= std::numeric_limits<int32_t>::min() && x <= std::numeric_limits<int32_t>::max()))
    return createInt32(value);
  else if ((x >= std::numeric_limits<int64_t>::min() && x <= std::numeric_limits<int64_t>::max()))
    return createInt64(value);
  else if (((x >= -(std::numeric_limits<float>::max())) && x <= std::numeric_limits<float>::max()))
    return createFloat(value);
  else if (((x >= -(std::numeric_limits<double>::max())) && x <= std::numeric_limits<double>::max()))
    return createDouble(value);
  throw VMException(std::string("Unrecognized value: ") + value);
}

IOperand		*Cpu::createOperand(eOperandType t, const std::string &value)
{
  IOperand *(Cpu::*ptr)(const std::string &) = _operand[t];
  return ((this->*ptr)(value));
}
