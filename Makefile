# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 14:34:27 by danpalac          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2024/11/13 13:03:10 by danpalac         ###   ########.fr        #
=======
<<<<<<< HEAD
#    Updated: 2024/11/13 10:25:01 by danpalac         ###   ########.fr        #
=======
#    Updated: 2024/11/13 11:36:08 by danpalac         ###   ########.fr        #
>>>>>>> 56a64e2 (mejoras)
>>>>>>> refs/remotes/origin/main
#                                                                              #
# **************************************************************************** #

#==========COLOURS=============================================================#

# Basic Colors
BLACK       = \033[0;30m
RED         = \033[0;31m
GREEN       = \033[0;32m
YELLOW      = \033[0;33m
BLUE        = \033[0;34m
MAGENTA     = \033[0;35m
CYAN        = \033[0;36m
WHITE       = \033[0;37m

# Bright Colors
BOLD_BLACK  = \033[1;30m
BOLD_RED    = \033[1;31m
BOLD_GREEN  = \033[1;32m
BOLD_YELLOW = \033[1;33m
BOLD_BLUE   = \033[1;34m
BOLD_MAGENTA= \033[1;35m
BOLD_CYAN   = \033[1;36m
BOLD_WHITE  = \033[1;37m

# Extended Colors (256 colors)
ORANGE      = \033[38;5;208m
WINE        = \033[38;5;88m
LIME        = \033[38;5;190m
TURQUOISE   = \033[38;5;38m
LIGHT_PINK  = \033[38;5;13m
DARK_GRAY   = \033[38;5;235m
LIGHT_RED   = \033[38;5;203m
LIGHT_BLUE  = \033[38;5;75m

BRIGHT_BLUE = \033[38;5;27m
BRIGHT_GREEN= \033[38;5;46m
BRIGHT_YELLOW=\033[38;5;226m
BRIGHT_CYAN = \033[38;5;51m
BRIGHT_WHITE= \033[38;5;231m

# Reseteo de color
NO_COLOR    = \033[0m
DEF_COLOR   = \033[0;39m
CLEAR_LINE  = \033[2K
MOVE_UP     = \033[1A

#==========NAMES===============================================================#

NAME		:= libmemtrack.a
EXE			:= exe

#==========DIRECTORIES=======================================================#

INC 			:= inc/
SRC_DIR 		:= src/
OBJ_DIR 		:= obj/
LIBFT_DIR		:= ../libft/
LIB_DIR			:= ../lib/

MEMTRACK_DIR	:= memtrack/
MTLIB_DIR		:= mtlib/


LIBFT			:= $(LIBFT_DIR)libft.a
INC_LIBFT		:= $(LIBFT_DIR)$(INC)
INCLUDES		:= $(INC)*.h

#==========COMMANDS============================================================#

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -g3 -fsanitize=address
RM			:= rm -rf
AR			:= ar rcs
LIB			:= ranlib
MKDIR 		:= mkdir -p
IFLAGS		:= -I$(INC) -I$(LIB_DIR) -I$(LIBFT_DIR)
LFLAGS		:= -L$(LIBFT_DIR)

#==========SOURCES============================================================#

MEMTRACK_FILES:= ft_mtadd_back ft_mtnew ft_mtclear ft_mtdel_data ft_mtfind_cmp \
				ft_mtiter ft_mtlast ft_mtprint ft_mtremove ft_mtsize \
				ft_mtadd_front ft_mtfind_data ft_mtpop #ft_pop_back ft_pop_front ft_pop_at

MTLIB_FILES:= ft_chaosmatrix ft_freedom ft_strmtdup ft_splitmt ft_submtstr

#==========FILES==============================================================#

SRC_FILES+=$(addprefix $(MEMTRACK_DIR), $(MEMTRACK_FILES))
SRC_FILES+=$(addprefix $(MTLIB_DIR), $(MTLIB_FILES))

SRCS := $(addsuffix .c, $(SRC_FILES))
OBJS := $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS := $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))

#==========RULES==============================================================#

all: $(NAME)
-include $(DEPS)

$(OBJ_DIR)%.o: %.c Makefile
	@$(MKDIR) $(dir $@)	
	@$(CC) $(CFLAGS) $(LFLAGS) $(IFLAGS) -MP -MMD -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@$(LIB) $(NAME)
	@echo "$(BOLD_BLUE)[$(BRIGHT_GREEN)$(NAME)$(DEF_COLOR)$(BOLD_BLUE)] compiled!$(DEF_COLOR)"
	@echo "$(TURQUOISE)------------\n| Done! 👌 |\n------------$(DEF_COLOR)"
<<<<<<< HEAD
	@$(MKDIR) $(LIB_DIR)
	@cp -R $(INCLUDES) $(NAME) $(LIB_DIR)
=======
	@$(MKDIR) ../inc/
	@$(MKDIR) ../lib/
	@cp -R $(INCLUDES) ../inc/
	cp $(NAME) ../lib/
>>>>>>> refs/remotes/origin/main

$(EXE): main.c $(NAME)
	@$(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) -L. main.c $(NAME) -lft -o $(EXE)
	@echo "$(BOLD_BLUE)[$(BRIGHT_GREEN)$(EXE)$(DEF_COLOR)$(BOLD_BLUE)] compiled!$(DEF_COLOR)"
	@echo "$(TURQUOISE)------------\n| Done! 👌 |\n------------$(DEF_COLOR)"

$(LIBFT):
	@make -sC $(LIBFT_DIR)
	
clean:
	@$(RM) -rf $(OBJ_DIR) $(DEPS) $(LIB_DIR)
	@make clean -sC $(LIBFT_DIR)
	@echo "$(CYAN)[$(NAME)]:\tobject files $(GREEN) => Cleaned!$(DEF_COLOR)"

fclean: clean
	@$(RM) -rf $(NAME) $(EXE)
	@make fclean -sC $(LIBFT_DIR)
	@echo "$(CYAN)[$(NAME)]:\texe. files $(GREEN) => Cleaned!$(DEF_COLOR)"

re: fclean all

.SILENT: all clean fclean
.PHONY: all clean fclean re bonus
