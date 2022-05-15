SRCS =  ft_printf.c \
        ft_u_itoa.c

BONUS =

OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS:.c=.o}

NAME = libftprintf.a

CC = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror -I.

#.c.o:
#		${CC}  ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		make -C libft
		cp libft/libft.a $(NAME)
		ar rcs ${NAME} ${OBJS}

bonus: ${BONUS_OBJS}
		ar rcs ${NAME} ${BONUS_OBJS}
all:		${NAME}

clean:
		make -C libft clean
		${RM} ${OBJS}
		${RM} ${BONUS_OBJS}

fclean:		clean
		make -C libft fclean
		${RM} ${NAME}

re:		fclean all


.PHONY:		all clean fclean re bonus
