#include <iostream>
using namespace std;

struct UserData{
    private:
        const string Name = "Twenewaa Adelaide";
        const string PhoneNumber = "0546561454";
        string Pin = "0000";
        long int Balance = 1000;
    public:
        string get_pin(){return Pin;}
        long int get_balance(){return Balance;}
        string set_pin(string new_pin){Pin = new_pin;}
        void reset_pin(){Pin = "0000";}
        void print_balance(){cout << "Your balance is GHC"<< Balance << endl;}
};
UserData newUser;

bool authenticate(){
    int tries = 0;
    string response;
    while (tries < 3){
        cout << "Enter Pin" << endl;
        cout << ">";
        cin >> response;
        if (response == newUser.get_pin()){
            return true;
        } else {
            cout << "Incorrect pin" << endl;
            tries += 1;
        }
    }
    return false;
}
void sendMoney(){
    long int waste;
    cout << "Enter recipient's number:";
    cin >> waste;
    cout << "Enter amount:";
    cin >> waste;
    if (waste > newUser.get_balance()){
        cout << "You balance isn't enough" << endl;
        return;
    }
    if (!authenticate()){
        cout << "Authentication Failed" << endl;
        return;
    }
    cout << "Your money has been successfully sent!" << endl;

}
void changePin(){
    string newPin = "";
    cout << "Enter new Pin:";
    cin >> newPin;
    newUser.set_pin(newPin);
}

int main(){
    int response;
    if (!authenticate()){
        cout << "Authentication Failed";
        return 0;
    }
    while (true){
            cout << " 1. Send money\n 2. Change Pin\n 3. Reset Pin \n 4. Check balance\n 5. Exit" << endl;
            cout << ">";
            cin >> response;
            switch (response){
                case 1: sendMoney(); break;
                case 2: changePin(); break;
                case 3: newUser.reset_pin(); break;
                case 4: newUser.print_balance(); break;
                case 5: return 0;
                default: cout << "Invalid input" << endl;
            }

    }
    return 0;
}
