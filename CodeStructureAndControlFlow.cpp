// Nested Loops
void badNestedLoops() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 5; ++j) {
            // Nested loops can be harder to understand.
        }
    }
}

void goodNestedLoops() {
    for (int i = 0; i < 10; ++i) {
        // Separating into functions or using better abstractions.
    }
}

// Long Functions
void badLongFunction() {
    // A long and complex function.
    // ...
}

void goodLongFunctions() {
    // Breaking down functionality into smaller functions.
    // Each function does one thing.
}


// Global State
int badGlobalState = 0;
void badModifyGlobalState() {
    badGlobalState = 42; // Modifying global state.
}

int goodLocalState() {
    int localState = 0; // Localized state.
    return localState;
}

// Manual Array Management
void badManualArrayManagement() {
    int* arr = new int[10];
    // ...
    delete[] arr; // Manual array management is error-prone.
}

// Using std::vector
void goodVectorUsage() {
    std::vector<int> arr(10);
    // ...
    // Automatic memory management with std::vector.
}


// Copying Large Objects
std::string badCopyLargeObjects(const std::string& source) {
    std::string result = source; // Creates a copy of the entire string.
    return result;
}

std::string goodCopyLargeObjects(const std::string& source) {
    // Avoiding unnecessary copies by using references.
    return source;
}

//Namespace Naming
namespace badNamespaceNaming {
    void function1() {
        // This function is exposed globally without proper encapsulation.
        // Implementation of function1 is accessible from anywhere in the code.
    }
}

// Example 2: Encapsulated Function in a Namespace

namespace goodNamespaceNaming {
    void function1() {
        // This function is encapsulated within a namespace.
        // Implementation of function1 is localized and accessed through the namespace.
    }
}


// Multiple Return Statements
int badMultipleReturnStatements(int x) {
    if (x > 0) {
        return x;
    } else {
        return 0;
    }
}

int goodSingleReturnStatement(int x) {
    int result = 0;
    if (x > 0) {
        result = x;
    }
    return result;
}

// Mutable Lambda Capture
void badMutableLambdaCapture() {
    int x = 5;
    auto lambda = [x]() mutable {
        // Modifying the captured variable inside a non-mutable lambda.
        x = 10;
    };
    lambda();
}

// Avoiding Mutable Lambda Capture
void goodAvoidingMutableLambdaCapture() {
    int x = 5;
    auto lambda = [x]() {
        // Not modifying the captured variable inside a non-mutable lambda.
        // x = 10; // Uncommenting this line will cause a compilation error.
    };
    lambda();
}