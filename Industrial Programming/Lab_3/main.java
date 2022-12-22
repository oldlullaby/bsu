import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.*;

public class Main {

    public class sort_arr implements Comparable {

        @Override
        public int compareTo(Object o) {
            sort_arr other = (sort_arr)o;
            if (this == other)
                return 0;
            if (this.age < other.age) return 1;
            else if (this.age == other.age) return 0;
            else return -1;

        }

    public static Double[][] copy(Double[][] src, double min, int x, int y) {
        if (src == null) {
            return null;
        }

        Double[][] copy = new Double[src.length + 1][];

        // 3 4 5 6 2 1 3 7 8 9

        for (int i = 0; i < x; ++i) {
            copy[i] = new Double[src[i].length + 1];
            System.arraycopy(src[i], 0, copy[i], 0, x);
            System.arraycopy(src[i], x, copy[i], x + 1, src[i].length - x);
        }

        copy[x] = new Double [src.length + 1];
        Arrays.fill(copy[x], min);

        for (int i = x; i < src.length; i++) {
            copy[i + 1] = new Double[src[i].length + 1];
            System.arraycopy(src[i], 0, copy[i + 1], 0, x);
            System.arraycopy(src[i], x, copy[i + 1], x + 1, src[i].length - x);
        }

        for (int i = 0; i < src.length + 1; ++i) {
            copy[i][x] = min;
        }

        Scanner in = new Scanner(System.in);
        int i = in.nextInt();
        int j = in.nextInt();

        Arrays.sort(copy[0], i, j, Comparator.reverseOrder());


        return copy;
    }

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        Double[][] arr = new Double[n][n];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                arr[i][j] = in.nextDouble();

        Double min = arr[0][0];
        int x = 0, y = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; ++j)
                if (arr[i][j] < min) {
                    min = arr[i][j];
                    x = j;
                    y = i;
                }


        Double[][] destination = copy(arr, min, x, y);
        System.out.println(Arrays.deepToString(destination));
        System.out.println();
        System.out.println("Formatted output: ");

        for (int i = 0; i < destination[0].length; i++) {
            for (int j = 0; j < destination[0].length; j++) {
                if (destination[i][j].intValue() == destination[i][j]) {

                    NumberFormat numberFormat = NumberFormat.getCurrencyInstance();
                    System.out.print(numberFormat.format(destination[i][j])  + " ");

                } else {

                    Locale locale = new Locale("be", "BY");
                    DecimalFormat decimalFormat3 = (DecimalFormat)
                            NumberFormat.getPercentInstance(locale);
                    System.out.print(decimalFormat3.format(destination[i][j]) + " ");

                }
            }
            System.out.println();
        }


        Double []arr_tmp = Arrays.copyOf(destination[0], destination[0].length + 2);
        arr_tmp[destination[0].length] = 15.4;
        arr_tmp[destination[0].length + 1] = 30.7;

        System.out.println("\nNew array copy after modifications:");
        for (Double aDouble : arr_tmp) System.out.print(aDouble + " ");


    }
}
