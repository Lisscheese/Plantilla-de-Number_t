#include "Number.hpp"


#include<iostream>
#include <cassert>
#include <cstdio>
#include <vector>


using namespace std;


int main () {
    
    Number_t<10,16,int>  n(243);
    n.write(cout);
    cout << endl;
    Number_t<10,16,int>  n1(40);
    n1.write(cout);
    cout << endl;
    Number_t<10,16,int>  n2;
    n2 = n + n1;
}