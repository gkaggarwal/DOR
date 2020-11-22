// reading a text file
#include <iostream>
#include <fstream>
#include <cstring>
#include<sstream>
#include<string>
using namespace std;
//static long int term_id;
int main() 
{ 
    
    fstream file,file1,file_t1,file_t2,file_t3,file6;
    fstream file_c; 
    string word,word1,word2,word3,word4, t, q, filename,filename1,filename3,filename4,filename5,filename6; 
    filename = "lyrl2004_tokens_train.dat"; 
    filename1 = "dict.dat";
    filename3 = "t1.dat";
    filename4 = "t2.dat";
    filename5 = "t3.dat";
    filename6 = "vocab.dat";
    file.open(filename.c_str()); 
    file1.open(filename1.c_str(),ios::app); 
    file6.open(filename6.c_str(),ios::app); 
    file >> word;
          
    while (file >> word) 
    {     
          std::istringstream iss (word);
          long int term=0 ;
           iss >> term;
           file >> word1;
        file_t1.open(filename3.c_str(),ios::out | ios::trunc); 
        file_t2.open(filename4.c_str(),ios::out | ios::trunc); 
        file_t3.open(filename5.c_str(),ios::app);
        while(word1 != ".I")
           {
           	file >> word1;
           	file_t1 <<word1 <<" ";
           	file_t2 <<word1 <<" ";
           	file_t3 <<word1 <<" ";
           	
           	//cout<<word1<<endl;
          }
          
           file_t1.close();
          file_t2.close();
          file_t3.close();
          
        file_t1.open(filename3.c_str(),ios::in); 
          while(file_t1 >> word2)
          { int count=0;
            int flag=0;
        file_t2.open(filename4.c_str(),ios::in);
        
           while( file_t2 >> word3)
           {  // cout<<word3<<endl;
                  if(word2!= word3)
           	  {}
           	  else
           	  { 
           	    count+=1;
           	   
           	  }
           }
           file_t2.close();
           file_t3.open(filename5.c_str(),ios::in);
          while(file_t3 >> word4)
          {
            if(word2!= word4)
            {
            }
            else
            {
             flag=1;
            }
          
          }
          file_t3.close();
          if(flag==1)
          {
           file6 << word2 <<"\n";
          }
          for(int i=0;i<count-1;i++)
          {
           file_t1>>word2;
           
          }
    //      term_id+=1;
          file1 << term<<"\t"<<word2 <<"\t "<<count<<"\n";
          }
          file_t1.close();
         }
    
  
    return 0; 
} 
