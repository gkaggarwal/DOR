#include <iostream>
#include <utility>
#include<stdlib.h>
using namespace std;
 
int main()
{   //long int *pair1;
    pair<int, int> *pair2;
    pair2=(pair<int,int> *)calloc(10,sizeof(pair<int,int>));
    (*pair2).first=2;
    (*pair2).second=2;
    cout << ((*(pair2)).first) << " ";
    cout << pair2[0].second << endl;
 
    return 0;
}
