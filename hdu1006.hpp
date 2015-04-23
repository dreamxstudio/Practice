#pragma once

#include <stdio.h>
#include <limits.h> 
 
#define max(l,m) ((l)>(m)?(l):(m))
#define min(l,m) ((l)<(m)?(l):(m))
#define abs(l) ((l)>0?(l):-(l))

namespace hdu1006{
 
const double sec_m = 60;
const double sec_h = 60 * 60;
const double sec_d = 60 * 60 * 12;

const double vs = 360.0 / sec_m;
const double vm = 360.0 / sec_h;
const double vh = 360.0 / sec_d;

const double T_sm = 360.0 / (vs - vm);
const double T_sh = 360.0 / (vs - vh);
const double T_mh = 360.0 / (vm - vh);

void run()
{ 
	//printf("%lf %lf %lf\n", T_sm, T_sh, T_mh); 
	//printf("%lf %lf %lf\n", sec_d / T_sm, sec_d / T_sh, sec_d / T_mh);

	double deg;
	for (; scanf("%lf", &deg), deg != -1;)
	{
		//Start time -- cycle begin
		double S_sm = deg / 360 * T_sm;
		double S_sh = deg / 360 * T_sh;
		double S_mh = deg / 360 * T_mh;

		//End time  -- cycle end
		double E_sm = (360.0 - deg) / 360 * T_sm;// / (vs - vm);
		double E_sh = (360.0 - deg) / 360 * T_sh;/// (vs - vh);
		double E_mh = (360.0 - deg) / 360 * T_mh;/// (vm - vh);

		double happy = 0.0;

		double cur_start = S_mh;
		double cur_end = E_mh;

		while (S_mh < sec_d - T_sh && S_sm < sec_d - T_sh)
		{
			cur_start = max(S_sm, max(S_sh,S_mh));
			cur_end = min(E_sm, min(E_sh, E_mh));

			happy += (cur_end - cur_start)>0 ? (cur_end - cur_start) : 0;

			S_sm += (abs(cur_end - E_sm) <= 1e-15 ? T_sm : 0); 
			S_sh += (abs(cur_end - E_sh) <= 1e-15 ? T_sh : 0);
			S_mh += (abs(cur_end - E_mh) <= 1e-15 ? T_mh : 0);

			E_sm += (abs(cur_end - E_sm) <= 1e-15 ? T_sm : 0);
			E_sh += (abs(cur_end - E_sh) <= 1e-15 ? T_sh : 0);
			E_mh += (abs(cur_end - E_mh) <= 1e-15 ? T_mh : 0);
		}

		printf("%.3lf\n", happy /( sec_d/100));
	}
}

} 