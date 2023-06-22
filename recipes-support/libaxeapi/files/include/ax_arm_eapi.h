//============================================================================
// copyright (c) axiomtek, inc - all rights reserved
// unauthorized copying of this file, via any medium is strictly prohibited
// proprietary and confidential
//
// author: aaron <aaron.chou@axiomtek.com.tw>
//============================================================================

#ifndef __ARM_H__
#define __ARM_H__

//============================================================================
//    includes
//============================================================================
#include <stdint.h>
#include <stdbool.h>

#include <EApiI2c-dev.h>

#ifdef __cplusplus
extern "C"
{
#endif


//============================================================================
//    definations
//============================================================================
// bool _set_gpio_pin(const char *location,const char *address, uint32_t data, int start, int length);
// bool _get_gpio_single_value(const char *location,const char *address, uint32_t *data, int start, int length);
// bool _set_gpio_single_value(const char *location,const char *address, uint32_t data, int start, int length);
// bool _get_gpio_value(const char *location,const char *address, uint32_t *data, int start, int length);
// bool _set_gpio_value(const char *location,const char *address, uint32_t data, int start, int length);
// bool _get_node_value(const char *location,const char *address, uint32_t *data, int start, int length);
// bool _set_node_value(const char *location,const char *address, uint32_t data, int start, int length);
// bool _get_cpld_value(const char *location,const char *address, uint32_t *data, int start, int length);
// bool _set_cpld_value(const char *location,const char *address, uint32_t data, int start, int length);
// bool _set_socket_can_enable(const char *location,const char *address, uint32_t data, int start, int length);

// typedef enum ax_eapi_arm_id {
//     AX_EAPI_ARM_DI_0 = 0,
//     AX_EAPI_ARM_DI_1,
//     AX_EAPI_ARM_DI_2,
//     AX_EAPI_ARM_DI_3,
//     AX_EAPI_ARM_DI_4,
//     AX_EAPI_ARM_DI_5,
//     AX_EAPI_ARM_DI_6,
//     AX_EAPI_ARM_DI_7,
//     AX_EAPI_ARM_DI,
//     AX_EAPI_ARM_POWER_STATUS_1,
//     AX_EAPI_ARM_POWER_STATUS_2,
//     AX_EAPI_ARM_LED,
//     AX_EAPI_ARM_ALARMLED,
//     AX_EAPI_COM_1,
//     AX_EAPI_COM_2,
//     AX_EAPI_COM_3,
//     AX_EAPI_COM_4,
//     AX_EAPI_COM_1_TERMINATION,
//     AX_EAPI_COM_2_TERMINATION,
//     AX_EAPI_COM_3_TERMINATION,
//     AX_EAPI_COM_4_TERMINATION,
//     AX_EAPI_WDT_ENABLE,
//     AX_EAPI_WDT_COUNTER,
//     AX_EAPI_CAN_0,
//     AX_EAPI_CAN_1,
//     AX_EAPI_CAN_0_TERMINATION,
//     AX_EAPI_CAN_1_TERMINATION,
//     AX_EAPI_ARM_DO_0,
//     AX_EAPI_ARM_DO_1,
//     AX_EAPI_ARM_DO_2,
//     AX_EAPI_ARM_DO_3,
//     AX_EAPI_ARM_DO_4,
//     AX_EAPI_ARM_DO_5,
//     AX_EAPI_ARM_DO_6,
//     AX_EAPI_ARM_DO_7,
//     AX_EAPI_ARM_DO
// }ax_eapi_arm_id_t;

// typedef struct arm_function_map {
//     ax_eapi_arm_id_t id;
//     bool (*get) (const char *location,const char *address, uint32_t *data, int start, int length);
//     bool (*set) (const char *location,const char *address, uint32_t data, int start, int length);
//     const char *location;
//     const char *address;
//     int start;
//     int length;
// } arm_function_map_t;

// static arm_function_map_t rbox630[] = {
//     {AX_EAPI_ARM_DI_0, _get_gpio_single_value, NULL,"151", NULL,0,0},
//     {AX_EAPI_ARM_DI_1, _get_gpio_single_value, NULL,"36", NULL,0,0},
//     {AX_EAPI_ARM_DI_2, _get_gpio_single_value, NULL,"12", NULL,0,0},
//     {AX_EAPI_ARM_DI_3, _get_gpio_single_value, NULL,"13", NULL,0,0},
//     {AX_EAPI_ARM_DI_4, _get_gpio_single_value, NULL,"37", NULL,0,0},
//     {AX_EAPI_ARM_DI_5, _get_gpio_single_value, NULL,"152", NULL,0,0},
//     {AX_EAPI_ARM_DI_6, _get_gpio_single_value, NULL,"150", NULL,0,0},
//     {AX_EAPI_ARM_DI_7, _get_gpio_single_value, NULL,"153", NULL,0,0},
//     {AX_EAPI_ARM_DI, _get_gpio_value, NULL,"151,36,12,13,37,152,150,153", NULL,0,0},
//     {AX_EAPI_ARM_POWER_STATUS_1, _get_cpld_value, NULL,"0x01","0x50",0,1}, 
//     {AX_EAPI_ARM_POWER_STATUS_2, _get_cpld_value, NULL,"0x01","0x50",1,1},
//     {AX_EAPI_ARM_LED, _get_cpld_value, _set_cpld_value,"0x01","0x51",0,1}, 
//     {AX_EAPI_ARM_ALARMLED, _get_cpld_value, _set_cpld_value,"0x01","0x51",6,1},
//     {AX_EAPI_COM_1, _get_cpld_value, _set_cpld_value,"0x02","0x50",0,2}, 
//     {AX_EAPI_COM_2, _get_cpld_value, _set_cpld_value,"0x02","0x51",0,2},
//     {AX_EAPI_COM_3, _get_cpld_value, _set_cpld_value,"0x02","0x52",0,2},
//     {AX_EAPI_COM_4, _get_cpld_value, _set_cpld_value,"0x02","0x53",0,2}, 
//     {AX_EAPI_COM_1_TERMINATION, _get_cpld_value, _set_cpld_value,"0x02","0x50",2,1}, 
//     {AX_EAPI_COM_2_TERMINATION, _get_cpld_value, _set_cpld_value,"0x02","0x51",2,1},
//     {AX_EAPI_COM_3_TERMINATION, _get_cpld_value, _set_cpld_value,"0x02","0x52",2,1},
//     {AX_EAPI_COM_4_TERMINATION, _get_cpld_value, _set_cpld_value,"0x02","0x53",1,1}, 
//     {AX_EAPI_WDT_ENABLE, _get_cpld_value, _set_cpld_value,"0x04","0x50",6,1}, 
//     {AX_EAPI_WDT_COUNTER, _get_cpld_value, _set_cpld_value,"0x04","0x51",0,8}, 
//     {AX_EAPI_CAN_0, NULL, _set_socket_can_enable,"0","1000000",0,0}, //x
//     {AX_EAPI_CAN_1, NULL, _set_socket_can_enable,"1","1000000",0,0}, //x
//     {AX_EAPI_CAN_0_TERMINATION, _get_cpld_value, _set_cpld_value,"0x07","0x50",0,2}, 
//     {AX_EAPI_CAN_1_TERMINATION, _get_cpld_value, _set_cpld_value,"0x07","0x50",4,2}, 
//     {AX_EAPI_ARM_DO_0, _get_cpld_value, _set_cpld_value,"0x06","0x50",0,1},
//     {AX_EAPI_ARM_DO_1, _get_cpld_value, _set_cpld_value,"0x06","0x50",1,1},
//     {AX_EAPI_ARM_DO_2, _get_cpld_value, _set_cpld_value,"0x06","0x50",2,1},
//     {AX_EAPI_ARM_DO_3, _get_cpld_value, _set_cpld_value,"0x06","0x50",3,1},
//     {AX_EAPI_ARM_DO_4, _get_cpld_value, _set_cpld_value,"0x06","0x50",4,1},
//     {AX_EAPI_ARM_DO_5, _get_cpld_value, _set_cpld_value,"0x06","0x50",5,1},
//     {AX_EAPI_ARM_DO_6, _get_cpld_value, _set_cpld_value,"0x06","0x50",6,1},
//     {AX_EAPI_ARM_DO_7, _get_cpld_value, _set_cpld_value,"0x06","0x50",7,1},
//     {AX_EAPI_ARM_DO, _get_cpld_value, _set_cpld_value,"0x06","0x50",0,8}
// };

// static arm_function_map_t aaarbox630[] = {
//     {AX_EAPI_ARM_DI1, _getbb, _setbb},
//     {AX_EAPI_ARM_DI2, NULL, NULL},
// };


//============================================================================
//    functions
//============================================================================
//--- public method ---------------------------------------------------------
/**
 * @brief ax_rdm_get_value
 */
int ax_arm_get_value (
    uint32_t Id,            /* Value Id */
    uint32_t* pValue            /* Value */
);

/**
 * @brief ax_rdm_set_value
 */
int ax_arm_set_value (
    uint32_t Id,            /* Value Id */
    uint32_t pValue             /* Value */
);


// string GetStdoutFromCommand(string cmd);
// arm_function_map_t* get_map(uint32_t id);

//============================================================================
//    types
//============================================================================

//============================================================================
//    variables
//============================================================================
// TODO: will change to AVL tree to improve performance


#ifdef __cplusplus
}
#endif


#endif
