#include <stdio.h>
#include<ctype.h>
#define MAX_SIZE 30

char stack[MAX_SIZE];
int top = -1;

void push(char item) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';  // Return a null character to indicate error
    }
    return stack[top--];
}

int pri(char ch) {
    if (ch == '^' || ch == '$') {
        return 2;
    } else if (ch == '*' || ch == '/') {
        return 1;
    } else if (ch == '+' || ch == '-') {
        return 0;
    } else {
        return -1;  // Return -1 for invalid operators
    }
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE], ch;
    int i, j;

    printf("Enter an infix expression: ");
    fgets(infix, MAX_SIZE, stdin);  // Use fgets instead of gets for safety

    i = 0;
    j = 0;

    while (infix[i] != '\0') {
        if (infix[i] == ' ') {
            i++;
        } else if (isalnum(infix[i])) {  // Check for alphanumeric characters
            postfix[j++] = infix[i++];
        } else if (infix[i] == '(') {
            push(infix[i++]);
        } else if (infix[i] == ')') {
            while ((ch = pop()) != '(') {
                postfix[j++] = ch;
            }
            i++;
        } else {  // Handle operators
            while (top != -1 && pri(stack[top]) >= pri(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i++]);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';  // Add null terminator to the postfix expression

    printf("Postfix expression: %s", postfix);

    return 0;
}
