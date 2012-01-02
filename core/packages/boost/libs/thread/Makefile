OUT := thread.a

BUILD_DIRECTORY := out
CC := g++
CFLAGS := -c -Wall -g -fPIC

INCLUDE := -I../../
SRC_DIR := src
SOURCES := $(shell find src -name '*.cpp' | grep -v 'win32' | tr '\n' ' ' )
OBJECTS := $(SOURCES:.cpp=.o)
OUT_OBJECTS := $(subst $(SRC_DIR), $(BUILD_DIRECTORY), $(OBJECTS))

all: $(OUT)

$(OUT): $(OUT_OBJECTS)
	@echo Linking...
	@ar rcs $(OUT) $(OUT_OBJECTS)
	@echo done

out/%.o: $(SRC_DIR)/%.cpp
	@echo $<
	@mkdir -p `dirname $@`
	@$(CC) $(CFLAGS) $(INCLUDE) $< -o $@

clean:
	@rm -rf $(BUILD_DIRECTORY)
	@rm -f $(OUT)
