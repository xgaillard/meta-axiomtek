#include <EApiLib.h>
#include <cstdio>
#include <iostream>
#include <fcntl.h>
#include <linux/watchdog.h>



using namespace std;

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

int retrun_status;
uint32_t return_value;

void print_error(int errorcode){
    cout << RED << "error:" << errorcode << RESET << "\n";
}

void print_title (const char* Title){
    cout <<"\n";
    cout <<"\n";
    cout << BOLDYELLOW << "======================" << Title << "======================" << RESET << "\n";
}

void print_value (const char* id, int value){
    cout << CYAN << id << ":" << WHITE  << value << RESET << "\n";
}

void getDI(){
    print_title("getDI");
    retrun_status = EApiGPIOGetLevel(AX_EAPI_DI_0,0,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_DI_0",return_value);
    retrun_status = EApiGPIOGetLevel(AX_EAPI_DI_1,0,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_DI_1",return_value);
    retrun_status = EApiGPIOGetLevel(AX_EAPI_DI,0,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_DI",return_value);
}

void getDO(){
    print_title("getDO");
    retrun_status = EApiGPIOGetLevel(AX_EAPI_DO_0,0,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_DO_0",return_value);
    retrun_status = EApiGPIOGetLevel(AX_EAPI_DO,0,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_DO",return_value);
}

void setDO(){
    print_title("setDO");
    retrun_status = EApiGPIOSetLevel(AX_EAPI_DO,0,0);
    if (retrun_status)print_error(retrun_status);
    retrun_status = EApiGPIOSetLevel(AX_EAPI_DO_0,0,1);
    if (retrun_status)print_error(retrun_status);
}

void getCOM_type(){
    print_title("getCOM_type");
    /*
      1: RS232 Enable 
      2: RS485 2W Enable
      3: RS422 /RS485 4W Enable
    */
    retrun_status = EApiComGetType(AX_EAPI_COM_1,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_COM_1",return_value);
    retrun_status = EApiComGetType(AX_EAPI_COM_2,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_COM_2",return_value);
}

void setCOM_type(){
    print_title("setCOM_type");
    /*
      1: RS232 Enable 
      2: RS485 2W Enable
      3: RS422 /RS485 4W Enable
    */
    retrun_status = EApiComSetType(AX_EAPI_COM_1,1);
    if (retrun_status)print_error(retrun_status);
    retrun_status = EApiComSetType(AX_EAPI_COM_2,2);
    if (retrun_status)print_error(retrun_status);
}

void setCOM_Termination(){
    print_title("setCOM_Termination");
    /*
    0: disable
    1: enable
    */
    retrun_status = EApiComSetTermination(AX_EAPI_COM_1_TERMINATION,1);
    if (retrun_status)print_error(retrun_status);
    retrun_status = EApiComSetTermination(AX_EAPI_COM_2_TERMINATION,1);
    if (retrun_status)print_error(retrun_status);
}

void getCOM_Termination(){
    /*
    0: disable
    1: enable
    */
    print_title("getCOM_Termination");
    retrun_status = EApiComGetTermination(AX_EAPI_COM_1_TERMINATION,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_COM_1_TERMINATION",return_value);
    retrun_status = EApiComGetTermination(AX_EAPI_COM_2_TERMINATION,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_COM_2_TERMINATION",return_value);
}

void wdt_start(){
    print_title("startwdt");
    retrun_status =  EApiWDogStart(0,0,10000);  // 10s
    if (retrun_status)print_error(retrun_status);
}


void trigger_wdt(){
    print_title("trigger_wdt");
    while(1){
        retrun_status =  EApiWDogTrigger();
        if (retrun_status)print_error(retrun_status);
        sleep(3);
    }
}

void stop_wdt(){
    print_title("stop_wdt");
    retrun_status =  EApiWDogStop();
    if (retrun_status)print_error(retrun_status);
}

void getGPIO(){
    print_title("getGPIO");
    retrun_status = EApiGPIOGetLevel(AX_EAPI_RELAY_0,0,&return_value);
    if (retrun_status)print_error(retrun_status);
}

void toggleGPIO(){
    print_title("toggleGPIO");
    int times=0;
    while(times<10) {
        retrun_status = EApiGPIOGetLevel(AX_EAPI_RELAY_0,0,&return_value);
        if (retrun_status)print_error(retrun_status);
        retrun_status = EApiGPIOSetLevel(AX_EAPI_RELAY_0,0, 1 - return_value);
        if (retrun_status)print_error(retrun_status);

        retrun_status = EApiGPIOGetLevel(AX_EAPI_LED_1,0,&return_value);
        if (retrun_status)print_error(retrun_status);
        retrun_status = EApiGPIOSetLevel(AX_EAPI_LED_1,0, 1 - return_value);
        if (retrun_status)print_error(retrun_status);

        retrun_status = EApiGPIOGetLevel(AX_EAPI_LED_2,0,&return_value);
        if (retrun_status)print_error(retrun_status);
        retrun_status = EApiGPIOSetLevel(AX_EAPI_LED_2,0, 1 - return_value);
        if (retrun_status)print_error(retrun_status);

        retrun_status = EApiGPIOGetLevel(AX_EAPI_LED_3,0,&return_value);
        if (retrun_status)print_error(retrun_status);
        retrun_status = EApiGPIOSetLevel(AX_EAPI_LED_3,0, 1 - return_value);
        if (retrun_status)print_error(retrun_status);

        retrun_status = EApiGPIOGetLevel(AX_EAPI_LED_4,0,&return_value);
        if (retrun_status)print_error(retrun_status);
        retrun_status = EApiGPIOSetLevel(AX_EAPI_LED_4,0, 1 - return_value);
        if (retrun_status)print_error(retrun_status);
        times++;
        sleep(1);
    }
}

int main(){
    getDI();
    getDO();
    setDO();
    getDO();
    getDI();
    setCOM_type();
    getCOM_type();
    getCOM_Termination();
    setCOM_Termination();
    // wdt_start();
    // trigger_wdt();
    // stop_wdt();
    toggleGPIO();
    return 0;
}