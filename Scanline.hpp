//
// Created by saniya on 13.04.2021.
//

#include <vector>
#include <string>

#include "Circle.hpp"

namespace solution
{
    const double EPSILON = 20;

    /*
     * Основной класс для работы
     */
    class Scanline {
    public:
        explicit Scanline(std::vector<std::string>& bits);

        size_t Scan();
    private:
        /*
         * Проверяет текущую колонку
         */
        void CheckColumn(size_t raw);

        /*
         * Проверка, что точка раньше не встречалась
         */
        bool NotFound(size_t x, size_t y);

        static double Dist(const std::pair<size_t, size_t>& first, const std::pair<size_t, size_t>& second);

        std::vector<std::string>& bits_view;
        std::vector<std::pair<size_t, size_t>> cross_points;
    };
}
