################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
source/cc3100/cc3100_device.obj: ../source/cc3100/cc3100_device.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/adi/workspace_v7/smarterHome_CC1350_LAUNCHXL_433_tirtos_ccs" --include_path="C:/TI/simplelink_cc13x0_sdk_1_50_00_08/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --define=DeviceFamily_CC13X0 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="source/cc3100/cc3100_device.d_raw" --obj_directory="source/cc3100" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/cc3100/device.obj: ../source/cc3100/device.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/adi/workspace_v7/smarterHome_CC1350_LAUNCHXL_433_tirtos_ccs" --include_path="C:/TI/simplelink_cc13x0_sdk_1_50_00_08/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --define=DeviceFamily_CC13X0 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="source/cc3100/device.d_raw" --obj_directory="source/cc3100" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/cc3100/driver.obj: ../source/cc3100/driver.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/adi/workspace_v7/smarterHome_CC1350_LAUNCHXL_433_tirtos_ccs" --include_path="C:/TI/simplelink_cc13x0_sdk_1_50_00_08/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --define=DeviceFamily_CC13X0 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="source/cc3100/driver.d_raw" --obj_directory="source/cc3100" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/cc3100/extensions.obj: ../source/cc3100/extensions.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/adi/workspace_v7/smarterHome_CC1350_LAUNCHXL_433_tirtos_ccs" --include_path="C:/TI/simplelink_cc13x0_sdk_1_50_00_08/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --define=DeviceFamily_CC13X0 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="source/cc3100/extensions.d_raw" --obj_directory="source/cc3100" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/cc3100/flowcont.obj: ../source/cc3100/flowcont.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/adi/workspace_v7/smarterHome_CC1350_LAUNCHXL_433_tirtos_ccs" --include_path="C:/TI/simplelink_cc13x0_sdk_1_50_00_08/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --define=DeviceFamily_CC13X0 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="source/cc3100/flowcont.d_raw" --obj_directory="source/cc3100" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/cc3100/fs.obj: ../source/cc3100/fs.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/adi/workspace_v7/smarterHome_CC1350_LAUNCHXL_433_tirtos_ccs" --include_path="C:/TI/simplelink_cc13x0_sdk_1_50_00_08/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --define=DeviceFamily_CC13X0 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="source/cc3100/fs.d_raw" --obj_directory="source/cc3100" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/cc3100/netapp.obj: ../source/cc3100/netapp.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/adi/workspace_v7/smarterHome_CC1350_LAUNCHXL_433_tirtos_ccs" --include_path="C:/TI/simplelink_cc13x0_sdk_1_50_00_08/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --define=DeviceFamily_CC13X0 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="source/cc3100/netapp.d_raw" --obj_directory="source/cc3100" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/cc3100/netcfg.obj: ../source/cc3100/netcfg.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/adi/workspace_v7/smarterHome_CC1350_LAUNCHXL_433_tirtos_ccs" --include_path="C:/TI/simplelink_cc13x0_sdk_1_50_00_08/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --define=DeviceFamily_CC13X0 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="source/cc3100/netcfg.d_raw" --obj_directory="source/cc3100" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/cc3100/nonos.obj: ../source/cc3100/nonos.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/adi/workspace_v7/smarterHome_CC1350_LAUNCHXL_433_tirtos_ccs" --include_path="C:/TI/simplelink_cc13x0_sdk_1_50_00_08/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --define=DeviceFamily_CC13X0 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="source/cc3100/nonos.d_raw" --obj_directory="source/cc3100" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/cc3100/socket.obj: ../source/cc3100/socket.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/adi/workspace_v7/smarterHome_CC1350_LAUNCHXL_433_tirtos_ccs" --include_path="C:/TI/simplelink_cc13x0_sdk_1_50_00_08/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --define=DeviceFamily_CC13X0 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="source/cc3100/socket.d_raw" --obj_directory="source/cc3100" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/cc3100/spawn.obj: ../source/cc3100/spawn.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/adi/workspace_v7/smarterHome_CC1350_LAUNCHXL_433_tirtos_ccs" --include_path="C:/TI/simplelink_cc13x0_sdk_1_50_00_08/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --define=DeviceFamily_CC13X0 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="source/cc3100/spawn.d_raw" --obj_directory="source/cc3100" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/cc3100/spi.obj: ../source/cc3100/spi.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/adi/workspace_v7/smarterHome_CC1350_LAUNCHXL_433_tirtos_ccs" --include_path="C:/TI/simplelink_cc13x0_sdk_1_50_00_08/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --define=DeviceFamily_CC13X0 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="source/cc3100/spi.d_raw" --obj_directory="source/cc3100" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/cc3100/wlan.obj: ../source/cc3100/wlan.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/adi/workspace_v7/smarterHome_CC1350_LAUNCHXL_433_tirtos_ccs" --include_path="C:/TI/simplelink_cc13x0_sdk_1_50_00_08/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --define=DeviceFamily_CC13X0 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="source/cc3100/wlan.d_raw" --obj_directory="source/cc3100" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


