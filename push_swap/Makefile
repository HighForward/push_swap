SRCS		=	./main.c            \
                ./instructions.c    \
                ./algo.c            \
                ./selection_sort.c  \
                ./bubble_sort.c     \
                ./wtf_sort.c        \
                ../utils/utils.c

NAME		=	push_swap

H           =   ../includes/push_swap.h

OBJS		=	${SRCS:.c=.o}

FLAGS		=	-Iincludes

CC			=	gcc

RM			=	rm -f

.c.o:
				@$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

all: ${NAME}

link:
				@$(MAKE) -C ../libft/

${NAME}: ${OBJS} ${H} link
			    @$(CC) ${OBJS} -Wall -Wextra -Werror -L ../libft -lft -o ${NAME}
			    @echo "\033[1;32m > Building <\033[0m\033[1;35m .o files\033[0m"
			    @echo "\033[1;32m > Building <\033[0m\033[1;36m ${NAME}\033[0m"

clean:
				@${RM} ${OBJS}
				@$(MAKE) clean -C ../libft/
				@echo "\033[1;31m > Deleting <\033[0m\033[1;35m .o files\033[0m"

fclean: clean
			    @${RM} $(NAME)
			    @$(MAKE) fclean -C ../libft/
			    @echo "\033[1;31m > Deleting <\033[0m\033[1;35m ${NAME} \033[0m"

re:	fclean all

.PHONY: clean fclean re bonus run