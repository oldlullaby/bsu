import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.concurrent.ThreadLocalRandom;


class MyString implements Comparable<MyString> {
    private String name;

    public MyString(String name) {
        this.name = name;
    }

    @Override
    public int compareTo(MyString o) {
        int compare;
        String digitsFirst = this.getDigitsFromString();
        String digitsSecond = o.getDigitsFromString();
        int lengthFirst = digitsFirst.length();
        int lengthSecond = digitsSecond.length();

        if (lengthFirst == 0 && lengthFirst == lengthSecond) {
            compare = this.name.compareTo(o.name);
        } else if (lengthSecond == 0 || lengthFirst == 0) {
            compare = lengthSecond - lengthFirst;
        } else {
            compare = lengthFirst - lengthSecond;
            if (compare == 0) {
                compare = digitsFirst.compareTo(digitsSecond);
            }
        }
        return compare;
    }

    private String getDigitsFromString() {
        return this.name.replaceAll("[^a-zA-Z]", "");
    }

    @Override
    public String toString() {
        return this.name;
    }
}


public class Main {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        System.out.println("String 1: ");
        String ss_1 = in.nextLine();

        System.out.println("String 2: ");
        String ss_2 = in.nextLine();

        System.out.println("P-value: ");
        int ss_3 = in.nextInt();

        System.out.println();

        StringTokenizer tokenizer = new StringTokenizer(ss_1, ss_2);
        Integer []arr = new Integer[tokenizer.countTokens()];

        int i = 0;

        while (tokenizer.hasMoreTokens()) {

            String token = tokenizer.nextToken();

            Pattern pattern = Pattern.compile("^0[1-7][0-7]{0,8}$");
            Matcher matcher = pattern.matcher(token);
            while (matcher.find()) {

                arr[i] = Integer.parseInt(token.substring(matcher.start(), matcher.end())); i++;
                System.out.println(String.format(token.substring(matcher.start(), matcher.end())));

            }

        }


        tokenizer = new StringTokenizer(ss_1, ss_2);
        while (tokenizer.hasMoreTokens()) {

            String token = tokenizer.nextToken();

            Pattern pattern = Pattern.compile("\\w+");
            Matcher matcher = pattern.matcher(token);
            while (matcher.find()) {
                System.out.println(String.format(token.substring(matcher.start(), matcher.end())));
            }

        }

        System.out.println();
        System.out.println();

        Pattern p = Pattern.compile("\\d+");
        Matcher m = p.matcher(ss_1);

        while(m.find()) {

            if (Integer.parseInt(ss_1.substring(m.start(), m.end())) == ss_3) {
                System.out.println(m.start());
            }
        }


        int randomNum;
        if (i > 0) randomNum = ThreadLocalRandom.current().nextInt(0, i);
        else randomNum = ThreadLocalRandom.current().nextInt(-30, 30);

        String ss_1_new;
        if (arr.length > 0 && i > 0) ss_1_new = ss_1.substring(0, ss_1.length() / 2) + -arr[randomNum] + ss_1.substring(ss_1.length() / 2);
        else ss_1_new = ss_1.substring(0, ss_1.length() / 2) + -randomNum + ss_1.substring(ss_1.length() / 2);

        System.out.println(String.format("New string: " + ss_1_new));

        // Выдаленне перадапошняй велічыні з радка.

        Pattern pattern = Pattern.compile("\\d+");
        Matcher matcher = pattern.matcher(ss_1);
        Integer []tmp = new Integer[2];

        if (matcher.find()) {
            tmp[0] = Integer.parseInt(ss_1.substring(matcher.start(), matcher.end()));
        }
        if (matcher.find()) {
            tmp[1] = Integer.parseInt(ss_1.substring(matcher.start(), matcher.end()));
        }

        while (matcher.find()) {
            tmp[0] = tmp[1];
            tmp[1] = Integer.parseInt(ss_1.substring(matcher.start(), matcher.end()));
        }

        String ss_1_new_new = ss_1.replace(String.valueOf(tmp[0]) + " ", "");
        System.out.println(String.format("ss1_new_new: " + ss_1_new_new));


        ArrayList<MyString> list = new ArrayList<>();
        tokenizer = new StringTokenizer(ss_1, ss_2);
        while (tokenizer.hasMoreTokens()) {
            String token = tokenizer.nextToken();
            list.add(new MyString(token));
        }

        Collections.sort(list);
        System.out.println();

        for (MyString myString : list) {
            System.out.println(myString);
        }

        

    }

}
