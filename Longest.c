#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Maxline 2048

int main(){
	char line[Maxline];
	char lword[Maxline];
	char word[Maxline];
	int lcnt = 0;
	char *target_h, *target_t, *qtr;
	
	while(fgets(line, Maxline, stdin)){
		if(line[strlen(line)-1] == '\n') line[strlen(line)-1] = '\0';
		target_h = line;
		target_t = line;
		qtr = word;

		while(target_h && target_t){
			if((target_h = strstr(target_h, "「"))){
				//printf("in 1-1 loop\n");
				if(target_t = strstr(target_t, "」")){
					//printf("in 1-2 loop\n");
					target_h += strlen("「");
					while(target_h < target_t) *qtr++ = *target_h++;
					*qtr = '\0';
					//printf("%s\n", word);
					if(strlen(word) > lcnt){
						lcnt = strlen(word);
						strcpy(lword, word);
					}
					memset(word, 0, sizeof(word));
					qtr = word;
					target_h += strlen("」");
					target_t += strlen("」");
					//printf("%s\n%d\n", lword, lcnt);
				}
				else {
					target_t = target_h;
					target_h += strlen("「");
					target_t += strlen("「");
				}
			}
			else{
				target_h = target_t;
			}
			if((target_h = strstr(target_h, "『"))){
				//printf("in 2-1 loop\n");
				if(target_t = strstr(target_t, "』")){
					//printf("in 2-2 loop\n");
					target_h += strlen("『");
					while(target_h < target_t) *qtr++ = *target_h++;
					*qtr = '\0';
					if(strlen(word) > lcnt){
						lcnt = strlen(word);
						strcpy(lword, word);
					}
					memset(word, 0, sizeof(word));
					qtr = word;
					target_h += strlen("』");
					target_t += strlen("』");
				}
				else {
					target_t = target_h;
					target_h += strlen("『");
					target_t += strlen("『");
				}
			}
		}
	}
	printf("%s\n", lword);
	
	return 0;
}