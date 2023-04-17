#include <iostream>

using namespace std;

class TwoDimensionalCoordinate {
protected:
    int x;
    int y;

public:
    TwoDimensionalCoordinate(int _x, int _y) : x(_x), y(_y) {}

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    int operator[](int index) const {
        if (index == 0) {
            return x;
        }
        else if (index == 1) {
            return y;
        }
        else {
            throw out_of_range("Index out of range");
        }
    }

    bool operator==(const TwoDimensionalCoordinate& other) const {
        return (x == other.x) and (y == other.y);
    }
};

class ThreeDimensionalCoordinate : public TwoDimensionalCoordinate {
private:
    int z;

public:
    ThreeDimensionalCoordinate(int _x, int _y, int _z) : TwoDimensionalCoordinate(_x, _y), z(_z) {}

    int getZ() const {
        return z;
    }

    int operator[](int index) const {
        if (index == 0) {
            return x;
        }
        else if (index == 1) {
            return y;
        }
        else if (index == 2) {
            return z;
        }
        else {
            throw out_of_range("Index out of range");
        }
    }

    bool operator==(const ThreeDimensionalCoordinate& other) const {
        return (x == other.x) and (y == other.y) and (z == other.z);
    }
};

int main() {
    TwoDimensionalCoordinate point2D(1, 2);
    ThreeDimensionalCoordinate point3D(3, 4, 5);

    // Функции получения отдельной компоненты координаты
    cout << "point2d x cord = " << point2D.getX() << endl; // 1
    cout << "point3d z cord = " << point3D.getZ() << endl; // 5

    // Перегруженная операция доступа по индексу
    cout << point2D[0] << endl; // 1
    cout << point3D[1] << endl; // 4

    // Перегруженная операция сравнения
    TwoDimensionalCoordinate point2D2(1, 2);
    ThreeDimensionalCoordinate point3D2(3, 4, 7);

    if (point2D == point2D2) { cout << "Objects are equal" << endl; }
    else { cout << "Objects are not euqal" << endl; }
    if (point3D == point3D2) { cout << "Objects are equal" << endl; }
    else { cout << "Objects are not euqal" << endl; }


    return 0;
}
