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