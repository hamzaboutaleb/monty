CFALGS = -Wall -Werror -Wextra -pedantic -std=c89

git:
	@git add .
	@git commit -m "$m"
	@git push

clear:
	@rm monty

build:
	@gcc ${CFLAGS} *.c -o monty

run: build
	@./monty "$f"
