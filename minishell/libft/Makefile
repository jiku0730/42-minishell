# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/04 16:00:02 by kjikuhar          #+#    #+#              #
#    Updated: 2025/06/02 20:46:59 by kjikuhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror -I../includes/
NAME	=	libft.a

SRCS	=	conversion/ft_atoi.c \
			conversion/ft_itoa.c \
			conversion/ft_tolower.c \
			conversion/ft_toupper.c \
			judge/ft_isalnum.c \
			judge/ft_isalpha.c \
			judge/ft_isascii.c \
			judge/ft_isdigit.c \
			judge/ft_isprint.c \
			list/ft_lstadd_back.c \
			list/ft_lstadd_front.c \
			list/ft_lstclear.c \
			list/ft_lstdelone.c \
			list/ft_lstiter.c \
			list/ft_lstlast.c \
			list/ft_lstmap.c \
			list/ft_lstnew.c \
			list/ft_lstsize.c \
			memory/ft_bzero.c \
			memory/ft_calloc.c \
			memory/ft_memchr.c \
			memory/ft_memcmp.c \
			memory/ft_memcpy.c \
			memory/ft_memmove.c \
			memory/ft_memrchr.c \
			memory/ft_memset.c \
			output/ft_putchar_fd.c \
			output/ft_putendl_fd.c \
			output/ft_putnbr_fd.c \
			output/ft_putstr_fd.c \
			string/ft_split.c \
			string/ft_strchr.c \
			string/ft_strdup.c \
			string/ft_striteri.c \
			string/ft_strjoin.c \
			string/ft_strlcat.c \
			string/ft_strlcpy.c \
			string/ft_strlen.c \
			string/ft_strmapi.c \
			string/ft_strncmp.c \
			string/ft_strnstr.c \
			string/ft_strrchr.c \
			string/ft_strtrim.c \
			string/ft_substr.c \
			original/ft_swap.c \
			original/ft_max.c \
			original/ft_min.c \
			original/ft_isspace.c

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

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			@echo "Compiled with $(GREEN)$(BOLD)$(CFLAGS)$(RESET)"
			@ar crs $(NAME) $(OBJS)
			@echo "$(YELLOW)$(BOLD)========================================="
			@echo "        You can use My $(NAME)!!"
			@echo "=========================================$(RESET)"

# =========================================
#         You can use My libft.a!!
# =========================================

%.o: %.c
	@echo "Compiled ✅ $(CYAN) $(BOLD) $^ $(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
