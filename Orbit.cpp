#include <iostream>
#include <string>
#include <fstream>
// #include "Icon.rc" // Still commented out for compatibility with GitHub Codespaces Linux environment.
using namespace std;

// Function prototype for menu() so main() knows about it
void menu();

void menu() {
    string choice;
    cout << "\nWelcome to Orbit!\n";
    cout << "Here are 2 Options:\n";
    cout << "1. Create and edit a File\n";
    cout << "2. Create a batch script for it to turn off the laptop without more then 1 click\n";
    cout << "Type 'exit' to quit the program.\n";
    cin >> choice;

    if (choice == "1") {
        string filename, content;
        cout << "Enter the filename: ";
        cin >> filename;
        cin.ignore(); // to ignore the newline character after filename input
        cout << "Enter the content (end with a single line containing only 'END'):\n";
        ofstream file(filename);
        if (file.is_open()) {
            while (true) {
                getline(cin, content);
                if (content == "END") break;
                file << content << endl;
            }
            file.close();
            cout << "File '" << filename << "' created successfully.\n";
        } else {
            cout << "Error opening file!\n";
        }
    } else if (choice == "2") {
        string scriptName;
        cout << "Enter the name for the batch script (e.g., shutdown.bat): ";
        cin >> scriptName;
        ofstream script(scriptName);
        if (script.is_open()) {
            script << "@echo off\n";
            script << "shutdown /s /t 0\n";
            script.close();
            cout << "Batch script '" << scriptName << "' created successfully.\n";
        } else {
            cout << "Error creating script file!\n";
        }
    } else if (choice == "exit") {
        cout << "Goodbye! Thanks for using Orbit!\n";
        exit(0); // Exits the program entirely
    }
    else {
        cout << "Invalid choice. Please select 1, 2, or type 'exit'.\n";
    }
    
    // Call menu again to loop the program until 'exit' is chosen
    menu();
}

int main() {
    // The main function just starts the loop
    menu();
    return 0; // This line is technically never reached because menu() calls exit(0)
}
