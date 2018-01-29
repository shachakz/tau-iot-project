#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/TI/simplelink_cc13x0_sdk_1_50_00_08/source;C:/TI/simplelink_cc13x0_sdk_1_50_00_08/kernel/tirtos/packages;C:/TI/ccsv7/ccs_base
override XDCROOT = C:/TI/xdctools_3_50_03_33_core
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/TI/simplelink_cc13x0_sdk_1_50_00_08/source;C:/TI/simplelink_cc13x0_sdk_1_50_00_08/kernel/tirtos/packages;C:/TI/ccsv7/ccs_base;C:/TI/xdctools_3_50_03_33_core/packages;..
HOSTOS = Windows
endif
