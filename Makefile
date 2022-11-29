CC=c++
OBJ_DIR=obj/
SRC_DIR=src/
BIN_DIR=bin/
INCLUDES=includes/
NAME=$(BIN_DIR)containers
CFLAGS=-Wall -Wextra -Werror -I $(INCLUDES) -g -std=c++98
CFILES=$(addprefix $(SRC_DIR), main.cpp)
OBJS=$(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(CFILES))

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@if [ ! -d "$(dir $@)" ]; then mkdir -p $(dir $@); fi
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@if [ ! -d "$(dir $@)" ]; then mkdir -p $(dir $@); fi
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

std: NAME=$(BIN_DIR)stl
std: fclean
std: CFLAGS=-Wall -Wextra -Werror -I $(INCLUDES) -g -std=c++98 -D NM=std
std: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all debug clean fclean re
