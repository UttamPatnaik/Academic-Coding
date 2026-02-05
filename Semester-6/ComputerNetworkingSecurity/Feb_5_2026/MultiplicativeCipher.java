import java.util.*;

public class MultiplicativeCipher {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a string:");
        String s = sc.nextLine();

        System.out.println("Enter a key (coprime with 26):");
        int key = sc.nextInt();

        while (gcd(key, 26) != 1) {
            System.out.println("Invalid key. Enter a key coprime with 26:");
            key = sc.nextInt();
        }

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);

            if (ch >= 'A' && ch <= 'Z') {
                int x = ch - 'A';
                int enc = (x * key) % 26;
                ch = (char) (enc + 'A');
            } 
            else if (ch >= 'a' && ch <= 'z') {
                int x = ch - 'a';
                int enc = (x * key) % 26;
                ch = (char) (enc + 'a');
            }

            System.out.print(ch);
        }
    }
    static int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
}
