package odevh2;

import java.util.Arrays;
import java.util.List;

/**
 *
 * @author bufgix
 */
public class Odevh2 {

    /**
     * @param args komut satırı argumanları
     */
    public static void main(String[] args) {
        /*
        args bir Array. Bunun bir List'e dönüşmesi gerek.
        altaki kod Array'i List'e dönüştürür.

        .contains() ve .containsAll() methodları hakkında
        kaynaklar: 
            http://tutorials.jenkov.com/java-collections/list.html
            https://www.mkyong.com/java/java-check-if-array-contains-a-certain-value/
        */
        List<String> argsList = Arrays.asList(args);

        if (argsList.containsAll(Arrays.asList("a", "d"))) {
            for (int i = 1; i < 11; i++) {
                System.out.print(i + " ");
            }
            System.out.println("");
            for (int i = 10; i > 1; i--) {
                System.out.print(i + " ");
            }
        } else if (argsList.contains("a")) {
            for (int i = 1; i < 11; i++) {
                System.out.print(i + " ");

            }
        } else if (argsList.contains("d")) {
            for (int i = 10; i > 0; i--) {
                System.out.print(i + " ");
            }
        }
        else {
            System.err.println("Args yok");
        }

    }

}
