//
// main.cpp for  in /home/chambo_e/epitech/cpp_abstractvm
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.net>
//
// Started on  Tue Feb 17 17:22:32 2015 Emmanuel Chambon
// Last update Wed Feb 18 01:06:08 2015 Emmanuel Chambon
//

#include <iostream>
#include "Chipset.hpp"

int main(int ac, char **av)
{
  Chipset	c(ac, av);

  try {
    c.read();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
