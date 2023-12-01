# A line starting with a has is a comment, we'll build up
# the below example

TARGET = losec
SRC_FILES = ./src/main.cpp ./src/reader.cpp ./src/lexer.cpp ./src/string_functions.cpp ./src/Model.cpp

# NO EDITS NEEDED BELOW THIS LINE

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -pedantic-errors
CXXFLAGS_DEBUG = -g
CXXVERSION = -std=c++17

OBJECTS = $(SRC_FILES:.cpp=.o)

ifeq ($(shell echo "Windows"), "Windows")
	TARGET := $(TARGET).exe
	DEL = del
	Q=
else
	DEL = rm -f
	Q="
endif

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

.cpp.o:
	$(CXX) $(CXXFLAGS) $(CXXVERSION) $(CXXFLAGS_DEBUG) -o $@ -c $<

clean:
	$(DEL) $(TARGET) $(OBJECTS) Makefile.bak

depend:
	@sed -i.bak '/^# DEPENDENCIES/,$$d' Makefile
	@$(DEL) sed*
	@echo $(Q)# DEPENDENCIES$(Q) >> Makefile
	@$(CXX) -MM $(SRC_FILES) >> Makefile

.PHONY: all clean depend

# DEPENDENCIES
main.o: src/main.cpp src/lexer.h src/model.h src/reader.h
reader.o: src/reader.cpp src/reader.h
lexer.o: src/lexer.cpp src/lexer.h src/string_functions.h
string_functions.o: src/string_functions.cpp src/string_functions.h
Model.o: src/Model.cpp src/model.h src/lexer.h
