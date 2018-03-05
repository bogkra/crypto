#include <map>
using namespace std;

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
};
