#include <stdio.h>
#include <stdbool.h>

char stack[100];
int top = -1;

void push(char ch) {
    if(top >= 100) {
        printf("Stack Overflow");
    }
    top++;
    stack[top] = ch;
    
}

void pop(){
    top--;
}


bool checkmatch(char ch1, char ch2) {
    if((ch1 == '{' && ch2 == '}') || (ch1 == '(' && ch2 == ')') || (ch1 == '[' && ch2 == ']')) {
        return true;
    }
    
    return false;
}

bool checkbalance(char *str) {
    
    bool res;
    char rec;
    
    for(int i = 0; str[i] != '\0'; i++) {
    
        if(str[i] == '{' || str[i] == '(' || str[i] == '[') {
        
            push(str[i]);
            continue;
        } 

        else if(str[i] == '}' || str[i] == ')' || str[i] == ']') {
            
             rec = stack[top];
             res = checkmatch(rec,str[i]);
             if(!res) { 
                 return false;  
             }
             pop();
        }

    }
    return true;

}

int main() {
   
   /*
    char ch[20];
    printf("Enter the brackets");
    scanf("%s",&ch);
    */
    char ch[20] = "{()}()[]";
    bool res = checkbalance(ch);
    if(res) {
        printf("True");
    }
    else {
        printf("False");
    }
    
    return 0;
}



