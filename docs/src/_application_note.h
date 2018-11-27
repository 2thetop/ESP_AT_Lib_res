/**
 * \page            page_appnote Application note
 * \tableofcontents
 *
 * \section         sect_clone_get_started Clone repository and getting started
 *
 * Library development is fully hosted on Github and there is no future plans to move to any other platform.
 *
 * There are `2` repositories
 *
 *	- <a href="https://github.com/MaJerle/ESP_AT_Lib"><b>ESP_AT_Lib</b></a>: Source code of library itself.
 *	    - Repository is required when developing final project
 *
 *	- <a href="https://github.com/MaJerle/ESP_AT_Lib_res"><b>ESP_AT_Lib_res</b></a>: Resources, development code,
 *		documentation sources, examples, code snippets, etc.
 *      - This repository uses `ESP_AT_Lib` repository as `submodule`
 *	    - Repository is used to evaluate library using prepared examples
 *
 * \subsection      subsect_clone_res Clone resources repository with examples
 *
 * Easiest way to test the library is to clone resources repository.
 *
 *  - Download and install `git` if not already
 *  - Open console and navigate to path in the system to clone repository to. Use command `cd your_path`
 *  - Run `git clone https://github.com/MaJerle/ESP_AT_Lib_res` command to clone repository
 *  - Enter into newly cloned folder using `cd ESP_AT_Lib_res`. Now we are inside working git directory
 *  - Run command `git submodule update --init --recursive` to download and update all submodules
 *  - Navigate to `examples` directory and run favourite example
 *
 * \subsection      subsect_clone_lib Clone library only
 *
 * If you are already familiar with library and you wish to include it in existing project, easiest way is to clone library repository only.
 *
 *  - Download and install `git` if not already
 *  - Open console and navigate to path in the system to clone repository to. Use command `cd your_path`
 *  - Run `git clone https://github.com/MaJerle/ESP_AT_Lib` command to clone repository
 *
 * \section         sect_project_examples Example projects
 *
 * \note            Examples are part of `ESP_AT_Lib_res` repository. Refer to \ref subsect_clone_res
 *
 * Several examples are available to show application use cases. These are split and can be tested on different systems.
 *
 * \subsection      subsect_project_examples_win32 WIN32
 *
 * Library is developed under WIN32 system. That is, all examples are first developed and tested under WIN32, later ported to embedded application.
 * Examples come with <b>Visual Studio</b> project. You may open project and directly run the example from there.
 *
 * \note            It may happen that Visual Studio sets different configuration on first project load and this may lead to wrong build and possible errors.
 *                  Active configuration must be `Debug` and `Win32 or x86`. Default active build can be set in project settings.
 *
 * \par             NodeMCU development board
 *
 * For development purposes, `NodeMCU v3` board is used with virtual COM port support to translate USB communication to UART required for ESP8266.
 *
 * \warning         Some NodeMCU boards have `CH340 USB->UART` transceiver where I found problems with communication due to data loss between ESP and PC even at `115200` bauds.
 *                  Try to find NodeMCU with something else than CH340.
 *
 * \par             System functions for WIN32
 *
 * Required system functions are based on "windows.h" file, available on windows operating system. Natively, there is support for:
 * 
 *  - Timing functions
 *  - Semaphores
 *  - Mutexes
 *  - Threads
 *
 * The last part are message queues which are not implemented in Windows OS.
 * Message queues were developed with help of semaphores and dynamic memory allocatations.
 * System port for WIN32 is available in `src/system/esp_sys_win32.c` file.
 *
 * \par             Low-level communication between NodeMCU and WIN32
 *
 * Communication with NodeMCU hardware is using virtual files for COM ports.
 * Implementation of low-level part (together with memory allocation for library) is available in `src/system/esp_ll_win32.c` file.
 *
 * \note            In order to start using this port, user must set the appropriate COM port name when opening a virtual file. 
 *                  Please check implementation file for details.
 *
 * \subsection      subsect_project_examples_arm_stm32 STM32 (ARM Cortex-M)
 *
 * Library is indendant from CPU architecture, meaning we can also run it on embedded systems. 
 * Different ports for `FreeRTOS` operating system and `STM32` based microcontrollers are available too.
 *
 *  <table>
 * 	    <caption>STM32 boards and pinouts for tests</caption>
 *      <tr><th>Board name       <th>STM32F769I-Discovery   <th>STM32F723E-Discovery   <th>STM32L496G-Discovery   <th>STM32L432KC-Nucleo
 *      <tr><td colspan="5" style="text-align: center;"><b>GPIO settings</b>
 *      <tr><td>ESP_RX (MCU_TX pin) <td>PC12                <td>PC12                   <td>PB6                    <td>PA9
 *      <tr><td>ESP_TX (MCU_RX pin) <td>PD2                 <td>PD2                    <td>PG10                   <td>PA10
 *      <tr><td>ESP_RESET        <td>PJ14                   <td>PG14                   <td>PB2                    <td>PA12
 *      <tr><td>ESP_CH_PD        <td>-                      <td>PD3                    <td>PA4                    <td>PB0
 *      <tr><td>ESP_GPIO0        <td>-                      <td>-                      <td>PH0                    <td>PA7
 *      <tr><td>ESP_GPIO2        <td>-                      <td>PD6                    <td>PA0                    <td>PA6
 *      <tr><td>Comment          <td>Use `CN2` to plug-in device <td>                  <td>                       <td>
 *      <tr><td colspan="5" style="text-align: center;"><b>UART settings for ESP8266</b>
 *      <tr><td>UART             <td>UART5                  <td>UART5                  <td>USART1                 <td>USART1
 *      <tr><td>Implementation file <td>`esp_ll_stm32f769i_discovery.c` <td>`esp_ll_stm32f723e_discovery.c` <td>`esp_ll_stm32l496g_discovery.c` <td>`esp_ll_stm32l432kc_nucleo.c`
 *      <tr><td colspan="5" style="text-align: center;"><b>Debug settings</b>
 *      <tr><td>DEBUG_UART       <td>USART1                 <td>USART6                 <td>USART2                 <td>USART2
 *      <tr><td>DEBUG_TX         <td>PA9                    <td>PC6                    <td>PA2                    <td>PA2
 *      <tr><td>DEBUG_RX         <td>PA10                   <td>PC7                    <td>PD6                    <td>PA3
 *      <tr><td>DEBUG_BAUDRATE   <td>921600                 <td>921600                 <td>921600                 <td>921600
 *      <tr><td>Comment          <td>On-board ST-Link       <td>On-board ST-Link       <td>On-board ST-Link       <td>External USB<->UART needed
 *  </table>
 *
 * \note            All examples for STM32 come with ST's official free development studio.
 *
 * \section         sect_porting_guide Porting guide
 *
 * \subsection      subsect_sys_arch System structure
 *
 * \image html system_structure.svg System structure organization
 *
 * We can describe library structure in 4 different layers:
 *
 *  - <b>User application</b>: User application is highest layer where entire code is implemented by user
 *      and where ESP AT library API functions are called from
 *
 *  - <b>ESP AT middleware</b>: ESP AT middleware layer consists of API functions,
 *      thread management functions and all utilities necessary for smooth operation.
 *
 *  - <b>System functions</b>: Layer where system dependant functions must be implemented,
 *      such as current time in milliseconds and all OS dependant functions for:
 *      - Managing threads
 *      - Managing semaphores
 *      - Managing mutexes
 *      - Managing message queues
 *
 *      More about this part can be found in \ref ESP_SYS section.
 *
 *  - <b>AT port communication functions</b> or <b>ESP LL</b>: Part of code where user must take care
 *      of sending and receiving data from/to ESP AT lib to properly handle communication between
 *      host device and ESP device.
 *      - User must assign memory for memory manager in this section.
 *          Check \ref ESP_MEM and \ref ESP_LL sections for more information.
 *
 *      More about this part can be found in \ref ESP_LL section.
 *      
 *      Together with this section, user must implement part to input the received data from AT port.
 *
 *  - <b>ESP physical device</b>: Actual ESP8266 or ESP32 device
 *
 * \subsection      subsect_port_implementation Implementation specific part
 *
 * Before usage, user must implement all functions in \ref ESP_LL section
 * as well as take care of proper communication with ESP device in \ref ESP_LL section.
 *
 * \note            For more information about how to port, check sections accordingly
 *
 * \section         sect_config Library configuration
 *
 * To make library as efficient as possible, different configuration parameters are available
 * to make sure all the requirements are met for different purposes as possible.
 *
 * A list of all configurations can be found in \ref ESP_CONF section.
 *
 * \subsection      subsect_conf_file Project configuration file
 *
 * Library comes with `2` configuration files:
 *
 *  - Default configuration file `esp_config_default.h`
 *  - Project template configuration file `esp_config_template.h`
 *
 * When project is started, user has to rename template file to `esp_config.h`
 * and if required, it should override default settings in this file.
 *
 * Default template file comes with something like this:
 *
 * \include         _example_config_template.h
 *
 * In case user wants to increase default buffer size_t for received data,
 * a file should be modified to something similar like code below:
 *
 * \include         _example_config.h
 *
 * \note            Important notes:
 *                      - Always do default settings modifications in user custom `esp_config.h` file
 *                          which was previously renamed from `esp_config_template.h`,
 *                      - Always include `esp/esp_debug.h` before any custom settings and
 *                          `esp/esp_config_default.h` after custom settings
 *
 * \section         sect_thread_comm Inter-thread communication
 *
 * In order to have very effective library from resources point of view,
 * an inter-thread communication was introduced.
 *
 * \image html thread_communication.svg Inter-Thread communication between user and library.
 *
 * Library consists of 2 threads working in parallel and bunch of different user threads.
 *
 * \subsection      subsect_thread_user User thread(s)
 *
 * User thread is a place where user communicates with ESP AT library.
 * When a new command wants to be executed to ESP device, user calls appropriate API function which will do following steps:
 *
 *  - Allocate memory for command message from memory manager
 *  - Assign command type to message
 *  - Set other parameters, related or required to command
 *  - If user wants to wait for response (blocking mode), then create system semaphore `sem` and lock it immediatelly
 *  - Send everything to producing message queue which is later read in producing thread
 *  - If user don't want blocking mode, return from function with status OK
 *      otherwise wait for semaphore `sem` to be released from producing thread
 *      - When `sem` semaphore is locked, user thread may sleep and release resources for other threads this time
 *  - If user selects blocking mode, wait for response, free command memory in memory manager and return command response status
 *
 * User may use different threads to communicate with ESP AT lib at the same time since memory manager
 * is natively protected by mutex and producing queue is protected from multiple accesses by OS natively.
 *
 * \subsection      subsec_thread_producer Producer thread
 *
 * Producer threads reads message queue with user commands and sends initial AT command to AT port.
 * When there is no commands from user, thread can sleep waiting for new command from user.
 *
 * Once there is a command read from message queue, these steps are performed:
 *
 *  - Check if processing function is set and if command is valid
 *  - Locks `sync_sem` semaphore for synchronization between processing and producing threads
 *  - Sends initial AT command to AT port according to command type
 *  - Waits for `sync_sem` to be ready again (released in processing thread)
 *  - If command was blocking, set result and unlock command `sem` semaphore
 *  - If command was not blocking, free command memory from memory manager
 *
 * \subsection      subsec_thread_process Process thread
 *
 * Processing thread reads received data from AT port and processes them.
 *
 * If command is active and received data belongs to command, they are processed according to command.
 * If received data are not related to command (such as received network data `+IPD`),
 * they are also processed and callback function is immediatelly called to notify user about received data.
 *
 * Here is a list of some URC (Unsolicited Result Code) messages:
 *  
 *  - Received network data `+IPD`
 *  - Connection just active `+LINK_CONN`
 *  - Station disconnected from access point `WIFI DISCONNECT`
 *  - Station connected to access point `WIFI CONNECTED`
 *  - ...
 *
 * All these commands must be reported to user. To do this, callback is triggered to notify user.
 *
 * \section         sect_block_nonblock Blocking and non-blocking commands
 *
 * Every command (except if noted otherwise) can be executed in blocking or non-blocking mode.
 *
 * \subsection      subsect_blocking Blocking mode
 *
 * When blocking mode is selected, function will block thread execution until response is received
 * and ready for further processing. When the function returns, user has known result from ESP device.
 * Linear programming style may be applied.
 *
 * \include         _example_blocking_pseudo.c
 *
 * \warning         When user wants to send command from callback function,
 *                  it is mandatory to call it in non-blocking way, otherwise you may enter dead-lock
 *                  and your program will stop in this position forever.
 *
 * \subsection      subsect_nonblocking Non-blocking mode
 *
 * In non-blocking mode, command is created, sent to producing message queue and function returns without waiting for response from device.
 * This mode does not allow linear programming style, because after non-blocking command, callback function is called.
 *
 * \note            As of now, fully implemented callbacks are implemented for \ref ESP_CONN section onlyl
 *                  because these are used the most and therefore most focus was applied to this section.
 *
 * \note            When user wants to send command from callback function,
 *                  this is the only allowed way to do it. Every command must be called in
 *                  non-blocking way from callback function.
 *
 * Pseudo code example for non-blocking API call. Full example for connections API can be found in \ref ESP_CONN section.
 *
 * \include         _example_nonblocking_pseudo.c
 *
 */