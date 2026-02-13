# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coholbur <coholbur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 17:29:15 by coholbur          #+#    #+#              #
#    Updated: 2025/01/30 17:17:09 by coholbur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = pipex

INC = pipex.h

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDE = -I$(LIBFT_DIR) -I$(SRC_DIR)

SRC =      pipex.c\
	 utils.c\
	 utils1.c\
	 utils2.c\
	 

CC	:= cc

AR 	:= ar -crs

CFLAGS = -Wall -Wextra -Werror 

SRCO := $(SRC:.c=.o)

all:  $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(SRCO) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCO) ./libft/libft.a


$(SRCO): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(SRCO)


fclean: clean
	rm -f $(SRCO) $(NAME)
	make fclean -C $(LIBFT_DIR)
	

re: fclean all

lib:
	make -C $(LIBFT_DIR)


.PHONY: all clean fclean re lib
