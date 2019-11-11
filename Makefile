CC=gcc

utils: list_int.o

list_int.o: src/list_int.c src/list_int.h
	mkdir build
	mkdir build/lib
	gcc -c src/list_int.c -o build/lib/list_int.o

test: list_int.o
	gcc test/test_list_int.c build/lib/list_int.o -o test/test

clean:
	rm -rf test/*.o
	rm -rf test/test
	rm -rf build

run-test: test
	./test/test

