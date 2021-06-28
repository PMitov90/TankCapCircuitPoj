#pragma once

int const TYPE_ARR_LEN = 50; //some length for array
int const INPUT_NUMBER_LIMIT = 1000 * 1000;
int const TYPE_MAX = 5; //max number for capacitor type 
int const TYPE_MIN = 1;
int const COUNT_MAX = 5; //max number of capacitors per group
int const COUNT_MIN = 1;
int const CAPACITOR_GROUPS_COUNT = 2;
double const PI = 3.14;

static const struct
{
	double const C_1 = 0.0000010;
	double const I_MAX_1 = 500;
	double const Q_1 = 500;
	double const U_1 = 1000;
} paramsType1;

static const struct
{
	double const C_2 = 0.0000033;
	double const I_MAX_2 = 600;
	double const Q_2 = 500;
	double const U_2 = 800;
} paramsType2;

static const struct
{
	double const C_3 = 0.0000060;
	double const I_MAX_3 = 750;
	double const Q_3 = 500;
	double const U_3 = 750;
} paramsType3;

static const struct
{
	double const C_4 = 0.0000100;
	double const I_MAX_4 = 800;
	double const Q_4 = 500;
	double const U_4 = 600;
} paramsType4;

static const struct
{
	double const C_5 = 0.0000230;
	double const I_MAX_5 = 1000;
	double const Q_5 = 500;
	double const U_5 = 500;
} paramsType5;


struct capacitor {
	double capacity = 0;
	int type = -1;
	char group = -1;

	double i_rms = 0;
	double u_rms = 0;
	double xc = 0;

	double i_max = 0;
	double q_max = 0;
	double u_max = 0;
};