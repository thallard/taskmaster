SRC_DIR	:= srcs/
OBJ_DIR	:= obj/

classes = Classes
core = Core

OBJ_DIRS = $(addprefix $(OBJ_DIR), $(classes) $(core))

PRE_SRCS	=	main \
		$(classes)/Server $(classes)/Headers \
		$(classes)/Core \
		$(classes)/Worker \
		$(classes)/Client \
		$(classes)/Parser \
		$(classes)/CGI

SRCS = $(addsuffix .cpp, $(addprefix $(SRC_DIR), $(PRE_SRCS)))
OBJS = $(addsuffix .o, $(addprefix $(OBJ_DIR), $(PRE_SRCS)))

CLANG = clang++
FLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address
INC = -I./includes
NAME = webserv

$(NAME):  $(OBJ_DIRS) $(OBJS)
	@$(CLANG) $(FLAGS) $(OBJS) $(INC) -o $(NAME)
	@echo "----- \033[32m $@ created\033[0m  -----"

$(OBJS) : includes/Server.hpp includes/Utils.hpp

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@$(CLANG) $(FLAGS) $(INC) -o $@ -c $<
	@echo "$@ \033[32mcreated\033[0m"

$(OBJ_DIRS):
	@mkdir -p $(OBJ_DIRS)

 
all: $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re:	fclean all


.PHONY: all clean fclean re