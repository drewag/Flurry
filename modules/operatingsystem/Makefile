OUT := ../operatingsystem.so

BUILD_DIRECTORY := out
CC := g++
CFLAGS := -Wall -fPIC -g
# OS X
LINKER_FLAGS := -Wl,-all_load
AFTER_LINKER_FLAGS :=

# LINUX
#LINKER_FLAGS := -Wl,--whole-archive
#AFTER_LINKER_FLAGS := -Wl,-no-whole-archive

INCLUDE := -I./inc -I../../core/inc
LIBRARIES := ../../core/flurry_core.a

SRC_DIR := src
SOURCES := $(shell find $(SRC_DIR) -type f -name '*.cpp' | tr '\n' ' ' )
OBJECTS := $(SOURCES:.cpp=.o)
OUT_OBJECTS := $(subst $(SRC_DIR), $(BUILD_DIRECTORY), $(OBJECTS))

all: $(OUT)

$(BUILD_DIRECTORY):
	@mkdir -p $(BUILD_DIRECTORY)

$(OUT): $(BUILD_DIRECTORY) $(OUT_OBJECTS) $(LIBRARIES)
	@echo Linking...
	@$(CC) $(CFLAGS) $(LINKER_FLAGS) $(LIBRARIES) $(AFTER_LINKER_FLAGS) -shared $(OUT_OBJECTS) -o $@
	@echo done

out/%.o: $(SRC_DIR)/%.cpp
	@echo $<
	@$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

clean:
	@rm -rf $(BUILD_DIRECTORY) $(LIB_FOLDERS)
	@rm -f $(OUT)
