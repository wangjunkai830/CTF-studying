#include <iostream>
#include <fstream>
using namespace std;
void bintoascill(int num[], int num_size){
    int ch;
    ch = 0;
    for(int i = 0; i < num_size; i++){
        ch |= num[i];
        if(i%8 == 7){
            cout << (char)ch;
            ch = 0;
        }
        else ch <<= 1;
    }
    cout<<endl;
}
int main(int argc, char const *argv[]) {

    std::ifstream infile;
    char *buffer;
    int Plaintext[288], Ciphertext[288], SecretMessage[288];
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

    int P0[144], P1[144], C0[144], C1[144], S0[144], S1[144];
    for(int i = 0; i < 144; i++){
        P0[i] = Plaintext[i];
        P1[i] = Plaintext[144+i];
        C0[i] = Ciphertext[i];
        C1[i] = Ciphertext[144+i];
        S0[i] = SecretMessage[i];
        S1[i] = SecretMessage[144+i];
    }

    int key1[144], key2[144], flag0[144], flag1[144];
    // key = C0 xor P0
    for(int i = 0; i < 144; i++)
        flag0[i] = C0[i] ^ P0[i] ^ S0[i];
    cout << "test 1:";bintoascill(flag0,144);
    for(int i = 0; i < 144; i++)
        flag0[i] = C0[i] ^ P0[i] ^ S1[i];
    cout << "test 2:";bintoascill(flag0,144);
    // key = C0 xor P1
    for(int i = 0; i < 144; i++)
        flag1[i] = C0[i] ^ P1[i] ^ S0[i];
    cout << "test 3:";bintoascill(flag0,144);
    for(int i = 0; i < 144; i++)
        flag1[i] = C0[i] ^ P1[i] ^ S1[i];
    cout << "test 4:";bintoascill(flag0,144);
    // key = C1 xor P0
    for(int i = 0; i < 144; i++)
        flag0[i] = C1[i] ^ P0[i] ^ S0[i];
    cout << "test 5:";bintoascill(flag0,144);


    for(int i = 0; i < 144; i++)
        flag0[i] = C1[i] ^ P0[i] ^ S1[i];
    cout << "test 6:";bintoascill(flag0,144);
    for(int i = 0; i < 144; i++)
        flag1[i] = C0[i] ^ P0[i] ^ P1[i] ^ flag0[i] ^ S0[i];
    cout << "test 6-1:";bintoascill(flag1,144);
    for(int i = 0; i < 144; i++)
        flag1[i] = C1[i] ^ P0[i] ^ P1[i] ^ flag0[i] ^ S0[i];
    cout << "test 6-2:";bintoascill(flag1,144);
    // key = C1 xor P1
    for(int i = 0; i < 144; i++)
        flag1[i] = C1[i] ^ P1[i] ^ S0[i];
    cout << "test 7:";bintoascill(flag0,144);
    for(int i = 0; i < 144; i++)
        flag1[i] = C1[i] ^ P1[i] ^ S1[i];
    cout << "test 8:";bintoascill(flag0,144);
    /*
    // key = C0 xor P0 xor P1
    for(int i = 0; i < 144; i++){
    }
    */
    cout << "press antkeying to continue...\n";
    cin.ignore();
    return 0;
}
