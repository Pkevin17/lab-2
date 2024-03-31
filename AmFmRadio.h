/*
programmer: Kevinkumar Patel
Assignment: Major Assignment 3
First version: 2023-03-09
student id: 8913814
Description:UPGRADING YOUR CAR RADIO
*/
//AmFmRadio.h

#ifndef _AMFMRADIO_H
#define _AMFMRADIO_H

struct Freqs
{
	int AMFreq=530;
	double FMFreq=87.9;
};

class AmFmRadio
{
private:
	Freqs	button[5];// Array of preset buttons for AM and FM frequencies
	double	current_station;// Current tuned frequency
	char	band[3];
	int		volume;
	bool	on;
	struct Freqs last;
	char lband[3] = { "AM" };
	int lvolume = 0;
	bool displayOutput = false;
public:
    // Constructor with default parameters
    // Initializes the preset buttons to default frequencies, sets current station to default AM frequency,

	//sets the each button to the lowest frequency, sets the current station, sets the
	//frequency to AM, sets the volume to 0 and sets on to false
	AmFmRadio(bool on);
	AmFmRadio(bool on, struct Freqs f[]);

	//sets on to true
	void PowerToggle();

	//returns a true if the radio is currently powered on, and false if the radio is in
	//the off position
	bool IsRadioOn();

	//toggles frequency between AM and FM and sets current station
	void ToggleBand();

	//sets button (radio preset) with current station by being passed a button number
	int SetPresetButton(int button_num);

	//sets current station to radio preset by being passed a button number
	int SelectPresetButton(int button_num);

	//sets volume
	int SetVolume();
	int SetVolume(int Volume);

	//shows volume, button settings, current station, AM or FM
	void ShowCurrentSettings();

	//changes frequency up in increments of .2 for FM, 10 for AM
	void ScanUp();

	//changes frequency up in decrements of .2 for FM, 10 for AM
	void ScanDown();

	~AmFmRadio();	

	// Mutators
	void setCurrent_Station(double current_station);
	void setdisplayOutput(bool Display);

	// Accessors
	int getVolume();
	double getCurrent_Station();
	bool getdisplayOutput();
	char* getBand();
	struct Freqs* getPresetValues();
};
#endif