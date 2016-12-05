#include<string>
#include<math.h>

//Note type is whole 1, half 2, triplet 3, quarter 4, eigth 8, sixteenth 16, etc.
//Note that carries beat is in relation to the time signature, most songs are in 4/4 so the note that carries the beat is 4
//If time signature was 3/4 4 carries the beat, 6/8 8 carries the beat and etc.
//bpm is beats per minute, or the tempo. If the tempos is moderate or slowly, just use  your judgement for beats per minute.

int calculateDurationOfNote(int bpm, int noteType, int noteCarriesBeat)
{
	int miliSec = 60000/bpm*noteCarriesBeat/noteType;
	return miliSec;
}

//Normally tuning standard would be 440 tuningStandardNote = "A" octaveOfStandard= 4, the octave of note and note depends on the note you want to find a freqency for.

int calculateFrequencyOfNote (string note, int tuningStandard, string tuningStandardNote, int octaveOfStandard, int octaveOfNote)
{
	int stepsfromstandard[12];
	int index=0;//this cooresponds to the location in the array
	int halfsteps=0;//this will be calculated for the frequency equation.
	int frequency;
	
	if(tuningStandardNote=="C")
		index = 0;
	if(tuningStandardNote=="CSDF")//C# or Db
		index = 1;
	if(tuningStandardNote=="D")
		index = 2;
	if(tuningStandardNote=="DSEF")//D# or Eb
		index = 3;
	if(tuningStandardNote=="E")
		index = 4;
	if(tuningStandardNote=="F")
		index = 5;
	if(tuningStandardNote=="FSGF")//F# or Gb
		index = 6;
	if(tuningStandardNote=="G")
		index = 7;
	if(tuningStandardNote=="GSAF")//G# or Ab
		index = 8;
	if(tuningStandardNote=="A")
		index = 9;
	if(tuningStandardNote=="ASBF")//A# or Bb
		index = 10;
	if(tuningStandardNote=="B")
		index = 11;
	
	for (in i = 0; i<12; i++)//This calculates how many half steps away from the tuningStandard a note is, within the same octave.
	{
		stepsfromstandard[i]=i-index;//in same octave
	}
	
	halfsteps = stepsfromstandard+12*(octaveOfStandard-octaveOfNote);//this calculates the halfsteps from the standard note in any octave.
	
	frequency = tuningStandard*pow(pow(2,(1/12),halfsteps);//We plug all values we found above into the equation to solve for frequency of the note.
	
	return frequency;
	
}
