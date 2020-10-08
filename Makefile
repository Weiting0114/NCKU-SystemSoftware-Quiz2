CC = gcc
FLAGS=-O2 -Wall -Wextra

GIT_HOOKS := .git/hooks/applied
all: $(GIT_HOOKS) test1
clean:
	rm -rf test1

$(GIT_HOOKS):
	@scripts/install-git-hooks
	@echo

test1: test1.c
	gcc $(FLAGS) -Wall test1.c -o test1