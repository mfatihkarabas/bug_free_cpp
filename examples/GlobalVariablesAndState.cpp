// Using Global Variables
int badGlobalVariable = 10;
int badGlobalVariableUsage() {
    return badGlobalVariable; // Dependence on global state.
}

int goodGlobalVariableUsage() {
    int localVariable = 10; // Prefer local variables over global state.
    return localVariable;
}

// Use of Global Constants
const double globalConstant = 3.14;
void badModifyGlobalConstant() {
    // Modifying a global constant.
    // globalConstant = 2.71; // Uncommenting this line will cause a compilation error.
}

void goodGlobalConstantUsage() {
    // Using a global constant without modification.
    double result = globalConstant * 2;
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