import java.util.Scanner;

public class Odev3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Yıl > ");
        int year = sc.nextInt();
        sc.close();

        switch (year % 4) {
        case 0:
            System.out.println("29 Çeker");
            break;
        case 1:
        case 2:
        case 3:
        case 4:
            if (year % 100 == 0 && year % 400 == 0) {
                System.out.println("29 çeker");
            } else {
                System.out.println("28 Çeker");
            }
        }
    }
}