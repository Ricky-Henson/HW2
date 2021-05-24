all: main.o Generate.o bst.o arr.o bs.o ll.o hash.o
	gcc main.o Generate.o bst.o arr.o bs.o ll.o hash.o -o all

main.o: main.c
	gcc -c main.c

Generate.o: Generate.c
	gcc -c Generate.c

bst.o: bst.c
	gcc -c bst.c

bs.o: bs.c
	gcc -c bs.c

arr.o: arr.c
	gcc -c arr.c

ll.o: ll.c
	gcc -c ll.c

hash.o: hash.c
	gcc -c hash.c

clean:
	rm *.o all
