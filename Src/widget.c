#include "cmsis_os.h"
#include "../Middlewares/Third_Party/lv_examples/lv_examples.h"
#include "../Middlewares/Third_Party/lvgl/hal_stm_lvgl/touchpad/touchpad.h"
#include "widget.h"
#include "main.h"

static void visuals_create(lv_obj_t * parent);

static lv_obj_t * tv;
static lv_obj_t * t2;
static lv_style_t style_box;

void initWidget(void)
{
    tv = lv_tabview_create(lv_scr_act(), NULL);
    t2 = lv_tabview_add_tab(tv, "TAIWAN");
    lv_style_init            ( &style_box                                          );
    lv_style_set_value_align ( &style_box ,LV_STATE_DEFAULT ,LV_ALIGN_OUT_TOP_LEFT ) ;
    lv_style_set_value_ofs_y ( &style_box ,LV_STATE_DEFAULT ,- LV_DPX(10           ));
    lv_style_set_margin_top  ( &style_box ,LV_STATE_DEFAULT ,LV_DPX(30             ));
    visuals_create(t2);
}

lv_obj_t * arc;

static void visuals_create(lv_obj_t * parent)
{
    lv_page_set_scrl_layout(parent, LV_LAYOUT_PRETTY_TOP);
    lv_coord_t grid_w_meter;
    grid_w_meter = lv_page_get_width_grid(parent, 1, 1);

    lv_coord_t meter_h    = lv_page_get_height_fit(parent);
    lv_coord_t meter_size = LV_MATH_MIN(grid_w_meter, meter_h);

    arc = lv_arc_create(parent, NULL);
    lv_obj_set_drag_parent           ( arc, true                                    );
    lv_arc_set_bg_angles             ( arc, 0, 360                                  );
    lv_arc_set_rotation              ( arc, 270                                     );
    lv_arc_set_angles                ( arc, 0, 0                                    );
    lv_obj_set_size                  ( arc,  meter_size, meter_size                 );
    lv_obj_add_style                 ( arc, LV_ARC_PART_BG, &style_box              );
    lv_obj_set_style_local_value_str ( arc, LV_ARC_PART_BG, LV_STATE_DEFAULT, "Arc" );

    lv_obj_t * led_h = lv_cont_create(parent, NULL);
    lv_cont_set_layout(led_h, LV_LAYOUT_PRETTY_MID);
    lv_obj_set_width(led_h, lv_page_get_width_grid(parent, 1, 1));

    lv_obj_set_height(led_h, 40);
    lv_obj_add_style(led_h, LV_CONT_PART_MAIN, &style_box);
    lv_obj_set_drag_parent(led_h, true);
    lv_obj_set_style_local_value_str(led_h, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, "LEDs");

    lv_obj_t * led = lv_led_create(led_h, NULL);
    lv_coord_t led_size = lv_obj_get_height_fit(led_h);
    lv_obj_set_size(led, led_size, led_size);
    lv_led_off(led);

    led = lv_led_create(led_h, led);
    lv_led_set_bright(led, (LV_LED_BRIGHT_MAX - LV_LED_BRIGHT_MIN) / 2 + LV_LED_BRIGHT_MIN);

    led = lv_led_create(led_h, led);
    lv_led_on(led);

}

void moveArcTask(void* rien)
{
   int value=0;
   int16_t x,y;
   while (1) {

   if(value<300)
      value++;
   else
      value=0;


   lv_arc_set_end_angle(arc, value);
   touchpad_get_xy(&x,&y);
   printInt(x);
   printInt(y);
   vTaskDelay(portTICK_RATE_MS*30);
   }
}

    //lv_arc_set_end_angle(arc, value);
    //lv_gauge_set_value(gauge, 0, value);
    //lv_linemeter_set_value(linemeter, value);


