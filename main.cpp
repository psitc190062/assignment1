/*UNIVERSITY OF CAPE COAST
DEPARTMENT OF COMPUTER SCIENCE AND IT
PROGRAMMING AND PROBLEM ANALYSIS (INF 217)

PS/ITC/19/0062
*/

#include <iostream>
#include <string>
using namespace std;

int main(){

    string customerName, additionalItems, itemBuying, customerId,itemsSold[3] = {"Printer","Phone","Table"};
    int quantity, newQuantity, totalQuantity;
    double itemPrice, amountPaid, itemPrice2, amountBalance, vat;

    cout << "WELCOME TO BENNY'S SUPERMARKET" << endl;

    cout << "....................................................." <<endl;


    //Customer enters name
    cout << "Please enter your name" << endl;
    getline(cin, customerName);
    cout <<  endl;

    cout << "Hello, "<< customerName << endl;
    cout << "Please enter customer ID" << endl;
    cin >> customerId;
    cout << endl;

    cout << "Please note that we charge 12% VAT on all items purchased" << endl;
    cout << endl;

    //Lis of items that are being sold
    cout << "Items available in stock" << endl;
    cout << "a - " << itemsSold[0] << "-- GHS 320.00" <<endl;
    cout << "b - " << itemsSold[1] << "-- GHS 1600.00"<< endl;
    cout << "c - " << itemsSold[2] << "-- GHS 60.00"<< endl;
    cout << endl;

    //Customer chooses item to buy
    cout << "Choose item you want to buy" << endl;
    cin >> itemBuying;

    if ( (itemBuying == "A") || (itemBuying == "a") || (itemBuying == "Printer")|| (itemBuying == "printer") || ( itemBuying == "PRINTER" ) ) {
        itemBuying = itemsSold[0];
        itemPrice = 320.00;
        vat = 0.12 * itemPrice;

    }
    else if ( (itemBuying == "B") || (itemBuying == "b" ) || (itemBuying == "Phone") || (itemBuying == "phone") || ( itemBuying == "PHONE" ) ) {
        itemBuying = itemsSold[1];
        itemPrice = 1600.00;
        vat = 0.12 * itemPrice;
    }
    else if ( (itemBuying == "C") || (itemBuying == "c") || (itemBuying == "Table") || (itemBuying == "table") || ( itemBuying == "TABLE" ) ) {
        itemBuying = itemsSold[2];
        itemPrice = 60.00;
        vat = 0.12 * itemPrice;
    }
    else {
            cout << "Item not available" << endl;
            return 0;

    };
    cout << "How many " << itemBuying << "s do you want?"<< endl;
    cin >> quantity; //customer chooses number of items to buy.
    cout << endl;

    double totalCost = itemPrice * quantity + vat; //declaration of total cost without any additional item
    cout<<customerName<< ", you are buying "<<quantity<< " " <<itemBuying<< "s Which costs GHS " << itemPrice << " a unit (VAT exclusive)"<< endl;
    cout << endl;

    //Ask customer add more items
    cout << "Do you want to add another item?" << endl;
    cout << "a- Yes" << endl;
    cout << "b- No" << endl;

    string answer;//Stores user's answer input
    cin >> answer;//accepts answer of the use either (yes or no)
    cout <<endl;

    //this is what will display after customer inputs "a"
    while ( (answer == "a") || (answer == "A") ) {
        cout << "What do you want to add?"<< endl;

        //Items that are being sold
        cout << "Items available in stock" << endl;
        cout << "a - " << itemsSold[0]<< "-- GHS 320.00" << endl;
        cout << "b - " << itemsSold[1]<< "-- GHS 1600.00" << endl;
        cout << "c - " << itemsSold[2]<< "-- GHS 60.00" << endl;

        cin >> additionalItems;//Accepts additional items user is adding

        cout << endl;

    if ( ( additionalItems == "A" ) || ( additionalItems == "a") || (additionalItems == "Printer")|| (additionalItems == "printer") || ( additionalItems == "PRINTER" ) ) {
        cout << "How many " << itemsSold[0] << "s do you want?"<< endl;
        additionalItems = itemsSold[0];
        itemPrice2 = 320.00;




    }
    else if ( (additionalItems == "B") || ( additionalItems == "b") || (additionalItems == "Phone")|| (additionalItems == "phone") || ( additionalItems == "PHONE" ) ) {
        cout << "How many " << itemsSold[1] << "s do you want?"<< endl;
        additionalItems = itemsSold[1];
        itemPrice2 = 1600.00;

    }
    else if ( (additionalItems == "C") || ( additionalItems == "c") || (additionalItems == "Table")|| (additionalItems == "table") || ( additionalItems == "TABLE" ) ) {
        cout << "How many " << itemsSold[2] << "s do you want?"<< endl;
        additionalItems = itemsSold[2];
        itemPrice2 = 60.00;

    }
    else {
        cout << "Item not available" << endl;
        return 0;
    }

        cin >> newQuantity;
        vat = 0.12 * itemPrice2;
        totalCost = (itemPrice + itemPrice2) * (quantity + newQuantity) + vat;
        break;
    }

    //what will happen if customer chooses not to add any item.
    if ( (answer == "b") || (answer == "B") ) {
        cout << "Continue to check out." <<  endl;
        newQuantity = 0;
    }

    cout <<  endl;
    cout <<"Amount to pay = GHS " <<totalCost<< " (VAT inclusive)"<< endl;
    //user making payment
    cout << "Please type amount being paid" << endl;
    cin >> amountPaid;
    cout << endl;


    if (amountPaid >= totalCost) {
        cout << "Thanks for your purchase." << endl;
    }
    else {

        do {
            cout << "Amount insufficient" << endl;
            cout << "Please enter amount being paid ( amount should be equal to or more than to GHS " <<totalCost<< " ) " << endl;
            cin >> amountPaid;
        continue;
        }

        while ( (amountPaid < totalCost ) );
    };

    cout << "....................................................." <<endl;
    totalQuantity = quantity + newQuantity;
    amountBalance = amountPaid - totalCost;


    //PRINT RECEIPT

    if (answer == "a") {
    cout <<  endl;
            //Receipt for when customer adds more items
    cout << "HERE IS YOUR RECEIPT"<< endl;
    cout << "____________________________________________________" <<endl;
    cout << "" << endl;
    cout << "Customer Name: " << customerName<< endl;
    cout << "Customer ID: " << customerId<< endl;
    cout << "////////////////" << endl;
    cout << "Items Bought"<< endl;
    cout << itemBuying << "(" <<quantity<< ")" << " - GHS " << itemPrice << endl;
    cout << additionalItems << "(" << newQuantity << ")" << " - GHS " << itemPrice2 << endl;
    cout << "////////////////" << endl;

    cout << "Vat = GHS " << vat<< endl;
    cout << "Total Cost = GHS " << totalCost <<endl;
    cout << "Total Quantity = " << totalQuantity << endl;
    cout << "Amount Paid = GHS " << amountPaid << endl;
    cout << "Balance = GHS " << amountBalance << endl;


    }
    else {

    cout <<  endl;
            //Receipt for when customer does not add more items
    cout << "HERE IS YOUR RECEIPT"<< endl;
    cout << "____________________________________________________" <<endl;
    cout <<  endl;
    cout << "Customer Name: " << customerName<< endl;
    cout << "Customer ID: " << customerId<< endl;
    cout << "Items Bought"<< endl;
    cout << "////////////////" << endl;
    cout << itemBuying << "(" <<quantity<< ")" << " - GHS " << itemPrice << endl;
    cout << "////////////////" << endl;
    cout << "Vat = GHS " << vat<< endl;
    cout << "Total Cost = GHS " << totalCost <<endl;
    cout << "Total Quantity = " << totalQuantity << endl;
    cout << "Amount Paid = GHS " << amountPaid << endl;
    cout << "Balance = GHS " << amountBalance << endl;
    };

    cout <<  endl;
    cout << "....................................................." <<endl;
    cout << "" << endl;

    cout << "Thank you for transacting with us." << endl;



    return 0;
}
