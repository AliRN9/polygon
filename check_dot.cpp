#include "check_dot.h"

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
		double len_a = std::sqrt(pow(vax, 2) + pow(vay, 2));
		double len_b = std::sqrt(pow(vbx, 2) + pow(vby, 2));
		double det = (vax * vby - vbx * vay);
		double direction = (det >= 0) ? 1 : -1;

		if ((len_a < eps) or (len_b < eps))
		{
			return 0;
		}
		double norm = (len_a * len_b);
		double  sk = ((vax * vbx) + (vay * vby));
		double cosangle = ((vax * vbx) + (vay * vby)) / (len_a * len_b);
		double angle = std::acos(cosangle);
		if (fabs(fabs(angle) - PI) < eps)
		{
			return 1;
		}
		anglesum = anglesum + angle * direction;
	}
	if (fabs(fabs(anglesum) - 2 * PI) < eps)
	{
		return 2;
	}
	return 3;
}