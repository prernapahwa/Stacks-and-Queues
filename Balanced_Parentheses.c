/*Program to checCk Balanced Parantheses
 *
 *@Prerna(1910990964)
 *Assignment-4-Stacks and Queues
 */

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

char *stack;
int top = -1;//stack is empty
int size = 1;

//function to increase size to 2 * initial size.
//
void increase_size() {
    size = size * 2;
    //printf("SIZE %d \n",size);
    stack = realloc(stack, size * sizeof(char));
}

void push(char value) {
    if(top == size) {
        //have to increase size.
        increase_size();
    }
    stack[++top] = value;
}

//remove top element and return
char pop() {
    if(top > -1) {
        return stack[top--];
    }
}

//only returns top element of the stack
char peek() {
    if(top > -1) {
        return stack[top];
    }
}


bool balanced(char *str) {
    int i = 0;
    while(str[i] != '\0') {
       // printf("%c ",str[i]);
        if(str[i] == '(' || str[i] == '{' || str[i] == '[') {
            push(str[i]);
            //printf("%c",str[i]);
        }
        else if(top >= 0){
            //printf("%c",str[i]);
            if(str[i] == ')' && peek() != '(') {
                return false;
            }
            else if(str[i] == ']' && peek() != '[') {
                return false;
            }
            else if(str[i] == '}' && peek() != '{') {
                return false;
            }
            pop();
        }
        else {
            return false;
        }
        
        i++;
    }
    if(top == -1) {
        return true;
    }
    return false;
}

int main() {
    stack = (char *) malloc(sizeof(char));
    char str[20];
    gets(str);
    //printf("%s",str);
    bool ans = balanced(str);
    if(ans == true) {
        printf("True\n");
    }
    else {
        printf("False\n");
    }
}

