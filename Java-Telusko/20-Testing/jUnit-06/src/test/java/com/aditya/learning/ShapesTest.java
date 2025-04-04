package com.aditya.learning;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class ShapesTest {

	Shapes shape = new Shapes();
	@Test
	void testComputeSquareArea() {
		assertNotEquals(5765, shape.computeSquareArea(24));
	}
	
	@Test
	void testComputeSquareAreawithMessage(){
		assertNotEquals(5765, shape.computeSquareArea(24), "Area of square is correct");
	}

}
