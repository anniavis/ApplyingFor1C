//
// Created by saniya on 13.04.2021.
//

#include <fstream>
#include <vector>
#include <string>

namespace solution
{
    /**
     * Класс чекер необходим для запуска сканлайна и поиска точек пересечения
     */
    class Checker {
    public:
        explicit Checker(std::ifstream& input);

        size_t FindCross();
    private:
        std::vector<std::string> bits;
    };
}
