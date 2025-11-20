# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/18 21:11:39 by kjikuhar          #+#    #+#              #
#    Updated: 2025/11/20 11:49:13 by kjikuhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----------------------------------------------------------------------------
#> options
#-----------------------------------------------------------------------------
BLACK	:=	\033[30m
RED		:=	\033[31m
GREEN	:=	\033[32m
YELLOW	:=	\033[33m
BLUE	:=	\033[96m
MAGENTA	:=	\033[38;5;206m
CYAN	:=	\033[36m
WHITE	:=	\033[37m
RESET	:=	\033[0m
BOLD	:=	\033[1m
DIM		:=	\033[2m
ITALIC	:=	\033[3m
UNDER	:=	\033[4m
BLINK	:=	\033[5m
REVERSE	:=	\033[7m
HIDDEN	:=	\033[8m
PINK	:=	\033[35m

#-----------------------------------------------------------------------------

#▸ variables

#-----------------------------------------------------------------------------

NAME		:=	minishell

#─ compile config ────────────────────────────────────────────────────────────

CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror -Iincludes -Ilibft

#─ directory name ────────────────────────────────────────────────────────────

SRCDIR		:=	src
MAND 		:=	mandatory
OBJDIR		:=	obj
LIBFT_DIR	:=	libft
LIBFT_A		:=	$(LIBFT_DIR)/libft.a

#─ sources & objects ─────────────────────────────────────────────────────────

#mandatory sources
SRCS_MAND	:=	src/main.c \
				src/prompt/prompt.c \
				src/callback/on_input.c \
				src/tokenize/tokenize.c \
				src/tokenize/is_operator.c \
				src/tokenize/state/in_normal.c \
				src/tokenize/state/in_double_quote.c \
				src/tokenize/state/in_single_quote.c \
				src/tokenize/state/in_operator.c \
				src/tokenize/state/on_success.c \
				src/tokenize/state/on_error.c \
				src/tokenize/store/free_store.c \
				src/tokenize/store/push_token.c \
				src/tokenize/store/add_buffer.c \
				src/parser/parser.c \
				src/parser/utils/add_to_cmd.c \
				src/parser/utils/new_ast_node.c \
				src/parser/utils/new_cmd.c \
				src/parser/utils/new_redir.c \
				src/parser/utils/token_check.c \
				src/parser/utils/free_ast.c \
				src/parser/utils/print_ast.c \
				src/parser/utils/print_ast_utils.c \
				src/parser/utils/print_ast_utils2.c

#bonus sources

SRCS_BONUS	:=

#object files

OBJS_MAND	:=	$(SRCS_MAND:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
OBJS_BONUS	:=	$(SRCS_BONUS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
# OBJS	 	:=	$(OBJS_MAND) $(OBJS_BONUS)

#-----------------------------------------------------------------------------

#▸ rules

#-----------------------------------------------------------------------------

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS_MAND)
	@echo "Compiled with $(GREEN)$(BOLD)$(CFLAGS)$(RESET)"
	@$(CC) $(CFLAGS)  $(OBJS_MAND) -o $@ $(LIBFT_A) -lreadline
	@echo "$(YELLOW)$(BOLD)========================================="
	@echo "    You can use My $(NAME)!!"
	@echo "=========================================$(RESET)"

# compile object files

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@echo "Compiled ✅ $(WHITE) $(BOLD) $^ $(RESET)"
	@$(CC) $(CFLAGS) -c -o $@ $^

# libft
$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

# clean targets
clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(OBJDIR)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

# bonus: $(LIBFT_A) $(OBJS_BONUS)
# 	@cp $(LIBFT_A) $(NAME)
# 	@echo "Compiled with $(GREEN)$(BOLD)$(CFLAGS)$(RESET)"
# 	@ar rcs $(NAME) $(OBJS_BONUS)
# 	@echo "$(YELLOW)$(BOLD)========================================="
# 	@echo "  You can use My Bonus_$(NAME)!!"
# 	@echo "=========================================$(RESET)"

.PHONY: all clean fclean re bonus

#-----------------------------------------------------------------------------

#▸ original rules

#-----------------------------------------------------------------------------

norm:
	norminette src/* includes/* libft/

valgrind: re
	valgrind --leak-check=full --suppressions=readline.supp ./$(NAME)

test: norm valgrind

docker:
	docker compose up -d && docker compose exec minishell bash

.PHONY: norm valgrind test docker
