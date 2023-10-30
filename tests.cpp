// Shehriar Burney
// UIN - 679754208

#include <iostream>
//#include "bar.h" //remove after testing ms1
//#include "barchart.h" //remove after testing ms2
#include "barchartanimate.h" //add back after testing ms1 and ms2
using namespace std;


/*---------------------------------------------Milestone 1 tests---------------------------------------------*/

bool testBarDefaultConstructor() {
	Bar b;
    if (b.getName() != "") {
    	cout << "testBarDefaultConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 0) {
    	cout << "testBarDefaultConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "") {
    	cout << "testBarDefaultConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarDefaultConstructor: all passed!" << endl;
    return true;
}

bool testBarParamConstructor() {
	Bar b("Chicago", 9234324, "US");
    if (b.getName() != "Chicago") {
    	cout << "testBarParamConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 9234324) {
    	cout << "testBarParamConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "US") {
    	cout << "testBarParamConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarParamConstructor: all passed!" << endl;
    return true;
}

bool Milestone1_test(){
	Bar b1("Karachi", 64464656, "Pakistan");
	Bar b2("Ahmedabad", 56551, "India");
  Bar b3("Naperville", 56551, "US");  // same population different names and countries as b2
  //
  // < OPERATOR
  //
  int count = 0;
	if(b1.getName()<b2.getName()){
		cout<<"Milestone One: getName < operator failed"<<endl;
		return false;
	}
	else if(b1.getValue()<b2.getValue()){
		cout<<"Milestone One: getValue < operator failed"<<endl;
		return false;
	}
	else if(b1.getCategory()<b2.getCategory()){
		cout<<"Milestone One: getCategory < operator < failed"<<endl;
		return false;
	} else {
    count++;
  }
  //
  // > OPERATOR
  //
  if (b1.getName() > b3.getName()) {
    cout<<"Milestone One: getName > operator > failed"<<endl;
		return false;
  }
  else if (b2.getValue() > b3.getValue()) {
    cout<<"Milestone One: getValue > operator > failed"<<endl;
		return false;
  }
  else if (b1.getCategory() > b3.getCategory()) {
    cout<<"Milestone One: getCategory > operator > failed"<<endl;
		return false;
  } else {
    count++;
  }
  //
  // <= OPERATOR
  //

  Bar b4("Karachi", 3, "Pakistan");
	Bar b5("Ahmedabad", 3, "India");
  Bar b6("Lahore", 6, "Pakistan");  // same population different names and countries as b2
  
  if (b6.getName() <= b5.getName()) {
    cout<<"Milestone One: getName <= operator <= failed"<<endl;
		return false;
  }
  else if (!(b4.getValue() <= b5.getValue())) {
    cout<<"Milestone One: getValue <= operator <= failed"<<endl;
		return false;
  }
  else if (!(b4.getCategory() <= b6.getCategory())) {
    cout<<"Milestone One: getCategory <= operator <= failed"<<endl;
		return false;
  } else {
    count++;
  }

  //
  // >= OPERATOR
  //
  if (b5.getName() >= b6.getName()) {
    cout<<"Milestone One: getName >= operator >= failed"<<endl;
		return false;
  }
  else if (!(b5.getValue() >= b4.getValue())) {
    cout<<"Milestone One: getValue >= operator >= failed"<<endl;
		return false;
  }
  else if (!(b6.getCategory() >= b4.getCategory())) {
    cout<<"Milestone One: getCategory >= operator >= failed"<<endl;
		return false;
  } else {
    count++;
  }

  if (count == 4) {
    cout<<"All operators milestone 1 test cases passed!"<<endl;
	  return true;
  } else {
    return false;
  }
}

/*---------------------------------------------Milestone 2 tests---------------------------------------------*/

bool testBarChartDefaultConstructor(){
	BarChart b1;
	if(b1.getSize() != 0){
		cout<<"testBarChartDefaultConstructor: getSize failed"<<endl;
		return false;
	}
	else if(b1.getFrame() != ""){
		cout<<"testBarChartDefaultConstructor: getFrame failed"<<endl;
		return false;
	}
	else{
		cout<<"testBarChartDefaulConstructor: all passed"<<endl;
	}
	return true;
}

bool testBarChartParamConstructor(){
	BarChart b1(3);

	for(int i = 0; i<3; i++){
		b1.addBar("name",i,"category");
	}
	if(b1.getSize() != 3){
		cout<<"testBarChartParamConstructor: addBar failed"<<endl;
		return false;
	}
	cout<<"testBarChartParamConstructor: all passed"<<endl;
	return true;
}

// testBarChartGraph()
// Tests to see if the color maps and graph works

void testBarChartGraph() {
  BarChart bc(10);
  bc.addBar("Shehriar", 22, "US");
  bc.addBar("Shayan", 6, "Australia");
  bc.addBar("Shehram", 14, "UAE");
  bc.addBar("Haya", 24, "Netherlands");
  bc.setFrame("2006");

  string GREEN("\033[1;32m");
  string GOLD("\033[1;33m");
  string RED("\033[1;31m");
  string PURPLE("\033[1;35m");
  map < string, string > colorMap;
  colorMap["US"] = GREEN;
  colorMap["Australia"] = RED;
  colorMap["UAE"] = PURPLE;
  colorMap["Netherlands"] = GOLD;
  bc.graph(cout, colorMap, 4);
}

void testBarChartGraph2() {
  BarChart bc(10);
  bc.addBar("Hamilton", 44, "UK");
  bc.addBar("Verstappen", 33, "Holland");
  bc.addBar("Vettel", 5, "Germany");
  bc.addBar("Ricciardo", 3, "Australia");
  bc.setFrame("2022");

  string CYAN("\033[1;36m");
  string GREEN("\033[1;32m");
  string BLUE("\033[1;34m");
  string WHITE("\033[1;37m");

  map < string, string > colorMap;
  colorMap["UK"] = CYAN;
  colorMap["Holland"] = GREEN;
  colorMap["Germany"] = BLUE;
  colorMap["Australia"] = WHITE;
  bc.graph(cout, colorMap, 4);
}


/*---------------------------------------------Milestone 2 tests---------------------------------------------*/

int main() {
	//Milestone 1 tests:
	testBarDefaultConstructor();
	testBarParamConstructor();
	
	Milestone1_test();

  //Milestone 2 tests:
	testBarChartDefaultConstructor();
	testBarChartParamConstructor();
  testBarChartGraph();
  testBarChartGraph2();

  //Milestone 3 test in application.cpp
    return 0;
}