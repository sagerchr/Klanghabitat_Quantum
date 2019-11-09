/*******************************************************************************
*
********************************************************************************
*     ModuleList.h  Created on 12-Apr-2019 20:29:32
********************************************************************************
*
*     Description:  Module list for the target
*
*     Copyright: (c) 2019 DSP Concepts, Inc. All rights reserved.
*                         3235 Kifer Road
*                         Santa Clara, CA 95054-1527
*
*******************************************************************************/

#define TOTALNUMBEROFCLASSES 8

extern const ModClassModule awe_modDeinterleaveClass;
extern const ModClassModule awe_modGPIOClass;
extern const ModClassModule awe_modGraphicEQBandClass;
extern const ModClassModule awe_modInterleaveClass;
extern const ModClassModule awe_modMeterFract32Class;
extern const ModClassModule awe_modMultiplexorV2Class;
extern const ModClassModule awe_modSinkFract32Class;
extern const ModClassModule awe_modTypeConversionClass;


#define LISTOFCLASSOBJECTS \
&awe_modDeinterleaveClass, \
&awe_modGPIOClass, \
&awe_modGraphicEQBandClass, \
&awe_modInterleaveClass, \
&awe_modMeterFract32Class, \
&awe_modMultiplexorV2Class, \
&awe_modSinkFract32Class, \
&awe_modTypeConversionClass
