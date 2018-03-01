#include "crypto.hpp"
#include <algorithm>
#include <chrono>
#include <iostream>
//#include <string>
//#include <bitset>

string Crypt::encrypt(const string s) 
{
  string enc = "";
  for (char l : s) {
   if (letters.find(l) != string::npos)
    enc += m[l];
   else
    enc += l;
  }
  return enc;
}

string Crypt::decrypt(const string s)
{
}

void Crypt::randomize()
{
  string s2 = letters;
 // obtain a time-based seed:
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

  shuffle(s2.begin(), s2.end(), default_random_engine(seed));
  int i=0;
  for (auto it=letters.begin(); it!=letters.end(); it++, i++)
    m[letters[i]] = s2[i];

}

bool Crypt::load(const string file)
{
}

bool Crypt::save(const string file)
{
}

Crypt::Crypt()
{
  for (char l: letters)
     m[l] = l;
}

void Crypt::show()
{
  for (char l: letters)
   cout << l << ":" << m[l] << " ";
 cout << endl;
}

