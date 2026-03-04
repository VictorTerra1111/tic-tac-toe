
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I./hpps
SRCDIR = cpps
OBJDIR = obj
BINDIR = bin

# Arquivos fonte
SOURCES = $(SRCDIR)/main.cpp $(SRCDIR)/board.cpp $(SRCDIR)/intro.cpp $(SRCDIR)/menu.cpp $(SRCDIR)/save_files.cpp $(SRCDIR)/win_logic.cpp

# Arquivos objeto
OBJECTS = $(OBJDIR)/main.o $(OBJDIR)/board.o $(OBJDIR)/intro.o $(OBJDIR)/menu.o $(OBJDIR)/save_files.o $(OBJDIR)/win_logic.o

TARGET = $(BINDIR)/game

all: $(TARGET)

$(TARGET): $(OBJECTS) | $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $@

$(BINDIR):
	mkdir -p $@

clean:
	rm -rf $(OBJDIR) $(BINDIR)

rebuild: clean all

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean rebuild run
