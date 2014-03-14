/* Longest Common Subsequence */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static char *_s1;
static char *_s2;
static int _len_s1;
static int _len_s2;

static int **_matrix;
static int _matrix_row_size = 0;
static int _matrix_collumn_size = 0;
#define UNKNOWN -1

static void init(char *s1, char *s2){
    _s1 = s1;
    _s2 = s2;
    _len_s1 = strlen(_s1);
    _len_s2 = strlen(_s2);

    if (_len_s1 > _matrix_row_size || _len_s2 > _matrix_collumn_size){
	/* free matrix */
	for (int i = 0; i < _matrix_row_size; i++)
	    free(_matrix[i]);
	free(_matrix);
	
	/* malloc matrix */
	_matrix = (int **)malloc(_len_s1 * sizeof(int *));
	for (int i = 0; i < _len_s1; i++)
	    _matrix[i] = (int *)malloc(_len_s2 * sizeof(int));
    }
    
    /* init default value for matrix */
    for (int i = 0; i < _len_s1; i++)
	for (int j = 0; j < _len_s2; j++)
	    _matrix[i][j] = UNKNOWN;
}


static int cal_LCS(int index_s1, int index_s2){
    if (index_s1 >= _len_s1 || index_s2 >= _len_s2)
	return 0;

    if (_matrix[index_s1][index_s2] != UNKNOWN)
	return _matrix[index_s1][index_s2];
    
    if (_s1[index_s1] == _s2[index_s2])
	return _matrix[index_s1][index_s2] = cal_LCS(index_s1+1, index_s2+1) + 1;
    else{
	int a = cal_LCS(index_s1, index_s2+1);
	int b = cal_LCS(index_s1+1, index_s2);
	return _matrix[index_s1][index_s2] = a>=b?a:b;
    }
}


int LCS(char *s1, char *s2){
    if (s1 == NULL || s2 == NULL || strlen(s1) == 0 || strlen(s2) == 0)
	return 0;

    init(s1, s2);
    return cal_LCS(0, 0);
}


/* int main(int argc, char *argv[]){ */
/*     printf("7:%d\n", LCS("zuotian", "zQuQoQtQiQaQnQ")); */
/*     printf("3:%d\n", LCS("abc", "dabbc")); */

/*     return 0; */
/* } */
