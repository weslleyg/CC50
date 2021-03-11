all: caesar crack hash

caesar: caesar.c
	gcc -ggdb -std=c99 -Wall -Werror -Wformat=0 -o caesar caesar.c -lcc50 -lm
	
crack: crack.c
	gcc -ggdb -std=c99 -Wall -Werror -Wformat=0 -o crack crack.c -lcc50 -lm -lcrypt

hash: hash.c
	gcc -ggdb -std=c99 -Wall -Werror -Wformat=0 -o hash hash.c -lcc50 -lm -lcrypt