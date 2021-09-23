
import java.util.*;

class CircularLL {
    Node last;
    class Node{
        int data;
        Node next;

        Node(int d)
        {
            data=d;
            next=null;
        }
    }
    void insert(int val)
    {
        Node newnnode=new Node(val);
        if(this.last==null)
        {
            this.last=newnnode;
            this.last.next=this.last;
        }
        else
        {
            newnnode.next=this.last.next;
            this.last.next=newnnode;
            this.last=newnnode;
        }
    }
    void circle(int m,int n)
    {
        Node temp=this.last;
        while(n!=1)
        {
            for(int i=1;i<m;i++)
            {
                temp=temp.next;
            }
            temp.next=temp.next.next;
            n--;
        }
        System.out.print(temp.data);
    }
    void display()
    {
        Node temp=this.last.next;
        do
        {
            System.out.print(temp.data+" ");
            temp=temp.next;
        }while(temp!=this.last);
        System.out.print(this.last.data);
    }
    public static void main(String args[] ) throws Exception {
        Scanner sc=new Scanner(System.in);
        CircularLL list=new CircularLL();
        int n=sc.nextInt(),m=sc.nextInt();
        for(int i=1;i<=n;i++)
        {
            list.insert(i);
        }
        list.circle(m,n);
    }
}
