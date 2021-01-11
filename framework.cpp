#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

string rooms[6] = {"Library", "Kitchen", "Office Wing", "Observatory", "Gallery", "Parlor"};
string keys[6] = {"l", "k", "ow", "ob", "g", "p"};
int size = 6;

void room_selection(string next_rooms[], string room_keys[], int array_size);

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
    if (input != correct_answer)
    {
        print(error_message);
        check(correct_answer, error_message);
    }

}

void welcome_message(string name)
{
    print_endl("");
    print_endl("Welcome " + name + "!");
    print_endl("The year is 1750, and you are at a castle party when all of a sudden, ");
    print_endl("the lights turn off and the doors are locked.");
    delay(2);
    print_endl("You have one hour to find the exit and escape with your life! \n");
    delay(2);
    print_endl("Make sure you enter all your answers in LOWERCASE! \n");
    delay(2);
}

//*** Room Methods ***

void library()
{
    //TODO: fill out library plotline here

    print_endl("You step into the library.");
    delay(1);
    print_endl("Tacked to the door is a note with three hints: \n");
    delay(1);

    print_endl("1. Secrets are often spoken over the flame.");
    delay(1);
    print_endl("2. Over the course of 50 years, this library has amassed 4,000 treasured volumes of literature in it.");
    delay(1);
    print_endl("3. I know the reigns of your Kings and Queens, trials of the poor and men I've seen.");
    print_endl("I die in darkness and the mouths of the dead, my chief purpose is to be read.");
    print_endl("If my words you fail to heed, in your future you shall bleed.");
    print_endl("What am I? \n");
    delay(5);

    print_endl("You look up into the vast room.");
    print_endl("Over 4,000 books, they say? How are you supposed to find a clue in here? \n");
    delay(2);

    print_endl("You cannot afford the luxury of looking through every book in the wing.");
    print_endl("However, there is likely a specific book you should be looking for. \n");
    print_endl("What wing of the library could it be in? (one word)");
    print("The __________ wing. ");

    check("history", "You run to this wing, but none of the books seem to stand out. \nWhat wing of the library could the book be in? (one word)");

    print_endl("You make your way to the history wing, and lying on a table, you see a book ringed in silver.");
    print_endl("You pick up the book and flip through the pages, and a loose sheet of parchment falls out.");
    delay(3);

    print_endl("But upon closer inspection, the paper seems to be blank.");
    delay(1);
    print_endl("Why are there no words on this paper? (one word)");
    print("The words are ");

    check("invisible", "No, that's not right. Why are there no words on the paper? \nThe words are ___________.");

    print_endl("\nThe words are invisible!");
    delay(1);
    print_endl("You search around the room and see a bookmark, candle, paperweight, and quill.");
    print_endl("Can one of these help you see the words?");
    delay(3);

    print("Which of these would you like to try using? ");

    check("candle", "You pick it up, but it doesn't seem to make a difference. Try something else. \nWhich of these would you like to try using?");

    print_endl("\nYou pick up the candle, remembering the clue on the wall.");
    print_endl("You hold the parchment over the flame, and slowly, the letter “T” appears. \n");
    print_endl("You’ve found a clue!");
    delay(4);

    print_endl("You skim the room for any more clues, and since there’s no more,");
    print_endl("you leave the library and head to your next location.");

    // Removing library from the rooms array, l from the keys array, and doing size--
    remove("Library", rooms, size);
    remove("l", keys, size);
    size--;

    // Running room_selection again so that user can move on to the next room.
    room_selection(rooms, keys, size);
}

void kitchen()
{
    //IMAGE: 2 boxes
    printendl("One box seems to have a puzzle on it, and the other box has nothing remarkable, save a star-shaped key-hole.");
    delay(5);

    //IMAGE 1st box only
    printendl("What does this puzzle say once completed?");
    delay(5);
    check("rose", "Please try again. \n What does this puzzle say once completed?");

    //IMAGE 2nd box only
    printendl("Nothing seems off with the 2nd box, it only requires a key. \n Do you have a key?");
    delay(5);

    string input;
    cin >> input;
    if (input == "yes")
    {
        "What is the inscription on the key?"
        check("dreams", "Please try again. \n What is the inscription on the key?");
        print_endl("Great you solved the puzzle! Please move to another room.");
        // Removing library from the rooms array, l from the keys array, and doing size--
        remove("Kitchen", rooms, size);
        remove("k", keys, size);
        size--;

        // Running room_selection so that user can move on to the next room.
        room_selection(rooms, keys, size);
    }
    else if (input == "no")
    {
        print_endl("Please go to a new room. This puzzle cannot be solved without the key.");
        // Running room_selection so that user can move on to the next room.
        room_selection(rooms, keys, size);
    }
    else
    {
        print_endl("Please enter either "yes" or "no" in all LOWERCASE letters.");
    }
}

void office_wing()
{
    print_endl("The office is dimly lit, with various stationary scattered across the desks. You take a few pencils, notepads, and paperclips just in case.”);
    delay(7);

    //insert image here
    print_endl("In the Office Wing you find a safe with a piece of parchment next to it. It lists the names of many European cities. An idea comes to you.");
    delay(7);
    print_endl("You try connecting the cities on the map, and the lines form a pattern. \n What combination will unlock the safe? Enter answer without spaces:");
    check("427", "Please try again. \n What combination will unlock the safe? Enter answer without spaces:");

    //insert image here
    print_endl("You enter the combination into the safe.");
    delay(5);
    print_endl("It clicks open and you reach in and pull out a piece of parchment paper with the letter “E” on it and a metal ball, on which there is the inscription 'soul'.");
    delay(15);
    print_endl("You take note of the clue for this room.");

    // Removing library from the rooms array, l from the keys array, and doing size--
    remove("Office Wing", rooms, size);
    remove("ow", keys, size);
    size--;

    // Running room_selection so that user can move on to the next room.
    room_selection(rooms, keys, size);
}

void observatory()
{
  print_endl("You enter the Observatory.")
  delay(1);
  print_endl("You look around the room. Where could the clue be hidden? In the ____.");


  check("safe", "You take a closer look, but you can't seem to find anything.\nWhat else can we check inside?");

  //buttons puzzle
  print_endl("You take a closer look at the safe. There seem to be words carved into the metal under three buttons: Red, Yellow, and Green.");
  delay(3);
  //img
  delay(2);
  print_endl("In which order do you press them? Enter colors separated by commas.");
  check("red, yellow, green", "Nothing happens. You try again, this time pressing in the order: ");

  print_endl("The safe opens and you find a piece of parchment with the letter “U” and a peculiar key, with the inscription “Dreams” on its side. These seem to be the room’s clue.");
  delay(4);
  print_endl("Which room do you go to next?");

// Running room_selection so that user can move on to the next room.
  remove("Observatory", rooms, size);
  remove("ob", keys, size);
  size--;
  room_selection(string next_rooms[], string room_keys[], int array_size);
}

void gallery()
{
    //TODO: images
    print_endl("You enter the gallery.");
    delay(1);
    print_endl("The gallery is home to the portraits of the heroes of this country.");
    delay(2);
    print_endl("Some of the most beautiful portraits are those of Prince Casper, Queen Mary, and Baroness Reagan.");

    //image
    print_endl("What in this room looks out of the ordinary? The ________");
    check("envelope", "You check, but nothing is amiss. What else seems unusual?");

    //image
    print_endl("These are all pictures of animals. Perhaps they can be arranged in a certain order to spell a word.");
    delay(2);
    print_endl("What does this clue spell?");
    check("Reagan", "That arrangement doesn't seem to make sense. Perhaps there's a better answer.");
    print_endl("You go to the portrait of Baroness Reagan. Slowly, You feel around the corners of the frame.");
    delay(3);
    print_endl("Giving a small tug, you stumble back as the frame swings open. There is a hidden storage behind the portrait.");
    delay(3);
    print_endl("In it is a piece of parchment with the letter \"U\" and a small metal ball.");
    delay(1);

    //image
    delay(2);
    print_endl("Upon closer inspection, the metal ball has the word \"mind\" inscribed into it.");
    delay(2);
    print_endl("Pocketing the ball and paper, you check off the gallery on your map of the castle. This seems to be the room’s clue.");
    delay(2);
    print_endl("Where will you go next?");

    // Running room_selection so that user can move on to the next room.
    remove("Gallery", rooms, size);
    remove("g", keys, size);
    size--;
    room_selection(string next_rooms[], string room_keys[], int array_size);
}

void parlor()
{
    print_endl("You enter the parlor and take a look around.");
    //image of parlor
    delay(2);
    print_endl("There's a strange chest carved into the floor...");
    //image of box
    print_endl("Looks like the three grooves labled \"M\", \"B\", and \"S\"need to be filled to open it. "
    print_endl("What can be used to open the box? _____ _____")
    check("metal balls", "No, that doesn't seem to make sense. Try again.");
    print_endl("Do you have the three metal balls required to open this box?");
    
    string input;
    cin >> input;
    if (input == "yes")
    {
        print_endl("Which sphere goes in the spot labeled \"M\"?");
        check("mind", "You try that metal ball, but it doesn't seem to work. Try another one.");
        print_endl("Which sphere goes in the spot labeled \"B\"?");
        check("body", "You try that metal ball, but it doesn't seem to work. Try another one.");
        print_endl("Which sphere goes in the spot labeled \"S\"?");
        check("soul", "You try that metal ball, but it doesn't seem to work. Try another one.");
        //image of box with balls
        print_endl("CLICK!");
        delay(2);
        print_endl("You hear the box unlock. Inside you find a key and piece of parchment with the letter \"R\".");
        //image of open box
        delay(5);
        print_endl("Have you collected clues from all 6 locations on the map?");
        
        string input2;
        cin >> input2;
        if (input2 == "yes")
        {
            print_endl("This key must be the one to unlock the front doors!You run to go try it!");
            //image of front door
            print_endl("The door swings open, and you come face-to-face with a cloaked figure.");
            //image of figure
            //PROCEED TO THE ENDING WHERE IS IT AT??
        }
        
        else if (input2 == "no")
        {
            print_endl("Please visit all the other rooms.");
            // Running room_selection so that user can move on to the next room.
            room_selection(rooms, keys, size);
        }
        else
        {
            print_endl("Please enter either \"yes\" or \"no\" in all LOWERCASE letters.");
        }    
      
    }
    else if (input == "no")
    {
        print_endl("Please go to a new room. This box cannot be opened without all three metal balls.");
        // Running room_selection so that user can move on to the next room.
        room_selection(rooms, keys, size);
    }
    else
    {
        print_endl("Please enter either \"yes\" or \"no\" in all LOWERCASE letters.");
    }    
}
                           
//method for ending
               
void room_selection(string next_rooms[], string room_keys[], int array_size)
{
    print_endl("Which room would you like to enter?");
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
    room_selection(rooms, keys, size);

    return 0;
}
