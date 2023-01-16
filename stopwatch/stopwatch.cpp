#include "stopwatch.hpp"

const long ms_in_second=1000;
const long ms_in_minute=60*ms_in_second;
const long ms_in_hour=60*ms_in_minute;

using std_hours=std::chrono::hours;
using std_minutes=std::chrono::minutes;
using std_seconds=std::chrono::seconds;
using std_milliseconds=std::chrono::milliseconds;

void sleep_for(std_milliseconds ms={});
void sleep_for(std_seconds s={});
void sleep_for(std_minutes m={});
void sleep_for(std_hours h={});

//void formatted_time(
//    std::chrono::time_point<std::chrono::system_clock> tp1=std::chrono::high_resolution_clock::now(), 
//    std::chrono::time_point<std::chrono::system_clock> tp2={}
//    );

void stopwatch(){

}

void sleep_for(std_milliseconds ms){
    std::this_thread::sleep_for(ms);
}

void sleep_for(std_seconds s){
    std::this_thread::sleep_for(s);
}

void sleep_for(std_minutes m){
    std::this_thread::sleep_for(m);
}

void sleep_for(std_hours h){
    std::this_thread::sleep_for(h);
}

std::string formatted_time(std::chrono::time_point<std::chrono::system_clock> tp1, std::chrono::time_point<std::chrono::system_clock> tp2){
    auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(tp2-tp1).count();
    
    long h=ms/ms_in_hour, m=ms/ms_in_minute, s=ms/ms_in_second;
    ms%=ms_in_second;

    std::string str_h{""}, str_m{""}, str_s{}, str_ms{};
    str_h=(0<=h && h<10) ? "0"+std::to_string(h): std::to_string(h);
    str_m=(0<=m && m<10) ? "0"+std::to_string(m): std::to_string(m);
    str_s=(0<=s && s<10) ? "0"+std::to_string(s): std::to_string(s);
    str_ms=(0<=ms && ms<10) ? "00"+std::to_string(ms): (10<=ms && ms<100) ? "0"+std::to_string(ms) : std::to_string(ms);

    return str_h+"."+str_m+"."+str_s+":"+str_ms;
}