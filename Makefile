OUT =		notifier
OBJ =		battery.o x.o
CC ?=		cc

LIB =		`pkg-config --libs x11`

CFLAGS =	-Wall -Wextra -O0

PREFIX ?=	/usr

all: $(OUT)

.c.o:
	@$(CC) -c $(CFLAGS) $<

$(OUT): main.o $(OBJ)
	@$(CC) $(LDFLAGS) $^ $(LIB) -o $@

test: test.o $(OBJ)
	@$(CC) $(LDFLAGS) $^ $(LIB) -o $@

install:
	@install -D $(OUT) $(PREFIX)/bin
	@cp -r runit/notifier-service /etc/runit/sv
	@touch /etc/runit/sv/notifier-service/down

uninstall:
	@rm -rf $(PREFIX)/bin/$(OUT)
	@rm -rf /etc/runit/sv/notifier-service

clean:
	rm -rf main.o test.o $(OBJ) $(OUT)
