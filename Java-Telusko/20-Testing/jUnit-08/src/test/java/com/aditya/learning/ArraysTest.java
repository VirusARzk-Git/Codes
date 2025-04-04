package com.aditya.learning;

import static org.junit.jupiter.api.Assertions.*;

import java.util.Arrays;

import org.junit.jupiter.api.Test;

class ArraysTest {

	@Test
	void testArrays() {
		int []expected = {2,4,6,8};
		int []actual = {8,4,6,2};
		Arrays.sort(actual);
//		assertEquals(expected, actual);
		assertArrayEquals(expected, actual);
	}

}
