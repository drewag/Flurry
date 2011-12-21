OUT := flurry

BUILD_DIRECTORY := out
CC := g++
CFLAGS := -c -Wall -g -fPIC
LDFLAGS := -ldl

INCLUDE := -I./inc -I./core/inc
SRC_DIR := src
LIBRARIES := core/flurry_core.a
SOURCES := $(shell find $(SRC_DIR) -type f -name '*.cpp' | tr '\n' ' ')
OBJECTS := $(SOURCES:.cpp=.o)
OUT_OBJECTS := $(subst $(SRC_DIR), $(BUILD_DIRECTORY), $(OBJECTS))

all: $(OUT) $(MODULES)

$(BUILD_DIRECTORY):
	@mkdir -p $(BUILD_DIRECTORY)

$(OUT): $(LIBRARIES) $(BUILD_DIRECTORY) $(OUT_OBJECTS)
	@echo Linking...
	@$(CC) $(LDFLAGS) $(INCLUDE) $(OUT_OBJECTS) $(LIBRARIES) -o $@
	@echo done

CORE_SRC := $(shell find core \( -name '*.cpp' -o -name '*.h' \) | tr '\n' ' ')
core/flurry_core.a: $(CORE_SRC)
	@echo ----------------------------------------------------
	@echo " Making core..."
	@echo ----------------------------------------------------
	@cd core; make
	@echo

out/%.o: $(SRC_DIR)/%.cpp
	@echo $<
	@$(CC) $(CFLAGS) $(INCLUDE) $< -o $@

clean:
	@rm -rf $(BUILD_DIRECTORY)
	@rm -f $(OUT)

clean_core:
	@cd core; make clean
