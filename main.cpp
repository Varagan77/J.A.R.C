#include <conio.h>      // i want to use getch so i include this
#include <iostream>     // i need cout so yeah i gotta include this too
#include <vector>       // using a vector feels easier than dealing with arrays
using namespace std;    // im too lazy to type std:: every time

#define KEY_UP    72     // this number means up arrow
#define KEY_DOWN  80     // this one means down arrow
#define ENTER_KEY 13     // enter key is important so i wrote it here

void printMenu(const vector<string>& menu, int selected) {

    system("cls"); // this wipes the screen so everything doesnt pile up into chaos

    // this is just the banner because empty screens are boring
    cout << R"(
    /$$$$$     /$$$$$$      /$$$$$$$       /$$$$$$
   |__  $$    /$$__  $$    | $$__  $$     /$$__  $$
      | $$   | $$  \ $$    | $$  \ $$    | $$  \__/
      | $$   | $$$$$$$$    | $$$$$$$/    | $$
 /$$  | $$   | $$__  $$    | $$__  $$    | $$
| $$  | $$   | $$  | $$    | $$  \ $$    | $$    $$
|  $$$$$$//$$| $$  | $$ /$$| $$  | $$ /$$|  $$$$$$/
 \______/|__/|__/  |__/|__/|__/  |__/|__/ \______/

Created by Varagan77 > https://github.com/Varagan77

)" << '\n';

    // now we loop through all menu options
    for(int i = 0; i < menu.size(); i++) {

        // if this one is the selected one we show it special so you know where you are
        if(i == selected)
            cout << " > " << menu[i] << " <" << endl;   // this one is highlighted
        else
            cout << "   " << menu[i] << endl;           // this one is not highlighted
    }
}

int main() {

    // options to choose from
    vector<string> menuItems = {
        "START",
        "OPTIONS",
        "MANUAL",
        "INFO",
        "EXIT"
    };

    int selected = 0;

    // this loop is just gonna sit here and watch for key presses forever
    while(true) {

        printMenu(menuItems, selected); // redraw the menu every time something changes

        int key = getch(); // get a key instantly without pressing enter

        // if the user presses up we move up in the list
        if(key == KEY_UP) {
            selected = (selected - 1 + menuItems.size()) % menuItems.size(); // wrap around so it never breaks
        }
        // if the user presses down we move down
        else if(key == KEY_DOWN) {
            selected = (selected + 1) % menuItems.size(); // again we wrap so it loops nicely
        }
        // and if the user presses enter then we stop and show what they chose
        else if(key == ENTER_KEY) {
            system("cls"); // clear the screen so it looks neat
            cout << "you selected: " << menuItems[selected] << endl; // tell them what they picked
            break; // end the loop because the choice has been made
        }
    }

    return 0;
}
