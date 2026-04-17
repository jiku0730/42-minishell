# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/18 21:11:39 by kjikuhar          #+#    #+#              #
#    Updated: 2026/04/17 21:12:31 by kjikuhar         ###   ########.fr        #
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
				src/builtin/echo/echo.c \
				src/builtin/export/export.c \
				src/builtin/pwd/pwd.c \
				src/builtin/unset/unset.c \
				src/builtin/cd/cd.c \
				src/builtin/cd/search_cdpath.c \
				src/builtin/exit/exit.c \
				src/prompt/prompt.c \
				src/callback/on_input.c \
				src/tokenize/tokenize.c \
				src/tokenize/is_specific.c \
				src/tokenize/state/in_normal.c \
				src/tokenize/state/in_normal/by_last.c \
				src/tokenize/state/in_normal/by_space.c \
				src/tokenize/state/in_normal/by_operator.c \
				src/tokenize/state/in_normal/by_quote.c \
				src/tokenize/state/in_normal/by_parenthesis.c \
				src/tokenize/state/in_double_quote.c \
				src/tokenize/state/in_single_quote.c \
				src/tokenize/state/in_operator.c \
				src/tokenize/state/on_success.c \
				src/tokenize/state/on_error.c \
				src/tokenize/store/free_store.c \
				src/tokenize/store/push_token.c \
				src/tokenize/store/add_buffer.c \
				src/parse/parse.c \
				src/parse/utils/add_to_cmd.c \
				src/parse/utils/new_ast_node.c \
				src/parse/utils/new_cmd.c \
				src/parse/utils/new_redir.c \
				src/parse/utils/token_check.c \
				src/parse/utils/free_ast.c \
				src/component/heredoc/heredoc.c \
				src/component/heredoc/heredoc_prompt.c \
				src/component/heredoc/tmpfile.c \
				src/component/shell_table/shell_hash.c \
				src/component/shell_table/shell_insert.c \
				src/component/shell_table/shell_search.c \
				src/component/shell_table/shell_delete.c \
				src/component/shell_table/shell_destroy.c \
				src/component/shell_table/shell_print.c \
				src/component/shell_table/build_shell_table.c \
				src/component/shell_table/export_envp.c \
				src/execute/exec_ast.c \
				src/execute/exec_cmd.c \
				src/execute/exec_pipe.c \
				src/execute/utils/ft_wexitstatus.c \
				src/execute/utils/ft_wifexited.c \
				src/execute/command/find_exec_path.c \
				src/execute/command/exec_builtin_cmd.c \
				src/execute/command/list_to_argv.c \
				src/execute/pipe/exec_pipe_child.c \
				src/execute/redirects/exec_redirs.c \
				src/component/directory/list_directory.c \
				src/component/directory/list_directory_recursive.c \
				src/component/path/to_absolute_path.c \
				src/component/path/join_path.c \
				src/component/path/append_path.c \
				src/component/path/resolve_relative_path.c \
				src/expand/expand.c \
				src/expand/expand_parameter/expand_parameter.c \
				src/expand/expand_parameter/state/in_normal_expand.c \
				src/expand/expand_parameter/state/in_double_quote_expand.c \
				src/expand/expand_parameter/state/in_single_quote_expand.c \
				src/expand/expand_parameter/state/on_success_expand.c \
				src/expand/expand_parameter/state/on_error_expand.c \
				src/expand/expand_parameter/store/push_token_expand.c \
				src/expand/expand_parameter/store/add_buffer_expand.c \
				src/expand/expand_parameter/store/get_key_length_expand.c \
				src/expand/expand_parameter/store/free_store_expand.c \
				src/expand/expand_tilde/expand_tilde.c \
				src/expand/expand_wildcard/resolve_wildcard.c \
				src/expand/expand_wildcard/match_wildcard.c \
				src/expand/expand_wildcard/expand_wildcard.c \
				src/expand/expand_remove_quotes/expand_remove_quotes.c \
				src/expand/expand_question/expand_question.c \
				src/signal/setup_signal_handlers.c \
				src/signal/set_signals.c \

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

docker:
	docker compose up -d && docker compose exec minishell bash

.PHONY: docker
