package ObserverDesignPattern.Observer;

import ObserverDesignPattern.Observable.StocksObservable;

public class MobileObserver implements NotifyObserver {

  String userName;
  StocksObservable observable;

  public MobileObserver(String phoneNumber, StocksObservable observable) {
    this.userName = phoneNumber;
    this.observable = observable;
  }

  @Override
  public void update() {
    sendMsgOnMobile(userName, "Stock is available now");
  }

  public void sendMsgOnMobile(String userName, String msg) {
    // Send email to userName about stock availability
    System.out.println("notification sent to " + userName);
  }
}
