import java.util.ArrayList;
import java.util.List;

// Define a class to represent Product
class Product {
    private String productId;
    private String productName;

    public Product(String productId, String productName) {
        this.productId = productId;
        this.productName = productName;
    }
}

// Define a class to represent Line Item
class LineItem {
    private Product product;

    public LineItem(Product product) {
        this.product = product;
    }
}

// Define a class to represent Account
class Account {
    private List<ShoppingCart> shoppingCarts = new ArrayList<>();
    private List<CustomerOrder> orders = new ArrayList<>();
    private List<Payment> payments = new ArrayList<>();

    public void addShoppingCart(ShoppingCart shoppingCart) {
        shoppingCarts.add(shoppingCart);
    }

    public void addOrder(CustomerOrder order) {
        orders.add(order);
    }

    public void addPayment(Payment payment) {
        payments.add(payment);
    }
}

// Define a class to represent ShoppingCart
class ShoppingCart {
    private Account account;
    private List<LineItem> lineItems = new ArrayList<>();

    public ShoppingCart(Account account) {
        this.account = account;
    }

    public void addLineItem(LineItem lineItem) {
        lineItems.add(lineItem);
    }
}

// Define a class to represent CustomerOrder
class CustomerOrder {
    private Account account;
    private String orderStatus;
    private List<LineItem> lineItems = new ArrayList<>();

    public CustomerOrder(Account account, String orderStatus) {
        this.account = account;
        this.orderStatus = orderStatus;
    }

    public void addLineItem(LineItem lineItem) {
        lineItems.add(lineItem);
    }
}

// Define a class to represent Payment
class Payment {
    private String paymentId;
    private Account account;

    public Payment(String paymentId, Account account) {
        this.paymentId = paymentId;
        this.account = account;
    }
}

// Define a class to represent Customer
class Customer {
    private String customerId;
    private Account account;

    public Customer(String customerId, Account account) {
        this.customerId = customerId;
        this.account = account;
    }

    public void registerWebUser(String loginName) {
        // Implement web user registration logic here
    }
}

// Define a class to represent WebUser
class WebUser extends Customer {
    private String loginName;
    private String webUserStatus;

    public WebUser(String customerId, Account account, String loginName) {
        super(customerId, account);
        this.loginName = loginName;
    }

    public void changeWebUserStatus(String status) {
        webUserStatus = status;
    }
}

public class UMLClassDemo {
    public static void main(String[] args) {
        // Create instances and establish relationships based on the UML diagram
        Product product1 = new Product("P1", "Product 1");
        LineItem lineItem1 = new LineItem(product1);

        Account account = new Account();
        ShoppingCart shoppingCart = new ShoppingCart(account);
        shoppingCart.addLineItem(lineItem1);
        account.addShoppingCart(shoppingCart);

        CustomerOrder order1 = new CustomerOrder(account, "New");
        order1.addLineItem(lineItem1);
        account.addOrder(order1);

        Payment payment1 = new Payment("PAY1", account);
        account.addPayment(payment1);

        Customer customer1 = new Customer("C1", account);
        customer1.registerWebUser("webuser1");

        WebUser webUser1 = new WebUser("C2", account, "webuser2");
        webUser1.changeWebUserStatus("Active");
    }
}
