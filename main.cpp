
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "check_dot.h"

#include <cmath>



/*
const double PI = 3.141592653589793;
int point(std::vector<double>& masx, std::vector<double>& masy, double& x, double& y)
{
	double anglesum = 0;
	double eps = 1e-7;
	for (int i = 0; i < masx.size() - 1; ++i)
	{

		double x1 = masx[i];
		double x2 = masx[i + 1];
		double y1 = masy[i];
		double y2 = masy[i + 1];
		double vax = x1 - x;
		double vay = y1 - y;
		double vbx = x2 - x;
		double vby = y2 - y;
		//double vbz = 0;
		//double vaz = 0;
		//std::cout << "y2 = " << y2 << std::endl;
		//std::cout << " point" << vax <<" " <<" "<<vay << " "<<vbx <<" " <<vby;
		//double zcor = 1, ycor = 0, xcor = 0;
		double len_a = std::sqrt(pow(vax, 2) + pow(vay, 2));
		double len_b = std::sqrt(pow(vbx, 2) + pow(vby, 2));
		//std::cout << "len_a" << len_a << std::endl;
		//std::cout << "len_b" << len_b << std::endl;
		double det = (vax * vby - vbx * vay);
		//double det = vax * vby * zcor + vay *vbz  * xcor + vbx * ycor * vaz -
		//vaz* vby* xcor - vbx * vay * zcor - vax * ycor * vbz;
		//std::cout << "det" << det << std::endl;
		double direction = (det >= 0) ? 1 : -1;
		//std::cout << i << ":    " << "len a:" << len_a << "  len b:" << len_b;

		if ((len_a < eps) or (len_b < eps))
		{
			std::cout << i << ":    " << "len a:" << len_a << "  len b:" << len_b;
			return 0;
		}
		double norm = (len_a * len_b);
		//std::cout << "norma" << norm << std::endl;

		double  sk = ((vax * vbx) + (vay * vby));
		//std::cout << "skalayr" << sk << std::endl;

		double cosangle = ((vax * vbx) + (vay * vby)) / (len_a * len_b);
		//std::cout << "cos" << cosangle << std::endl;
		double angle = std::acos(cosangle);
		if (fabs(fabs(angle) - PI) < eps)
		{
			return 1;
		}


		anglesum = anglesum + angle * direction;
		//std::cout << "acos" << angle << std::endl;

	}
	//std::cout << "SUM = " << anglesum << std::endl;
	if (fabs(fabs(anglesum) - 2 * PI) < eps)
	{
		return 2;
	}
}
*/


int main(int argc, char** argv)
{

    std::string path =argv[1];//
    double x ,y;
    x = std::stod(argv[2]);
    y = std::stod(argv[3]);

    std::vector <double> vx;
    std::vector <double> vy;
    double x0, y0;
    std::ifstream f;
    f.open(path);
    if (!f.is_open())// считывания файла
    {
        std::cout << "error open file" << std::endl;
    }
    else
    {
        std::cout << "file open" << std::endl;
        while (!f.eof())
        {
            f >> x0 >> y0;

            vx.push_back(x0);
            vy.push_back(y0);
        }
        vx.push_back(vx[0]);
        vy.push_back(vy[0]);

        int res = point(vx, vy, x, y);
        if (res == 0)
        {
            std::cout << "dot at the top" << std::endl;
        }
        else if (res == 1)
        {
            std::cout << "dot on the edge" << std::endl;
        }
        else if (res == 2)
        {
            std::cout << "dot in polygon" << std::endl;
        }
        else
        {
            std::cout << "dot outside the polygon" << std::endl;
        }
    }
    f.close();

    /*
    while (!f.eof())
    {
        f >> x >> y;

        vx.push_back(x);
        vy.push_back(y);
    }
    f.close();

    for (int i = 0; i < vx.size(); i++)
    {
        std::cout << vx[i] << std::endl;
        std::cout << vy[i] << std::endl;

    }

    int res=point(vx, vy, x, y);
    if (res == 0)
    {
        std::cout << "dot at the top" << std::endl;
    }
    else if  (res == 1)
    {
        std::cout << "dot on the edge" << std::endl;
    }
    else if (res == 2)
    {
        std::cout << "dot in polygon" << std::endl;
    }
    else
    {
        std::cout << "dot outside the polygon" << std::endl;
    }
    */
    return 0;
}

