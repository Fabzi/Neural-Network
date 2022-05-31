CXX           := g++
CXXFLAGS      := -Wall -Wextra -pedantic -std=c++2a -c -o
LIBFLAGS	  	:= -lm
MAINFILE    	:= knn

BUILDDIR      := build
SOURCES       := $(shell find * -path ScoopyArduino -prune -o -name "*.cpp" -print)
SRCNAMES			:=$(notdir $(SOURCES))
OBJECTS       := $(patsubst %,$(BUILDDIR)/%,${SOURCES:.cpp=.o})
#DIRS := $(find * -type f -name "*.cpp" | grep -v ScoopyArduino)
DEP := $(shell find $(BUILDDIR)/* -name *.d)

.DEFAULT_GOAL := bin
.PHONY: clean bin all run

-include $(DEP)

prepare:
	@echo $(SOURCES)

$(BUILDDIR)/%.o: %.cpp
	@echo "[\033[36mINFO\033[0m] Compiling object:" $<
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $@ $< -MMD -MF ./$@.d


$(MAINFILE) : $(OBJECTS)
	@echo "[\033[36mINFO\033[0m] Linking objects:" $@
	$(CXX) -o $@ $^ $(LIBFLAGS)

clean:						## cleans up project folder
	@echo "[\033[36mINFO\033[0m] Cleaning up folder..."
	rm -f $(MAINFILE)
	rm -rf ./$(BUILDDIR)

bin: prepare $(MAINFILE)	## compiles project to executable binary
	@echo "[\033[36mINFO\033[0m] Compiling binary..."
	chmod +x $(MAINFILE)

all: clean bin				## all of the above
	

run: all					## runs the project with default config
	@echo "[\033[36mINFO\033[0m] Executing binary..."
	./$(MAINFILE)


