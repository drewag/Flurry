OUT := flurry_core.a

BUILD_DIRECTORY := out
CC := g++
CFLAGS := -c -Wall -g -fPIC

INCLUDE := -I./inc
SRC_DIR := src
SOURCES := $(shell find $(SRC_DIR) -type f -name '*.cpp' | tr '\n' ' ' )
OBJECTS := $(SOURCES:.cpp=.o)
OUT_OBJECTS := $(subst $(SRC_DIR), $(BUILD_DIRECTORY), $(OBJECTS))

all: $(OUT)

$(BUILD_DIRECTORY):
	@mkdir -p $(BUILD_DIRECTORY)

$(OUT): $(BUILD_DIRECTORY) $(OUT_OBJECTS)
	@echo Linking...
	@ar rcs $(OUT) $(OUT_OBJECTS)
	@echo done

out/%.o: $(SRC_DIR)/%.cpp
	@echo $<
	@$(CC) $(CFLAGS) $(INCLUDE) $< -o $@

clean:
	@rm -rf $(BUILD_DIRECTORY)
	@rm -f $(OUT)
