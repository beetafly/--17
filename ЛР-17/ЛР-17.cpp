// ЛР-17.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdexcept>

class Room {
private:
    double length;
    double width;
    double height;
    int windows;

    void validate() {
        if (length <= 0 || width <= 0 || height <= 0 || windows < 0) {
            throw std::invalid_argument("Invalid values for room dimensions or number of windows.");
        }
    }

public:
    Room(double length, double width, double height, int windows)
        : length(length), width(width), height(height), windows(windows) {
        validate();
    }

    double getLength() const {
        return length;
    }

    double getWidth() const {
        return width;
    }

    double getHeight() const {
        return height;
    }

    int getWindows() const {
        return windows;
    }

    double calculateArea() const {
        return length * width;
    }

    double calculateVolume() const {
        return length * width * height;
    }
};

class DecoratedRoom : public Room {
public:
    DecoratedRoom(double length, double width, double height, int windows)
        : Room(length, width, height, windows) {}

    double calculateWallpaperNeeded(double rollWidth, double rollLength) const {
        double wallArea = 2 * (getLength() + getWidth()) * getHeight();
        double windowArea = getWindows() * 1.5;  // Assuming average window area is 1.5 square meters
        double totalAreaToCover = wallArea - windowArea;

        double rollCoverage = rollWidth * rollLength;
        return totalAreaToCover / rollCoverage;
    }
};

int main() {
    try {
        Room room(5.0, 4.0, 3.0, 2);
        std::cout << "Room area: " << room.calculateArea() << " square meters" << std::endl;
        std::cout << "Room volume: " << room.calculateVolume() << " cubic meters" << std::endl;

        DecoratedRoom decoratedRoom(5.0, 4.0, 3.0, 2);
        double rollWidth = 0.53; // Width of wallpaper roll in meters
        double rollLength = 10.0; // Length of wallpaper roll in meters
        std::cout << "Wallpaper needed: " << decoratedRoom.calculateWallpaperNeeded(rollWidth, rollLength) << " rolls" << std::endl;
    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
