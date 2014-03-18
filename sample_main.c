#include <stdio.h>
#include <longest_common_subsequence.h>


int main(int argc, char *argv[]){
    char *lcs_str;
    printf("7:%d\n", LCS("zuotian", "zQuQoQtQiQaQnQ", &lcs_str));
    printf("%s\n", lcs_str);
    
    printf("3:%d\n", LCS("abc", "dabbc", &lcs_str));
    printf("%s\n", lcs_str);
    return 0;
}

