#include <map>
using namespace std;

/* (C) 2018 Boguslaw Krawczuk */


enum Direction
{
  dir_enc,
  dir_dec
};


class Crypt //: map<char,char> ?
{
public:
  string encrypt(const string& s) const;
  string decrypt(const string& s) const;
  void randomize();
  bool load(const string& fileName);
  bool save(const string& fileName) const;
  void show() const;
  Crypt();
private:
  string letters = "", code = "";
  string crypt(const string& s, const Direction dir) const;
};
