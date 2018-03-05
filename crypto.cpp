#include "crypto.hpp"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>

/* (C) 2018 Bogusław Krawczuk */

string Crypt::crypt(const string s, Direction dir) 
{
  string result = "";
  string s1 = (dir == encr ? letters : code);
  string s2 = (dir == encr ? code : letters);
  for (char l : s) {
    auto pos = s1.find(l);
    if (pos != string::npos)
      result += s2.at(pos);
    else
      result += l;    
  }
  return result;
}

string Crypt::encrypt(const string s) 
{
  return crypt(s, encr);
}


string Crypt::decrypt(const string s)
{
  return crypt(s, decr);
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
    getline(file, code);
    file.close();
  } 
  return result;
}

bool Crypt::save(const string fileName)
{
  bool result;
  ofstream file(fileName);

  if ((result = file.good())) {
    file << code << endl;
    file.close();
  };
  return result;
}

Crypt::Crypt()
{
  letters.insert(letters.end(), 'z' - 'A' + 1, ' ');
  iota(letters.begin(), letters.end(), 'A');   
  letters = letters + " .:,;!?"; 
  code = letters;
  randomize();
}

void Crypt::show()
{
  cout << letters << endl << code << endl << endl;
}

