# --- Compilateur & Options ---
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iheaders

# --- Librairies SFML ---
SFML = -lsfml-graphics -lsfml-window -lsfml-system

# --- Fichiers sources communs ---
SRCS_COMMON = \
    src/main.cpp \
    src/Grid.cpp \
    src/Cellule.cpp \
    src/CelluleVivante.cpp \
    src/CelluleMorte.cpp \
    src/CelluleObstacle.cpp

# --- Interface graphique (SFML) ---
SRCS_SFML = \
    src/InterfaceSFML.cpp

# --- Interface console ---
SRCS_CONSOLE = \
    src/InterfaceConsole.cpp

# --- Exécutables ---
BIN_SFML = game
BIN_CONSOLE = game_console

# --- Cible par défaut : SFML ---
all: $(BIN_SFML)

# --- Compilation SFML ---
$(BIN_SFML): $(SRCS_COMMON) $(SRCS_SFML)
	$(CXX) $(CXXFLAGS) $(SRCS_COMMON) $(SRCS_SFML) -o $@ $(SFML)

# --- Compilation mode console ---
console: $(BIN_CONSOLE)

$(BIN_CONSOLE): $(SRCS_COMMON) $(SRCS_CONSOLE)
	$(CXX) $(CXXFLAGS) $(SRCS_COMMON) $(SRCS_CONSOLE) -o $@

# --- Mode debug ---
debug:
	$(CXX) $(CXXFLAGS) -O0 -g $(SRCS_COMMON) $(SRCS_SFML) -o game_debug $(SFML)

# --- Nettoyage ---
clean:
	rm -f $(BIN_SFML) $(BIN_CONSOLE) game_debug

.PHONY: all console debug clean
