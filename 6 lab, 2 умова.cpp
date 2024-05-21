#include <iostream>
#include <cmath>

class Vector3D {
private:
    double x, y, z;

public:
    // Конструктор за замовчуванням
    Vector3D() : x(0), y(0), z(0) {}

    // Конструктор з параметрами
    Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

    // Конструктор копії
    Vector3D(const Vector3D& other) : x(other.x), y(other.y), z(other.z) {}

    // Перевантаження оператора присвоювання
    Vector3D& operator=(const Vector3D& other) {
        if (this == &other) {
            return *this;
        }
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    // Перевантаження оператора додавання
    Vector3D operator+(const Vector3D& other) const {
        return Vector3D(x + other.x, y + other.y, z + other.z);
    }

    // Векторний добуток
    Vector3D operator*(const Vector3D& other) const {
        return Vector3D(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }

    // Перевантаження оператора порівняння
    bool operator==(const Vector3D& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    bool operator!=(const Vector3D& other) const {
        return !(*this == other);
    }

    // Виведення вектора
    friend std::ostream& operator<<(std::ostream& os, const Vector3D& vec) {
        os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
        return os;
    }

    // Метод для відображення вектора (альтернативний спосіб)
    void display() const {
        std::cout << *this << std::endl;
    }
};

int main() {
    // Створення векторів
    Vector3D v1(1.0, 2.0, 3.0);
    Vector3D v2(4.0, 5.0, 6.0);
    Vector3D v3;

    // Використання конструктора копії
    Vector3D v4 = v1;

    // Додавання векторів
    v3 = v1 + v2;
    std::cout << "v1 + v2 = " << v3 << std::endl;

    // Векторний добуток
    Vector3D v5 = v1 * v2;
    std::cout << "v1 * v2 = " << v5 << std::endl;

    // Перевірка оператора порівняння
    std::cout << "v1 == v4: " << (v1 == v4 ? "True" : "False") << std::endl;
    std::cout << "v1 != v2: " << (v1 != v2 ? "True" : "False") << std::endl;

    return 0;
}
