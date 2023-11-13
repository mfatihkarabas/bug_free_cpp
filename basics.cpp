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

// Bad Naming Convention
int badNamingConvention() {
    int a_b_c;
    return a_b_c;
}

// Good Naming Convention
int goodNamingConvention() {
    int meaningful_variable_name;
    return meaningful_variable_name;
}

// Using Magic Numbers
int badMagicNumbers() {
    int result = 42 * 7;
    return result;
}

// Avoiding Magic Numbers
int goodMagicNumbers() {
    const int weeks_in_a_year = 52;
    int result = 42 * weeks_in_a_year;
    return result;
}

// Raw Pointers Ownership
void badRawPointersOwnership() {
    int* ptr = new int;
    // Ownership transfer is unclear.
}

// Smart Pointers Ownership learn
void goodSmartPointersOwnership() {
    std::unique_ptr<int> ptr = std::make_unique<int>();
    // Ownership is clearly managed.
}

// Unused Variable
void badUnusedVariable() {
    int unused_variable = 5;
    // 'unused_variable' is not used.
}

// Using Variables Before Initialization
int badUseBeforeInitialization() {
    int x;
    return x + 5;
}

// Range-based For Loop
void badRangeBasedForLoop() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    for (int i = 0; i < numbers.size(); ++i) {
        // Process each number using index.
    }
}

void goodRangeBasedForLoop() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    for (const auto& num : numbers) {
        // Process each number.
    }
}

// Global Variables
int badGlobalVariable;
void badGlobalVariableUsage() {
    // Dependence on global state.
    badGlobalVariable = 10;
}

int goodGlobalVariableUsage() {
    int localVariable = 10; // Avoid using global state.
    return localVariable;
}

// Avoiding Magic Numbers
int badMagicNumbers() {
    int result = 42 * 7;
    // Magic number without explanation.
    return result;
}

int goodMagicNumbers() {
    const int weeks_in_a_year = 52;
    int result = 42 * weeks_in_a_year;
    // Magic number replaced with a named constant.
    return result;
}

// Raw Pointers Ownership
void badRawPointersOwnership() {
    int* ptr = new int;
    // No ownership transfer or clear delete.
}

void goodRawPointersOwnership() {
    int* ptr = new int;
    // Use smart pointers or delete appropriately.
    delete ptr;
}

// Unused Function Parameter
void badUnusedParameter(int x) {
    // 'x' is not used.
}

void goodUnusedParameter([[maybe_unused]] int x) {
    // 'x' is marked as maybe_unused or used.
}

// Using Exceptions for Flow Control
void badExceptionFlowControl() {
    try {
        // Code that relies on exceptions for flow control.
        throw std::runtime_error("Exception for flow control");
    } catch (const std::exception& ex) {
        // Handling exceptions as part of normal program flow.
    }
}

// Proper Exception Usage
void goodExceptionUsage() {
    try {
        // Code that throws exceptions for exceptional situations.
        throw std::runtime_error("This is a real exception");
    } catch (const std::exception& ex) {
        // Properly handling the exceptional situation.
        std::cerr << "Exception caught: " << ex.what() << std::endl;
    }
}

// Use of Global Constants
const double badGlobalConstant = 3.14;
void badModifyGlobalConstant() {
    // Modifying a global constant.
    // badGlobalConstant = 2.71; // Uncommenting this line will cause a compilation error.
}

void goodGlobalConstantUsage() {
    // Using a global constant without modification.
    double result = badGlobalConstant * 2;
}

// String Concatenation
std::string badStringConcatenation(const std::string& str1, const std::string& str2) {
    return str1 + str2; // Inefficient for large strings.
}

std::string goodStringConcatenation(const std::string& str1, const std::string& str2) {
    return str1.append(str2); // More efficient for large strings.
}

// Manual Memory Management
void badManualMemoryManagement() {
    char* buffer = new char[100];
    // ...
    delete[] buffer; // Manual memory management is error-prone.
}

// Using RAII
void goodRAII() {
    std::vector<char> buffer(100);
    // ...
    // Memory is automatically managed when 'buffer' goes out of scope.
}

// Unused Code
int badUnusedCode() {
    int x = 5;
    return x * 2; // The result is not used. badUnusedCode();
}

int goodUnusedCode() {
    int x = 5;
    return x * 2; // The result is used. bar = goodUnusedCode();
}

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

// Function Length
void badLongFunction() {
    // A long and complex function.
    // ...
}

void goodShortFunctions() {
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

std::string goodPassByReference(const std::string& source) {
    // Avoiding unnecessary copies by using references.
    return source;
}

// Global Functions
namespace badGlobalFunction {
    void function1() {
        // Implementation of function1.
    }
}

namespace goodNamespaceEncapsulation {
    void function1() {
        // Implementation of function1.
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

// Use of goto Statement
void badGotoStatement() {
    int x = 0;
    // ...
    goto cleanup; // Unstructured control flow.
cleanup:
    // Cleanup code.
}

// Avoiding Goto
void goodAvoidingGoto() {
    int x = 0;
    // ...
    // Structured control flow without goto.
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

// Bad Comment
void badComment() {
    // This function does something.
    int x = 5;
    std::cout << x << std::endl;
}

// Good Comment
void goodComment() {
    // Initialize variable 'x' to 5 and print its value.
    int x = 5;
    std::cout << x << std::endl;
}

// Using using namespace in Global Scope
namespace badUsingNamespace {
    using namespace std; // Avoid using namespace in global scope.
    void function1() {
        cout << "Function 1" << endl;
    }
}

namespace goodNamespaceUsage {
    void function1() {
        // Using specific items from the namespace.
        std::cout << "Function 1" << std::endl;
    }
}

// Not Using const Correctly
void badConstUsage() {
    int x = 5;
    const int* ptr = &x;
    // Modifying the value pointed to by 'ptr'.
    // *ptr = 10; // Uncommenting this line will cause a compilation error.
}

void goodConstUsage() {
    int x = 5;
    const int* ptr = &x;
    // Cannot modify the value pointed to by 'ptr'.
    int y = *ptr;
}

// Returning a Reference to a Local Variable
const std::string& badReturnReferenceToLocalVariable() {
    std::string localVariable = "Hello";
    return localVariable; // Returning a reference to a local variable.
}

// Avoiding Returning References to Local Variables
std::string goodAvoidReturningReferenceToLocalVariable() {
    std::string localVariable = "Hello";
    return localVariable; // Returning by value.
}

// Global Constants Without Namespace
const double badGlobalConstantWithoutNamespace = 3.14;
void badUsageGlobalConstantWithoutNamespace() {
    // Using global constants without a namespace.
    double result = badGlobalConstantWithoutNamespace * 2;
}

namespace goodGlobalConstantWithNamespace {
    const double globalConstant = 3.14;
    void goodUsageGlobalConstantWithNamespace() {
        // Using global constants with a namespace.
        double result = globalConstant * 2;
    }
}

// Using Macros for Constants
#define BAD_PI 3.14
void badMacroForConstants() {
    double result = BAD_PI * 2;
}

// Avoiding Macros for Constants
const double GOOD_PI = 3.14;
void goodAvoidMacroForConstants() {
    double result = GOOD_PI * 2;
}

// Global Function without Namespace
int badGlobalFunction() {
    // Function in global scope without a namespace.
    return 42;
}

namespace goodGlobalFunctionWithNamespace {
    int goodGlobalFunction() {
        // Function in global scope with a namespace.
        return 42;
    }
}

// Not Using Inline Functions
inline int badNotUsingInlineFunction(int x, int y) {
    // Not using inline for small functions.
    return x + y;
}

// Using Inline Functions
inline int goodUsingInlineFunction(int x, int y) {
    // Using inline for small functions.
    return x + y;
}

// Using C-Style Cast
int badCStyleCast(double value) {
    return (int)value; // Using C-style cast.
}

// Avoiding C-Style Cast
int goodAvoidCStyleCast(double value) {
    return static_cast<int>(value); // Using C++ style cast.
}

// Using 'using' Declarations
namespace badUsingDeclarations {
    using std::cout;
    using std::endl;
    void function1() {
        // Using 'using' declarations for specific items.
        cout << "Function 1" << endl;
    }
}

// Avoiding 'using' Declarations
namespace goodAvoidUsingDeclarations {
    void function1() {
        // Avoiding 'using' declarations to prevent naming conflicts.
        std::cout << "Function 1" << std::endl;
    }
}

// Returning a Pointer to a Local Variable
int* badReturnPointerToLocalVariable() {
    int localVariable = 42;
    return &localVariable; // Returning a pointer to a local variable.
}

// Avoiding Returning Pointers to Local Variables
int* goodAvoidReturningPointerToLocalVariable() {
    int* dynamicVariable = new int(42);
    return dynamicVariable; // Returning a pointer to dynamically allocated memory.
}

// Using 'endl' for Line Breaks
void badUsingEndlForLineBreaks() {
    std::cout << "Hello" << std::endl; // Unnecessary flushing.
}

// Avoiding 'endl' for Line Breaks
void goodAvoidUsingEndlForLineBreaks() {
    std::cout << "Hello\n"; // Using '\n' for line breaks.
}

// Function with Too Many Parameters
void badFunctionWithTooManyParameters(int a, int b, int c, int d, int e) {
    // Function with too many parameters.
}

// Avoiding Functions with Too Many Parameters
struct GoodParameters {
    int a, b, c, d, e;
};

void goodAvoidFunctionWithTooManyParameters(const GoodParameters& params) {
    // Function with a struct or class parameter.
}

// Using Non-const Global Variables
int badNonConstGlobalVariable;
void badModifyNonConstGlobalVariable() {
    badNonConstGlobalVariable = 10; // Modifying non-const global variable.
}

const int goodConstGlobalVariable = 42;
void goodAvoidModifyConstGlobalVariable() {
    // Cannot modify const global variable.
    // goodConstGlobalVariable = 10; // Uncommenting this line will cause a compilation error.
}

// Unused Includes
#include <cmath> // Unused include.
double badUnusedInclude() {
    return 2.0 * M_PI;
}

// Avoiding Unused Includes
#include <cmath>
double goodAvoidUnusedInclude() {
    return 2.0 * M_PI;
}

#include <iostream>
#include <vector>
#include <algorithm>

// Using Global Variables
int badGlobalVariable = 10;
int badGlobalVariableUsage() {
    return badGlobalVariable; // Dependence on global state.
}

// Avoiding Global Variables
int goodAvoidGlobalVariable() {
    int localVariable = 10; // Prefer local variables over global state.
    return localVariable;
}

// Using std::endl for Line Breaks
void badUsingStdEndlForLineBreaks() {
    std::cout << "Hello" << std::endl; // Unnecessary flushing.
}

// Avoiding std::endl for Line Breaks
void goodAvoidUsingStdEndlForLineBreaks() {
    std::cout << "Hello\n"; // Using '\n' for line breaks.
}

// Unused Parameters
void badUnusedParameters(int x, int y) {
    // Unused parameters in the function.
}

void goodAvoidUnusedParameters([[maybe_unused]] int x, [[maybe_unused]] int y) {
    // Parameters marked as maybe_unused or used.
}

// Not Using constexpr
int badNotUsingConstexpr() {
    const int size = 10;
    int arr[size]; // Size is not known at compile time.
    return sizeof(arr);
}

// Using constexpr
constexpr int goodUsingConstexpr() {
    const int size = 10;
    return size * size; // Size is known at compile time.
}

// Using static for Internal Linkage
static int badStaticInternalLinkage = 5; // Each translation unit gets its own copy.
int badStaticInternalLinkageUsage() {
    return badStaticInternalLinkage;
}

// Using unnamed namespace for Internal Linkage
namespace goodUnnamedNamespaceInternalLinkage {
    int goodStaticInternalLinkage = 5; // Internal linkage within the translation unit.
}

int goodUnnamedNamespaceInternalLinkageUsage() {
    return goodUnnamedNamespaceInternalLinkage::goodStaticInternalLinkage;
}

// Using #define for Constants
#define BAD_PI 3.14
double badDefineForConstants() {
    return BAD_PI * 2; // Using #define for constants.
}

// Avoiding #define for Constants
const double GOOD_PI = 3.14;
double goodAvoidDefineForConstants() {
    return GOOD_PI * 2; // Using const for constants.
}

// Using 'new' and 'delete' for Dynamic Arrays
void badNewDeleteDynamicArray() {
    int* arr = new int[10];
    // ...
    delete[] arr; // Manual memory management for dynamic arrays.
}

// Using std::vector for Dynamic Arrays
void goodVectorDynamicArray() {
    std::vector<int> arr(10);
    // ...
    // Automatic memory management with std::vector.
}

// Using 'NULL' for Null Pointers
void badUsingNULLForNullPointers() {
    int* ptr = NULL; // Using NULL instead of nullptr.
}

// Avoiding Using NULL for Null Pointers
void goodAvoidUsingNULLForNullPointers() {
    int* ptr = nullptr; // Using nullptr for null pointers.
}

// Using 'rand()' for Random Numbers
int badRandForRandomNumbers() {
    int randomValue = rand(); // Limited randomness and biased distribution.
    return randomValue;
}

// Using <random> for Random Numbers
int goodRandomLibraryForRandomNumbers() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1, 6);
    return distribution(gen); // Better randomness and distribution.
}

// Using 'goto' Statement
void badGotoStatement() {
    int x = 0;
    // ...
    goto cleanup; // Unstructured control flow.
cleanup:
    // Cleanup code.
}

// Avoiding 'goto' Statement
void goodAvoidingGoto() {
    int x = 0;
    // ...
    // Structured control flow without goto.
}

// Global Functions with Side Effects
int badGlobalFunctionWithSideEffects() {
    std::cout << "This function has side effects." << std::endl;
    return 42;
}

// Avoiding Global Functions with Side Effects
int goodAvoidGlobalFunctionWithSideEffects() {
    // Functions should ideally have no side effects.
    return 42;
}

// Using 'using namespace' in Header Files
// bad_header.h
namespace badNamespace {
    void function1();
}

// bad_header.cpp
#include "bad_header.h"
using namespace badNamespace; // Avoid using namespace in header files.

void badNamespaceFunction1() {
    function1(); // Namespace pollution in the global scope.
}

// Avoiding 'using namespace' in Header Files
// good_header.h
namespace goodNamespace {
    void function1();
}

// good_header.cpp
#include "good_header.h"

void goodNamespaceFunction1() {
    goodNamespace::function1(); // Explicitly use the namespace.
}

