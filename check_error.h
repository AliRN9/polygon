#pragma once
#include <string>


enum class ParseErrors
{
    INSUFFICIENT_ARGUMENTS = -6,
    TO_MUCH_ARGUMENTS = -5,
    WRONG_ARGUMENTS = -4,
    ERROR_OPEN_FILE = -3,
    INVALID_POLYGON = -2,
    SUCCESS = 0
};
ParseErrors check_error(int argc, char** argv, std::string& path, std::vector<double>& masx, std::vector<double>& masy, double& x, double& y);
std::string get_error_name(ParseErrors err_info);