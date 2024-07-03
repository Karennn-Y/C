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
    int idx = 0;

    char token[4][255];

    memset(buff, 0x00, 1024);

    for(int i = 0; i < 4; i++) {
        memset(token[i], 0x00, 255);
    }

    strcpy(buff, "strtok first,second,third");

    printf("원본 : %s\n", buff);

    prtn = strtok(buff, " ");
    memcpy(token[idx++], prtn, strlen(prtn));

    while(1) {
        prtn = strtok(NULL, ",");
        if (prtn == NULL) break;
        memcpy(token[idx++], prtn, strlen(prtn));
    }

    for (int i = 0; i < 4; i++) {
        printf("%d번째 값 : %s\n", i, token[i]);
    }
}
