
import java.util.*;

class LinkedLL {

    Node head, last;

    class Node {

        char data;
        Node previous, next;

        Node(char d) {
            data = d;
            previous = next = null;
        }
    }

    void insert(char data) {
        Node newnode = new Node(data);
        if (this.head == null) {
            this.head = newnode;
            this.last = this.head;
        } else {
            newnode.previous = this.last;
            this.last.next = newnode;
            this.last = newnode;
        }
    }

    void rotateList(int count) {
        while (count-- > 0) {
            Node temp = this.head;
            this.head = this.head.next;
            this.last.next = temp;
            temp.previous = this.last;
            temp.next = null;
            this.last = temp;
        }
    }

    void display() {
        Node temp = this.head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
    }

    public static void main(String args[]) throws Exception {
        Scanner sc = new Scanner(System.in);
        LinkedLL inputList = new LinkedLL();
        String inpString = sc.nextLine();
        for (int i = 0; i < inpString.length(); i++) {
            if (inpString.charAt(i) != ' ') {
                inputList.insert(inpString.charAt(i));
            }
        }
        int rotateCount = sc.nextInt();
        inputList.rotateList(rotateCount);
        inputList.display();
        sc.close();
    }
}
