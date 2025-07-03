#include <iostream>
#include <cmath>

double area(double radius) {
    return M_PI * radius * radius;
}

double area(double width, double height, char type) {
    return width * height;
}

double area(double base, double height) {
    return 0.5 * base * height;
}

int area(int side) {
    return side * side;
}

bool isValid(double value) {
    return value >= 0;
}

int main() {
    int choice;
    std::cout << "Select a shape to calculate area:\n";
    std::cout << "1. Circle\n";
    std::cout << "2. Rectangle\n";
    std::cout << "3. Triangle\n";
    std::cout << "4. Square\n";
    std::cout << "Enter your choice (1-4): ";
    std::cin >> choice;

    switch (choice) {
        case 1: {
            double radius;
            std::cout << "Enter radius: ";
            std::cin >> radius;
            if (!isValid(radius)) {
                std::cout << "Invalid input. Radius cannot be negative.\n";
                break;
            }
            std::cout << "Area of Circle = " << area(radius) << endl;
            break;
        }
        case 2: {
            double width, height;
            std::cout << "Enter width: ";
            std::cin >> width;
            std::cout << "Enter height: ";
            std::cin >> height;
            if (!isValid(width) || !isValid(height)) {
                std::cout << "Invalid input. Width and height must be non-negative.\n";
                break;
            }
            std::cout << "Area of Rectangle = " << area(width, height, 'r') << endl;
            break;
        }
        case 3: {
            double base, height;
            std::cout << "Enter base: ";
            std::cin >> base;
            std::cout << "Enter height: ";
            std::cin >> height;
            if (!isValid(base) || !isValid(height)) {
                std::cout << "Invalid input. Base and height must be non-negative.\n";
                break;
            }
            std::cout << "Area of Triangle = " << area(base, height) << endl;
            break;
        }
        case 4: {
            int side;
            std::cout << "Enter side length: ";
            std::cin >> side;
            if (side < 0) {
                std::cout << "Invalid input. Side length must be non-negative.\n";
                break;
            }
            std::cout << "Area of Square = " << area(side) << endl;
            break;
        }
        default:
            std::cout << "Invalid choice.\n";
    }

    return 0;
}
