
using namespace std;

#include "screen.h"

Screen::Screen(int width, int height) {
    screenWidth = width;
    screenHeight = height;

    // Initialize 2D array of characters
    screenContent = new char*[screenWidth];

    for (int i=0; i < width; i++) {
        screenContent[i] = new char[height];
    }

    // Fill everything but edges with empty space
    for (int i=1; i < width-1; i++) {
        for (int j=1; j < height-1; j++) {
            screenContent[i][j] = ' ';
        }
    }

    // Fill edges with '#'
    for (int i=0; i < screenHeight; i++) {
        screenContent[0][i] = '#';
        screenContent[screenWidth-1][i] = '#';
    }

    for (int i=1; i < screenWidth; i++) {
        screenContent[i][0] = '#';
        screenContent[i][screenHeight-1] = '#';
    }

}

Screen::~Screen() {
    for (int i=0; i<screenWidth; i++) {
        delete[] screenContent[i];
    }
    delete screenContent;
}

void Screen::renderScreen() {
    clearScreen();

    string output = "";
    for (int i = 0; i < screenHeight; i++) {
        for (int j = 0; j < screenWidth; j++) {
            output += screenContent[j][i];
        }
        output += "\n";
    }
    cout << output;
}

void Screen::clearScreen() {
    cout << string(screenHeight, '\n');
}

TitleScreen::TitleScreen(int width, int height) : Screen(width, height) {

    string titleString = "Welkom to Command Line D&D";
    string instructionString = "Please resize your window to fit the application";
    string continueString = "Press Enter to continue.";
    
    updateScreenContent();
}

void TitleScreen::updateScreenContent() {
    screenState = (screenState + 1) % 2;

    screenContent[screenWidth / 2 - 1][screenHeight / 2 - 1] = loadingIconCharacters[screenState];
    screenContent[screenWidth / 2][screenHeight / 2]         = loadingIconCharacters[screenState];
    screenContent[screenWidth / 2][screenHeight / 2 - 1]     = loadingIconCharacters[(screenState + 1) % 2];
    screenContent[screenWidth / 2 - 1][screenHeight / 2]     = loadingIconCharacters[(screenState + 1) % 2];

}