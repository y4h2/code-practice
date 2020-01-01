import java.util.*;
import java.io.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;



class Solution{
    public static void main(String []argh)
    {
        Scanner sc = new Scanner(System.in);
        BigInteger longlim_min = BigInteger.valueOf(-9223372036854775808L);
        BigInteger longlim_max = BigInteger.valueOf(9223372036854775807L);
        
        int t=sc.nextInt();

        for(int i=0;i<t;i++)
        {
            BigInteger N = sc.nextBigInteger();
            if (N.compareTo(longlim_min) < 0 || N.compareTo(longlim_max) > 0) {
                System.out.print(N + " can't be fitted anywhere.\n");
            } else {
                System.out.print(N + " can be fitted in:\n");
                long longN = N.longValue();
                if (longN >= 0 && longN <= 1)
                    System.out.print("* boolean\n");
                if (longN >= -Math.pow(2,7) && longN <= Math.pow(2,7) - 1)
                    System.out.print("* byte\n");
                if (longN >= -Math.pow(2,15) && longN <= Math.pow(2,15) - 1)
                    System.out.print("* short\n");
                if (longN >= -Math.pow(2,31) && longN <= Math.pow(2,31) - 1)
                    System.out.print("* int\n");
                if (longN >= -Math.pow(2,63) && longN <= Math.pow(2,63) - 1)
                    System.out.print("* long\n");
            }
        }
    }
}
