//
// cOperandType.hpp for  in /home/chambo_e/epitech/cpp_abstractvm
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.net>
//
// Started on  Thu Feb 19 19:46:58 2015 Emmanuel Chambon
// Last update Fri Feb 27 15:58:17 2015 Emmanuel Chambon
//

#ifndef COPERANDTYPE_HPP_
# define COPERANDTYPE_HPP_

#include <stdint.h>

static const char *cOperandType[6] = {
  "Int8",
  "Int16",
  "Int32",
  "Int64",
  "Float",
  "Double"
};

static const size_t sOperandType[6] = {
  sizeof(int8_t),
  sizeof(int16_t),
  sizeof(int32_t),
  sizeof(int64_t),
  sizeof(float),
  sizeof(double)
};

#endif
