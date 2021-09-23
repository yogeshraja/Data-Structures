import java.util.*;

class LinkedLL {
    Node head;

    class Node{
        int data;
        Node next,previous;

        Node(int d)
        {
            data=d;
            next=previous=null;
        }
    }
    void insert(int val)
    {
        Node newnode=new Node(val);
        if(this.head==null)
        {
            this.head=newnode;
        }
        else
        {
            Node temp=this.head;
            while(temp.next!=null)
            {
                temp=temp.next;
            }
            temp.next=newnode;
            newnode.previous=temp;
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

    int countTriplets(int sumVal)
    {
        int count=0;
        HashMap <Integer,Node> mapper=new HashMap<>();
        for(Node temp=this.head;temp!=null;temp=temp.next)
        {
            mapper.put(temp.data,temp);
        }
        for(Node temp=this.head;temp!=null;temp=temp.next)
        {
            for(Node temp1=temp.next;temp1!=null;temp1=temp1.next)
            {
                for(Node temp2=temp1.next;temp2!=null;temp2=temp2.next)
                {
                    int val=temp2.data+temp.data+temp1.data;
                    if(val==sumVal)
                    count++;
                }
                // int val=sumVal-(temp.data+temp1.data);
                // if(mapper.containsKey(val) && mapper.get(val)!=temp && mapper.get(val)!=temp1)
                // {
                //     count++;
                // }
            }
        }
        return count;
    }
    public static void main(String args[] ) throws Exception 
    {
        
        Scanner sc = new Scanner(System.in);
        LinkedLL list=new LinkedLL();
        int size=sc.nextInt(); 
        for(int i=0;i<size;i++)
        {
            int var=sc.nextInt();
            list.insert(var);
        }
        int sumVal=sc.nextInt();
        //list.display();
        System.out.print(list.countTriplets(sumVal));
    }
}
