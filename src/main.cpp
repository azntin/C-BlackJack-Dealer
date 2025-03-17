#include <iostream>
#include "../header/game.h"

using namespace std;

int main(){
    cout << "Welcome to " << endl;
    cout << "██████╗ ██╗      █████╗  ██████╗██╗  ██╗     ██╗ █████╗  ██████╗██╗  ██╗" << endl;
    cout << "██╔══██╗██║     ██╔══██╗██╔════╝██║ ██╔╝     ██║██╔══██╗██╔════╝██║ ██╔╝" << endl;
    cout << "██████╔╝██║     ███████║██║     █████╔╝      ██║███████║██║     █████╔╝ " << endl;
    cout << "██╔══██╗██║     ██╔══██║██║     ██╔═██╗ ██   ██║██╔══██║██║     ██╔═██╗ " << endl;
    cout << "██████╔╝███████╗██║  ██║╚██████╗██║  ██╗╚█████╔╝██║  ██║╚██████╗██║  ██╗" << endl;
    cout << "╚═════╝ ╚══════╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝ ╚════╝ ╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝" << endl;
 
    string name;
    cout << "Enter your name: ";
    cin >> name;
    Game game(name);

    bool playGame = true;
    while(playGame){
        game.handleBet();
        if(game.getPlayerBalance() == 0) {
            cout << "You ran out of money." << endl;
            cout << "Ending game..." << endl;
            break;
        }

        cout << endl << "Play another round? (y/n): ";
        char choice = game.charInputCheck();
        while (choice != 'n' && choice != 'y') {
            cout << "Not a valid option (y/n): ";
            choice = game.charInputCheck();
        }
        if(choice == 'n'){
            playGame = false;
        }
    }

    return 0;
}







                                                                        
