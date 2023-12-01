.PHONY: help

all: main  # Build all targets

help: # Show help for each of the Makefile recipes.
	@printf "\n"
	@grep -E '^[a-z].*:.*'  Makefile | while read -r l; do printf "\033[1;32m$$(echo $$l | cut -f 1 -d':')\033[00m:$$(echo $$l | cut -f 2- -d'#')\n"; done
	@printf "\n"

main: displayBook.c changeContact.c searchContact.c workWithFiles.c main.c
	gcc displayBook.c changeContact.c searchContact.c workWithFiles.c main.c -o main

clean: # Delete all builded files
	rm -f main