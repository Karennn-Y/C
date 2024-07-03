///
/// @brief  :
/// @file   : tokenizer.c
/// @date   : 2024년 6월 19일 수요일 15시 54분 02초 KST
/// @author : Karen
///
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    char buff[1024];
    char *prtn;

    memset(buff, 0x00, 1024);
    strcpy(buff, "strtok first,second,third");

    prtn = strtok(buff, " ");
    printf("First : %s\n", prtn);

    printf("원본 : %s\n", buff);

    while(1) {
        prtn = strtok(NULL, ",");
        if (prtn == NULL) break;
        printf("%s\n", prtn);
    }
}
