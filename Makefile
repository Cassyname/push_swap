# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgeoffra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/28 12:39:34 by cgeoffra          #+#    #+#              #
#    Updated: 2023/10/03 15:17:12 by cgeoffra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAGS = -Wall -Wextra -Werror -g 

SRCS_FOLDER = src/
SRCS = main.c utils.c radix.c push.c reverse.c rotate.c sorting2.c sorting.c swap.c
OBJS_MENDA = $(addprefix $(SRCS_FOLDER), $(SRCS:%.c=%.o))

LIBFT_PATH = libft/
LIBFT_LIB = $(LIBFT_PATH)libft.a
PRINTF_PATH = printf/
PRINTF_LIB = $(PRINTF_PATH)libftprintf.a

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@

$(NAME):	$(OBJS_MENDA)
	@make -C $(LIBFT_PATH) --no-print-directory -s
	@make -C $(PRINTF_PATH) --no-print-directory -s
	@gcc $(FLAGS) $(OBJS_MENDA) $(PRINTF_LIB) $(LIBFT_LIB) -o $(NAME)

all: $(NAME)

clean:
	@rm -rf $(OBJS_MENDA)
	@make clean -C $(LIBFT_PATH) --no-print-directory -s
	@make clean -C $(PRINTF_PATH) --no-print-directory -s

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH) --no-print-directory -s
	@make fclean -C $(PRINTF_PATH) --no-print-directory -s

re: fclean all

.PHONY:		all clean fclean re

