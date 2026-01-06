#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int hexToInt(char hex) {
    if (hex>= '0' && hex <= '9') {return hex - '0';}
    if (hex >= 'A' && hex <= 'F') {return hex - 'A' + 10;}
    if (hex >= 'a' && hex <= 'f') {return hex - 'a' + 10;}
    return -1;
}

vector<int> hexToBinary(string hexText, int bits){
    if (hexText.length() >= 2 && hexText[0] == '0' && (hexText[1] == 'x' || hexText[1] == 'X')){
        hexText = hexText.substr(2);
    };
    vector<int> binaryVector(bits); //allocate "bits" of vector space

    for (size_t i=0; i< hexText.length(); i++ ) {
        int num = hexToInt(hexText[i]);
        if (num == -1) {
            cout << "Hex Character error occured!"<<endl;
            exit(1);
        }
        for (int j = 0; j < 4; j++) {
            if ((i * 4 + j) < bits) {
                binaryVector[i * 4 + j] = (num >> (3 - j)) & 1;
            }
        }
    }
    return binaryVector;
}

string BinaryToHex(const vector<int>& binaryVector) {
    string hexResult = "0x";
    for (size_t i = 0; i < binaryVector.size(); i += 4) {
        int val = 0;
        for (int j = 0; j < 4; j++) {
            if ((i + j) < binaryVector.size()) {
                val = (val << 1) | binaryVector[i + j];
            }
        }
        if (val < 10)
            hexResult += char('0' + val);
        else
            hexResult += char('A' + (val - 10));
    }
    return hexResult;
}