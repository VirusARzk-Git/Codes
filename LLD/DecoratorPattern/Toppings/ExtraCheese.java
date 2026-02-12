package DecoratorPattern.Toppings;

import DecoratorPattern.Pizza.BasePizza;

public class ExtraCheese extends ToppingDecorator {

  public ExtraCheese(BasePizza pizza) {
        super(pizza);
    }

  @Override
  public int cost() {
    return this.pizza.cost() + 10;
  }
}
