#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


int main(int argc, char **argv){
    FILE *fp;

    fp = fopen(argv[1], "r");
    char ch;
    char word[2048] = {'\0'};
	int cnt = 0;
    //printf("%s\n",argv[argc-1]);
    while((ch = getc(fp)) != EOF){
		word[cnt++] = ch;
    }
	fclose(fp);
	
	fp = fopen(argv[1], "w");
	
	//printf("cnt: %d\n", cnt);
    for(int i = cnt-1; i >= 0; i--){
        fprintf(fp,"%c",word[i]);
    }
	fclose(fp);
    return 0;
}