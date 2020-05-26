CSRCS += ili9341.c
CSRCS += tft.c 

DEPPATH += --dep-path $(LVGL_DIR)/$(LVGL_DIR_NAME)/hal_stm_lvgl/tft
VPATH += :$(LVGL_DIR)/$(LVGL_DIR_NAME)/hal_stm_lvgl/tft

CFLAGS += "-I$(LVGL_DIR)/$(LVGL_DIR_NAME)/hal_stm_lvgl/tft"
