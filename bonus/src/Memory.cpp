//
// Memory.cpp for $ in /home/chambo_e/epitech/cpp_abstractvm
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.net>
//
// Started on  Thu Feb 19 02:38:28 2015 Emmanuel Chambon
// Last update Sun Mar  1 00:39:33 2015 Emmanuel Chambon
//

#include "Memory.hpp"
#include "cOperandType.hpp"

Memory::~Memory()
{
  while (size() > 0)
    del();
}

void		Memory::clear()
{
  while (size() > 0)
    del();
}

void		Memory::del()
{
  if (_stack.size() <= 0)
    throw VMException("Cannot pop on empty stack");
  IOperand	*front = (*this)[0];
  delete front;
  _stack.pop_front();
}

void		Memory::push(IOperand *op)
{
  _stack.push_front(op);
}

void                    Memory::dump() const
{
  std::cout << "+-----------------------------------+------------+------------+------------------------------------------------------------------------+" << std::endl;
  std::cout << "|               Value               |    Type    |    Size    |                                Binary                                  |" << std::endl;
  std::cout << "+-----------------------------------+------------+------------+------------------------------------------------------------------------+" << std::endl;

  for (size_t i = 0; i < size(); i++)
    desc((*this)[i]);
  std::cout << "+-----------------------------------+------------+------------+------------------------------------------------------------------------+" << std::endl;
}

void                    Memory::desc(IOperand *el) const
{
  std::stringstream     s;
  double                t;

  if (el == 0)
    el = (*this)[0];
  s << el->toString();
  s >> t;
  if (el->getType() == ::Float || el->getType() == ::Double) {
    std::cout << "| " << std::setw(33);
    std::cout << t << " | " << std::setw(10);
  }
  else {
    std::cout << "| " << std::setw(33);
    std::cout << el->toString() << " | " << std::setw(10);
  }
  std::cout << ::cOperandType[el->getType()] << " | " << std::setw(10);
  std::cout << ::sOperandType[el->getType()] << " | " << std::setw(70);
  if (el->getType() == ::Int8)
    std::cout << std::bitset<8>(t) << " |" << std::endl;
  else if (el->getType() == ::Int16)
    std::cout << std::bitset<16>(t) << " |" << std::endl;
  else if (el->getType() == ::Int32 || el->getType() == ::Float)
    std::cout << std::bitset<32>(t) << " |" << std::endl;
  else if (el->getType() == ::Int64 || el->getType() == ::Double)
    std::cout << std::bitset<64>(t) << " |" << std::endl;
}

IOperand	*Memory::pop()
{
  if (_stack.size() <= 0)
    throw VMException("Stack is empty");
  IOperand	*front = (*this)[0];
  _stack.pop_front();
  return front;
}

size_t		Memory::size() const
{
  return _stack.size();
}

IOperand	*Memory::operator[](size_t i) const
{
  if (_stack.size() < i)
    throw VMException("Stack is empty");
  return _stack[i];
}

Memory		&Memory::operator<<(IOperand *op)
{
  push(op);
  return *this;
}
