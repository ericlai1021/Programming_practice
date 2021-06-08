#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void getToken(char *ptr, char *source, char *delima){
    while(*ptr != ' ') *source++ = *ptr++;
    *source = '\0';
    ptr++;
    while(*ptr != '\0') *delima++ = *ptr++;
    *delima = '\0';
}

int main(){
    char line[1024];    //輸入字串
    char Output[2048];  //輸出字串
    char *ptr, *qtr, *cur;
    char source[1024];
    char delima[1024];
    int len;

    while(fgets(line, 1024, stdin) != NULL){
        len = strlen(line);
        if (line[len - 1] == '\n') line[len - 1] = '\0';
        getToken(line, source, delima);
        if(strcmp(source, delima) == 0){
            printf("empty string\n");
            continue;
        }
        ptr = source; //ptr指向輸入字串
        cur = source;  //cur指向目前在輸入字串的哪個位置
        qtr = Output;   //qtr指向輸出字串
        while((ptr = strstr(ptr, delima)) != NULL){
            if(ptr != cur){
                while(cur < ptr){
                    *qtr++ = *cur++;
                }
                *qtr++ = ',';
            }
            ptr += strlen(delima);
            cur += strlen(delima);
        }
        //把輸入字串除了delima之外的都複製到輸出字串
        ptr = source+strlen(source);
        if(ptr == cur) *--qtr = '\0';
        while(cur < ptr){
            *qtr++ = *cur++;
        }
        *qtr = '\0';
        printf("%s\n", Output);
        //清除輸入跟輸出字串，以便給下一筆資料使用
        memset(line, '\0', 1024);
        memset(source, '\0', 1024);
        memset(delima, '\0', 1024);
        memset(Output, '\0', 2048);
    }

    return 0;
}
