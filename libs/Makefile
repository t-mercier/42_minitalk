# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tmercier <tmercier@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/27 21:50:52 by tmercier      #+#    #+#                  #
#    Updated: 2022/12/01 22:22:40 by tmercier      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# ----------------- FILES #
SRCS 		=		libft/ft_printf/char_conversion.c libft/ft_printf/ft_printf.c \
					libft/ft_printf/num_conversion.c \
					libft/check_bool.c libft/check_case.c libft/check_char.c libft/compare.c \
					libft/convert_char.c libft/convert_num.c libft/convert_str.c \
					libft/copy.c libft/errors.c libft/free.c libft/join.c libft/length.c \
					libft/memory.c libft/put_.c libft/search.c libft/split.c \
					libft/strings_iter.c libft/ternaries.c \


HDRS 		= 		inc/lib42.h inc/libft.h

# ----------------- DIRECTORIES #
OBJ_DIR		=		obj
BIN_DIR		=		bin

# ----------------- CC #
CC			= 		gcc

# ----------------- LIBS #
LIB42		=		lib42.a

# ----------------- COMPILER FLAGS #
CFLAGS 		=		-Iinc -Wall -Wextra
ifdef DEBUG
CFLAGS		+=		-g3 -fsanitize=address
endif
ifndef DEV
CFLAGS 		+=		-Werror
endif

# ----------------- OBJECTS #
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# ----------------- TARGETS #
all: $(LIB42) $(LIB42MLX)

$(OBJ_DIR)/%.o: %.c $(HDRS)
	@mkdir -p $(@D)
	@printf "$(GREEN)Compiling: $(RESET)$(notdir $<)\n"
	@$(CC) -o $@ -c $< $(CFLAGS)

$(LIB42): $(OBJS)
	@ar rc $@ $^
	@printf "\n-> $(LIB42_A) archive created ✔️\n"

# ----------------- MISC #
norm:
	norminette ./**/**/{*.c,*.h}
	norminette inc/*.h

# ----------------- CLEANING #
clean:
	@if [ -d $(OBJ_DIR) ]; then rm -rf $(OBJ_DIR) && \
		printf "$(GREEN)\n-> lib42/obj cleaned\n$(RESET)"; \
		else printf "$(GREEN)\n-> lib42/obj already cleaned\n$(RESET)"; fi

fclean: clean
	@rm -rf $(LIB42)

re:
	@$(MAKE) fclean
	@$(MAKE) all

signature:
	@printf \
	"+---------------------+ © tmercier@student.codam.nl +\n\n$(RESET)"

.PHONY: clean fclean re graphic

# ----------------------------------- colors --------------------------------- #

BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m


################### BUILDING LIBRARIES PROCESS

# 'ar rc' creates a static library named 'libft.a' and puts copies
# of the object files in it. If the library file already exists, it has
# the object files added to it, or replaced, if they are newer than
# those inside the library.
# The 'c' flag tells ar to create the library if it doesn't already exist.
# The 'r' flag tells it to replace older object files in the library,
# with the new object files.

# After an archive is created, or modified, there is a need to index it.
# This index is later used by the compiler to speed up symbol-lookup
# inside the library, and to make sure that the order of the symbols
# in the library won't matter during compilation.
# The command used to create or update the index is called 'ranlib'.