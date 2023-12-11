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