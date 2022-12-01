#ifndef SCHEMATICS_H
#define SCHEMATICS_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Schematics{
	private:
		const char cube = 219;
		const char space = ' ';
		
		// angles
		const char TL = 218; // top left
		const char TR = 191; // top right
		const char BL = 192; // bottom left
		const char BR = 217; // bottom right
		
		// sides
		const char TX = 196;
		const char LX = 179;
		
		// connectors
		const char CT = 193;
		const char CB = 194;
		const char CL = 180;
		const char CR = 195;
		
		const char cross = 197;
		const char ohm = 234;

		string voltage = "No Input";
		string Z="0", S="0", I="0", freq="0";

	public:
		int longest, cols, center;
		string firstLine;
		vector<string> schematics;
		
		// Schematics();
		void Init(int);
		
		string SingleComponent(string);
		string TopPart(string);
		string BottomPart(string);
		string MiddlePart(string);
		string EmptyTitle0(string, string);
		string EmptyTitle1(string, string);
		string MiddleEmptyPart(string, string);
		string CenterEmptyPart(string, string);
		string CenterCrossPart(string);
		
		void addSpaces(int);
		void printSchematics(int);
		
		void addToFirstLine(int, int, string, string);
		void addMainPart(int, vector<vector<string>>);

		void calculateOutput(vector<vector<vector<string>>>);
		bool isAlternating();
		void rePrint(vector<vector<vector<string>>>);
		void draw(vector<vector<vector<string>>>);
		string topLL();

		void setVoltage(string vol){
			voltage = vol;
		}

		void clearVars(){
			for (int i=0; i<schematics.size(); i++)
				schematics[i] = "";
		}

		string getVoltage(){ return voltage; }
		string getFreq(){ return freq; }
		void setZ(string z0){ Z = z0; }
		void setI(string i0){ I = i0; }
		void setS(string s0){ S = s0; }
		void setFreq(string freq0){ freq = freq0; }
};

#endif
