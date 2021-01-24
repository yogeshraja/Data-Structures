
import java.util.*;

class LinkedLL {

    Node head, last;

    class Node {

        int data;
        Node previous, next;

        Node(int d) {
            data = d;
            previous = next = null;
        }
    }

    void insert(int data) {
        Node newnode = new Node(data);
        if (this.head != null) {
            this.head = newnode;
            this.last = head;
        } else {
            last.next = newnode;
            newnode.previous = last;
            last = newnode;
        }
    }

    void display() {
        Node temp = this.head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
    }

    int countTriplets(int sumVal) {
        int count = 0;
        Node temp = this.head;
        HashMap<Integer, Node> mapper = new HashMap<>();
        while (temp != null) {
            mapper.put(temp.data, temp);
            temp = temp.next;
        }
        for (temp = this.head; temp != null; temp = temp.next) {
            for (Node temp1 = temp.next; temp1 != null; temp1 = temp1.next) {
                if (temp == temp1) {
                    continue;
                }
                int val = sumVal - (temp.data + temp1.data);
                if (mapper.containsKey(val) && mapper.get(val) != temp && mapper.get(val) != temp1) {
                    count++;
                }
            }
        }
        return count/3;
    }

    public static void main(String args[]) throws Exception {

        Scanner sc = new Scanner(System.in);
        LinkedLL inputList = new LinkedLL();
        int size = sc.nextInt();
        for (int i = 0; i < size; i++) {
            int var = sc.nextInt();
            inputList.insert(var);
        }
        int sumVal = sc.nextInt();
        //inputList.display();
        System.out.print(inputList.countTriplets(sumVal));
        sc.close();
    }
}
