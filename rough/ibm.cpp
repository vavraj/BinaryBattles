#include <iostream>
#include<vector>
using namespace std;

string binaryToIp(const string &binaryStr) {
    string ipAddress = "";
    
    // Convert each 8-bit chunk of the 32-bit binary string to decimal
    for (int i = 0; i < 32; i += 8) {
        bitset<8> chunk(binaryStr.substr(i, 8));  // Extract 8-bit chunk
        ipAddress += to_string(chunk.to_ulong()); // Convert to decimal and append
        if (i < 24) ipAddress += ".";  // Add dots between the decimal numbers
    }
    
    return ipAddress;
}
vector<string> parseAddress(vector<string>packetData){
    string line1=packetData[0];
    string line2=packetData[1];
    string line3=packetData[2];


    vector<string>ans;

    int version=bitset<4>(line1.substr(0, 3)).to_ulong();
    string ver=to_string(version);
    int protocol=bitset<8>(line1.substr(4, 12)).to_ulong();
    string pro="UDP";
    if(protocol==6){
        pro="TCP";
    }

    int ttl =bitset<8>(line1.substr(13, 20)).to_ulong();
    string time=to_string(ttl);
    int packetLength =bitset<12>(line1.substr(20, 31)).to_ulong();
    string plen=to_string(packetLength);


    string header=ver+","+pro+","+time+","+plen;

    string source=binaryToIp(packetData[1]);
    string destination=binaryToIp(packetData[2]);

    ans.push_back(header);
    ans.push_back(source);
    ans.push_back(destination);
    
    
    return ans;

}
int main()
{
    vector<string>dataPacket;
    dataPacket.push_back("01000000011000110000000000011000");
    dataPacket.push_back("11000001010101000000101110110101");
    dataPacket.push_back("11000001010101000000101101001111");

    for(auto i:parseAddress(dataPacket)){
        cout<<i<<endl;
    }

    return 0;
}