#pragma once
#include "ElectricalCircuitElement.h"
class ACGenerator : public ElectricalCircuitElement
{
public:
	double frequencyHz;
};

class CapacitorObj
{
public:
	CapacitorObj(double capacity_F, double currentMax_A, double voltageMax_V, double reactivePowerMax_VA);

	struct Parameters
	{
#pragma region PROPERTIES
	private:
		void put_capF(double val) { capacity_F = val; }
		void put_curMaxA(double val) { currentMax_A = val; }


		__declspec(property(get = get_capf, put = put_capF)) double capacity_F;
		__declspec(property(get = get_curMaxA, put = put_curMaxA)) double currentMax_A;
		__declspec(property(get = get_voltMaxV, put = put_voltMaxV)) double voltageMax_V;
		__declspec(property(get = get_reactPowMaxVA, put = put_reactPowMaxVA)) double reactivePowerMax_VA;

	public:
		double get_capf() { return capacity_F; }

		double get_curMaxA() { return currentMax_A; }
		
		void put_voltMaxV(double val) { voltageMax_V = val; }
		double get_voltMaxV() { return voltageMax_V; }
		
		void put_reactPowMaxVA(double val) { reactivePowerMax_VA = val; }
		double get_reactPowMaxVA() { return reactivePowerMax_VA; }
#pragma endregion


	};
};

