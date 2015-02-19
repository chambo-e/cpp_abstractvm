//
// Memory.cpp for $ in /home/chambo_e/epitech/cpp_abstractvm
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.net>
//
// Started on  Thu Feb 19 02:38:28 2015 Emmanuel Chambon
// Last update Thu Feb 19 04:49:28 2015 Emmanuel Chambon
//

#include "Memory.hpp"

void		Memory::pop()
{
  if (_stack.size() <= 0)
    throw VMException("Cannot pop on empty stack");
  IOperand *front = popless();
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

IOperand	*Memory::popless() const
{
  if (_stack.size() <= 0)
    throw VMException("Stack is empty");
  return _stack[0];
}

void		Memory::operator>>(IOperand *op)
{
  IOperand *front = popless();
  op = front;
  _stack.pop_front();
}
