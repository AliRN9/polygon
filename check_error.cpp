#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
#include "check_error.h"


ParseErrors check_error(int argc, char** argv, std::string& path, std::vector<double>& vx, std::vector<double>& vy, double& x, double& y)
{
    //double x, y;
    if(argc < 4)
    {
        return ParseErrors::INSUFFICIENT_ARGUMENTS;
    }
    if (argc > 4) 
    {
        return ParseErrors::TO_MUCH_ARGUMENTS;
    }

    //std::string path;
    path = argv[1];

    try {
        x = std::stod(argv[2]);
        y = std::stod(argv[3]);
    }
    catch (std::logic_error)
    {
        //std::cerr << "Вы подали неверные аргументы!" << std::endl;
        return ParseErrors::WRONG_ARGUMENTS;
    }

    std::string x0, y0;
    std::ifstream f;
    f.open(path);
    if (!f.is_open()) // считывания файла
    {
        //std::cerr << "error open file" << std::endl;
        return ParseErrors::ERROR_OPEN_FILE;
    }

    std::cout << "file open" << std::endl;
    try
    {
        while (!f.eof())
        {
            f >> x0 >> y0;
            vx.push_back(std::stod(x0));
            vy.push_back(std::stod(y0));
        }
        f.close();

    }
    catch (std::invalid_argument)
    {
        //std::cerr << "Вы подали неверные точки!" << std::endl;
        return ParseErrors::INVALID_POLYGON;
    }
    return ParseErrors::SUCCESS;
    
}

std::string get_error_name(ParseErrors err_info)
{
    switch (err_info)
    {
    case ParseErrors::INSUFFICIENT_ARGUMENTS:
        return "Not enough arguments";
    case ParseErrors::TO_MUCH_ARGUMENTS:
        return "To much arguments";
    case ParseErrors::WRONG_ARGUMENTS:
        return "Wrong input: x and y must be double";
    case ParseErrors::ERROR_OPEN_FILE:
        return "Error open file";
    case ParseErrors::INVALID_POLYGON:
        return "Invalid polygon";
    case ParseErrors::SUCCESS:
        return "No error";
    }
    return "Unknown error";
}
