
import java.util.*;

class CircularLL {
    Node last,first;

    class Node
    {
        int data;
        Node next;

        Node(int d)
        {
            data =d;
            next=null;
        }
    }
    void insert(int val)
    {
        Node newnnode=new Node(val);
        if(this.last==null)
        {
            this.last=newnnode;
            this.last.next=last;
        }
        else
        {
            newnnode.next=this.last.next;
            this.last.next=newnnode;
        }
    }
    void display()
    {
        Node temp=this.first;
        if(temp==null)
            return;
        do
        {
            System.out.print(temp.data+" ");
            temp=temp.next;
        }while(temp!=first);
    }

    boolean isPrime(int n)
    {
        if(n<=1)
            return false;
        if(n<=3)
            return true;
        if(n%2==0 || n%3==0)
            return false;
        for(int i=5;i*i<=n;i+=6)
        {
            if(n%i==0 || n%(i+2)==0)
                return false;
        }
        return true;
    }
    void deletePrimes(int n)
    {
        int i=1;
        Node temp=this.last.next;
        Node old=this.last;
        while(n-->0)
        {
            if(isPrime(temp.data))
            {
                if(temp==this.first)
                {
                    this.first=this.first.next;
                    if(this.first.next==this.first)
                    {
                        first=null;
                    }
                }
                old.next=temp.next;
                temp=temp.next;
                continue;
            }
            old=temp;
            temp=temp.next;
        }
    }
    public static void main(String args[] ) throws Exception {
       
        Scanner sc = new Scanner(System.in);
        CircularLL list=new CircularLL();
        int x,n=sc.nextInt();
        for(int i=0;i<n;i++)
        {
            x=sc.nextInt();
            list.insert(x);
        }
        list.first=list.last.next;
        list.deletePrimes(n);
        list.display();
    }
}
