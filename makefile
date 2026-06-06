CFLAGS =  -Iincludes
SRC = src/main.c src/repository.c
OBJ = main.o repository.o

program: $(OBJ)
	gcc $(OBJ) -o program

main.o: src/main.c
	gcc $(CFLAGS) -c src/main.c

repository.o: src/repository.c
	gcc $(CFLAGS) -c src/repository.c

clean:
	rm -f *.o program