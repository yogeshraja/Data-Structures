import java.util.*;

public class treefrominorderandpost {

	static node root;
	static int n;
	static int index;

	static class node {
		char data;
		node left, right;

		node(char data) {
			this.data = data;
			this.left = null;
			this.right = null;
		}
	}


	static node construct(char[] in, char[] post, int start, int end) {

		if (start > end)
			return null;

		node temp = new node(post[index--]);

		if (start == end)
			return temp;
		else {
			int ind = 0;
			for (int j = start; j <= end; j++) {
				if (in[j] == temp.data) {
					ind = j;
					break;
				}
			}

			temp.right = construct(in, post, ind + 1, end);
			temp.left = construct(in, post, start, ind - 1);

			return temp;
		}
	}

	static void levelorder(node root) {
		if (root == null)
			return;
		Queue<node> q1 = new LinkedList<>();
		q1.add(root);
		q1.add(null);
		while (!q1.isEmpty()) {
			node current = q1.peek();
			q1.remove();
			if (current == null) {
				if (!q1.isEmpty()) {
					q1.add(null);
					System.out.println();
				}
			} else {
				System.out.print(current.data + " ");
				if (current.left != null)
					q1.add(current.left);
				if (current.right != null)
					q1.add(current.right);
			}
		}
	}

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		index=n-1;
		char[] in = new char[n];
		char[] post = new char[n];
		for (int i = 0; i < n; i++)
			in[i] = sc.next().charAt(0);
		for (int i = 0; i < n; i++)
			post[i] = sc.next().charAt(0);
		root = construct(in, post, 0, in.length - 1);
		levelorder(root);
		sc.close();
	}
}