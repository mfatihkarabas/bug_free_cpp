#include <iostream>
#include <thread>

int bad_counter = 0;

void badRaceCondition(){

    for (int i = 0; i<100000; ++i){
        bad_counter++; //Race condition on shared variable.
    }
}

int main(){

    std::thread t1 (badRaceCondition);
    std::thread t2 (badRaceCondition);

    t1.join();
    t2.join();

    std::cout << "Counter: " << bad_counter << std::endl;

    return 0;
}