//
// Memory.hpp for  in /home/chambo_e/epitech/cpp_abstractvm/include
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.net>
//
// Started on  Thu Feb 19 02:10:53 2015 Emmanuel Chambon
// Last update Sun Mar  1 00:20:52 2015 Emmanuel Chambon
//

#ifndef MEMORY_HPP_H
# define MEMORY_HPP_H

# include <deque>
# include <iostream>
# include <sstream>
# include <iomanip>
# include <bitset>
# include <cstring>
# include "IOperand.hpp"
# include "VMException.hpp"

class Memory
{
public:
  Memory() {};
  ~Memory();

public:
  IOperand			*pop();
  size_t			size() const;
  void				push(IOperand *);
  void				dump() const;
  void				del();
  void				clear();
  IOperand			*operator[](size_t) const;
  Memory			&operator<<(IOperand *);

private:
  void				desc(IOperand * = 0) const;

private:
  std::deque<IOperand *>	_stack;
};

#endif
