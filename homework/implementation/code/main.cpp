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
    if (argc < 2)
    {
        std::cout << "task5 <n> <s1> ... <sn>" << '\n';
        std::cout << "message chunks are the whole message divided into 3 parts." << '\n';
        return 1;
    }
    int n = std::atoi(argv[1]);
    std::cout << "n is: " << n << '\n';
    if (argc - 2 != n) {
        std::cout << "not enough strings" << '\n';
        return 1;
    }
    auto cipher = new Cipher();
    for (int i = 0; i < n; ++i) {
        std::string msg = argv[i + 2];
        std::cout << "chunk is: " << msg << '\n';
        std::promise<string> out_msg;
        auto out = out_msg.get_future();
        std::thread a(&process, *cipher, msg, std::move(out_msg));
        a.join();
        std::cout << "cipher is: " << out.get() << '\n';
    }
//
//    std::string msg1 = argv[1];
//    std::string msg2 = argv[2];
//    std::string msg3 = argv[3];
//
//    std::promise<string> out_msg1;
//    std::promise<string> out_msg2;
//    std::promise<string> out_msg3;
//
//    Cipher* cipher = new Cipher();
//    auto out1 = out_msg1.get_future();
//    auto out2 = out_msg2.get_future();
//    auto out3 = out_msg3.get_future();
//
//    std::thread f1(&process, *cipher, msg1, std::move(out_msg1));
//    std::thread f2(&process, *cipher, msg2, std::move(out_msg2));
//    std::thread f3(&process, *cipher, msg3, std::move(out_msg3));
//
//    f1.join();
//    f2.join();
//    f3.join();
//
//    std::cout << out1.get() << '\n';
//    std::cout << out2.get() << '\n';
//    std::cout << out3.get() << '\n';
}