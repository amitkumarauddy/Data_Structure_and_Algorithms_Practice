class MinStack {
    private Node head;

    private class Node {
        int value;
        int min;
        Node next;

        Node(int value, int min, Node next) {
            this.value = value;
            this.min = min;
            this.next = next;
        }
    }

    public MinStack() {
        // Initialize the stack
        head = null;
    }

    public void push(int val) {
        if (head == null) {
            head = new Node(val, val, null);
        } else {
            head = new Node(val, Math.min(val, head.min), head);
        }
    }

    public void pop() {
        if (head != null) {
            head = head.next;
        }
    }

    public int top() {
        if (head != null) {
            return head.value;
        }
        throw new IllegalStateException("Stack is empty");
    }

    public int getMin() {
        if (head != null) {
            return head.min;
        }
        throw new IllegalStateException("Stack is empty");
    }
}

public class MinimumStack {
    public static void main(String[] args) {
        MinStack minStack = new MinStack();
        
        minStack.push(1);
        minStack.push(2);
        minStack.push(0);
        System.out.println("getMin: " + minStack.getMin()); // Output: 0
        minStack.pop();
        System.out.println("top: " + minStack.top()); // Output: 2
        System.out.println("getMin: " + minStack.getMin()); // Output: 1
    }
}
