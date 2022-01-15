clean:
	rm -rf ./bin

bin:
	mkdir ./bin
	cc ./main.c -o ./bin/a.out
