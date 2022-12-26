package org.example;

import java.io.File;
import java.io.IOException;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {
    public static void main(String[] args) {

        String path = "input.txt";
        try (Scanner scan = new Scanner(new File(path))) {
            while (scan.hasNextLine()) {

                String sb = scan.nextLine();

                Pattern pattern = Pattern.compile("^[1-9]([0-9]{0,2})((\\.\\d+$)|((\\s[0-9]{3})+(\\.\\d+)?$)|((,[0-9]{3})+(\\.\\d+)?$)|$)");
                Matcher matcher = pattern.matcher(sb);
                while (matcher.find()) {
                    System.out.println(matcher.group());
                }

            }
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}
