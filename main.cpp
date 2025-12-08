#include <conio.h>
#include <iostream>
#include <vector>

using namespace std;

#define KEY_UP    72
#define KEY_DOWN  80
#define ENTER_KEY 13

// ─────────────────────────────────────────────
// MENU PRINT
// ─────────────────────────────────────────────
void printMenu(const vector<string>& menu, int selected) {
    system("cls");

    cout << R"(
    /$$$$$     /$$$$$$      /$$$$$$$       /$$$$$$
   |__  $$    /$$__  $$    | $$__  $$     /$$__  $$
      | $$   | $$  \ $$    | $$  \ $$    | $$  \__/
      | $$   | $$$$$$$$    | $$$$$$$/    | $$
 /$$  | $$   | $$__  $$    | $$__  $$    | $$
| $$  | $$   | $$  | $$    | $$  \ $$    | $$    $$
|  $$$$$$//$$| $$  | $$ /$$| $$  | $$ /$$|  $$$$$$/
 \______/|__/|__/  |__/|__/|__/  |__/|__/ \______/

  Created by Varagan77
)" << '\n';

    for(int i = 0; i < menu.size(); i++)
        if(i == selected) cout << " > " << menu[i] << " <\n";
        else              cout << "   " << menu[i] << '\n';
}


// ─────────────────────────────────────────────
// START SECTION — where commands are run
// ─────────────────────────────────────────────
void startPrompt() {
    system("cls");
    cout << "Enter command (example: jarc time london)\n";
    cout << "Type 'back' to return.\n\n";

    string input;
    while(true) {
        cout << "> ";
        getline(cin, input);

        if(input == "back") break;

        // Example command handling
        if(input == "jarc time london") cout << "London time is X:XX\n";
        else cout << "Unknown command.\n";
    }
}


// ─────────────────────────────────────────────
// OPTIONS SECTION — colour/theme later
// ─────────────────────────────────────────────
void settingsMenu() {
    system("cls");
    cout << "Settings / Themes Area\n";
    cout << "(Not implemented yet)\n";
    system("pause");
}


// ─────────────────────────────────────────────
// MANUAL SECTION — documentation
// ─────────────────────────────────────────────
void manualMenu() {
    system("cls");
    cout << "===== MANUAL =====\n";
    cout << "jarc time <region>   - prints the time\n";
    cout << "(More command docs soon)\n\n";
    system("pause");
}


// ─────────────────────────────────────────────
// INFO SECTION
// ─────────────────────────────────────────────
void infoMenu() {
    system("cls");
    cout << "CLI Tool Framework by Varagan77\n";
    cout << "Use START to input commands.\n\n";
    system("pause");
}


// ─────────────────────────────────────────────
// MAIN LOOP
// ─────────────────────────────────────────────
int main() {
    vector<string> menuItems = {"START","OPTIONS","MANUAL","INFO","EXIT"};
    int selected = 0;

    while(true) {
        printMenu(menuItems, selected);
        int key = getch();

        if(key == KEY_UP)    selected = (selected - 1 + menuItems.size()) % menuItems.size();
        if(key == KEY_DOWN)  selected = (selected + 1) % menuItems.size();

        if(key == ENTER_KEY) {
            switch(selected) {
                case 0: startPrompt();   break;
                case 1: settingsMenu();  break;
                case 2: manualMenu();    break;
                case 3: infoMenu();      break;
                case 4: return 0;
            }
        }
    }
}
