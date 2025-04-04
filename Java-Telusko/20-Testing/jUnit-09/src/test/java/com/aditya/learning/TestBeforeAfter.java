package com.aditya.learning;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.*;

class TestBeforeAfter {
	Shapes shape;

	@BeforeEach
	void init() {
		shape = new Shapes();
		System.out.println("Before Test");
	}
	
	@Test
	void testComputeSquareArea() {
		assertEquals(24*24, shape.computeSquareArea(24));
		System.out.println("Actual Test Running");
	}

	@Test
	void testComputeCircleArea() {	
		assertEquals(3.14*5*5, shape.computeCircleArea(5));
		System.out.println("Actual Test Running");
	}
	
	@AfterEach
	void destroy() {
		System.out.println("After Test\n");
	}

}

