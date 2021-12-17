#include "model/cipher.h"
#include <iostream>
#include <string>
#include <thread>
#include <future>

void process(Cipher cipher, std::string msg, std::promise<string> promise) {
    cipher.process_text(msg, &promise);
}


int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cout << "task5 msg_chunk1 msg_chunk2 msh_chunk3" << '\n';
        std::cout << "message chunks are the whole message divided into 3 parts." << '\n';
        return 1;
    }
    std::string msg1 = argv[1];
    std::cout << "first chunk: " << msg1 << '\n';
    std::string msg2 = argv[2];
    std::cout << "second chunk: " << msg2 << '\n';
    std::string msg3 = argv[3];
    std::cout << "third chunk: " << msg3 << '\n';

    std::promise<string> out_msg1;
    std::promise<string> out_msg2;
    std::promise<string> out_msg3;

    Cipher* cipher = new Cipher();
    auto out1 = out_msg1.get_future();
    auto out2 = out_msg2.get_future();
    auto out3 = out_msg3.get_future();

    std::thread f1(&process, *cipher, msg1, std::move(out_msg1));
    std::thread f2(&process, *cipher, msg2, std::move(out_msg2));
    std::thread f3(&process, *cipher, msg3, std::move(out_msg3));

    f1.join();
    f2.join();
    f3.join();

    std::cout << out1.get() << '\n';
    std::cout << out2.get() << '\n';
    std::cout << out3.get() << '\n';
}