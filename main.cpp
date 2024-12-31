#include <iostream>
#include <vector>
#include <string>
#include <Windows.h> 
#include <chrono>
#include <conio.h>
#include <thread>
#include "DatabaseHandler.h"
//#include"Hashing.h"
#include"menu.h"
using namespace std;


void printLoadingScreen(const vector<string>& pattern) {
    for (const auto& line : pattern) {
        cout << line << endl;
        int randomTime = 50 + (rand() % 200);
        this_thread::sleep_for(chrono::milliseconds(randomTime));
    }
}

vector<string> StartingLoadingScreen = {
      "****************************************************************************************************************************************************************************************************************",
      "****************************************************************************************************************************************************************************************************************",
      "****************************************************************************************************************************************************************************************************************",
      "****************************************************************************************************************************************************************************************************************",
      "****************************************************************************************************************************************************************************************************************",
      "****************************************************************************************************************************************************************************************************************",
      "****************************************************************************************************************************************************************************************************************",
      "**********        ********         ******          *******            ******************************************************************************************************************************************",
      "*********    ****   *****    ****    ****   *****    ****    ***************************************************************************************************************************************************",
      "*********   ******   ****   ******   ****   ******   ****   ****************************************************************************************************************************************************",
      "*********   *************   ******   ****   ******   ****    ***************************************************************************************************************************************************",
      "*********   *************   ******   ****   ******   ****            *******************************************************************************************************************************************",
      "*********   *************   ******   ****   ******   ****    ***************************************************************************************************************************************************",
      "*********   ******   ****   ******   ****   ******   ****   ****************************************************************************************************************************************************",
      "*********    *****   ****    *****   ****   *****    ****    ***************************************************************************************************************************************************",
      "**********         *******         ******          *******            ******************************************************************************************************************************************",
      "****************************************************************************************************************************************************************************************************************",
      "****************************************************************************************************************************************************************************************************************",
      "****************************************************************************************************************************************************************************************************************",
      "****************************************************************************************************************************************************************************************************************",
      "******************************************        ********         ******          ******     ******   ****   ****  **********  *****         ******   *********************************************************",
      "*****************************************    ****   *****    ****    ****   *****    ****      *****   ****   ****   ********   ****    ****    ****   *********************************************************",
      "*****************************************   ******   ****   ******   ****   ******   ****   *   ****   ****   ****    ******   *****   ******   ****   *********************************************************",
      "*****************************************   *************   ******   ****   *****    ****   **   ***   ****   *****   ******   *****   ******   ****   *********************************************************",
      "*****************************************   *************            ****            ****   ***   **   ****   *****    ****   ******            ****   *********************************************************",
      "*****************************************   *************   ******   ****   **     ******   *****  *   ****   ******   ****   ******   ******   ****   *********************************************************",
      "*****************************************   ******   ****   ******   ****   ***    ******   *****      ****   *******   **   *******   ******   ****   *********************************************************",
      "*****************************************    *****   ****   ******   ****   ****     ****   ******     ****   ********  ** *********   ******   ****    ********************************************************",
      "******************************************         ******   ******   ****   ******    ***   *******    ****   *********    *********   ******   ****            ************************************************",
      "****************************************************************************************************************************************************************************************************************",
      "****************************************************************************************************************************************************************************************************************",
      "****************************************************************************************************************************************************************************************************************",
      "****************************************************************************************************************************************************************************************************************",
      "****************************************************************************************************************************************************************************************************************",
      "****************************************************************************************************************************************************************************************************************",
      "****************************************************************************************************************************************************************************************************************",

};

bool isNumber(char& c) {
    return ((c == '0') || (c == '1') || (c == '2') || (c == '3')
        || (c == '4') || (c == '5') || (c == '6') || (c == '7')
        || (c == '8') || (c == '9'));
}

char check(const string& s) {
    for (char i : s) {
        if (i != ' ' && i != '0') {
            return i;
        }
    }
    return '\0';
}



void login() {
    system("CLS");
    cout << R"(

         ----------------------------------------------------
        |          _        ____   _____   _  _   _          |
        |         | |      / __ \ |  ___\ | || \ | |         |
        |         | |     | |  | || |   _ | ||  \| |         |
        |         | |     | |  | || | |_ || || . ` |         |
        |         | |____ | |__| || |__| || || |\  |         |
        |         |______| \____/  \_____||_||_| \_|         |
        |                                                    |
         ----------------------------------------------------

                        
    )";
    cout << "\n         +--------------------------------------------------+"
        << "\n                                                   "
        << "\n          Enter username: ";
    string username;
    cin >> username;
    char password[100];
    int i = 0;

    cout << "          Enter password: ";

    while (true) {
        char ch = _getch();  // Get a character without displaying it
        if (ch == 13) {  // 13 is ASCII for Enter key
            password[i] = '\0';  // Null-terminate the string
            break;
        }
        else if (ch == 8) {  // 8 is ASCII for Backspace key
            if (i > 0) {
                i--;
                std::cout << "\b \b";  // Erase last asterisk
            }
        }
        else {
            password[i] = ch;
            cout << "*";  // Print an asterisk for each character
            i++;
        }
    }

    cout << "\n                                                  "
        << "\n         +--------------------------------------------------+";

    DBHandler db;

    Hashing h;



    if (db.validateUser(username, password)) {
        std::cout << "\n User validated successfully!" << std::endl;
        cout << "\n Press any Key To Continue..";
        _getch();
        displayPlayerMenu(username);
    }
    else {
        std::cout << "\n Invalid username or password." << std::endl;

        cout << "\n Press any Key To Continue..";
        _getch();

        return;
    }

}

void Register() {
    system("CLS");
    cout << R"(

                --------------------------------------------------------------------
                |   _____   ______   _____   ___    _____  _______  ______  _____   | 
                |  |  __ \ |  ____| / ____| |_ _|  / ____||__   __||  ____||  __ \  | 
                |  | |__) || |__   | |  __   | |  | (___     | |   | |__   | |__)   |
                |  |  _  / |  __|  | | |_ |  | |   \___ \    | |   |  __|  |  _  /  |
                |  | | \ \ | |____ | |__| |  | |   ____) |   | |   | |____ | | \ \  |
                |  |_|  \_\|______| \_____| |___| |_____/    |_|   |______||_|  \_\ | 
                 ------------------------------------------------------------------




                        
    )";

    /*newuser*/


    cout << "\n                        +--------------------------------------------------+"
        << "\n                                                   "
        << "\n                                 Enter username: ";
    string username;
    cin >> username;

    char password[100];
    int i = 0;

    cout << "\n \n                                 Enter password: ";

    while (true) {
        char ch = _getch();  // Get a character without displaying it
        if (ch == 13) {  // 13 is ASCII for Enter key
            password[i] = '\0';  // Null-terminate the string
            break;
        }
        else if (ch == 8) {  // 8 is ASCII for Backspace key
            if (i > 0) {
                i--;
                std::cout << "\b \b";  // Erase last asterisk
            }
        }
        else {
            password[i] = ch;
            cout << "*";  // Print an asterisk for each character
            i++;
        }
    }
    cout << "\n ";


    cout << "\n "
        << "\n                                 Enter email Address : ";
    string emailAddress;
    cin >> emailAddress;
    cout << "\n                          +--------------------------------------------------+";
    DBHandler db;
    db.connect();



    if (!db.addUser(username, emailAddress, password)) {
        system("CLS");
        cout << "\n !!username already exist!!";
    }
    cout << "\n Press any Key To Continue..";
    _getch();
}

void loginRegPage() {
    if (true) {
        system("CLS");
    }
    cout << "\n +--------------------------------------------------+"
        << "\n |                                                  |"
        << "\n |  1. LOGIN (ALREADY HAVE AN ACCOUNT)              |"
        << "\n |                                                  |"
        << "\n +--------------------------------------------------+"
        << endl << endl
        << "\n +--------------------------------------------------+"
        << "\n |                                                  |"
        << "\n |  2. REGISTER (DONT  HAVE AN ACCOUNT)             |"
        << "\n |                                                  |"
        << "\n +--------------------------------------------------+"
        << endl << endl;
    string input;
    cout << "\n << ";


    getline(cin, input);

    if (check(input) == '1') {
        system("CLS");
        login();
    }
    else if (check(input) == '2') {
        system("CLS");
        Register();

    }
    else
        cout << "\n Invalid Input!";
}

int main() {

    printLoadingScreen(StartingLoadingScreen);

    cout << "\n Press any Key To Continue..";
    _getch();

    while (1) {
        (loginRegPage());
    }


    return 0;
}