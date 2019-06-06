# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/29 18:23:07 by fhenrion          #+#    #+#              #
#    Updated: 2019/06/02 17:56:19 by fhenrion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_NAME = atoi lstlast putchar strdup strnequ bzero lstmap putchar_fd strequ \
strnew isalnum lstmerge putendl striter strnstr isalpha lstnew putendl_fd \
striteri strrchr isascii lstreverse putnbr strjoin strsplit isdigit lstsize \
putnbr_fd strlcat strstr isprint memalloc putstr strlcpy strsub isspace \
memccpy putstr_fd strlen strtrim itoa memchr strcat strlowcase strupcase \
lstadd memcmp strchr strmap tolower lstat memcpy strclr strmapi toupper \
lstdel memdel strcmp strncat lstdelone memmove strcpy strncmp lstiter \
memset strdel strncpy strfreejoin strchrsub strchri

HDR_NAME = libft.h
SRC = $(addprefix ft_,$(SRC_NAME))

C_SRC = $(addsuffix .c,$(SRC))
O_SRC = $(addsuffix .o,$(SRC))

CC = gcc
CFLAGS = -Werror -Wall -Wextra
LDFLAGS =

all: $(NAME)

$(NAME): $(C_SRC)
	@$(CC) $(CFLAGS) -I $(HDR_NAME) -c $^
	@ar rc $@ $(O_SRC)
	@ranlib $@
	@echo "Compilation OK"

clean:
	@/bin/rm -f $(O_SRC)
	@echo "Objects cleaning OK"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "Library cleaning OK"

re: fclean all

.PHONY: clean fclean all re
