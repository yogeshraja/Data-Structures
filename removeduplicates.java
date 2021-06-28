import java.util.Scanner;

public class removeduplicates {

	static class node {
		char data;
		node next;

		node(char data) {
			this.data = data;
			this.next = null;
		}
	}

	static node top = null;

	static void pop() {
		top = top.next;
	}

	static void push(char a) {
		node nn = new node(a);
		if (top == null)
			top = nn;
		else {
			nn.next = top;
			top = nn;
		}
	}

	static void dup(char[] ch, int len, int i) {
		if (i == len)
			return;

		if (top.data == ch[i]) {
			while (top.data == ch[i] && i < len) {
				pop();
				push(ch[i++]);
			}
			pop();
		} else {
			push(ch[i]);
		}
		dup(ch, len, i + 1);

	}

	static void display() {
		node old = top;

		while (old != null) {
			System.out.print(old.data);
			old = old.next;
		}

	}

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		String str = "azxxxzy";
		char[] ch = str.toCharArray();
		int i = 1;
		push(ch[0]);
		dup(ch, ch.length, i);
		display();
		sc.close();
	}
}