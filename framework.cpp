#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

string rooms[6] = {"Library", "Kitchen", "Office Wing", "Observatory", "Gallery", "Parlor"};
string keys[6] = {"l", "k", "ow", "ob", "g", "p"};
int SIZE = 6;
int PARLOR_STATUS = 0;
int STATUS[6] = {0, 0, 0, 0, 0, 0};

void room_selection(string next_rooms[], string room_keys[], int array_size);

string bag[20];
int bagStorage = 0;
void bagCheck()
{
  for(int i = 0; i < bagStorage; i++){
    cout << (i+1) << ") " << bag[i] << endl;
  }
}

// Function that delays the execution of the next line of code by a given number of seconds
void delay(int seconds)
{
    clock_t startTime = clock(); //Start timer
    double secondsPassed;
    double secondsToDelay = seconds;
    bool flag = true;
    while(flag)
    {
        secondsPassed = (clock() - startTime) / CLOCKS_PER_SEC;
        if(secondsPassed >= secondsToDelay)
        {
            flag = false;
    }
  }
}

// Functions to make printing statements easier to write
void print_endl(string statement)
{
    cout << statement << endl;
}

void print(string statement)
{
    cout << statement;
}

// Function to remove an element from an array
void remove(string remove_this, string array[], int array_size)
{
    // Find the index at which the element is located in the array
    int index = 0;
    for (int i = 0; i < array_size; i++)
    {
        if (array[i] == remove_this)
        {
            index = i;
            break;
        }
    }

    for (int i = index; i < array_size; i++)
    {
        array[i] = array[i + 1];
    }

}

// Function to set all letters of a string to lowercase
string lowercase(string s)
{
    // std::string str = s;
    // string lower = "";
    // transform(str.begin(), str.end(), str.begin(), ::tolower);

    // char *p = s;
    // while (*s != \0)
    // {
    //     tolower(*s);
    //     s++
    // }

    // char str[] =

    // cout << "LOWER " << s << endl;
    return s;
}

// Function to check if the user's answer is correct
void check(string correct_answer, string error_message)
{
    string input;
    // cin >> lowercase(input);
    cin >> input; // TODO: handle capitalizations, etc.
    if (input == "leave")
    {
        room_selection(rooms, keys, SIZE);
    }
    if (input == "bag"){
      bagCheck();
      check(correct_answer, error_message);
    }
    else if (input != correct_answer)
    {
        print(error_message);
        check(correct_answer, error_message);
    }

}

void welcome_message(string name)
{
    cout << " " << endl;
    print_endl("Welcome, " + name + "!");
    print_endl("\nThe year is 1750, and you are at a castle party when all of a sudden, ");
    print_endl("the lights turn off and the doors are locked.");
    delay(4);
    print_endl("You have one hour to find the exit and escape with your life! \n");
    delay(3);
    print_endl("Make sure you enter all your answers in LOWERCASE (unless otherwise stated)! \n");
    delay(3);
    print_endl("Throughout the game, certain items will be added to your bag, which you can view by entering \"bag\".");
    delay(3);
    print_endl("If you can't answer a puzzle and want to come back to it later, just enter \"leave\" to exit the room.");
    delay(4);
}

//*** Room Methods ***

void ending()
{
    print_endl("\nYou make your way back to the entrance of the castle, and you find a chest by the door.");
    print_endl("There are six dials to enter letters into.");
    delay(4);
    print_endl("\nLying next to it is a sheet of parchment that says,");
    delay(2);
    print_endl("\"What is in front of you but cannot be seen?\"");
    delay(2);
    print_endl("\nUse the clues you’ve gathered so far. What is the answer?");
    print("\nThe _ _ _ _ _ _. ");
    check("future", "The chest does not open. Try again.");
    print_endl("\nThe chest clicks open, and you reach in and grab a key.");
    delay(3);
    print_endl("You insert the key into the grand doors, and turn. The lock clicks, and you push the door open.");
    delay(5);
    print_endl("Congratulations, you are free!");
}

void library()
{
    if (STATUS[0] == 1)
    {
        print_endl("You have already visited this room. Do you need to look in here again?\nEnter 'Y' or 'N': ");
        string input;
        cin >> input;
        if (input == "N")
        {
            room_selection(rooms, keys, SIZE);
        }
    }
    print_endl("\nYou step into the library.");
    print_endl("https://photos.app.goo.gl/7NyjXMBANhH5jLFM7");
    delay(8);
    print_endl("Tacked to the door is a note with three hints: \n");
    delay(3);

    print_endl("1. Secrets are often spoken over the flame.");
    delay(3);
    print_endl("2. Over the course of 50 years, this library has amassed 4,000 treasured volumes of literature in it.");
    delay(4);
    print_endl("3. I know the reigns of your Kings and Queens, trials of the poor and men I've seen.");
    print_endl("   I die in darkness and the mouths of the dead, my chief purpose is to be read.");
    print_endl("   If my words you fail to heed, in your future you shall bleed.");
    print_endl("   What am I? \n");
    delay(10);

    print_endl("You look up into the vast room.");
    print_endl("Over 4,000 books, they say? How are you supposed to find a clue in here? \n");
    delay(4);

    print_endl("You cannot afford the luxury of looking through every book in the wing.");
    print_endl("However, there is likely a specific book you should be looking for. \n");
    print_endl("What wing of the library could it be in? (one word)");
    print("The _ _ _ _ _ _ _ wing. ");

    check("history", "\nYou run to this wing, but none of the books seem to stand out. \nWhat wing of the library could the book be in? (one word) ");

    print_endl("\nYou make your way to the history wing, and lying on a table, you see a book ringed in silver.");
    delay(4);
    print_endl("You pick up the book and flip through the pages, and a loose sheet of parchment falls out.");
    delay(4);

    print_endl("https://photos.app.goo.gl/7TAb3cpfBZmTBMFY9");
    delay(6);
    print_endl("But upon closer inspection, the paper seems to be blank.");
    delay(3);
    print_endl("\nWhy are there no words on this paper? (one word)");
    print("The words are _ _ _ _ _ _ _ _ _. ");

    check("invisible", "\nNo, that's not right. Why are there no words on the paper? \nThe words are _ _ _ _ _ _ _ _ _. ");

    print_endl("\nThe words are invisible!");
    delay(2);
    print_endl("You search around the room and see a bookmark, candle, paperweight, and quill.");
    print_endl("Maybe one of these can help you see the words.");
    delay(5);

    print("Which of these would you like to try using? ");

    check("candle", "\nYou pick it up, but it doesn't seem to make a difference. Try something else. \nWhich of these would you like to try using? ");

    print_endl("\nYou pick up the candle, remembering the clue on the wall.");
    print_endl("You hold the parchment over the flame...\n");
    print_endl("https://photos.app.goo.gl/nwHEhXDB5VNtMTA59");
    delay(6);
    print_endl("... and slowly, the letter “T” appears.\n");
    delay(3);
    print_endl("You’ve found a clue! Parchment with letter \"T\" added to bag.");
    delay(3);
    bag[bagStorage] = "Parchment with letter \"T\"";
    bagStorage++;
    print_endl("You skim the room for any more clues, and since there’s no more,\nyou leave the library and head to your next location.");
    delay(6);
    STATUS[0] = 1;
    // Removing library from the rooms array, l from the keys array, and doing size--
    // remove("Library", rooms, size);
    // remove("l", keys, size);
    // size--;

    // Running room_selection again so that user can move on to the next room.
    room_selection(rooms, keys, SIZE);
}

void kitchen()
{
    if (STATUS[1] == 1)
    {
        print_endl("You have already visited this room. Do you need to look in here again?\nEnter 'Y' or 'N': ");
        string input;
        cin >> input;
        if (input == "N")
        {
            room_selection(rooms, keys, SIZE);
        }
    }
    //IMAGE: kitchen
    print_endl("\nYou enter the kitchen...what is that gross smell? Wrinkling your nose, you turn around and see some boxes.");
    print_endl("https://photos.app.goo.gl/SytFrk1gWpPcuJe8A \n");
    delay(6);
    print_endl("One box seems to have a puzzle on it, and the other box has nothing remarkable, save a star-shaped key-hole.\n");
    delay(5);

    //IMAGE 1st box only
    print_endl("Next to the first box is a riddle, saying:");
    delay(3);
    print_endl("Though my beauty is becoming, I can hurt you just the same.\nI come in many colors, many give me to their flames.");
    delay(6);
    print("What is the answer to the riddle? _ _ _ _ ");
    check("rose", "Please try again. \n What does this puzzle say once completed? _ _ _ _ ");
    print_endl("You place the scrambled parts of the puzzle to spell out \"rose\", and the lid clicks open.");
    delay(4);

    //IMAGE 2nd box only
    print_endl("Nothing seems off with the 2nd box, it only requires a key. \nDo you have a key that is star-shaped?");
    print("(Enter Y or N): ");

    string input;
    cin >> input;
    if (input == "Y")
    {
        print_endl("What is the inscription on the key? _ _ _ _ _ ");
        check("dreams", "Please try again. \n What is the inscription on the key? _ _ _ _ _ ");
        print_endl("https://photos.app.goo.gl/UYTeF5Jnn1kv8Mxa9");
        delay(6);
        print_endl("Looking inside both boxes, you take out a metal sphere with the inscription 'body' and a parchment paper with the letter 'F'.");
        delay(5);
        print_endl("These seem to be the clues for this room, so you decide to move on. \"body\" sphere and \"F\" parchment added to bag.");
        bag[bagStorage]="\"body\" sphere and \"F\" parchment";
        bagStorage++;
        // Removing library from the rooms array, l from the keys array, and doing size--
        // remove("Kitchen", rooms, size);
        // remove("k", keys, size);
        // size--;

        // Running room_selection so that user can move on to the next room.
        STATUS[1] = 1;
        delay(3);
        room_selection(rooms, keys, SIZE);
    }
    else if (input == "N")
    {
        print_endl("Please go to another room. This puzzle cannot be solved without the key.");
        delay(4);
        // Running room_selection so that user can move on to the next room.
        room_selection(rooms, keys, SIZE);
    }
    else
    {
        print_endl("Please enter either 'Y' or 'N'.");
    }
}

void office_wing()
{
    if (STATUS[2] == 1)
    {
        print_endl("You have already visited this room. Do you need to look in here again?\nEnter 'Y' or 'N': ");
        string input;
        cin >> input;
        if (input == "N")
        {
            room_selection(rooms, keys, SIZE);
        }
    }
    print_endl("\nThe office wing is dimly lit, with various stationary scattered across the desks.");
    print_endl("https://photos.app.goo.gl/F865pZvv2uTs9hbr6");
    print_endl("You take a few pencils, notepads, and paperclips just in case. \n");
    delay(10);

    //insert image here
    print_endl("You find a safe with a piece of parchment next to it. It lists the names of many European cities.");
    delay(4);
    print_endl("\nAn idea comes to you.");
    print_endl("https://photos.app.goo.gl/jzAhqPvXz4mv9Q7j9");
    delay(6);
    print_endl("\nYou try connecting the cities on the map, and the lines form a pattern. \nWhat combination will unlock the safe? Enter answer without spaces: _ _ _ ");
    check("427", "Please try again. \n What combination will unlock the safe? Enter answer without spaces:");

    //insert image here
    print_endl("\nYou enter the combination into the safe.");
    delay(3);
    print_endl("https://photos.app.goo.gl/SFp5jXJCGxmSWLyC9");
    delay(6);
    print_endl("It clicks open and you reach in and pull out a piece of parchment paper with the letter “E” on it and a metal sphere, on which there is the inscription 'soul'.");
    delay(5);
    print_endl("You take note of the clue for this room. \"soul\" sphere and \"E\" parchment added to bag.");
    delay(3);
    bag[bagStorage] = "\"soul\" sphere and \"E\" parchment";
    bagStorage++;

    // Removing library from the rooms array, l from the keys array, and doing size--
    // remove("Office Wing", rooms, size);
    // remove("ow", keys, size);
    // size--;

    // Running room_selection so that user can move on to the next room.
    STATUS[2] = 1;
    room_selection(rooms, keys, SIZE);
}

void observatory()
{
    if (STATUS[3] == 1)
    {
        print_endl("You have already visited this room. Do you need to look in here again?\nEnter 'Y' or 'N': ");
        string input;
        cin >> input;
        if (input == "N")
        {
            room_selection(rooms, keys, SIZE);
        }
    }
    print_endl("\nYou enter the observatory.");
    delay(1);
    print_endl("Tacked to the doorframe is a paper with the clues:");
    delay(2);
    print_endl("Venus: Red");
    print_endl("Mars: Red");
    print_endl("Io: Yellow");
    print_endl("Jupiter: Yellow");
    print_endl("Titan: Green");
    print_endl("Callisto: Green");
    delay(9);
    print_endl("\nhttps://photos.app.goo.gl/cmFJ14W361od9HW56");
    print_endl("You look around the room. Where could the clue be hidden? In the _ _ _ _. ");
    check("safe", "You take a closer look, but you can't seem to find anything there.\nWhat else looks out of the ordinary?");

    //buttons puzzle
    print_endl("https://photos.app.goo.gl/6mgPFqFrgnUp5Wgt9");
    delay(6);
    print_endl("\nYou take a closer look at the safe. There seem to be letters carved into the metal under three buttons.");
    delay(5);
    //img
    print_endl("In which order do you press the buttons? Enter colors separated by commas. _____,_____,_____");
    check("red,yellow,green", "Nothing happens. You try again, this time pressing in the order: ");

    print_endl("https://photos.app.goo.gl/8WeKAGrBRgvrdonf9");
    delay(6);
    print_endl("The safe opens and you find a piece of parchment with the letter “U” and a peculiar star-shaped key, with the inscription “dreams” on its side.");
    delay(5);
    print_endl("These seem to be the room’s clues.\n\"dreams\" star-shaped key and \"U\" parchment added to bag.");
    delay(3);
    bag[bagStorage] = "\"dreams\" star-shaped key and \"U\" parchment";
    bagStorage++;

    // Running room_selection so that user can move on to the next room.
    //   remove("Observatory", rooms, size);
    //   remove("ob", keys, size);
    //   size--;
    STATUS[3] = 1;
    room_selection(rooms, keys, SIZE);
}

void gallery()
{
    if (STATUS[4] == 1)
    {
        print_endl("You have already visited this room. Do you need to look in here again?\nEnter 'Y' or 'N': ");
        string input;
        cin >> input;
        if (input == "N")
        {
            room_selection(rooms, keys, SIZE);
        }
    }
    //TODO: images
    print_endl("\nYou enter the gallery.");
    delay(1);
    print_endl("You spot a sheet of parchment tacked to the doorframe. Written on it are a few clues:");
    delay(3);
    print_endl("1. The gallery is home to the heroes of this country.");
    delay(2);
    print_endl("2. Some of the most beautiful portraits are those of Prince Casper, Queen Mary, and Baroness Reagan.");
    delay(4);
    print_endl("3. Anteater, Angelfish, Eel, Guinea Pig, Narwhal, Rattlesnake");
    delay(3);
    print_endl("Interesting...");
    delay(3);
    //image
    print_endl("https://photos.app.goo.gl/kr74mSXtLE3XXxyeA");
    print_endl("What in this room looks out of the ordinary? The _ _ _ _ _ _ _ _. ");
    check("envelope", "You check, but nothing is amiss. \nWhat else seems unusual, like it isn't supposed to be part of this room?\nThe _ _ _ _ _ _ _ _. ");

    //image
    print_endl("\nhttps://photos.app.goo.gl/S5SMiepUoeBvhZck9");
    delay(6);
    print_endl("These are all pictures of animals. Perhaps they can be arranged in a certain order to spell a word.");
    delay(3);
    print_endl("What does this clue spell? ");
    check("reagan", "That arrangement doesn't seem to make sense. Perhaps there's a better answer. ");
    print_endl("https://photos.app.goo.gl/RNCgtBWw5CogiU219");
    delay(16);
    print_endl("\nYou go to the portrait of Baroness Reagan. Slowly, You feel around the corners of the frame.");
    delay(4);
    print_endl("Giving a small tug, you stumble back as the frame swings open. There is a hidden storage behind the portrait.");
    delay(3);
    print_endl("https://photos.app.goo.gl/qmAnG7CHzXfGvHPR8");
    delay(6);
    print_endl("In it is a piece of parchment with the letter \"U\" and a small metal sphere.");
    delay(4);

    //image
    print_endl("Upon closer inspection, the metal sphere has the word \"mind\" inscribed into it.");
    delay(3);
    print_endl("Pocketing the sphere and paper, you check off the gallery on your map of the castle. This seems to be the room’s clue.");
    delay(4);
    print_endl("\"mind\" sphere and \"U\" parchment added to bag.");
    delay(3);
    bag[bagStorage] = "\"mind\" sphere and \"U\" parchment";
    bagStorage++;

    // Running room_selection so that user can move on to the next room.
    // remove("Gallery", rooms, size);
    // remove("g", keys, size);
    // size--;
    STATUS[4] = 1;
    room_selection(rooms, keys, SIZE);
}

void parlor()
{
    bool visited_all = true;
    for (int i = 0; i < 6; i++)
    {
        if (STATUS[i] == 0)
        {
            visited_all = false;
        }
    }
    if (STATUS[5] == 0)
    {
        print_endl("\nYou enter the parlor and take a look around.");
        print_endl("https://photos.app.goo.gl/MwZ6UyD1DG16DvZN6");
        //image of parlor
        delay(10);
        print_endl("There's a strange chest on the floor...");
        print_endl("https://photos.app.goo.gl/zPNbTaBVQNxTEuWM9");
        delay(10);
        //image of box
        print_endl("\nLooks like the three grooves labled \"M\", \"B\", and \"S\" need to be filled to open it.");
        print_endl("\nWhat can be used to open the box? \n(Hint: what have you been collecting from the rooms you visited?)\nInstead of a space, split the two words with a '-': _ _ _ _ _-_ _ _ _ _ _ _ ");
        check("metal-spheres", "No, that doesn't seem to make sense. Try again.\nWhat can be used to open the box? _ _ _ _ _-_ _ _ _ _ _ _ ");
        print("\nDo you have the three metal spheres required to open this box? Enter 'Y' or 'N': ");

        string input;
        cin >> input;

        // while (input != "Y" || input != "N")
        // {
        //   print("Please enter either 'Y' or 'N': ");
        //   cin >> input;
        // }

        if (input == "Y")
        {
            print_endl("\nWhat is the inscription on the sphere goes in the spot labeled \"M\"? _ _ _ _ ");
            check("mind", "You try that metal sphere, but it doesn't seem to work. Try another one. ");
            print_endl("\nWhat is the inscription on the sphere goes in the spot labeled \"B\"? _ _ _ _ ");
            check("body", "You try that metal sphere, but it doesn't seem to work. Try another one. ");
            print_endl("\nWhat is the inscription on the sphere goes in the spot labeled \"S\"? _ _ _ _ ");
            check("soul", "You try that metal sphere, but it doesn't seem to work. Try another one. ");
            //image of box with spheres
            print_endl("\n*CLICK!*");
            delay(1);
            print_endl("https://photos.app.goo.gl/Lh8LX5958Hu1yd6U9");
            //image of open box
            delay(6);
            print_endl("\nYou hear the box unlock. Inside you find a key and piece of parchment with the letter \"R\".");
            delay(4);
            print_endl("Have you collected clues from all 6 locations on the map? Enter 'Y' or 'N': ");

            string input2;
            cin >> input2;

            // while (input2 != "Y" || input2 != "N")
            // {
            //   print_endl("Please enter either 'Y' or 'N'.");
            //   cin >> input;
            // }

            if (input2 == "Y" && visited_all)
            {
                ending();
            }

            else
            {
                print_endl("\nYou need clues from all the rooms to move on.");
                delay(2);
                print_endl("Please visit any rooms you haven't yet been to, then return here so you can move on.");
                delay(4);
                STATUS[5] = 2;
                // Running room_selection so that user can move on to the next room.
                room_selection(rooms, keys, SIZE);
            }

        }

        else
        {
            print_endl("\nPlease go to a new room. This box cannot be opened without all three metal spheres.");
            delay(3);
            // Running room_selection so that user can move on to the next room.
            room_selection(rooms, keys, SIZE);
        }
    }

    else if (STATUS[5] == 2 && visited_all)
    {
        print_endl("\nNow that you have collected the clues from all the rooms, you may move on.");
        delay(2);
        ending();
    }

    else if (STATUS[5] == 2 && visited_all == false)
    {
        print_endl("\nYou need clues from all the rooms to move on.");
        delay(2);
        print_endl("Please visit any rooms you haven't yet been to, then return here so you can move on.");
        delay(4);
        // Running room_selection so that user can move on to the next room.
        room_selection(rooms, keys, SIZE);
    }

}

void room_selection(string next_rooms[], string room_keys[], int array_size)
{
    print_endl("\nWhich room would you like to enter?");
    print_endl("(Type in a one or two-letter key.)");
    for (int i = 0; i < array_size; i++)
    {
        print_endl(room_keys[i] + ": " + next_rooms[i]);
    }

    string entered_room;
    cin >> entered_room;

    if (entered_room == "l" || entered_room == "L")
    {
        library();
    }
    else if (entered_room == "k" || entered_room == "K")
    {
        kitchen();
    }
    else if (entered_room == "ow" || entered_room == "OW" || entered_room == "oW" || entered_room == "Ow")
    {
        office_wing();
    }
    else if (entered_room == "ob" || entered_room == "OB" || entered_room == "oB" || entered_room == "Ob")
    {
        observatory();
    }
    else if (entered_room == "g" || entered_room == "G")
    {
        gallery();
    }
    else if (entered_room == "p" || entered_room == "P")
    {
        parlor();
    }
    else
    {
        print_endl("That is not a valid room choice. Please select a value from the keys given on the left.");
        room_selection(next_rooms, room_keys, array_size);
    }

}

int main()
{
    string player_name;
    print("Enter player name: ");
    cin >> player_name;

    welcome_message(player_name);
    room_selection(rooms, keys, SIZE);

    return 0;
}
