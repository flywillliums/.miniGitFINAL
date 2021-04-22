#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    // miniGit *MG;
    bool quit = false;
    bool initialized = false;
    string s_input;

    // loop until the user quits
    while (!quit)
    {
        int menuInput;
        string inputLine;

        cout << "======Main Menu======" << endl;
        cout << "1. Init Repo" << endl;
        cout << "2. Add file" << endl;
        cout << "3. Remove file" << endl;
        cout << "4. Commit" << endl;
        cout << "5. Quit" << endl;

        getline(cin, inputLine);

        menuInput = stoi(inputLine);

        switch (menuInput)
        {
        case 1:
            if (!initialized)
            {
                initialized = true;
                // MG = new miniGit();
                // MG->init();
            }
            cout << "you selected 1" << endl;
            break;
        case 2:
            // call addFile() function
            if (!initialized)
            {
                cout << "You must initialize a repository before adding files." << endl;
            }
            cout << "you selected 2" << endl;
            break;
        case 3:
            // call rmFile() function
            if (!initialized)
            {
                cout << "You must initialize a repository before removing files." << endl;
            }
            cout << "you selected 3" << endl;
            break;
        case 4:
            // call the commit() function
            if (!initialized)
            {
                cout << "You must initialize a repository before making commits." << endl;
            }
            cout << "you selected 4" << endl;
            break;
        case 5:
            // quit the program
            cout << "you selected quit" << endl;
            quit = true;
            break;

        default:
            cout << "try again" << endl;
            break;
        }
    }
}