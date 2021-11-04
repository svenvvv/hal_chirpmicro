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

		# Unimplemented as we don't need CH101 support :))
		# CONFIG_SONICLIB_FW_CH101_FLOOR_FW
		# CONFIG_SONICLIB_FW_CH101_GPR_RXOPT_NARROW_WD_FW
		# CONFIG_SONICLIB_FW_CH101_GPR_RXOPT_WD
		# CONFIG_SONICLIB_FW_CH101_GPR_RXOPT_WD
		# CONFIG_SONICLIB_FW_CH101_LIQUID_FW
		# CONFIG_SONICLIB_FW_CH101_GPR_OPEN_FW
		# CONFIG_SONICLIB_FW_CH101_GPR_NARROW_WD_FW
		# CONFIG_SONICLIB_FW_CH101_SONICSYNC_MASTER_FW
		# CONFIG_SONICLIB_FW_CH101_GPR_SR_OPEN_FW
		# CONFIG_SONICLIB_FW_CH101_GPR_RXOPT_FW
		# CONFIG_SONICLIB_FW_CH101_FINALTEST_FW
		# CONFIG_SONICLIB_FW_CH101_GPR_LOWPWR_FW
		# CONFIG_SONICLIB_FW_CH101_GPR_FW
		# CONFIG_SONICLIB_FW_CH101_GPR_SR_WD_FW
		# CONFIG_SONICLIB_FW_CH101_GPR_WD_FW
		# CONFIG_SONICLIB_FW_CH101_SONICSYNC_SLAVE_FW
		# CONFIG_SONICLIB_FW_CH101_GPR_RXOPT_NARROW_FW
		# CONFIG_SONICLIB_FW_CH101_GPR_SR_NARROW_FW
		# CONFIG_SONICLIB_FW_CH101_GPR_SR_FW
		# CONFIG_SONICLIB_FW_CH101_GPR_NARROW_FW
		# CONFIG_SONICLIB_FW_CH101_GPR_SR_NARROW_WD_FW
		# CONFIG_SONICLIB_FW_CH101_GPPC_FW
		if (CONFIG_SONICLIB_FW_CH201_GPRSTR_FW)
			zephyr_library_sources(soniclib/src/ch201_gprstr.c)
			zephyr_library_sources(soniclib/src/ch201_gprstr_fw.c)
			add_definitions(-DSONICLIB_INIT=ch201_gprstr_init)
		endif()

		if (CONFIG_SONICLIB_FW_CH201_GPRSTR_WD_FW)
			zephyr_library_sources(soniclib/src/ch201_gprstr_wd.c)
			zephyr_library_sources(soniclib/src/ch201_gprstr_wd_fw.c)
			add_definitions(-DSONICLIB_INIT=ch201_gprstr_wd_init)
		endif()

		if (CONFIG_SONICLIB_FW_CH201_GPRMT_WD_FW)
			zephyr_library_sources(soniclib/src/ch201_gprmt_wd.c)
			zephyr_library_sources(soniclib/src/ch201_gprmt_wd_fw.c)
			add_definitions(-DSONICLIB_INIT=ch201_gprmt_wd_init)
		endif()

		if (CONFIG_SONICLIB_FW_CH201_GPRMT_FW)
			zephyr_library_sources(soniclib/src/ch201_gprmt.c)
			zephyr_library_sources(soniclib/src/ch201_gprmt_fw.c)
			add_definitions(-DSONICLIB_INIT=ch201_gprmt_init)
		endif()

		if (CONFIG_SONICLIB_FW_CH201_PRESENCE_FW)
			zephyr_library_sources(soniclib/src/ch201_presence.c)
			zephyr_library_sources(soniclib/src/ch201_presence_fw.c)
			add_definitions(-DSONICLIB_INIT=ch201_presence_init)
		endif()

		if (CONFIG_SONICLIB_FW_CH201_FINALTEST_FW)
			zephyr_library_sources(soniclib/src/ch201_finaltest.c)
			zephyr_library_sources(soniclib/src/ch201_finaltest_fw.c)
			add_definitions(-DSONICLIB_INIT=ch201_finaltest_init)
		endif()

	endif()

endif()
