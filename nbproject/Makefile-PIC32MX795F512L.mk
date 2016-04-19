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
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=PIC32MX795F512L
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/BadgerLoopPod.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/BadgerLoopPod.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=src/interrupts.c src/exceptions.c src/application.c lib/CANopenNode/CANopen.c lib/CANopenNode/CO_driver.c lib/CANopenNode/CO_Emergency.c lib/CANopenNode/CO_HBconsumer.c lib/CANopenNode/CO_NMT_Heartbeat.c lib/CANopenNode/CO_OD.c lib/CANopenNode/CO_PDO.c lib/CANopenNode/CO_SDO.c lib/CANopenNode/CO_SDOmaster.c lib/CANopenNode/CO_SYNC.c lib/CANopenNode/crc16-ccitt.c lib/CANopenNode/eeprom.c src/system.c src/main.c src/adc.c src/CAN.c src/USBDebug.c src/I2C.c src/MPU9250.c src/VL6180X.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/src/interrupts.o ${OBJECTDIR}/src/exceptions.o ${OBJECTDIR}/src/application.o ${OBJECTDIR}/lib/CANopenNode/CANopen.o ${OBJECTDIR}/lib/CANopenNode/CO_driver.o ${OBJECTDIR}/lib/CANopenNode/CO_Emergency.o ${OBJECTDIR}/lib/CANopenNode/CO_HBconsumer.o ${OBJECTDIR}/lib/CANopenNode/CO_NMT_Heartbeat.o ${OBJECTDIR}/lib/CANopenNode/CO_OD.o ${OBJECTDIR}/lib/CANopenNode/CO_PDO.o ${OBJECTDIR}/lib/CANopenNode/CO_SDO.o ${OBJECTDIR}/lib/CANopenNode/CO_SDOmaster.o ${OBJECTDIR}/lib/CANopenNode/CO_SYNC.o ${OBJECTDIR}/lib/CANopenNode/crc16-ccitt.o ${OBJECTDIR}/lib/CANopenNode/eeprom.o ${OBJECTDIR}/src/system.o ${OBJECTDIR}/src/main.o ${OBJECTDIR}/src/adc.o ${OBJECTDIR}/src/CAN.o ${OBJECTDIR}/src/USBDebug.o ${OBJECTDIR}/src/I2C.o ${OBJECTDIR}/src/MPU9250.o ${OBJECTDIR}/src/VL6180X.o
POSSIBLE_DEPFILES=${OBJECTDIR}/src/interrupts.o.d ${OBJECTDIR}/src/exceptions.o.d ${OBJECTDIR}/src/application.o.d ${OBJECTDIR}/lib/CANopenNode/CANopen.o.d ${OBJECTDIR}/lib/CANopenNode/CO_driver.o.d ${OBJECTDIR}/lib/CANopenNode/CO_Emergency.o.d ${OBJECTDIR}/lib/CANopenNode/CO_HBconsumer.o.d ${OBJECTDIR}/lib/CANopenNode/CO_NMT_Heartbeat.o.d ${OBJECTDIR}/lib/CANopenNode/CO_OD.o.d ${OBJECTDIR}/lib/CANopenNode/CO_PDO.o.d ${OBJECTDIR}/lib/CANopenNode/CO_SDO.o.d ${OBJECTDIR}/lib/CANopenNode/CO_SDOmaster.o.d ${OBJECTDIR}/lib/CANopenNode/CO_SYNC.o.d ${OBJECTDIR}/lib/CANopenNode/crc16-ccitt.o.d ${OBJECTDIR}/lib/CANopenNode/eeprom.o.d ${OBJECTDIR}/src/system.o.d ${OBJECTDIR}/src/main.o.d ${OBJECTDIR}/src/adc.o.d ${OBJECTDIR}/src/CAN.o.d ${OBJECTDIR}/src/USBDebug.o.d ${OBJECTDIR}/src/I2C.o.d ${OBJECTDIR}/src/MPU9250.o.d ${OBJECTDIR}/src/VL6180X.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/src/interrupts.o ${OBJECTDIR}/src/exceptions.o ${OBJECTDIR}/src/application.o ${OBJECTDIR}/lib/CANopenNode/CANopen.o ${OBJECTDIR}/lib/CANopenNode/CO_driver.o ${OBJECTDIR}/lib/CANopenNode/CO_Emergency.o ${OBJECTDIR}/lib/CANopenNode/CO_HBconsumer.o ${OBJECTDIR}/lib/CANopenNode/CO_NMT_Heartbeat.o ${OBJECTDIR}/lib/CANopenNode/CO_OD.o ${OBJECTDIR}/lib/CANopenNode/CO_PDO.o ${OBJECTDIR}/lib/CANopenNode/CO_SDO.o ${OBJECTDIR}/lib/CANopenNode/CO_SDOmaster.o ${OBJECTDIR}/lib/CANopenNode/CO_SYNC.o ${OBJECTDIR}/lib/CANopenNode/crc16-ccitt.o ${OBJECTDIR}/lib/CANopenNode/eeprom.o ${OBJECTDIR}/src/system.o ${OBJECTDIR}/src/main.o ${OBJECTDIR}/src/adc.o ${OBJECTDIR}/src/CAN.o ${OBJECTDIR}/src/USBDebug.o ${OBJECTDIR}/src/I2C.o ${OBJECTDIR}/src/MPU9250.o ${OBJECTDIR}/src/VL6180X.o

# Source Files
SOURCEFILES=src/interrupts.c src/exceptions.c src/application.c lib/CANopenNode/CANopen.c lib/CANopenNode/CO_driver.c lib/CANopenNode/CO_Emergency.c lib/CANopenNode/CO_HBconsumer.c lib/CANopenNode/CO_NMT_Heartbeat.c lib/CANopenNode/CO_OD.c lib/CANopenNode/CO_PDO.c lib/CANopenNode/CO_SDO.c lib/CANopenNode/CO_SDOmaster.c lib/CANopenNode/CO_SYNC.c lib/CANopenNode/crc16-ccitt.c lib/CANopenNode/eeprom.c src/system.c src/main.c src/adc.c src/CAN.c src/USBDebug.c src/I2C.c src/MPU9250.c src/VL6180X.c


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
	${MAKE}  -f nbproject/Makefile-PIC32MX795F512L.mk dist/${CND_CONF}/${IMAGE_TYPE}/BadgerLoopPod.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

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
${OBJECTDIR}/src/interrupts.o: src/interrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/interrupts.o.d 
	@${RM} ${OBJECTDIR}/src/interrupts.o 
	@${FIXDEPS} "${OBJECTDIR}/src/interrupts.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/src/interrupts.o.d" -o ${OBJECTDIR}/src/interrupts.o src/interrupts.c     
	
${OBJECTDIR}/src/exceptions.o: src/exceptions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/exceptions.o.d 
	@${RM} ${OBJECTDIR}/src/exceptions.o 
	@${FIXDEPS} "${OBJECTDIR}/src/exceptions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/src/exceptions.o.d" -o ${OBJECTDIR}/src/exceptions.o src/exceptions.c     
	
${OBJECTDIR}/src/application.o: src/application.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/application.o.d 
	@${RM} ${OBJECTDIR}/src/application.o 
	@${FIXDEPS} "${OBJECTDIR}/src/application.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/src/application.o.d" -o ${OBJECTDIR}/src/application.o src/application.c     
	
${OBJECTDIR}/lib/CANopenNode/CANopen.o: lib/CANopenNode/CANopen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/CANopenNode" 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CANopen.o.d 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CANopen.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/CANopenNode/CANopen.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/lib/CANopenNode/CANopen.o.d" -o ${OBJECTDIR}/lib/CANopenNode/CANopen.o lib/CANopenNode/CANopen.c     
	
${OBJECTDIR}/lib/CANopenNode/CO_driver.o: lib/CANopenNode/CO_driver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/CANopenNode" 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CO_driver.o.d 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CO_driver.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/CANopenNode/CO_driver.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/lib/CANopenNode/CO_driver.o.d" -o ${OBJECTDIR}/lib/CANopenNode/CO_driver.o lib/CANopenNode/CO_driver.c     
	
${OBJECTDIR}/lib/CANopenNode/CO_Emergency.o: lib/CANopenNode/CO_Emergency.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/CANopenNode" 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CO_Emergency.o.d 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CO_Emergency.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/CANopenNode/CO_Emergency.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/lib/CANopenNode/CO_Emergency.o.d" -o ${OBJECTDIR}/lib/CANopenNode/CO_Emergency.o lib/CANopenNode/CO_Emergency.c     
	
${OBJECTDIR}/lib/CANopenNode/CO_HBconsumer.o: lib/CANopenNode/CO_HBconsumer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/CANopenNode" 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CO_HBconsumer.o.d 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CO_HBconsumer.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/CANopenNode/CO_HBconsumer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/lib/CANopenNode/CO_HBconsumer.o.d" -o ${OBJECTDIR}/lib/CANopenNode/CO_HBconsumer.o lib/CANopenNode/CO_HBconsumer.c     
	
${OBJECTDIR}/lib/CANopenNode/CO_NMT_Heartbeat.o: lib/CANopenNode/CO_NMT_Heartbeat.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/CANopenNode" 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CO_NMT_Heartbeat.o.d 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CO_NMT_Heartbeat.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/CANopenNode/CO_NMT_Heartbeat.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/lib/CANopenNode/CO_NMT_Heartbeat.o.d" -o ${OBJECTDIR}/lib/CANopenNode/CO_NMT_Heartbeat.o lib/CANopenNode/CO_NMT_Heartbeat.c     
	
${OBJECTDIR}/lib/CANopenNode/CO_OD.o: lib/CANopenNode/CO_OD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/CANopenNode" 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CO_OD.o.d 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CO_OD.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/CANopenNode/CO_OD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/lib/CANopenNode/CO_OD.o.d" -o ${OBJECTDIR}/lib/CANopenNode/CO_OD.o lib/CANopenNode/CO_OD.c     
	
${OBJECTDIR}/lib/CANopenNode/CO_PDO.o: lib/CANopenNode/CO_PDO.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/CANopenNode" 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CO_PDO.o.d 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CO_PDO.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/CANopenNode/CO_PDO.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/lib/CANopenNode/CO_PDO.o.d" -o ${OBJECTDIR}/lib/CANopenNode/CO_PDO.o lib/CANopenNode/CO_PDO.c     
	
${OBJECTDIR}/lib/CANopenNode/CO_SDO.o: lib/CANopenNode/CO_SDO.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/CANopenNode" 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CO_SDO.o.d 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CO_SDO.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/CANopenNode/CO_SDO.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/lib/CANopenNode/CO_SDO.o.d" -o ${OBJECTDIR}/lib/CANopenNode/CO_SDO.o lib/CANopenNode/CO_SDO.c     
	
${OBJECTDIR}/lib/CANopenNode/CO_SDOmaster.o: lib/CANopenNode/CO_SDOmaster.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/CANopenNode" 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CO_SDOmaster.o.d 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CO_SDOmaster.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/CANopenNode/CO_SDOmaster.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/lib/CANopenNode/CO_SDOmaster.o.d" -o ${OBJECTDIR}/lib/CANopenNode/CO_SDOmaster.o lib/CANopenNode/CO_SDOmaster.c     
	
${OBJECTDIR}/lib/CANopenNode/CO_SYNC.o: lib/CANopenNode/CO_SYNC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/CANopenNode" 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CO_SYNC.o.d 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CO_SYNC.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/CANopenNode/CO_SYNC.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/lib/CANopenNode/CO_SYNC.o.d" -o ${OBJECTDIR}/lib/CANopenNode/CO_SYNC.o lib/CANopenNode/CO_SYNC.c     
	
${OBJECTDIR}/lib/CANopenNode/crc16-ccitt.o: lib/CANopenNode/crc16-ccitt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/CANopenNode" 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/crc16-ccitt.o.d 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/crc16-ccitt.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/CANopenNode/crc16-ccitt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/lib/CANopenNode/crc16-ccitt.o.d" -o ${OBJECTDIR}/lib/CANopenNode/crc16-ccitt.o lib/CANopenNode/crc16-ccitt.c     
	
${OBJECTDIR}/lib/CANopenNode/eeprom.o: lib/CANopenNode/eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/CANopenNode" 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/eeprom.o.d 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/eeprom.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/CANopenNode/eeprom.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/lib/CANopenNode/eeprom.o.d" -o ${OBJECTDIR}/lib/CANopenNode/eeprom.o lib/CANopenNode/eeprom.c     
	
${OBJECTDIR}/src/system.o: src/system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/system.o.d 
	@${RM} ${OBJECTDIR}/src/system.o 
	@${FIXDEPS} "${OBJECTDIR}/src/system.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/src/system.o.d" -o ${OBJECTDIR}/src/system.o src/system.c     
	
${OBJECTDIR}/src/main.o: src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	@${FIXDEPS} "${OBJECTDIR}/src/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/src/main.o.d" -o ${OBJECTDIR}/src/main.o src/main.c     
	
${OBJECTDIR}/src/adc.o: src/adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/adc.o.d 
	@${RM} ${OBJECTDIR}/src/adc.o 
	@${FIXDEPS} "${OBJECTDIR}/src/adc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/src/adc.o.d" -o ${OBJECTDIR}/src/adc.o src/adc.c     
	
${OBJECTDIR}/src/CAN.o: src/CAN.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/CAN.o.d 
	@${RM} ${OBJECTDIR}/src/CAN.o 
	@${FIXDEPS} "${OBJECTDIR}/src/CAN.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/src/CAN.o.d" -o ${OBJECTDIR}/src/CAN.o src/CAN.c     
	
${OBJECTDIR}/src/USBDebug.o: src/USBDebug.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/USBDebug.o.d 
	@${RM} ${OBJECTDIR}/src/USBDebug.o 
	@${FIXDEPS} "${OBJECTDIR}/src/USBDebug.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/src/USBDebug.o.d" -o ${OBJECTDIR}/src/USBDebug.o src/USBDebug.c     
	
${OBJECTDIR}/src/I2C.o: src/I2C.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/I2C.o.d 
	@${RM} ${OBJECTDIR}/src/I2C.o 
	@${FIXDEPS} "${OBJECTDIR}/src/I2C.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/src/I2C.o.d" -o ${OBJECTDIR}/src/I2C.o src/I2C.c     
	
${OBJECTDIR}/src/MPU9250.o: src/MPU9250.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/MPU9250.o.d 
	@${RM} ${OBJECTDIR}/src/MPU9250.o 
	@${FIXDEPS} "${OBJECTDIR}/src/MPU9250.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/src/MPU9250.o.d" -o ${OBJECTDIR}/src/MPU9250.o src/MPU9250.c     
	
${OBJECTDIR}/src/VL6180X.o: src/VL6180X.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/VL6180X.o.d 
	@${RM} ${OBJECTDIR}/src/VL6180X.o 
	@${FIXDEPS} "${OBJECTDIR}/src/VL6180X.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/src/VL6180X.o.d" -o ${OBJECTDIR}/src/VL6180X.o src/VL6180X.c     
	
else
${OBJECTDIR}/src/interrupts.o: src/interrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/interrupts.o.d 
	@${RM} ${OBJECTDIR}/src/interrupts.o 
	@${FIXDEPS} "${OBJECTDIR}/src/interrupts.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/src/interrupts.o.d" -o ${OBJECTDIR}/src/interrupts.o src/interrupts.c     
	
${OBJECTDIR}/src/exceptions.o: src/exceptions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/exceptions.o.d 
	@${RM} ${OBJECTDIR}/src/exceptions.o 
	@${FIXDEPS} "${OBJECTDIR}/src/exceptions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/src/exceptions.o.d" -o ${OBJECTDIR}/src/exceptions.o src/exceptions.c     
	
${OBJECTDIR}/src/application.o: src/application.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/application.o.d 
	@${RM} ${OBJECTDIR}/src/application.o 
	@${FIXDEPS} "${OBJECTDIR}/src/application.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/src/application.o.d" -o ${OBJECTDIR}/src/application.o src/application.c     
	
${OBJECTDIR}/lib/CANopenNode/CANopen.o: lib/CANopenNode/CANopen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/CANopenNode" 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CANopen.o.d 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CANopen.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/CANopenNode/CANopen.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/lib/CANopenNode/CANopen.o.d" -o ${OBJECTDIR}/lib/CANopenNode/CANopen.o lib/CANopenNode/CANopen.c     
	
${OBJECTDIR}/lib/CANopenNode/CO_driver.o: lib/CANopenNode/CO_driver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/CANopenNode" 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CO_driver.o.d 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CO_driver.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/CANopenNode/CO_driver.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/lib/CANopenNode/CO_driver.o.d" -o ${OBJECTDIR}/lib/CANopenNode/CO_driver.o lib/CANopenNode/CO_driver.c     
	
${OBJECTDIR}/lib/CANopenNode/CO_Emergency.o: lib/CANopenNode/CO_Emergency.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/CANopenNode" 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CO_Emergency.o.d 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CO_Emergency.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/CANopenNode/CO_Emergency.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/lib/CANopenNode/CO_Emergency.o.d" -o ${OBJECTDIR}/lib/CANopenNode/CO_Emergency.o lib/CANopenNode/CO_Emergency.c     
	
${OBJECTDIR}/lib/CANopenNode/CO_HBconsumer.o: lib/CANopenNode/CO_HBconsumer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/CANopenNode" 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CO_HBconsumer.o.d 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CO_HBconsumer.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/CANopenNode/CO_HBconsumer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/lib/CANopenNode/CO_HBconsumer.o.d" -o ${OBJECTDIR}/lib/CANopenNode/CO_HBconsumer.o lib/CANopenNode/CO_HBconsumer.c     
	
${OBJECTDIR}/lib/CANopenNode/CO_NMT_Heartbeat.o: lib/CANopenNode/CO_NMT_Heartbeat.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/CANopenNode" 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CO_NMT_Heartbeat.o.d 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CO_NMT_Heartbeat.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/CANopenNode/CO_NMT_Heartbeat.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/lib/CANopenNode/CO_NMT_Heartbeat.o.d" -o ${OBJECTDIR}/lib/CANopenNode/CO_NMT_Heartbeat.o lib/CANopenNode/CO_NMT_Heartbeat.c     
	
${OBJECTDIR}/lib/CANopenNode/CO_OD.o: lib/CANopenNode/CO_OD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/CANopenNode" 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CO_OD.o.d 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CO_OD.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/CANopenNode/CO_OD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/lib/CANopenNode/CO_OD.o.d" -o ${OBJECTDIR}/lib/CANopenNode/CO_OD.o lib/CANopenNode/CO_OD.c     
	
${OBJECTDIR}/lib/CANopenNode/CO_PDO.o: lib/CANopenNode/CO_PDO.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/CANopenNode" 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CO_PDO.o.d 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CO_PDO.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/CANopenNode/CO_PDO.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/lib/CANopenNode/CO_PDO.o.d" -o ${OBJECTDIR}/lib/CANopenNode/CO_PDO.o lib/CANopenNode/CO_PDO.c     
	
${OBJECTDIR}/lib/CANopenNode/CO_SDO.o: lib/CANopenNode/CO_SDO.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/CANopenNode" 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CO_SDO.o.d 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CO_SDO.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/CANopenNode/CO_SDO.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/lib/CANopenNode/CO_SDO.o.d" -o ${OBJECTDIR}/lib/CANopenNode/CO_SDO.o lib/CANopenNode/CO_SDO.c     
	
${OBJECTDIR}/lib/CANopenNode/CO_SDOmaster.o: lib/CANopenNode/CO_SDOmaster.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/CANopenNode" 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CO_SDOmaster.o.d 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CO_SDOmaster.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/CANopenNode/CO_SDOmaster.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/lib/CANopenNode/CO_SDOmaster.o.d" -o ${OBJECTDIR}/lib/CANopenNode/CO_SDOmaster.o lib/CANopenNode/CO_SDOmaster.c     
	
${OBJECTDIR}/lib/CANopenNode/CO_SYNC.o: lib/CANopenNode/CO_SYNC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/CANopenNode" 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CO_SYNC.o.d 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/CO_SYNC.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/CANopenNode/CO_SYNC.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/lib/CANopenNode/CO_SYNC.o.d" -o ${OBJECTDIR}/lib/CANopenNode/CO_SYNC.o lib/CANopenNode/CO_SYNC.c     
	
${OBJECTDIR}/lib/CANopenNode/crc16-ccitt.o: lib/CANopenNode/crc16-ccitt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/CANopenNode" 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/crc16-ccitt.o.d 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/crc16-ccitt.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/CANopenNode/crc16-ccitt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/lib/CANopenNode/crc16-ccitt.o.d" -o ${OBJECTDIR}/lib/CANopenNode/crc16-ccitt.o lib/CANopenNode/crc16-ccitt.c     
	
${OBJECTDIR}/lib/CANopenNode/eeprom.o: lib/CANopenNode/eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/CANopenNode" 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/eeprom.o.d 
	@${RM} ${OBJECTDIR}/lib/CANopenNode/eeprom.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/CANopenNode/eeprom.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/lib/CANopenNode/eeprom.o.d" -o ${OBJECTDIR}/lib/CANopenNode/eeprom.o lib/CANopenNode/eeprom.c     
	
${OBJECTDIR}/src/system.o: src/system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/system.o.d 
	@${RM} ${OBJECTDIR}/src/system.o 
	@${FIXDEPS} "${OBJECTDIR}/src/system.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/src/system.o.d" -o ${OBJECTDIR}/src/system.o src/system.c     
	
${OBJECTDIR}/src/main.o: src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	@${FIXDEPS} "${OBJECTDIR}/src/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/src/main.o.d" -o ${OBJECTDIR}/src/main.o src/main.c     
	
${OBJECTDIR}/src/adc.o: src/adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/adc.o.d 
	@${RM} ${OBJECTDIR}/src/adc.o 
	@${FIXDEPS} "${OBJECTDIR}/src/adc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/src/adc.o.d" -o ${OBJECTDIR}/src/adc.o src/adc.c     
	
${OBJECTDIR}/src/CAN.o: src/CAN.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/CAN.o.d 
	@${RM} ${OBJECTDIR}/src/CAN.o 
	@${FIXDEPS} "${OBJECTDIR}/src/CAN.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/src/CAN.o.d" -o ${OBJECTDIR}/src/CAN.o src/CAN.c     
	
${OBJECTDIR}/src/USBDebug.o: src/USBDebug.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/USBDebug.o.d 
	@${RM} ${OBJECTDIR}/src/USBDebug.o 
	@${FIXDEPS} "${OBJECTDIR}/src/USBDebug.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/src/USBDebug.o.d" -o ${OBJECTDIR}/src/USBDebug.o src/USBDebug.c     
	
${OBJECTDIR}/src/I2C.o: src/I2C.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/I2C.o.d 
	@${RM} ${OBJECTDIR}/src/I2C.o 
	@${FIXDEPS} "${OBJECTDIR}/src/I2C.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/src/I2C.o.d" -o ${OBJECTDIR}/src/I2C.o src/I2C.c     
	
${OBJECTDIR}/src/MPU9250.o: src/MPU9250.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/MPU9250.o.d 
	@${RM} ${OBJECTDIR}/src/MPU9250.o 
	@${FIXDEPS} "${OBJECTDIR}/src/MPU9250.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/src/MPU9250.o.d" -o ${OBJECTDIR}/src/MPU9250.o src/MPU9250.c     
	
${OBJECTDIR}/src/VL6180X.o: src/VL6180X.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/VL6180X.o.d 
	@${RM} ${OBJECTDIR}/src/VL6180X.o 
	@${FIXDEPS} "${OBJECTDIR}/src/VL6180X.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"include/" -I"lib/CANopenNode/" -mlong-calls -D_SUPPRESS_PLIB_WARNING -MMD -MF "${OBJECTDIR}/src/VL6180X.o.d" -o ${OBJECTDIR}/src/VL6180X.o src/VL6180X.c     
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/BadgerLoopPod.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/BadgerLoopPod.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}              -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,--defsym=_min_heap_size=5000,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/BadgerLoopPod.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/BadgerLoopPod.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}            -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=5000,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	${MP_CC_DIR}/xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/BadgerLoopPod.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
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

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
