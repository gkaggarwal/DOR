#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <string>
#include <stdlib.h>
#include<cstdio>
using namespace std;
string word[50];
 
void parse(string inputString)
{
stringstream stringStream(inputString);
string line,wordp;
while(std::getline(stringStream, line)) 
{   int c=0;
    std::size_t prev = 0, pos;
    while ((pos = line.find_first_of(" ", prev)) != std::string::npos)
    {
        if (pos > prev)
            {
            wordp = line.substr(prev, pos-prev);
             if(wordp!= "at" && wordp!= "and" && wordp!= "a" && wordp!= "an" && wordp!= "on" && wordp!= "by" && wordp!= "also" && wordp!= "also" && wordp!= "am" && wordp!= "any" && wordp!= "are"  && wordp!= "as" && wordp!= "be" && wordp!= "been" && wordp!= "but" && wordp!= "can" && wordp!= "cannot" && wordp!= "could" && wordp!= "did" && wordp!= "do" && wordp!= "does" && wordp!= "either" && wordp!= "else" && wordp!= "ever" && wordp!= "for" && wordp!= "from" && wordp!= "had" && wordp!= "has" && wordp!= "have" && wordp!= "her" && wordp!= "him" && wordp!= "how" && wordp!= "however" && wordp!= "i" && wordp!= "if" && wordp!= "in" && wordp!= "into" && wordp!= "is" && wordp!= "its" && wordp!= "it" && wordp!= "just" && wordp!= "least" && wordp!= "let" && wordp!= "may" && wordp!= "me" && wordp!= "might" && wordp!= "my" && wordp!= "no" && wordp!= "nor" && wordp!= "off" && wordp!= "of" && wordp!= "other" && wordp!= "our" && wordp!= "so" && wordp!= "than" && wordp!= "that" && wordp!= "there" && wordp!= "their" && wordp!= "them" && wordp!= "these" && wordp!= "they" && wordp!= "this" && wordp!= "to" && wordp!= "too" && wordp!= "us" && wordp!= "was" && wordp!= "we" && wordp!= "were" && wordp!= "what" && wordp!= "when" && wordp!= "when" && wordp!= "where" && wordp!= "which" && wordp!= "while" && wordp!= "who" && wordp!= "whom" && wordp!= "why" && wordp!= "yet" && wordp!= "you" && wordp!= "your")
         //   cout<<wordp<<endl;
            word[c++]=wordp;
            }
        prev = pos+1;
    }
    if (prev < line.length())
      {wordp = line.substr(prev, line.length()-prev);
            //cout<<wordp<<endl;
            word[c]=wordp;
            }  
}  
}
int main()

{
string inputString="free point and life rate and market at franc";
int j=0;
string s2 ;                //Boolean Query
    string A[100];
    char s1[100];
    cout<<"Enter Query:";
    int and_query_type=0,or_query_type=0,not_query_type=0,and_operation=0,or_operation=0;
    fgets(s1,100,stdin);
    s2=s1;
parse(s2);
while(word[j]!="")
{
cout<<word[j++]<<endl;
}

    return 0;
 }
 
 

