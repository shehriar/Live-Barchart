// Shehriar Burney
// UIN - 679754208

// barchartanimate.h
// Bar chart animation where bars are colored by category

// This program creates an animation of bar charts using the information given in the txt files. 
// This includes barchart.h which includes bar.h


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map> 
#include <vector>
#include <unistd.h>
#include "myrandom.h" // used by graders, do not remove
#include "barchart.h"
  
using namespace std;


class BarChartAnimate {
 private:
    // BarCharts.  As a result, you must also keep track of the number of
    // elements stored (size) and the capacity of the array (capacity).
    // This IS dynamic array, so it must expand automatically, as needed.
    //
    BarChart* barcharts;  // pointer to a C-style array
    int size;
    int capacity;
    map<string, string> colorMap;
    string title;
    string xlabel;
    string source;

    int color;
    vector<string> categories;

    //creates categories for each file, stores it in a vector
    void create(string category) { 
      for (int i = 0; i < (int)categories.size(); i++) {
        if (categories[i] == category) {
          return;
        }
      }
      categories.push_back(category);
    }



 public:

    // a parameterized constructor:
    // Like the ourvector, the barcharts C-array should be constructed here
    // with a capacity of 4.
    BarChartAnimate(string title, string xlabel, string source) {
        this->title = title;
        this->xlabel = xlabel;
        this->source = source;
        color = 0;
        capacity = 4;
        size = 0;
        barcharts = new BarChart[capacity];
    }

    // destructor:
    // Called automatically by C++ to free the memory associated
    // by BarChartAnimate.
    virtual ~BarChartAnimate() {
      if (barcharts != nullptr) {
        delete[] barcharts;
        barcharts = nullptr;
      }
    }

    // addFrame:
    // adds a new BarChart to the BarChartAnimate object from the file stream.
    // if the barcharts has run out of space, double the capacity (see
    // ourvector.h for how to double the capacity).
    // See application.cpp and handout for pre and post conditions.
    void addFrame(ifstream &file) {
      string line;
      int bcSize;
      getline(file, line);
      if (file.eof()) {
        return;
      } 
      //if file is open
      getline(file, line);
      int total = stoi(line); // first line tells you capacity
      BarChart bc(total); //create barchart
      string extract, year, name, country, category;

      for (int i = 0; i < total; i++) {
        //assigning variables to their values from txt
        getline(file, line);
        stringstream s(line);
        getline(s, extract, ',');
        year = extract;
        getline(s, extract, ',');
        name = extract;
        getline(s, extract, ',');
        country = extract;
        getline(s, extract, ',');
        bcSize = stoi(extract);
        getline(s, extract, ',');
        category = extract;


        create(category); //adds to category vector
        
        bc.addBar(name, bcSize, category); //adding each bar
        bc.setFrame(year);

        //if category not in colorMap, insert it with a color
        if (colorMap.count(category) == 0) {
          colorMap.insert({category, COLORS[color % 7]});
          color++;
        }
      }
      if (size == capacity) { // if capacity is finished, double it
        int cap = capacity * 2;
        BarChart *new_bc = new BarChart[cap];
        
        for (int i = 0; i < size; i++) {
          new_bc[i] = barcharts[i];
        }
        delete[] barcharts;
        capacity = cap;
        barcharts = new_bc;
        new_bc = nullptr;
      }
      barcharts[size] = bc;
      size++;
  }

    // animate:
    // this function plays each frame stored in barcharts.  In order to see the
    // animation in the terminal, you must pause between each frame.  To do so,
    // type:  usleep(3 * microsecond);
    // Additionally, in order for each frame to print in the same spot in the
    // terminal (at the bottom), you will need to type: output << CLEARCONSOLE;
    // in between each frame.
	void animate(ostream &output, int top, int endIter, int speed) {
		unsigned int microsecond = 50000;
    if (speed != 50000) { //the speed of the animation
      microsecond = speed;
    }
        
    if (endIter == -1) {
      endIter = size;
    }
    
    for (int i = 0; i < endIter; i++) {
      usleep(3 * microsecond);
      output << CLEARCONSOLE;
      output << WHITE << title << endl;
      output << WHITE << source << endl;

      barcharts[i].graph(output, colorMap, top);

      output << WHITE << xlabel << endl;
      output << WHITE << "Frame: " << barcharts[i].getFrame() << endl;
    }
	}

    //
    // Public member function.
    // Returns the size of the BarChartAnimate object.
    //
    int getSize(){
        return size; 
    }

    // Public member function.
    // Returns BarChart element in BarChartAnimate.
    // This gives public access to BarChart stored in the BarChartAnimate.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChartAnimate: i out of bounds"
    BarChart& operator[](int i){
        //BarChart bc;
        if(i>size || i<0){
            throw out_of_range("BarChartAnimate: out of bounds");
        }
        
        return barcharts[i];
    }
};
