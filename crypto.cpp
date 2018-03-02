#include "crypto.hpp"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>

string Crypt::encrypt(const string s) 
{
  string enc = "";
  for (char l : s) 
    if (letters.find(l) != string::npos)
      enc += m[l];
    else
      enc += l;  
  return enc;
}

string Crypt::decrypt(const string s)
{
  map<char, char> reverseMap;
  for (auto pair : m)
     reverseMap[pair.second] = pair.first;

  string dec = "";
  for (char l : s) 
    if (letters.find(l) != string::npos)
      dec += reverseMap[l];
    else
      dec += l;  
  return dec;
}

void Crypt::randomize()
{
  string sh = letters;
 // obtain a time-based seed:
  unsigned seed = chrono::system_clock::now().time_since_epoch().count();

  shuffle(sh.begin(), sh.end(), default_random_engine(seed));
  for (unsigned int i=0; i< letters.length(); i++)
    m[letters[i]] = sh[i];

}

bool Crypt::load(const string fileName)
{
  bool result;
  ifstream file;
  file.open(fileName);
  char c1, c2;
  if ((result = file.good())) {
    while (file >> c1 >> c2 ) 
      m[c1] = c2;    
    file.close();
  } 
  return result;
}

bool Crypt::save(const string fileName)
{
  bool result;
  ofstream file(fileName);

  if ((result = file.good())) {
    for (auto p : m) {
      file << p.first << p.second << endl;
      file.flush();
    };
    file.close();
  };
  return result;
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

