package ObserverDesignPattern.Observer;

import ObserverDesignPattern.Observable.StocksObservable;

public class EmailObserver implements NotifyObserver {

  String userName;
  StocksObservable observable;

  public EmailObserver(String emailId, StocksObservable observable) {
    this.userName = emailId;
    this.observable = observable;
  }

  @Override
  public void update() {
    sendMsgOnEmail(userName, "Stock is available now");
  }

  public void sendMsgOnEmail(String userName, String msg) {
    // Send email to userName about stock availability
    System.out.println("notification sent to " + userName);
  }
}
