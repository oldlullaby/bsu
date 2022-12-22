import java.util.Scanner;
import java.util.Formatter;

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
            format_value_1(result);
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

    private static void format_value_1(double value) {
        Formatter fmt = new Formatter();
        System.out.println(fmt.format("8 bit && 16 bit: %o and %x", (int)value, (int)value));

        System.out.println();
        fmt = new Formatter();

        System.out.println(fmt.format("2) : %s", value));

        System.out.println();
        fmt = new Formatter();
        System.out.println(fmt.format("3) : %f", value));

        System.out.println();
        fmt = new Formatter();
        System.out.println(fmt.format("4) : %8.2e", value));

        System.out.println();
        fmt = new Formatter();
        System.out.println(fmt.format("5) : |%-10.2f|", value));
        fmt = new Formatter();
        System.out.println(fmt.format("5) : |%10.2f|", value));

        System.out.println();
        fmt = new Formatter();
        System.out.println(fmt.format("%(f", value));

        if (value > 0) {

            System.out.println();
            fmt = new Formatter();
            System.out.println(fmt.format("%+f", value));

        }

        System.out.println();
        fmt = new Formatter();
        double value_ = 1000000 * value;
        System.out.println(fmt.format("%,f", value_));

        System.out.println();
        fmt = new Formatter();
        System.out.println(fmt.format("%#f", 1.0));

        System.out.println();
        fmt = new Formatter();
        System.out.println(fmt.format("%09f", value));

        System.out.println();
        fmt = new Formatter();
        System.out.println(fmt.format("%3$d %1$d %2$d", 10, 20, 30));
    }

}
