CSRCS += stmpe811.c 
CSRCS += touchpad.c 

DEPPATH += --dep-path $(LVGL_DIR)/$(LVGL_DIR_NAME)/hal_stm_lvgl/touchpad
VPATH += :$(LVGL_DIR)/$(LVGL_DIR_NAME)/hal_stm_lvgl/touchpad

CFLAGS += "-I$(LVGL_DIR)/$(LVGL_DIR_NAME)/hal_stm_lvgl/touchpad"
