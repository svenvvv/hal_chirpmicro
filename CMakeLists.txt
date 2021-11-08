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
		zephyr_include_directories(soniclib/inc fw_init_wrapper)

		zephyr_library_sources(soniclib/src/ch_api.c)
		zephyr_library_sources(soniclib/src/ch_common.c)
		zephyr_library_sources(soniclib/src/ch_driver.c)
		zephyr_library_sources(soniclib/src/ch_math_utils.c)

		# We can't "see" the module's definitions in the CH201 driver code and I
		# didn't want to mix the module's configuration and driver configuration
		# where possible. So let's use a little wrapper function with a known name
		# which calls the configured FW init function (where the name changes per FW).
		#
		# Since the preprocessor "sees" the FW_INIT_FN only during the compilation of
		# this module then the wrapper can't just be defined as a static fn() in a
		# header.
		add_definitions(-DCONFIG_SONICLIB_FW_INIT_FN=${CONFIG_SONICLIB_FW_PREFIX}_init)
		zephyr_library_sources(soniclib/src/${CONFIG_SONICLIB_FW_PREFIX}.c)
		zephyr_library_sources(soniclib/src/${CONFIG_SONICLIB_FW_PREFIX}_fw.c)
		zephyr_library_sources(fw_init_wrapper/chirp_fw_init_wrapper.c)

	endif()

endif()
