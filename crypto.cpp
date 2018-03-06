#include "crypto.hpp"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>

/* (C) 2018 Boguslaw Krawczuk */


string Crypt::crypt(const string& s, const Direction direction) const
{
  string result = "";
  string keys   = (direction == dir_enc ? letters : code);
  string values = (direction == dir_enc ? code : letters);
  for (char letter : s) {
    auto pos = keys.find(letter);
    if (pos == string::npos)
      result += letter;    
    else
      result += values.at(pos);
  }
  return result;
}


string Crypt::encrypt(const string& s) const
{
  return crypt(s, dir_enc);
}


string Crypt::decrypt(const string& s) const
{
  return crypt(s, dir_dec);
}


void Crypt::randomize()
{
  shuffle(code.begin(), code.end(), default_random_engine(chrono::system_clock::now().time_since_epoch().count()));
}


bool Crypt::load(const string& fileName)
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


bool Crypt::save(const string& fileName) const
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


void Crypt::show() const
{
  cout << letters << endl << code << endl << endl;
}

