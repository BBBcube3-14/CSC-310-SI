#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    srand(time(0));
    for(int i = 0; i < 10; i++){
        int num = rand() % 4;
        if(num == 0){
            cout << "AT";
        }else if(num == 1){
            cout << "GC";
        }else if(num == 2){
            cout << "TA";
        }else{
            cout << "CG";
        }
    }
    return 0;
}