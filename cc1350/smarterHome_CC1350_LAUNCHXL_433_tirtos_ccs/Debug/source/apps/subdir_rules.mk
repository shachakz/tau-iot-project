################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
source/apps/app_main.obj: ../source/apps/app_main.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/adi/workspace_v7/smarterHome_CC1350_LAUNCHXL_433_tirtos_ccs" --include_path="C:/TI/simplelink_cc13x0_sdk_1_50_00_08/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --define=DeviceFamily_CC13X0 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="source/apps/app_main.d_raw" --obj_directory="source/apps" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/apps/app_mqtt.obj: ../source/apps/app_mqtt.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/adi/workspace_v7/smarterHome_CC1350_LAUNCHXL_433_tirtos_ccs" --include_path="C:/TI/simplelink_cc13x0_sdk_1_50_00_08/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --define=DeviceFamily_CC13X0 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="source/apps/app_mqtt.d_raw" --obj_directory="source/apps" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/apps/app_user.obj: ../source/apps/app_user.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/adi/workspace_v7/smarterHome_CC1350_LAUNCHXL_433_tirtos_ccs" --include_path="C:/TI/simplelink_cc13x0_sdk_1_50_00_08/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --define=DeviceFamily_CC13X0 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="source/apps/app_user.d_raw" --obj_directory="source/apps" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/apps/app_wifi.obj: ../source/apps/app_wifi.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/adi/workspace_v7/smarterHome_CC1350_LAUNCHXL_433_tirtos_ccs" --include_path="C:/TI/simplelink_cc13x0_sdk_1_50_00_08/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --define=DeviceFamily_CC13X0 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="source/apps/app_wifi.d_raw" --obj_directory="source/apps" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/apps/app_wifi_evt.obj: ../source/apps/app_wifi_evt.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/adi/workspace_v7/smarterHome_CC1350_LAUNCHXL_433_tirtos_ccs" --include_path="C:/TI/simplelink_cc13x0_sdk_1_50_00_08/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --define=DeviceFamily_CC13X0 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="source/apps/app_wifi_evt.d_raw" --obj_directory="source/apps" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


