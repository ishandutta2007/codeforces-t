import java.util.Scanner;

public class AlexAndARhombus {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        System.out.println((2 * n * (n - 1)) + 1);
    }
}