import java.util.ArrayList;
import java.util.List;
import java.util.Random;

enum PhoneType {
    ANDROID, IPHONE
}

enum ResponseType {
    SUCCESS, BUSY, NOT_FOUND;

}

class Person {
    String name;
    String number;
    boolean isReachable;

    public Person(String name, String number) {
        this.name = name;
        this.number = number;
        this.isReachable = Math.random() < 0.5;
    }

    @Override
    public String toString() {
        return name;
    }
}

class Phone {
    PhoneType type;
    int battery = 100;
    boolean mobileData = false;
    List<Person> contacts = new ArrayList<Person>();

    public Phone(PhoneType type) {
        this.type = type;
    }

    void addContact(Person p) {
        contacts.add(p);
    }

    ResponseType callPerson(String name) throws InterruptedException {
        for (Person person : contacts) {
            if (person.name.equals(name)) {
                System.out.println(name + " araniyor..." + person.number);
                Thread.sleep(2000);
                battery -= 1;
                if (person.isReachable)
                    return ResponseType.SUCCESS;
                else
                    return ResponseType.BUSY;
            }
        }
        return ResponseType.NOT_FOUND;
    }
}

public class Odev1 {
    public static void main(String[] args) throws InterruptedException {
        Phone telefon = new Phone(PhoneType.IPHONE);
        telefon.addContact(new Person("Mertcan", "0553-431-123"));
        telefon.addContact(new Person("Gungor", "0553-324-12-43"));
        System.out.println(telefon.contacts);
        ResponseType response = telefon.callPerson("Mertcan");
        switch (response) {
        case SUCCESS:
            System.out.println("arandi");
            break;
        case NOT_FOUND:
            System.out.println("rehberde yok");
            break;
        case BUSY:
            System.out.println("suan mesgul");
        }
    }
}