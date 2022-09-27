#include <stdio.h>
#include <math.h>

int main(void) {
int p, q, e, m, d, r1, r2, r, n, Qn;
int a[100];

  printf("\nEnter the first prime number (p): ");
  scanf("%d",&p);
    
  printf("Enter the second prime number (q): ");
  scanf("%d",&q);
    
  printf("Enter the value of e: ");
  scanf("%d",&e);

  printf("Enter the Value of M: ");
  scanf("%d",&m);

  printf("\nUsing RSA Algorithm...");
  
  n=p*q;
  printf("\n\nn => p*q \nn => %d*%d \nn => %d",p,q,n);
    
  Qn=(p-1)*(q-1);
  printf("\n\nQ(n) => (p-1)*(q-1) \nQ(n) => (%d-1)*(%d-1) \nQ(n) => %d",p,q,Qn);
  
int i=0;
r1=Qn;
r2=e;
while(r2!=0){ 
  a[i++]=r1/r2; 
  r=r1%r2; 
  r1=r2; 
  r2=r; 
}

int j = i;
int t1=0; 
int t2=1;
int t;
if(r1==1){
  for(i=0;i<=j;i++){ 
    t = t1-(t2*a[i]); 
    t1=t2; 
    t2=t; 
}
}
  
printf("\n\nFinal value of t1 => %d  and  t2 => %d",t2,t1);

d=t2%Qn;
printf("\n\nValue of d => %dmod%d \n\t\t d => %d",t2,t1,d);

int C;
C = (int)pow(m, e)%n;
printf("\n\nValue of C => %d^%dmod%d \n\t\t C => %d",m,e,n,C);

int M;
M = (int)pow(C, d)%n;
printf("\n\nValue of M => %d^%dmod%d \n\t\t M => %d",C,d,n,M);
  return 0;
}
