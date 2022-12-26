package org.example;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

import javax.crypto.*;
import javax.crypto.spec.SecretKeySpec;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import java.io.*;
import javax.crypto.Cipher;
import javax.xml.stream.XMLOutputFactory;
import javax.xml.stream.XMLStreamException;
import javax.xml.stream.XMLStreamWriter;
import java.nio.charset.StandardCharsets;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Map;
import java.util.TreeMap;

public class BlackBox {

    ArrayList<ArrayList <Integer> > set_integer = new ArrayList<>();
    ArrayList <ArrayList <Double> >  set_double = new ArrayList<>();
    ArrayList <ArrayList <TreeMap <Integer, Integer>> >  set_fractal = new ArrayList<>();
    ArrayList <ArrayList <TreeMap <Integer, Integer>> > set_complex = new ArrayList<>();

    Integer counter = 0;

    public void add_to_integer() throws ParserConfigurationException, IOException, SAXException {

        File fXml = new File("input_int.xml");
        DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
        DocumentBuilder db = dbf.newDocumentBuilder();
        Document doc = db.parse(fXml);

        doc.getDocumentElement().normalize();

        NodeList nodeLst = doc.getElementsByTagName("value");
        set_integer.add(new ArrayList<>());

        for(int je=0;je<nodeLst.getLength();je++)
        {
            Node fstNode=nodeLst.item(je);
            if(fstNode.getNodeType()==Node.ELEMENT_NODE) {
                Element elj=(Element)fstNode;
                NodeList nljx=elj.getElementsByTagName("x");
                Element eljx=(Element)nljx.item(0);
                NodeList nljxc=eljx.getChildNodes();


                set_integer.get(set_integer.size() - 1).add(Integer.parseInt(nljxc.item(0).getNodeValue()));

            }
        }
        counter++;
    }

    public void add_to_double() throws ParserConfigurationException, IOException, SAXException {

        File fXml = new File("input_double.xml");
        DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
        DocumentBuilder db = dbf.newDocumentBuilder();
        Document doc = db.parse(fXml);

        doc.getDocumentElement().normalize();

        NodeList nodeLst = doc.getElementsByTagName("value");
        set_double.add(new ArrayList<>());

        for(int je=0;je<nodeLst.getLength();je++)
        {
            Node fstNode=nodeLst.item(je);
            if(fstNode.getNodeType()==Node.ELEMENT_NODE) {
                Element elj=(Element)fstNode;
                NodeList nljx=elj.getElementsByTagName("x");
                Element eljx=(Element)nljx.item(0);
                NodeList nljxc=eljx.getChildNodes();


                set_double.get(set_double.size() - 1).add(Double.parseDouble(nljxc.item(0).getNodeValue()));

            }
        }
        counter++;
    }

    public void output_int() {
        for (int k = 0; k < set_integer.size(); ++k) {
            System.out.println("Set of integers №" + (k + 1));
            for (ArrayList<Integer> integers : set_integer) {
                integers.forEach((e) -> System.out.print(e + ", "));
            }
            System.out.println("\n");
        }
    }

    public void output_doubles() {
        for (int i = 0; i < set_double.size(); ++i) {
            System.out.println("Set of doubles №" + (i + 1));
            for (ArrayList<Double> doubles : set_double) {
                doubles.forEach((e) -> System.out.print(e + ", "));
            }
            System.out.println("\n");
        }
    }

    public void add_to_fractals() throws ParserConfigurationException, IOException, SAXException {

        File fXml = new File("input_fractals.xml");
        DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
        DocumentBuilder db = dbf.newDocumentBuilder();
        Document doc = db.parse(fXml);

        doc.getDocumentElement().normalize();

        NodeList nodeLst = doc.getElementsByTagName("value");
        set_fractal.add(new ArrayList<>());

        for(int je=0;je<nodeLst.getLength();je++)
        {
            Node fstNode=nodeLst.item(je);
            if(fstNode.getNodeType()==Node.ELEMENT_NODE) {
                Element elj=(Element)fstNode;
                NodeList nljx=elj.getElementsByTagName("x");
                Element eljx=(Element)nljx.item(0);
                NodeList nljxc=eljx.getChildNodes();

                NodeList nljy=elj.getElementsByTagName("y");
                Element eljy=(Element)nljy.item(0);
                NodeList nljyc=eljy.getChildNodes();

                set_fractal.get(set_fractal.size() - 1).add(new TreeMap<>());
                set_fractal.get(set_fractal.size() - 1).get(je).put(
                        Integer.parseInt(nljxc.item(0).getNodeValue()), Integer.parseInt(nljyc.item(0).getNodeValue())
                );


            }
        }
        counter++;
    }

    public void output_fractals() {
        for (int i = 0; i < set_fractal.size(); ++i) {
            System.out.println("Set of fractals №" + (i + 1));
            for (int j = 0; j < set_fractal.get(i).size(); ++j) {
                for (Map.Entry<Integer, Integer> entry : set_fractal.get(i).get(j).entrySet()) {
                    Integer key = entry.getKey();
                    Integer value = entry.getValue();

                    System.out.println(key + " / " + value);
                }
            }
        }
    }

    public void add_to_complex() throws ParserConfigurationException, IOException, SAXException {

        File fXml = new File("input_complex.xml");
        DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
        DocumentBuilder db = dbf.newDocumentBuilder();
        Document doc = db.parse(fXml);

        doc.getDocumentElement().normalize();

        NodeList nodeLst = doc.getElementsByTagName("value");
        set_complex.add(new ArrayList<>());

        for(int je=0;je<nodeLst.getLength();je++)
        {
            Node fstNode=nodeLst.item(je);
            if(fstNode.getNodeType()==Node.ELEMENT_NODE) {
                Element elj=(Element)fstNode;
                NodeList nljx=elj.getElementsByTagName("x");
                Element eljx=(Element)nljx.item(0);
                NodeList nljxc=eljx.getChildNodes();

                NodeList nljy=elj.getElementsByTagName("y");
                Element eljy=(Element)nljy.item(0);
                NodeList nljyc=eljy.getChildNodes();

                set_complex.get(set_complex.size() - 1).add(new TreeMap<>());
                set_complex.get(set_complex.size() - 1).get(je).put(
                        Integer.parseInt(nljxc.item(0).getNodeValue()), Integer.parseInt(nljyc.item(0).getNodeValue())
                );

            }
        }
        counter++;
    }

    public void output_comples() {
        for (int i = 0; i < set_complex.size(); ++i) {
            System.out.println("Set of complexes №" + (i + 1));
            for (int j = 0; j < set_complex.get(i).size(); ++j) {
                for (Map.Entry<Integer, Integer> entry : set_complex.get(i).get(j).entrySet()) {
                    Integer key = entry.getKey();
                    Integer value = entry.getValue();

                    System.out.println(key + " + " + value + "*i");
                }
            }
        }
    }
    public byte[] get_encrypted_string () throws NoSuchPaddingException, NoSuchAlgorithmException, InvalidKeyException, IllegalBlockSizeException, BadPaddingException, UnsupportedEncodingException {

        byte[] keyBytes   = new byte[]{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
        String algorithm  = "AES";
        SecretKeySpec key = new SecretKeySpec(keyBytes, algorithm);

        Cipher cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");

        cipher.init(Cipher.ENCRYPT_MODE, key);

        StringBuilder tmp_k = new StringBuilder();
        for (int i = 0; i < set_integer.size(); ++i) {
            for (ArrayList<Integer> integers : set_integer) {
                tmp_k.append(integers);
            }
        }

        byte[] plainText  = tmp_k.toString().getBytes(StandardCharsets.UTF_8);

        return cipher.doFinal(plainText);

    }

    public void write_to_xml () throws FileNotFoundException, XMLStreamException {

        XMLOutputFactory output = XMLOutputFactory.newInstance();
        XMLStreamWriter writer = output.createXMLStreamWriter(
                new FileOutputStream("test.xml"));

        writer.writeStartDocument();
        for (int k = 0; k < set_integer.size(); ++k) {
            writer.writeStartElement("Set of integers №" + (k + 1));
            for (ArrayList<Integer> integers : set_integer) {
                integers.forEach((e) -> {
                    try {
                        writer.writeStartElement(e + ", ");
                    } catch (XMLStreamException ex) {
                        throw new RuntimeException(ex);
                    }
                });
            }

        }
        writer.writeEndDocument();
        writer.flush();
        writer.close();

    }

}
