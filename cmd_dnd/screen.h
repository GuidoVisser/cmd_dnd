#pragma once

#include <string>
#include <iostream>

class Board;
class CreatureInfoPanel;
class ActionMenu;

using namespace std;

struct Screen {
    Screen() = delete;
    Screen(int width, int height);
    ~Screen();

    void renderScreen();
    virtual void updateScreenContent() = 0;

protected:
    int screenWidth;
    int screenHeight;

    char** screenContent;
private:
    void clearScreen();
};

struct TitleScreen : public Screen {
    TitleScreen() = delete;
    TitleScreen(int width, int height);

    void updateScreenContent();
private:
    int screenState = 0;
    char loadingIconCharacters[2] = {'/', '\\'};
};

// struct CombatScreen : public Screen {
//     CombatScreen() = delete;
//     CombatScreen(int width, 
//                  int height, 
//                  Board* board, 
//                  CreatureInfoPanel* creatureInfoPanel, 
//                  ActionMenu* actionMenu);

//     void updateScreenContent();
// };