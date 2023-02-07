# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 15:30:00 by ccaballe          #+#    #+#              #
#    Updated: 2023/01/30 15:02:33 by ccaballe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror -MMD
SRCS = ft_printf.c \
	ft_putchars.c \
	ft_putnbrs.c \

OBJS = ${SRCS:.c=.o}
RM = rm -f
DEPS = ${SRCS:.c=.d}

GREEN = \033[1;92m
RED = \033[1;91m
NC = \033[0m

%.o: %.c Makefile
	@${CC} ${CFLAGS} -I./ -c $< -o $@

all: ${NAME}

$(NAME):: $(OBJS)
	@ar crs $(NAME) $(OBJS)
	@echo "$(GREEN)ft_printf compiled$(NC)"

$(NAME)::
	@echo -n

clean:
	@${RM} ${OBJS} ${DEPS}
	@echo "$(RED)ft_printf objects deleted$(NC)"

fclean: clean
	@${RM} ${NAME}
	@echo "$(RED)ft_printf exec deleted$(NC)"

re: fclean all

.PHONY: all clean fclean re

-include ${DEPS}