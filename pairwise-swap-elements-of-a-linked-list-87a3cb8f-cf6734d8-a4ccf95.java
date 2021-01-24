
import java.util.*;

class LinkedLL {

    Node head,last;

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
        Node newnnode=new Node(val);
        if(this.head==null)
        {
            this.head=newnnode;
            this.head.next=null;
            this.last=head;
        }
        else
        {
            last.next=newnnode;
            last=newnnode;
        }
    }
    void pairSwap(int size)
    {
        Node old=this.head;
        Node temp=old.next;
        while(temp!=null && old!=null)
        {
            int dVal=old.data;
            old.data=temp.data;
            temp.data=dVal;
            old=temp.next;
            if(old==null)
            break;
            temp=old.next;
        }
    }
    void display()
    {
        Node temp=this.head;
        while(temp!=null)
        {
            System.out.print(temp.data+" ");
            temp=temp.next;
        }
    }
    public static void main(String args[] ) throws Exception {
       
        Scanner sc = new Scanner(System.in);
        int size=sc.nextInt();
        LinkedLL list=new LinkedLL();
        for(int i=0;i<size;i++)
        {
            int var=sc.nextInt();
            list.insert(var);
        }
        list.pairSwap(size);
        list.display();
    }
}
