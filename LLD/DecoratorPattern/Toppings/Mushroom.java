package DecoratorPattern.Toppings;
import DecoratorPattern.Pizza.BasePizza;

public class Mushroom extends ToppingDecorator {

  public Mushroom(BasePizza pizza) {
    super(pizza);
  }

  @Override
  public int cost() {
    return this.pizza.cost() + 15;
  }
}
