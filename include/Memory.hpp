//
// Memory.hpp for  in /home/chambo_e/epitech/cpp_abstractvm/include
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.net>
//
// Started on  Thu Feb 19 02:10:53 2015 Emmanuel Chambon
// Last update Sat Feb 21 22:29:43 2015 Emmanuel Chambon
//

#ifndef MEMORY_HPP_H
# define MEMORY_HPP_H

#include <deque>
#include <iostream>
#include "IOperand.hpp"
#include "VMException.hpp"

class Memory
{
public:
  Memory() {};
  ~Memory() {};

public:
  IOperand			*pop();
  void				push(IOperand *);
  void				dump() const;
  void				popless();
  void				del();
  IOperand			*operator[](size_t) const;
  Memory			&operator<<(IOperand *);

private:
  std::deque<IOperand *>	_stack;
};

#endif
