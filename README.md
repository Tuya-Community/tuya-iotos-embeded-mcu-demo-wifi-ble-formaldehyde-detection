# Tuya IoTOS Embedded Mcu Demo Wifi Ble Formaldehyde Detection

[English](./README.md) | [中文](./README_zh.md)

## Introduction  

This Demo uses the Tuya smart cloud platform, Tuya smart APP, and IoTOS Embedded MCU SDK to realize a formaldehyde  detector.

The implemented features include:

+ formaldehyde   detection


## Quick start  

### Compile & Burn
+ [Get MCU SDK](https://developer.tuya.com/en/docs/iot/device-development/embedded-software-development/mcu-development-access/mcu-access-guide?id=K9hrbv1ub5owo#title-2-产品创建)
+ [MCU SDK Migration](https://developer.tuya.com/en/docs/iot/device-development/embedded-software-development/mcu-development-access/wifi-mcu-sdk-solution/overview-of-migrating-tuyas-mcu-sdk?id=K9hhi0xr5vll9)


### File introduction 

```
├── user
│   ├── main.c
│   └── MY_ST_config.h
├── CMSIS
│   ├── system_stm32g0xx.c
│   └── startup_stm32g071xx.s
├── SYSTEM
│   ├── sys.c
│   ├── sys.h
│   ├── RCC.c
│   ├── RCC.h
│   ├── delay.c
│   ├── delay.h
│   ├── USART.c
│   ├── USART.h
│   ├── IO.c
│   ├── IO.h
│   ├── TIM.c
│   └── TIM.h
└── MCU_SDK
    ├── mcu_api.c
    ├── mcu_api.h
    ├── protocol.c
    ├── protocol.h
    ├── system.c
    ├── system.h
    └── wifi.h
    
```



### Demo entry

Entry file：main.c

Important functions：main()

+ Initialize and configure MCU IO port, USART, timer, etc. All events are polled and judged in while(1)。




### DataPoint related

+ DP point processing: mcu_dp_value_update()

| function name | unsigned char mcu_dp_value_update(unsigned char dpid,unsigned long value) |
| ------------- | ------------------------------------------------------------ |
| dpid          | DP ID number                                                 |
| value         | DP data                                                      |
| Return        | SUCCESS: Success ERROR: Failure                              |



### I/O List  

| UASRT2  | UASRT1  |
| :-----: | :-----: |
| PD5 TXD | PC4 TXD |
| PD6 RXD | PC5 RXD |



## Related Documents

  Tuya Demo Center: https://developer.tuya.com/demo/



## Technical Support

  You can get support for Tuya by using the following methods:

- Developer Center: https://developer.tuya.com
- Help Center: https://support.tuya.com/help
- Technical Support Work Order Center: [https://service.console.tuya.com](https://service.console.tuya.com/) 

