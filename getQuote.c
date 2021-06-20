#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char line[2048], word[2048];
	char *ptr, *qtr;
	int flag = 0;

	while(fgets(line, 2048, stdin)){
		if(line[strlen(line)-1] == '\n') line[strlen(line)-1] = '\0';
		ptr = line;
		qtr = word;

		while(*ptr != '\0'){
			if(*ptr == '"'){
				flag++;
				ptr++;	// !!!
			}
			if(flag == 1) *qtr++ = *ptr++;
			else if(flag == 2){
				*qtr = '\0';
				printf("%s\n", word);
				memset(word, 0, sizeof(word));
				flag = 0;
				qtr = word;
			}
			else ptr++;
		}
	}

	return 0;
}
