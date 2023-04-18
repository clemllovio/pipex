# ====================== VARIABLES ====================== #

# ---- Final Executable --- #
NAME 			=	libft.a

# ---- Directories ---- #
DIR_OBJS		=	.objs/

# ---- Files path ---- #
HEADERS			=	libft.h

SRCS			=	ft_split.c\
					ft_strncmp.c\
					ft_putchar_fd.c\
					ft_putstr_fd.c\
					ft_substr.c\
					ft_strdup.c\
					ft_strlen.c\
					ft_strjoin.c\
					ft_putendl_fd.c
					
OBJS 			=	${addprefix ${DIR_OBJS},${SRCS:.c=.o}}

# ---- Flag---- #
CFLAG			=	-Wall -Werror -Wextra

# ====================== RULES ====================== #

# ---- Compiled rules ---- #
all:				${NAME}

${NAME}:			${OBJS}
					ar rcs ${NAME} ${OBJS}

${DIR_OBJS}%.o: 	%.c ${HEADERS}
					@mkdir -p ${shell dirname $@}
					$(CC) $(CFLAG) -c $< -o $@

${DIR_OBJS}:
					mkdir -p ${DIR_OBJS}

# ---- Usual Rules ---- #
clean:
					${RM} -rf ${OBJS} ${DIR_OBJS}

fclean: 			clean
					${RM} ${NAME}

re:					fclean ${NAME}

.PHONY:				all clean fclean re