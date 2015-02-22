//
// VMException.hpp for  in /home/chambo_e/epitech/cpp_abstractvm
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.net>
//
// Started on  Wed Feb 18 00:49:54 2015 Emmanuel Chambon
// Last update Sun Feb 22 01:12:15 2015 Emmanuel Chambon
//

#ifndef VMEXCEPTION_HPP_
# define VMEXCEPTION_HPP_

# include <exception>
# include <string>

class VMException : public std::exception
{
public:
  VMException(std::string const & = "Critical Error");
  virtual ~VMException() throw() {};

public:
  virtual const char*		what() const throw();

private:
  std::string			_e;
};

#endif
