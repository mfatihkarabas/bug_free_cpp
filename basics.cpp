#include <iostream>
#include <stdexcept>

// Memory Leak
void badMemoryLeak(){

    int *ptr = new int;
    //...
}

void goodMemoryLeak(){

    int *ptr = new int;
    //...
    delete ptr;
}

// Null Pointer Dereference
void badNullDereference (int *ptr){

    int value = *ptr;
}

void goodNullDereference (int *ptr){

    if (ptr != nullptr){
        int value = *ptr;
    }
}

//Uninitialized Variable
int badUninitialized(){
    int x;
    return x;
}

int goodUninitialized(){

    int x = 0;
    return x;
}

//Initialization Overflow
int badInitializationOverflow(){
    short int x = 99999;
    return x;
}

int goodInitializationOverflow(){
    short int x {99999};
    return x;
}

//Buffer Overflow
void badBufferOverflow(){

    int arr[5];
    arr[5] = 32;
}

void goodBufferOverflow(){

}

//Unhandled Exceptions
void badUnhandledExceptions(){

    try{

        throw std::runtime_error("An exception occured.");
        
    } catch (...) {

        //No handling of the exception.
    }
}

void goodUnhandledExceptions(){

    try{

        throw std::runtime_error("An exception occured.");
        
    } catch (const std::exception &ex) {

        std::cerr << "Exception caught:" << ex.what() << std::endl;
    }
}

//Resource Management
void badResourceManagement(){

    FILE *file = fopen("data.txt", "r");
    //...
    //Missing fclose(file) to relase resources.
}

void goodResourceManagement(){

    FILE *file = fopen("data.txt", "r");
    if(file){
        //...
        fclose(file);
    }
}

//Division by Zero
double badDivisionByZero (double x, double y){

    return x/y;
}

double goodDivisionByZero (double x, double y){

    if (y != 0){

        return x/y;

    } else {

        return 0.0;
    }

}