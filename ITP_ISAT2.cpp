//162514274
//Matthyse C
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Array size setup
    const int MAX_ORDERS = 50;
    
    // Parallel arrays to store order data
    string orderIDs[MAX_ORDERS];
    string customerNames[MAX_ORDERS];
    int magwinyasOrdered[MAX_ORDERS];
    float totalCosts[MAX_ORDERS];
    
    // Track number of active orders
    int orderCount = 10;

    //initial 10 orders
    orderIDs[0] = "101"; customerNames[0] = "Thabo";    magwinyasOrdered[0] = 3; totalCosts[0] = 15.75;
    orderIDs[1] = "102"; customerNames[1] = "Lerato";   magwinyasOrdered[1] = 5; totalCosts[1] = 30.50;
    orderIDs[2] = "103"; customerNames[2] = "Nomvula";  magwinyasOrdered[2] = 2; totalCosts[2] = 10.00;
    orderIDs[3] = "104"; customerNames[3] = "Sipho";    magwinyasOrdered[3] = 4; totalCosts[3] = 22.00;
    orderIDs[4] = "105"; customerNames[4] = "Bongani";  magwinyasOrdered[4] = 6; totalCosts[4] = 40.25;
    orderIDs[5] = "106"; customerNames[5] = "Lindiwe";  magwinyasOrdered[5] = 1; totalCosts[5] = 5.50;
    orderIDs[6] = "107"; customerNames[6] = "Jabulani"; magwinyasOrdered[6] = 3; totalCosts[6] = 18.00;
    orderIDs[7] = "108"; customerNames[7] = "Ayanda";   magwinyasOrdered[7] = 2; totalCosts[7] = 12.75;
    orderIDs[8] = "109"; customerNames[8] = "Kgosi";    magwinyasOrdered[8] = 6; totalCosts[8] = 28.00;
    orderIDs[9] = "110"; customerNames[9] = "Refilwe";  magwinyasOrdered[9] = 4; totalCosts[9] = 24.50;

    // Initialize the remaining elements with "0" or 0
    for (int i = 10; i < MAX_ORDERS; i++) {
        orderIDs[i] = "0";
        customerNames[i] = "";
        magwinyasOrdered[i] = 0;
        totalCosts[i] = 0.0;
    }

    int choice = 0;

    while (choice != 5) {
        // Menu 
        cout << "Order Management System" << endl;
        cout << "1. Add a new order" << endl;
        cout << "2. Display all orders" << endl;
        cout << "3. Find an order by Order ID" << endl;
        cout << "4. Calculate total revenue" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        if (choice == 1) {
            if (orderCount < MAX_ORDERS) {
                cout << "Enter Order ID: ";
                cin >> orderIDs[orderCount];
                cout << "Enter Customer Name: ";
                cin >> customerNames[orderCount];
                cout << "Enter Number of Magwinyas Ordered: ";
                cin >> magwinyasOrdered[orderCount];
                cout << "Enter Total Cost: ";
                cin >> totalCosts[orderCount];

                orderCount++;
                cout << "Order added successfully!" << endl;
            } else {
                cout << "Order limit reached!" << endl;
            }
        } 
        else if (choice == 2) {
            if (orderCount == 0) {
                cout << "No orders to display." << endl;
            } else {
                cout << "All Orders:" << endl;
                for (int i = 0; i < orderCount; i++) {
                    cout << "Order ID: " << orderIDs[i] 
                         << ", Customer: " << customerNames[i] 
                         << ", Number of Magwinyas: " << magwinyasOrdered[i] 
                         << ", Total: " << totalCosts[i] << endl;
                }
            }
        } 
        else if (choice == 3) {
            string searchID;
            cout << "Enter Order ID to find: ";
            cin >> searchID;

            bool found = false;
            for (int i = 0; i < orderCount; i++) {
                if (orderIDs[i] == searchID) {
                    cout << "Order ID: " << orderIDs[i] 
                         << ", Customer: " << customerNames[i] 
                         << ", Number of Magwinyas: " << magwinyasOrdered[i] 
                         << ", Total: " << totalCosts[i] << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Order with Order ID " << searchID << " not found." << endl;
            }
        } 
        else if (choice == 4) {
            float totalRevenue = 0.0;
            for (int i = 0; i < orderCount; i++) {
                totalRevenue += totalCosts[i];
            }
            cout << "Total Revenue: " << totalRevenue << endl;
        } 
        else if (choice == 5) {
            // Exit loop
        } 
        else {
            cout << "Invalid option!" << endl;
        }
    }

    return 0;
}