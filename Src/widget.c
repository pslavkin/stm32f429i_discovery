/**
 * @file lv_demo_widgets.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "../Middlewares/Third_Party/lv_examples/lv_examples.h"
#include "widget.h"

static void visuals_create(lv_obj_t * parent);
static void gauge_anim(lv_obj_t * gauge, lv_anim_value_t value);;


/**********************
 *  STATIC VARIABLES
 **********************/
static lv_obj_t * tv;
static lv_obj_t * t2;
static lv_obj_t * kb;

static lv_style_t style_box;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void widget(void)
{
    tv = lv_tabview_create(lv_scr_act(), NULL);
    t2 = lv_tabview_add_tab(tv, "Visuals");

    lv_style_init(&style_box);
    lv_style_set_value_align(&style_box, LV_STATE_DEFAULT, LV_ALIGN_OUT_TOP_LEFT);
    lv_style_set_value_ofs_y(&style_box, LV_STATE_DEFAULT, - LV_DPX(10));
    lv_style_set_margin_top(&style_box, LV_STATE_DEFAULT, LV_DPX(30));

    visuals_create(t2);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/



static void visuals_create(lv_obj_t * parent)
{
    lv_page_set_scrl_layout(parent, LV_LAYOUT_PRETTY_TOP);

    lv_disp_size_t disp_size = lv_disp_get_size_category(NULL);

    lv_coord_t grid_h_chart = lv_page_get_height_grid(parent, 1, 1);
    lv_coord_t grid_w_chart = lv_page_get_width_grid(parent, disp_size <= LV_DISP_SIZE_LARGE ? 1 : 2, 1);


    lv_coord_t grid_w_meter;
    if(disp_size <= LV_DISP_SIZE_SMALL) grid_w_meter = lv_page_get_width_grid(parent, 1, 1);
    else if(disp_size <= LV_DISP_SIZE_MEDIUM) grid_w_meter = lv_page_get_width_grid(parent, 2, 1);
    else grid_w_meter = lv_page_get_width_grid(parent, 3, 1);

    lv_coord_t meter_h = lv_page_get_height_fit(parent);
    lv_coord_t meter_size = LV_MATH_MIN(grid_w_meter, meter_h);
//

    lv_obj_t * arc = lv_arc_create(parent, NULL);
    lv_obj_set_drag_parent(arc, true);
    lv_arc_set_bg_angles(arc, 0, 360);
    lv_arc_set_rotation(arc, 270);
    lv_arc_set_angles(arc, 0, 0);
    lv_obj_set_size(arc,  meter_size, meter_size);
    lv_obj_add_style(arc, LV_ARC_PART_BG, &style_box);
    lv_obj_set_style_local_value_str(arc, LV_ARC_PART_BG, LV_STATE_DEFAULT, "Arc");

    lv_obj_t * label = lv_label_create(arc, label);
    lv_obj_align(label, arc, LV_ALIGN_CENTER, 0, 0);


//    /*Create a bar and use the backgrounds value style property to display the current value*/
//    lv_obj_add_style(bar_h, LV_CONT_PART_MAIN, &style_box);
//    lv_obj_set_style_local_value_str(bar_h, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, "Bar");
//
//    if(disp_size <= LV_DISP_SIZE_SMALL) lv_obj_set_width(bar_h, lv_page_get_width_grid(parent, 1, 1));
//    else if(disp_size <= LV_DISP_SIZE_MEDIUM) lv_obj_set_width(bar_h, lv_page_get_width_grid(parent, 2, 1));
//    else lv_obj_set_width(bar_h, lv_page_get_width_grid(parent, 3, 2));
//
//    lv_obj_t * bar = lv_bar_create(bar_h, NULL);
//    lv_obj_set_width(bar, lv_obj_get_width_fit(bar_h));
//    lv_obj_set_style_local_value_font(bar, LV_BAR_PART_BG, LV_STATE_DEFAULT, lv_theme_get_font_small());
//    lv_obj_set_style_local_value_align(bar, LV_BAR_PART_BG, LV_STATE_DEFAULT, LV_ALIGN_OUT_BOTTOM_MID);
//    lv_obj_set_style_local_value_ofs_y(bar, LV_BAR_PART_BG, LV_STATE_DEFAULT, LV_DPI / 20);
//    lv_obj_set_style_local_margin_bottom(bar, LV_BAR_PART_BG, LV_STATE_DEFAULT, LV_DPI / 7);
//    lv_obj_align(bar, NULL, LV_ALIGN_CENTER, 0, 0);

    lv_obj_t * led_h = lv_cont_create(parent, NULL);
    lv_cont_set_layout(led_h, LV_LAYOUT_PRETTY_MID);
    if(disp_size <= LV_DISP_SIZE_SMALL) lv_obj_set_width(led_h, lv_page_get_width_grid(parent, 1, 1));
    else if(disp_size <= LV_DISP_SIZE_MEDIUM) lv_obj_set_width(led_h, lv_page_get_width_grid(parent, 2, 1));
    else lv_obj_set_width(led_h, lv_page_get_width_grid(parent, 3, 1));

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

    if(disp_size == LV_DISP_SIZE_MEDIUM) {
        lv_obj_add_protect(led_h, LV_PROTECT_POS);
        lv_obj_align(led_h, 40, LV_ALIGN_OUT_BOTTOM_MID, 0, lv_obj_get_style_margin_top(led_h, LV_OBJ_PART_MAIN) + lv_obj_get_style_pad_inner(parent, LV_PAGE_PART_SCROLLABLE));
    }

}








static void arc_anim(lv_obj_t * arc, lv_anim_value_t value)
{
    lv_arc_set_end_angle(arc, value);

    static char buf[64];
    lv_snprintf(buf, sizeof(buf), "%d", value);
    lv_obj_t * label = lv_obj_get_child(arc, NULL);
    lv_label_set_text(label, buf);
    lv_obj_align(label, arc, LV_ALIGN_CENTER, 0, 0);

}

static void linemeter_anim(lv_obj_t * linemeter, lv_anim_value_t value)
{
    lv_linemeter_set_value(linemeter, value);

    static char buf[64];
    lv_snprintf(buf, sizeof(buf), "%d", value);
    lv_obj_t * label = lv_obj_get_child(linemeter, NULL);
    lv_label_set_text(label, buf);
    lv_obj_align(label, linemeter, LV_ALIGN_CENTER, 0, 0);
}

static void gauge_anim(lv_obj_t * gauge, lv_anim_value_t value)
{
    lv_gauge_set_value(gauge, 0, value);

    static char buf[64];
    lv_snprintf(buf, sizeof(buf), "%d", value);
    lv_obj_t * label = lv_obj_get_child(gauge, NULL);
    lv_label_set_text(label, buf);
    lv_obj_align(label, gauge, LV_ALIGN_IN_TOP_MID, 0, lv_obj_get_y(label));
}

static void table_event_cb(lv_obj_t * table, lv_event_t e)
{
    if(e == LV_EVENT_CLICKED) {
        uint16_t row;
        uint16_t col;
        lv_res_t r = lv_table_get_pressed_cell(table, &row, &col);
        if(r == LV_RES_OK && col && row) {  /*Skip the first row and col*/
            if(lv_table_get_cell_type(table, row, col) == 1) {
                lv_table_set_cell_type(table, row, col, 4);
            } else {
                lv_table_set_cell_type(table, row, col, 1);
            }
        }
    }
}

#if LV_USE_THEME_MATERIAL
static void color_chg_event_cb(lv_obj_t * sw, lv_event_t e)
{
    if(LV_THEME_DEFAULT_INIT != lv_theme_material_init) return;
    if(e == LV_EVENT_VALUE_CHANGED) {
        uint32_t flag = LV_THEME_MATERIAL_FLAG_LIGHT;
        if(lv_switch_get_state(sw)) flag = LV_THEME_MATERIAL_FLAG_DARK;

        LV_THEME_DEFAULT_INIT(lv_theme_get_color_primary(), lv_theme_get_color_primary(),
                flag,
                lv_theme_get_font_small(), lv_theme_get_font_normal(), lv_theme_get_font_subtitle(), lv_theme_get_font_title());
    }
}
#endif

#if LV_DEMO_WIDGETS_SLIDESHOW

static void tab_content_anim_create(lv_obj_t * parent)
{
    lv_anim_t a;
    lv_obj_t * scrl = lv_page_get_scrl(parent);
    lv_coord_t y_start = lv_obj_get_style_pad_top(parent, LV_PAGE_PART_BG);
    lv_coord_t anim_h = lv_obj_get_height(scrl) - lv_obj_get_height_fit(parent);
    uint32_t anim_time = lv_anim_speed_to_time(LV_DPI, 0, anim_h);

    lv_anim_init(&a);
    lv_anim_set_var(&a, scrl);
    lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)lv_obj_set_y);
    lv_anim_set_values(&a, y_start, y_start - anim_h);
    lv_anim_set_time(&a, anim_time);
    lv_anim_set_playback_time(&a, anim_time);
    lv_anim_set_playback_delay(&a, 200);
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_repeat_delay(&a, 200);
    lv_anim_start(&a);
}
static void tab_changer_task_cb(lv_task_t * task)
{
    uint16_t act = lv_tabview_get_tab_act(tv);
    act++;
    if(act >= 3) act = 0;

    lv_tabview_set_tab_act(tv, act, LV_ANIM_ON);

    switch(act) {
    case 0:
        tab_content_anim_create(t1);
        break;
    case 1:
        tab_content_anim_create(t2);
        break;
    case 2:
        tab_content_anim_create(t3);
        break;
    }
}
#endif

