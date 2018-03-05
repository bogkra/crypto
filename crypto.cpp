#include "crypto.hpp"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>

string Crypt::encrypt(const string s) 
{
  string result = "";
  for (char l : s) {
    auto pos = letters.find(l);
    if (pos != string::npos)
      result += code.at(pos);
    else
      result += l;    
  }
  return result;
}

string Crypt::decrypt(const string s)
{
  string result = "";
  for (char l : s) {
    auto pos = code.find(l);
    if (pos != string::npos)
      result += letters.at(pos);
    else
      result += l;  
  }
  return result;
}

void Crypt::randomize()
{
  unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  shuffle(code.begin(), code.end(), default_random_engine(seed));
}

bool Crypt::load(const string fileName)
{
  bool result;
  ifstream file;
  file.open(fileName);

  if ((result = file.good())) {
    file >> code;
    file.close();
  } 
  return result;
}

bool Crypt::save(const string fileName)
{
  bool result;
  ofstream file(fileName);

  if ((result = file.good())) {
    file << code;
    file.close();
  };
  return result;
}

Crypt::Crypt()
{
  letters.insert(letters.end(), 'z' - 'A' + 1, ' ');
  iota(letters.begin(), letters.end(), 'A');   
  letters = letters + " .:,;!?"; 
  cout << letters;
  code = letters;
  randomize();
}

void Crypt::show()
{
  cout << endl;
}

