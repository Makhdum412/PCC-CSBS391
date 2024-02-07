#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;


void push(int ele) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    } else
        stack[++top] = ele;
}


int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    } else {
        return stack[top--];
    }
}


int evaluatePostfix(char *expr) {
    int i, op, res;

    for (i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == ' ') {
            continue;
        } else if (isdigit(expr[i])) {
           
            int num = 0;
            while (isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            i--; 
            push(num);
        } else {
            int op2 = pop();
            int op1 = pop();
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
            push(res);
        }
    }
    return pop();
}

int main() {
    char expr[MAX_SIZE];
    printf("Enter a postfix expression: ");
    gets(expr);

    int result = evaluatePostfix(expr);
    printf("Result: %d\n", result);

    return 0;
}
