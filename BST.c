#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* right;
    struct node* left;
}node;

int insert(node* root,int key){
    if(root==NULL){node* keys=malloc(sizeof(node));
    keys->data=key;
    root=keys;return key;}
    else{
        if(root->data<key){
            if(root->right==NULL){
                node* keys=malloc(sizeof(node));
                keys->data=key;
                root->right=keys;
                return key;
            }
            return insert(root->right,key);
        }
        else if(root->data>key){
            if(root->left==NULL){
                node* keys=malloc(sizeof(node));
                keys->data=key;
                root->left=keys;
                return key;
            }
            return insert(root->left,key);
        }
return (key+1);
    }
}

node* search(node* root,int key){
    if(root==NULL)return root;
    else{
        if(root->data==key)return root;
        else if(root->data<key){
            return search(root->right,key);
        }
        else return search(root->left,key);
    }
}

node* searchParent(node* a,node* b,int key){
    if(b==NULL)return b;
    else{
        if(b->data==key){
            return a;
        }
        else if(b->data<key){
            return searchParent(b,b->right,key);
        }
        else{
            return searchParent(b,b->left,key);
        }
    } 
}

node* rotateright(node* q){
    node* y=q->left;
    node* z=q->left->right;
    q->left=z;
    y->right=q;
    return y;
}

int delete(node *root,int key){
    node* a=NULL;
    node* p=searchParent(a,root,key);
    node* q=search(root,key);
    if(p==NULL && q==NULL)return (key+1);
    else if(q->left==NULL){
        if(p->right==q){
            p->right=q->right;
            free(q);
        }
        else if(p->left==q){
            p->left=q->right;
            free(q);
        }
    }
    else if(q->right==NULL){
        if(p->right==q){
            p->right=q->left;
            free(q);
        }
        else if(p->left==q){
            p->left=q->left;
            free(q);
        }
    }
    else{
        if(p->right==q){
            for(int i=0;i>=0;i++){
                p->right=rotateright(q);
                p=p->right;
                if(q->left==NULL){
                    p->right=q->right;
                    free(q);
                    break;
                }
            }
        }
        else{
            for(int i=0;i>=0;i++){
                p->left=rotateright(q);
                p=p->left;
                if(q->left==NULL){
                    p->right=q->right;
                    free(q);
                    break;
                }
            }
        }
    }
    return key;
}

node* successor(node* root,int key){
    node* p=search(root,key);
if(p==NULL)return p;
    if(p->right!=NULL){
        node* q=p->right;
        for(int i=0;i>=0;i++){
        if(q->left!=NULL){
            return q->left;
        }
        else if(q->right==NULL && q->left==NULL)break;
        else{
            q=q->right;
        }
    }
    return p->right;
    }
    node* q=searchParent(p->right,root,key);
node* null=NULL;
    if(q==NULL)return q;
    else{
while(q!=NULL){
         if(q->left==p)return q;
else {p=q;q=searchParent(null,root,p->data);}}
return null;
}
    }

void print(node* root,int n){
    
    if(root!=NULL){
        node* arr[n];
        for (int i = 0; i < n; i++) {
    arr[i] = NULL;
}

        arr[0]=root;
    for(int i=0;i<n;i++){
        if(i%2==0){int j=0;
        while(arr[j]!=NULL){
            printf("%d ",arr[j]->data);
            j=j+1;
        }
        j=0;
        int k=n-1;
        while(arr[j]!=NULL){
            if(arr[j]->left!=NULL){
            arr[k]=arr[j]->left;k=k-1;}
            if(arr[j]->right!=NULL){
                arr[k]=arr[j]->right;k=k-1;
            }
arr[j]=NULL;
            j=j+1;
        }
        if(k==n-1)break;
    }
    else{
        int j=n-1;
        while(arr[j]!=NULL){
            printf("%d ",arr[j]->data);
            j=j-1;
        }
        j=n-1;
        int k=0;
        while(arr[j]!=NULL){
            if(arr[j]->left!=NULL){
                arr[k]=arr[j]->left;
                k=k+1;
            }
            if(arr[j]->right!=NULL){
                arr[k]=arr[j]->right;
                k=k+1;
            }
arr[j]=NULL;
            j=j-1;
        }
        if(k==0)break;
    }
    }
}
printf("\n");
}



int main(){

node* root=malloc(sizeof(node));
root->data=12;
insert(root,31);
insert(root,34);
insert(root,56);
insert(root,78);
insert(root,89);
insert(root,91);
insert(root,32);
insert(root,56);
insert(root,81);
insert(root,100);
insert(root,2);
insert(root,55);
insert(root,21);
insert(root,99);
insert(root,121);
insert(root,67);

int n=17;

node* d=search(root,32);
if(d!=NULL)printf("Key not found\n");
else printf("Key found\n");
d=search(root,56);
if(d!=NULL)printf("Key not found\n");
else printf("Key found\n");

int c=insert(root,32);
if(c==32)n=n+1;
print(root,n);
c=insert(root,56);
if(c==56)n=n+1;
print(root,n);
c=insert(root,21);
if(c==21)n=n+1;
print(root,n);
c=insert(root,90);
if(c==90)n=n+1;
print(root,n);

node* r=successor(root,32);
if(r==NULL)printf("successor is not there\n");
else printf("%d\n",r->data);
r=successor(root,56);
if(r==NULL)printf("successor is not there\n");
else printf("%d\n",r->data);
r=successor(root,21);
if(r==NULL)printf("successor is not there\n");
else printf("%d\n",r->data);
r=successor(root,90);
if(r==NULL)printf("successor is not there\n");
else printf("%d\n",r->data);



c=delete(root,332);
if(c==332)n=n-1;
print(root,n);
c=delete(root,51);
if(c==51)n=n-1;
print(root,n);
c=delete(root,71);
if(c==71)n=n-1;
print(root,n);
c=delete(root,67);
if(c==67)n=n-1;
print(root,n);

    scanf("%d",&n);
    int a,b=0;
    root->data=0;
root->left=NULL;
root->right=NULL;
    for(int i=0;i<n;i++){
        scanf("%d",&a);
if(i==0){root->data=a;b=b+1;continue;}
        int c=insert(root,a);
if(c==a){b=b+1;}
    }
n=b;
    print(root,n);
printf("Enter your choice:\n1 - Search for an element\n2 - Insert an element\n3 - Find the successor of an element\n4 - Delete an element\n0 - Exit\n");
scanf("%d",&a);    
while(a!=0){
        if(a==0)break;
        else if(a==1){
            scanf("%d",&b);
            node* p=search(root,b);
            if(p==NULL)printf("key not found\n");
            else printf("key %d found\n",b);
        }
        else if(a==2){
            scanf("%d",&b);
            int c=insert(root,b);
if(c==b)n=n+1;
            print(root,n);
        }
        else if(a==3){
            scanf("%d",&b);
            node*p=successor(root,b);
            if(p==NULL)printf("successor is not present for key %d\n",b);
            else printf("%d\n",p->data);
        }
        else if(a==4){
            scanf("%d",&b);
            int c=delete(root,b);
            if(c!=b){printf("Key is not present\n");}
            else {n=n-1;}
print(root,n);
        }
        else{
            printf("Invalid command\n");
        }
        printf("Enter your choice:\n1 - Search for an element\n2 - Insert an element\n3 - Find the successor of an element\n4 - Delete an element\n0 - Exit\n");
        scanf("%d",&a);
    }
free(root);
}