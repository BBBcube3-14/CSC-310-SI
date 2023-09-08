#include <iostream>
using namespace std;

template<class Type>
class Addition{
    Type x,y;
    public:
        Addition(Type, Type);
        Type Addition();
};

template <class Type>
Type Addition<int> :: Addition(Type One, Type Two){
    Type x = One;
    Type y = Two;
}