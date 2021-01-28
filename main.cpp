#include <iostream>
using namespace std;

int main(){

    string customerName, additionalItems, itemBuying;
    string itemsSold[3] = {"Printer","Phone","Table"};
    int quantity, newQuantity, totalQuantity, customerId;
    float itemPrice, amountPaid, itemPrice2, amountBalance, vat;



    cout << "WELCOME TO BENNY'S SUPERMARKET" << endl;

    cout << "....................................................." <<endl;


    //Customer enters name
    cout << "Please enter your name" << endl;
    cin >> customerName;

    cout << "" << endl;

    cout << "Hello, "<< customerName << endl;

    cout << "Please enter customer ID" << endl;
    cin >> customerId;

    cout << "" <<endl;

    cout << "Please note that we charge 12% VAT on all items purchased" << endl;
    cout << "" <<endl;

    //Items that are being sold
    cout << "Items available in stock" << endl;
    cout << "a - " << itemsSold[0] << endl;
    cout << "b - " << itemsSold[1] << endl;
    cout << "c - " << itemsSold[2] << endl;
    cout << "" << endl;


    //Customer chooses item to buy
    cout << "Choose item you want to buy" << endl;
    cin >> itemBuying;


    if ( itemBuying == "a" ) {
        cout << "How many " << itemsSold[0] << "s do you want?"<< endl;
        itemBuying = itemsSold[0];
        itemPrice = 3200.00;
        vat = 0.12 * itemPrice;

        //customer chooses number of items to buy.
        cin >> quantity;



    }
    else if ( itemBuying == "b") {
        cout << "How many " << itemsSold[1] << "s do you want?"<< endl;
        itemBuying = itemsSold[1];
        itemPrice = 1600.00;
        vat = 0.12 * itemPrice;
        //customer chooses number of items to buy.
        cin >> quantity;

    }
    else if ( itemBuying == "c") {
        cout << "How many " << itemsSold[2] << "s do you want?"<< endl;
        itemBuying = itemsSold[2];
        itemPrice = 760.00;
        vat = 0.12 * itemPrice;

        //customer chooses number of items to buy.
        cin >> quantity;
    }
    else {

            cout << "Item not available" << endl;
            return 0;

    };

    cout << "" << endl;

    double totalCost = itemPrice * quantity + vat;

    cout<<customerName<< ", you are buying "<<quantity<< " " <<itemBuying<< "s Which costs GHS " << itemPrice << " a unit (VAT exclusive)"<< endl;

    cout << "" << endl;

    //Ask customer add more items
    cout << "Do you want to add another item?" << endl;
    cout << "a- Yes" << endl;
    cout << "b- No" << endl;

    string answer;
    cin >> answer;

    cout << " " << endl;

    //this is what will display after customer inputs "a"
    while ( answer == "a" ) {
        cout << "What do you want to add?"<< endl;

        //Items that are being sold
        cout << "Items available in stock" << endl;
        cout << "a - " << itemsSold[0] << endl;
        cout << "b - " << itemsSold[1] << endl;
        cout << "c - " << itemsSold[2] << endl;

        cin >> additionalItems;

        cout << " "<< endl;

    if ( additionalItems == "a" ) {
        cout << "How many " << itemsSold[0] << "s do you want?"<< endl;
        additionalItems = itemsSold[0];
        itemPrice2 = 3200.00;
        vat = 0.12 * itemPrice2;

        //customer chooses number of items to buy.
        cin >> newQuantity;

        totalCost = (itemPrice + itemPrice2) * (quantity + newQuantity) + vat;



    }
    else if ( additionalItems == "b") {
        cout << "How many " << itemsSold[1] << "s do you want?"<< endl;
        additionalItems = itemsSold[1];
        itemPrice2 = 1600.00;
        vat = 0.12 * itemPrice2;
        //customer chooses number of items to buy.
        cin >> newQuantity;

        totalCost = (itemPrice + itemPrice2) * (quantity + newQuantity) + vat;

    }
    else if ( additionalItems == "c") {
        cout << "How many " << itemsSold[2] << "s do you want?"<< endl;
        additionalItems = itemsSold[2];
        itemPrice2 = 760.00;
        vat = 0.12 * itemPrice2;
        //customer chooses number of items to buy.
        cin >> newQuantity;

        totalCost = (itemPrice + itemPrice2) * (quantity + newQuantity) + vat;

    }
    else {
        cout << "Item not available" << endl;
        return 0;
    }


        break;
    }

    //what will happen if customer chooses not to add any item.
    if ( answer == "b") {
        cout << "Continue to check out." <<  endl;
        newQuantity = 0;
    }

    cout << "" << endl;



    cout <<"Amount to pay = GHS " <<totalCost<< " (VAT inclusive)"<< endl;
    //user making payment
    cout << "Please type amount being paid" << endl;
    cin >> amountPaid;

    cout << "" << endl;
    amountBalance = amountPaid - totalCost;

    if (amountPaid >= totalCost) {
        cout << "Thanks for your purchase." << endl;
    }
    else {

        do {
            cout << "Amount insufficient" << endl;
            cout << "Please enter amount being paid ( amount should be equal to or more than to GHS " <<totalCost<< " ) " << endl;
            cin >> amountPaid;
        }

        while ( amountPaid < totalCost );
    };

    cout << "....................................................." <<endl;
    totalQuantity = quantity + newQuantity;

    //PRINT RECIEPT

    if (answer == "a") {
            //Receipt for when customer adds more items
    cout << "HERE IS YOUR RECEIPT"<< endl;

    cout << "Customer Name: " << customerName<< endl;
    cout << "Customer ID: " << customerId<< endl;
    cout << "Items Bought"<< endl;
    cout << itemBuying << "(" <<quantity<< ")" << " - GHS " << itemPrice << endl;
    cout << additionalItems << "(" << newQuantity << ")" << " - GHS " << itemPrice2 << endl;
    cout << "Vat = GHS " << vat<< endl;
    cout << "Total Cost = GHS " << totalCost <<endl;
    cout << "Total Quantity = " << totalQuantity << endl;
    cout << "Amount Paid = GHS " << amountPaid << endl;
    cout << "Balance = GHS " << amountBalance << endl;


    }
    else {

    cout << "" << endl;
            //Receipt for when customer does not add more items
    cout << "HERE IS YOUR RECEIPT"<< endl;

    cout << "____________________________________________________" <<endl;
    cout << ""<< endl;

    cout << "Customer Name: " << customerName<< endl;
    cout << "Customer ID: " << customerId<< endl;
    cout << "Items Bought"<< endl;
    cout << itemBuying << "(" <<quantity<< ")" << " - GHS " << itemPrice << endl;
    cout << "Vat = GHS " << vat<< endl;
    cout << "Total Cost = GHS " << totalCost <<endl;
    cout << "Total Quantity = " << totalQuantity << endl;
    cout << "Amount Paid = GHS " << amountPaid << endl;
    cout << "Balance = GHS " << amountBalance << endl;
    };

    cout << "" << endl;

    cout << "....................................................." <<endl;

    cout << "Thank you for transacting with us." << endl;




    return 0;
}
