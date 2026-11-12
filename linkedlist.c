#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node*next;
}node;
void traversal(node*head);
node*insertatbegin(node*head,int val);
node*insertatend(node*head,int val);
node*indertatpos(node*head,int val,int pos);
node*deleteatfront(node*head);
node*dleeteatend(node*head);
node*deleteatpos(node*head,int pos);
node*deleteval(node*head,int val);
node*deletealloccurences(node*head,int val);

int main(){
    node* head=NULL;
    head=insertatbeg(head,10);
    head=insertatend(head,12);
    head=insertatend(head,15);
    head=insertatend(head,19);
    head=insertatend(head,21);
    head=insertatend(head,19);
    head=insertatend(head,4);
    head=insertatpos(head,18,2);
    head=deleteatfront(head);
    head=deleteatend(head);
    head=deleteatpos(head,1);
    head=deleteval(head,21);
    head=deletealloccurences(head,19);
    traversal(head);
    return 0;
}
void traversal(node*head){  
    if(head==NULL){
        return NULL;
    }
    node*n=head;
    while (n!=NULL){
        printf("%d ",n->data);
        n=n->next;
    }
}
node* insertatbeg(node *head,int val){
     if(head==NULL){
        return NULL;
    }
    node*new=malloc (sizeof(node));
    new->data=val;
    new->next=head;
    head=new;
    return head;


}
node* insertatend(node*head,int val){
     if(head==NULL){
        return NULL;
    }
    node*n=head;
    node *new= malloc(sizeof(node));
    new->data=val;
    while(n->next!=NULL){
        n=n->next;
    }
    n->next=new;
    new->next=NULL;
    return head;
}
node *insertatpos(node*head,int val,int pos){
     if(head==NULL){
        return NULL;
    }
    node*n=head;
    node*new= malloc(sizeof(node));
    new->data=val;
    for(int i=0;i<pos-1;i++){
        n=n->next;
    }
    new->next=n->next;
    n->next=new;
    return head;
}
node*deleteatfront(node*head){
    node*temp=head;
    head=head->next;
    free(temp);
    return head;
}
node*deleteatend(node*head){
     if(head==NULL){
        return NULL;
    }
    node*n=head;
    while(n->next->next!=NULL){
        n=n->next;
    }
    free(n->next->next);
    n->next=NULL;
    return head;
}
node*deleteatpos(node*head,int pos){
     if(head==NULL){
        return NULL;
    }
    node*n=head;
    node*temp;
    for(int i=0;i<pos-1;i++){
        n=n->next;
    }
    temp=n->next;
    n->next=n->next->next;
    free(temp);
    return head;
}
node* deleteval(node*head,int val){
     if(head==NULL){
        return NULL;
    }
    node*n=head;
    while(n->next!=NULL && n->next->data!=val){
        n=n->next;
    }
    node*temp=n->next;
    n->next=n->next->next;
    free(temp);
    return head;
}
node*deletealloccurences(node*head,int val){
    while(head!=NULL && head->data==val){
        node*temp=head;
        head=head->next;
        free(temp);
    }
    if(head==NULL){
        return NULL;
    }
    node*n=head;
    while(n->next!=NULL){
    if(n->next->data==val){
     node*temp=n->next;
      n->next=n->next->next;
        free(temp);
     }
     else{
     n=n->next;
     }
    }
    return head;
    }