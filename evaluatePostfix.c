#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

// Function to push an element onto the stack
void push(int ele) {
	//printf("\n%d",top);
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    else
    stack[++top] = ele;
    
}

// Function to pop an element from the stack
int pop() {
	int t;
	//printf("\n%d u pop",top);
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    else
    {
    	t=stack[top--];
	}
    
    return t;
}

// Function to evaluate a postfix expression
int evaluatePostfix(char *expr) {
    int i, op1, op2, res;

    for (i = 0; expr[i] != '\0'; i++) {
    //	printf("\n%c",expr[i]);
        if(expr[i]==' '){}
		
        else if (isdigit(expr[i])) {
            push(expr[i] - '0'); // Convert character digit to integer
        } else {
            op2 = pop();
            op1 = pop();
            switch (expr[i]) {
                case '+':
                    res = op1 + op2;
                    break;
                case '-':
                    res = op1 - op2;
                    break;
                case '*':
                    res = op1 * op2;
                    break;
                case '/':
                    if (op2 == 0) {
                        printf("Error: Division by zero\n");
                        exit(1);
                    }
                    res = op1 / op2;
                    break;
                default:
                    printf("Invalid operator: %c\n", expr[i]);
                    exit(1);
            }
          //  printf("\n%d",res);
            push(res);
        }
    }
   // printf("\nafter function %d",res);
   // res=pop();
   return pop();
}

int main() {
    char expr[MAX_SIZE];
    printf("Enter a postfix expression: ");
    //fgets(expr, MAX_SIZE, stdin);
    gets(expr);
     
    // printf("\nFinal top=%d",top);
    int result =evaluatePostfix(expr); 
    printf("Result: %d\n", result);


}
