//
// Created by saniya on 13.04.2021.
//

#include <iostream>
#include <vector>
#include <cmath>

namespace  solution
{
    const char BLACK ='1';
    const char WHITE = '0';
    const double DELTA_PHY = 1e-3; // Настраиваемый параметр

    /*
     * Это служебный класс. Он исаользуется для детекции точек пересечения.
     */
    class Circle {
     public:
        static bool IsPoint(const std::vector<std::string>& bits, size_t x, size_t y, double epsilon);
    private:
        static bool InRange(const std::vector<std::string>& bits, int64_t x, int64_t y);
    };

}