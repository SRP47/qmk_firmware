// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* ============================================
 * CONFIGURATION - Matching working lechiffre setup
 * ============================================ */

/* COMBO SETTINGS */
#define COMBO_COUNT 3
#define COMBO_TERM 30

// Reduce buffer sizes for atmega32u2's limited RAM (1KB vs 16KB)
#define COMBO_BUFFER_LENGTH 4
#define COMBO_KEY_BUFFER_LENGTH 8

/* MOD-TAP SETTINGS */
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD
