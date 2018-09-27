public interface PaymentPolicy {
  public int calculate( Integer entry, Integer exit);
}

public class PaymenPolicyWeekly implements PaymentPolicy {
  Array<PaymentPolicy> multicastPolicy = new Array<PaymentPolicy>();

  constructor() {
    PaymentPolicyDaily daily = new PayentPolicyDaily();
    PaymentPolicyFixed fixed = new PaymentPolicyFixed();
    PaymentPolicyMax maxP = new mentPolicyMax();
    PaymentPerHour perHr = new entPerHour();
    PaymentEscape escape = new entEscape(daily);

    multicastPolicy.add(daily);
    multicastPolicy.add(fixed);
    multicastPolicy.add(maxP);
    multicastPolicy.add(perHr);
    multicastPolicy.add(escape);
  }
  public int calculate( Integer entry, Integer exit) {
    
    for (PaymentPolicy policy : multicastPolicy) {
      policy.calculate(entry, exit);
    }
  }
}


public class ClientMachine {
  constructor(PaymentPolicy p) {}
}
