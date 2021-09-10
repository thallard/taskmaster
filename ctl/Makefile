CC			=	clang++
RM			=	rm -rf
NAME		=	taskmasterctl

SRCS_DIR	=	./srcs
INCS_DIR	=	./includes

SRCS		:=	$(wildcard ./$(SRCS_DIR)/*.cpp)
INCS		=	$(wildcard ./$(INCS_DIR)/*.hpp)

OBJS		:=	$(SRCS:.cpp=.o)

FSANITIZE	=	-fsanitize=address
FLAGS		=	-Wall -Wextra -Werror -g3 $(FSANITIZE) -I$(INCS_DIR)


%.o:%.cpp
	$(CC) $(FLAGS) -c $< -o $@

all:		$(NAME)

$(OBJS):	$(INCS)

$(NAME):	$(OBJS) $(INCS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

re:			fclean all

clean:
	$(RM) $(OBJS)

fclean: 	clean
	$(RM) $(NAME)

.PHONY:		all clean fclean re