import java.util.Scanner;
import java.util.Stack;

class MinStack {
    private Stack<Integer> stack;

    // Constructor to initialize the main stack
    public MinStack() {
        stack = new Stack<>();
    }

    // Push a value onto the stack
    public void push(int val) {
        stack.push(val);
        System.out.println(val + " pushed onto the stack.");
    }

    // Pop the top value from the stack
    public void pop() {
        if (!stack.isEmpty()) {
            System.out.println(stack.pop() + " popped from the stack.");
        } else {
            System.out.println("Stack is empty, cannot pop.");
        }
    }

    // Return the top value of the stack
    public int top() {
        if (!stack.isEmpty()) {
            return stack.peek();
        } else {
            System.out.println("Stack is empty.");
            return Integer.MIN_VALUE;
        }
    }

    // Get the minimum value from the stack
    public int getMin() {
        if (stack.isEmpty()) {
            System.out.println("Stack is empty.");
            return Integer.MIN_VALUE;
        }

        Stack<Integer> tmp = new Stack<>();
        int mini = stack.peek();

        // Find the minimum value by iterating through the stack
        while (!stack.isEmpty()) {
            mini = Math.min(mini, stack.peek());
            tmp.push(stack.pop());
        }

        // Restore the original stack by pushing values back from tmp stack
        while (!tmp.isEmpty()) {
            stack.push(tmp.pop());
        }

        return mini;
    }
}

public class MinimumStack {
    public static void main(String[] args) {
        MinStack minStack = new MinStack();
        Scanner scanner = new Scanner(System.in);
        boolean exit = false;

        System.out.println("Welcome to the MinStack program!");
        System.out.println("Commands: push <value>, pop, top, getMin, exit");

        // Loop to keep the program running until the user exits
        while (!exit) {
            System.out.print("Enter command: ");
            String command = scanner.next();

            switch (command) {
                case "push":
                    int val = scanner.nextInt();
                    minStack.push(val);
                    break;

                case "pop":
                    minStack.pop();
                    break;

                case "top":
                    int topValue = minStack.top();
                    if (topValue != Integer.MIN_VALUE) {
                        System.out.println("Top value: " + topValue);
                    }
                    break;

                case "getMin":
                    int minValue = minStack.getMin();
                    if (minValue != Integer.MIN_VALUE) {
                        System.out.println("Minimum value: " + minValue);
                    }
                    break;

                case "exit":
                    exit = true;
                    System.out.println("Exiting program.");
                    break;

                default:
                    System.out.println("Invalid command. Try again.");
                    break;
            }
        }

        scanner.close();
    }
}
