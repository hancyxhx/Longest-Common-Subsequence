
all : liblcs.a sample_main.out

sample_main.out : sample_main.c liblcs.a longest_common_subsequence.h
	gcc -std=c99 -o $@ sample_main.c -L. -llcs -I.

liblcs.a : longest_common_subsequence.o
	ar -rcs liblcs.a longest_common_subsequence.o

longest_common_subsequence.o : longest_common_subsequence.c
	gcc -std=c99 -o $@ -c longest_common_subsequence.c

clean :
	rm -rf longest_common_subsequence.o
	rm -rf liblcs.a
	rm -rf sample_main.out
