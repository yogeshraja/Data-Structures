import java.util.*;

class LinkedLL {

    Node head;

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
        if (this.head == null) {
            this.head = newnode;
        } else {
            Node last = this.head;
            while (last.next != null) {
                last = last.next;
            }
            newnode.previous = last;
            last.next = newnode;
        }
    }

    int getval(int index) {
        int i = 1;
        Node temp = this.head;
        while (temp != null) {
            if (i == index) {
                return temp.data;
            }
            i++;
            temp = temp.next;
        }
        return 0;
    }

    void setval(int index, int data) {
        int i = 1;
        Node temp = this.head;
        while (temp != null) {
            if (i == index) {
                temp.data = data;
            }
            i++;
            temp = temp.next;
        }
    }

    void merge(int low, int high) {
        for (int i = low; i <= high; i++) {
            int min = this.getval(i);
            int sub = i;
            for (int j = i + 1; j <= high; j++) {
                if (min > this.getval(j)) {
                    min = this.getval(j);
                    sub = j;
                }
            }
            int dTemp = this.getval(i);
            this.setval(i, this.getval(sub));
            this.setval(sub, dTemp);
        }
    }

    void mergeSort(int low, int high) {
        if (low < high) {
            int mid = (low + high) / 2;
            this.mergeSort(low, mid);    //left recursion
            this.mergeSort(mid + 1, high); //right recursion
            this.merge(low, high);
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
        int size = sc.nextInt();
        for (int i = 0; i < size; i++) {
            int var = sc.nextInt();
            inputList.insert(var);
        }
        inputList.mergeSort(0, size);
        inputList.display();
        sc.close();

    }
}
