// Macy So
// Finite_State_Machines


#include <iostream>
#include <string>

using namespace std;

enum VendingMachinesState{
    SELECT, QUANTITY, CALCULATE, UPDATE
};

enum Brand{
    COKE = 100,PEPSI = 200,SEVENUP = 300
};

struct Student{
    string name;
    int points;
};

struct Soda{
    Brand brandName;
    int inventory;
    int price;
};

int main() {

    // Initial Vending Machine State is SELECT, Update upon state change.
    VendingMachinesState currentState = SELECT;
    
    //Fill up our vending machine with Soda
    Soda VendingMachine[3];
    //Load up with COKE
    VendingMachine[0].brandName = COKE;
    VendingMachine[0].inventory = 10;
    VendingMachine[0].price = 1000;
    //Load up with PEPSI
    VendingMachine[1].brandName = PEPSI;
    VendingMachine[1].inventory = 10;
    VendingMachine[1].price = 2000;
    //Load up with SEVENUP
    VendingMachine[2].brandName = SEVENUP;
    VendingMachine[2].inventory = 10;
    VendingMachine[2].price = 3000;
    
    Soda selectSoda;
    Student eric;
    eric.name = "Eric";
    eric.points = 100000; // 100,000 Points in Wallet
    
    switch (currentState) {
        case SELECT:
            // 1. Display the current status for the vending machine & the student wallet
            cout << "<<<<<--- CURRENT STATUS --->>>>>" << endl ;
            cout << "[[[Vending Machine]]]" << endl ;
            for (int i = 0; i < 3; i++){
                cout << VendingMachine[i].brandName << " has " << VendingMachine[i].inventory << " drinks, and each costs " << VendingMachine[i].price << endl;
            }
            cout << "[[[Student]]]" << endl ;
            cout << eric.name << " has " << eric.points << " points total." << endl ;
            cout << "<<<<<<--- END STATUS --->>>>>" << endl << endl ;
            
            // 2. Ask the user what drink they wane
            cout << "Please select a drink from the following available options: " << endl ;
            
            // 3. Display the soda name & corresponding ID values
            cout << "COKE = 100\nPEPSI = 200 \nSEVENUP = 300" << endl ;
        
            // 4. User Input the drink
            int selectedDrink;
            cin >> selectedDrink;
            
            // 5. If valid drink select, move to QUANTITY state, else, go back to SELECT state
            switch (selectedDrink) {
                case COKE:
                    cout << "You have selected COKE" << endl;
                    selectSoda.brandName = COKE;
                    currentState = QUANTITY;
                    break;
                case PEPSI:
                    cout << "You have selected PEPSI" << endl;
                    selectSoda.brandName = PEPSI;
                    currentState = QUANTITY;
                    break;
                case SEVENUP:
                    cout << "You have selected SEVENUP" << endl;
                    selectSoda.brandName = SEVENUP;
                    currentState = QUANTITY;
                    break;
                default:
                    cout << "Invalid Drink Selected!" << endl ;
                    currentState = SELECT;
                    break;
            }
            break;
        /*case QUANTITY:
            <#statements#>
            break;
        case CALCULATE:
            statements
            break;
        case UPDATE:
            <#statements#>
            break;*/
        default:
            cout << "Error! Invalid Statement" << endl ;
            break;
    }
    
    return 0;
}
