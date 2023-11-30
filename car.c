#include<stdio.h>
#include<stdlib.h>
struct Node{
    int num;
    struct Node *next;
};
struct Node *add(struct Node *head,int data){
    struct Node *p=head;
    while(p->num!=0 && p->next!=NULL){
        p=p->next;
    }
    if(p->num==0){
    p->num=data;
    return(head);
    }
    else{
        printf("parking slot is filled\n");
        return(head);
    }
}
void display(struct Node *head){
    while(head!=NULL){
        if(head->num!=0){
            printf("|");
            printf("  %d \t",head->num);
            printf("| \t");
        }
        else{
            printf("|");
            printf("empty space \t");
            printf("|\t");
        }
        head=head->next;
    }
}
struct Node *del(struct Node *head,int data){
    if(head->num==0){
        printf("their are no cars in parking slot\n");
        return(head);
    }
    else{
    struct Node *p=head;
    while(p->num!=data && p->next!=NULL){
        p=p->next;
    }
    if(p->num!=data){
        printf("invalid car number\n");
        return(head);
    }
    else{
    p->num=0;
    return(head);
    }
    }
}
void length(struct Node *head){
    int c=0;
    while(head!=NULL){
        if(head->num!=0){
            c++;
        }
        head=head->next;
    }
    printf("their are %d cars in parking slot\n",c);
}
struct Node *change(struct Node *head,int data,int new){
    struct Node *ptr=head;
    int c=0;
    while(ptr!=NULL){
        if(ptr->num!=0){
            c++;
        }
        ptr=ptr->next;
    }
    if(c==0){
        printf("their are no cars in parking slot to change the car number\n");
        return(head);
    }
    else{
    struct Node *ptr=head;
    while(ptr->num!=data && ptr->next!=NULL){
        ptr=ptr->next;
    }
    if(ptr->num!=data){
        printf("car number doesn't match\n");
        return(head);
    }
    else{
        ptr->num=new;
        return(head);
    }
    }
}
int main(){
    struct Node head=(struct Node)malloc(sizeof(struct Node));
    struct Node second=(struct Node)malloc(sizeof(struct Node));
    struct Node third=(struct Node)malloc(sizeof(struct Node));
    struct Node fourth=(struct Node)malloc(sizeof(struct Node));
    struct Node five=(struct Node)malloc(sizeof(struct Node));
    head->num=0;
    second->num=0;
    third->num=0;
    fourth->num=0;
    five->num=0;
    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=five;
    five->next=NULL;
    int ch,data,new;
    while(1){
        printf("\n\n*** WELCOME TO PARKING SLOT ***\n\n");
        printf("1.add a car\n");
        printf("2.remove a car\n");
        printf("3.display the  slot\n");
        printf("4.number of cars\n");
        printf("5.change the car number\n");
        printf("6.exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("enter the car number\n");
                    scanf("%d",&data);
                    head=add(head,data);
                    break;
            case 2:printf("enter the car number\n");
                    scanf("%d",&data);
                    head=del(head,data);
                    break;
            case 3:display(head);
                    break;
            case 4:length(head);
                    break;
            case 5:printf("enter the car number to change(old)\n");
                    scanf("%d",&data);
                    printf("enter the new car number\n");
                    scanf("%d",&new);
                    head=change(head,data,new);
                    break;
            case 6:exit(0);
                    break;
            default:printf("invalid input from user\n");
        }
    }
}