// Shehriar Burney
// UIN - 679754208


// Bar Chart Animation
//
// This application uses BarChartAnimate (which uses BarChart, which uses Bar)
// to produce an animated bar chart.
//
// Once your three class/abstraction files are completed and tested, run with
// this application to see your final creation.
//
// TO DO: Nothing for the standard application, just compile and run! However,
// before submitting you need to add your creative component.
//
// Adam Koehler
// U. of Illinois, Chicago
// Fall 2022
//
// Original iteration of program developed by:
// Shanon Reckinger
// U. of Illinois, Chicago 

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "barchartanimate.h"
using namespace std;


// CREATIVE FUNCTION

// User interaction to change refresh rate.
// The user is prompted to put in how fast they would want to see the barchart animation.
// This function is useful as it depends on the user if they want to analyze how within each year the data changes. If they want to thoroughly analyze it, it would be best to set the rate as slow as possible. However, if they just want to see the progress as quick as possible, they can select option no. 5 for the fastest refresh rate.

int main() {
	cout << "Enter filename: ";
	// string filename = "cities.txt";
  string filename;
  cin >> filename;

  cout << "Enter rate of barchart 1 (slow) - 5 (fast): ";
  int rate, speed;
  cin >> rate;

  if (rate == 1) {
    speed = 400000;
  } else if (rate == 2) {
    speed = 200000;
  } else if (rate == 3) {
    speed = 90000;
  } else if (rate == 4) {
    speed = 50000;
  } else {
    speed = 20000;
  }
	ifstream inFile(filename);
	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);

	BarChartAnimate bca(title, xlabel, source);
	
	while (!inFile.eof()) {
		bca.addFrame(inFile);
	}
	
	bca.animate(cout, 12, -1, speed);

  return 0;
}
