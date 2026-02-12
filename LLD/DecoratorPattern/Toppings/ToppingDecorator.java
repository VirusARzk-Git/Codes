package DecoratorPattern.Toppings;

import DecoratorPattern.Pizza.BasePizza;

public abstract class ToppingDecorator extends BasePizza {

  protected BasePizza pizza;

  public ToppingDecorator(BasePizza pizza) {
    this.pizza = pizza;
  }
}
