// Java program to find GCD of two numbers
public class GFG {
     
    // Function to return gcd of a and b
    static int gcd(int a, int b)
    {
        int result = Math.min(a, b); // Find Minimum of a nd b
        while (result > 0) {
            if (a % result == 0 && b % result == 0) {
                break;
            }
            result--;
        }
        return result; // return gcd of a nd b
    }
     
    // Driver program to test above function
    public static void main (String[] args)
    {
        int a = 98, b = 56;
        System.out.print("GCD of " + a + " and " + b + " is " + gcd(a, b));
    }
}
