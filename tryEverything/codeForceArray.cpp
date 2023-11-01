#include <iostream>
int main(){
    int numValues;
    std::cin >> numValues;
    int arr[numValues];
    for(int i = 0; i < numValues; i++){
        std::cin >> arr[i];
    }
    int one, two, numQ;
    std::cin >> numQ;
    for(int i = 0; i < numQ; i++){
        std::cin >> one;
        std::cin >> two;
        for(int i = 0; i < numValues; i++){
            if(arr[i] == one)
                one = i;
            if(arr[i] == two)
                two = i;
        }
        std::cout << "ONE:" << one << " " << one % (numQ + 1)<< std::endl << "TWO: " << two << " " << two % (numQ + 1) << std::endl;
        if(one % (numQ + 1) < two % (numQ + 1))
            std::cout << "Yes\n";
        else
            std::cout << "No\n";
    }

    return 0;
}