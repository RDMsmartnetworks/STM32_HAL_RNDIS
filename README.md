# STM32_HAL_RNDIS
RNDIS for ST HAL library.
The rndis library is based on the library from Sergey Fetisov: https://github.com/fetisov/lrndis .

This rndis project is based on the HAL library and uses FreeRTOS. The rndis usb interface is functional and implemented. At least enummeration is working if you flash this project on a stm32f411 based board with usb socket.
The rs485 interface is just a template for a second interface and needs to be completed. You could also implement a webserver, a dhcp server and a dns which are using the second interface.
For frame management I implemented a ringbuffer "queuex". The ringbuffers parameters can be found in its header file.
Data handling on the rndis usb interface is zero copy -> As soon as frame has been received the head will jump to the next ringbuffer slot (if it is not occpied by the tail of course).
