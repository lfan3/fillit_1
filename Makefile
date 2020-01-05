# directories
SRC_DIR := ./sources
INC_DIR := ./includes
OBJ_DIR := ./obj

#src 
SRC	:=	ft_printf.c \
		parsingformat.c \
		linklist.c \
		format_helper.c \
		helper.c \
		case_d.c \
		display.c \
		int_helper.c \

OBJ	:= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
#compiler
CC	:=	gcc
CFLAGS	:= -Wall -Wextra -Werror

NAME	:=	libftprintf.a

#rules
all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/util
	mkdir -p $(OBJ_DIR)/handlers

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(LIB_INC) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ)
		ar rc $(PRINTF_NAME) $(OBJ)
		ranlib $(PRINTF_NAME)

clean: rm -rf $(OBJ_DIR)
fclean: clean
		rm -f $(PRINTF_NAME)
re:
	fclean
	all
.PHONY: all clean fclean re relibs