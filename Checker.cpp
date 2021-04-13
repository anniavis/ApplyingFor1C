//
// Created by saniya on 13.04.2021.
//

#include "Checker.hpp"
#include "Scanline.hpp"

namespace solution
{

    /*
     * Считываем битовое представление картинки
     */
    Checker::Checker(std::ifstream &input)
    {
        std::string next_read;
        while (!input.eof())
        {
            input >> next_read;
            bits.emplace_back(next_read);
        }
    }

    /*
     * Запускаем сканлайн для нахождение потенциальных точек
     */
    size_t Checker::FindCross()
    {
         Scanline line(bits);
         size_t points_found = line.Scan();

         return points_found;
    }

}
