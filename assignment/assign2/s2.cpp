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
 
   string s ,s2;
    string A[100];
    char s1[100];
    cout<<"Enter Query:";
    int query_type=0;
    fgets(s1,100,stdin);
    s=s1;
    std::string delimiter = " AND ";
    std::string delimiter1 = " OR ";
    std::string delimiter2 = "NOT ";
    int k=1;
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
    token = s.substr(0, pos);
    query_type=1;
    A[k++]=token;
    
    s.erase(0, pos + delimiter.length());
   }
   s2=s;
   while ((pos = s2.find(delimiter1)) != std::string::npos) {
    token = s2.substr(0, pos);
    query_type=2;
    A[k++]=token;
    
    s2.erase(0, pos + delimiter1.length());
   }
   while ((pos = s2.find(delimiter2)) != std::string::npos) {
    if(pos ==0)
    { s2.erase(0, delimiter2.length());
      query_type=3;
    }
    }
   
   pos = s2.find("\n");  // Deleteing newline character at the end of input string
   s2.erase(pos,pos+1);
    A[k]=s2;
    cout<<"Query: "<<query_type<<endl;
    for(int i=1;i<=k;i++)
    {
    cout<<A[i]<<i<<endl;
    }
    cout<<"k="<<k<<endl;
    
    return 0;
 }
