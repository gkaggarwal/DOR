// reading a text file
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct data
{
  string data1;
  int count;
}d1;

 int main() 
{ 
    
    fstream file,file1;
    fstream file_c; 
    string word,word1,word2,word_c, t, q, filename,filename1; 
    //map < string, int>M;
    long int count;
    int flag=0;
    filename = "lyrl2004_tokens_train.dat"; 
    filename1 = "dict.txt";
    file.open(filename.c_str()); 
    file1.open(filename1.c_str(),ios::app); 
     
    
           	
    file >> word;
          
    while (file >> word) 
    {    
           //file1.open(filename1.c_str(),ios::app | ios :: out); 
           //file1 << "Document_ID \n"; 
           //file1 << word << "\n";
           //file1.close();
           file >> word1;
           
           	
           
           while(word1 != ".I")
           {
           	file >> word1;
           	count=0;
           	flag=0;
           	file_c.open(filename1.c_str());	   
           	 
           	while(file_c >> word2)
           	 { if(word1 != word2)
           	   {}
           	   else
           	   {    count+=1;
           	        flag=1;
                 	
           	   }
           	  
           	   
           	 }
           	 file_c.close();
           	 if(flag==0 )
           	 {
           	  file1.open(filename1.c_str(),ios::app); 
                  file1 << word1 <<"\n";
                  file1.close();
                       
           
                 }
              // cout << word1 << " " << count << " "<< flag << endl; 
        }
    }
  
    return 0; 
} 
