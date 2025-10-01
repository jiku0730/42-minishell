NAME = minishell

SRCDIR = src
INCDIR = src
OBJDIR = obj

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(INCDIR) -I$(INCDIR)/console -I$(INCDIR)/libft

CONSOLE_SRCS = $(SRCDIR)/console/console.c

LIBFT_SRCS = $(SRCDIR)/libft/conversion/ft_atoi.c \
             $(SRCDIR)/libft/conversion/ft_itoa.c \
             $(SRCDIR)/libft/conversion/ft_tolower.c \
             $(SRCDIR)/libft/conversion/ft_toupper.c \
             $(SRCDIR)/libft/judge/ft_isalnum.c \
             $(SRCDIR)/libft/judge/ft_isalpha.c \
             $(SRCDIR)/libft/judge/ft_isascii.c \
             $(SRCDIR)/libft/judge/ft_isdigit.c \
             $(SRCDIR)/libft/judge/ft_isprint.c \
             $(SRCDIR)/libft/list/ft_lstadd_back.c \
             $(SRCDIR)/libft/list/ft_lstadd_front.c \
             $(SRCDIR)/libft/list/ft_lstclear.c \
             $(SRCDIR)/libft/list/ft_lstdelone.c \
             $(SRCDIR)/libft/list/ft_lstiter.c \
             $(SRCDIR)/libft/list/ft_lstlast.c \
             $(SRCDIR)/libft/list/ft_lstmap.c \
             $(SRCDIR)/libft/list/ft_lstnew.c \
             $(SRCDIR)/libft/list/ft_lstsize.c \
             $(SRCDIR)/libft/memory/ft_bzero.c \
             $(SRCDIR)/libft/memory/ft_calloc.c \
             $(SRCDIR)/libft/memory/ft_memchr.c \
             $(SRCDIR)/libft/memory/ft_memcmp.c \
             $(SRCDIR)/libft/memory/ft_memcpy.c \
             $(SRCDIR)/libft/memory/ft_memmove.c \
             $(SRCDIR)/libft/memory/ft_memrchr.c \
             $(SRCDIR)/libft/memory/ft_memset.c \
             $(SRCDIR)/libft/original/ft_isspace.c \
             $(SRCDIR)/libft/original/ft_max.c \
             $(SRCDIR)/libft/original/ft_min.c \
             $(SRCDIR)/libft/original/ft_swap.c \
             $(SRCDIR)/libft/output/ft_putchar_fd.c \
             $(SRCDIR)/libft/output/ft_putendl_fd.c \
             $(SRCDIR)/libft/output/ft_putnbr_fd.c \
             $(SRCDIR)/libft/output/ft_putstr_fd.c \
             $(SRCDIR)/libft/string/ft_split.c \
             $(SRCDIR)/libft/string/ft_strchr.c \
             $(SRCDIR)/libft/string/ft_strdup.c \
             $(SRCDIR)/libft/string/ft_striteri.c \
             $(SRCDIR)/libft/string/ft_strjoin.c \
             $(SRCDIR)/libft/string/ft_strlcat.c \
             $(SRCDIR)/libft/string/ft_strlcpy.c \
             $(SRCDIR)/libft/string/ft_strlen.c \
             $(SRCDIR)/libft/string/ft_strmapi.c \
             $(SRCDIR)/libft/string/ft_strncmp.c \
             $(SRCDIR)/libft/string/ft_strnstr.c \
             $(SRCDIR)/libft/string/ft_strrchr.c \
             $(SRCDIR)/libft/string/ft_strtrim.c \
             $(SRCDIR)/libft/string/ft_substr.c

MAIN_SRCS = $(SRCDIR)/main.c

SRCS = $(MAIN_SRCS) $(CONSOLE_SRCS) $(LIBFT_SRCS)

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

HEADERS = $(INCDIR)/minishell.h \
		  $(INCDIR)/console/console.h \
		  $(INCDIR)/libft/libft.h

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
NC = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Linking $(NAME)...$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN) $(NAME) created successfully!$(NC)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) | $(OBJDIR)
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)/console
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
