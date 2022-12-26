package org.example;

import org.junit.Test;
import org.junit.After;
import org.junit.Before;

import java.io.ByteArrayOutputStream;
import java.io.PrintStream;
import java.io.ByteArrayInputStream;
import java.io.InputStream;

import static org.junit.Assert.assertEquals;


public class MainTest {

    private final InputStream systemIn = System.in;
    private final PrintStream systemOut = System.out;

    private ByteArrayInputStream testIn;
    private ByteArrayOutputStream testOut;

    @Before
    public void setUpOutput() {
        testOut = new ByteArrayOutputStream();
        System.setOut(new PrintStream(testOut));
    }

    private void provideInput(String data) {
        testIn = new ByteArrayInputStream(data.getBytes());
        System.setIn(testIn);
    }

    private String getOutput() {
        return testOut.toString();
    }

    @After
    public void restoreSystemInputOutput() {
        System.setIn(systemIn);
        System.setOut(systemOut);
    }

    @Test
    public void testCase1() {
        final String testString = "3" + "\n" + "1 2 3 4 5 6 7 8 9"+ "\n" + "2 2";
        provideInput(testString);
        Main.main(new String[1]);
        assertEquals("[[1.0, 1.0, 1.0, 1.0], [1.0, 1.0, 2.0, 3.0], [1.0, 4.0, 5.0, 6.0], [1.0, 7.0, 8.0, 9.0]]" +
                        "\n" + "\n" + "Formatted output:" + "\n" +
        "1,00 Br 1,00 Br 1,00 Br 1,00 Br " + "\n" +
        "1,00 Br 1,00 Br 2,00 Br 3,00 Br " + "\n" +
        "1,00 Br 4,00 Br 5,00 Br 6,00 Br " + "\n" +
        "1,00 Br 7,00 Br 8,00 Br 9,00 Br " + "\n" + "\n" +

        "New array copy after modifications:" + "\n" +
        "1.0 1.0 1.0 1.0 15.4 30.7 ", getOutput());
    }


}
