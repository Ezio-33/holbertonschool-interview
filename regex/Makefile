# Makefile pour le projet RegEx (Holberton)

# Définition des variables
NAME	:= regex
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -pedantic
SRC		:= regex.c
TEST	:= main.c
OBJ		:= $(SRC:.c=.o)
HDR		:= regex.h

.PHONY: all clean fclean re betty run  # Déclare les cibles qui ne sont pas des fichiers

# Cible par défaut - compile le projet
all: $(NAME)

# Règle pour créer l'exécutable
$(NAME): $(OBJ) $(TEST)
	$(CC) $(CFLAGS) $(TEST) $(OBJ) -o $(NAME)

# Règle pour compiler les fichiers .c en fichiers objets .o
%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

# Supprime les fichiers objets
clean:
	rm -f $(OBJ)

# Supprime les fichiers objets et l'exécutable
fclean: clean
	rm -f $(NAME)

# Nettoie tout et recompile
re: fclean all

# Vérifie le style du code avec Betty
betty:
	betty-style *.c *.h || true
	betty-doc *.c *.h || true

# Compile et exécute le programme
run: $(NAME)
	./$(NAME)
