#include <iostream>
#include <fstream>
#include <cstring>
#include<sstream>
#include<string>
using namespace std;


int main() 
{ 
    
    fstream file1,file2;
    string word1_doc,word1_string,word1_freq,word2,word3, filename1,filename2; 
    filename1 = "dict0.dat"; 
    filename2 = "vocab.dat";
    file1.open(filename1.c_str(),ios::in);  
    while( file1 >> word1_doc)
    {  long int term_id=0;
       long int doc_id=0;
       long int frequency=0;
       std::istringstream doc (word1_doc);
       doc >> doc_id;
       file1>>word1_string;
       file2.open(filename2.c_str(),ios::in);  
    
       while ( file2 >> word2)
       {
           file2 >> word3;
           if ( word1_string != word2)
           {
           }
           else
           { std::istringstream term (word3);
              term >> term_id;
              file2.close();
              break;
              
           }
       
       }
       
       file1>>word1_freq;
      std::istringstream freq (word1_freq);
       freq>>frequency;
    cout<<term_id<<" "<<doc_id<<" "<<frequency<<endl;
    }
    return 0;
    
}
