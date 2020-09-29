all: make_exec then

make_exec:
	gcc cat.c -o cat
	gcc ls.c -o ls
	gcc remove.c -o remove
	gcc mkdir.c -o mkdir
	gcc date.c -o date

then:
	gcc shell.c
	./a.out