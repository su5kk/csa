#include "model/cipher.h"
#include <iostream>
#include <string>
#include <thread>
#include <string>
#include <future>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cout << "task5 msg_chunk1 msg_chunk2 msh_chunk3" << '\n';
        std::cout << "message chunks are the whole message divided into 3 parts." << '\n';
        return 1;
    }
    std::string msg1 = argv[0];
    std::string msg2 = argv[1];
    std::string msg3 = argv[2];

    std::promise<string> out_msg1;
    std::promise<string> out_msg2;
    std::promise<string> out_msg3;

    auto cipher = new Cipher();
    auto out1 = out_msg1.get_future();
    auto out2 = out_msg2.get_future();
    auto out3 = out_msg3.get_future();

    std::thread f1(cipher.process_text, msg1, out_msg1);
    std::thread f2(cipher.process_text, msg2, out_msg2);
    std::thread f3(cipher.process_text, msg3, out_msg3);

    f1.join();
    f2.join();
    f3.join();

    std::cout << out1.get() << '\n';
    std::cout << out2.get() << '\n';
    std::cout << out3.get() << '\n';
}