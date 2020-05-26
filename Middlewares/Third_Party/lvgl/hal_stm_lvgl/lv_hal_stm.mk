CSRCS += stm32f429i_discovery.c

DEPPATH += --dep-path $(LVGL_DIR)/$(LVGL_DIR_NAME)/hal_stm_lvgl
VPATH += :$(LVGL_DIR)/$(LVGL_DIR_NAME)/hal_stm_lvgl

CFLAGS += "-I$(LVGL_DIR)/$(LVGL_DIR_NAME)/hal_stm_lvgl"
