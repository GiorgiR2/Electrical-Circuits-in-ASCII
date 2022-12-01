#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "./functions/calculateOutput.cpp"
#include "./functions/Schematics.cpp"
#include "./functions/rePrint.cpp"

using namespace std;

void printCircuitData(vector<vector<vector<string>>>);

int main(){
	int inParallel=1, longest=0;

	vector<vector<vector<string>>> circuitData;
	
	Schematics* schematics0 = new Schematics();
	cout << schematics0->topLL();

	// input voltage
	string voltage;
	cout << "Voltage (50 or 50sin(100t+90)> "; cin >> voltage;
	schematics0->setVoltage(voltage);

	int inputData;
	while (inParallel != 0){
		cout << "Number of Components> ";
		cin >> inParallel;

		if (inParallel > longest)
			longest = inParallel;

		vector<vector<string>> newVect(inParallel);
		for (int i=0; i<inParallel; i++){
			string type, data;
			cout << "input {" << i+1 << "} (componentType, data)> ";
			getline(cin, type, ' ');
			getline(cin, data);

			vector<string> element{type, data};
			newVect[i] = element;
		}
		circuitData.push_back(newVect);

		if (inParallel != 0){
			schematics0->calculateOutput(circuitData);
			schematics0->Init(longest);
			schematics0->draw(circuitData);
			// printCircuitData(circuitData);
		}
	}
	
	return 0;
}

void printCircuitData(vector<vector<vector<string>>> V){
	for (int j=0; j<V.size(); j++){
		for(int i=0; i<V[j].size(); i++){
			cout << setw(5) << V[j][i][0] << setw(3) << V[j][i][1];

		}
		cout << endl;
	}
}
