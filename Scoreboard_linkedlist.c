#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{
	char *name;
	int hw[5];
	int sum;
	struct student *next;
}Student;

Student* getData(char *ptr){
	Student *newStudent =(Student *) malloc(sizeof(Student));
    newStudent->sum = 0;
    newStudent->next = NULL;
	char tmp[64];
	char *qtr = tmp;
	while(*ptr != ' '){
		*qtr++ = *ptr++;
	}
	*qtr = '\0';
	newStudent->name = strdup(tmp);
	memset(tmp, 0, sizeof(tmp));
	ptr++;
	int i;
	for(i = 0; i < 5; i++){
		qtr = tmp;
		while(*ptr != ' ' && *ptr != '\n'){
			*qtr++ = *ptr++;
		}
		*qtr = '\0';
		newStudent->hw[i] = atoi(tmp);
        newStudent->sum += newStudent->hw[i];
		memset(tmp, 0, sizeof(tmp));
		ptr++;
	}
	
	return newStudent;
}

int main(){
	char line[1024];
	Student *head = NULL;
	
	while(fgets(line, 1024, stdin)){
		Student *newStudent = getData(line);
        //printf("\n%s\t%d\t%d\t%d\t%d\t%d\nsum: %d\n", newStudent->name, newStudent->hw[0], newStudent->hw[1], newStudent->hw[2], newStudent->hw[3], newStudent->hw[4], newStudent->sum);
		if(head == NULL) head = newStudent;
		else{
			Student *cur = head;
			Student *pre = NULL;
			while(cur){
				if(newStudent->sum > cur->sum){
					if(pre == NULL){
                        newStudent->next = cur;
                        head = newStudent;
                    }
                    else{
                        pre->next = newStudent;
					    newStudent->next = cur;
                    }
					break;
				}
				else{
					pre = cur;
					cur = cur->next;
				}
			}
			if(cur == NULL){
				pre->next = newStudent;
			}
		}
	}
	
	Student *pre = head;
	Student *cur = head;
	while(cur){
		printf("%s\t%d\t%d\t%d\t%d\t%d\n", cur->name, cur->hw[0], cur->hw[1], cur->hw[2], cur->hw[3], cur->hw[4]);
		pre = cur;
		cur = cur->next;
		free(pre);
	}
	
	return 0;
}