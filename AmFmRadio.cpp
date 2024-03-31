/*
programmer: Kevinkumar Patel
Assignment: Major Assignment 3
First version: 2023-03-09
student id: 8913814
Description:UPGRADING YOUR CAR RADIO
*/
//AmFmRadio.cpp
// This header comment is quite inadequate and should be replaced.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "AmFmRadio.h"
#pragma warning(disable:4996)
// Constructor with default parameters
AmFmRadio::AmFmRadio(bool on=false)
{
	// Initialize the preset buttons for AM and FM frequencies
	for (int i = 0; i < 5; ++i)
	{
		button[i].AMFreq = 530;
	}
	for (int j = 0; j < 5; ++j)
	{
		button[j].FMFreq = 87.9;
	}
	current_station = 530;
	strcpy(band, "AM");
	volume = 0;
	this->on = on;
}
// Constructor with custom preset frequencies
AmFmRadio::AmFmRadio(bool on, struct Freqs f[])
{
	for (int i = 0; i < 5; ++i)
	{
		button[i].AMFreq =f[i].AMFreq;
	}
	for (int i = 0; i < 5; ++i)
	{
		button[i].FMFreq = f[i].FMFreq;
	}
	current_station = 530;
	strcpy(band, "AM");
	volume = 0;
	this->on = on;
}

void AmFmRadio::PowerToggle()
{
	if (on == false)
	{
		on = true;
		volume = lvolume;
		strcpy(band,lband);
		strcmp(band, "AM") == 0 ? current_station = last.AMFreq : current_station = last.FMFreq;
	}
	else
	{
		on = false;
		lvolume = volume;
		strcpy(lband, band);
		strcmp(band, "AM") == 0 ? last.AMFreq = current_station : last.FMFreq = current_station;
	}
}
// Check if the radio is on
bool AmFmRadio::IsRadioOn()
{
	return on;
}
// Set the volume level based on user input
int AmFmRadio::SetVolume()
{
	char buf[20] = "";

	printf("\nEnter the volume level (0 - 100). ");
	fgets(buf, sizeof buf, stdin);
	volume = atoi(buf);

	if (volume < 0) //if user enters volume less than 0, volume = 0
	{
		volume = 0;
		return 0;
	}

	if (volume > 100) //if user enters volume greater than 100, volume = 100
	{
		volume = 100;
		return 2;
	}
	return 1;


}
int AmFmRadio::SetVolume(int Volume) {
	if (Volume >= 0 && Volume <= 100) {
		volume = Volume;
		return 1;
	}
	else if (Volume > 100) {
		volume = 100;
		return 2;
	}
	else {
		volume = 0;
		return 0;
	}
}

void AmFmRadio::ToggleBand()
{
	if (strcmp(band, "AM") == 0)
	{
		strcpy(band, "FM");
		last.AMFreq = current_station;
		current_station = last.FMFreq;
	}
	else
	{
		strcpy(band, "AM");
		last.FMFreq = current_station;
		current_station = last.AMFreq;
	}
}

int AmFmRadio::SetPresetButton(int button_num)
{
	if ((button_num >= 0) && (button_num <= 4))
	{
		if (strcmp("AM", band) == 0)
		{
			button[button_num].AMFreq = current_station;
		}
		else
		{
			button[button_num].FMFreq = current_station;
		}
		return 1;

	}
	return 0;

}

int AmFmRadio::SelectPresetButton(int button_num)
{
	if ((button_num >= 0) && (button_num <= 4))
	{
		if (strcmp("AM", band) == 0)
		{
			current_station = button[button_num].AMFreq;
		}
		else
		{
			current_station = button[button_num].FMFreq;
		}

		return 1;
	}
	return 0;


}

void AmFmRadio::ShowCurrentSettings()
{

	if (on == true)
	{
		printf("\n\nRadio is on. \n");
	}
	else
	{
		printf("\n\nRadio is off. \n");
	}

	printf("\nRadio Band: %s\n", band);
	printf("Volume: %d\n", volume);
	printf("Current Station: %.1f %s\n", current_station, band);
	printf("AM Button Settings: ");
	for (int i = 0; i < 5; ++i)
	{
		printf("%d) %6d ", i + 1, button[i].AMFreq);
	}

	printf("\nFM Button Settings: ");
	for (int j = 0; j < 5; ++j)
	{
		printf("%d) %6.1f ", j + 1, button[j].FMFreq);
	}
}

void AmFmRadio::ScanUp()
{
	if (strcmp("AM", band) == 0)
	{
		//if current_station is 1700, the current_station becomes 530
		if (current_station == 1700)
		{
			current_station = 530;
		}
		else
		{
			current_station = current_station + 10;
		}
	}
	else
	{
		//if the current_station is 107.9, the current_station becomes 87.9
		//Note: car radios jump .2 for the FM. That's how it's modeled here.
		if (current_station >= 107.9)
		{
			current_station = 87.9;
		}
		else
		{
			current_station = current_station + .2;
		}
	}
	printf("\nCurrent station: %f %s\n", current_station, band);
}

void AmFmRadio::ScanDown()
{
	if (strcmp("AM", band) == 0)
	{
		//if current_station is 530, the current_station becomes 1700
		if (current_station == 530)
		{
			current_station = 1700;
		}
		else
		{
			current_station = current_station - 10;
		}
	}
	else
	{
		//if the current_station is 87.9, the current_station becomes 107.9
		if (current_station >= 87.9)
		{
			current_station = 107.9;
		}
		else
		{
			current_station = current_station - .2;
		}
	}
	printf("\nCurrent station: %f %s\n", current_station, band);
}

AmFmRadio::~AmFmRadio() {
	printf("Destroying AmFmRadio");
}

void AmFmRadio::setCurrent_Station(double current_station) {
	this->current_station = current_station;
}
void AmFmRadio::setdisplayOutput(bool Display) {
	displayOutput = Display;
}
int AmFmRadio::getVolume() {
	return volume;
}
double AmFmRadio::getCurrent_Station() {
	return current_station;
}
bool AmFmRadio::getdisplayOutput() {
	return displayOutput;
}
char* AmFmRadio::getBand() {
	return band;
}
struct Freqs* AmFmRadio::getPresetValues() {
	return button;
}