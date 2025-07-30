#include<stdio.h>
struct no_t {
    int po;
    int co;
};
struct poly{
    int n;
    struct no_t no[100];
};
struct poly read(struct poly a){
    printf("Enter size \n");
    scanf("%d",&a.n);
    printf("Enter coefficient and exponent \n");
    for(int i=0;i<a.n;i++){
        scanf("%d%d",&a.no[i].co,&a.no[i].po);
    }
    return a;
}
void disp(struct poly a){
    printf("The polynomial is \n");
    printf("%dX^%d ",a.no[0].co,a.no[0].po);
    for(int i=1;i<a.n;i++){
        printf("+ %dX^%d",a.no[i].co,a.no[i].po);   
    }
    printf("\n"); 
}
struct poly addpoly(struct poly a,struct poly b){
    int ia=0, ib=0,ic=0;
    struct poly c;
    for(;ia<a.n&&ib<b.n;){
        if(a.no[ia].po==b.no[ib].po){
            if(a.no[ia].co+b.no[ib].co!=0){
               c.no[ic].co=a.no[ia].co+b.no[ib].co;
               c.no[ic].po=a.no[ia].po;
               ic++;
            }
           ia++;
           ib++; 
        }else if(a.no[ia].po>b.no[ib].po){
            c.no[ic].co=a.no[ia].co;
            c.no[ic].po=a.no[ia].po;
            ia++;
            ic++;
        }else{
            c.no[ic].co=b.no[ib].co;
            c.no[ic].po=b.no[ib].po;
            ib++;
            ic++;
        }
    }
    for(;ia<a.n;ic++){
        c.no[ic].co=a.no[ia].co;
        c.no[ic].po=a.no[ia].po;
        ia++;
    }
    for(;ib<b.n;ic++){
        c.no[ic].co=b.no[ib].co;
        c.no[ic].po=b.no[ib].po;
        ib++;
    }
    c.n=ic;
    return c;

} 
void main(){
    struct poly a,b,c;
    a = read(a);
    b = read(b);
    disp(a);
    disp(b);
    c=addpoly( a, b);   
    printf("The Sum of ");
    disp(c);
    printf("\n");
}