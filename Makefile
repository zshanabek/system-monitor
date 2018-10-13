NAME = ft_gkrellm

SRC_DIR = ./src/
OBJ_DIR = ./obj/

FILENAMES = main.cpp

SRC = $(addprefix $(SRC_DIR), $(FILENAMES))
OBJ = $(addprefix $(OBJ_DIR), $(FILENAMES:.cpp=.o))

CC = clang++
FLAGS ?= -Wall -Werror -Wextra -g -std=c++98
FLAGS += -I./include/

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) -lncurses
	@echo "\x1b[32mProject is successfully built\x1b[0m"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp | obj
	@$(CC) $(FLAGS) -o $@ -c $<

%.o:	%.cpp
		@$(CC)-g -o $@ -c $<

obj:
	mkdir obj/

clean:
	@rm -rf obj/
	@echo "\x1b[33mObject files are cleaned\x1b[0m"	
fclean: clean
	@rm -f $(NAME)
	@echo "\x1b[33mAll is cleaned\x1b[0m"	
re: fclean all

.PHONY: all clean fclean re