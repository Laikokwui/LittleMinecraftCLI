#pragma once

#include "LinkedList.h"
#include "DoublyLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "AVLTree.h"
#include "Creature.h"
#include "Sheep.h"
#include "Cow.h"
#include "Pig.h"
#include "CreatureFactory.h"
#include "CowFactory.h"
#include "SheepFactory.h"
#include "PigFactory.h"
#include "Visitor.h"
#include "MakeSoundVisitor.h"
#include "LookVisitor.h"
#include "Player.h"
#include "ItemEnchancement.h"
#include "Sharpening.h"
#include "Toughness.h"
#include "Flame.h"
#include "InventoryIterator.h"
#include <iostream>
#include <fstream>
#include <string>
#include <SDL.h>
#include <SDL_mixer.h>

using namespace std;

class GameEngine {
private:
	// Array of locations
	string fLocations[5] = {
		"forest_terrain", 
		"mountain_terrain", 
		"dessert_terrain", 
		"ruins_terrain", 
		"volcano_terrain"
	};
	// Command Database
	LinkedList<string> fCommandList;
	// Item Database
	AVLTree<Item*> fItemDatabase;
	// list of sheep
	Stack<Creature*> fSheep;
	// list of cow
	Stack<Creature*> fCow;
	//list of pig
	Stack<Creature*> fPig;
	// Map
	DoublyLinkedList<string> fGameMap;
	// chat
	Queue<string> fHistory;
	// currect location
	string fLocation;
public:
	// GameEngine default contructor
	GameEngine();
	// GameEngine destructor
	~GameEngine();

	// GameEngine getCommandList
	LinkedList<string> getCommandList();
	// GameEngine getItemDatabase
	AVLTree<Item*> getItemDatabase();
	// GameEngine getGameMap
	DoublyLinkedList<string> getGameMap();
	// GameEngine getLocation
	string getLocation();
	// GameEngine getLocation
	string getLocations(int aIndex);

	// GameEngine setCommandList
	void setCommandList(LinkedList<string> aCommandList);
	// GameEngine set Item database
	void setItemDatabase(AVLTree<Item*> aItemDatabase);
	// GameEngine setGameMap
	void setGameMap(DoublyLinkedList<string> aGameMap);
	// GameEngine set location
	void setLocation(string aLocation);
	// GameEngine set location
	void setLocations(string aLocations, int aIndex);

	// GameEngine print Game title screen
	void TitleScreen();
	// GameEngine UserInput function
	void UserInput(string aUserInput, Player& aPlayer);
	// GameEngine Play sound effect
	void PlayEffect(int aSoundID, int aloop);
	// GameEngine Simulate Keyboard effect
	void KeyboardEffect(string aMessage);
	// GameEngine Show Game Map
	void GameMap();
	// GameEngine find a location in the map
	void Locate(string aPlaceName);
	// GameEngine add new location
	void NewLocation();
	// GameEngine spawn creature
	void Spawn(int aChoice);
	// GameEngine spawn creature
	void Despawn(int aChoice);
	// GameEngine Show a list of Creature
	void CreatureList();
};

