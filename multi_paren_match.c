#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int top;
    int size;
    char *arr;
};
// isEmpty
int isEmpty(struct stack *sp){
    if (sp->top == -1)
    {
        return 1;
    }else{
        return 0;
    }
}
//isFull
int isFull(struct stack *sp){
    if (sp->top == sp->size-1)
    {
        return 1;
    }else{
        return 0;
    }
}
//push
void push(struct stack *sp, int data){
    if (isFull(sp))
    {
        printf("stack overflow!!!\n");
    }else{
        sp->top++;
        sp->arr[sp->top] = data;
    }
}
//pop
char pop(struct stack *sp){
    if (isEmpty(sp))
    {
        printf("stack underflow!!!\n");
    }else{
        char val = sp->arr[sp->top];
        sp->top--;
        return val;
    }
}
//match expression with popped charecter
int match(char a, char b){
    if(a=='{' && b=='}'){
        return 1;
    }
    if(a=='(' && b==')'){
        return 1;
    }
    if(a=='[' && b==']'){
        return 1;
    }
  return 0;  
}
 //matching multiple parentehesis
int parenthesisMatch(char * exp){
    // Create and initialize the stack
    struct stack* sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char popped_ch;
    for (int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            push(sp, exp[i]);
        }
        else if(exp[i]==')'|| exp[i]=='}' || exp[i]==']'){
            if(isEmpty(sp)){
                return 0;
            }
            popped_ch = pop(sp);
            if(!match(popped_ch, exp[i])){ 
              return 0;  
            }
        }
    }
    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    } 
}

int main()
{
    char *exp = "[4-6]((8){(9-8)})";;
    if (parenthesisMatch(exp))
    {
        printf("matched\n");
    }else{
        printf("not match\n");
    }
    
    return 0;
}
