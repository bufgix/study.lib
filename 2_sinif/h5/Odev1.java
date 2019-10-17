import java.util.ArrayList;;

class Cipher {
    private String cipherText;
    private String plainText;
    int key;
    ArrayList<Character> alphabet = new ArrayList<Character>();

    Cipher(int key) {
        this.key = key;
        for (int i = 0; i < 26; i++) {
            alphabet.add((char) (97 + i));
        }
        alphabet.add(' ');
    }

    public String getPlainText() {
        return plainText;
    }

    public String getCipherText() {
        return cipherText;
    }

    String encipher(String plain) {
        plain = plain.toLowerCase();
        plainText = plain;
        StringBuilder ciperTextBuild = new StringBuilder();
        for (int i = 0; i < plain.length(); i++) {
            ciperTextBuild.append((char) (plain.codePointAt(i) + key));
        }
        cipherText = ciperTextBuild.toString();
        return cipherText;
    }

}

class DeCipher {
    private String plainText;
    private String cipherText;
    private int key;
    ArrayList<Character> alphabet = new ArrayList<Character>();

    DeCipher(int key) {
        this.key = key;
        for (int i = 0; i < 26; i++) {
            alphabet.add((char) (97 + i));
        }
        alphabet.add(' ');
    }

    public String getPlainText() {
        return plainText;
    }

    public String getCipherText() {
        return cipherText;
    }

    public int getKey() {
        return key;
    }

    String decipher(String cipher) {
        cipherText = cipher;
        StringBuilder plainTextBuild = new StringBuilder();
        for (int i = 0; i < cipher.length(); i++) {

            plainTextBuild.append((char) (cipher.codePointAt(i) - key));
        }
        plainText = plainTextBuild.toString();
        return plainText;
    }

}

public class Odev1 {
    public static void main(String[] args) {
        Cipher cp = new Cipher(6);
        DeCipher dp = new DeCipher(6);
        String cipherText = cp.encipher("hello world");
        System.err.println("Sifreli: " + cipherText);
        System.out.println("Cozulmus: " + dp.decipher(cipherText));
    }
}