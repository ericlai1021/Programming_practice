#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char list[32][1024];
char tmpA[32][1024];
char tmpB[32][1024];

// Merge two subarrays of A[].
// First subarray is arr[head..mid]
// Second subarray is arr[mid+1..tail]
void merge(int head, int mid, int tail){
	int lenA = mid - head + 1;
	int lenB = tail - (mid + 1) + 1;

	//Copy data to temp arrays A[] and B[]
	int i, j, k;
		for(i = 0; i < lenA; i++) {strcpy(tmpA[i], list[head + i]);}
		for(i = 0; i<lenB; i++) {strcpy(tmpB[i], list[mid + 1 + i]);}
		i = 0;
		j = 0;
		k = head;
		//while array A and B haven't finished scanning
		while(i < lenA && j < lenB){
			if(strcmp(tmpA[i], tmpB[j]) < 0){
				strcpy(list[k], tmpA[i]);
				i++;
			}
			else{
				strcpy(list[k], tmpB[j]);
				j++;
			}
			k++;
		}
		//Copy the remaing elements into arr[], if A[] haven't finished scanning
		while(i < lenA){
			strcpy(list[k], tmpA[i]);
			i++;
			k++;
		}
		//Copy the remaing elements into arr[], if B[] haven't finished scanning
		while(j < lenB){
			strcpy(list[k], tmpB[j]);
			j++;
			k++;
		}
}

void merge_sort(int head, int tail){
	if(head < tail){
		int mid = (head + tail) / 2;
		merge_sort(head, mid);
		merge_sort(mid+1, tail);
		merge(head, mid, tail);
	}
}

void rmNewline(char *line){
    while(*line != '\n' && *line != '\0') line++;
    *line = '\0';
    return;
}

int main(){
	// 產生亂數資料
    int cnt = 0;
	char line[1024];
    while(fgets(line, 1024, stdin)){
        rmNewline(line);
        strcpy(list[cnt], line);
        //printf("%s\n", list[cnt]);
        cnt++;
    }
	
	merge_sort(0, cnt-1);

    for(int i = 0; i < cnt; i++){
        printf("%s\n", list[i]);
    }

	return 0;
}