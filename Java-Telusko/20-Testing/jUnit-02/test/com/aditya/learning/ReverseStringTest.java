package com.aditya.learning;

import static org.junit.Assert.*;

import org.junit.Test;

public class ReverseStringTest {

  @Test(timeout = 100)
  public void test() {
    ReverseString rev = new ReverseString();
    String actual = rev.reverse("Java");
	String expected = "avaJ";
    assertEquals(expected, actual);
//    fail("Not yet implemented");
  }
}
