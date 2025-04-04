package com.aditya.service;

import com.aditya.course.Course;
public class PurchaseCourse {
	private Course course;
	
	public boolean proceedWithCourse(Course course) {
		return course.coursePurchased();
	}
}
