#include<stdio.h>
#include<stdbool.h>
#define capacity 100
typedef struct que{
    int arr[capacity];
    int front;
    int rear;
}que;
void init(que *q){
    q->front=-1;
    q->rear=-1;
}
bool isfull(que *q){
    if(q->rear==capacity-1) return true;
    else return false;
}
bool isempty(que *q){
    if(((q->front)>(q->rear))|| q->front==-1) return true;
    else return false;
}
void enqueue(que *q,int val){
    if(isfull(q)) printf("already full\n");
    else { 
        if (isempty(q)){
            q->rear++;
            q->front++;
        }
        else q->rear++;
        q->arr[q->rear]=val;
    }
}
void dequeue(que*q){
    if(isempty(q)) printf("queue is empty\n");
    else printf("%d ",q->arr[q->front++]);
} 
void peek(que *q){
    if(isempty(q)) printf("queue is empty\n");
    else printf("%d ",q->arr[q->front]);
}
int main(){
    que q;
    init(&q);
    dequeue(&q);
    enqueue(&q,10);
    enqueue(&q,19);
    dequeue(&q);
    dequeue(&q);
    peek(&q);
    return 0;
}