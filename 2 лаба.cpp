#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846

using namespace std;

// Звичайна функція для обчислення об'єму та площі бічної поверхні прямого кругового конуса
void cone_properties(double l, double h, double* volume, double* lateral_surface_area) {
    *volume = (1.0 / 3.0) * M_PI * pow(l, 2) * h;
    double slant_height = sqrt(pow(l, 2) + pow(h, 2));
    *lateral_surface_area = M_PI * l * slant_height;
}

// Шаблон функції для обчислення об'єму та площі бічної поверхні прямого кругового конуса
template<typename T>
void cone_properties_template(T l, T h, T* volume, T* lateral_surface_area) {
    *volume = (1.0 / 3.0) * M_PI * pow(l, 2) * h;
    T slant_height = sqrt(pow(l, 2) + pow(h, 2));
    *lateral_surface_area = M_PI * l * slant_height;
}

int main() {
    double l_value = 3.0;
    double h_value = 4.0;
    double result_volume, result_lateral_surface_area;

    // Виклик звичайної функції
    cone_properties(l_value, h_value, &result_volume, &result_lateral_surface_area);
    cout << "Volume of the right circular cone (Regular Function): " << result_volume << endl;
    cout << "Lateral surface area of the right circular cone (Regular Function): " << result_lateral_surface_area << endl;

    // Виклик шаблону функції з типом double
    cone_properties_template(l_value, h_value, &result_volume, &result_lateral_surface_area);
    cout << "Volume of the right circular cone (Template Function): " << result_volume << endl;
    cout << "Lateral surface area of the right circular cone (Template Function): " << result_lateral_surface_area << endl;

    return 0;
}
