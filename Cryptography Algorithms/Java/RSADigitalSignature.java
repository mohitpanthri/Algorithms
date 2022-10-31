import java.util.*;

public class RSA{

static LinkedList<Integer> Q=new LinkedList();

static int gcd(int a,int b){

if(a==0)return b;

Q.add(b/a);

return gcd(b%a,a);

}

static int inverse(int t1,int t2){

if(Q.isEmpty())return t1;

return inverse(t2,t1-t2*Q.removeFirst());

}

public static void main(String [] args){

Scanner in = new Scanner(System.in);

System.out.print("Enter two prime numbers: ");

int p=in.nextInt();int q=in.nextInt();

int n=p*q;System.out.println("Value of n = "+n);

int phi_n=(p-1)*(q-1);

System.out.print("Enter value of e: ");

int e = in.nextInt();

while(gcd(e,phi_n)!=1){

Q.clear();

System.out.print("gcd!=1 Enter value of e again: ");

e=in.nextInt();

}

int d= inverse(0,1);

while(d<0)d+=n;

d=d%phi_n;

System.out.println("Value of d = "+d);

System.out.print("Enter value of m: ");

int m= in.nextInt();

int sign = (int)Math.pow(m,d)%n;

System.out.println("Signature value = "+sign);

int m1= (int)Math.pow(sign,e)%n;

System.out.println("Value of m1 = "+m1);

if(m==m1)System.out.print("m==m1 message accepted");

}

}
