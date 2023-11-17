public static void main (String [] args){
// Bank
Bank NationalBank = new Bank ( ) ;
// Payment
Payment pay1= new Payment (13.95);
NationalBank.addEayment (pay1) ;
// Two cash payments
Payment cash1 = new CashPayment (39.93, "Emma") ;
CashPayment cash2 =new CashPayment (15.60, "John");
NationalBank.addPayment (cash1) ;
NationalBank.addPayment (cash2) ;
// Two credit card payments
CreditCardPayment credit1 =new CreditCardPayment (56.60 ,"********678","06/22");
Payment credit2 = new CreditCardPayment (19.65,"********123","07/25");
NationalBank.addPayment (credit1) ;
NationalEank.addEayment (credit2) ;
// Show details
NationalBank.showPayments ( ) ;
}