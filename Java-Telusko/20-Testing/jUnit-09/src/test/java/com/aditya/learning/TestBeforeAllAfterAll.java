package com.aditya.learning;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.*;

@TestInstance(TestInstance.Lifecycle.PER_CLASS)
class TestBeforeAllAfterAll {

	Shapes shape;
	
	TestBeforeAllAfterAll(){
		shape = new Shapes();
		System.out.println("Test Object is created before Test Method\n");
	}
	
	@BeforeAll
	void beforeAll() {
		System.out.println("Before All Tests\n");
	}
	
	@BeforeEach
	void init() {
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
	
	@AfterAll
	void afterAll() {
		System.out.println("After All Tests");
	}


}
