CC = gcc -std=gnu11
DEFINES = 
CFLAGS = -c $(addprefix -D,$(DEFINES))
LFLAGS =
LIBS = 

SRC = $(wildcard *.c)
OBJ = $(SRC:%.c=obj/%.o)
TARGET = test.out

all: $(TARGET)

$(TARGET):$(OBJ)
	@mkdir -p $(@D)
	$(CC) $(LFLAGS) -o $@ $^ $(addprefix -l,$(LIBS))

obj/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $<

clear:
	@rm -r obj *.out 2> /dev/null || true

debug: CC += -g
debug: DEFINES += DEBUG
debug: clear all
