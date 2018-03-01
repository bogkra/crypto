#include <map>
using namespace std;

class Crypt //: map<char,char>
{
public:
  map<char, char> m;

  string encrypt(const string s);
  string decrypt(const string s);
  void randomize();
  bool load(const string file);
  bool save(const string file);
  void show();
  Crypt();
private:
  const string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string code = letters;
};
