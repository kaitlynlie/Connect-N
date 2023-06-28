connectn.out: main.o setup.o game.o
	gcc -g -Wall -Werror -o connectn.out main.o setup.o game.o

main.o: main.c setup.h game.h
	gcc -g -Wall -Werror -c main.c

setup.o: setup.c setup.h
	gcc -g -Wall -Werror -c setup.c

game.o: setup.h game.c game.h
	gcc -g -Wall -Werror -c game.c

clean:
	rm -f *.o *.out
