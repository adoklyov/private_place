#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <fstream>

#include "Player.h"
#include "Board.h"
#include "Button.h"

using namespace std;

enum GameState
{
    START,
    PLAYING,
    DRAW,
    OVER,
};

class Game {

public:

    //Constructor and destructor
    Game();
    ~Game();

    //Initialise the game window, renderer and game state
    bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
    //Render the game objects
    void render();
    //Update the game state and objects
    void update();
    //Processes events and user input
    void handleEvents();
    //Cleans up the game
    void clean();
    //Checks if the game is running
    bool isRunning();
    //Changes the game state
    void changeState(GameState newState);
    //Reset game
    void reset();
    //Message on win state
    void winMessage();
    //Message on draw state
    void drawMessage();
    //Message before move make
    void readyMessage();
    //Grid render
    void renderGame();
    //Ready indicator
    bool ready;
    //Info flag
    bool showRules;
    //Move made flag
    bool madeMove;
    //Board click
    void processBoardClick(int mouseX, int mouseY);
    //Check if a win is made
    bool checkWinCon();
    //Check the board click
    bool checkBoardClick(int mouseX, int mouseY);
    //Swaps player's turn
    void togglePlayerTurn();
    //Current player turn
    void currentPlayerTurn();
    //Player X score
    void playerXScore();
    //Player O score
    void playerOScore();
    //Write score in file
    void scoreboardFile(int xScore, int oScore);
    //Read from scoreboard
    void readFromScore(int& xScore, int& oScore);
    //Read from XML
    void readFromScoreFromXML(int& xScore, int& oScore);
    //Write in XML
    void writeScoreInXML(int& xScore, int& oScore);

private:

    //SDL window and renderer
    SDL_Window* gameWindow = NULL;
    SDL_Renderer* gameRenderer = NULL;
    //Win image
    SDL_Texture* winImage;
    //Info image
    SDL_Texture* infoImage;
    //X image ---------
    SDL_Texture* xImage;
    //O image ---------
    SDL_Texture* oImage;
    //Win line image
    SDL_Texture* winLineImage;
    //Background image
    SDL_Surface* surface;
    SDL_Texture* texture;
    //Start button sound
    Mix_Chunk* startButtonSound;
    //Info button sound
    Mix_Chunk* infoButtonSound;
    //Font
    TTF_Font* font;
    //Game running state
    bool running;
    //Players
    Player* xPlayer;
    Player* oPlayer;
    Player* playerTurn;
    //Board
    Board* gameBoard;
    // Board board;
    //Buttons
    Button startButton;
    Button infoButton;
    Button readyButton;
    Button undoButton;
    Button restartButton;
    //Game states
    GameState gameState;
    //X and O scores
    int xScore = 0;
    int oScore = 0;

};

#endif