#include "Number.hpp"


#include<iostream>
#include <cassert>
#include <cstdio>
#include <vector>


using namespace std;


int main () {
    
    cout << "***************************" << endl;
    cout << "PLANTILLA DE CLASE NUMBER_T" << endl;
    Number_t<10,2>  n(1);
    n.write(cout);
    cout << endl;
    Number_t<10,8>  n1(7);
    n1.write(cout);
    cout << endl;
    Number_t<10,2>  n2(0);
    n2 = n.to_this_base(n1.to_decimal()) + n;
    
    cout << "write(int b)" << endl;
    n1.write(3);
    cout << "***************************" << endl;
}