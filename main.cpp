#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


void splitFunction(std::vector<char> &wordToSplit);
void combineFunction(std::vector<char> &wordToCombine);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char operation = 'a';
    char type = 'b';
    std::string word;

    std::cout << "Enter C for Combine or S for Split" << std::endl;
    std::cin >> operation;
    std::cout << "Enter M for method, C for Class, or V for variable" << std::endl;
    std::cin >> type;

    vector<char> input;
    input.push_back(operation);
    input.push_back(';');
    input.push_back(type);
    input.push_back(';');
    std::cout << "Enter words with spaces to combine or no spaces with capital letters for each different word to split. \n";
    cin.ignore();
    std::getline(std::cin,word);
//    std::cout << "Your word is: " << word << std::endl;

    for(int i=0; i<word.length(); i++)
    {
        input.push_back(word[i]);
    }


//    for(int i=0; i<input.size(); i++) //ensure proper output
//    {
//        std::cout << input[i];
//    }
//    std::cout << "\n";

    if(input[0]=='S')
    splitFunction(input);
    else
    combineFunction(input);

//    cout << "Our final result is ";
    for(auto i: input)  //Output result
        std::cout << i;

//    std::cout << "\n";
//
//    std::cout << "End of program" << std::endl;

    return 0;
}

void splitFunction(std::vector<char> &wordToSplit)
{
    char c = wordToSplit[4];
    wordToSplit[4] = tolower(c); //ensures first letter for a method is lower case

    if(wordToSplit[2]=='M')
    {
        wordToSplit.erase(wordToSplit.end()-2,wordToSplit.end());
    }


    for(int i = 4; i<wordToSplit.size(); i++)
    {
        char c = wordToSplit[i];

        //std::cout << "char c is: " << c << std::endl;

        if(isupper(c))
        {
            wordToSplit[i] = tolower(c);
            wordToSplit.insert(wordToSplit.begin()+i, ' ');
            i++;
        }

    }

    wordToSplit.erase(wordToSplit.begin(),wordToSplit.begin()+4);

}

void combineFunction(std::vector<char> &wordToCombine)
{

    for(int i=4; i<wordToCombine.size(); i++)
    {
        char c = wordToCombine[i];
        //std::cout << "char c is: " << c << std::endl;
        if(c==' ')
        {
            c = wordToCombine[i+1];
            wordToCombine[i+1] = toupper(c); //ensures new word is lower case
            wordToCombine.erase(wordToCombine.begin()+i);
        }
    }

    if(wordToCombine[2]=='M')
    {
        wordToCombine.push_back('(');
        wordToCombine.push_back(')');
    }

    wordToCombine.erase(wordToCombine.begin(),wordToCombine.begin()+4);

}