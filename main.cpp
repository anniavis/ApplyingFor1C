#include <iostream>

int main(int argc, char **argv)
{
    if (argc < 1)
    {
        std::cout << "No File" << std::endl;
    }
    std::ifstream image_bits(argv[1]);

    std::cout << (image_bits.is_open() ? "File opened successfully.\n": "Failed to open file.\n");

    if (image_bits.is_open())
    {
        solution::Checker checker(image_bits);

        std::cout << checker.FindCross();
    }
    return 0;
}
