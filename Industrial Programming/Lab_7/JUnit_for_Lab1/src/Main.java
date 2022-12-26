package org.example;

import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        try (Scanner in = new Scanner(System.in)) {

            System.out.println("Enter k & x:");

            BigInteger k = in.nextBigInteger();

            if (k.compareTo(BigInteger.valueOf(0)) < 0)
                throw new IllegalArgumentException("Error: k-value should be not negative");

            BigDecimal x = in.nextBigDecimal();

            BigDecimal eps = BigDecimal.valueOf(1);
            for (int i = 0; i < k.intValue(); ++i) {
                eps = eps.divide(BigDecimal.valueOf(10));
            }

            BigDecimal result = TS_sin(x, eps, k.intValue());
            BigDecimal expected = BigDecimal.valueOf(Math.sin(x.doubleValue()));

            System.out.println("Our result: " + format_value(result, k.intValue()));
            System.out.println("Result using sin function: " + format_value(expected, k.intValue()));



        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }

    public static BigDecimal TS_sin(BigDecimal x, BigDecimal eps, int k) {

        BigDecimal sum = x;
        BigDecimal nt = x;
        BigDecimal i = new BigDecimal("1");

        while (nt.abs().compareTo(eps) == 0 | nt.abs().compareTo(eps) > 0) {

            i = i.add(BigDecimal.valueOf(2));

            nt = nt.multiply(x);
            nt = nt.multiply(x);
            nt = nt.multiply(BigDecimal.valueOf(-1));

            nt = nt.divide(i, k+1, RoundingMode.HALF_DOWN);
            nt = nt.divide(i.subtract(BigDecimal.valueOf(1)), k+1, RoundingMode.HALF_DOWN);

            sum = sum.add(nt);
        }
        return sum;
    }

    private static String format_value(BigDecimal value, int k) {
        return String.format("%." + Integer.toString(k+1) + "f\n", value);
    }

}
