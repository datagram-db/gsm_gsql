package uk.jackbergus.gsm;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;

import java.util.ArrayList;

public class ArbitraryClassTest {
    public static void main(String args[]) throws IllegalAccessException, JsonProcessingException {
        ArbitraryClass ac = new ArbitraryClass();
        ac.doubleField = 3.0;
        ac.stringField = "This is some text";
        ac.additional_textual_content.add("this");
        ac.additional_textual_content.add("is");
        ac.additional_textual_content.add("some");
        ac.additional_textual_content.add("text");

        ArbitraryClass.ExternalReference ref1 = new ArbitraryClass.ExternalReference("Alice", "Miller");
        ref1.loopback_reference = ac;
        ac.externalTables.add(ref1);
        ArbitraryClass.ExternalReference ref2 = new ArbitraryClass.ExternalReference("Bob", "Jenkins");
        ref1.loopback_reference = null;
        ac.externalTables.add(ref2);

        GSMObject[] array = new GSMObject[3];
        array[0] = GSMUtil.fromObject(ac);
        array[1] = GSMUtil.fromObject(ref1);
        array[2] = GSMUtil.fromObject(ref2);

        ObjectMapper objectMapper = new ObjectMapper();
        System.out.println(objectMapper.writeValueAsString(array));
    }
}
