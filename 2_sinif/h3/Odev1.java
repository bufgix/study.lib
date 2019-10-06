import java.util.Random;
import java.util.Scanner;

public class Odev1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random rand = new Random();
        
        int number = rand.nextInt(1000);


        while (true) {
            System.out.print("Tahmin -> ");
            int guess = scanner.nextInt();
            if (guess > number) {
                System.out.println("Düşür");
            } else if (guess < number) {
                System.out.println("Yükselt");
            } else {
                System.out.println("Buldun");
                break;
            }
        }
        scanner.close();
    }
}