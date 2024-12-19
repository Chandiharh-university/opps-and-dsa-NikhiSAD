/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string sentence;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, sentence);

    std::istringstream stream(sentence);
    std::string word, longestWord;

    while (stream >> word) {
        if (word.length() > longestWord.length()) {
            longestWord = word;
        }
    }

    std::cout << "The longest word is: " << longestWord << std::endl;
    return 0;
}
