# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 15:04:10 by ccaballe          #+#    #+#              #
#    Updated: 2023/02/16 16:49:12 by ccaballe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CLIENT = client
SERVER = server
CLIENT_BONUS = client_b
SERVER_BONUS = server_b

CFLAGS = -Wall -Wextra -Werror

SRC_CLIENT = client.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
DEP_CLIENT = $(SRC_CLIENT:.c=.d)

SRC_SERVER = server.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)
DEP_SERVER = $(SRC_SERVER:.c=.d)

SRC_CLIENT_BONUS = bonus/client_bonus.c
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)
DEP_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.d)

SRC_SERVER_BONUS = bonus/server_bonus.c
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)
DEP_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.d)

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
	@$(MAKE) -C libft
	@$(MAKE) -C ft_printf
	@$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBS) -o $@
	@echo "$(GREEN)client compiled$(NC)"

$(CLIENT)::
	@echo -n

$(SERVER):: $(OBJ_SERVER)
	@$(MAKE) -C libft
	@$(MAKE) -C ft_printf
	@$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBS) -o $@
	@echo "$(GREEN)server compiled$(NC)"

$(SERVER)::
	@echo -n

#BONUS
bonus:
	@$(MAKE) -C libft
	@$(MAKE) -C ft_printf
	@$(MAKE) $(CLIENT_BONUS)
	@$(MAKE) $(SERVER_BONUS)

$(CLIENT_BONUS):: $(OBJ_CLIENT_BONUS)
	@$(MAKE) -C libft
	@$(MAKE) -C ft_printf
	@$(CC) $(CFLAGS) $(OBJ_CLIENT_BONUS) $(LIBS) -o $@
	@echo "$(GREEN)client bonus compiled$(NC)"

$(CLIENT_BONUS)::
	@echo -n

$(SERVER_BONUS):: $(OBJ_SERVER_BONUS)
	@$(MAKE) -C libft
	@$(MAKE) -C ft_printf
	@$(CC) $(CFLAGS) $(OBJ_SERVER_BONUS) $(LIBS) -o $@
	@echo "$(GREEN)server bonus compiled$(NC)"

$(SERVER_BONUS)::
	@echo -n


clean:
	@$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) $(DEP_SERVER) $(DEP_CLIENT)
	@$(RM) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS) $(DEP_SERVER_BONUS) $(DEP_CLIENT_BONUS)
	@$(MAKE) clean -C libft
	@$(MAKE) clean -C ft_printf
	@echo "$(RED)\ndestruction successful\n$(NC)"

fclean: clean
	@$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS) $(LIBS) 

re: fclean all

.PHONY: all clean fclean re bonus

-include $(DEP_CLIENT)
-include $(DEP_SERVER)
-include $(DEP_CLIENT_BONUS)
-include $(DEP_SERVER_BONUS)
