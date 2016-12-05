#include<string>
#include<math.h>


int calculateDurationOfNote(int bpm, int noteType, int noteCarriesBeat)
{
	int miliSec = 60000/bpm*noteCarriesBeat/noteType;
	return miliSec;
}

int calculateFrequencyOfNote (string note, int tuningStandard, string tuningStandardNote, int octaveOfStandard, int octaveOfNote)
{
	int stepsfromstandard[12];
	int index=0;
	int halfsteps=0;
	
	if(tuningStandardNote=="C")
		index = 0;
	if(tuningStandardNote=="CSDF")
		index = 1;
	if(tuningStandardNote=="D")
		index = 2;
	if(tuningStandardNote=="DSEF")
		index = 3;
	if(tuningStandardNote=="E")
		index = 4;
	if(tuningStandardNote=="F")
		index = 5;
	if(tuningStandardNote=="FSGF")
		index = 6;
	if(tuningStandardNote=="G")
		index = 7;
	if(tuningStandardNote=="GSAF")
		index = 8;
	if(tuningStandardNote=="A")
		index = 9;
	if(tuningStandardNote=="ASBF")
		index = 10;
	if(tuningStandardNote=="B")
		index = 11;
	
	for (in i = 0; i<12; i++)
	{
		stepsfromstandard[i]=i-index;//in same octave
	}
	
	halfsteps = stepsfromstandard+12*(octaveOfStandard-octaveOfNote)
	
	frequency = tuningStandard*pow(pow(2,(1/12),halfsteps);
	
	return frequency;
	
}