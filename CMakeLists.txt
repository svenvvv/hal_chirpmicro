#
# Copyright (c) 2021 TalTech
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_HAS_SONICLIB)

zephyr_library()

if(CONFIG_CH101 OR CONFIG_CH201)

if(CONFIG_SONICLIB_DEBUG)
    add_definitions(-DCHDRV_DEBUG)
endif()

# There is a CMake file provided in the library, but it builds the whole thing
# (incl. multiple ASIC FW blobs), so let's just pick out what we want ;).
zephyr_include_directories(soniclib/inc
			   ${PROJECT_SOURCE_DIR}/drivers/soniclib)
zephyr_library_sources(soniclib/src/ch_api.c)
zephyr_library_sources(soniclib/src/ch_common.c)
zephyr_library_sources(soniclib/src/ch_driver.c)
zephyr_library_sources(soniclib/src/ch_math_utils.c)

# TODO Kconfig-based FW selection
zephyr_library_sources(soniclib/src/ch201_gprmt.c)
zephyr_library_sources(soniclib/src/ch201_gprmt_fw.c)
endif()

endif()
