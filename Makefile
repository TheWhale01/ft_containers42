CC=c++
BIN_DIR=bin/
OBJ_DIR=obj/
OBJ_STL_DIR=$(OBJ_DIR)STL/
SRC_DIR=src/
SRC_STL_DIR=$(SRC_DIR)STL/
INCLUDES=includes/
NAME_STL=$(BIN_DIR)stl
NAME=$(BIN_DIR)ft_containers

CFLAGS=-Wall -Wextra -Werror -I $(INCLUDES) -g -std=c++98
CFILES=$(addprefix $(SRC_DIR), main.cpp)
CFILES_STL=$(addprefix $(SRC_STL_DIR), main.cpp)
OBJS=$(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(CFILES))
OBJS_STL=$(patsubst $(SRC_STL_DIR)%.cpp, $(OBJ_STL_DIR)%.o, $(CFILES_STL))

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@if [ ! -d "$(dir $@)" ]; then mkdir -p $(dir $@); fi
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_STL_DIR)%.o: $(SRC_STL_DIR)%.cpp
	@if [ ! -d "$(dir $@)" ]; then mkdir -p $(dir $@); fi
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@if [ ! -d "./$(BIN_DIR)" ]; then mkdir $(dir $@); fi
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(NAME_STL): $(OBJS_STL)
	@if [ ! -d "./$(BIN_DIR)" ]; then mkdir $(dir $@); fi
	$(CC) $(CFLAGS) $(OBJS_STL) -o $(NAME_STL)

all: $(NAME)

stl: $(NAME_STL)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(BIN_DIR)

re: fclean all

.PHONY: all debug clean fclean re
