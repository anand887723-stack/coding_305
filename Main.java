import java.util.ArrayList;

class Payment {
    private double paymentAmount;

    public Payment(double paymentAmount) {
        this.paymentAmount = paymentAmount;
    }

    public double getPaymentAmount() {
        return paymentAmount;
    }

    public void setPaymentAmount(double paymentAmount) {
        this.paymentAmount = paymentAmount;
    }

    public void paymentDetails() {
        System.out.println("Payment of $" + paymentAmount);
    }
}

class Bank {
    private ArrayList<Payment> payments;

    public Bank() {
        payments = new ArrayList<>();
    }

    public void addPayment(Payment payment) {
        payments.add(payment);
    }

    public void showPayments() {
        for (Payment payment : payments) {
            payment.paymentDetails();
        }
    }
}

class CashPayment extends Payment {
    private String clientName;

    public CashPayment(double paymentAmount, String clientName) {
        super(paymentAmount);
        this.clientName = clientName;
    }

    public String getClientName() {
        return clientName;
    }

    @Override
    public void paymentDetails() {
        System.out.println("Payment of $" + getPaymentAmount());
        System.out.println("Client " + clientName + " paid in cash");
        System.out.println("-----------------------------------------");
    }
}

class CreditCardPayment extends Payment {
    private String cardNumber;
    private String expirationDate;

    public CreditCardPayment(double paymentAmount, String cardNumber, String expirationDate) {
        super(paymentAmount);
        this.cardNumber = cardNumber;
        this.expirationDate = expirationDate;
    }

    public String getCardNumber() {
        return cardNumber;
    }

    public String getCardExpiration() {
        return expirationDate;
    }

    @Override
    public void paymentDetails() {
        System.out.println("Payment of $" + getPaymentAmount());
        System.out.println("Using the card " + cardNumber + " with expiration date " + expirationDate);
        System.out.println("-----------------------------------------");
    }
}

public class Main {
    public static void main(String[] args) {
        // Bank
        Bank NationalBank = new Bank();

        // Payment
        Payment pay1 = new Payment(13.95);
        NationalBank.addPayment(pay1);

        // Two cash payments
        Payment cash1 = new CashPayment(39.93, "Emma");
        Payment cash2 = new CashPayment(15.60, "John");
        NationalBank.addPayment(cash1);
        NationalBank.addPayment(cash2);

        // Two credit card payments
        Payment credit1 = new CreditCardPayment(56.60, "********678", "06/22");
        Payment credit2 = new CreditCardPayment(19.65, "********123", "07/25");
        NationalBank.addPayment(credit1);
        NationalBank.addPayment(credit2);

        // Show details
        NationalBank.showPayments();
    }
}
