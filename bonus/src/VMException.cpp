//
// VMException.cpp for  in /home/chambo_e/epitech/cpp_abstractvm
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.net>
//
// Started on  Wed Feb 18 00:46:34 2015 Emmanuel Chambon
// Last update Thu Feb 19 03:10:49 2015 Emmanuel Chambon
//

#include "VMException.hpp"
#include <iostream>

VMException::VMException(std::string const &e) : _e(e)
{

}

const char		*VMException::what() const throw()
{
  return _e.c_str();
}
