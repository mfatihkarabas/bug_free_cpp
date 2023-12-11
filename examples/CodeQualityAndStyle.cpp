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