package com.aditya.learning;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class ReverseStringTest {

	ReverseString rev = new ReverseString();
	@Test
	void testReverseString_OneWord() {
		assertEquals("aytidA", rev.reverse("Aditya"));
	}
	
	@Test
	void testReverseString_MultipleWords() {
		assertEquals("jaR aytidA", rev.reverse("Aditya Raj"));
	}

}
