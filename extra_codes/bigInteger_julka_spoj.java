import java.util.*;
import java.math.*;

class bigInteger_julka_spoj {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int start = 1;
    while (start <= 10) {
      BigInteger t = sc.nextBigInteger();
      BigInteger d = sc.nextBigInteger();
      BigInteger n = new BigInteger("0");
      BigInteger k = new BigInteger("0");
      n = (t.subtract(d)).divide(BigInteger.valueOf(2));
      k = n.add(d);
      System.out.println(k);
      System.out.println(n);
      start++;
    }
    sc.close();
  }
}