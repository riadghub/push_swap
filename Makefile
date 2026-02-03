NAME = push_swap

SRCS =	push_swap.c		\
		finder.c		\
		init.c			\
		lst_utils.c		\
		moves.c			\
		parsing.c		\
		parsing_utils.c	\
		push.c			\
		reverse.c		\
		sort.c			\
		swap.c			\
		target.c		\
		verif.c			\
		ft_split.c		\

HEADERS = ./includes/

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

# Couleurs ANSI
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RESET = \033[0m

# Animation de chargement
define LOADING_ANIM
	@echo -n "$(YELLOW)Loading"
	@for i in 1 2 3 4 5; do \
		echo -n "."; \
		sleep 0.2; \
	done
	@echo "$(RESET)"
endef

%.o : %.c
	@echo "$(BLUE)Compiling $(YELLOW)$< $(RESET)..."
	@${CC} ${CFLAGS} -I ${HEADERS} -c $< -o $@

${NAME} : ${OBJS}
	@echo "$(GREEN)Linking objects into $(YELLOW)${NAME}$(RESET)..."
	@${CC} ${CFLAGS} -I ${HEADERS} ${OBJS} -o ${NAME}
	@echo "$(GREEN)Build complete!$(RESET)"

all : ${NAME}
	@echo "$(GREEN)All done!$(RESET)"

clean :
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -f ${OBJS}
	@echo "$(GREEN)Clean complete!$(RESET)"

fclean : clean
	@echo "$(RED)Removing $(YELLOW)${NAME}$(RESET)..."
	@rm -f ${NAME}
	@echo "$(GREEN)Full clean complete!$(RESET)"

re : fclean all
	@echo "$(GREEN)Rebuild complete!$(RESET)"

run : all
	$(LOADING_ANIM)
	@echo "$(GREEN)Running $(YELLOW)${NAME}$(RESET)..."
	@./${NAME}

.PHONY: all clean fclean re run