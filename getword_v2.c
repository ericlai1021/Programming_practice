#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

unsigned char* getword(unsigned char *ptr, char *word)
{
	char *qtr;

	qtr = word;
	if(*ptr == '\0') return NULL;
	while(isspace(*ptr)) ptr++;
	
	if(*ptr >= 240){	// 11110XXX 10yyyyyy 10yyyyyy 10yyyyyy
		*qtr++ = *ptr++;
		*qtr++ = *ptr++;
		*qtr++ = *ptr++;
		*qtr++ = *ptr++;
		*qtr = '\0';
	}
	else if(*ptr >= 224){	// 1110XXXX 10yyyyyy 10yyyyyy
		*qtr++ = *ptr++;
		*qtr++ = *ptr++;
		*qtr++ = *ptr++;
		*qtr = '\0';
	}
	else if(*ptr >= 192){	// 110XXXXX 10yyyyyy
		*qtr++ = *ptr++;
		*qtr++ = *ptr++;
		*qtr = '\0';
	}
	else if(*ptr >= 128){	// error
		*qtr = '\0';
		ptr++;
	}
	else{	// ASCII
		while(!isspace(*ptr) && *ptr != '\0'){
			*qtr++ = *ptr++;
		}
		*qtr = '\0';
	}
	if(qtr == word)
		return NULL;
	else
		return ptr;
}

int main(){
	char line[1024];
	char word[64];
	unsigned char *ptr;
	
	while(fgets(line, 1024, stdin)){
		ptr =(unsigned char *) line;
		while((ptr = getword(ptr, word))){
			if(word[0] == '\0'){
				printf("illegal code\n");
			}
			else{
				printf("%s\n", word);
			}
		}
	}
}