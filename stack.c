#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define capacity 100 
typedef struct stack{
    int arr[capacity];
    int top ;
}stack;
void initstack(stack *s){
    s->top=-1;
}
bool isfull(stack *s){
    if(s->top==(capacity-1)) return true;
    else return false;
}
bool isempty(stack *s){
    if(s->top==-1) return true;
    else return false;
} 
void push (stack *s,int val){
    if(isfull(s)) printf("stack already full\n"); 
    else s->arr[++s->top]=val;
}
void pop(stack *s){
    if(isempty(s)) printf("stack already empty\n");
    else printf("%d ", s->arr[s->top--]);
}
void peek(stack*s){
    if(isempty(s)) printf("stack empty\n");
    else printf("%d ", s->arr[s->top]);
}
int main(){
    stack s;
    initstack(&s);
    push(&s,10);
    push(&s,20);
    push(&s,30);
    pop(&s);
    peek(&s);
}