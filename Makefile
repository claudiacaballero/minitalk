# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 15:04:10 by ccaballe          #+#    #+#              #
#    Updated: 2023/02/07 18:05:37 by ccaballe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CLIENT = client
SERVER = server

CFLAGS = -Wall -Wextra -Werror

SRC_CLIENT = client.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
DEP_CLIENT = $(SRC_CLIENT:.c=.d)

SRC_SERVER = server.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)
DEP_SERVER = $(SRC_SERVER:.c=.d)

RM = rm -f

LIBS = ft_printf/libftprintf.a libft/libft.a

GREEN = \033[1;92m
RED = \033[1;91m
NC = \033[0m

%.o: %.c $(LIBS) Makefile
	@$(CC) $(CFLAGS) -MMD -I./ -c $< -o $@

all:
	@$(MAKE) -C libft
	@$(MAKE) -C ft_printf
	@$(MAKE) $(CLIENT)
	@$(MAKE) $(SERVER)

$(CLIENT):: $(OBJ_CLIENT)
	@$(CC) $(OBJ_CLIENT) $(LIBS) -o $@
	@echo "$(GREEN)client compiled$(NC)"

$(CLIENT)::
	@echo -n

$(SERVER):: $(OBJ_SERVER)
	@$(CC) $(OBJ_SERVER) $(LIBS) -o $@
	@echo "$(GREEN)server compiled$(NC)"

$(SERVER)::
	@echo -n


# bonus:
# 	@$(MAKE) -C libft
# 	@$(MAKE) -C ft_printf
# 	@$(MAKE) $(BONUS)

# $(BONUS):: $(OBJBONUS)
# 	@$(CC) $(OBJBONUS) $(LIBS) -o $@
# 	@echo "$(GREEN)checker compiled$(NC)"

# $(BONUS)::
# 	@echo -n

clean:
	@$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) $(DEP_SERVER) $(DEP_CLIENT)
	@$(MAKE) clean -C libft
	@$(MAKE) clean -C ft_printf
	@echo "$(RED)\ndestruction successful\n$(NC)"

fclean: clean
	@$(RM) $(CLIENT) $(SERVER) $(LIBS)

re: fclean all

.PHONY: all clean fclean re

-include $(DEP_CLIENT)
-include $(DEP_SERVER)
#-include $(DEPBONUS)
