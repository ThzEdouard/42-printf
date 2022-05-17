NAME		= libft.a
SRC_DIR		= ./
OBJ_DIR		= obj/
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I.
RM			= rm -f
AR			= ar rcs

SRC_FILES =	\
        ft_memset     \
        ft_memmove    \
        ft_memchr     \
        ft_memcmp     \
        ft_memcpy     \
        ft_bzero      \
        ft_atoi       \
        ft_strlen     \
        ft_strlcpy    \
        ft_strchr     \
        ft_strrchr    \
        ft_strnstr    \
        ft_strncmp    \
        ft_atoi       \
        ft_isalnum    \
        ft_isdigit    \
        ft_isalpha    \
        ft_isascii    \
        ft_isprint    \
        ft_tolower    \
        ft_toupper    \
        ft_calloc     \
        ft_strdup     \
        ft_substr     \
        ft_strjoin    \
        ft_strtrim    \
        ft_putchar_fd \
        ft_putstr_fd  \
        ft_putendl_fd \
        ft_putnbr_fd  \
        ft_itoa       \
        ft_strmapi    \
	ft_striteri \

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF		=	.cache_exists
#.c.o:
#		${CC}  ${CFLAGS} -c $< -o ${<:.c=.o}

all:		$(NAME)

$(NAME):	$(OBJ)
		@$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
			@$(RM) -rf $(OBJ_DIR)

fclean:		clean
			@$(RM) -f $(NAME)

re:		fclean all


.PHONY:		all clean fclean re
