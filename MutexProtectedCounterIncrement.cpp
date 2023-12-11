
#include <iostream>
#include <thread>
#include <mutex>


//Bad Mutex-Protected Counter Increment
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

//Bad Mutex-Protected Counter Increment
int good_counter = 0;
std::mutex counter_mutex;

void goodRaceCondition(){

    for (int i = 0; i < 100000; ++i){

        std::lock_guard <std::mutex> lock(counter_mutex); // Proper sync.
        good_counter++;
    }
}

int main(){

    std::thread t1 (goodRaceCondition);
    std::thread t2 (goodRaceCondition);

    t1.join();
    t2.join();

    std::cout << "Counter: " << good_counter << std::endl;

    return 0;
}