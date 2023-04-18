
# ====================== VARIABLES ====================== #

# ---- Final executable ---- #
NAME		=	pipex

LIBFT		=	${DIR_LIBFT}/libft.a

# ---- Directories ---- #
DIR_HEADERS	=	includes/
DIR_SRCS 	=	sources/
DIR_UTLS	=	utils/
DIR_LIBFT 	=	libft/
DIR_OBJS 	=	.objs/

# ---- Files path ---- #
HEADERS 	= 	${DIR_HEADERS}pipex.h

SRCS		=	${DIR_SRCS}pipex.c\
				${DIR_SRCS}utils_mandatory.c\
				${DIR_UTLS}parsing.c\
				${DIR_UTLS}dup_fd.c\
				${DIR_UTLS}execute_cmd.c\
				${DIR_UTLS}error_close.c\
				${DIR_UTLS}ft_free_tab.c

OBJS		=	${addprefix ${DIR_OBJS},${SRCS:.c=.o}}

# ---- Flag ---- #
CFLAGS 		= 	-Wall -Werror -Wextra -I ${DIR_LIBFT} -I ${DIR_HEADERS}

# ====================== RULES ====================== #
# ---- Compiled rules ---- #
all:	
		make libft
		make ${NAME}

${DIR_OBJS}%.o: %.c ${HEADERS} ${LIBFT}
				@ mkdir -p ${shell dirname $@}
				${CC} ${CFLAGS} -c $< -o $@

${NAME}: 	 	${OBJS}
				${CC} ${OBJS} ${CFLAGS} ${LIBFT} -o ${NAME}

libft:			
				${MAKE} -C ${DIR_LIBFT}

# ---- Usual rules --- #
clean:
				make fclean -C ${DIR_LIBFT}
				${RM} -rf ${DIR_OBJS}

fclean:			clean
				${RM} ${NAME} ${NAME}
				make fclean -C ${DIR_LIBFT}

re: 			fclean all

.PHONY: all re clean fclean libft