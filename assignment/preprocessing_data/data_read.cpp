// reading a text file
#include <iostream>
#include <fstream>
#include <cstring>
#include<sstream>
#include<string>
using namespace std;
static long int term_id;
int main() 
{ 
    
    fstream file[5],file1,file_t1,file_t2,file_t3,file6;
    fstream file_c;
    int i =0; 
    string word,word1,word2,word3,word4,word5, t, q, filename[5],filename1[5],filename3,filename4,filename5,filename6; 
    filename[0] = "lyrl2004_tokens_train.dat"; 
    filename[1] = "lyrl2004_tokens_test_pt0.dat"; 
    filename[2] = "lyrl2004_tokens_test_pt1.dat"; 
    filename[3] = "lyrl2004_tokens_test_pt2.dat"; 
    filename[4] = "lyrl2004_tokens_test_pt3.dat"; 
    
    filename1[0] = "dict0.dat";
    filename1[1] = "dict1.dat";
    filename1[2] = "dict2.dat";
    filename1[3] = "dict3.dat";
    filename1[4] = "dict4.dat";
    
    filename3 = "t1.dat";
    filename4 = "t2.dat";
    filename5 = "t3.dat";
    filename6 = "vocab.dat";
     
    while(i<5)
    {
    file1.open(filename1[i].c_str(),ios::app); 
    file[i].open(filename[i].c_str()); 
    file[i] >> word;
    
    while (file[i] >> word) 
    {     
          std::istringstream iss (word);
          long int term=0 ;
           iss >> term;
           file[i] >> word1;
        file_t1.open(filename3.c_str(),ios::out | ios::trunc); 
        file_t2.open(filename4.c_str(),ios::out | ios::trunc); 
    //    file_t3.open(filename5.c_str(),ios::app);
        while(word1 != ".I")
           {
           	file[i] >> word1;
           	file_t1 <<word1 <<" ";
           	file_t2 <<word1 <<" ";
      //     	file_t3 <<word1 <<" ";
           	
           	//cout<<word1<<endl;
          }
          
           file_t1.close();
          file_t2.close();
        //  file_t3.close();
          
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
           
          file6.open(filename6.c_str(),ios::in);
          while(file6 >> word4)
          {  file6 >> word5;
            if(word2!= word4)
            {
            }
            else
            {
             flag=1;
             break;
            }
          
          }
          file6.close();
          if(flag==0)
          {term_id+=1; 
           file6.open(filename6.c_str(),ios::app);
           file6 << word2 <<"\t"<<term_id <<"\n";
           file6.close();
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
         
         cout<<"file done "<<filename[i]<<endl;
        file1.close();
        i++;
        } 
  
    return 0; 
} 
