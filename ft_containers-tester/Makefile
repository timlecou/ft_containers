NAME		= ft_containers_test
CC			= clang++
RM			= rm -f
OBJS_DIR	= ./objects/
START		= 1
CFLAGS		= -Wall -Wextra -Werror -std=c++98

SRCSC		=	main.cpp

OBJS		= ${SRCSC:%.cpp=${OBJS_DIR}/%.o}

${OBJS_DIR}/%.o: %.cpp
			@mkdir -p ${@D}
			@printf "\033[2K\033[0;35mFT_CONTAINERS_TESTER\033[0;0m:    \033[0;33mCompilation...    \033[0;31m%-15.15s\033[0;0m\r" $(notdir ${<})
			@${CC} -pthread ${CFLAGS} -c $< -o $@

${NAME}:	header ${OBJS}
			@printf "\033[2K\033[0;35mFT_CONTAINERS_TESTER\033[0;0m:    \033[0;32mCompleted         \033[0;31m----\033[0;0m          \r"
			@printf "\n\033[0;0m⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤\n\033[0;35mFT_CONTAINERS_TESTER\033[0;0m:    \033[0;32mReady             \033[0;31m----          \033[0;0m\n⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤\n"
			@${CC} -pthread ${CFLAGS} ${OBJS} -o ${NAME}

run:		${NAME}
			@echo "\033[0;34mRunning ${NAME}...\033[0;0m"
			@./${NAME}

test:		re
			@echo "\033[0;34mRunning ${NAME}...\033[0;0m"
			@./${NAME}

header:
			@printf "\033[0;0m⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤\n\033[0;35mNAME          \033[0;0mSTATUS            \033[0;31mFILE          \033[0;0m\n⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤\n"

all:		${NAME}

leaks:		re
			@echo "\033[0;34mTesting ${NAME}...\033[0;0m"
			@valgrind ./${NAME} 2> leaks.txt
			@cat leaks.txt | tail -n 8
			@rm leaks.txt

clean:
			@${RM} ${OBJS}
			@printf "\033[0;35mPROJECT\033[0;0m:      \033[0;32mCleaned\033[0;0m\n"

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

silent:
			@:

.PHONY:		all clean fclean re