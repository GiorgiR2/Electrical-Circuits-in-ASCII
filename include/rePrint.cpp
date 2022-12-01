
#include "./Schematics.h"

string Schematics::topLL(){
	// Z; S; I; f;
	const char f = 159;	// f but pretty
	
	const char ttl = 201; // top left angle
	const char ttr = 187; // top right angle
	const char tta = 203; // top angle
	
	const char tbl = 200; // bottom left angle
	const char tbr = 188; // bottom right angle
	const char tba = 202; // bottom angle
	
	const char th = 205; // horizontal line
	const char tv = 186; // vertical line
	
	return ttl + string(34, th) + tta + string(34, th) + ttr + "\n" +
	       tv + "                                  " + tv + " output:                          " + tv + "\n" +
		   tv + "         CALCULATE CIRCUIT        " + tv + " Z=" + Z + string(31-Z.length(), space) + tv + "\n" +
		   tv + "                                  " + tv + " S=UI=" + S + string(28-S.length(), space) + tv + "\n" +
		   tv + "                                  " + tv + " I=" + I +string(31-I.length(), space) + tv + "\n" +
		   tv + "  Voltage = " + voltage + string(22-voltage.length(), ' ') + tv + " " + f + "=" + freq + string(31-freq.length(), ' ') + tv + "\n" +
		   tbl + string(34, th) + tba + string(34, th) + tbr + "\n";
}

void Schematics::rePrint(vector<vector<vector<string>>> circuitData){
	system("cls");
	cout << topLL();
	// if (longest != 0)
	// draw(circuitData);
}

void Schematics::draw(vector<vector<vector<string>>> V){
	int elementsNum, vectSize=V.size();
	for (int i=0; i<V.size(); i++){
		elementsNum = V[i].size();
		addToFirstLine(elementsNum, vectSize, V[i][0][0], V[i][0][1]);
		addMainPart(elementsNum, V[i]);
		addSpaces(elementsNum);
	}
	
	printSchematics(vectSize);
	clearVars();
}
