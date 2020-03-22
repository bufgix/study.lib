public class Odev2 {
    public static void main(String[] args) {
        int x = 10, y = 20;

        x ^= y;
        y ^= x;
        x ^= y;

        System.out.println(String.format("x: %d y: %d", x, y));
    }
}