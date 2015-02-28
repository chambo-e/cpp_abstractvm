//
// Memory.cpp for $ in /home/chambo_e/epitech/cpp_abstractvm
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.net>
//
// Started on  Thu Feb 19 02:38:28 2015 Emmanuel Chambon
// Last update Sat Feb 28 02:07:52 2015 Emmanuel Chambon
//

#include "Memory.hpp"

Memory::~Memory()
{
  while (_stack.size() > 0)
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

void		Memory::dump() const
{
  for (std::deque<IOperand *>::const_iterator i = _stack.begin(); i != _stack.end(); i++)
    std::cout << (*i)->toString() << std::endl;
}

IOperand	*Memory::pop()
{
  if (_stack.size() <= 0)
    throw VMException("Stack is empty");
  IOperand	*front = (*this)[0];
  _stack.pop_front();
  return front;
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
