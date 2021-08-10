/*Program to find minimum element from stack in constant time 
 *
 * @Prerna(1910990964) 
 *
 * Leetcode 155
 *
 * Assignment_4-Stacks and Queues
 *
 */



typedef struct 
{
    int data[30000];   
    int top;
    int min;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() 
{
    MinStack * stack = (MinStack *)malloc(sizeof(MinStack));
    stack -> top = -1;
    stack -> min = INT_MAX;
    return stack;
}

int isStackEmpty(MinStack *obj)
{
    if(obj -> top == -1) {
        return 1;
    }
        return 0;
}

int is_empty(MinStack *obj)
{
    if(obj -> top == 30000 - 1) {
        return 1;
    }
        return 0;
}

void minStackPush(MinStack* obj, int val) 
{
    if(is_empty(obj))
        return;
    
    obj -> data[++(obj -> top)] = val;
    if(val <= obj -> min)
    {
        obj -> min = val;
    }
}

void minStackPop(MinStack* obj) 
{
    if(isStackEmpty(obj))
        return;
    
    int pop_element = obj -> data[(obj -> top) --];
    if(pop_element == obj -> min)
    {
        //Search for the new min
        int i=0;
        obj->min = INT_MAX;
        for(i = 0; i <= obj -> top; i++)
        {
            if(obj -> data[i] <= obj->min)
            {
                obj -> min = obj -> data[i];
            }
        }
    }
}

int minStackTop(MinStack* obj) 
{
    return obj -> data[obj -> top];
}

int minStackGetMin(MinStack* obj) 
{
    return obj -> min;
}

void minStackFree(MinStack* obj) 
{
    free(obj);    
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
