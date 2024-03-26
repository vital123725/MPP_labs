#include <iostream>
#include <vector>
#include <algorithm> // для функцій min_element, max_element та sort

class Polynomial {
private:
    std::vector<int> coefficients; // Масив коефіцієнтів

public:
    Polynomial(const std::vector<int>& coeffs) : coefficients(coeffs) {}

    int evaluate(int x) {
        int result = 0;
        for (int i = 0; i < coefficients.size(); i++) {
            result += coefficients[i] * pow(x, i);
        }
        return result;
    }

    Polynomial add(const Polynomial& other) {
        std::vector<int> result_coeffs(std::max(coefficients.size(), other.coefficients.size()), 0);
        for (int i = 0; i < result_coeffs.size(); i++) {
            if (i < coefficients.size()) {
                result_coeffs[i] += coefficients[i];
            }
            if (i < other.coefficients.size()) {
                result_coeffs[i] += other.coefficients[i];
            }
        }
        return Polynomial(result_coeffs);
    }

    Polynomial subtract(const Polynomial& other) {
        std::vector<int> result_coeffs(std::max(coefficients.size(), other.coefficients.size()), 0);
        for (int i = 0; i < result_coeffs.size(); i++) {
            if (i < coefficients.size()) {
                result_coeffs[i] += coefficients[i];
            }
            if (i < other.coefficients.size()) {
                result_coeffs[i] -= other.coefficients[i];
            }
        }
        return Polynomial(result_coeffs);
    }

    Polynomial multiply(const Polynomial& other) {
        std::vector<int> result_coeffs(coefficients.size() + other.coefficients.size() - 1, 0);
        for (int i = 0; i < coefficients.size(); i++) {
            for (int j = 0; j < other.coefficients.size(); j++) {
                result_coeffs[i + j] += coefficients[i] * other.coefficients[j];
            }
        }
        return Polynomial(result_coeffs);
    }

    void print() const {
        for (int i = coefficients.size() - 1; i >= 0; i--) {
            if (coefficients[i] != 0) {
                std::cout << coefficients[i];
                if (i > 0) {
                    std::cout << "x^" << i;
                }
                if (i > 0 && i < coefficients.size() - 1) {
                    std::cout << " + ";
                }
            }
        }
        std::cout << std::endl;
    }

    int getMinElement() const {
        return *std::min_element(coefficients.begin(), coefficients.end());
    }

    int getMaxElement() const {
        return *std::max_element(coefficients.begin(), coefficients.end());
    }

    void sortCoefficients() {
        std::sort(coefficients.begin(), coefficients.end());
    }
};

int main() {
    std::vector<int> coeffs1 = { 1, 2, 3 }; // Поліном 1 + 2x + 3x^2
    std::vector<int> coeffs2 = { 3, 4, 5 }; // Поліном 3 + 4x + 5x^2

    Polynomial poly1(coeffs1);
    Polynomial poly2(coeffs2);

    std::cout << "Evaluation of poly1 at x = 2: " << poly1.evaluate(2) << std::endl;
    std::cout << "Evaluation of poly2 at x = 3: " << poly2.evaluate(3) << std::endl;

    Polynomial poly_sum = poly1.add(poly2);
    std::cout << "Sum of polynomials: ";
    poly_sum.print();

    Polynomial poly_diff = poly1.subtract(poly2);
    std::cout << "Difference of polynomials: ";
    poly_diff.print();

    Polynomial poly_prod = poly1.multiply(poly2);
    std::cout << "Product of polynomials: ";
    poly_prod.print();

    std::cout << "Minimum element of poly1: " << poly1.getMinElement() << std::endl;
    std::cout << "Maximum element of poly1: " << poly1.getMaxElement() << std::endl;

    poly1.sortCoefficients();
    std::cout << "Sorted coefficients of poly1: ";
    poly1.print();

    return 0;
}
