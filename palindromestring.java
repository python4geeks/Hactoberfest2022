import java.util.*;
public class palindromestring {
    public static void palindrome(String s){
        String rev="";
        for(int i=s.length()-1;i>=0;i--){
            rev=rev+s.charAt(i);

        }
        if(s.equals(rev)){
            System.out.println("palindrome string");
        }
        else{
            System.out.println("not a palindrome string");
        }
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("enter the string");
        String s=sc.next();
        palindrome(s);

    }
}
