#include <map>
using namespace std;

/* (C) 2018 Bogusław Krawczuk */

enum Direction
{
  encr,
  decr
};



class Crypt //: map<char,char>
{
public:
  string encrypt(const string s);
  string decrypt(const string s);
  void randomize();
  bool load(const string fileName);
  bool save(const string fileName);
  void show();
  Crypt();
private:
  string letters = "";
  string code = letters;
  string crypt(const string s, Direction dir);
};
