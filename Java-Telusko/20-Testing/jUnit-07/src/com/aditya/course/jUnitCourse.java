package com.aditya.course;

public class jUnitCourse implements Course {
	@Override
	public boolean coursePurchased() {
		System.out.print("jUnit Course Purchased");
		return true;
	}
}
