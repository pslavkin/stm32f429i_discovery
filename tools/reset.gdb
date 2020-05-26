target remote | openocd  -f tools/tiva.cfg -c "gdb_port pipe; log_output openocd.log"
monitor reset
quit

