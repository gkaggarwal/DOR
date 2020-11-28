#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <string>
#include <stdlib.h>
#include<cstdio>
using namespace std;

int main()

{
string inputString="free point and life rate and market at franc";

stringstream stringStream(inputString);
string line,word;
while(std::getline(stringStream, line)) 
{
    std::size_t prev = 0, pos;
    while ((pos = line.find_first_of(" ", prev)) != std::string::npos)
    {
        if (pos > prev)
            {
            word = line.substr(prev, pos-prev);
             if(word!= "at" && word!= "and" && word!= "a" && word!= "an" && word!= "on" && word!= "by" && word!= "also" && word!= "also" && word!= "am" && word!= "any" && word!= "are"  && word!= "as" && word!= "be" && word!= "been" && word!= "but" && word!= "can" && word!= "cannot" && word!= "could" && word!= "did" && word!= "do" && word!= "does" && word!= "either" && word!= "else" && word!= "ever" && word!= "for" && word!= "from" && word!= "had" && word!= "has" && word!= "have" && word!= "her" && word!= "him" && word!= "how" && word!= "however" && word!= "i" && word!= "if" && word!= "in" && word!= "into" && word!= "is" && word!= "its" && word!= "it" && word!= "just" && word!= "least" && word!= "let" && word!= "may" && word!= "me" && word!= "might" && word!= "my" && word!= "no" && word!= "nor" && word!= "off" && word!= "of" && word!= "other" && word!= "our" && word!= "so" && word!= "than" && word!= "that" && word!= "there" && word!= "their" && word!= "them" && word!= "these" && word!= "they" && word!= "this" && word!= "to" && word!= "too" && word!= "us" && word!= "was" && word!= "we" && word!= "were" && word!= "what" && word!= "when" && word!= "when" && word!= "where" && word!= "which" && word!= "while" && word!= "who" && word!= "whom" && word!= "why" && word!= "yet" && word!= "you" && word!= "your")
            cout<<word<<endl;
            
            }
        prev = pos+1;
    }
    if (prev < line.length())
      {word = line.substr(prev, line.length()-prev);
            cout<<word<<endl;
            
            }  
}  
    return 0;
 }
 
 

