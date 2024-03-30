#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode {
    void* data;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
} Stack;

StackNode* newNode(void* data)
{
    StackNode* stackNode = (StackNode*)malloc(sizeof(StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

Stack* createStack()
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void push(Stack* stack, void* data)
{
    StackNode* stackNode = newNode(data);
    stackNode->next = stack->top;
    stack->top = stackNode;
}

int isEmpty(Stack* stack)
{
    return stack->top == NULL;
}

void* pop(Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    StackNode* temp = stack->top;
    stack->top = stack->top->next;
    void* popped = temp->data;
    free(temp);
    return popped;
}

int main()
{
    Stack* my_stack = createStack();

    push(my_stack, "apple");
    push(my_stack, "phone");
    push(my_stack, 'dash'); 
    push(my_stack, NULL); 
    push(my_stack, (void*)7865); 
   

    while (!isEmpty(my_stack))
    {
        printf("%p\n", pop(my_stack));
    }

    return 0;
}
