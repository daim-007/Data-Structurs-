#include<stdio.h>
#include<stdlib.h>
typedef struct snode{
    int data;
    struct snode*next;
}snode;
int isempty(snode*head){
    if(head==NULL) return 1;
    else return 0;
}
snode* push(snode*head,int val){    // insertion at front  O(1)
    snode*new=malloc(sizeof(snode));
    new->data=val;
    new->next=head;
    head=new;
    return head;
}
snode* pop(snode*head){    // deletion at front O(1)
    if(isempty(head)) {printf("\nalready empty");exit (0);} 
    printf("%d ",head->data);
    snode* temp=head;
    head=head->next;
    free(temp);
    return head;

}
snode* peek(snode*head){
    if(isempty(head)) {printf("\nalready empty");exit (0); }
    printf("%d ", head->data);
    return head;
}
int main(){
    snode*head=NULL;
    head= push(head,10);
    head=push(head,11);
    head=push(head,12);
    head=push(head,13);
    head=peek(head);
    head=pop(head);
    head=pop(head);
    head=pop(head);
    head=pop(head);
    head=pop(head);
    return 0;

}