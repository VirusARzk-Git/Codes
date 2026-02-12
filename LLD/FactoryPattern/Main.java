package FactoryPattern;

public class Main {

  public static void main(String[] args) {
    ShapeFactory shapeFactory = new ShapeFactory();
    Shape shape1 = shapeFactory.getShape("CIRCLE");
    Shape shape2 = shapeFactory.getShape("RECTANGLE");
    Shape shape3 = shapeFactory.getShape("TRIANGLE");

    shape1.draw();
    shape2.draw();
    if (shape3 != null) {
      shape3.draw();
    } else {
      System.out.println("Shape not found");
    }
  }
}
