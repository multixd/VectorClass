//
//  main.cpp
//  VectorClass
//
//  Created by Vincent Liang on 12/15/19.
//  Copyright © 2019 Vincent Liang. All rights reserved.
//

#include "Vector.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    Vector<int> hi(1,0);
    
    hi.push_back(25);
    hi.push_back(50);
    hi.push_back(75);
    hi.push_back(100);
    hi.push_back(125);
    
    for(int i = 0; i < hi.size(); ++i) {
        std::cout << hi.at(i) << " ";
    }
    std::cout << std::endl;
    
    hi.insert(3,150);
    for(int i = 0; i < hi.size(); ++i) {
        std::cout << hi.at(i) << " ";
    }
    std::cout << std::endl;
    
    hi.erase(3);
    for(int i = 0; i < hi.size(); ++i) {
        std::cout << hi.at(i) << " ";
    }
    
    std::cout << std::endl;
    
    
    Vector<int> bye; //= hi;
    bye = hi;
    for(int i = 0; i < bye.size(); ++i) {
          std::cout << bye.at(i) << " ";
      }
    return 0;
}
