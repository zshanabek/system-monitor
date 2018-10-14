NAME = ft_gkrellm

SRC_DIR = ./src/
OBJ_DIR = ./obj/

FILENAMES = main.cpp Module.cpp Network.cpp Hostname.cpp OSInfo.cpp RAM.cpp Datetime.cpp CPU.cpp IMonitorDisplay.cpp IMonitorModule.cpp helpers.cpp Cat.cpp imgui.cpp imgui_demo.cpp imgui_draw.cpp imgui_impl_opengl2.cpp imgui_impl_sdl.cpp imgui_widgets.cpp

SRC = $(addprefix $(SRC_DIR), $(FILENAMES))
OBJ = $(addprefix $(OBJ_DIR), $(FILENAMES:.cpp=.o))

CC = clang++
FLAGS ?= -Wall -Werror -Wextra -g -std=c++98 -F frameworks/ 
FLAGS += -I./include/

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) -lncurses -framework SDL2 -framework OpenGL -framework AppKit
	@echo "\x1b[32mProject is successfully built\x1b[0m"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp | obj
	@$(CC) $(FLAGS) -o $@ -c $<

%.o:	%.cpp
		@$(CC)-g -o $@ -c $<

obj:
	@mkdir obj/

clean:
	@rm -rf obj/
	@echo "\x1b[33mObject files are cleaned\x1b[0m"	
fclean: clean
	@rm -f $(NAME)
	@echo "\x1b[33mAll is cleaned\x1b[0m"	
re: fclean all

.PHONY: all clean fclean re
