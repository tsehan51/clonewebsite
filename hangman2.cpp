#include <iostream>
#include <vector> 
#include <fstream>
#include <ctime>

using namespace std;

string createWord(vector<string>&wordlist){
    fstream myfile;
    myfile.open("food.txt", ios::in);
    if(myfile.is_open()){
        string wordEnter;

        while(getline(myfile, wordEnter)){
            wordlist.push_back(wordEnter);
        }

        srand(time(NULL));
        int randomNum = rand() % wordlist.size() ;
        string randWord = wordlist[randomNum];
        myfile.close();
        return randWord;

    }else{
        cout << "file cannot be opened...\ngame failed to start !!!";
        return 0;
    };
    
};

//reference used as emptyVec is modified, but not happen in guess
void inputUsed(vector <char> &emptyVec, char guess){
    emptyVec.push_back(guess);
    cout << "Used letter: ";
    for(char c : emptyVec){
        cout << c << " ";
    };
    cout << endl;
};

//reference used as modification is done in both
void inputGuess(vector <char> &emptyVec, char &guess){
    cout << "Enter your guessing(a-z): ";
    cin >> guess;
    inputUsed(emptyVec, guess);
};

//to check whether word and blank is same or not
//if same return true and break, win
//false continue
bool inputCheck(string word, string blank){
    
    for(int i = 0; i < word.length(); i++){
        if (word[i] == blank[i]){

        }else{
            return false;
        };
    };
    return true;
    
};

//to break if lives == 0
//minus lives if wrong guessing
bool inputLives(int &lives, bool answer, string &word){

    if(answer == false){

        lives = lives - 1;

        if(lives == 0){
            cout << "Answer: " << word << endl;
            cout << "GAME OVER TT !! TRY AGAIN" << endl;
            return false; // if false then break the while loop

        }else{cout << "Wrong !! Lives remaining: " << lives << endl;};
        
    }else{cout << "Correct !! Lives remaining: " << lives << endl;};

    return true; // if true then continue
};


int main(){
    char guess;
    int lives = 7;
    vector <char> emptyVec;
    vector <string> wordlist;
    string blank = "_________________";
    string word = createWord(wordlist); //open food.txt and choose a random word
    cout << word << endl;
    for(int i = 0; i < word.length(); i++){ //print before guessing
        cout << blank[i] << " ";
    };
    cout << endl;

    while (lives > 0){
        bool answer = false; //will be set to default(false) when each loop begins
        
        inputGuess(emptyVec, guess);
    
        for(int i = 0; i < word.length(); i++){
            char letter = word[i];
            if (letter == guess){
                blank[i] = guess;
                answer = true; //happen when guessing correct, else follow by default
            };
        };

        if (inputLives(lives, answer, word) == false){
            break; //happen when lives == 0
        };

        for(int i = 0; i < word.length(); i++){ //print after guessing
            cout << blank[i] << " ";
        };
        cout << endl;
        cout << endl;
        if(inputCheck(word, blank) == true){ //happen when word == blank
            cout << "YOU WIN IT XD XD" << endl;
            break;
        }
    };
    
    return 0;
}