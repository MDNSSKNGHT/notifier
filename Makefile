X11 := -lX11
FLAGS := -Wall -Wextra -O0
CC := cc
NAME := notifier

build: *.c
	@mkdir -p out
	@${CC} $^ ${FLAGS} ${X11} -o out/${NAME}

clean:
	@rm -r out

run: build
	@./out/${NAME}
