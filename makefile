CC := gcc

CFLAGS := -g -Wall -Wextra -Iinclude -MMD -MP
LDFLAGS := -lm
VALGRIND_FLAGS := --leak-check=full

SRCDIR := src
BINDIR := bin
OBJDIR := $(BINDIR)/obj

SOURCES := $(wildcard $(SRCDIR)/**/*.c $(SRCDIR)/*.c)
OBJECTS := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.c=.o))
TARGET := test

.PHONY: all clean valgrind sanitize

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $^ -o $(BINDIR)/$@ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

-include $(OBJECTS:.o=.d)

.PHONY: run clean valgrind sanitize 
#.PHONY: lint valgrind clean run

#lint:
#	cppcheck $(SRC)
#	clang-format -i $(SRC)

valgrind: 
	valgrind $(VALGRIND_FLAGS) ./$(BINDIR)/$(TARGET)

clean:
	rm -r $(BINDIR)/*

run: 
	./$(BINDIR)/$(TARGET)

sanitize: clean compile_sanitize

CFLAGSSANITIZER := -Wall -Wextra -Iinclude -fsanitize=address -static-libasan -MMD -MP
LDFLAGSSANITIZER := -lm -fsanitize=address -static-libasan

compile_sanitize: CFLAGS += -fsanitize=address
compile_sanitize: LDFLAGS += -fsanitize=address
compile_sanitize: $(OBJECTS)
	$(CC) $^ -o $(BINDIR)/$(TARGET) $(LDFLAGSSANITIZER)

#$(OBJDIR)/%.o: $(SRCDIR)/%.c
#@mkdir -p $(@D)
#$(CC) $(CFLAGS) -c $< -o $@

