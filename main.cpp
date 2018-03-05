#include "crypto.hpp"
#include <iostream>
using namespace std;
/* (C) 2018 Boguslaw Krawczuk */

int main()
{
  const string file = "plik.txt";  
  Crypt crypt;
  crypt.show();
  crypt.randomize();
  crypt.show();
  const string s = "GAIVS IVLIVS CAESAR";
  cout << s << " : " << crypt.encrypt(s) << " -> " << crypt.decrypt(crypt.encrypt(s)) << endl;
  if (crypt.save(file)) {
    crypt.randomize();
    crypt.show();
    if (crypt.load(file)) 
      crypt.show();  
  }
 
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
