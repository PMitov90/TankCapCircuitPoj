#pragma once
	class ElectricalCircuitElement
	{
	public:

		struct rms_values
		{
			double i_rms;
			double u_rms;
			double r_rms;
		} rvalues;

		inline void CalcI_ohm() { rvalues.i_rms = rvalues.r_rms / rvalues.u_rms; }
		inline void CalcU_ohm() { rvalues.u_rms = rvalues.r_rms / rvalues.i_rms; }
		inline void CalcR_ohm() { rvalues.r_rms = rvalues.i_rms / rvalues.u_rms; }

		template <typename T>
		virtual T SeriesEquivElement(T e1, T e2)
		{

		}

	};

