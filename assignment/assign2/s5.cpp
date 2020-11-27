#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <string>
#include <stdlib.h>
#include<cstdio>
using namespace std;
string word[25];
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
std::getline(stringStream, line);
string s1,s2,s3,p1,p2,p3;
    std::size_t prev = 0, pos,pos1,pos2;
    if ((pos = line.find(delimiter1, prev)) != std::string::npos)
    {
           
           
            p1 = line.substr(pos+delimiter1.length(),line.length());
          //  divide(p1);
            s1 = line.substr(prev, pos-prev);       
            //divide(s1);
            if(s1.length() > p1.length())
                  {divide(s1);
                  divide(p1);
                  }
               else
                  {divide(p1);
                  divide(s1);
                  }

            // cout<<"OR"<<endl;
             word[i++]="OR";
    }
    else if((pos1 = line.find(delimiter2, prev)) != std::string::npos)
            {
                  
              p2 = line.substr(pos1+delimiter2.length(),line.length());
              s2 = line.substr(prev, pos1-prev);
              
               if(s2.length() > p2.length())
                  {divide(s2);
                  divide(p2);
                  }
               else
                  {divide(p2);
                  divide(s2);
                  }
              //cout<<"AND "<<endl;
              word[i++]="AND";
            }
    else if((pos2 = line.find(delimiter3, prev)) != std::string::npos)
            {
              p3 = line.substr(pos2+delimiter3.length(),line.length());
               //cout<<"s3="<<s3<<endl;
               divide(p3);
               word[i++]="NOT";
          //    cout<<"NOT "<<line<<endl;
            }           
               
     else
      { word[i++]=line;
      //cout<<line<<endl;     
      }  

}
int main()

{
int j=0;
string inputString="gaurav AND sit OR Geeks AND meera AND renu AND Geeksfor AND tool OR gaurav AND NOT market";
//string inputString="gaurav OR geeks";
divide(inputString);
  while(word[j]!="")
  {
  cout<<word[j]<<endl;
   j++;
  }
return 0;
 }
