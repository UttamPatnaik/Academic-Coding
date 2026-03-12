import java.util.*;
public class Vigenere_Cipher
{
    public static String preparePlaintext(String text)
    {
        return text.toUpperCase().replace(" ","");
    }
    public static String charAdd(int ok, String ke)
    {
        String m="";
        for(int i=0;i<ok;i++)
        {
            m=m+ke.charAt(i);
        }
        return m;
    }
    public static String generate_Key(String t, String k)
    {
        String p=preparePlaintext(t);
        String nk=preparePlaintext(k);
        int lp=p.length();
        int lk=nk.length();
        if(lk!=lp)
        {
            int x=lp%lk;
            int y=lp/lk;
            if(x<=0)
            {
                nk=nk.repeat(y);
            }
            else
            {
                nk=nk.repeat(y)+charAdd(x,nk);
            }
        }
        return nk;
    }
    public static String Encrypt(String p, String k)
    {
        String ET="";
        for(int i=0;i<p.length();i++)
        {
            ET = ET + (char)((((int)p.charAt(i) - 65) + ((int)k.charAt(i) - 65)) % 26 + 65);
        }
        return ET;
    }
    public static String Decrypt(String p, String k)
    {
        String ET="";
        for(int i=0;i<p.length();i++)
        {
            ET = ET + (char)((((p.charAt(i) - 65) - (k.charAt(i) - 65) + 26) % 26) + 65);
        }
        return ET;
    }
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter a text: ");
        String s=sc.nextLine();
        System.out.println("Enter a keyword: ");
        String k=sc.next();
        String kj=generate_Key(s,k);
        String ETA=Encrypt(preparePlaintext(s),kj);
        String DTA=Decrypt(preparePlaintext(ETA),kj);
        System.out.println("Encrypted Text: "+ETA);
        System.out.println("Decrypted Text: "+DTA);
    }
}
//Sample Input and Output
/*
Enter a text: 
hello world
Enter a keyword: 
key
Encrypted Text: RIJVSUYVJN
Decrypted Text: HELLOWORLD
*/
