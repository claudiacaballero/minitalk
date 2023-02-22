# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/17 16:36:29 by ccaballe          #+#    #+#              #
#    Updated: 2023/02/22 18:35:15 by ccaballe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
BNAME = .bonus
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
	ft_memcpy.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_atoi.c ft_strchr.c ft_strrchr.c ft_memmove.c \
	ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strtrim.c ft_strmapi.c ft_striteri.c ft_itoa.c ft_split.c \
	get_next_line.c

SRCSBONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c  ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \

OBJS = $(SRCS:.c=.o)
OBJSBONUS = $(SRCSBONUS:.c=.o)
RM = rm -f
DEPS = $(SRCS:.c=.d)
DEPSBONUS = $(SRCSBONUS:.c=.d)

GREEN = \033[1;92m
RED = \033[1;91m
NC = \033[0m

%.o: %.c Makefile
	@$(CC) $(CFLAGS) -MMD -I./ -c $< -o $@

all: $(NAME)

$(NAME):: $(OBJS)
	@ar crs $(NAME) $(OBJS)
	@echo "$(GREEN)libft compiled$(NC)"

$(NAME)::
	@echo -n


bonus: $(BNAME)

$(BNAME): $(OBJS) $(OBJSBONUS)
	@ar rcs $(NAME) $(OBJS) $(OBJSBONUS)
	@touch $@


clean:
	@$(RM) $(OBJS) $(DEPS) $(OBJSBONUS) $(DEPSBONUS)
	@echo "$(RED)libft objects deleted$(NC)"

fclean: clean
	@$(RM) $(NAME) $(BNAME)
	@echo "$(RED)libft exec deleted$(NC)"

re: fclean all

.PHONY: all clean fclean re bonus

-include $(DEPS)
-include $(DEPSBONUS)