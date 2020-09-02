/*
 * lwiIPTask.h
 *
 *  Created on: 13.11.2019
 *      Author: christiansager
 */
/*******************************************/
typedef enum
{
	bypass=0,
	activate,
}Byp;

void BypassLeft(Byp State);
void BypassRight(Byp State);
/*******************************************/
typedef enum
{
	MS=0,
	RL,
}Source;

void VCASource(Source State);
/*******************************************/
typedef enum
{
	NormalOutput=0,
	MonoS,
	MonoM,
}Output;

typedef enum
{
	MS_Deconvert_Active=0,
	MS_Deconvert_Inactive,
}Convert;

void VCAOutput(Output Out, Convert Conv);
/*******************************************/
