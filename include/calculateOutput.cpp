#include "./Schematics.h"

#include <cmath>
#include <string>

using namespace std;

bool Schematics::isAlternating(){
	if (getVoltage().find("sin(") < 10){
//		setVoltage("4");
		return true;
	}
	return false;
}

void Schematics::calculateOutput(vector<vector<vector<string>>> V){
	double volts = isAlternating() ? stod(getVoltage())/sqrt(2) : stod(getVoltage());
	double freq0 = 0;
	if (isAlternating()){
		freq0 = 314 / 6.28;
		setFreq(to_string(freq0));
	}
	else
		setFreq("0");

	double R;
	double z = 0, resistanceOfParallels = 0, NR = 0, Xc = 0; 
	for (int j=0; j<V.size(); j++){
		for (int i=0; i<V[j].size(); i++){
			if (V[j][i][0] == "c" || V[j][i][0][1] == 'c'){
				Xc += (1/(3.14*2*50*stof(V[j][i][1])));
			}
			else{
				NR += (1/stof(V[j][i][1]));
			}
		}
		cout << "Resistence of capacitors : " << Xc << endl;
		R = 1/NR;
		cout<< "Resistence of resistors : " << R << endl;
		z = sqrt(pow(R, 2)+pow(Xc, 2));
		Xc = 0;
		NR = 0;
		resistanceOfParallels += z;
	}
	string res = to_string(resistanceOfParallels);
	setZ(res);
	
	double i0 = volts / resistanceOfParallels;
	string i00 = to_string(i0);
	setI(i00);
	
	double s0 = volts * i0;
	string s00 = to_string(i0);
	setS(s00);
	
	cout << "I: " << i00 << endl;
	cout << "Z: " << resistanceOfParallels << endl;
	// string resAlg = to_string(Z).substr(0, 4);

	 rePrint(V);
}
