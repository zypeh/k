SOURCES=$(wildcard src/*.c) $(wildcard src/*.s)
HEADERS=$(wildcard src/*.h)
CFLAGS=-Wall -Wextra -Werror

k0: $(SRC) $(HEADERS)
	clang $(CFLAGS) -o "$@" $(SOURCES)
