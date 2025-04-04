package com.aditya.learning;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class TestTrial {

	@Test
	void test() {
		assertEquals(6, 6);
//		fail("Not yet implemented");
	}
	
	@Test
	void testComputeSquareArea()
	{
		Shapes shape = new Shapes();
		assertEquals(24*24, shape.computeSquareArea(24),() -> "Area is Wrong");
	}

}
