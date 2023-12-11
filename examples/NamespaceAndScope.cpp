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