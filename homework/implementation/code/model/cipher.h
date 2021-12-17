#include <future>
#include <map>
#include <string>
#include <iostream>

using std::string;

class Cipher {
private:
    std::map<char, int> cipher_table;

public:
    Cipher() {
        for (int i = 0; i < 26; ++i) {
            char in_small = char(i + 97);
            cipher_table.insert(std::pair<char, int>(in_small, i));
        }
    }

    void process_text(string message, std::promise<string> *output_message) {
        string ciphered_message = "";
        for (int i = 0; i < message.length(); ++i) {
            if ('a' <= message[i] <= 'z' || 'A' <= message[i] <= 'Z')
                ciphered_message += std::to_string(cipher_table.at(char(message[i])));
        }
        output_message->set_value(ciphered_message);
    }
};