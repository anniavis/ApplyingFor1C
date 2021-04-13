//
// Created by saniya on 13.04.2021.
//

#include "Scanline.hpp"

namespace solution
{

    Scanline::Scanline(std::vector<std::string> &bits): bits_view(bits) {}

    /*
     * Классический поиск расстоний
     */
    double Scanline::Dist(const std::pair<size_t, size_t> &first, const std::pair<size_t, size_t> &second)
    {
        return sqrt(static_cast<double>(
                (first.first - second.first)*(first.first - second.first)
                + (first.second - second.second)*(first.second - second.second))
                );
    }

    /*
     * Пробег по массиву и проверка, что мы не считаем дважды одну и ту же точку
     */
    bool Scanline::NotFound(size_t x, size_t y)
    {
        for (auto& point: cross_points)
        {
            if (Dist(point, {x, y}) <= EPSILON)
            {
                return false;
            }
        }
        return true;
    }

    /*
     * Проверка колонки:
     *    Запускаем проверку на точку пересечения для каждого фрагмента прямой с помощью окружности (см алгоритм)
     */
    void Scanline::CheckColumn(size_t raw)
    {
        // std::cout << "Cheking raw " << raw << " From " << bits_view[0].size() << std::endl;
        std::vector<std::pair<size_t, size_t>> black;
        bool first_black_found = false;
        size_t first_black;
        size_t second_black;

        for (size_t i = 0; i < bits_view.size(); ++i)
        {
            if (bits_view[i][raw] == BLACK)
            {
                if (first_black_found)
                {
                    continue;
                }
                else
                {
                    first_black_found = true;
                    first_black = i;
                }
            }
            else
            {
                if (first_black_found)
                {
                    second_black = i - 1;
                    first_black_found = false;
                }
                else
                {
                    continue;
                }
            }
            if (!solution::Circle::IsPoint(bits_view, raw, (first_black + second_black) / 2, EPSILON)) {
                if (NotFound(raw, (first_black + second_black) / 2)) {
                    cross_points.emplace_back(raw, (first_black + second_black) / 2);
                    std::cout << raw << " y= " <<  (first_black + second_black) / 2 << std::endl;
                }
            }
        }
    }

    size_t Scanline::Scan()
    {
        for (size_t i = 0; i < bits_view[0].size(); ++i)
        {
            CheckColumn(i);
        }
        return cross_points.size();
    }
}