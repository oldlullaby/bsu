package org.example;

import org.xml.sax.SAXException;

import javax.crypto.BadPaddingException;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.NoSuchPaddingException;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.stream.XMLStreamException;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import java.util.Arrays;
import java.util.zip.ZipEntry;
import java.util.zip.ZipOutputStream;

public class Main
{
    public static void main( String[] args ) throws ParserConfigurationException, IOException, SAXException, NoSuchPaddingException, NoSuchAlgorithmException, IllegalBlockSizeException, BadPaddingException, InvalidKeyException, XMLStreamException {

        BlackBox example_1 = new BlackBox();

        example_1.add_to_integer(); example_1.output_int();
        example_1.add_to_double(); example_1.output_doubles();
        example_1.add_to_fractals(); example_1.output_fractals();
        example_1.add_to_complex(); example_1.output_comples();
        System.out.println(Arrays.toString(example_1.get_encrypted_string()));

        String filename = "input_double.xml";
        try(ZipOutputStream zout = new ZipOutputStream(new FileOutputStream("output_zip.zip"));
            FileInputStream fis = new FileInputStream(filename);) {

            ZipEntry entry1 = new ZipEntry("input_double.xml");
            zout.putNextEntry(entry1);
            byte[] buffer = new byte[fis.available()];
            zout.write(buffer);
            zout.closeEntry();
        }
        catch(Exception ex){
            System.out.println(ex.getMessage());
        }

        example_1.write_to_xml();

    }
}
