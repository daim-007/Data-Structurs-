#include<stdio.h>
#include<stdlib.h>
typedef struct dnode{
    int data;
    struct dnode*next;
    struct dnode*prev;
}dnode;
void traversal(dnode*head){
    dnode*p=head;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}
dnode* insertatbegin(dnode*head,int val){
    dnode*new=malloc(sizeof(dnode));
    new->data=val;
    new->prev=NULL;
    new->next = head;
    if (head!=NULL){
        head->prev=new;
    }
     head=new;
    return head;
}
dnode*insertatend(dnode*head,int val){
    dnode*new=malloc(sizeof(dnode));
    new->data=val;
    dnode*n=head;
    if(head==NULL){
        return NULL;
    }
    while(n->next!=NULL)
        n=n->next;
    new->prev=n;
    n->next=new;
    new->next=NULL;
    return head; 

}
dnode*insertatany(dnode*head,int val,int pos){
    dnode*new=malloc(sizeof(dnode));
    new->data=val;
    dnode*n=head;
    for(int i=0;i<pos;i++){
        n=n->next;
    }
    new->next=n;
    new->prev=n->prev;
    n->prev->next=new;
    n->prev=new;
    return head;

}
dnode*deleteatfront(dnode*head){
    if(head==NULL){
        return NULL;
    }
    dnode*temp=head;
    head=head->next;
    head->prev=NULL;
    free(temp);
    return head;
}
dnode*deleteatend(dnode*head){
    dnode*n=head;
    if(head==NULL){
        return NULL;
    }
    while(n->next!=NULL){
        n=n->next;
    }
    n->prev->next=NULL;
    free(n);
    return head;

}
dnode*deleteatpos(dnode*head,int pos){
    if(head==NULL){
        return NULL;
    }
    dnode*n= head;
    for(int i=0;i<pos;i++){
        n=n->next;
    }
    n->prev->next=n->next;
    n->next->prev=n->prev;
    free(n);
    return head;
}
int main(){
    dnode*head=NULL;
    head=insertatbegin(head,18);
    head=insertatbegin(head,10); 
    head=insertatbegin(head,45);
    head=insertatany(head,22,1);
    head=insertatany(head,33,1);
    head=deleteatfront(head);
    head=deleteatend(head);
    head=deleteatpos(head,1);
    traversal(head);
    return 0;
}