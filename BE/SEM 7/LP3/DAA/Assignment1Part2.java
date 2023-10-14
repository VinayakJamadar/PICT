// Recursive Approach

import java.util.*;
public class Assignment1Part2 {
    static int fib(int n)
    {
        // Base Case
        if (n <= 1)
            return n;
        // Recursive call
        return fib(n - 1)+ fib(n - 2);
    }
    // Driver Code
    public static void
    main(String args[])
    {
        Scanner sc = new Scanner(System.in);  
        System.out.println("Enter number");
        int  N = sc.nextInt();
        sc.close();
        // Print the first N numbers
        for (int i = 0; i < N; i++) {
            System.out.print(fib(i) + " ");
        }
    }
}
