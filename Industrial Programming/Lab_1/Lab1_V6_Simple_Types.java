import java.util.Scanner;


public class Main {

    public static void main(String[] args) {

        try (Scanner in = new Scanner(System.in)) {

            System.out.println("Enter k & x:");

            int k = in.nextInt();

            if (k < 0)
                throw new IllegalArgumentException("Error: k-value should be not negative");

            double x = in.nextDouble();

            double eps = 1;
            for (int i = 0; i < k; ++i) {
                eps /= 10;
            }

            double result = TS_sin(x, eps);
            double expected = Math.sin(x);

            System.out.println("Our result: " + format_value(result, k));
            System.out.println("Result using sin function: " + format_value(expected, k));



        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }

    public static double TS_sin(double x, double eps) {

        double sum = x;
        double nt = x;
        double i = 1;

        while (Math.abs(nt) >= eps) {

            i += 2;
            nt *= -x*x/(i-1)/i;
            sum += nt;
        }
        return sum;
    }

    private static String format_value(double value, int k) {
        return String.format("%." + Integer.toString(k+1) + "f\n", value);
    }

}