CFALGS = -Wall -Werror -Wextra -pedantic -std=c89

git:
	@git add .
	@git commit -m "$m"
	@git push

clear:
	@rm monty

build:
	@gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty

run: build
	@./monty code
run_m: build
	@valgrind ./monty code
