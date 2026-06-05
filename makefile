CFLAGS =  -Iincludes
SRC = src/main.c src/add-contact.c
OBJ = main.o add-contact.o

program: $(OBJ)
	gcc $(OBJ) -o program

main.o: src/main.c
	gcc $(CFLAGS) -c src/main.c

add-contact.o: src/add-contact.c
	gcc $(CFLAGS) -c src/add-contact.c

clean:
	rm -f *.o program