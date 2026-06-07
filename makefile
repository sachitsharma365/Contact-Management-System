CFLAGS =  -Iincludes
SRC = src/main.c src/repository.c src/helper_funs.c
OBJ = main.o repository.o helper_funs.o

program: $(OBJ)
	gcc $(OBJ) -o program

main.o: src/main.c
	gcc $(CFLAGS) -c src/main.c

repository.o: src/repository.c
	gcc $(CFLAGS) -c src/repository.c

helper_funs.o: src/helper_funs.c
	gcc $(CFLAGS) -c src/helper_funs.c
	
clean:
	rm -f *.o program