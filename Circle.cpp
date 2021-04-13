//
// Created by saniya on 13.04.2021.
//

#include "Circle.hpp"

namespace solution {
    bool Circle::IsPoint(const std::vector<std::string> &bits, size_t x, size_t y, double epsilon) {
        /*
         * Функция IsPoint строит окружность с центром в (x, y) радиусом epsilon и проверяет, располагается ли какая-либо
         * точка пересечения отрезков вблизи (x, y)
         */
        double angle = 0;
        bool black = false;
        double start_angle, end_angle, mean_angle;
        int64_t new_x, new_y;
        while (angle < M_PI) {
            new_x = static_cast<int64_t>(static_cast<double>(x) + epsilon * cos(angle));
            new_y = static_cast<int64_t>(static_cast<double>(y) + epsilon * sin(angle));

            if (InRange(bits, new_x, new_y)) {
                if (bits[new_y][new_x] == BLACK) {
                    if (!black) {
                        start_angle = angle;
                        black = true;
                    }
                } else {
                    end_angle = angle;
                    black = false;
                    mean_angle = (start_angle + end_angle) / 2;

                    new_x = static_cast<int64_t>(static_cast<double>(x) + epsilon * cos(mean_angle + M_PI));
                    new_y = static_cast<int64_t>(static_cast<double>(y) + epsilon * sin(mean_angle + M_PI));

                    if (bits[new_y][new_x] == BLACK && bits[(new_y + y) / 2][(new_x + x) / 2] == BLACK) {
                        return false;
                    }
                }
            }

            angle += DELTA_PHY;
        }

        return true;
    }

    bool Circle::InRange(const std::vector<std::string> &bits, int64_t x, int64_t y) {
        /*
         * Эта функция проверяет, что точка находится внутри битового представления картинки
         */
        return !(x < 0 || y < 0 || bits.size() <= y || bits[0].size() <= x);
    }

}