package com.aditya.learning;

import static org.junit.Assert.*;

import org.junit.Test;

public class CalcTest {

	@Test
	public void test() {
		Calc c = new Calc();
		int actual = c.divide(10, 5);
		int expected = 2;
		assertEquals(expected, actual);
//		System.out.println("First JUnit test");
//		 fail("Not yet implemented");
	}
}
