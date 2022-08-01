#include "GameEngine.h"

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_mixer.h>
#include <fstream>

using namespace std;
// set up the SDL
void SetUpSDL() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) { // init everything from sdl
        cout << "Error: " << SDL_GetError() << endl;
    } // open audio to make sure it output from the speaker
    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024) < 0) { 
        cout << "Unable to open audio!" << endl;
        exit(1);
    }
    Mix_VolumeMusic(MIX_MAX_VOLUME / 4);
}

// set up the player class
Player SetUpPlayer() {
    string name;
    cout << "Enter your name to get started: "; getline(cin, name);
    while (name == "" || name == " ") {
        cout << "\nThe name cannot be empty: "; getline(cin, name);
    }
    
    Player player("001", name, 1.0, 1.0);

    for (int i = 0; i < 10; i++) {
        player.setSlot(i, new BaseItem());
    }
    return player;
}

// set up the game engine 
GameEngine SetUpGameEngine() {
    // insert item database
    GameEngine game;
    AVLTree<Item*> ItemDB;
    Item* item[] = { 
        new BaseItem("wheat", "Wheat"),
        new BaseItem("wood", "Wood"),
        new BaseItem("wooden_plank", "WoodenPlank"),
        new BaseItem("stick", "Stick"),
        new BaseItem("tree_leave", "TreeLeave"),
        new BaseItem("wool", "Wool"),
        new BaseItem("raw_beef", "RawBeef"),
        new BaseItem("beef", "Beef"),
        new BaseItem("raw_mutton", "RawMutton"),
        new BaseItem("mutton", "Mutton"),
        new BaseItem("raw_porkchop", "RawPorkchop"),
        new BaseItem("porkchop", "Porkchop"),
        new BaseItem("sword","Sword"),
        new BaseItem("pickaxe","Pickaxe"),
        new BaseItem("axe","Axe"),
    };

    for (int i = 0; i < 15; i++) {
        ItemDB.fRoot = ItemDB.insert(ItemDB.fRoot, item[i]);
    }
    game.setItemDatabase(ItemDB);

    // Insert the list of commands
    LinkedList<string> CL;
    CL.appendtail("/Collect <ItemID> <ItemName>");
    CL.appendtail("/Craft <ItemName>");
    CL.appendtail("/Drop <ItemID> <ItemName>");
    CL.appendtail("/Enchance <ItemID> <ItemName> Sharpening");
    CL.appendtail("/Enchance <ItemID> <ItemName> Toughness");
    CL.appendtail("/Enchance <ItemID> <ItemName> Flame");
    CL.appendtail("/Feed <CreatureName> <ItemID> <ItemName>");
    CL.appendtail("/Goto <LocationName>");
    CL.appendtail("/Help");
    CL.appendtail("/Show Creature");
    CL.appendtail("/Show Map");
    CL.appendtail("/Show ItemList");
    CL.appendtail("/Quit");
    CL.appendtail("/Travel");
    game.setCommandList(CL);

    // set up the gamemap
    DoublyLinkedList<string> GM = game.getGameMap();
    int index = rand() % 5;
    GM.appendtail(game.getLocations(index));
    game.setLocation(game.getLocations(index));
    game.setGameMap(GM);

    return game; // return the gameengine
}

int main(int argc, char *argv[]) {
    string str, temp; // Declare str and temp
    Player p; // Declare a player
    GameEngine game; // Declare a Game Engine
    ifstream inFile; // Declare an input file stream
    game = SetUpGameEngine(); // Set up game engine
    SetUpSDL(); // Set up SDL library
    
    // play music 
    Mix_Music* music = Mix_LoadMUS("Music/Frolic.mp3");
    Mix_PlayMusic(music, -1);
    while (Mix_PlayMusic(music, -1) != -1) {
        Mix_PlayMusic(music, -1);
        break;
    }

    game.TitleScreen(); // Print the title screen
    p = SetUpPlayer(); // Set up player (include insert player name and set up player inventory)
    cout << "Do you want to skip the movie? [yes/no]: "; getline(cin, temp);

    Mix_HaltMusic();
    music = Mix_LoadMUS("Music/Gamela.mp3");
    Mix_PlayMusic(music, -1);

    system("CLS"); // Clear the console
    if (temp == "no") {
        inFile.open("Save File/fInput.txt"); // Open the txt file

        // Check whether it can access the file
        if (!inFile) {
            cout << "Unable to open fInput.txt" << endl;
            exit(1);   // end the program
        }
        // Get the string from the file
        while (getline(inFile, str)) {
            game.KeyboardEffect(str); cout << "" << endl;// Output the string
            SDL_Delay(800); // Delay
        }
        inFile.close(); // Close the fInput.txt
    }
    SDL_Delay(500);
    Mix_HaltMusic();
    music = Mix_LoadMUS("Music/Sleepy_Hollow.mp3");
    Mix_PlayMusic(music, -1);
    system("CLS");
    cout << "Use these commands proceed the game...\n" << endl;
    game.getCommandList().print();
    cout << "\nPress Enter to continue!"; cin.ignore();
    system("CLS");

    // loop the main part of the game
    while (true) {
        string userinput = " ";
        int randomspawn = rand() % 6 + 1; // chance of spawning
        int randomdespawn = rand() % 7 + 1; // chance of despawning

        // Output status line 150 - 165
        cout << "Status Provided by Siera....." << endl; 
        game.Spawn(randomspawn);
        game.Despawn(randomdespawn);
        cout << "\nYou currently in: " << game.getLocation() << endl; // location status
        p.Status(); // player status

        // inventory status
        cout << p.getName() << "'s Inventory:" << endl;
        for (InventoryIterator iter(p); iter != iter.end(); ++iter) {
            if ((*iter).getName() != "empty slot") {
                cout << "[" << (*iter).getName() << " x " << (*iter).getQuantity() << "] ";
            }
            else {
                cout << "[ ] ";
            }
        }
        // User input
        cout << "\n\nWhat you want to do next?: "; getline(cin, userinput);
        // gameengine accept input and provide an output
        cout << "\n========================================================" << endl;
        game.UserInput(userinput, p);
        cout << "========================================================\n" << endl;
    }
	return 0;
};

