/*
 * OpenHMD
 *
 * Copyright (C) 2013 Fredrik Hultin
 * Copyright (C) 2013 Jakob Bornecrantz
 *
 * Vive Libre
 *
 * Copyright (C) 2016 Lubosz Sarnecki <lubosz.sarnecki@collabora.co.uk>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Suite 500,
 * Boston, MA 02110-1335, USA.
 */

#pragma once

#include <hidapi.h>

#include "vl_magic.h"
#include "vl_fusion.h"
#include "vl_messages.h"

#define FEATURE_BUFFER_SIZE 256

#define HTC_ID                   0x0bb4
#define VIVE_HMD                 0x2c87

#define VALVE_ID                 0x28de
#define VIVE_WATCHMAN_DONGLE     0x2101
#define VIVE_LIGHTHOUSE_FPGA_RX  0x2000
#define VIVE_CONTROLLER          0x2012

#define FREQ_48MHZ 1.0f / 48000000.0f

typedef struct {
    hid_device* hmd_device;
    hid_device* hmd_imu_device;
    hid_device* watchman_dongle_device;
    hid_device* hmd_light_sensor_device;
    uint32_t previous_ticks;
    vl_fusion sensor_fusion;
} vl_driver;

vl_driver* vl_driver_init();
void vl_driver_close(vl_driver* drv);
vl_driver* vl_driver_open_device(int idx);

void vl_driver_log_watchman(hid_device *dev);
void vl_driver_log_hmd_light(hid_device *dev);
void vl_driver_log_hmd_imu(hid_device* dev);

void vl_driver_update_pose(vl_driver* drv);
