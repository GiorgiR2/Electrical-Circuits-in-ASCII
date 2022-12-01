#include "./Schematics.h"

void Schematics::addToFirstLine(int elementsNum, int vectSize, string type0, string data0){
    if (elementsNum == longest)
        firstLine += EmptyTitle0(type0, data0);
    else
        firstLine += string(10, space);
}

void Schematics::addMainPart(int elementsNum, vector<vector<string>> V){
    if (center-elementsNum >= 0)
        schematics[center-elementsNum] += EmptyTitle1(V[0][0], V[0][1]);
    if (elementsNum == 1)
        schematics[center] += SingleComponent(V[0][0]);
    else if (elementsNum % 2 == 0){
        schematics[center] += CenterEmptyPart(V[elementsNum/2][0], V[elementsNum/2][1]);

        // add first and the last parts
        schematics[center-elementsNum+1] += TopPart(V[0][0]);
        schematics[center+elementsNum-1] += BottomPart(V[elementsNum-1][0]);
        if (elementsNum > 2)
            schematics[center-elementsNum+2] += MiddleEmptyPart(V[1][0], V[1][1]);
        
        int extraSpace = (cols-(elementsNum*2-1))/2;
        for (int m=1; m<elementsNum-1; m++){
            schematics[extraSpace+m*2] += MiddlePart(V[m][0]);
            if (extraSpace+m*2+1 != center)
                schematics[extraSpace+m*2+1] += MiddleEmptyPart(V[m+1][0], V[m+1][1]);
        }
    }
    else {
        schematics[center] += CenterCrossPart(V[(elementsNum-1)/2][0]);
        schematics[center+1] += MiddleEmptyPart(V[(elementsNum-1)/2+1][0], V[(elementsNum-1)/2+1][1]);

        // add first and the last parts
        schematics[center-elementsNum+1] += TopPart(V[0][0]);
        schematics[center+elementsNum-1] += BottomPart(V[elementsNum-1][0]);
        schematics[center-elementsNum+2] += MiddleEmptyPart(V[1][0], V[1][1]);
        
        int extraSpace = (cols-(elementsNum*2-1))/2;
        for (int m=1; m<(elementsNum-1)/2; m++){
            schematics[extraSpace+m*2] += MiddlePart(V[m][0]);
            schematics[extraSpace+m*2+1] += MiddleEmptyPart(V[m+1][0], V[m+1][1]);
        }
        for (int m=(elementsNum-1)/2+1; m<elementsNum-1; m++){
            schematics[extraSpace+m*2] += MiddlePart(V[m][0]);
            schematics[extraSpace+m*2+1] += MiddleEmptyPart(V[m+1][0], V[m+1][1]);
        }
    }
}

void Schematics::Init(int longest0){
	longest = longest0;
	cols = longest*2 - 1;
	center = (cols-1)/2;
	schematics.resize(cols);
	
	firstLine = string(7, space);
	
	// add empty spaces
	for (int l=0; l<cols; l++)
		if (l != center)
			schematics[l] += "  ";
	schematics[center] = string(2, TX);
}

// Schematics::Schematics(){
// }

string Schematics::SingleComponent(string type){
	string data = "";
	if (type == "c" || type[1] == 'c')
		return data+TX+TX+TX+TX+CL+CR+TX+TX+TX+TX;
	return data+TX+TX+string(6, cube)+TX+TX;
}

string Schematics::TopPart(string type){
	string data = "";
	if (type == "c" || type[1] == 'c')
		return data+TL+TX+TX+TX+CL+CR+TX+TX+TX+TR;;
	return data+TL+TX+string(6, cube)+TX+TR;
}

string Schematics::BottomPart(string type){
	string data = "";
	if (type == "c" || type[1] == 'c')
		return data+BL+TX+TX+TX+CL+CR+TX+TX+TX+BR;
	return data+BL+TX+string(6, cube)+TX+BR;
}

string Schematics::MiddlePart(string type){
	string data = "";
	if (type == "c" || type[1] == 'c')
		return data+CR+TX+TX+TX+CL+CR+TX+TX+TX+CL;;
	return data+CR+TX+string(6, cube)+TX+CL;
}

string Schematics::EmptyTitle0(string type, string n){ // size 10
	string data = "";
	string label = (type == "c" || type[1] == 'c') ? n + "F" : n + ohm;
	int length = label.length();
	if (length % 2 == 0)
		return data+string(8/2-length/2+1, ' ')+label+string(8/2-length/2+1, ' ');
	return data+string(8/2-(length-1)/2+1, ' ')+label+string(8/2-(length+1)/2+1, ' ');
}

string Schematics::EmptyTitle1(string type, string n){ // size 8;
    // oriT naklebi unda iyos amis sigrZe, imis gamo rom boloSi 2 speici emateba, ar vici ratom
	string data = "";
	string label = (type == "c" || type[1] == 'c') ? n + "F" : n + ohm;
	int length = label.length();
	if (length % 2 == 0)
		return data+string(8/2-length/2+1, ' ')+label+string(8/2-length/2-1, ' ');
	return data+string(8/2-(length-1)/2+1, ' ')+label+string(8/2-(length+1)/2-1, ' ');
}

string Schematics::MiddleEmptyPart(string type, string n){
	string data = "";
	string label = (type == "c" || type[1] == 'c') ? n + "F" : n + ohm;
	int length = label.length();
	if (length % 2 == 0)
		return data+LX+string(8/2-length/2, ' ')+label+string(8/2-length/2, ' ')+LX;
	return data+LX+string(8/2-(length-1)/2, ' ')+label+string(8/2-(length+1)/2, ' ')+LX;
}

string Schematics::CenterEmptyPart(string type, string n){
	string data = "";
	string label = (type == "c") ? n + "F" : n + ohm;
	int length = label.length();
	if (length % 2 == 0)
		return data+CL+string(8/2-length/2, ' ')+label+string(8/2-length/2, ' ')+CR;
	return data+CL+string(8/2-(length-1)/2, ' ')+label+string(8/2-(length+1)/2, ' ')+CR;
}

string Schematics::CenterCrossPart(string type){
	string data = "";
	if (type == "c" || type[1] == 'c')
		return data+cross+TX+TX+TX+CL+CR+TX+TX+TX+cross;
	return data+cross+TX+string(6, cube)+TX+cross;
}

void Schematics::addSpaces(int elementsNum){
//	cout << "space: " << (cols-(elementsNum*2-1))/2-1 << endl;
	for (int m=0; m<(cols-(elementsNum*2-1))/2; m++){
		if (m == (cols-(elementsNum*2-1))/2-1 && longest > elementsNum)
			schematics[m] += string(2, space);
		else
			schematics[m] += string(10, space);
		schematics[cols-m-1] += string(10, space);
	}
}

void Schematics::printSchematics(int vectSize){
	cout << firstLine << endl;
	int spaceStart = 2;
	for (int i=0; i<cols; i++){
		if (i == center)
     		cout << string(spaceStart, space) << string(3, TX) << schematics[i] << TX << TR << endl;
     	else if (i > center)
     	    cout << string(spaceStart, space) << string(3, space) << schematics[i] << space << LX << endl;
     	else
     	    cout << string(spaceStart, space) << string(3, space) << schematics[i] << space << space << endl;
	}
	
	cout << string(vectSize*12+4+spaceStart-(vectSize-1)*2, space) << LX << endl;
	cout << string(spaceStart, space) << string(vectSize*12+4-(vectSize-1)*2, TX) << BR << endl;
}
