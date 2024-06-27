#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
vector <string> city;// input cities
vector <int> Ftemp; // input value 
vector <int> Ctemp;// converted value 
// function to convert far. temp to celicus
int FToC(int tempF){
    int i ;
    int tempC = (tempF -32)*5/9; // convert f to c 
    return tempC;
}
int main() {
  int tempC;
  int result;
  string Tcity; // temp city variable 
  int tempF; // temp variable to store the values in 
  int i ;
  int j;
   ifstream inFS; // input filestream
   ofstream outFS;

cout << "Opening file: FahrenheitTemperature.txt" << endl;
inFS.open("FahrenheitTemperature.txt");
outFS.open("CelsiusToFahrenheit.txt");
if(!inFS.is_open()){
    cout << "Could not open file FahrenheitTemperature.txt" << endl;
    return 1;
}
cout << "Reading Cities and Temperatures from FahrenheitTemperature.txt " << endl;
  
   while (inFS >> Tcity >> tempF){
     city.push_back(Tcity);
     Ftemp.push_back(tempF);
     
}
if (!inFS.eof()) {
      cout << "Input failure before reaching end of file." << endl;
   }
   cout << "Closing File: FahrenheitTemperature.txt" << endl;

inFS.close();
if(!outFS.is_open()){
  cout << "Failure to open CelsiusToFahrenheit"<< endl;  
} //done with it so close it 
  
    for(i = 0; i < Ftemp.size(); ++i){
   		result = FToC(Ftemp.at(i));
      Ctemp.push_back(result);
    }
         for(i=0; i < city.size(); ++i){
    outFS << city.at(i) << " " << Ctemp.at(i)<<endl;
    } 
 outFS.close();
}