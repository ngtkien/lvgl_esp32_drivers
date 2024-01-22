/**
 * @file ra8875.h
 *
 */

#ifndef RA8875_H
#define RA8875_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include <stdbool.h>

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

/*********************
 *      DEFINES
 *********************/
#define RA8875_RST  CONFIG_LV_DISP_PIN_RST

// System & Configuration Registers
#define RA8875_REG_PWRR   (0x01)     // Power and Display Control Register (PWRR)
#define RA8875_REG_MRWC   (0x02)     // Memory Read/Write Command (MRWC)
#define RA8875_REG_PCSR   (0x04)     // Pixel Clock Setting Register (PCSR)
#define RA8875_REG_SYSR   (0x10)     // System Configuration Register (SYSR)
#define RA8875_REG_HDWR   (0x14)     // LCD Horizontal Display Width Register (HDWR)
#define RA8875_REG_HNDFTR (0x15)     // Horizontal Non-Display Period Fine Tuning Option Register (HNDFTR)
#define RA8875_REG_HNDR   (0x16)     // LCD Horizontal Non-Display Period Register (HNDR)
#define RA8875_REG_HSTR   (0x17)     // HSYNC Start Position Register (HSTR)
#define RA8875_REG_HPWR   (0x18)     // HSYNC Pulse Width Register (HPWR)
#define RA8875_REG_VDHR0  (0x19)     // LCD Vertical Display Height Register (VDHR0)
#define RA8875_REG_VDHR1  (0x1A)     // LCD Vertical Display Height Register (VDHR1)
#define RA8875_REG_VNDR0  (0x1B)     // LCD Vertical Non-Display Period Register (VNDR0)
#define RA8875_REG_VNDR1  (0x1C)     // LCD Vertical Non-Display Period Register (VNDR1)
#define RA8875_REG_VSTR0  (0x1D)     // VSYNC Start Position Register (VSTR0)
#define RA8875_REG_VSTR1  (0x1E)     // VSYNC Start Position Register (VSTR1)
#define RA8875_REG_VPWR   (0x1F)     // VSYNC Pulse Width Register (VPWR)

// LCD Display Control Registers
#define RA8875_REG_DPCR   (0x20)     // Display Configuration Register (DPCR)

// Active Window & Scroll Window Setting Registers
#define RA8875_REG_HSAW0  (0x30)     // Horizontal Start Point 0 of Active Window (HSAW0)
#define RA8875_REG_HSAW1  (0x31)     // Horizontal Start Point 1 of Active Window (HSAW1)
#define RA8875_REG_VSAW0  (0x32)     // Vertical Start Point 0 of Active Window (VSAW0)
#define RA8875_REG_VSAW1  (0x33)     // Vertical Start Point 1 of Active Window (VSAW1)
#define RA8875_REG_HEAW0  (0x34)     // Horizontal End Point 0 of Active Window (HEAW0)
#define RA8875_REG_HEAW1  (0x35)     // Horizontal End Point 1 of Active Window (HEAW1)
#define RA8875_REG_VEAW0  (0x36)     // Vertical End Point 0 of Active Window (VEAW0)
#define RA8875_REG_VEAW1  (0x37)     // Vertical End Point 1 of Active Window (VEAW1)

// Cursor Setting Registers
#define RA8875_REG_MWCR0  (0x40)     // Memory Write Control Register 0 (MWCR0)
#define RA8875_REG_MWCR1  (0x41)     // Memory Write Control Register 1 (MWCR1)
#define RA8875_REG_CURH0  (0x46)     // Memory Write Cursor Horizontal Position Register 0 (CURH0)
#define RA8875_REG_CURH1  (0x47)     // Memory Write Cursor Horizontal Position Register 1 (CURH1)
#define RA8875_REG_CURV0  (0x48)     // Memory Write Cursor Vertical Position Register 0 (CURV0)
#define RA8875_REG_CURV1  (0x49)     // Memory Write Cursor Vertical Position Register 1 (CURV1)

// Block Transfer Engine(BTE) Control Registers
#define RA8875_REG_LTPR0  (0x52)     // Layer Transparency Register 0 (LTPR0)
#define RA8875_REG_LTPR1  (0x53)     // Layer Transparency Register 1 (LTPR1)

// Touch Panel Control Registers
#define RA8875_REG_TPCR0  (0x70)     // Touch Panel Control Register 0 (TPCR0)
#define RA8875_REG_TPCR1  (0x71)     // Touch Panel Control Register 1 (TPCR1)
#define RA8875_REG_TPXH   (0x72)     // Touch Panel X High Byte Data Register (TPXH)
#define RA8875_REG_TPYH   (0x73)     // Touch Panel Y High Byte Data Register (TPYH)
#define RA8875_REG_TPXYL  (0x74)     // Touch Panel X/Y Low Byte Data Register (TPXYL)

// PLL Setting Registers
#define RA8875_REG_PLLC1  (0x88)     // PLL Control Register 1 (PLLC1)
#define RA8875_REG_PLLC2  (0x89)     // PLL Control Register 2 (PLLC2)

// Memory Clear Register
#define RA8875_REG_MCLR   (0x8E)     // Memory Clear Control Register (MCLR)

// Interrupt Control Registers
#define RA8875_REG_INTC1  (0xF0)     // Interrupt Control Register1 (INTC1)
#define RA8875_REG_INTC2  (0xF1)     // Interrupt Control Register1 (INTC2)


#define RA8875_GPIOX (0xC7) ///< See datasheet
#define RA8875_P1CR 0x8A         ///< See datasheet
#define RA8875_P1CR_ENABLE 0x80  ///< See datasheet
#define RA8875_P1CR_DISABLE 0x00 ///< See datasheet
#define RA8875_P1CR_CLKOUT 0x10  ///< See datasheet
#define RA8875_P1CR_PWMOUT 0x00  ///< See datasheet
#define RA8875_P1DCR 0x8B ///< See datasheet
#define RA8875_P2CR_ENABLE 0x80  ///< See datasheet
#define RA8875_P2CR_DISABLE 0x00 ///< See datasheet
#define RA8875_P2CR_CLKOUT 0x10  ///< See datasheet
#define RA8875_P2CR_PWMOUT 0x00  ///< See datasheet
#define RA8875_P2DCR 0x8D ///< See datasheet

#define RA8875_PWM_CLK_DIV1 0x00     ///< See datasheet
#define RA8875_PWM_CLK_DIV2 0x01     ///< See datasheet
#define RA8875_PWM_CLK_DIV4 0x02     ///< See datasheet
#define RA8875_PWM_CLK_DIV8 0x03     ///< See datasheet
#define RA8875_PWM_CLK_DIV16 0x04    ///< See datasheet
#define RA8875_PWM_CLK_DIV32 0x05    ///< See datasheet
#define RA8875_PWM_CLK_DIV64 0x06    ///< See datasheet
#define RA8875_PWM_CLK_DIV128 0x07   ///< See datasheet
#define RA8875_PWM_CLK_DIV256 0x08   ///< See datasheet
#define RA8875_PWM_CLK_DIV512 0x09   ///< See datasheet
#define RA8875_PWM_CLK_DIV1024 0x0A  ///< See datasheet
#define RA8875_PWM_CLK_DIV2048 0x0B  ///< See datasheet
#define RA8875_PWM_CLK_DIV4096 0x0C  ///< See datasheet
#define RA8875_PWM_CLK_DIV8192 0x0D  ///< See datasheet
#define RA8875_PWM_CLK_DIV16384 0x0E ///< See datasheet
#define RA8875_PWM_CLK_DIV32768 0x0F ///< See datasheet

#define RA8875_PLLC1 0x88         ///< See datasheet
#define RA8875_PLLC1_PLLDIV2 0x80 ///< See datasheet
#define RA8875_PLLC1_PLLDIV1 0x00 ///< See datasheet

#define RA8875_PLLC2 0x89        ///< See datasheet
#define RA8875_PLLC2_DIV1 0x00   ///< See datasheet
#define RA8875_PLLC2_DIV2 0x01   ///< See datasheet
#define RA8875_PLLC2_DIV4 0x02   ///< See datasheet
#define RA8875_PLLC2_DIV8 0x03   ///< See datasheet
#define RA8875_PLLC2_DIV16 0x04  ///< See datasheet
#define RA8875_PLLC2_DIV32 0x05  ///< See datasheet
#define RA8875_PLLC2_DIV64 0x06  ///< See datasheet
#define RA8875_PLLC2_DIV128 0x07 ///< See datasheet

#define RA8875_DCR 0x90                   ///< See datasheet
#define RA8875_DCR_LINESQUTRI_START 0x80  ///< See datasheet
#define RA8875_DCR_LINESQUTRI_STOP 0x00   ///< See datasheet
#define RA8875_DCR_LINESQUTRI_STATUS 0x80 ///< See datasheet
#define RA8875_DCR_CIRCLE_START 0x40      ///< See datasheet
#define RA8875_DCR_CIRCLE_STATUS 0x40     ///< See datasheet
#define RA8875_DCR_CIRCLE_STOP 0x00       ///< See datasheet
#define RA8875_DCR_FILL 0x20              ///< See datasheet
#define RA8875_DCR_NOFILL 0x00            ///< See datasheet
#define RA8875_DCR_DRAWLINE 0x00          ///< See datasheet
#define RA8875_DCR_DRAWTRIANGLE 0x01      ///< See datasheet
#define RA8875_DCR_DRAWSQUARE 0x10        ///< See datasheet

    /**********************
     *      TYPEDEFS
     **********************/

    /**********************
     * GLOBAL PROTOTYPES
     **********************/

    void ra8875_init(void);
    void ra8875_enable_backlight(bool backlight);
    void ra8875_enable_display(bool enable);
    void ra8875_flush(lv_disp_drv_t *drv, const lv_area_t *area, lv_color_t *color_map);

    void ra8875_sleep_in(void);
    void ra8875_sleep_out(void);

    uint8_t ra8875_read_cmd(uint8_t cmd);
    void ra8875_write_cmd(uint8_t cmd, uint8_t data);

    void ra8875_gpiox(bool on);
    void ra8875_PWM1config(bool on, uint8_t clock);
    void ra8875_PWM1out(uint8_t p);
    void ra8875_PWM2out(uint8_t p);

    void rectHelper(int16_t x, int16_t y, int16_t w, int16_t h,
                    uint16_t color, bool filled);
    /**********************
     *      MACROS
     **********************/


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*RA8875_H*/
