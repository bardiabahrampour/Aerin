CXX = g++
TARGET = app

SRC_DIR = src
BUILD_DIR = build

CXXFLAGS = -std=c++20 -Wall -Wextra -Wpedantic
CPPFLAGS = -Iinclude
LDFLAGS =
LDLIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SOURCES = $(shell find $(SRC_DIR) -name '*.cc')
OBJECTS = $(patsubst $(SRC_DIR)/%.cc,$(BUILD_DIR)/%.o,$(SOURCES))
DEPS = $(OBJECTS:.o=.d)

.PHONY: all debug release clean run

all: release

release: CXXFLAGS += -O2 -DNDEBUG
release: $(TARGET)

debug: CXXFLAGS += -O0 -g
debug: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(OBJECTS) $(LDFLAGS) $(LDLIBS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc
	@mkdir -p $(@D)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -MMD -MP -c $< -o $@

-include $(DEPS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)