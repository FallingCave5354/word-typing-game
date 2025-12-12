#include <iostream>
#include <string.h>
#include <ctime>
#include <windows.h>
#include <iomanip>
#include <fstream>

using namespace std;

// Word Typing Game: Improving the typing speed/capability of a user
int main(){
    srand(time(0));
    // List of the words / Dictionary
    string words[3000];

    string difficulty_text[10] = {"Beginner Mode", "Easy Mode", "Normal Mode", "Intermediate Mode", "Challenging Mode", "Hard Mode", "Expert Mode", "Extreme Mode", "Insane Mode", "Custom Mode"},
           answer, // Declaration for user's inputted answer
           wrong_text = "   Your answer didn't match the word!\n";

    // Design template
    string style_ln = "\n========================================\n\n",
           title_header = "\n\n========================================\n=====       Word Typing Game       =====\n========================================\n\n";

    // Will get the array size of words
    int dictionary_size = sizeof(words) / sizeof(words[0]),
    // Declaration for difficulty selection
        difficulty_choice = 0;

    // Will store it to the array
    int line_tracker = 0; // This is for tracking, what index will it be stored
    string line; // Store words temporarily
    ifstream dictionary("dictionary.txt");
    while (getline(dictionary, line) && line_tracker < dictionary_size){
        words[line_tracker] = line;
        line_tracker++;
    }
    dictionary.close();

    // Documentation/Tutorial
    cout << title_header;
    cout << "Developed by: Renz Andrei G. Comintan\n"
         << "              Rayven D. Enriquez\n\n"
         << "Submitted to: Daniel Villanueva\n\n";
    cout << style_ln;
    Sleep(5000);
    system("cls");
    cout << "Word Typing Game\n\n"
         << "A console-based application designed to help users improve their typing capabilities, speed, and accuracy.\n"
         << "The game challenges players to type randomly generated words from a dictionary of nearly 3,000 words.\n\n"
         << "How to Play: \n\n"
         << "1. Launch the Game: Run the code by pressing F9.\n"
         << "2. Select Difficulty: You will be prompted to select a difficulty level between 1 and 10.\n"
         << "3. Type the number corresponding to your desired mode and press Enter.\n"
         << "4. Type the Words: A random word will appear on the screen (e.g., 1. Type \"abandon\").\n"
         << "5. Type the word exactly as shown next to Answer: and press Enter.\n"
         << "6. Note: In Custom Mode, you will be asked to manually input the \"Amount of Words\" you wish to play.\n\n"
         << "7. Review Results:\n"
         << "   - If correct, the game moves to the next word.\n"
         << "   - If wrong, the game displays \"Your answer didn\'t match the word!\" before moving on.\n"
         << "   - View Score: Once the session is finished, review your accuracy and score.\n\n"
         << "8. Play Again: Type Y (or y) to restart the game, or any other key to exit.\n";

    // Tutorial skip
    string tutorial_input;
    cout << "\n\nEnter any key to continue!   "; cin >> tutorial_input;
    if (tutorial_input == "0"){}
    system("cls");

    // Loading screen
    cout << title_header;
    cout << "\n\n\n\tWelcome to Word Type Game";
    cout << "\n\n\n\n\n" << style_ln;
    Sleep(2000); system("cls");
    for (int i = 1; i < 4; i++){
        cout << title_header;
        cout << "\n\n\n\tLoading";
        for (int j = 0; j < i; j++){
            cout << '.';
        }
        cout << "\n\n\n\n\n" << style_ln;
        Sleep(2000); system("cls");
    }

    // Play again/Restart
    char play_again, restart;
    play_again:
    system("cls");

    // Header/Title
    cout << title_header;

    // Display the difficulty selection
    cout << "Select a difficulty (1-10): \n\n";
    cout << "[1] Beginner       [6] Hard\n";
    cout << "[2] Easy           [7] Expert\n";
    cout << "[3] Normal         [8] Extreme\n";
    cout << "[4] Intermediate   [9] Insane\n";
    cout << "[5] Challenging    [10] Custom Mode\n\n";
    cout << style_ln;
    // Difficulty selection
    cout << "Difficulty: ";
    // Fix stuck on a loop when entering other than integer
    if (!(cin >> difficulty_choice)){
        cin.clear();
        cin.ignore(1000, '\n');
        difficulty_choice = -1;
    }
    difficulty_choice--; // Convert the value to index value (start from 0)

    // Amount of words in a difficulty
    double difficulty_duration[9] = {10,  // Beginner
                                     20,  // Easy
                                     40,  // Normal
                                     60,  // Intermediate
                                     80,  // Challenging
                                     100, // Hard
                                     120, // Expert
                                     160, // Extreme
                                     200} // Insane
                                     ;
    int correct_words = 0, // Counter for correct answers/words that matched
        wrong_words = 0, // Counter for incorrect answers/words that didn't matched
        numbering = 0; // Counts on what number you are

    double accuracy = 0.00, // Accuracy of the user
           custom_amount = 0.00; // Amount of words in Custom Mode

    const int percent = 100; // Percentage

    // If the user selected (1-9)
    if (difficulty_choice >= 0 && difficulty_choice <= 8){
        Sleep(1000);

        for (int i = 0;i < difficulty_duration[difficulty_choice];i++){
            system("cls");
            cout << title_header;

            // Word randomizer
            int random_word = rand() % dictionary_size;

            numbering++; // Number tracker
            // Displays the difficulty and the amount of words on that
            cout << "\t" << difficulty_text[difficulty_choice] << ':' << numbering << '/' << difficulty_duration[difficulty_choice] << " words\n\n";
            // Displays the word
            cout << numbering << ". Type \"" << words[random_word] << "\"\n   Answer: ";
            cin >> answer;

            // Score
            if (words[random_word] == answer){
                correct_words++;
            } else {
                wrong_words++;
            cout << wrong_text;
            Sleep(1000);
            }
            Sleep(60);
        }
        system("cls");
        // Scoreboard
        cout << title_header;
        cout << "\tDifficulty: " << difficulty_text[difficulty_choice] << "\n\n";
        cout << "\tScore: " << correct_words << '/' << difficulty_duration[difficulty_choice] << endl;
        accuracy = ((correct_words / difficulty_duration[difficulty_choice]) * percent);
        cout << "\tAccuracy: " << setprecision(4) << accuracy << "%\n\n";
        cout << "\tCorrect words: " << correct_words << endl;
        cout << "\tWrong words: " << wrong_words << endl << endl;
        cout << style_ln;

    // If the user selected 10
    }
    if (difficulty_choice == 9) {
        system("cls");
        cout << title_header;
        cout << "Amount of Words: ";
        cin >> custom_amount; // Amount of Words
        cout << endl;
        Sleep(1000);

        for (int i = 0;i < custom_amount;i++){
            system("cls");
            cout << title_header;

            // Word randomizer
            int random_word = rand() % dictionary_size;

            numbering++; // Number tracker
            // Displays the difficulty and the amount of words on that
            cout << "\t" << difficulty_text[difficulty_choice] << ':' << numbering << '/' << custom_amount << " words\n\n";
            // Displays the word
            cout << numbering << ". Type \"" << words[random_word] << "\"\n   Answer: ";
            cin >> answer;

            // Score
            if (words[random_word] == answer){
                correct_words++;
            } else {
                wrong_words++;
            cout << wrong_text;
            Sleep(1000);
            }
            Sleep(60);
        }
        system("cls");

        // Scoreboard
        cout << title_header;
        cout << "\tDifficulty: " << difficulty_text[difficulty_choice] << "\n\n";
        cout << "\tScore: " << correct_words << '/' << custom_amount << endl;
        accuracy = ((correct_words / custom_amount) * percent);
        cout << "\tAccuracy: " << setprecision(4) << accuracy << "%\n\n";
        cout << "\tCorrect words: " << correct_words << endl;
        cout << "\tWrong words: " << wrong_words << endl << endl;
        cout << style_ln;
    }
    // If the user didn't select from 1-10
    if (0 > difficulty_choice|| 9 < difficulty_choice){
        cout << "\n   Please select a valid difficulty!";
        Sleep(1500);
        goto play_again;
    }
    // Ask to play again
    cout << "\n\tPlay again? Y/N\t";
    cin >> restart;
    cout << endl;
    if (restart == 'Y' || restart == 'y'){
        goto play_again;
    }

    return 0;
}
