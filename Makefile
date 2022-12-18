OUT =		notifier
OBJ =		battery.o x.o
CC ?=		cc

LIB =		`pkg-config --libs x11`

CFLAGS =	-Wall -Wextra -O0

all: $(OUT)

.c.o:
	@$(CC) -c $(CFLAGS) $<

$(OUT): main.o $(OBJ)
	@$(CC) $(LDFLAGS) $^ $(LIB) -o $@

test: test.o $(OBJ)
	@$(CC) $(LDFLAGS) $^ $(LIB) -o $@

clean:
	rm -rf main.o test.o $(OBJ) $(OUT)
