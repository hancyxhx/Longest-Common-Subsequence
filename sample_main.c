#include <stdio.h>
#include <longest_common_subsequence.h>


int main(int argc, char *argv[]){
    /* To get sample_s2, I insert 'Q' between every character of sample_s1.
       So the length of the longest common subsequence of the two strings
       is 9, which is the length of sample_s1 */
    char *sample_s1 = "yesterday";
    char *sample_s2 = "yQeQsQtQeQrQdQaQy"; 
    printf("first sample string: %s\n", sample_s1);
    printf("second sample string: %s\n", sample_s2);
    
    char *lcs_str;    
    int len = LCS(sample_s1, sample_s2, &lcs_str);
    printf("the length of the longest common subsequence is: %d\n", len);
    printf("the longest common subsequence is: %s\n", lcs_str);
    
    return 0;
}

