/**
 * Program to convert an arithmetic expression from infix to postfix
 * 
 * @Prerna(1910990964)
 * 
 * Assignment_4 - Stacks and Queues
 *
 */
 

#include <stdio.h>
#include<string.h>
#include<stdlib.h>

char *stack;
int top = -1;//when stack is empty
int size = 1;


void increase_size() {
    size = size * 2;
    stack = realloc(stack, size * sizeof(char));
}

// add element to the stack 
// if stack is full increase size of the stack to push more elements

void push(char value) {
    if(top == size ) {
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


// only returns top element of stack

char peek() {
    if(top > -1) {
        return stack[top];
    }
}

//return integer precedence of given operator
int precedence(char ch) {
    if(ch == '/' || ch == '*') {
        return 2;
    }
    else if(ch == '+' || ch == '-') {
        return 1;
    }
    else {
        return -1;
    }
}

void postfix(char * str) {
    
    char ans[100];
    int index = 0; // index to be updated when we insert in the answer string
    
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] >= '0' && str[i] <= '9') {
            ans[index++] = str[i];
        }
        else if(str[i] == '/' || str[i] == '*' || str[i] == '-' || str [i] == '+') {
            while(size != -1 && precedence(str[i]) <= precedence(peek())) {
                ans[index++] = peek();
                pop();
            }
            
            push(str[i]);
        }
        else if(str[i] == '(') {
            push(str[i]);
        }
        else if(str[i] == ')') {
            //keep poping top element till closing bracket
            while(peek() != '(') {
                ans[index++] = peek();
                pop();
            }
            pop();
        }
    }
    while(top != -1) {
        ans[index++] = pop();
    }
    
    //setting last element of ans to null
    
    ans[index++] = '\0';
    printf("%s",ans);
}

int main() {
	char str[100];
	scanf("%s",str);
	
	postfix(str);
	return 0;
}

