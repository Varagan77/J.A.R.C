#include <conio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
//-----------------
// HEADER FUNCTIONS
//-----------------
#include "fns_note.h"
//------------------
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
// START
// ─────────────────────────────────────────────
void startPrompt() {
    string input;
    string lastMessage; // to store feedback from previous command

    while (true) {
        system("cls"); // clear console
        cout << "Enter command\n";
        cout << "Type 'back' to return.\n\n";

        if(!lastMessage.empty()) {
            cout << lastMessage << "\n\n";
            lastMessage.clear(); // reset after displaying
        }

        cout << "> ";
        getline(cin, input);

        if(input == "back") break;

        // ─────────────────────────────────────────────
        // NOTE COMMANDS
        // ─────────────────────────────────────────────
        if (input.rfind("jarc note add ", 0) == 0) {
            string name = input.substr(14); // after "jarc note add "
            if (name.empty()) {
                lastMessage = "Error: Note name required.";
            } else {
                noteAdd(name);
                lastMessage = "Note '" + name + "' has been created.";
            }
        }
        else if (input == "jarc note list") {
            system("cls");
            noteList();
            cout << "\nPress Enter to continue...";
            cin.ignore(); // wait for user
            continue;     // skip clearing message
        }
        else if (input.rfind("jarc note remove ", 0) == 0) {
            string name = input.substr(17); // after "jarc note remove "
            if (name.empty()) {
                lastMessage = "Error: Note name required.";
            } else {
                noteRemove(name);
                lastMessage = "Note '" + name + "' has been removed.";
            }
        }
        else {
            lastMessage = "Unknown command.";
        }
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

    ifstream file;
    string line;

    file.open("man.md");

    if (file.is_open()) {
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Error: Could not open manual\n";
    }

    cout << "\n";
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
