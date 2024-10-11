#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

//Stack structure
typedef struct{
    char exp[MAX_SIZE];
    int top;
}Stack;

//Intitializing stack
void initialize(Stack *stack){
    stack->top = -1;
}

//Checking to see if stack is empty
int isEmpty(Stack *stack){
    return stack->top == -1;
}

//Checking to see if stack is full
int isFull(Stack *stack){
    return stack->top == MAX_SIZE - 1;
}

//Function for pushing expression into stack
void push(Stack *stack, char expres){
    if(isFull(stack)){
        printf("Stack Full\n");
        return;
    }
    stack->exp[++(stack->top)] = expres; //Increment top and add the element to the stack
}

//Function for poping out expression from stack
char pop(Stack *stack){
    if(isEmpty(stack)){
        printf("Empty\n");
        return '\0';
    }
    return stack->exp[(stack->top)--]; //Return the top element and decrement top
}

//Function for checking if expressions are balanced
int parenbal(char *expression){
    Stack stack;
    initialize(&stack);

    for(int i = 0; i < strlen(expression); i++){
        char ch = expression[i];

        //Push opening expression
        if(ch == '(' || ch == '{' || ch == '['){
            push(&stack, ch);
        }
        else if(ch == ')' || ch == '}' || ch == ']'){
            if(isEmpty(&stack)){
                return 0; //Unbalanced due to no opening(match) expression present
            }
            char top = pop(&stack); //Pop closing expression

            if((ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '[')){
                return 0; //Unbalanced due to mismatch expression
            }
        }
    }
    return isEmpty(&stack); //Balanced if stack is empty
}


int main()
{

    char expression[MAX_SIZE];
    printf("Enter expression: ");
    //User input for string (assuming expression only)
    fgets(expression, MAX_SIZE, stdin);

    //Removing newline character when trying to evaluate for balancing
    size_t length = strlen(expression);
    if(length > 0 && expression[length - 1] == '\n'){
        expression[length - 1] == '\0';
    }

    //Calling function to check if expression is balanced
    if(parenbal(expression)){
        printf("Balanced!!!\n");
    }
    else{
        printf("Not Balanced \n");
    }

    return 0;
}