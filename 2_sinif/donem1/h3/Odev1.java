import java.util.Random;
import java.util.Scanner;

public class Odev1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random rand = new Random();

        System.out.print("Aralık seçin Orn: 3-19  -> ");
        String rawData = scanner.nextLine().replace(" ", "");
        int start = Integer.parseInt(rawData.split("-")[0]);
        int end = Integer.parseInt(rawData.split("-")[1]);

        int number = rand.ints(start, end).findFirst().getAsInt();

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