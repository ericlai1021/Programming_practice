#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char name[1024];
    struct node *left;
    struct node *right;
} Node;

Node* Insert(Node *cur, char *pat){
    if(cur != NULL){
        if(strcmp(pat, cur->name) <= 0) cur->left = Insert(cur->left, pat);
        else if(strcmp(pat, cur->name) > 0) cur->right = Insert(cur->right, pat);
    }
    else{
        cur =(Node *) malloc(sizeof(Node));
        strcpy(cur->name, pat);
        cur->left = NULL;
        cur->right = NULL;
    }
    return cur;
}

void in_order(Node* cur){
    if(cur == NULL) return;
    in_order(cur->left);
    printf("%s\n", cur->name);
    in_order(cur->right);
}

void Pre_order(Node* cur){
    if(cur == NULL) return;
    printf("%s\n", cur->name);
    Pre_order(cur->left);
    Pre_order(cur->right);
}

void Post_order(Node* cur){
    if(cur == NULL) return;
    Post_order(cur->left);
    Post_order(cur->right);
    printf("%s\n", cur->name);
}

int Search(Node *cur, char *line){
    while(cur){
        if(strcmp(cur->name, line) == 0) return 0;
        if(strcmp(line, cur->name) < 0) cur = cur->left;
        else if(strcmp(line, cur->name) > 0) cur = cur->right;
    }
    return 1;
}

void rmnewline(char *line)
{
	char *ptr = line;
	while(ptr != NULL && *ptr!= '\n') ptr++;
	*ptr = '\0';
}


int main(int argc, char *argv[]){
    char line[1024];
    Node *root = NULL;

    while(fgets(line, 1024, stdin)){
        rmnewline(line);
        if(Search(root, line)){
            root = Insert(root, line);
        }
    }
    if(strcmp(argv[1], "-p") == 0) Pre_order(root);
    else if(strcmp(argv[1], "-P") == 0) Post_order(root);
    else if(strcmp(argv[1], "-i") == 0) in_order(root);
}