// Iterative Approach

import java.util.*;
public class Assignment1Part1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);  
        System.out.println("Enter number");
        int N = sc.nextInt();
        sc.close();

        Fibonacci(N);
    }

    static void Fibonacci(int N) {
        int num1 = 0, num2 = 1;
        int counter = 0;
        while (counter < N) {
            System.out.print(num1 + " ");
            int num3 = num2 + num1;
            num1 = num2;
            num2 = num3;
            counter = counter + 1;
        }
    }
}