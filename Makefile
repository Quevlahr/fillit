# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 15:48:47 by tbouder           #+#    #+#              #
#    Updated: 2016/01/22 19:33:13 by quroulon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	fillit

CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra

SRC 		= 	ft_launcher.c \
				ft_check_form.c \
				ft_check_content.c \
				ft_extract_form.c \
				ft_split.c \
				ft_resolv.c \
				ft_resolv_helper.c \
				ft_helpers.c

LIB			=	ft_lib.c ft_lib_two.c ft_lib_three.c

OBJ			=	$(SRC:.c=.o) $(LIB:.c=.o)
OBJ2		=	$(wildcard *.gch)

HEADER 		=	fillit.h

all: $(NAME)

.SILENT : $(NAME)
$(NAME):
	$(CC) $(CFLAGS) -c $(HEADER) $(SRC) $(LIB)
	$(CC) -o $(NAME) $(OBJ)

.SILENT : clean
clean:
	rm -f $(OBJ) $(OBJ2)

.SILENT : fclean
fclean: clean
	rm -f $(NAME)

re: fclean all
