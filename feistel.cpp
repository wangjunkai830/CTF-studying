#include <iostream>
#include <fstream>
using namespace std;
void bintoascill(int num[144]){

}
int main(int argc, char const *argv[]) {

    std::ifstream infile;
    char *buffer;
    int Plaintext[288], Ciphertext[288], SecretMessage[288];
    int P0[144], P1[144], C0[144], C1[144], S0[144], S1[144];
    int buffer_size = 0;

    // read Trend-Micro-Plaintext-Ciphertext-Pair.txt
    infile.open("Trend-Micro-Plaintext-Ciphertext-Pair.txt", ifstream::in | ifstream::binary);
    buffer_size = 600;
    buffer = new char[buffer_size];
    if(infile){
        infile.read(buffer, buffer_size);
        for(int i = 0; i < 288; i++){
            Plaintext[i] = buffer[11 + i] - '0';
            Ciphertext[i] = buffer[312 + i] - '0';
        }
        delete[] buffer;
    }
    infile.close();

    // read Trend-Micro-CTF-Secret-Message.txt
    infile.open("Trend-Micro-CTF-Secret-Message.txt", ifstream::in | ifstream::binary);
    buffer_size = 304;
    buffer = new char[buffer_size];
    if(infile){
      infile.read(buffer, buffer_size);
      for(int i = 0; i < 288; i++)
          SecretMessage[i] = buffer[16+i] - '0';
      delete[] buffer;
    }
    infile.close();





    for(int i = 0; i < 288; i++)
        cout<<SecretMessage[i];
    cout<<endl;

    cout << "press antkeying to continue...\n";
    cin.ignore();
    return 0;
}
