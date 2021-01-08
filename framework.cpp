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
    //TODO: fill out kitchen plotline here

    /*
    At the end of this plotline, remove the kitchen from the rooms array, do size--,
    and run room_selection again so that the user can move on to the next room.
    */
}

void office_wing()
{
    //TODO: fill out office wing plotline here

    /*
    At the end of this plotline, remove the office wing from the rooms array, do size--,
    and run room_selection again so that the user can move on to the next room.
    */
}

void observatory()
{
    //TODO: fill out observatory plotline here

    /*
    At the end of this plotline, remove the observatory from the rooms array, do size--,
    and run room_selection again so that the user can move on to the next room.
    */
}

void gallery()
{
    //TODO: fill out gallery plotline here

    /*
    At the end of this plotline, remove the gallery from the rooms array, do size--,
    and run room_selection again so that the user can move on to the next room.
    */
}

void parlor()
{
    //TODO: fill out parlor plotline here

    /*
    At the end of this plotline, remove the parlor from the rooms array, do size--,
    and run room_selection again so that the user can move on to the next room.
    */
}

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