package com.aditya.learning;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class ShapesTest {
	Shapes shape = new Shapes();

	@Test
	void testComputeSquareArea() {
		assertEquals(24*24, shape.computeSquareArea(24));
	}

	@Test
	void testComputeCircleArea() {
		assertEquals(3.14*5*5, shape.computeCircleArea(5));
	}

}
