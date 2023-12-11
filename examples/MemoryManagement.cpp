//Memory Leak
void badMemoryLeak(){

    int *ptr = new int;
    //...
}

void goodMemoryLeak(){

    int *ptr = new int;
    //...
    delete ptr;
}

//Null Dereference
void badNullDereference (int *ptr){

    int value = *ptr;
}

void goodNullDereference (int *ptr){

    if (ptr != nullptr){
        int value = *ptr;
    }
}

//Initialization
int badUninitialized(){
    int x;
    return x;
}

int goodUninitialized(){

    int x = 0;
    return x;
}

int betterUninitialized(){

    int x{}; //Available since C++
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
    int arr[5];
    arr[4] = 32;
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