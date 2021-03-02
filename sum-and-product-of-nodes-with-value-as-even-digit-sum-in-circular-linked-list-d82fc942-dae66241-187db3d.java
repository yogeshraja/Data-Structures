import java.util.*;

class CircularLL {
    Node last;
    class Node
    {
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
        Node newnode=new Node(val);
        if(this.last==null)
        {
            this.last=newnode;
            this.last.next=this.last;
        }
        else
        {
            newnode.next=this.last.next;
            this.last.next=newnode;
            this.last=newnode;
        }
    }
    void sumProduct()
    {
        Node temp=last;
        int sum=0,product=1;
        do
        {
            sum+=temp.data;
            product*=temp.data;
            temp=temp.next;
        }while(temp!=last);
        System.out.println(sum);
        System.out.print(product);
    }
    boolean checkEven(int val)
    {
        int sum=0;
        while(val>0)
        {
            sum+=val%10;
            val/=10;
        }
        if(sum%2==0)
        {
            return true;
        }
        return false;
    }
    public static void main(String args[] ) throws Exception {
       Scanner sc=new Scanner(System.in);
       CircularLL list=new CircularLL();
       int size=sc.nextInt();
       for(int i=0;i<size;i++)
       {
           int var=sc.nextInt();
           if(list.checkEven(var))
            list.insert(var);
       }
       list.sumProduct();
       sc.close();
    }
}
