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

// String Concatenation
std::string badStringConcatenation(const std::string& str1, const std::string& str2) {
    return str1 + str2; // Inefficient for large strings.
}

std::string goodStringConcatenation(const std::string& str1, const std::string& str2) {
    return str1.append(str2); // More efficient for large strings.
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

// Not Using Inline Functions
inline int badNotUsingInlineFunction(int x, int y) {
    // Not using inline for small functions.
    for (int i = 0; i < y; i++){

        x++;
    }
    return x;
}

inline int goodUsingInlineFunction(int x, int y) {
    // Using inline for small functions.
    return x + y;
}

// Using C-Style Cast
int badCStyleCast(double value) {
    return (int)value; // Using C-style cast.
}

int goodAvoidCStyleCast(double value) {
    return static_cast<int>(value); // Using C++ style cast.
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

// Function with Too Many Parameters
void badFunctionWithTooManyParameters(int a, int b, int c, int d, int e) {
    // Function with too many parameters.
}

struct GoodParameters {
    int a, b, c, d, e;
};

void goodAvoidFunctionWithTooManyParameters(const GoodParameters& params) {
    // Function with a struct or class parameter.
}

// Using 'rand()' for Random Numbers
int badRandForRandomNumbers() {
    int randomValue = rand(); // Limited randomness and biased distribution.
    return randomValue;
}

int goodRandomLibraryForRandomNumbers() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1, 6);
    return distribution(gen); // Better randomness and distribution.
}

// Using 'NULL' for Null Pointers
void badUsingNULLForNullPointers() {
    int* ptr = NULL; // Using NULL instead of nullptr.
}

void goodAvoidUsingNULLForNullPointers() {
    int* ptr = nullptr; // Using nullptr for null pointers.
}

// Using 'goto' Statement
void badGotoStatement() {
    int x = 0;
    // ...
    goto cleanup; // Unstructured control flow.
cleanup:
    // Cleanup code.
}

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

int goodAvoidGlobalFunctionWithSideEffects() {
    // Functions should ideally have no side effects.
    return 42;
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

// Using 'endl' for Line Breaks
void badUsingEndlForLineBreaks() {
    std::cout << "Hello" << std::endl; // Unnecessary flushing.
}

// Avoiding 'endl' for Line Breaks
void goodAvoidUsingEndlForLineBreaks() {
    std::cout << "Hello\n"; // Using '\n' for line breaks.
}

// Unused Includes
#include <cmath> // Unused include.
double badUnusedInclude() {
    return 2.0 * 3.14;
}

// Avoiding Unused Includes
#include <cmath>
double goodAvoidUnusedInclude() {
    return 2.0 * M_PI;
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