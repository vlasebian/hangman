TAGS=-Wall -g -c
COMPILER=gcc
.PHONY: build run clean

build: hangman

hangman: hangman.o read.o game.o drawing.o menu.o hiddenExpression.o panel.o
		$(COMPILER) hangman.o read.o game.o drawing.o menu.o hiddenExpression.o panel.o -o hangman -lncurses

hangman.o: hangman.c
		$(COMPILER) $(TAGS) hangman.c -o hangman.o

hiddenExpression.o: hiddenExpression.c hiddenExpression.h
		$(COMPILER) $(TAGS) -g -c hiddenExpression.c -o hiddenExpression.o

drawing.o: drawing.c drawing.h
		$(COMPILER) $(TAGS) -g -c drawing.c -o drawing.o

game.o: game.c game.h
		$(COMPILER) $(TAGS) -g -c game.c -o game.o

read.o: read.c read.h
		$(COMPILER) $(TAGS) -g -c read.c -o read.o

panel.o: panel.c panel.h
		$(COMPILER) $(TAGS) -g -c panel.c -o panel.o

menu.o: menu.c menu.h
		$(COMPILER) $(TAGS) -g -c menu.c -o menu.o

run: hangman
		./hangman README hangman.c Makefile

clean:
		rm -f hangman.o hangman read.o game.o drawing.o menu.o hiddenExpression.o panel.o 

