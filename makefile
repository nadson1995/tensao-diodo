build: main.c
	gcc main.c -w -o main.exe
run: build main.exe
	./main.exe argumento1 argumento2 <0.in
	./main.exe argumento1 argumento2 <1.in
	./main.exe argumento1 argumento2 <2.in
	./main.exe argumento1 argumento2 <3-c.in
run2: build main.exe
	./main.exe 