#include <stdio.h>
#include "Header.h"


double plusVal(int x, int y) //used for test if code is compiling
{
	int z = x + y;
	
	double p = paramsType1.C_1  * paramsType3.C_3 * x + z * paramsType5.C_5;

	return p;
}

bool readGroupInput(capacitor capArr[])
{
	int i_gr1 = 0;

	while (true)
	{
		printf("\nEnter capacitors count for the group\n");

		if (!scanf_s("%d", &i_gr1))
		{
			printf("\nCould not read intput\n");
			return false;
		}

		if ((i_gr1 <= 0) || (i_gr1 > 5))
		{
			printf("\nError: count is out of boundries. Min:1 Max:5\n");
			continue;
		}

		printf("\nCount in group is %d.\n", i_gr1);
		break;
	}

	for (int n = 0; n < i_gr1; n++)
	{
		while (true)
		{
			printf("\nEnter the type number of capacitor %d\n", n + 1);

			if (!scanf_s("%d", &capArr[n].type))
			{
				printf("\nError: unexpected value.\n");
				return false;
			}

			if ((capArr[n].type < 0) || (capArr[n].type > 5))
			{
				printf("\nType is number from 1 to 5.\n");
				continue;
			}

			printf("\nType is set to %d\n", capArr[n].type);
			break;
		}
	}

	printf("\nA type was assigned to all capacitors from the group.\n\n\n");
	return true;
}

bool readInput2(capacitor capArr1[], capacitor capArr2[], double& fHz_A, double& RMS_A)
{
	int i_gr1 = 0;
	int i_gr2 = 0;

	printf("\nEnter input for the 1st group.\n");

	if (!readGroupInput(capArr1))
		return false;

	printf("\nEnter input for the 2nd group.\n");

	if (!readGroupInput(capArr2))
		return false;

	while (true)
	{
		printf("\nEnter power source frequency [Hz] : ");

		if (!scanf_s("%lf", &fHz_A))
		{
			printf("\nERROR: Could not read intput\n");
			return false;
		}

		if (fHz_A > INPUT_NUMBER_LIMIT)
		{
			printf("\nERROR: The frequency value is too big \n");
			continue;
		}

		if (fHz_A < 0)
		{
			printf("\nERROR: The frequency value cannot be negative number.\n");
			continue;
		}

		printf("Frequency is %lf Hz\n", fHz_A);
		break;
	}


	/*================================= #RMS ================================*/
	while (true)
	{
		printf("\nEnter current RMS: ");

		if (!scanf_s("%lf", &RMS_A))
		{
			printf("\nERROR: Could not read intput\n");
			return false;
		}

		if (RMS_A <= 0)
		{
			printf("\nERROR: RMS current must be greater than 0.\n");
			continue;
		}

		if (RMS_A > INPUT_NUMBER_LIMIT)
		{
			printf("\nERROR: RMS value number is too big.\n");
			continue;
		}

		printf("RMS is %lf A\n", RMS_A);
		break;
	}

	return true;
}



//bool readInput(int& capType, int& capCount, double& fHz_A, double& RMS_A)
//{
//	/*================================= #Type ================================*/
//	while (true)
//	{
//		
//
//		printf("\nEnter capacitors type: ");
//
//		if (!scanf_s("%d", &capType))
//		{
//			printf("\nCould not read intput\n");
//			return false;
//		}
//
//		if ((capType <= 0) || (capType > 5))
//		{
//			printf("\n Error: Type value is out of boundries. Max:5 Min:1\n");
//			continue;
//		}
//
//		printf("Type is %d\n", capType);
//		break;
//	}
//
//
//	/*================================= #Count ================================*/
//
//	while (true)
//	{
//		printf("\nEnter capacitors count in a group: ");
//
//		if (!scanf_s("%d", &capCount))
//		{
//			printf("\nERROR: Could not read intput\n");
//			return false;
//		}
//
//		if ((capCount <= 0) || (capCount > 5))
//		{
//			printf("\n ERROR: capacitors count value is out of boundries. Max:5 Min:1\n");
//			continue;
//		}
//
//		printf("Count is %d\n", capCount);
//		break;
//	}
//
//
//	/*================================= #Frequency ================================*/
//
//	while (true)
//	{
//		printf("\nEnter power source frequency [Hz] : ");
//
//		if (!scanf_s("%lf", &fHz_A))
//		{
//			printf("\nERROR: Could not read intput\n");
//			return false;
//		}
//
//		if (fHz_A > INPUT_NUMBER_LIMIT)
//		{
//			printf("\nERROR: The frequency value is too big \n");
//			continue;
//		}
//
//		if (fHz_A < 0)
//		{
//			printf("\nERROR: The frequency value cannot be negative number.\n");
//			continue;
//		}
//
//		printf("Frequency is %lf\n", fHz_A);
//		break;
//	}
//
//
//	/*================================= #RMS ================================*/
//	while (true)
//	{
//		printf("\nEnter current RMS: ");
//
//		if (!scanf_s("%lf", &RMS_A))
//		{
//			printf("\nERROR: Could not read intput\n");
//			return false;
//		}
//
//		if (RMS_A <= 0)
//		{
//			printf("\nERROR: RMS current must be greater than 0.\n");
//			continue;
//		}
//
//		if (RMS_A > INPUT_NUMBER_LIMIT)
//		{
//			printf("\nERROR: RMS value number is too big.\n");
//			continue;
//		}
//
//		printf("RMS is %lf\n", RMS_A);
//		break;
//	}
//
//	return true;
//}

capacitor equivCapPar(capacitor cArr[])				//Parallel eqivalent
{
	//double gr1 = cF * 5;
	//double gr2 = cF * 5;
	//double c_eq = (gr1 * gr2) / (gr1 + gr2);

	struct capacitor equivParCap;

	for (int n = 0; n < COUNT_MAX; n++)
	{
		if (cArr[n].capacity == 0)
			break;

		equivParCap.capacity += cArr[n].capacity;
	}

	printf("\nDEBUG: EQUIV PAR CAP FINAL: %lf\n", equivParCap.capacity);

	return equivParCap;
}

capacitor equivCapSer(capacitor cArr[])				//Series equivalent
{
	struct capacitor equivSerCap;
	double sum = 0;

	for (int n = 0; n < COUNT_MAX; n++)
	{
		if (cArr[n].capacity == 0)
			break;

		sum += (double)1 / cArr[n].capacity;

		printf("\nDEBUG: EQUIV SER SUM: %lf\n", sum);
	}

	equivSerCap.capacity = (double)1 / sum;

	printf("\nDEBUG: EQUIV SER CAP FINAL: %lf\n", equivSerCap.capacity);

	return equivSerCap;
}



double CapReactance(double fHz, double capF) 
{ 
	double xc = (double)1 / (2 * PI * fHz * capF);
	return xc;
}


double rmsVoltageDropSeries(double equivC, double cap, double uCirc, double xc, double iCirc)  //voltage drop in series capacitors
{
	double u = equivC * uCirc / cap;
	printf("\nDEBUG: series special frmula result: %lf\n", u);

	double uSame = iCirc * xc;
	printf("\nDEBUG: series Ohm formula result %lf\n", uSame);

	return u;
}

double rmsVoltageDropParallel(double cap, double uGroup, double xc)
{
	double i = uGroup / xc;
	printf("\nDEBUG: parallel Irms result: %lf\n", i);

	return i;
}

void calculateSeriesRMSVoltageDrop(capacitor arrC[], double equivC, double uCirc, double fHz)
{
	for (int n = 0; n < 2; n++)    // n < 2 because only two groups
	{
		if (arrC[n].capacity == 0)
			break;

		arrC[n].xc = CapReactance(fHz, arrC[n].capacity);

		arrC[n].u_rms = rmsVoltageDropSeries(
			equivC, 
			arrC[n].capacity, 
			uCirc, 
			arrC[n].xc, 
			arrC[n].i_rms
		);

		printf("\nDeBUG: series capacitors next RMS Voltage: %lf\n", arrC[n].u_rms);
	}
}

void calculateParallelRMSCurrent(capacitor arrC[], double fHz)
{
	for (int n = 0; n < COUNT_MAX; n++)
	{
		if (arrC[n].capacity == 0)
			break;

		arrC[n].xc = CapReactance(fHz, arrC[n].capacity);

		arrC[n].i_rms = rmsVoltageDropParallel(
			arrC[n].capacity, 
			arrC[n].u_rms, 
			arrC[n].xc
		);

		printf("\nDEBUG: parallel capacitor next current: %lf\n", arrC[n].i_rms);
	}
}

double circuitU(double i_rms, double xc)
{
	printf("\nDEBUG: CIRCUIT U_RMS = %lf\n", i_rms * xc);
	return i_rms * xc;
}

void setCapacity(capacitor capArr[])
{
	for (int n = 0; n < COUNT_MAX; n++)
	{
		if (capArr[n].type < 1)
			break;

		switch (capArr[n].type) {
		case 1:
			capArr[n].capacity = paramsType1.C_1;
			capArr[n].i_max = paramsType1.I_MAX_1;
			capArr[n].q_max = paramsType1.Q_1;
			capArr[n].u_max = paramsType1.U_1;
			break;
		case 2:
			capArr[n].capacity = paramsType2.C_2;
			capArr[n].i_max = paramsType2.I_MAX_2;
			capArr[n].q_max = paramsType2.Q_2;
			capArr[n].u_max = paramsType2.U_2;
			break;
		case 3:
			capArr[n].capacity = paramsType3.C_3;
			capArr[n].i_max = paramsType3.I_MAX_3;
			capArr[n].q_max = paramsType3.Q_3;
			capArr[n].u_max = paramsType3.U_3;
			break;
		case 4:
			capArr[n].capacity = paramsType4.C_4;
			capArr[n].i_max = paramsType4.I_MAX_4;
			capArr[n].q_max = paramsType4.Q_4;
			capArr[n].u_max = paramsType4.U_4;
			break;
		case 5:
			capArr[n].capacity = paramsType5.C_5;
			capArr[n].i_max = paramsType5.I_MAX_5;
			capArr[n].q_max = paramsType5.Q_5;
			capArr[n].u_max = paramsType5.U_5;
			break;
		}
	}
}

void setIndividualUrms(double uGrRms, capacitor capArrGr[])
{
	for (int i = 0; i < COUNT_MAX; i++)
	{
		if (capArrGr[i].capacity == 0)
			break;

		capArrGr[i].u_rms = uGrRms;
	}
}

void PrintOutput(capacitor capArrGr[])
{
	printf("\nGroup: \n");

	for (int i = 0; i < COUNT_MAX; i++)
	{
		if (capArrGr[i].capacity == 0)
			break;

		printf("\n          %d.Irms: %lf\n", i, capArrGr[i].i_rms);
		printf("\n          Urms: %lf\n", capArrGr[i].u_rms);
	}

	
}

void myPrint()
{
	printf("%lf; %lf; %lf; %lf; %lf", paramsType1.C_1, paramsType2.C_2, paramsType3.C_3, paramsType4.C_4, paramsType5.C_5);
}

int main(int argc, char* argv[])
{
	double res = plusVal(10, 5);

	printf("\nTEST: The result sum is: %lf\n\n\n\n\n", res);


/*================================ ACTUAL PROGRAM ========================================*/
	//char capType[TYPE_ARR_LEN];


	struct capacitor capArrGr1[COUNT_MAX];
	struct capacitor capArrGr2[COUNT_MAX];
	struct capacitor capArrEquivGr[CAPACITOR_GROUPS_COUNT];			//stores equivalent of each group
	//struct capacitor capGroups[CAPACITOR_GROUPS_COUNT][COUNT_MAX];
	int capType = 0;
	int capCount = 0;
	double fHz_A = 0;
	double RMS_A = 0;

	if (!readInput2(capArrGr1, capArrGr2, fHz_A, RMS_A))
		return 0;

	setCapacity(capArrGr1);
	setCapacity(capArrGr2);

	capArrEquivGr[0] = equivCapPar(capArrGr1);		//calculating equivalent capacitor for gr1
	capArrEquivGr[1] = equivCapPar(capArrGr2);		//calculating equivalent capacitor for gr2

	struct capacitor equivCap = equivCapSer(capArrEquivGr); // calculating equivalent capacitor for gr1 + gr2

	double xc = CapReactance(fHz_A, equivCap.capacity);

	double circU_rms = circuitU(RMS_A, xc);

	capArrEquivGr[0].i_rms = RMS_A;
	capArrEquivGr[1].i_rms = RMS_A;

	calculateSeriesRMSVoltageDrop(capArrEquivGr, equivCap.capacity, circU_rms, fHz_A);

	setIndividualUrms(capArrEquivGr[0].u_rms, capArrGr1);
	setIndividualUrms(capArrEquivGr[1].u_rms, capArrGr2);

	calculateParallelRMSCurrent(capArrGr1, fHz_A);
	calculateParallelRMSCurrent(capArrGr2, fHz_A);

	PrintOutput(capArrGr1);
	PrintOutput(capArrGr2);

	//if (!readInput(capType, capCount, fHz_A, RMS_A))
	//	return 0;

	//myPrint();

	return 0;
}