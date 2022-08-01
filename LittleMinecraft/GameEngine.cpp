#include "GameEngine.h"

// GameEngine default contructor
GameEngine::GameEngine(){}

// GameEngine destructor
GameEngine::~GameEngine(){}

// GameEngine UserInput function
void GameEngine::UserInput(string aUserInput, Player& aPlayer){
	string array[5]; // store part of the command
	string token; // store one part of the command temporary
	string delimiter = " "; // which character to detect
	string str = aUserInput; // copy the full command
	size_t pos = 0; // used to represent a string index
	int count = 0; // count number of time it split the command
	fHistory.enqueue(aUserInput); // Add the full command into the queue

	// Start spliting the command by searching the delimiter and will not go over 3 times
	while ((pos = str.find(delimiter)) != string::npos && count < 4) {
		token = str.substr(0, pos); // substr is use to take a part of the main string and tore it to token
		array[count] = token; // store the token into one of the space of the array
		str.erase(0, pos + delimiter.length()); // erase() remove the part of the string to stop infinite loop
		count++; // increase count by one
	}
	array[count] = str; // store the rest of the string here as we may or may not need it

	// Check the first part of the command
	if (array[0] == "/Collect") {
		aPlayer.AddItem(array[1], array[2], 1); // Add Item
		cout << array[2] << " has been added into your inventory!" << endl; // Output message
	}
	else if (array[0] == "/Craft") {
		bool crafted = false; // boolean true or false 
		crafted = aPlayer.CraftItem(array[1]); // craft item and make sure it is crafted

		// play sound effect it it crafted successfully
		if (crafted) {
			PlayEffect(2, 1);
			PlayEffect(1, 1);
		}
	}
	else if (array[0] == "/Drop") {
		// check item is available in the inventory
		if (aPlayer.CheckItem(array[2], 1)) {
			aPlayer.RemoveItem(array[1], array[2], 1); // remove item
			cout << array[2] << " has been drop from your inventory!" << endl; // output message
		}
		else {
			cout << "You do not have this item in your inventory!" << endl; // output message
		}
	}
	else if (array[0] == "/Enchance") {
		// check item is available in the inventory
		if (aPlayer.CheckItem(array[2], 1)) {
			Item* temp = aPlayer.getSlot(aPlayer.getSlotIndex(array[2])); // get the item class object

			// Check which enchancement the user wants
			if (array[3] == "Sharpening") {
				temp = new Sharpening(temp); // wrap the item with new object

				// Output item descripton
				cout << "\nItem Description:" << endl;
				cout << temp->Description() << endl;

				cout << "Enchance Successfully!" << endl; // Output message
				aPlayer.AddItem(temp->getID(), temp->getName(), temp->getQuantity()); // Add item in
				aPlayer.RemoveItem(array[1], array[2], 1); // remove one of the item
			}
			else if (array[3] == "Toughness") {
				temp = new Toughness(temp); // wrap the item with new object

				// Output item descripton
				cout << "\nItem Description:" << endl;
				cout << temp->Description() << endl;

				cout << "Enchance Successfully!" << endl; // Output message
				aPlayer.AddItem(temp->getID(), temp->getName(), temp->getQuantity()); // Add item in
				aPlayer.RemoveItem(array[1], array[2], 1); // remove one of the item
			}
			else if (array[3] == "Flame") {
				temp = new Flame(temp); // wrap the item with new object

				// Output item descripton
				cout << temp->Description() << endl;
				cout << "\nItem Description:" << endl;

				cout << "Enchance Successfully!" << endl; // Output message
				aPlayer.AddItem(temp->getID(), temp->getName(), temp->getQuantity()); // Add item in
				aPlayer.RemoveItem(array[1], array[2], 1); // remove one of the item
			}
			else {
				cout << "Invalid Command! Type '/Help' command to get a list of command!" << endl;  // Output message
			}
			delete temp; // delete temp
		}
		else {
			cout << "You do not have the item in your inventory!" << endl; // Output message
		}
	}
	else if (array[0] == "/Feed") {
		bool feed = false;
		LookVisitor look; // look visitor

		// Check which creature to feed and is it available
		if (array[1] == "Sheep" && fSheep.size() >= 1) {
			Sheep sheep; // create sheep class object
			sheep.accept(look); // output the visitor method
			feed = aPlayer.FeedCreature(array[1], array[3]); // feed it

			// check whether it is feeded
			if (feed) {
				aPlayer.RemoveItem(array[2], array[3], 1); // remove the item
			}
			else {
				cout << "Sheep walked away" << endl; // Output message
			}
		}
		else if (array[1] == "Cow" && fCow.size() >= 1) {
			Cow cow;
			cow.accept(look);
			feed = aPlayer.FeedCreature(array[1], array[3]);

			// check whether it is feeded
			if (feed) {
				aPlayer.RemoveItem(array[2], array[3], 1); // remove the item
			}
			else {
				cout << "Cow walked away" << endl; // Output message
			}
		}
		else if (array[1] == "Pig" && fPig.size() >= 1) {
			Pig pig;
			pig.accept(look);
			feed = aPlayer.FeedCreature(array[1], array[3]);

			// check whether it is feeded
			if (feed) {
				aPlayer.RemoveItem(array[2], array[3], 1); // remove the item
			}
			else {
				cout << "Pig walked away" << endl; // Output message
			}
		}
		else {
			cout << "No creature found to feed!" << endl; // Output message
		}
	}
	else if (array[0] == "/Goto") {
		Locate(array[1]); // go to the location
	}
	else if (array[0] == "/Help") {
		fCommandList.print(); // print the command list
	}
	else if (array[0] == "/Quit") {
		system("CLS"); // Clear the screen
		Mix_HaltMusic(); // STop the music

		// Open output file and output the queue
		ofstream outFile; 
		outFile.open("Save file/fOutput.txt");
		cout << "Saving";

		while(!fHistory.isEmpty()) {
			outFile << fHistory.dequeue() << endl;
			cout << ".";
			SDL_Delay(100);
		}
		SDL_Delay(300);
		outFile.close(); // close the output file
		Mix_CloseAudio(); // close the audio device
		SDL_Quit(); // quit the sdl
		
		TitleScreen(); // print out title screen
		// output the thank you message
		cout << "Thanks For Playing! Little Minecraft <3" << endl;
		cout << "Subscribe to Mailson Wei!" << endl;
		exit(0); // exit the program
	}
	else if (array[0] == "/Show") {
		if (array[1] == "Creature") {
			CreatureList(); // call the creaturelist method
		}
		else if (array[1] == "Map") {
			GameMap(); // call the GameMap method
		}
		else if (array[1] == "ItemList") {
			// List out all the items
			cout << "In Order: " << endl; 
			fItemDatabase.inOrderObject(fItemDatabase.fRoot);
			cout << "" << endl;
			cout << "Pre Order: " << endl;
			fItemDatabase.preOrderObject(fItemDatabase.fRoot);
			cout << "" << endl;
			cout << "Post Order: " << endl;
			fItemDatabase.postOrderObject(fItemDatabase.fRoot);
		}
		else {
			cout << "Invalid Command! Type '/Help' command to get a list of command!" << endl; // output the message
		}
	}
	else if (array[0] == "/Travel") {
		NewLocation(); // get new location
	}
	else {
		cout << "Invalid Command! Type '/Help' command to get a list of command!" << endl; // output the message
	}
}

// GameEngine getCommandList
LinkedList<string> GameEngine::getCommandList() { return fCommandList; }
// GameEngine getItemDatabase
AVLTree<Item*> GameEngine::getItemDatabase() { return fItemDatabase; }
// GameEngine setGameMap
DoublyLinkedList<string> GameEngine::getGameMap() { return fGameMap; }
// GameEngine getLocation
string GameEngine::getLocation() { return fLocation; }
// GameEngine getLocation
string GameEngine::getLocations(int aIndex) { return fLocations[aIndex]; }

// GameEngine setCommandList
void GameEngine::setCommandList(LinkedList<string> aCommandList) { fCommandList = aCommandList; }
// GameEngine set Item database
void GameEngine::setItemDatabase(AVLTree<Item*> aItemDatabase) { fItemDatabase = aItemDatabase; }
// GameEngine setGameMap
void GameEngine::setGameMap(DoublyLinkedList<string> aGameMap) { fGameMap = aGameMap; }
// GameEngine set location
void GameEngine::setLocation(string aLocation) { fLocation = aLocation; }
// GameEngine set locations
void GameEngine::setLocations(string aLocations, int aIndex) { fLocations[aIndex] = aLocations; }

// GameEngine print Game title screen
void GameEngine::TitleScreen() {
	// use raw string literals
	cout << R"abcd(
   .____    .__  __    __  .__                                             _____
   |    |   |__|/  |__/  |_|  |   ____                                 ,-:` \;',`'-,   
   |    |   |  \   __\   __\  | _/ __ \                              .'-;_,;  ':-;_,'.
   |    |___|  ||  |  |  | |  |_\  ___/                             /;   '/    ,  _`.-\
   |_______ \__||__|  |__| |____/\___  >                           | '`. (`     /` ` \`|
           \/                        \/                            |:.  `\`-.   \_   / |
      _____  .__                                   _____  __       |     (   `,  .`\ ;'|
     /     \ |__| ____   ____   ________________ _/ ____\/  |_      \     | .'     `-'/
    /  \ /  \|  |/    \_/ __ \_/ ___\_  __ \__  \\   __\\   __\      `.   ;/        .'
   /    Y    \  |   |  \  ___/\  \___|  | \// __ \|  |   |  |          `'-.______.-'
   \____|__  /__|___|  /\___  >\___  >__|  (____  /__|   |__|  
           \/        \/     \/     \/           \/             

                                                             Little Minecraft by Lai Kok Wui
)abcd" << endl;
}

// GameEngine Play sound effect
void GameEngine::PlayEffect(int aSoundID, int aloop) {
	Mix_Chunk* effect = NULL;
	if (aSoundID == 1) {
		effect = Mix_LoadWAV("Sound Effects/hammering.wav"); // load hammering.wav
	}
	if (aSoundID == 2) {
		effect = Mix_LoadWAV("Sound Effects/sawing_wood.wav"); // load sawing_wood.wav
	}
	if (aSoundID == 3) {
		effect = Mix_LoadWAV("Sound Effects/cow_moo.wav"); // load cow_moo.wav
	}
	if (aSoundID == 4) {
		effect = Mix_LoadWAV("Sound Effects/sheep_meh.wav"); // load sheep_meh.wav
	}
	if (aSoundID == 5) {
		effect = Mix_LoadWAV("Sound Effects/pig_oink.wav"); // load pig_oink.wav
	}
	if (aSoundID == 6) {
		effect = Mix_LoadWAV("Sound Effects/walking.wav"); // load walking.wav
	}
	Mix_VolumeChunk(effect, 20); // set the volumn of the sound effect to 20
	Mix_PlayChannel(0, effect, aloop); // play the effect with aloop number of loop

	// check is it playing
	while (Mix_PlayChannel(0, effect, aloop) != -1) {
		Mix_PlayChannel(0, effect, aloop); // play the effect
		SDL_Delay(2000); // delay to let the music finish playing
		Mix_HaltChannel(-1); // stop the effect
		break; // break the while loop
	}
}

// GameEngine Simulate Keyboard effect
void GameEngine::KeyboardEffect(string aMessage){
    Mix_Chunk* blip = Mix_LoadWAV("Sound Effects/blip.wav"); // load blip.wav
	Mix_VolumeChunk(blip, 5); // set the volumn of the sound effect to 5
    Mix_PlayChannel(0, blip, -1); // play the blip.wav

	// chech is it playing
    while (Mix_PlayChannel(0, blip, 0) != -1) {
        Mix_PlayChannel(0, blip, -1); // play the blip.wav

		// Output one character one at a time
        for (size_t i = 0; i < aMessage.length(); i++) {
            cout << aMessage[i];
            SDL_Delay(50); // delay before the next character print out
        }
		Mix_HaltChannel(-1); // stop the effect
		break; // break the while loop
    }
}

// GameEngine Show Game Map
void GameEngine::GameMap(){
	cout << "Your map!:" << endl;
	fGameMap.printforward();
}

// GameEngine find a location in the map
void GameEngine::Locate(string aPlaceName) {
	DoublyListNode<string>* temp = NULL; // create empty node
	temp = fGameMap.find(aPlaceName); // find the value and store in it

	// check is it available
	if (temp != NULL) {
		setLocation(temp->fData);
	}
	else {
		cout << "location stay the same!" << endl; // output message
	}
}

// GameEngine find a location in the map
void GameEngine::NewLocation() {
	int index = rand() % 5; // select random number
	fGameMap.appendtail(getLocations(index)); // get the random location from an array
	setLocation(getLocations(index)); // set the location
	PlayEffect(6, 1); // play the walking.wav
	cout << "You discovered a new biome which is: " << getLocations(index) << "!" << endl; // output message
}

// GameEngine spawn creature
void GameEngine::Spawn(int aChoice) {
	MakeSoundVisitor sound; // makesoundvisitor 
	if (aChoice == 1) {
		cout << "One Sheep spawn just now!" << endl; // output message
		SheepFactory s;
		Sheep sheep;
		fSheep.push(s.CreateCreature());
		sheep.accept(sound); // call the accept method
		PlayEffect(4, 0);
	}
	else if (aChoice == 2) {
		cout << "One Cow spawn just now!" << endl;
		CowFactory c;
		Cow cow;
		fCow.push(c.CreateCreature());
		cow.accept(sound); // call the accept method
		PlayEffect(3, 0);
	}
	else if (aChoice == 3) {
		cout << "One Pig spawn just now!" << endl;
		PigFactory p; 
		Pig pig;
		fPig.push(p.CreateCreature());
		pig.accept(sound); // call the accept method
		PlayEffect(5, 0);
	}
	else {
		cout << "No creature spawn at the moment!" << endl;
	}
}

// GameEngine spawn creature
void GameEngine::Despawn(int aChoice) {
	MakeSoundVisitor sound; // makesoundvisitor
	if (aChoice == 1 && fSheep.size() >= 1) {
		Sheep sheep;
		cout << "One Sheep despawn just now!" << endl; // output message
		sheep.accept(sound); // call the accept method
		fSheep.pop(); // remove 1 sheep
		PlayEffect(4, 0); // play sheep_meh.wav
	}
	else if (aChoice == 2 && fCow.size() >= 1) {
		Cow cow;
		cout << "One Cow despawn just now!" << endl; // output message
		cow.accept(sound); // call the accept method
		fCow.pop(); // remove 1 cow
		PlayEffect(3, 0); // play cow_moo.wav
	}
	else if (aChoice == 3 && fCow.size() >= 1) {
		Pig pig;
		cout << "One Pig despawn just now!" << endl; // output message
		pig.accept(sound); // call accept method
		fPig.pop(); // remove 1 pig
		PlayEffect(5, 0); // play pig_oink.wav
	}
	else {
		cout << "No creature despawn at the moment!" << endl; // output message
	}
}

// GameEngine Show a list of Creature
void GameEngine::CreatureList(){
	cout << "Number of Sheep: " << to_string(fSheep.size()) << endl; // show number of sheep
	cout << "Number of Cow: " << to_string(fCow.size()) << endl; // show number of cow
	cout << "Number of Pig: " << to_string(fPig.size()) << endl; // show number of pig
}

