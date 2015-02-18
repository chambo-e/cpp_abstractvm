##
## Makefile for  in /home/chambo_e/epitech/cpp_abstractvm
## 
## Made by Emmanuel Chambon
## Login   <chambo_e@epitech.net>
## 
## Started on  Tue Feb 17 22:06:35 2015 Emmanuel Chambon
## Last update Wed Feb 18 00:55:00 2015 Emmanuel Chambon
##

NAME		=	avm

CXX		=	g++

INCDIR		=	include/

CXXFLAGS	=	-Wall -Wextra -I$(INCDIR)

RM		=	rm -rf

SRCDIR		=	src

SRC		=	$(SRCDIR)/main.cpp		\
			$(SRCDIR)/VMException.cpp	\
			$(SRCDIR)/Chipset.cpp

OBJ		=	$(SRC:.cpp=.o)


$(NAME)		:	$(OBJ)
			$(CXX) $(OBJ) -o $(NAME)

all		:	$(NAME)

clean		:
			$(RM) $(OBJ)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all