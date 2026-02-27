CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -MMD -MP
LDFLAGS :=

TARGET := game
SRCS := $(wildcard *.cc)
OBJS := $(patsubst %.cc,build/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

build/%.o: %.cc | build
	$(CXX) $(CXXFLAGS) -c $< -o $@

build:
	mkdir -p build

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf build $(TARGET)

-include $(DEPS)
