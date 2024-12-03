# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 14:34:27 by danpalac          #+#    #+#              #
#    Updated: 2024/12/03 10:57:45 by danpalac         ###   ########.fr        #
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

NAME		:= libmt.a
EXE			:= exe
LIBFT_LIB	:= libft.a

#==========DIRECTORIES=======================================================#

INC 			:= inc/
SRC_DIR 		:= src/
OBJ_DIR 		:= obj/
LIBFT_DIR		:= ../libft/
LIB_DIR			:= ../lib/
SRC_DIR			:= src/

LIST_DIR		:= list/
HASH_DIR		:= hash/
STACK_DIR		:= stack/
MEM_DIR			:= mem/
MTLIB_DIR		:= mtlib/
UTILS_DIR		:= utils/

LIBFT			:= $(LIBFT_DIR)$(LIBFT_LIB)
INCLUDES		:= $(INC)/*.h

#==========COMMANDS============================================================#

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -g3 -fsanitize=address
RM			:= rm -rf
AR			:= ar rcs
LIB			:= ranlib
MKDIR 		:= mkdir -p
IFLAGS		:= -I$(INC) -I$(LIBFT_DIR)$(INC)
LFLAGS		:= -L$(LIBFT_DIR)

#==========SOURCES============================================================#
#ft_pop_back ft_pop_front ft_pop_a

#LIST_FILES :=  ft_mtflatten.c ft_mtmap.c ft_mtmerge.c ft_mtdistinct.c ft_mtclone.c ft_mtinsert_index.c ft_mtfind_cmp.c ft_mtlast.c ft_mtiter.c

LIST_FILES := ft_mtadd_back ft_mtiter ft_mtlast ft_mtsize \
			ft_mtadd_front ft_mtpop ft_mtpop_back ft_mtpush ft_mtswap ft_mtmigrate ft_mtreverse_rotate ft_mtrotate \
			ft_mtinsert_index ft_mtpush_back ft_mtmigrate_back ft_mtprint \
			ft_mtreplace ft_mtreplace_all ft_mtsearch_mt ft_mtadd_child \
			ft_mtcount_type ft_mtcollect_type ft_mtnew_original_key \
			ft_mtexists_mt ft_mtexists_list

HASH_FILES := ft_mthash_insert ft_mthash_remove ft_mthash ft_mthash_find ft_mtfree_hash_table ft_mthash_new_table ft_mtprint_hash_table \
			ft_mthash_find_index ft_mthash_add_child ft_mthash_replace_data ft_mthash_replace_key \
			ft_mthash_table_free ft_mthash_add_node ft_mthash_exists ft_mthash_replace_node \
			ft_mthash_count_type ft_mthash_collect_type ft_mthash_insert_child ft_mthash_new_original_key

MEM_FILES :=  ft_mtnew ft_mtdup ft_mtclear ft_mtdel_data ft_mtfree ft_mtdel_list ft_mterase ft_mtremove_data ft_mtpush_data ft_mtpush_data_back \
			ft_mtnew_chaos ft_mtreplace_all_data ft_mtzip ft_mtunzip \

UTILS_FILES := ft_mtadd_key_prefix ft_mtadd_key_suffix ft_mtnew_key ft_mtcmp_utils ft_mtprint_utils ft_mtutils \
			ft_mtset_to_free

#ft_stkclone.c ft_stkpush.c ft_stkpop.c ft_stkswap.c ft_stkrotate.c ft_stkreverse_rotate.c ft_stkpush_back.c ft_stkmigrate.c ft_stkinsert_index.c

MTLIB_FILES:= ft_chaosmatrix ft_freedom ft_strmtdup ft_splitmt ft_submtstr

#==========FILES==============================================================#

SRC_FILES+=$(addprefix $(LIST_DIR), $(LIST_FILES))
SRC_FILES+=$(addprefix $(MEM_DIR), $(MEM_FILES))
SRC_FILES+=$(addprefix $(HASH_DIR), $(HASH_FILES))
SRC_FILES+=$(addprefix $(MTLIB_DIR), $(MTLIB_FILES))
SRC_FILES+=$(addprefix $(STACK_DIR), $(STACK_FILES))
SRC_FILES+=$(addprefix $(UTILS_DIR), $(UTILS_FILES))

SRCS := $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS := $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS := $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))

#==========RULES==============================================================#

-include $(DEPS)
all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c Makefile
	@$(MKDIR) $(dir $@)	
	@$(CC) $(CFLAGS) $(LFLAGS) $(IFLAGS) -MP -MMD -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(BOLD_BLUE)[$(BRIGHT_GREEN)$(NAME)$(DEF_COLOR)$(BOLD_BLUE)] compiled!$(DEF_COLOR)"
	@echo "$(TURQUOISE)------------\n| Done! 👌 |\n------------$(DEF_COLOR)"
	@mkdir -p $(LIB_DIR)
	@$(MKDIR) $(LIB_DIR) 
	@cp $(NAME) $(INCLUDES) $(LIB_DIR)

$(EXE): main.c $(NAME)
	@$(CC) $(CFLAGS) $(LFLAGS) -L. main.c $(NAME) $(IFLAGS)  -lft -o $(EXE)
	@echo "$(BOLD_BLUE)[$(BRIGHT_GREEN)$(EXE)$(DEF_COLOR)$(BOLD_BLUE)] compiled!$(DEF_COLOR)"
	@echo "$(TURQUOISE)------------\n| Done! 👌 |\n------------$(DEF_COLOR)"

$(LIBFT):
	@make -sC $(LIBFT_DIR)
	
clean:
	@$(RM) -rf $(OBJ_DIR) $(LIB_DIR)
	@make clean -sC $(LIBFT_DIR)

fclean: clean
	@$(RM) -rf $(NAME) $(EXE)
	@make fclean -sC $(LIBFT_DIR)
	@echo "$(CYAN)[$(NAME)]:\tfiles $(GREEN) => Cleaned!$(DEF_COLOR)"

re: fclean all

.SILENT: all clean fclean
.PHONY: all clean fclean re bonus
