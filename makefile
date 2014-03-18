
all : liblongest_common_subsequence.a sample_main.out

sample_main.out : sample_main.c liblongest_common_subsequence.a longest_common_subsequence.h
	gcc -std=c99 -o $@ sample_main.c -L. -llongest_common_subsequence -I.

liblongest_common_subsequence.a : longest_common_subsequence.o
	ar -rcs $@ longest_common_subsequence.o

longest_common_subsequence.o : longest_common_subsequence.c
	gcc -std=c99 -o $@ -c longest_common_subsequence.c

clean :
	rm -rf longest_common_subsequence.o
	rm -rf liblongest_common_subsequence.a
	rm -rf sample_main.out
