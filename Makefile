# A line starting with a has is a comment, we'll build up
# the below example

TARGET = losec
SRC_FILES = ./main.cpp ./reader.cpp ./lexer.cpp ./string_functions.cpp ./Model.cpp

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
main.o: main.cpp lexer.h model.h reader.h
reader.o: reader.cpp reader.h
lexer.o: lexer.cpp lexer.h string_functions.h
string_functions.o: string_functions.cpp string_functions.h
Model.o: Model.cpp model.h lexer.h
