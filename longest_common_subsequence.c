
/* 计算两个字符串s1, s2的最长公共子序列 (Longest Common Subsequence)，
   采用自顶向下的动态规划方法实现。
   计算包括1. 计算最长公共子序列的长度
           2. 返回其中一个最长公共子序列

   1. 计算最长公共子序列的长度
      假设有两个字符串s1和s2，函数LCS_length(i,j)表示计算s1第i个字符开始的子串
      和s2第j个字符开始的子串的最长公共子序列的长度，(i,j>=0)。
      则LCS_length(0, 0)即为字符串s1和s2的最长公共子串的长度。
   
      递推公式如下—— s1[i]表示字符串s1的第i个字符。
      LCS_length(i, j) = LCS_length(i+1, j+1) + 1                 (if s1[i] == s2[j])
      LCS_length(i, j) = max(LCS_length(i+1, j), LCS_length(i, j+1)) (if s1[i] != s2[j])
   
      实现时用一个二维矩阵_matrix来保存中间结果,_matrix[i][j]保存的
      就是LCS_length(i, j)的值。
      
   2. 返回其中一个最长公共子序列
      根据二维矩阵_matirx保存的中间结果，可以回溯得到最长公共子序列。
      我的实现只返回其中一个最长公共子序列 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* _s1,_s2用于保存字符串s1, s2,
   设置2这两个变量是为了减少函数的参数数量 */
static char *_s1;
static char *_s2;
static int _len_s1; //字符串s1的长度
static int _len_s2; //字符串s2的长度。

/* 二维矩阵用于保存中间结果，_matrix[i][j]表示s1第i个字符开始的子串
   和s2第j个字符开始的子串的最长公共子序列的长度 */
static int **_matrix; 
static int _matrix_row_size = 0; //二维矩阵_matrix的行数
static int _matrix_collumn_size = 0; //二维矩阵_matrix的列数
#define UNKNOWN -1 //二维矩阵_matrix的初始值


/* 初始化字符串变量_s1, _s2, _len_s1, _len_s2
   为二维矩阵分配空间，并重置矩阵初始值为UNKNOWN */
static void LCS_init(char *s1, char *s2){
    _s1 = s1;
    _s2 = s2;
    _len_s1 = strlen(_s1);
    _len_s2 = strlen(_s2);

    if (_len_s1 > _matrix_row_size || _len_s2 > _matrix_collumn_size){
	/* free matrix memory */
	for (int i = 0; i < _matrix_row_size; i++)
	    free(_matrix[i]);
	free(_matrix);
	
	/* malloc matrix memory */
	_matrix = (int **)malloc(_len_s1 * sizeof(int *));
	for (int i = 0; i < _len_s1; i++)
	    _matrix[i] = (int *)malloc(_len_s2 * sizeof(int));

	_matrix_row_size = _len_s1;
	_matrix_collumn_size = _len_s2;
    }
    
    /* reset default value UNKNOWN for matrix */
    for (int i = 0; i < _len_s1; i++)
	for (int j = 0; j < _len_s2; j++)
	    _matrix[i][j] = UNKNOWN;
}


/* 计算s1从index_s1开始的子串和s2从index_s2开始的子串
   的最长公共子序列的长度 */
static int LCS_length(int index_s1, int index_s2){
    if (index_s1 >= _len_s1 || index_s2 >= _len_s2)
	return 0;

    if (_matrix[index_s1][index_s2] != UNKNOWN)
	return _matrix[index_s1][index_s2];
    
    if (_s1[index_s1] == _s2[index_s2])
	return _matrix[index_s1][index_s2] = LCS_length(index_s1+1, index_s2+1) + 1;
    else{
	int a = LCS_length(index_s1, index_s2+1);
	int b = LCS_length(index_s1+1, index_s2);
	return _matrix[index_s1][index_s2] = a>=b?a:b;
    }
}


/* 根据二维矩阵回溯得到最长公共子序列 */
static char* LCS_str(){
    // 为最长公共子序列开辟内存空间
    int index = 0;
    char *str = (char *)malloc(sizeof(char) * _len_s1>=_len_s2?_len_s1:_len_s2);
    
    int i = 0, j = 0; //index of s1 and s2
    while(i < _len_s1 && j < _len_s2){
	/* 如果_s1[i]等于_s2[j]，_s1[i]在最长公共子序列中 */
	if (_s1[i] == _s2[j]){
	    str[index++] = _s1[i];
	    i++; j++;
	    continue;
	}

	/* 如果_s1[i]不等于_s2[j]，则_matirx[i][j]的值等于
	   _matrix[i+1][j]或者_matrix[i][j+1]，_matrix[i][j]的值
	   等于哪个决定了是s1[i]还是s2[j]不在最长公共子序列中 */
	if(i+1 == _len_s1 || _matrix[i][j] != _matrix[i+1][j])
	    j++;
	else //j+1 == _len_s2 || _matrix[i][j] != _matrix[i][j+1]
	    i++;
    }
    str[index] = '\0';
    return str;
}

/* 入口函数
   接受两个字符串S1 S2为输入
   最长公共子序列通过参数LONGEST_COMMON_SUBSEQUENCE返回，
   最长公共子序列的长度通过返回值返回 */
int LCS(char *s1, char *s2, char **longest_common_subsequence){
    if (s1 == NULL || s2 == NULL || strlen(s1) == 0 || strlen(s2) == 0)
	return 0;

    LCS_init(s1, s2);
    int longest_length = LCS_length(0, 0);
    *longest_common_subsequence = LCS_str();
    return longest_length;
}


