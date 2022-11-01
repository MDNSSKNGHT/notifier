X11 := -lX11
FLAGS := -Wall -Wextra -O0
CC := cc

build:
	mkdir -p out
	${CC} main.c ${FLAGS} ${X11} -o out/main
clean:
	rm -r out

run: build
	./out/main
