# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbelange <gbelange@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/01 16:36:26 by gbelange          #+#    #+#              #
#    Updated: 2022/05/17 17:47:49 by gbelange         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = @gcc
CFLAGS = -Wall -Wextra -Werror
RM = @rm -f
OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $<

#Couleurs!
_END=$'\x1b[0m
_BOLD=$'\x1b[1m
_UNDER=$'\x1b[4m


_RED=$'\x1b[31m
_GREEN=$'\x1b[32m
_YELLOW=$'\x1b[33m
_BLUE=$'\x1b[34m
_PURPLE=$'\x1b[35m
_WHITE=$'\x1b[37m

_IRED=$'\x1b[41m
_IGREEN=$'\x1b[42m
_IYELLOW=$'\x1b[43m
_IBLUE=$'\x1b[44m
_IPURPLE=$'\x1b[45m
_IWHITE=$'\x1b[47m

SRCS =	ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_strjoin.c \
	ft_isdigit_str.c \
	ft_substr.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_printf.c \
	ft_arrlen.c \
	printf_utils.c \
	ft_arrfree.c \
	ft_strndup.c \
	get_next_line.c \

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "${_BLUE}libft + get_next_line compiled${_END}"

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

all: $(NAME)

re: fclean all

.PHONY: clean all fclean
