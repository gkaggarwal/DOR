#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <string>
#include <stdlib.h>
#include<cstdio>
using namespace std;
string word[15];
static int i;

void divide(string inputString)
{ 

stringstream stringStream(inputString);
string line;
//static int i;
std::string delimiter1 = " OR ";
std::string delimiter2 = " AND ";
std::string delimiter3 = "NOT ";
string token;
while(std::getline(stringStream, line)) 
{    string s1,s2,s3;
    std::size_t prev = 0, pos,pos1,pos2;
    if ((pos = line.find(delimiter1, prev)) != std::string::npos)
    {
            s1 = line.substr(prev, pos-prev);       
            divide(s1);
           
            line = line.substr(pos+delimiter1.length(),line.length());
            divide(line);
            cout<<"OR"<<endl;
     
    }
    else if((pos1 = line.find(delimiter2, prev)) != std::string::npos)
            {
               s2 = line.substr(prev, pos1-prev);
              divide(s2);
                  
              line = line.substr(pos1+delimiter2.length(),line.length());
               divide(line);
              cout<<"AND "<<endl;
            }
    else if((pos2 = line.find(delimiter3, prev)) != std::string::npos)
            {
              line = line.substr(pos2+delimiter3.length(),line.length());
               //cout<<"s3="<<s3<<endl;
               divide(line);
               
          //    cout<<"NOT "<<line<<endl;
            }           
               
     else
      { word[i++]=line;
      cout<<line<<endl;
        //cout<<line<<endl;     
      }  
}
//cout<<word<<endl;
}
int main()

{
int j=0;
string inputString="gaurav AND meera OR Geeks AND NOT Geeksfor AND tool OR gaurav AND NOT market";
divide(inputString);
  while(word[j]!="")
  {
 //  cout<<word[j]<<endl;
   j++;
  }
return 0;
 }
