package com.aditya.learning;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class AssertTest {

	@Test
	void test() {
		String str = "Junit";
		assertTrue(str.equals("jUnit"));
	}

}
