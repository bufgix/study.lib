import java.util.Scanner;

public class Odev1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Sayi > ");
        int number = scanner.nextInt();

        while (true) {
            System.out.print("Tahmin -> ");
            int guess = scanner.nextInt();
            if (guess > number) {
                System.out.println("Düşür");
            } else if (guess < number) {
                System.out.println("Yükselt");
            } else {
                System.out.println("Buldun (Sanki bilmiyormuş gibi)");
                break;
            }
        }
        scanner.close();
    }
}