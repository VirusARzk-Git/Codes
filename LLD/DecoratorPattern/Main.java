package DecoratorPattern;

import DecoratorPattern.Pizza.*;
import DecoratorPattern.Toppings.*;
public class Main {
    public static void main(String[] args) {
        BasePizza pizza = new Margherita();
        System.out.println("Cost of Margherita: " + pizza.cost());

        pizza = new ExtraCheese(pizza);
        System.out.println("Cost of Margherita with Extra Cheese: " + pizza.cost());

        pizza = new Mushroom(pizza);
        System.out.println("Cost of Margherita with Extra Cheese and Mushroom: " + pizza.cost());

    }
}
