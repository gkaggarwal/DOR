#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <string>
#include <stdlib.h>
#include<cstdio>
using namespace std;
int main()
{string s ;//= "scott AND tiger AND mushroom";
char s1[100];
fgets(s1,100,stdin);
s=s1;
std::string delimiter = " AND ";

size_t pos = 0;
std::string token;
while ((pos = s.find(delimiter)) != std::string::npos) {
    token = s.substr(0, pos);
    std::cout << token << std::endl;
    s.erase(0, pos + delimiter.length());
}
pos = s.find("\n");
//s.erase(remove(s.begin(), s.end(), '\n'),s.end());
s.erase(pos,pos+1);
std::cout << s << std::endl;
cout<<"hello"<<endl;
return 0;

}
