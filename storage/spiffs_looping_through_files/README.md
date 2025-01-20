# commands

## To generate a bin file 
`
spiffsgen.py <size> <folder> <out bin file>
`
```
spiffsgen.py 0x100000 folder_to_download to_flash.bin 
```
## To flash
`
esptool.py --chip <chip> --port <port> --baud <baudrate> write_flash -z <start address> <bin file>
`
```
esptool.py --chip esp32 --port ttyACM0 --baud 115200 write_flash -z 0x110000 to_flash.bin
```