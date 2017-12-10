
#include "Client.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    Board * b = new Board();
    Player * p1 = new RemotePlayer("127.0.0.1",8001);
    try{
        p1.connectToServer();
    } catch(const char *msg) {
        cout << "Failed to connect to server .reason- " << msg << endl;
    }
    Player * p2;
    /*
    char player;
    cout << "Choose Player 2: H for Human and c for Computer";
    cin >> player;
    if(player == 'c'){
        p2 = new AIPlayer('O');
    } else {
        p2 = new HumanConsolePlayer('O');
    }
    */


    int c = p1.readSign(); // getting number of the player
    char op = 'O';
    if (c == O) {
        op = 'X';
    }
    p2 = new VirtualPlayer(op);
    GameRules * rules = new BasicGameRules();
    GamePlay * game = new GamePlay(rules , b , p1 , p2);
    if (c == O) {
        game.swapPlayers(p1 , p2);
    }
    game->playGame();

    /*
    while(true){
        cout << "choose play" << endl;
        cin >>num1 >> num2;
        try {
            client.sendMove(num1,op,num2);
        } catch (const char *msg){
            cout << "Failed to send move. reason- " << msg << endl;
        }
       client.readMove();
    }
    */
    delete p1;
    delete p2;
    delete rules;
    delete b;
    delete game;
    return 0;
}