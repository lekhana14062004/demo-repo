#include<stdio.h>
typedef struct polynomial
{
    int cf;
    int px;
}
P;
void accept(P p1[10],int n)
{
    printf("enter the coefficiet and exponent");
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&p1[i].cf,&p1[i].px);
    }
}
void display(P p1[20],int n)
{
    for(int i=0;i<n;i++)
    {
        if(p1[i].cf>0)
        {
            printf("+%dx^%d",p1[i].cf,p1[i].px);
        }
        else
        {
            printf("%dx^%d",p1[i].cf,p1[i].px);
        }
    }
    printf("\n");
}
int multiply(P p1[20],int n1,P p2[20],int n2,P res[20])
{
    int k=0;
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            res[k].cf=p1[i].cf*p2[j].cf;
            res[k].px=p1[i].px+p2[j].px;
            k++;
        }
    }
    return k;
}
int addpoly(P res[20],int k,P res2[20])
{
    int index=0;
    for(int i=0;i<k;i++)
    {
    
        res2[index].cf=0;
        if(res[i].cf!=-999)
        {
            for(int j=0;j<k;j++)
            {
                if(res[i].px==res[j].px)
                {
                    res2[index].cf=res2[index].cf+res[j].cf;
                    res2[index].px=res[i].px;
                    res[j].cf=-999;
                }
            }
            index++;
        }
    }
    return index;
}
int main()
{
    int n1=3,n2=3;
    int k,index;
    P p1[20],p2[20],res[20],res2[20];
    accept(p1,n1);
    accept(p2,n2);
    k=multiply(p1,n1,p2,n2,res);
    index=addpoly(res,k,res2);
    display(res2,index);
    return 0;
}

