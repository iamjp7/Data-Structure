#include<stdio.h>
#include<string.h>
#include<malloc.h>
struct nodes{
    char info[5];
    struct nodes *next;
};
typedef struct nodes node;
node *insert_at_front(node *head,char a[]){
    node *aa;
    aa=(node *)malloc(sizeof(node));
    strcpy(aa->info,a);
    node *p=head;
    if (head==NULL){
        aa->next=NULL;
        return aa;
}
    else{
        aa->next=head;
        return aa;}
}
node *delete_at_last(node *head){
    if(head==NULL)
        return NULL;
    else{
        node *p=head;
        node *q=NULL;
        while(p->next!=NULL){
            q=p;
            p=p->next;
        }
        if (q==NULL)
            return NULL;
        else{
            q->next=NULL;
            free(p);
            return head;
        }
    }
}
node *store(node *head,char arr[],char brr[]){
    int aa=strlen(arr);
    int bb=strlen(brr);
    int carry=0;
    while (aa!=0 || bb!=0){
        int j=0;
        int num1=0;
        int num2=0;
        int k=1;
        while(j<4 && aa!=0){
            num1+=(arr[aa-1]-48)*k;
            j+=1;
            aa-=1;
            k*=10;
        }
        j=0;
        k=1;
        while(j<4 && bb!=0){
            num2+=(brr[bb-1]-48)*k;
            j+=1;
            bb-=1;
            k*=10;
        }
        int num3=num2+num1+carry;
        carry=num3/10000;
        num3=num3%10000;
        char prr[5];
        int i=3;
        while(i>=0){
            prr[i]=(num3%10+48);
            num3/=10;
            i-=1;
        }
        prr[4]='\0';
        head=insert_at_front(head,prr);


    }
    if(carry!=0){
        char ls[2];
        ls[0]=carry+48;
        ls[1]='\0';
        head=insert_at_front(head,ls);
    }
    return head;
}
node * reverse(node *head){
    if((head==NULL))
        return head;
    node *p=head;
    node *q=head->next;
    head->next=NULL;
    while(q!=NULL){
        node *w=q->next;
        q->next=p;
        p=q;
        q=w;}
    return p;
        }

void display(node *head){
    if (head==NULL){
        printf("no element");
        return;}
    node *p=head;
    while(p!=NULL){
        printf("%s",p->info);
        p=p->next;
    }
    printf("\n");
}

main(){
    node *head=NULL;
    char arr[100];
    char crr[100];
    printf("enter the first number\n");
    scanf("%s",arr);
    printf("enter the second number\n");
    scanf("%s",crr);
    int aa=strlen(arr);
    int bb=strlen(crr);
    head=store(head,arr,crr);
    display(head);
}