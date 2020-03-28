//
//  Vector.hpp
//  VectorClass
//
//  Created by Vincent Liang on 12/15/19.
//  Copyright © 2019 Vincent Liang. All rights reserved.
//

#ifndef Vector_hpp
#define Vector_hpp

#include <stdio.h>
#include <stdexcept>
#include <iostream>
template <class T>
class Vector {
private:
    unsigned sz;
    unsigned cap;
    T *data;
    
public:

    Vector(){
        sz  = 0;
        cap = 0;
        data = nullptr;
    }
    
    Vector(unsigned size, T value){
        sz = size;
        cap  = size;
        data =  new T[size];
        for(unsigned i = 0; i < size; ++i) {
           data[i] = value;
        }
    }
    
    Vector(const Vector& old) {
        
        cap = old.capacity();
        data  = new T[cap];
        sz  = old.size();
        for(unsigned i = 0; i < size(); ++i) {
           data[i] = old.at(i);
        }
    }
    
    Vector& operator =(const Vector& old)  {
        if(this != &old) {
            if(data!= nullptr)  {
                delete [] data;
            }
            sz = old.size();
            cap  =  old.capacity();
            data  = new T[cap];
            for(unsigned i = 0; i < size(); ++i) {
               data[i] = old.at(i);
            }
        }
            return *this;
        
    }
    
    ~Vector(){
        delete [] data;
    }
    
    unsigned size() const{
        return sz;
    }
    unsigned capacity() const{
        return cap;
    }
    
    bool empty() const{
        return sz==0;
    }
    
    const T &at(unsigned index) const{
        try {
            if(sz <= index) {
                throw std::out_of_range("Vector:at_range_check");
            }
        }
        
        catch (std::out_of_range& except) {
            std::cout << except.what() << std::endl;
        }
        return data[index];
    }
    const T & front() const{
        return data[0];
    }
    const T & back() const{
        return data[sz-1];
    }
    
    void expand(){
        cap = 2*cap;
        if(cap == 0) {
            cap = 1;
            data = new T[cap];
            return;
        }
        T* temp = new T[cap];
        for(unsigned i = 0; i < sz; ++i) {
            temp[i] = data[i];
        }
        delete []data;
        data= temp;
    }
    
    void expand(unsigned amount){
        cap = amount +cap;
        
        T* temp = new T[cap];
        for(unsigned i = 0; i < sz; ++i) {
            temp[i] = data[i];
        }
        if(data != nullptr) {
            delete []data;
        }
        data= temp;
    }
    
    void insert(unsigned index, T value){
        try {
            if(index >= sz){
                throw std::out_of_range("Vector:at_range_check");
            }
            
            ++sz;
            if(sz>=cap) {
                expand();
            }
            for(unsigned i = sz-1; i >=index; --i) {
                data[i+1] = data[i];
            }
            data[index] = value;
        }
        catch (std::out_of_range& except) {
            std::cout << except.what() << std::endl;
        }
    }
    
    void erase(unsigned index){
        try {
            if(index >= sz) {
                throw std::out_of_range("Vector:at_range_check");
            }
            
            if(sz ==  0)  {
                return;
            }
            
            for(unsigned i = index; i < sz; ++i) {
                data[i] = data[i+1];
            }
            --sz;
        }
        catch (std::out_of_range& except) {
            std::cout << except.what() << std::endl;
        }
    }
    void push_back(T value){
        if(sz >= cap) {
               expand();
           }
           ++sz;
           data[sz-1] = value;
    }
    void pop_back(){
        if(sz ==0) {
            return;
        }
        --sz;
    }
    void clear(){
        sz = 0;
    }
    void resize(unsigned size, T value){
        if(sz > size) {
               sz = size;
           }
           
           if(sz < size) {
               if(2*cap > size-cap) {
                   expand();
               }
               else {
                   expand(size-cap);
               }
               
               for(unsigned i = sz; i < size; ++i) {
                   data[i] = value;
               }
               sz = size;
           }
    }
    void reserve(unsigned n){
        if(2*cap > n-cap) {
               expand();
           }
           else {
               expand(n-cap);
           }
    }
    void assign(unsigned n, T value){
        if(n > cap) {
            if(2*cap > n-cap) {
                cap = 2*cap;
            }
            else {
                cap = cap +(n-cap);
            }
        }
        delete [] data;
        data= new T[cap];
        sz = n;
        
        for(unsigned i = 0; i < sz; ++i) {
            data[i] = value;
        }
    }
    
};

#endif /* Vector_hpp */
