Summary
--------------------------

This is an C language implement of algorithm to solve Longest Common Subsequence problem. According to Wikipedia, 'The longest common subsequence (LCS) problem is to find the longest subsequence common to all sequences in a set of sequences'.  

By now, only suport to find TWO string's longest common subsequence. Giving two c string, the library function would return one of the longest common subsequences and its length. It's very easy to use.  

(Note: A subsequence is different from a substring, for the terms of the former need not be consecutive terms of the original sequence.If you are inserested in solving Longest Common Substring, you may refer to [Longest-Common-Substring](https://github.com/hancyxhx/Longest-Common-Substring) )  


Usage:
--------------------------

step 1:  

    git clone https://github.com/hancyxhx/Longest-Common-Subsequence
step 2:  

    cd Longest-Common-Subsequence/
step 3:  

    make
step 4:  
if every thing works fine, you can find these file in the directory  

    liblongest_common_subsequence.a
    longest_common_subsequence.h

copy them to your project, then add command like below to your makefile  
(say you put liblongest_common_subsequence.a in the directory named LIB_FILE_PATH,  
put longest_common_subsequence.h in the directory named HEAD_FILE_PATH)  

    gcc -std=c99 -o YOUR_MAIN.out YOUR_MAIN.c -L LIB_FILE_PATH -l longest_common_subsequence -I HEAD_FILE_PATH


TODO List
--------------------------
1. write usage document  
2. suport return multi longest-common-subsequences if there are  
3. translate comment to english  
