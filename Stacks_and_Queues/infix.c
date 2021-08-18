#include <stdio.h>

char stack[100];
int top = -1;

void push(char ch) {
    if(top >= 100) {
        printf("Overflow");
    }
    
    top++;
    stack[top] = ch;
     
}

void pop() {
    
    
    top--;
    
}

int is_empty() {
    if(top == -1) {
        return 1;
    }
    
    return 0;
}



int checkprior(char ch) {
    
    int prior = 0;
    switch(ch) {
        case '(':
            prior = 0;
            break;
        case '/':
            prior = 4;
            break;
        case '*':
            prior = 3;
            break;
        case '+':
            prior = 2;
            break;
        case '-':
            prior = 1;
            break;
        
    }
    
    return prior;
}


void postfix(char input[]) {
    
    int k = 0;
    char last;
    int lastprior = 0;
    int currentprior = 0;
    char output[100];
    
    for(int i = 0; input[i] != '\0'; i++) {
        
        if(input[i] == '(') {
            push(input[i]);
        }
        
        else if(input[i] >= '0' && input[i] <= '9') {
            output[k++] = input[i];
            
        }
        
        else if(input[i] == '/' || input[i] == '*' || input[i] == '+' || input[i] == '-') {
            currentprior = checkprior(input[i]);
            if(is_empty()) {
                push(input[i]);
                continue;
            }
            
            last = stack[top];
            lastprior = checkprior(last);
            
            if(lastprior > currentprior) {
                last = stack[top];
                push(input[i]);
                output[k++] = last;
            
            }
            else if(lastprior == currentprior) {
                last = stack[top];
                push(input[i]);
                output[k++] = last;
            }
            else {
                push(input[i]);
            }
        }
        
        else if(input[i] == ')') {
            last = stack[top];
            if(last == '(') {
                pop();
                continue;
            }
            
            if(last == '/' || last == '*' || last == '+' || last == '-' ) {
                output[k++] = last;
                pop();
                pop();
            }
        }
        
    }
    
    output[k] = '\0';
    
    printf("%s",output);
    
    
    
}

int main()
{
    char input[100] = "(1+((3-1)*(4/2)))";
    
    postfix(input);

    return 0;
}

