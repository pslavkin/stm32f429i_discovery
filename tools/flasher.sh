#if [ -f "flashed.log" ];
#then 
# echo 'sin novedades...'
#else
# echo 'grabando...'
#   /opt/STMicroelectronics/STM32Cube/STM32CubeProgrammer/bin/STM32_Programmer_CLI -c port=SWD  -d ../build/taiwan.elf
#  touch "flashed.log"
#fi
#./openocd.sh

echo 'grabando...'
/opt/STMicroelectronics/STM32Cube/STM32CubeProgrammer/bin/STM32_Programmer_CLI -c port=SWD  -d ../build/taiwan.elf
#/opt/STMicroelectronics/STM32Cube/STM32CubeProgrammer/bin/STM32_Programmer_CLI -c port=SWD  -d /home/pslavkin/Downloads/lv_port_stm32f429_disco-master/Debug/lv_port_stm32f429_disco.elf
