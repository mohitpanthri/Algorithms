import java.util.*;
class Main{
    
    static String toCipher(String plain,String key){
        plain=plain.toLowerCase();
        key=key.toLowerCase();
        String newKey="";
        for(int i=0;i<plain.length();i++)
            newKey=newKey+key.charAt(i%key.length());
        System.out.println("Updated key: "+newKey);
        String cipher="";
        for(int i=0;i<plain.length();i++)
            cipher=cipher+(char)((plain.charAt(i)+newKey.charAt(i)-2*97)%26+97);
        return cipher;
    }
    
    static String toPlain(String cipher,String key){
        cipher=cipher.toLowerCase();
        key=key.toLowerCase();
        String newKey="";
        for(int i=0;i<cipher.length();i++)
            newKey=newKey+key.charAt(i%key.length());
        String plain="";
        for(int i=0;i<cipher.length();i++)
         plain=plain+(char)((cipher.charAt(i)-97+26-(newKey.charAt(i)-97))%26+97);
        return plain;
    }
    
	public static void main(String[] args) {
		Scanner in =new Scanner(System.in);
		System.out.print("Enter plain text: ");
		String plainText=in.next();
		System.out.print("Enter key text: ");
		String key=in.next();
		String cipher=toCipher(plainText,key);
		System.out.println("Encrypted text: "+cipher);
		System.out.println("Decrypted text: "+toPlain(cipher,key));
	}
}
