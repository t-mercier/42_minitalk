# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tmercier <tmercier@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/12/02 17:13:26 by tmercier      #+#    #+#                  #
#    Updated: 2022/12/18 21:37:12 by tmercier      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/sh

# ---------------------------------- FILES ---------------------------------- #

SERVER		=	server.c
CLIENT		=	client.c
INC_DIR		=	.
OBJ_DIR 	= 	obj

# ----------------------------------- CC ------------------------------------ #

CC			=	gcc

# ---------------------------------- LIB42 ---------------------------------- #

LIB42		=	libs/lib42.a
LIB42_DIR	=	libs

# ----------------------------------- debug ---------------------------------- #

LFLAGS		+=	-Ilibs/inc

ifdef DEBUG
	CFLAGS +=	-fsanitize=address
else
	CFLAGS +=	-std=c99 -Wall -Wextra
endif

ifndef DEV
	CFLAGS +=	-Werror
endif

# -------------------------------- Libraries -------------------------------- #

CC = gcc

all: $(LIB42) server client

server: server.c
	$(CC) $(CFLAGS) -o $@ $^  $(LFLAGS) $(LIB42)
	@printf "$(GREEN)-> server executable created $(NO_COLOR) ✔️\n";

client: client.c
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS) $(LIB42)
	@printf "$(GREEN)-> client executable created $(NO_COLOR) ✔️\n";

.PHONY: run
run: ./server


$(LIB42):
	@if ! [ -f $(LIB42) ]; then $(MAKE) -C $(LIB42_DIR); fi
	@printf "$(GREEN)-> $(LIB42) archive created$(NO_COLOR) ✔️\n";

# -------------------------------- clean -------------------------------- #

clean:
	@rm -rf $(OBJ_DIR)
	@printf "$(LIGHT_RED)\n-> obj files removed.\n$(NO_COLOR)"

fclean:	clean
	@rm -rf server client
	@make fclean -C $(LIB42_DIR)
	@printf "\n$(LIGHT_RED)-> executable removed.\n\n$(NO_COLOR)"

re: fclean all

signature:
			@printf \
	"$(LIGHT_CYAN)+---------------------+ © tmercier@student.codam.nl +\n\n"

.PHONY: clean fclean re psclean leaks test f

# -------------------------------- colors -------------------------------- #

GREEN			=	\033[1;32m
LIGHT_RED		=	\033[1;31m
LIGHT_CYAN		=	\033[1;36m
NO_COLOR		=	\033[0m

