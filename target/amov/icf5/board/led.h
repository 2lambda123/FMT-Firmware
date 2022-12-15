/******************************************************************************
 * Copyright 2022 The Firmament Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
#ifndef LED_H__
#define LED_H__

#include <firmament.h>

#include "driver/rgb_led/ncp5623c.h"
#include "hal/pin/pin.h"

#ifdef __cplusplus
extern "C" {
#endif

#define __GD32_PORT(port)   GPIO##port
#define GET_PIN(PORTx, PIN) (rt_base_t)((16 * (((rt_base_t)__GD32_PORT(PORTx) - (rt_base_t)GPIO_BASE) / (0x0400UL))) + PIN)

#define FMU_MCU_LED_PIN GET_PIN(B, 4)

#define LED_ON(_pin)     led_set((struct device_pin_status) { .pin = _pin, .status = 1 })
#define LED_OFF(_pin)    led_set((struct device_pin_status) { .pin = _pin, .status = 0 })
#define LED_TOGGLE(_pin) led_toggle(_pin)

#define RGB_LED_MANUAL_MODE  0
#define RGB_LED_PATERN_MODE 1

fmt_err_t led_control_init(void);
fmt_err_t led_init(struct device_pin_mode pin_mode);
fmt_err_t led_set(struct device_pin_status pin_sta);
fmt_err_t led_toggle(uint32_t pin);
fmt_err_t rgb_led_set_color(uint32_t color);
fmt_err_t rgb_led_set_bright(uint32_t bright);

#ifdef __cplusplus
}
#endif

#endif