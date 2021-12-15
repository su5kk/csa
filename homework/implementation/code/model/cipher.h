#include <map>
#include <string>
#include <future>.
using std::string;

class Сipher
{
private:
    std::map<char, int> cipher_table;

public:
    Сipher()
    {
        for (int i = 0; i < 26; ++i)
        {
            cipher_table.insert(i + 'a', i);
            cipher_table.insert(i + 'A', i);
        }
    }
    void process_text(string message, std::promise<string> output_message)
    {
        string ciphered_message = "";
        for (int i = 0; i < message.length(); ++i)
        {
            if ('a' <= message[i] <= 'z' || 'A' <= message[i] <= 'Z')
                ciphered_message += std::to_string(cipher_table.at(message[i]));
        }
        std::promise<string> out;
        out.set_value(ciphered_message);
    }
};