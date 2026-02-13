//C program to evaluate value of postfix expression
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Stack Type 
struct Stack
{
    int top;
    unsigned capacity;
    int* array;
};

// stack operations 
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    
    if(!stack)
      return NULL;  
      
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    
    if(!stack)
        return NULL;
        
    return stack;
    
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

char peek(struct Stack* stack)
{
    return stack->array[stack->top];
}

char pop(struct Stack* stack)
{
    if(!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

void push(struct Stack* stack, char op)
{
    stack->array[++stack->top] = op;
}
// the main function that returns value of a given postfix expression

int evaluatePostfix(char* exp)
{
    // Create a stack of capacity eqaul to expression sizeof
    struct Stack* stack = createStack(strlen(exp));
    int i;
    // see if stack is was created successfully
    if(!stack)
        return -1;
        
    // scan all character one by one 
    for (i = 0; exp[i]; i++)
    {
         //Scan All Character is an opened
        // (number here), push it to the stack.
    
        if(isdigit(exp[i]))
            push(stack, exp[i] - '0');
        
        // if the scanned Character is an operator ,
        // pop two element from stack apply the operator
    
        else {
            int val1 = pop(stack);
            int val2 = pop(stack);
        
            switch (exp[i])
            {
                case '+': push(stack, val2 + val1); break;
                case '-': push(stack, val2 - val1); break;
                case '*': push(stack, val2 * val1); break;
                case '/': push(stack, val2 / val1); break;
            }
        }
    }
        
   
    return pop(stack);
}

int main()
{
    char exp[] = "593*+3-"; 
        printf("Input Postfix expression: %s",exp);
    // function call
    printf("\npostfix evaluation: %d",evaluatePostfix(exp));
    
    return 0;
}
