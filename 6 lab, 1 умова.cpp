#include <iostream>
#include <string>
#include <cmath>

class Point {
protected:
    double x, y;

public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    virtual ~Point() {}

    void move(double dx, double dy) {
        x += dx;
        y += dy;
    }

    virtual void resize(double factor) = 0;
    virtual void rotate(double angle) = 0;
    virtual void setColor(const std::string& color) = 0;
    virtual void display() const = 0;
};

class Ellipse : public Point {
protected:
    double radiusX, radiusY;
    std::string color;

public:
    Ellipse(double x, double y, double radiusX, double radiusY, const std::string& color = "black")
        : Point(x, y), radiusX(radiusX), radiusY(radiusY), color(color) {}

    void resize(double factor) override {
        radiusX *= factor;
        radiusY *= factor;
    }

    void rotate(double angle) override {
        // Ellipse rotation does not affect its appearance in this simplified model
    }

    void setColor(const std::string& color) override {
        this->color = color;
    }

    void display() const override {
        std::cout << "Ellipse at (" << x << ", " << y << "), radii: ("
            << radiusX << ", " << radiusY << "), color: " << color << "\n";
    }
};

void displayMenu() {
    std::cout << "1. Move Ellipse\n";
    std::cout << "2. Resize Ellipse\n";
    std::cout << "3. Change Color of Ellipse\n";
    std::cout << "4. Display Ellipse\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    Ellipse ellipse(0, 0, 10, 5, "red");
    int choice;
    double dx, dy, factor;
    std::string color;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter dx and dy: ";
            std::cin >> dx >> dy;
            ellipse.move(dx, dy);
            break;

        case 2:
            std::cout << "Enter resize factor: ";
            std::cin >> factor;
            ellipse.resize(factor);
            break;

        case 3:
            std::cout << "Enter new color: ";
            std::cin >> color;
            ellipse.setColor(color);
            break;

        case 4:
            ellipse.display();
            break;

        case 5:
            std::cout << "Exiting...\n";
            break;

        default:
            std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
