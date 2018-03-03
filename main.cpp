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

Exercise 12B:
B. Divisors Finder
Requirements:
1. Generate N random values (int numbers from 0 to M)
2. Generate all prime numbers from 0 to M
3. Create a map Prime-> Values , where Prime is a divisor of Value. (eg . 3 -> [6,9]  where 6,9 are generated random numbers )
4. Input data: N, M (from cin )

Use as much STL as possible :smiley:


*/
