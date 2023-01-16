#include <chrono>
#include <iostream>
#include <thread>
#include <string>
#include <stdlib.h>

long count(long start_position=0);
void timer();
void sleep_for(std::chrono::milliseconds ms={});
void sleep_for(std::chrono::seconds sec={});

int main(int argc, char* argv[]){
    system("clear");
    timer();
    
}

long count(long start_position){
    static long f_count=start_position;
    return ++f_count;
}

void timer(){

    std::chrono::hours h{};
    std::chrono::minutes m{};
    std::chrono::seconds s{};
    std::chrono::milliseconds ms{};
    
    std::string str_h, str_m, str_s, str_ms;

    auto start_tp{std::chrono::high_resolution_clock::now()};

    while (true){

        str_h=((0<=h.count() && h.count()<10) ? "0"+std::to_string(h.count()): std::to_string(h.count()));
        str_m=((0<=m.count() && m.count()<10) ? "0"+std::to_string(m.count()): std::to_string(m.count()));
        str_s=((0<=s.count() && s.count()<10) ? "0"+std::to_string(s.count()): std::to_string(s.count()));
        
        std::cout<<str_h<<"."<<str_m<<"."<<str_s<<std::endl;
        sleep_for(std::chrono::seconds(1));
        h=std::chrono::duration_cast<std::chrono::hours>(std::chrono::high_resolution_clock::now()-start_tp);
        m=std::chrono::duration_cast<std::chrono::minutes>(std::chrono::high_resolution_clock::now()-start_tp);
        s=std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now()-start_tp);
        
        system("clear");
    }

}

void sleep_for(std::chrono::milliseconds ms){
    std::this_thread::sleep_for(ms);
}
void sleep_for(std::chrono::seconds sec){
    std::this_thread::sleep_for(sec);
}