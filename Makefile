NAME = minishell

SRCDIR = src
INCDIR = src
OBJDIR = obj

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iincludes -Ilibft

LIBFT_SRCS = libft/conversion/ft_atoi.c \
             libft/conversion/ft_itoa.c \
             libft/conversion/ft_tolower.c \
             libft/conversion/ft_toupper.c \
             libft/judge/ft_isalnum.c \
             libft/judge/ft_isalpha.c \
             libft/judge/ft_isascii.c \
             libft/judge/ft_isdigit.c \
             libft/judge/ft_isprint.c \
             libft/list/ft_lstadd_back.c \
             libft/list/ft_lstadd_front.c \
             libft/list/ft_lstclear.c \
             libft/list/ft_lstdelone.c \
             libft/list/ft_lstiter.c \
             libft/list/ft_lstlast.c \
             libft/list/ft_lstmap.c \
             libft/list/ft_lstnew.c \
             libft/list/ft_lstsize.c \
             libft/memory/ft_bzero.c \
             libft/memory/ft_calloc.c \
             libft/memory/ft_memchr.c \
             libft/memory/ft_memcmp.c \
             libft/memory/ft_memcpy.c \
             libft/memory/ft_memmove.c \
             libft/memory/ft_memrchr.c \
             libft/memory/ft_memset.c \
             libft/original/ft_isspace.c \
             libft/original/ft_max.c \
             libft/original/ft_min.c \
             libft/original/ft_swap.c \
             libft/output/ft_putchar_fd.c \
             libft/output/ft_putendl_fd.c \
             libft/output/ft_putnbr_fd.c \
             libft/output/ft_putstr_fd.c \
             libft/string/ft_split.c \
             libft/string/ft_strchr.c \
             libft/string/ft_strdup.c \
             libft/string/ft_striteri.c \
             libft/string/ft_strjoin.c \
             libft/string/ft_strlcat.c \
             libft/string/ft_strlcpy.c \
             libft/string/ft_strlen.c \
             libft/string/ft_strmapi.c \
             libft/string/ft_strncmp.c \
             libft/string/ft_strnstr.c \
             libft/string/ft_strrchr.c \
             libft/string/ft_strtrim.c \
             libft/string/ft_substr.c

PROMPT_SRCS = $(SRCDIR)/prompt/prompt.c

MAIN_SRCS = $(SRCDIR)/main.c

SRCS = $(MAIN_SRCS) $(PROMPT_SRCS) $(LIBFT_SRCS)

OBJS = $(MAIN_SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o) \
       $(PROMPT_SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o) \
       $(LIBFT_SRCS:%.c=$(OBJDIR)/%.o)

HEADERS = includes/minishell.h \
		  includes/prompt.h \
		  libft/libft.h

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
NC = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Linking $(NAME)...$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) -lreadline -o $(NAME)
	@echo "$(GREEN) $(NAME) created successfully!$(NC)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) | $(OBJDIR)
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/%.o: %.c $(HEADERS) | $(OBJDIR)
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)/prompt
	@mkdir -p $(OBJDIR)/libft/conversion
	@mkdir -p $(OBJDIR)/libft/judge
	@mkdir -p $(OBJDIR)/libft/list
	@mkdir -p $(OBJDIR)/libft/memory
	@mkdir -p $(OBJDIR)/libft/original
	@mkdir -p $(OBJDIR)/libft/output
	@mkdir -p $(OBJDIR)/libft/string

%:
	@:

clean:
	@if [ -d $(OBJDIR) ]; then \
		echo "$(RED)Removing object files...$(NC)"; \
		rm -rf $(OBJDIR); \
		echo "$(GREEN) Object files removed!$(NC)"; \
	fi

fclean: clean
	@if [ -f $(NAME) ]; then \
		echo "$(RED)Removing $(NAME)...$(NC)"; \
		rm -f $(NAME); \
		echo "$(GREEN) $(NAME) removed!$(NC)"; \
	fi

re: fclean all

.PHONY: all clean fclean re

.PRECIOUS: $(OBJDIR)/%.o
