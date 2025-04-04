package com.aditya.learning;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class ReverseStringTest {

	@Test
	void test() {
		ReverseString rev = new ReverseString();
//		String actual = rev.reverse("Java");
//		String expected = "avaJ";
		assertEquals("avaJ", rev.reverse("Java"));
		assertEquals("olleH", rev.reverse("Hello"));
//		fail("Not yet implemented");
	}

}
