#include <EApiLib.h>
#include <cstdio>
#include <iostream>

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


void getDO_single(){
    print_title("getDO_single");
    retrun_status = EApiGPIOGetLevel(AX_EAPI_DO_0,0,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_DO_0",return_value);
    retrun_status = EApiGPIOGetLevel(AX_EAPI_DO_1,0,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_DO_1",return_value);
    retrun_status = EApiGPIOGetLevel(AX_EAPI_DO_2,0,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_DO_2",return_value);
    retrun_status = EApiGPIOGetLevel(AX_EAPI_DO_3,0,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_DO_3",return_value);
    retrun_status = EApiGPIOGetLevel(AX_EAPI_DO_4,0,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_DO_4",return_value);
    retrun_status = EApiGPIOGetLevel(AX_EAPI_DO_5,0,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_DO_5",return_value);
    retrun_status = EApiGPIOGetLevel(AX_EAPI_DO_6,0,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_DO_6",return_value);
    retrun_status = EApiGPIOGetLevel(AX_EAPI_DO_7,0,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_DO_7",return_value);
}

void getDI_all(){
    print_title("getDI_all");
    retrun_status = EApiGPIOGetLevel(AX_EAPI_DI,0,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_DI",return_value);
}

void getDI_single(){
    print_title("getDI_single");
    retrun_status = EApiGPIOGetLevel(AX_EAPI_DI_0,0,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_DI_0",return_value);
    retrun_status = EApiGPIOGetLevel(AX_EAPI_DI_1,0,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_DI_1",return_value);
    retrun_status = EApiGPIOGetLevel(AX_EAPI_DI_2,0,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_DI_2",return_value);
    retrun_status = EApiGPIOGetLevel(AX_EAPI_DI_3,0,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_DI_3",return_value);
    retrun_status = EApiGPIOGetLevel(AX_EAPI_DI_4,0,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_DI_4",return_value);
    retrun_status = EApiGPIOGetLevel(AX_EAPI_DI_5,0,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_DI_5",return_value);
    retrun_status = EApiGPIOGetLevel(AX_EAPI_DI_6,0,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_DI_6",return_value);
    retrun_status = EApiGPIOGetLevel(AX_EAPI_DI_7,0,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_DI_7",return_value);
}

void setDO_single(int id,uint32_t setvalue){
    print_title("setDO_single");
    retrun_status = EApiGPIOSetLevel(id,0,setvalue);
    if (retrun_status)print_error(retrun_status);
}

void setDO_all(int setvalue){
    print_title("setDO_all");
    retrun_status = EApiGPIOSetLevel(AX_EAPI_DO,0,setvalue);
    if (retrun_status)print_error(retrun_status);
}

void getDO_all(){
    print_title("getDO_all");
    retrun_status = EApiGPIOGetLevel(AX_EAPI_DO,0,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_DO",return_value);
}

void getPowser_DC(){
    print_title("getPowserDC");
    /*
    0: disable
    1: enable
    */
    retrun_status = EApiHWMGetCaps(AX_EAPI_POWER_DC_1,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_POWER_DC_1",return_value);
    retrun_status = EApiHWMGetCaps(AX_EAPI_POWER_DC_2,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_POWER_DC_2",return_value);
}

void getCOM_type(){
    print_title("getCOM_type");
    /*0: RSVD
      1: RS232 Enable 
      2: RS422 /RS485 4W Enable
      3: RS485 2W Enable
    */
    retrun_status = EApiComGetType(AX_EAPI_COM_1,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_COM_1",return_value);
    retrun_status = EApiComGetType(AX_EAPI_COM_2,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_COM_2",return_value);
    retrun_status = EApiComGetType(AX_EAPI_COM_3,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_COM_3",return_value);
    retrun_status = EApiComGetType(AX_EAPI_COM_4,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_COM_4",return_value);
}

void setCOM_type(){
    print_title("setCOM_type");
    /*0: RSVD
      1: RS232 Enable 
      2: RS422 /RS485 4W Enable
      3: RS485 2W Enable
    */
    retrun_status = EApiComSetType(AX_EAPI_COM_1,0);
    if (retrun_status)print_error(retrun_status);
    retrun_status = EApiComSetType(AX_EAPI_COM_2,1);
    if (retrun_status)print_error(retrun_status);
    retrun_status = EApiComSetType(AX_EAPI_COM_3,2);
    if (retrun_status)print_error(retrun_status);
    retrun_status = EApiComSetType(AX_EAPI_COM_4,3);
    if (retrun_status)print_error(retrun_status);
}

void setCOM_Termination(){
    print_title("setCOM_Termination");
    /*0: RSVD
      1: RS232 Enable 
      2: RS422 /RS485 4W Enable
      3: RS485 2W Enable
    */
    retrun_status = EApiComSetTermination(AX_EAPI_COM_1_TERMINATION,0);
    if (retrun_status)print_error(retrun_status);
    retrun_status = EApiComSetTermination(AX_EAPI_COM_2_TERMINATION,1);
    if (retrun_status)print_error(retrun_status);
    retrun_status = EApiComSetTermination(AX_EAPI_COM_3_TERMINATION,1);
    if (retrun_status)print_error(retrun_status);
    retrun_status = EApiComSetTermination(AX_EAPI_COM_4_TERMINATION,0);
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
    retrun_status = EApiComGetTermination(AX_EAPI_COM_3_TERMINATION,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_COM_3_TERMINATION",return_value);
    retrun_status = EApiComGetTermination(AX_EAPI_COM_4_TERMINATION,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_COM_4_TERMINATION",return_value);
}

void setCAN_Termination(){
    print_title("setCAN_Termination");
    /*
    0: disable
    1: enable
    */
    retrun_status = EApiCanSetTermination(AX_EAPI_CAN_0_TERMINATION,0); //disable
    if (retrun_status)print_error(retrun_status);
    retrun_status = EApiCanSetTermination(AX_EAPI_CAN_1_TERMINATION,1); //enable
    if (retrun_status)print_error(retrun_status);
}

void getCAN_Termination(){
    print_title("getCAN_Termination");
    /*
    0: disable
    1: enable
    */
    retrun_status = EApiCanGetTermination(AX_EAPI_CAN_0_TERMINATION,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_CAN_0_TERMINATION",return_value);
    retrun_status = EApiCanGetTermination(AX_EAPI_CAN_1_TERMINATION,&return_value);
    if (retrun_status)print_error(retrun_status);
    print_value("AX_EAPI_CAN_1_TERMINATION",return_value);
}

void startwdt(){
    print_title("startwdt");
    retrun_status =  EApiWDogStart(0,0,10000);  // 10s
    if (retrun_status)print_error(retrun_status);
}

void stopwdt(){
    print_title("stopwdt");
    retrun_status =  EApiWDogStop();
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

void errortest(){
    print_title("errortest");
    //use wrong ID
    printf("--------errortest--------\n");
    retrun_status = EApiGPIOGetLevel(AX_EAPI_CAN_1_TERMINATION,0,&return_value);
    if (retrun_status)print_error(retrun_status);
    printf("----------------\n");
    retrun_status = EApiGPIOSetLevel(AX_EAPI_CAN_1_TERMINATION,0,1);
    if (retrun_status)print_error(retrun_status);
    printf("----------------\n");

    retrun_status = EApiHWMGetCaps(AX_EAPI_CAN_1_TERMINATION,&return_value);
    if (retrun_status)print_error(retrun_status);
    printf("----------------\n");

    retrun_status = EApiComGetTermination(AX_EAPI_CAN_1_TERMINATION,&return_value);
    if (retrun_status)print_error(retrun_status);
    printf("----------------\n");
    retrun_status = EApiComSetTermination(AX_EAPI_CAN_1_TERMINATION,1);
    if (retrun_status)print_error(retrun_status);

    printf("----------------\n");
    retrun_status = EApiComGetType(AX_EAPI_CAN_1_TERMINATION,&return_value);
    if (retrun_status)print_error(retrun_status);
    printf("----------------\n");
    retrun_status = EApiComSetType(AX_EAPI_CAN_1_TERMINATION,1);
    if (retrun_status)print_error(retrun_status);
    
    printf("----------------\n");
    retrun_status = EApiCanGetTermination(AX_EAPI_DI_0,&return_value);
    if (retrun_status)print_error(retrun_status);
    printf("----------------\n");
    retrun_status = EApiCanSetTermination(AX_EAPI_DI_0,1);
    if (retrun_status)print_error(retrun_status);

    printf("----------------\n");
    retrun_status = EApiCanGetTermination(AX_EAPI_DI_0,&return_value);
    if (retrun_status)print_error(retrun_status);
    printf("----------------\n");
    retrun_status = EApiCanSetTermination(AX_EAPI_DI_0,1);
    if (retrun_status)print_error(retrun_status);

    //use not support function
    printf("-------use not support function---------\n");
    printf("----------------\n");
    retrun_status = EApiGPIOSetLevel(AX_EAPI_DI_0,0,1);
    if (retrun_status)print_error(retrun_status);
    printf("----------------\n");
    retrun_status = EApiGPIOSetLevel(AX_EAPI_DI_1,0,1);
    if (retrun_status)print_error(retrun_status);
    printf("----------------\n");
    retrun_status = EApiGPIOSetLevel(AX_EAPI_DI_2,0,1);
    if (retrun_status)print_error(retrun_status);
    printf("----------------\n");
    retrun_status = EApiGPIOSetLevel(AX_EAPI_DI_3,0,1);
    if (retrun_status)print_error(retrun_status);
    printf("----------------\n");
    retrun_status = EApiGPIOSetLevel(AX_EAPI_DI_4,0,1);
    if (retrun_status)print_error(retrun_status);
    printf("----------------\n");
    retrun_status = EApiGPIOSetLevel(AX_EAPI_DI_5,0,1);
    if (retrun_status)print_error(retrun_status);
    printf("----------------\n");
    retrun_status = EApiGPIOSetLevel(AX_EAPI_DI_6,0,1);
    if (retrun_status)print_error(retrun_status);
    printf("----------------\n");
    retrun_status = EApiGPIOSetLevel(AX_EAPI_DI_7,0,1);
    if (retrun_status)print_error(retrun_status);
    printf("----------------\n");
    retrun_status = EApiGPIOSetLevel(AX_EAPI_DI,0,1);
    if (retrun_status)print_error(retrun_status);

    //out of range
    printf("---------out of range-------\n");
    retrun_status = EApiGPIOSetLevel(AX_EAPI_DO_0,0,255);
    if (retrun_status)print_error(retrun_status);
    printf("----------------\n");
    retrun_status = EApiGPIOSetLevel(AX_EAPI_DO_0,0,255);
    if (retrun_status)print_error(retrun_status);
    printf("----------------\n");
    retrun_status = EApiComSetType(AX_EAPI_COM_1,255);
    if (retrun_status)print_error(retrun_status);
    printf("----------------\n");
    retrun_status = EApiComSetTermination(AX_EAPI_COM_1_TERMINATION,255);
    if (retrun_status)print_error(retrun_status);
    printf("----------------\n");
    retrun_status = EApiComSetTermination(AX_EAPI_COM_1_TERMINATION,255);
    if (retrun_status)print_error(retrun_status);
    printf("----------------\n");
    retrun_status =  EApiWDogStart(0,0,61000);
    if (retrun_status)print_error(retrun_status);
    printf("----------------\n");
    retrun_status = EApiCanSetTermination(AX_EAPI_CAN_0_TERMINATION,255);
    if (retrun_status)print_error(retrun_status);
}



int main(){
    getDI_single();
    getDO_single();
    setDO_all(255);
    getDO_all();
    getDI_all();
    setDO_single(AX_EAPI_DO,1);
    getDI_all();
    getPowser_DC();
    setCOM_type();
    getCOM_type();
    setCOM_Termination();
    getCOM_Termination();
    setCAN_Termination();
    getCAN_Termination();
    //startwdt();
    // sleep(5);
    // trigger_wdt();
    // stopwdt();
    // errortest();
    return 0;
}