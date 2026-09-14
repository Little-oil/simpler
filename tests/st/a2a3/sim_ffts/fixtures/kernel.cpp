/*
 * Copyright (c) PyPTO Contributors.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 * -----------------------------------------------------------------------------------------------------------
 */

#include <cstddef>
#include <cstdint>

extern "C" void signal_event(int event) {
    __builtin_cce_ffts_cross_core_sync(0, pto::getFFTSMsg(FFTS_MODE_VAL, event));
}

extern "C" void wait_event(int event) { __builtin_cce_wait_flag_dev(event); }

extern "C" void legacy_signal_event(int event) { ffts_cross_core_sync(0, pto::getFFTSMsg(FFTS_MODE_VAL, event)); }

extern "C" void legacy_wait_event(int event) { wait_flag_dev(event); }

// CPU event tests exercise ordering independently of hardware pipeline selection.
extern "C" void signal_message(int mode, int event, int count) {
    __builtin_cce_ffts_cross_core_sync(0, pto::getFFTSMsg(mode, event, count));
}

extern "C" int encode_message(int mode, int event, int count) { return pto::getFFTSMsg(mode, event, count); }
