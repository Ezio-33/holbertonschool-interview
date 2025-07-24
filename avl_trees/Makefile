CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic
NAME = 0-is_avl
SOURCES = binary_tree_print.c 0-main.c 0-binary_tree_is_avl.c binary_tree_node.c

all: $(NAME)

$(NAME): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

clean:
	rm -f $(NAME)

test: $(NAME)
	./$(NAME)

.PHONY: all clean test
