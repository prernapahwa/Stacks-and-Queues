/* Implementing stack using queues
 *
 * @Prerna(1910990964)
 *
 * Assignment_4-Stacks and Queues
 */ 

typedef struct {
    int *stack;
    int top;
    int bottom;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *obj = malloc(sizeof(MyStack));
    obj -> stack = malloc(101 * sizeof(int));
    obj -> top = 0;
    obj -> bottom = 0;
    return obj;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj ->stack[obj -> top] = x;
    obj -> top = obj -> top + 1;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    obj -> top = obj -> top -1;
    return obj ->stack[obj -> top];
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj ->stack[obj -> top - 1];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if(obj -> top == 0) {
    return true;
    }
    return false;
}

void myStackFree(MyStack* obj) {
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
