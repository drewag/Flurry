OUT := flurry_core.a

BUILD_DIRECTORY := out
CC := g++
CFLAGS := -c -Wall -g -fPIC
# Add this to C Flags to show debug output on console for searchers
#-DSEARCHER_DEBUG=true

INCLUDE := -I./inc -I./packages/boost
SRC_DIR := src
SOURCES := $(shell find $(SRC_DIR) -type f -name '*.cpp' | tr '\n' ' ' )
OBJECTS := $(SOURCES:.cpp=.o)
OUT_OBJECTS := $(subst $(SRC_DIR), $(BUILD_DIRECTORY), $(OBJECTS))

all: $(OUT)

%.a:
	@cd `dirname $@`; make

$(BUILD_DIRECTORY):
	@mkdir -p $(BUILD_DIRECTORY)

$(OUT): $(BUILD_DIRECTORY) $(OUT_OBJECTS)
	@echo Linking...
	@ar rcs $(OUT) $(LIBS) $(OUT_OBJECTS)
	@echo done

out/%.o: $(SRC_DIR)/%.cpp
	@echo $<
	@$(CC) $(CFLAGS) $(INCLUDE) $< -o $@

clean:
	@rm -rf $(BUILD_DIRECTORY)
	@rm -f $(OUT)
