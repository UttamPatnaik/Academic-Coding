import java.util.*;

public class AdditiveCipher {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a string: ");
        String s = sc.nextLine();

        System.out.println("Enter a number between 1 and 25");
        int n = sc.nextInt();

        while (n < 1 || n > 25) {
            System.out.println("Enter a number between 1 and 25");
            n = sc.nextInt();
        }

        System.out.println("Enter 1 for Encryption or 2 for Decryption");
        int choice = sc.nextInt();

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);

            if (choice == 1) {
                if (ch >= 'A' && ch <= 'Z') {
                    ch = (char)(ch + n);
                    if (ch > 'Z') {
                        ch = (char)(ch - 26);
                    }
                } else if (ch >= 'a' && ch <= 'z') {
                    ch = (char)(ch + n);
                    if (ch > 'z') {
                        ch = (char)(ch - 26);
                    }
                }
            }

            if (choice == 2) {
                if (ch >= 'A' && ch <= 'Z') {
                    ch = (char)(ch - n);
                    if (ch < 'A') {
                        ch = (char)(ch + 26);
                    }
                } else if (ch >= 'a' && ch <= 'z') {
                    ch = (char)(ch - n);
                    if (ch < 'a') {
                        ch = (char)(ch + 26);
                    }
                }
            }

            System.out.print(ch);
        }
    }
}
