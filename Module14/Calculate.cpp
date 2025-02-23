#include "Calculate.h"

void calculate(const std::function<void()>& operation) {
    try {
        operation(); // Выполнение переданной лямбды
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument error: " << e.what() << std::endl;
    }
    catch (const std::domain_error& e) {
        std::cerr << "Domain error: " << e.what() << std::endl;
    }
    catch (const InvalidLogArgument& e) {
        std::cerr << "Logarithm error: " << e.what() << std::endl;
    }
    catch (const InvalidRadiusArgument& e) {
        std::cerr << "Circle area error: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "General exception: " << e.what() << std::endl;
    }
}
