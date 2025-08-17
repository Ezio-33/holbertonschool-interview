# Makefile pour le projet Substring with concatenated words

# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic
NAME = substring
MAIN = main.c
SOURCES = substring.c
HEADERS = substring.h
OBJECTS = $(SOURCES:.c=.o)

# Couleurs pour l'affichage
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
NC = \033[0m # No Color

# Règle par défaut
all: $(NAME)

# Compilation du programme principal
$(NAME): $(OBJECTS) $(MAIN)
	@echo "$(YELLOW)Compilation en cours...$(NC)"
	$(CC) $(CFLAGS) $(MAIN) $(OBJECTS) -o $(NAME)
	@echo "$(GREEN)✓ Compilation terminée avec succès !$(NC)"

# Compilation des fichiers objets
%.o: %.c $(HEADERS)
	@echo "$(YELLOW)Compilation de $<...$(NC)"
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	@echo "$(YELLOW)Nettoyage des fichiers objets...$(NC)"
	rm -f $(OBJECTS)
	@echo "$(GREEN)✓ Fichiers objets supprimés$(NC)"

# Nettoyage complet
fclean: clean
	@echo "$(YELLOW)Nettoyage complet...$(NC)"
	rm -f $(NAME)
	@echo "$(GREEN)✓ Nettoyage complet terminé$(NC)"

# Recompilation complète
re: fclean all

# Tests avec les exemples fournis
test: $(NAME)
	@echo "$(YELLOW)Exécution des tests...$(NC)"
	@echo "$(YELLOW)Test 1: barfoothefoobarman foo bar$(NC)"
	@./$(NAME) barfoothefoobarman foo bar
	@echo "$(YELLOW)Test 2: wordgoodgoodgoodbestword word good best word$(NC)"
	@./$(NAME) wordgoodgoodgoodbestword word good best word
	@echo "$(YELLOW)Test 3: wordgoodgoodgoodbestword word good best good$(NC)"
	@./$(NAME) wordgoodgoodgoodbestword word good best good
	@echo "$(GREEN)✓ Tous les tests terminés$(NC)"

# Vérification du style Betty
betty: $(SOURCES) $(HEADERS)
	@echo "$(YELLOW)Vérification du style Betty...$(NC)"
	@if command -v betty-style >/dev/null 2>&1; then \
		betty-style $(SOURCES) $(HEADERS); \
		betty-doc $(SOURCES); \
	else \
		echo "$(RED)Betty non trouvé, utilisation du chemin par défaut...$(NC)"; \
		/root/Betty/betty-style.pl $(SOURCES) $(HEADERS); \
		/root/Betty/betty-doc.pl $(SOURCES); \
	fi
	@echo "$(GREEN)✓ Vérification Betty terminée$(NC)"

# Installation de Betty (si nécessaire)
install-betty:
	@echo "$(YELLOW)Installation de Betty...$(NC)"
	@if [ ! -d "/root/Betty" ]; then \
		git clone https://github.com/holbertonschool/Betty.git /tmp/Betty; \
		sudo mv /tmp/Betty /root/; \
		sudo chmod +x /root/Betty/betty-style.pl; \
		sudo chmod +x /root/Betty/betty-doc.pl; \
		echo "$(GREEN)✓ Betty installé avec succès$(NC)"; \
	else \
		echo "$(GREEN)✓ Betty déjà installé$(NC)"; \
	fi

# Aide
help:
	@echo "$(GREEN)Commandes disponibles:$(NC)"
	@echo "  $(YELLOW)make$(NC) ou $(YELLOW)make all$(NC)     - Compile le projet"
	@echo "  $(YELLOW)make clean$(NC)           - Supprime les fichiers objets"
	@echo "  $(YELLOW)make fclean$(NC)          - Supprime tous les fichiers générés"
	@echo "  $(YELLOW)make re$(NC)              - Recompile complètement le projet"
	@echo "  $(YELLOW)make test$(NC)            - Exécute les tests fournis"
	@echo "  $(YELLOW)make betty$(NC)           - Vérifie le style et la documentation Betty"
	@echo "  $(YELLOW)make install-betty$(NC)   - Installe Betty si nécessaire"
	@echo "  $(YELLOW)make help$(NC)            - Affiche cette aide"

# Déclaration des règles qui ne correspondent pas à des fichiers
.PHONY: all clean fclean re test betty install-betty help
