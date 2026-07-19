#include "game.h"
#include <fstream>
#include <ctime>


Game::Game(Player &p1, Player &p2, bool aiMode, int level)
    : player1(p1), player2(p2)
{
    singlePlayer = aiMode;
    difficulty = level;


    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}




void Game::displayBoard()
{
    cout << "\n";

    cout << "-------------\n";

    for(int i = 0; i < 3; i++)
    {
        cout << "| ";

        for(int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " | ";
        }

        cout << "\n-------------\n";
    }
}




bool Game::makeMove(Player &player,int row,int col)
{
    if(row < 0 || row >= 3 || col < 0 || col >= 3)
        return false;


    if(board[row][col] != ' ')
        return false;


    board[row][col] = player.getSymbol();

    return true;
}





bool Game::checkWinner(Player &player)
{
    char s = player.getSymbol();


    for(int i=0;i<3;i++)
    {
        if(board[i][0]==s &&
           board[i][1]==s &&
           board[i][2]==s)
            return true;


        if(board[0][i]==s &&
           board[1][i]==s &&
           board[2][i]==s)
            return true;
    }



    if(board[0][0]==s &&
       board[1][1]==s &&
       board[2][2]==s)
        return true;



    if(board[0][2]==s &&
       board[1][1]==s &&
       board[2][0]==s)
        return true;



    return false;
}






bool Game::isDraw()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]==' ')
                return false;
        }
    }


    return true;
}







void Game::saveHistory(string result)
{
    ofstream file("game_history.txt",ios::app);


    if(file.is_open())
    {
        time_t now=time(0);


        file<<"Result: "
            <<result
            <<" | Date: "
            <<ctime(&now);


        file<<"----------------------------\n";


        file.close();
    }
}








void Game::startGame()
{
    playGame();
}









Player* Game::playGame()
{

    Player *current=&player1;



    while(true)
    {

        displayBoard();




        // COMPUTER TURN
        if(singlePlayer && current==&player2)
        {

            cout<<"Computer is thinking...\n";



            if(difficulty==1)
                AI::makeRandomMove(board);


            else if(difficulty==2)
                AI::makeMediumMove(board);


            else if(difficulty==3)
                AI::makeHardMove(board);






            if(checkWinner(player2))
            {

                displayBoard();

                cout<<"Computer wins!\n";


                player2.addWin();
                player1.addLoss();



                saveHistory("Computer won");


                player1.saveProfile();



                return &player2;
            }






            if(isDraw())
            {

                displayBoard();

                cout<<"Match Draw!\n";


                player1.addDraw();



                saveHistory("Match Draw");


                player1.saveProfile();



                return nullptr;
            }





            current=&player1;

            continue;
        }







       int row,col;



cout << current->getName()
     << " enter row and column (1-3) or 0 to quit: ";



cin >> row;



// Player wants to quit
if(row == 0)
{
    cout << current->getName()
         << " quit the match!\n";



    if(current == &player1)
    {
        player2.addWin();
        player1.addLoss();


        player1.saveProfile();
        player2.saveProfile();


        return &player2;
    }

    else
    {
        player1.addWin();
        player2.addLoss();


        player1.saveProfile();
        player2.saveProfile();


        return &player1;
    }
}



cin >> col;



row--;
col--;






        if(makeMove(*current,row,col))
        {


            if(checkWinner(*current))
            {

                displayBoard();


                cout<<current->getName()
                    <<" wins!\n";



                current->addWin();



                if(current==&player1)
                    player2.addLoss();





                saveHistory(current->getName()+" won");






                if(singlePlayer)
                {
                    player1.saveProfile();
                }

                else
                {
                    player1.saveProfile();
                    player2.saveProfile();
                }





                player1.showStats();
                player2.showStats();



                return current;
            }







            if(isDraw())
            {

                displayBoard();


                cout<<"Match Draw!\n";



                player1.addDraw();
                player2.addDraw();



                saveHistory("Match Draw");




                if(singlePlayer)
                {
                    player1.saveProfile();
                }
                else
                {
                    player1.saveProfile();
                    player2.saveProfile();
                }



                return nullptr;
            }






            if(current==&player1)
                current=&player2;

            else
                current=&player1;

        }


        else
        {
            cout<<"Invalid move! Try again.\n";
        }

    }

}