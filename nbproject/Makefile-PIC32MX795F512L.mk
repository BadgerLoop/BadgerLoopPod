#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-PIC32MX795F512L.mk)" "nbproject/Makefile-local-PIC32MX795F512L.mk"
include nbproject/Makefile-local-PIC32MX795F512L.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=PIC32MX795F512L
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/BadgerLoopPod.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/BadgerLoopPod.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=C_Drivers/MPU6050.c C_Drivers/SparkFun_VL6180X.c C_Drivers/I2Cdev.c CANopenNode/CANopen.c CANopenNode/CO_driver.c CANopenNode/CO_Emergency.c CANopenNode/CO_HBconsumer.c CANopenNode/CO_NMT_Heartbeat.c CANopenNode/CO_OD.c CANopenNode/CO_PDO.c CANopenNode/CO_SDO.c CANopenNode/CO_SDOmaster.c CANopenNode/CO_SYNC.c CANopenNode/crc16-ccitt.c CANopenNode/eeprom.c configuration_bits.c exceptions.c interrupts.c main.c system.c user.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/C_Drivers/MPU6050.o ${OBJECTDIR}/C_Drivers/SparkFun_VL6180X.o ${OBJECTDIR}/C_Drivers/I2Cdev.o ${OBJECTDIR}/CANopenNode/CANopen.o ${OBJECTDIR}/CANopenNode/CO_driver.o ${OBJECTDIR}/CANopenNode/CO_Emergency.o ${OBJECTDIR}/CANopenNode/CO_HBconsumer.o ${OBJECTDIR}/CANopenNode/CO_NMT_Heartbeat.o ${OBJECTDIR}/CANopenNode/CO_OD.o ${OBJECTDIR}/CANopenNode/CO_PDO.o ${OBJECTDIR}/CANopenNode/CO_SDO.o ${OBJECTDIR}/CANopenNode/CO_SDOmaster.o ${OBJECTDIR}/CANopenNode/CO_SYNC.o ${OBJECTDIR}/CANopenNode/crc16-ccitt.o ${OBJECTDIR}/CANopenNode/eeprom.o ${OBJECTDIR}/configuration_bits.o ${OBJECTDIR}/exceptions.o ${OBJECTDIR}/interrupts.o ${OBJECTDIR}/main.o ${OBJECTDIR}/system.o ${OBJECTDIR}/user.o
POSSIBLE_DEPFILES=${OBJECTDIR}/C_Drivers/MPU6050.o.d ${OBJECTDIR}/C_Drivers/SparkFun_VL6180X.o.d ${OBJECTDIR}/C_Drivers/I2Cdev.o.d ${OBJECTDIR}/CANopenNode/CANopen.o.d ${OBJECTDIR}/CANopenNode/CO_driver.o.d ${OBJECTDIR}/CANopenNode/CO_Emergency.o.d ${OBJECTDIR}/CANopenNode/CO_HBconsumer.o.d ${OBJECTDIR}/CANopenNode/CO_NMT_Heartbeat.o.d ${OBJECTDIR}/CANopenNode/CO_OD.o.d ${OBJECTDIR}/CANopenNode/CO_PDO.o.d ${OBJECTDIR}/CANopenNode/CO_SDO.o.d ${OBJECTDIR}/CANopenNode/CO_SDOmaster.o.d ${OBJECTDIR}/CANopenNode/CO_SYNC.o.d ${OBJECTDIR}/CANopenNode/crc16-ccitt.o.d ${OBJECTDIR}/CANopenNode/eeprom.o.d ${OBJECTDIR}/configuration_bits.o.d ${OBJECTDIR}/exceptions.o.d ${OBJECTDIR}/interrupts.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/system.o.d ${OBJECTDIR}/user.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/C_Drivers/MPU6050.o ${OBJECTDIR}/C_Drivers/SparkFun_VL6180X.o ${OBJECTDIR}/C_Drivers/I2Cdev.o ${OBJECTDIR}/CANopenNode/CANopen.o ${OBJECTDIR}/CANopenNode/CO_driver.o ${OBJECTDIR}/CANopenNode/CO_Emergency.o ${OBJECTDIR}/CANopenNode/CO_HBconsumer.o ${OBJECTDIR}/CANopenNode/CO_NMT_Heartbeat.o ${OBJECTDIR}/CANopenNode/CO_OD.o ${OBJECTDIR}/CANopenNode/CO_PDO.o ${OBJECTDIR}/CANopenNode/CO_SDO.o ${OBJECTDIR}/CANopenNode/CO_SDOmaster.o ${OBJECTDIR}/CANopenNode/CO_SYNC.o ${OBJECTDIR}/CANopenNode/crc16-ccitt.o ${OBJECTDIR}/CANopenNode/eeprom.o ${OBJECTDIR}/configuration_bits.o ${OBJECTDIR}/exceptions.o ${OBJECTDIR}/interrupts.o ${OBJECTDIR}/main.o ${OBJECTDIR}/system.o ${OBJECTDIR}/user.o

# Source Files
SOURCEFILES=C_Drivers/MPU6050.c C_Drivers/SparkFun_VL6180X.c C_Drivers/I2Cdev.c CANopenNode/CANopen.c CANopenNode/CO_driver.c CANopenNode/CO_Emergency.c CANopenNode/CO_HBconsumer.c CANopenNode/CO_NMT_Heartbeat.c CANopenNode/CO_OD.c CANopenNode/CO_PDO.c CANopenNode/CO_SDO.c CANopenNode/CO_SDOmaster.c CANopenNode/CO_SYNC.c CANopenNode/crc16-ccitt.c CANopenNode/eeprom.c configuration_bits.c exceptions.c interrupts.c main.c system.c user.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-PIC32MX795F512L.mk dist/${CND_CONF}/${IMAGE_TYPE}/BadgerLoopPod.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX795F512L
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/C_Drivers/MPU6050.o: C_Drivers/MPU6050.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/C_Drivers" 
	@${RM} ${OBJECTDIR}/C_Drivers/MPU6050.o.d 
	@${RM} ${OBJECTDIR}/C_Drivers/MPU6050.o 
	@${FIXDEPS} "${OBJECTDIR}/C_Drivers/MPU6050.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/C_Drivers/MPU6050.o.d" -o ${OBJECTDIR}/C_Drivers/MPU6050.o C_Drivers/MPU6050.c     
	
${OBJECTDIR}/C_Drivers/SparkFun_VL6180X.o: C_Drivers/SparkFun_VL6180X.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/C_Drivers" 
	@${RM} ${OBJECTDIR}/C_Drivers/SparkFun_VL6180X.o.d 
	@${RM} ${OBJECTDIR}/C_Drivers/SparkFun_VL6180X.o 
	@${FIXDEPS} "${OBJECTDIR}/C_Drivers/SparkFun_VL6180X.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/C_Drivers/SparkFun_VL6180X.o.d" -o ${OBJECTDIR}/C_Drivers/SparkFun_VL6180X.o C_Drivers/SparkFun_VL6180X.c     
	
${OBJECTDIR}/C_Drivers/I2Cdev.o: C_Drivers/I2Cdev.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/C_Drivers" 
	@${RM} ${OBJECTDIR}/C_Drivers/I2Cdev.o.d 
	@${RM} ${OBJECTDIR}/C_Drivers/I2Cdev.o 
	@${FIXDEPS} "${OBJECTDIR}/C_Drivers/I2Cdev.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/C_Drivers/I2Cdev.o.d" -o ${OBJECTDIR}/C_Drivers/I2Cdev.o C_Drivers/I2Cdev.c     
	
${OBJECTDIR}/CANopenNode/CANopen.o: CANopenNode/CANopen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/CANopenNode" 
	@${RM} ${OBJECTDIR}/CANopenNode/CANopen.o.d 
	@${RM} ${OBJECTDIR}/CANopenNode/CANopen.o 
	@${FIXDEPS} "${OBJECTDIR}/CANopenNode/CANopen.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/CANopenNode/CANopen.o.d" -o ${OBJECTDIR}/CANopenNode/CANopen.o CANopenNode/CANopen.c     
	
${OBJECTDIR}/CANopenNode/CO_driver.o: CANopenNode/CO_driver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/CANopenNode" 
	@${RM} ${OBJECTDIR}/CANopenNode/CO_driver.o.d 
	@${RM} ${OBJECTDIR}/CANopenNode/CO_driver.o 
	@${FIXDEPS} "${OBJECTDIR}/CANopenNode/CO_driver.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/CANopenNode/CO_driver.o.d" -o ${OBJECTDIR}/CANopenNode/CO_driver.o CANopenNode/CO_driver.c     
	
${OBJECTDIR}/CANopenNode/CO_Emergency.o: CANopenNode/CO_Emergency.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/CANopenNode" 
	@${RM} ${OBJECTDIR}/CANopenNode/CO_Emergency.o.d 
	@${RM} ${OBJECTDIR}/CANopenNode/CO_Emergency.o 
	@${FIXDEPS} "${OBJECTDIR}/CANopenNode/CO_Emergency.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/CANopenNode/CO_Emergency.o.d" -o ${OBJECTDIR}/CANopenNode/CO_Emergency.o CANopenNode/CO_Emergency.c     
	
${OBJECTDIR}/CANopenNode/CO_HBconsumer.o: CANopenNode/CO_HBconsumer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/CANopenNode" 
	@${RM} ${OBJECTDIR}/CANopenNode/CO_HBconsumer.o.d 
	@${RM} ${OBJECTDIR}/CANopenNode/CO_HBconsumer.o 
	@${FIXDEPS} "${OBJECTDIR}/CANopenNode/CO_HBconsumer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/CANopenNode/CO_HBconsumer.o.d" -o ${OBJECTDIR}/CANopenNode/CO_HBconsumer.o CANopenNode/CO_HBconsumer.c     
	
${OBJECTDIR}/CANopenNode/CO_NMT_Heartbeat.o: CANopenNode/CO_NMT_Heartbeat.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/CANopenNode" 
	@${RM} ${OBJECTDIR}/CANopenNode/CO_NMT_Heartbeat.o.d 
	@${RM} ${OBJECTDIR}/CANopenNode/CO_NMT_Heartbeat.o 
	@${FIXDEPS} "${OBJECTDIR}/CANopenNode/CO_NMT_Heartbeat.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/CANopenNode/CO_NMT_Heartbeat.o.d" -o ${OBJECTDIR}/CANopenNode/CO_NMT_Heartbeat.o CANopenNode/CO_NMT_Heartbeat.c     
	
${OBJECTDIR}/CANopenNode/CO_OD.o: CANopenNode/CO_OD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/CANopenNode" 
	@${RM} ${OBJECTDIR}/CANopenNode/CO_OD.o.d 
	@${RM} ${OBJECTDIR}/CANopenNode/CO_OD.o 
	@${FIXDEPS} "${OBJECTDIR}/CANopenNode/CO_OD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/CANopenNode/CO_OD.o.d" -o ${OBJECTDIR}/CANopenNode/CO_OD.o CANopenNode/CO_OD.c     
	
${OBJECTDIR}/CANopenNode/CO_PDO.o: CANopenNode/CO_PDO.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/CANopenNode" 
	@${RM} ${OBJECTDIR}/CANopenNode/CO_PDO.o.d 
	@${RM} ${OBJECTDIR}/CANopenNode/CO_PDO.o 
	@${FIXDEPS} "${OBJECTDIR}/CANopenNode/CO_PDO.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/CANopenNode/CO_PDO.o.d" -o ${OBJECTDIR}/CANopenNode/CO_PDO.o CANopenNode/CO_PDO.c     
	
${OBJECTDIR}/CANopenNode/CO_SDO.o: CANopenNode/CO_SDO.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/CANopenNode" 
	@${RM} ${OBJECTDIR}/CANopenNode/CO_SDO.o.d 
	@${RM} ${OBJECTDIR}/CANopenNode/CO_SDO.o 
	@${FIXDEPS} "${OBJECTDIR}/CANopenNode/CO_SDO.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/CANopenNode/CO_SDO.o.d" -o ${OBJECTDIR}/CANopenNode/CO_SDO.o CANopenNode/CO_SDO.c     
	
${OBJECTDIR}/CANopenNode/CO_SDOmaster.o: CANopenNode/CO_SDOmaster.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/CANopenNode" 
	@${RM} ${OBJECTDIR}/CANopenNode/CO_SDOmaster.o.d 
	@${RM} ${OBJECTDIR}/CANopenNode/CO_SDOmaster.o 
	@${FIXDEPS} "${OBJECTDIR}/CANopenNode/CO_SDOmaster.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/CANopenNode/CO_SDOmaster.o.d" -o ${OBJECTDIR}/CANopenNode/CO_SDOmaster.o CANopenNode/CO_SDOmaster.c     
	
${OBJECTDIR}/CANopenNode/CO_SYNC.o: CANopenNode/CO_SYNC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/CANopenNode" 
	@${RM} ${OBJECTDIR}/CANopenNode/CO_SYNC.o.d 
	@${RM} ${OBJECTDIR}/CANopenNode/CO_SYNC.o 
	@${FIXDEPS} "${OBJECTDIR}/CANopenNode/CO_SYNC.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/CANopenNode/CO_SYNC.o.d" -o ${OBJECTDIR}/CANopenNode/CO_SYNC.o CANopenNode/CO_SYNC.c     
	
${OBJECTDIR}/CANopenNode/crc16-ccitt.o: CANopenNode/crc16-ccitt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/CANopenNode" 
	@${RM} ${OBJECTDIR}/CANopenNode/crc16-ccitt.o.d 
	@${RM} ${OBJECTDIR}/CANopenNode/crc16-ccitt.o 
	@${FIXDEPS} "${OBJECTDIR}/CANopenNode/crc16-ccitt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/CANopenNode/crc16-ccitt.o.d" -o ${OBJECTDIR}/CANopenNode/crc16-ccitt.o CANopenNode/crc16-ccitt.c     
	
${OBJECTDIR}/CANopenNode/eeprom.o: CANopenNode/eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/CANopenNode" 
	@${RM} ${OBJECTDIR}/CANopenNode/eeprom.o.d 
	@${RM} ${OBJECTDIR}/CANopenNode/eeprom.o 
	@${FIXDEPS} "${OBJECTDIR}/CANopenNode/eeprom.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/CANopenNode/eeprom.o.d" -o ${OBJECTDIR}/CANopenNode/eeprom.o CANopenNode/eeprom.c     
	
${OBJECTDIR}/configuration_bits.o: configuration_bits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/configuration_bits.o.d 
	@${RM} ${OBJECTDIR}/configuration_bits.o 
	@${FIXDEPS} "${OBJECTDIR}/configuration_bits.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/configuration_bits.o.d" -o ${OBJECTDIR}/configuration_bits.o configuration_bits.c     
	
${OBJECTDIR}/exceptions.o: exceptions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/exceptions.o.d 
	@${RM} ${OBJECTDIR}/exceptions.o 
	@${FIXDEPS} "${OBJECTDIR}/exceptions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/exceptions.o.d" -o ${OBJECTDIR}/exceptions.o exceptions.c     
	
${OBJECTDIR}/interrupts.o: interrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/interrupts.o.d 
	@${RM} ${OBJECTDIR}/interrupts.o 
	@${FIXDEPS} "${OBJECTDIR}/interrupts.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/interrupts.o.d" -o ${OBJECTDIR}/interrupts.o interrupts.c     
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c     
	
${OBJECTDIR}/system.o: system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/system.o.d 
	@${RM} ${OBJECTDIR}/system.o 
	@${FIXDEPS} "${OBJECTDIR}/system.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/system.o.d" -o ${OBJECTDIR}/system.o system.c     
	
${OBJECTDIR}/user.o: user.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/user.o.d 
	@${RM} ${OBJECTDIR}/user.o 
	@${FIXDEPS} "${OBJECTDIR}/user.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/user.o.d" -o ${OBJECTDIR}/user.o user.c     
	
else
${OBJECTDIR}/C_Drivers/MPU6050.o: C_Drivers/MPU6050.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/C_Drivers" 
	@${RM} ${OBJECTDIR}/C_Drivers/MPU6050.o.d 
	@${RM} ${OBJECTDIR}/C_Drivers/MPU6050.o 
	@${FIXDEPS} "${OBJECTDIR}/C_Drivers/MPU6050.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/C_Drivers/MPU6050.o.d" -o ${OBJECTDIR}/C_Drivers/MPU6050.o C_Drivers/MPU6050.c     
	
${OBJECTDIR}/C_Drivers/SparkFun_VL6180X.o: C_Drivers/SparkFun_VL6180X.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/C_Drivers" 
	@${RM} ${OBJECTDIR}/C_Drivers/SparkFun_VL6180X.o.d 
	@${RM} ${OBJECTDIR}/C_Drivers/SparkFun_VL6180X.o 
	@${FIXDEPS} "${OBJECTDIR}/C_Drivers/SparkFun_VL6180X.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/C_Drivers/SparkFun_VL6180X.o.d" -o ${OBJECTDIR}/C_Drivers/SparkFun_VL6180X.o C_Drivers/SparkFun_VL6180X.c     
	
${OBJECTDIR}/C_Drivers/I2Cdev.o: C_Drivers/I2Cdev.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/C_Drivers" 
	@${RM} ${OBJECTDIR}/C_Drivers/I2Cdev.o.d 
	@${RM} ${OBJECTDIR}/C_Drivers/I2Cdev.o 
	@${FIXDEPS} "${OBJECTDIR}/C_Drivers/I2Cdev.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/C_Drivers/I2Cdev.o.d" -o ${OBJECTDIR}/C_Drivers/I2Cdev.o C_Drivers/I2Cdev.c     
	
${OBJECTDIR}/CANopenNode/CANopen.o: CANopenNode/CANopen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/CANopenNode" 
	@${RM} ${OBJECTDIR}/CANopenNode/CANopen.o.d 
	@${RM} ${OBJECTDIR}/CANopenNode/CANopen.o 
	@${FIXDEPS} "${OBJECTDIR}/CANopenNode/CANopen.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/CANopenNode/CANopen.o.d" -o ${OBJECTDIR}/CANopenNode/CANopen.o CANopenNode/CANopen.c     
	
${OBJECTDIR}/CANopenNode/CO_driver.o: CANopenNode/CO_driver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/CANopenNode" 
	@${RM} ${OBJECTDIR}/CANopenNode/CO_driver.o.d 
	@${RM} ${OBJECTDIR}/CANopenNode/CO_driver.o 
	@${FIXDEPS} "${OBJECTDIR}/CANopenNode/CO_driver.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/CANopenNode/CO_driver.o.d" -o ${OBJECTDIR}/CANopenNode/CO_driver.o CANopenNode/CO_driver.c     
	
${OBJECTDIR}/CANopenNode/CO_Emergency.o: CANopenNode/CO_Emergency.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/CANopenNode" 
	@${RM} ${OBJECTDIR}/CANopenNode/CO_Emergency.o.d 
	@${RM} ${OBJECTDIR}/CANopenNode/CO_Emergency.o 
	@${FIXDEPS} "${OBJECTDIR}/CANopenNode/CO_Emergency.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/CANopenNode/CO_Emergency.o.d" -o ${OBJECTDIR}/CANopenNode/CO_Emergency.o CANopenNode/CO_Emergency.c     
	
${OBJECTDIR}/CANopenNode/CO_HBconsumer.o: CANopenNode/CO_HBconsumer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/CANopenNode" 
	@${RM} ${OBJECTDIR}/CANopenNode/CO_HBconsumer.o.d 
	@${RM} ${OBJECTDIR}/CANopenNode/CO_HBconsumer.o 
	@${FIXDEPS} "${OBJECTDIR}/CANopenNode/CO_HBconsumer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/CANopenNode/CO_HBconsumer.o.d" -o ${OBJECTDIR}/CANopenNode/CO_HBconsumer.o CANopenNode/CO_HBconsumer.c     
	
${OBJECTDIR}/CANopenNode/CO_NMT_Heartbeat.o: CANopenNode/CO_NMT_Heartbeat.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/CANopenNode" 
	@${RM} ${OBJECTDIR}/CANopenNode/CO_NMT_Heartbeat.o.d 
	@${RM} ${OBJECTDIR}/CANopenNode/CO_NMT_Heartbeat.o 
	@${FIXDEPS} "${OBJECTDIR}/CANopenNode/CO_NMT_Heartbeat.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/CANopenNode/CO_NMT_Heartbeat.o.d" -o ${OBJECTDIR}/CANopenNode/CO_NMT_Heartbeat.o CANopenNode/CO_NMT_Heartbeat.c     
	
${OBJECTDIR}/CANopenNode/CO_OD.o: CANopenNode/CO_OD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/CANopenNode" 
	@${RM} ${OBJECTDIR}/CANopenNode/CO_OD.o.d 
	@${RM} ${OBJECTDIR}/CANopenNode/CO_OD.o 
	@${FIXDEPS} "${OBJECTDIR}/CANopenNode/CO_OD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/CANopenNode/CO_OD.o.d" -o ${OBJECTDIR}/CANopenNode/CO_OD.o CANopenNode/CO_OD.c     
	
${OBJECTDIR}/CANopenNode/CO_PDO.o: CANopenNode/CO_PDO.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/CANopenNode" 
	@${RM} ${OBJECTDIR}/CANopenNode/CO_PDO.o.d 
	@${RM} ${OBJECTDIR}/CANopenNode/CO_PDO.o 
	@${FIXDEPS} "${OBJECTDIR}/CANopenNode/CO_PDO.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/CANopenNode/CO_PDO.o.d" -o ${OBJECTDIR}/CANopenNode/CO_PDO.o CANopenNode/CO_PDO.c     
	
${OBJECTDIR}/CANopenNode/CO_SDO.o: CANopenNode/CO_SDO.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/CANopenNode" 
	@${RM} ${OBJECTDIR}/CANopenNode/CO_SDO.o.d 
	@${RM} ${OBJECTDIR}/CANopenNode/CO_SDO.o 
	@${FIXDEPS} "${OBJECTDIR}/CANopenNode/CO_SDO.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/CANopenNode/CO_SDO.o.d" -o ${OBJECTDIR}/CANopenNode/CO_SDO.o CANopenNode/CO_SDO.c     
	
${OBJECTDIR}/CANopenNode/CO_SDOmaster.o: CANopenNode/CO_SDOmaster.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/CANopenNode" 
	@${RM} ${OBJECTDIR}/CANopenNode/CO_SDOmaster.o.d 
	@${RM} ${OBJECTDIR}/CANopenNode/CO_SDOmaster.o 
	@${FIXDEPS} "${OBJECTDIR}/CANopenNode/CO_SDOmaster.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/CANopenNode/CO_SDOmaster.o.d" -o ${OBJECTDIR}/CANopenNode/CO_SDOmaster.o CANopenNode/CO_SDOmaster.c     
	
${OBJECTDIR}/CANopenNode/CO_SYNC.o: CANopenNode/CO_SYNC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/CANopenNode" 
	@${RM} ${OBJECTDIR}/CANopenNode/CO_SYNC.o.d 
	@${RM} ${OBJECTDIR}/CANopenNode/CO_SYNC.o 
	@${FIXDEPS} "${OBJECTDIR}/CANopenNode/CO_SYNC.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/CANopenNode/CO_SYNC.o.d" -o ${OBJECTDIR}/CANopenNode/CO_SYNC.o CANopenNode/CO_SYNC.c     
	
${OBJECTDIR}/CANopenNode/crc16-ccitt.o: CANopenNode/crc16-ccitt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/CANopenNode" 
	@${RM} ${OBJECTDIR}/CANopenNode/crc16-ccitt.o.d 
	@${RM} ${OBJECTDIR}/CANopenNode/crc16-ccitt.o 
	@${FIXDEPS} "${OBJECTDIR}/CANopenNode/crc16-ccitt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/CANopenNode/crc16-ccitt.o.d" -o ${OBJECTDIR}/CANopenNode/crc16-ccitt.o CANopenNode/crc16-ccitt.c     
	
${OBJECTDIR}/CANopenNode/eeprom.o: CANopenNode/eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/CANopenNode" 
	@${RM} ${OBJECTDIR}/CANopenNode/eeprom.o.d 
	@${RM} ${OBJECTDIR}/CANopenNode/eeprom.o 
	@${FIXDEPS} "${OBJECTDIR}/CANopenNode/eeprom.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/CANopenNode/eeprom.o.d" -o ${OBJECTDIR}/CANopenNode/eeprom.o CANopenNode/eeprom.c     
	
${OBJECTDIR}/configuration_bits.o: configuration_bits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/configuration_bits.o.d 
	@${RM} ${OBJECTDIR}/configuration_bits.o 
	@${FIXDEPS} "${OBJECTDIR}/configuration_bits.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/configuration_bits.o.d" -o ${OBJECTDIR}/configuration_bits.o configuration_bits.c     
	
${OBJECTDIR}/exceptions.o: exceptions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/exceptions.o.d 
	@${RM} ${OBJECTDIR}/exceptions.o 
	@${FIXDEPS} "${OBJECTDIR}/exceptions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/exceptions.o.d" -o ${OBJECTDIR}/exceptions.o exceptions.c     
	
${OBJECTDIR}/interrupts.o: interrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/interrupts.o.d 
	@${RM} ${OBJECTDIR}/interrupts.o 
	@${FIXDEPS} "${OBJECTDIR}/interrupts.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/interrupts.o.d" -o ${OBJECTDIR}/interrupts.o interrupts.c     
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c     
	
${OBJECTDIR}/system.o: system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/system.o.d 
	@${RM} ${OBJECTDIR}/system.o 
	@${FIXDEPS} "${OBJECTDIR}/system.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/system.o.d" -o ${OBJECTDIR}/system.o system.c     
	
${OBJECTDIR}/user.o: user.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/user.o.d 
	@${RM} ${OBJECTDIR}/user.o 
	@${FIXDEPS} "${OBJECTDIR}/user.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"CANopenNode/" -I"C_Drivers" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/user.o.d" -o ${OBJECTDIR}/user.o user.c     
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/BadgerLoopPod.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/BadgerLoopPod.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}              -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,--defsym=_min_heap_size=5000,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/BadgerLoopPod.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/BadgerLoopPod.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}            -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=5000,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/BadgerLoopPod.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/PIC32MX795F512L
	${RM} -r dist/PIC32MX795F512L

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
