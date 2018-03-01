#include "crypto.hpp"
#include <iostream>
#include <map>
#include <memory>
using namespace std;

int main()
{
  const string file = "plik.txt";  

  Crypt crypt;

  crypt.show();
  crypt.randomize();
  crypt.show();
  const string s = "IVLIVS CAESAR";
  cout << s << " : " << crypt.encrypt(s) << endl;
 
  return 0;
}

/*
Exercise 12A: Cryptographic application 
Requirements : 
1. Substitution ciphering (map letter -> cipher) 
2. Encryption and decryption 
3. Cipher is generated randomly 
4. Input data: : cin and/or file 
5. Output data: cout and/ or file 
*/
