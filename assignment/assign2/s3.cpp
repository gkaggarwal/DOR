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
string inputString="Geeks OR For AND Geeks OR gaurav NOT market";

stringstream stringStream(inputString);
string line,token;
while(std::getline(stringStream, line)) 
{
    std::size_t prev = 0, pos;
    while ((pos = line.find_first_of("  AND OR NOT", prev)) != std::string::npos)
    {
        if (pos > prev)
            {
            token = line.substr(prev, pos-prev);
            cout<<token<<endl;
            cout<<pos<<endl;
            
            }
        prev = pos+1;
    }
    if (prev < line.length())
      {token = line.substr(prev, line.length()-prev);
            cout<<token<<endl;
            
            }  
}  
    return 0;
 }
