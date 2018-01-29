################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
source/mqtt/MQTTCC3100.obj: ../source/mqtt/MQTTCC3100.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/adi/workspace_v7/smarterHome_CC1350_LAUNCHXL_433_tirtos_ccs" --include_path="C:/TI/simplelink_cc13x0_sdk_1_50_00_08/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --define=DeviceFamily_CC13X0 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="source/mqtt/MQTTCC3100.d_raw" --obj_directory="source/mqtt" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/mqtt/MQTTClient.obj: ../source/mqtt/MQTTClient.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/adi/workspace_v7/smarterHome_CC1350_LAUNCHXL_433_tirtos_ccs" --include_path="C:/TI/simplelink_cc13x0_sdk_1_50_00_08/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --define=DeviceFamily_CC13X0 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="source/mqtt/MQTTClient.d_raw" --obj_directory="source/mqtt" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/mqtt/MQTTConnectClient.obj: ../source/mqtt/MQTTConnectClient.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/adi/workspace_v7/smarterHome_CC1350_LAUNCHXL_433_tirtos_ccs" --include_path="C:/TI/simplelink_cc13x0_sdk_1_50_00_08/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --define=DeviceFamily_CC13X0 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="source/mqtt/MQTTConnectClient.d_raw" --obj_directory="source/mqtt" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/mqtt/MQTTConnectServer.obj: ../source/mqtt/MQTTConnectServer.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/adi/workspace_v7/smarterHome_CC1350_LAUNCHXL_433_tirtos_ccs" --include_path="C:/TI/simplelink_cc13x0_sdk_1_50_00_08/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --define=DeviceFamily_CC13X0 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="source/mqtt/MQTTConnectServer.d_raw" --obj_directory="source/mqtt" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/mqtt/MQTTDeserializePublish.obj: ../source/mqtt/MQTTDeserializePublish.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/adi/workspace_v7/smarterHome_CC1350_LAUNCHXL_433_tirtos_ccs" --include_path="C:/TI/simplelink_cc13x0_sdk_1_50_00_08/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --define=DeviceFamily_CC13X0 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="source/mqtt/MQTTDeserializePublish.d_raw" --obj_directory="source/mqtt" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/mqtt/MQTTFormat.obj: ../source/mqtt/MQTTFormat.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/adi/workspace_v7/smarterHome_CC1350_LAUNCHXL_433_tirtos_ccs" --include_path="C:/TI/simplelink_cc13x0_sdk_1_50_00_08/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --define=DeviceFamily_CC13X0 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="source/mqtt/MQTTFormat.d_raw" --obj_directory="source/mqtt" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/mqtt/MQTTPacket.obj: ../source/mqtt/MQTTPacket.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/adi/workspace_v7/smarterHome_CC1350_LAUNCHXL_433_tirtos_ccs" --include_path="C:/TI/simplelink_cc13x0_sdk_1_50_00_08/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --define=DeviceFamily_CC13X0 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="source/mqtt/MQTTPacket.d_raw" --obj_directory="source/mqtt" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/mqtt/MQTTSerializePublish.obj: ../source/mqtt/MQTTSerializePublish.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/adi/workspace_v7/smarterHome_CC1350_LAUNCHXL_433_tirtos_ccs" --include_path="C:/TI/simplelink_cc13x0_sdk_1_50_00_08/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --define=DeviceFamily_CC13X0 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="source/mqtt/MQTTSerializePublish.d_raw" --obj_directory="source/mqtt" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/mqtt/MQTTSubscribeClient.obj: ../source/mqtt/MQTTSubscribeClient.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/adi/workspace_v7/smarterHome_CC1350_LAUNCHXL_433_tirtos_ccs" --include_path="C:/TI/simplelink_cc13x0_sdk_1_50_00_08/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --define=DeviceFamily_CC13X0 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="source/mqtt/MQTTSubscribeClient.d_raw" --obj_directory="source/mqtt" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/mqtt/MQTTSubscribeServer.obj: ../source/mqtt/MQTTSubscribeServer.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/adi/workspace_v7/smarterHome_CC1350_LAUNCHXL_433_tirtos_ccs" --include_path="C:/TI/simplelink_cc13x0_sdk_1_50_00_08/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --define=DeviceFamily_CC13X0 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="source/mqtt/MQTTSubscribeServer.d_raw" --obj_directory="source/mqtt" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/mqtt/MQTTUnsubscribeClient.obj: ../source/mqtt/MQTTUnsubscribeClient.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/adi/workspace_v7/smarterHome_CC1350_LAUNCHXL_433_tirtos_ccs" --include_path="C:/TI/simplelink_cc13x0_sdk_1_50_00_08/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --define=DeviceFamily_CC13X0 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="source/mqtt/MQTTUnsubscribeClient.d_raw" --obj_directory="source/mqtt" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/mqtt/MQTTUnsubscribeServer.obj: ../source/mqtt/MQTTUnsubscribeServer.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/adi/workspace_v7/smarterHome_CC1350_LAUNCHXL_433_tirtos_ccs" --include_path="C:/TI/simplelink_cc13x0_sdk_1_50_00_08/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/TI/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --define=DeviceFamily_CC13X0 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="source/mqtt/MQTTUnsubscribeServer.d_raw" --obj_directory="source/mqtt" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


