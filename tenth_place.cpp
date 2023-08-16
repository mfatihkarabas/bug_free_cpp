#include <iostream>

class foo{

private:
    bool bar;
    bool baz;

public:
    bool isBar(){

        return bar;
    };

    bool isBaz(){

        return baz;
    };
};

bool isCompatible(class foo a, class foo b){

    bool retval = false;

    // BAD (same condition twice - hard to notice)
    retval = ((a.isBar() && b.isBaz()) ||
              (b.isBaz() && a.isBar()));

    //GOOD
    retval = ((a.isBar() && b.isBaz()) ||
              (a.isBaz() && b.isBar()));

    return retval;
}

int main(){

    return 0;
}