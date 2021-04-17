#include "main.h"
#include "CompressorEngine.h"
#include "ValueTableMotherEngine.h"
#include "UART_correction.h"

// 0 = no gain reduction
// 1 = attack
// 2 = gain reduction
// 3 = release
enum CompStates {S_NoOperation, S_Attack, S_GainReduction, S_Release };
enum CompStates State = S_NoOperation;





//threshold -20dB below limit -> 0.1 * 2^31
//float threshold = 0.1f * 2147483648;

//compression ratio: 6:1 -> -6dB = 0.5
float gainreduce = 0;

int out;

//initial gain = 1.0 -> no compression
float gain = 0;
float gain_step_attack = 123;
float gain_step_release = 456;
//int TimeOut;
int test;
int  Hold =123;

int DoCompressor (float inSample, int reduce) {





	float threshold = (-1)*reduce/10;
	float inSampleF = dbuMAX[0];
	int Attack = UARTDATA_CHECKED[6]*50;
	int Release =UARTDATA_CHECKED [7]*50;
	int ratio=UARTDATA_CHECKED[9];


	if (inSampleF > threshold) {

		//calculate gainreduce which is the value needed to reduce by//

		gainreduce = (threshold-inSampleF)/ratio;
		gainreduce = (-10)*((threshold - inSampleF)-gainreduce);
		//**********************************************************//
		gain_step_attack = gainreduce/Attack;

 		if (gain <=  gainreduce) {
			if (State==S_NoOperation) {
				State=S_Attack;
				TimeOut = Attack;
			}
			else if (State==S_Release) {
			State=S_Attack;
				TimeOut = Attack;
			}
		}
		//if (State==S_GainReduction) TimeOut = Hold;

	}

/*

	if (inSampleF < threshold) {
		if (TimeOut==0 && State==S_GainReduction) {
			State=S_Release;
			TimeOut = Release;
		}
	}

*/

	test=1234;
	switch (State) {

		case S_Attack:
			if (TimeOut>0 && gain < gainreduce) {
				gain += gain_step_attack;
				TimeOut--;
			}
			else {
				State=S_GainReduction;
				//TimeOut = Hold;
			}
			break;


		case S_GainReduction:
			//if (TimeOut>0) TimeOut--;
			//else {
				State=S_Release;
				TimeOut = Release;
				gain_step_release = gain/Release;
			//}
			break;


		case S_Release:
			if (TimeOut>0) {
				TimeOut--;
				gain -= gain_step_release;
				if(gain<0)gain=0;
			}
			else {
				State=S_NoOperation;
			}
			break;

		case S_NoOperation:
			//if (gain < 0)
			gain=0;
			break;

		default:

			break;

	}

	out = gain;
	return out;
}
