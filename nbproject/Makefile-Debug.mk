#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/Core/GeneralState.o \
	${OBJECTDIR}/src/Core/Threads/MotionThread.o \
	${OBJECTDIR}/src/Core/Threads/NetworkThread.o \
	${OBJECTDIR}/src/Network/AcceptClientCallback.o \
	${OBJECTDIR}/src/Network/BaseNetworkServer.o \
	${OBJECTDIR}/src/Network/BaseServerCallback.o \
	${OBJECTDIR}/src/Network/ClientReadCallback.o \
	${OBJECTDIR}/src/Network/DisconnectClientCallback.o \
	${OBJECTDIR}/src/Network/TcpNetworkServer.o \
	${OBJECTDIR}/src/main.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/src_test/Network/TcpNetworkServerTests.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-Wall -pthread -lwiringPi
CXXFLAGS=-Wall -pthread -lwiringPi

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lwiringPi

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/neoemb

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/neoemb: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/neoemb ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/Core/GeneralState.o: src/Core/GeneralState.cpp
	${MKDIR} -p ${OBJECTDIR}/src/Core
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -Isrc -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Core/GeneralState.o src/Core/GeneralState.cpp

${OBJECTDIR}/src/Core/Threads/MotionThread.o: src/Core/Threads/MotionThread.cpp
	${MKDIR} -p ${OBJECTDIR}/src/Core/Threads
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -Isrc -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Core/Threads/MotionThread.o src/Core/Threads/MotionThread.cpp

${OBJECTDIR}/src/Core/Threads/NetworkThread.o: src/Core/Threads/NetworkThread.cpp
	${MKDIR} -p ${OBJECTDIR}/src/Core/Threads
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -Isrc -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Core/Threads/NetworkThread.o src/Core/Threads/NetworkThread.cpp

${OBJECTDIR}/src/Network/AcceptClientCallback.o: src/Network/AcceptClientCallback.cpp
	${MKDIR} -p ${OBJECTDIR}/src/Network
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -Isrc -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Network/AcceptClientCallback.o src/Network/AcceptClientCallback.cpp

${OBJECTDIR}/src/Network/BaseNetworkServer.o: src/Network/BaseNetworkServer.cpp
	${MKDIR} -p ${OBJECTDIR}/src/Network
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -Isrc -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Network/BaseNetworkServer.o src/Network/BaseNetworkServer.cpp

${OBJECTDIR}/src/Network/BaseServerCallback.o: src/Network/BaseServerCallback.cpp
	${MKDIR} -p ${OBJECTDIR}/src/Network
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -Isrc -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Network/BaseServerCallback.o src/Network/BaseServerCallback.cpp

${OBJECTDIR}/src/Network/ClientReadCallback.o: src/Network/ClientReadCallback.cpp
	${MKDIR} -p ${OBJECTDIR}/src/Network
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -Isrc -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Network/ClientReadCallback.o src/Network/ClientReadCallback.cpp

${OBJECTDIR}/src/Network/DisconnectClientCallback.o: src/Network/DisconnectClientCallback.cpp
	${MKDIR} -p ${OBJECTDIR}/src/Network
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -Isrc -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Network/DisconnectClientCallback.o src/Network/DisconnectClientCallback.cpp

${OBJECTDIR}/src/Network/TcpNetworkServer.o: src/Network/TcpNetworkServer.cpp
	${MKDIR} -p ${OBJECTDIR}/src/Network
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -Isrc -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Network/TcpNetworkServer.o src/Network/TcpNetworkServer.cpp

${OBJECTDIR}/src/main.o: src/main.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -Isrc -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f1: ${TESTDIR}/src_test/Network/TcpNetworkServerTests.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS}   


${TESTDIR}/src_test/Network/TcpNetworkServerTests.o: src_test/Network/TcpNetworkServerTests.cpp 
	${MKDIR} -p ${TESTDIR}/src_test/Network
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -Isrc -Isrc -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${TESTDIR}/src_test/Network/TcpNetworkServerTests.o src_test/Network/TcpNetworkServerTests.cpp


${OBJECTDIR}/src/Core/GeneralState_nomain.o: ${OBJECTDIR}/src/Core/GeneralState.o src/Core/GeneralState.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Core
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Core/GeneralState.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Werror -Isrc -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Core/GeneralState_nomain.o src/Core/GeneralState.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Core/GeneralState.o ${OBJECTDIR}/src/Core/GeneralState_nomain.o;\
	fi

${OBJECTDIR}/src/Core/Threads/MotionThread_nomain.o: ${OBJECTDIR}/src/Core/Threads/MotionThread.o src/Core/Threads/MotionThread.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Core/Threads
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Core/Threads/MotionThread.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Werror -Isrc -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Core/Threads/MotionThread_nomain.o src/Core/Threads/MotionThread.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Core/Threads/MotionThread.o ${OBJECTDIR}/src/Core/Threads/MotionThread_nomain.o;\
	fi

${OBJECTDIR}/src/Core/Threads/NetworkThread_nomain.o: ${OBJECTDIR}/src/Core/Threads/NetworkThread.o src/Core/Threads/NetworkThread.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Core/Threads
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Core/Threads/NetworkThread.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Werror -Isrc -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Core/Threads/NetworkThread_nomain.o src/Core/Threads/NetworkThread.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Core/Threads/NetworkThread.o ${OBJECTDIR}/src/Core/Threads/NetworkThread_nomain.o;\
	fi

${OBJECTDIR}/src/Network/AcceptClientCallback_nomain.o: ${OBJECTDIR}/src/Network/AcceptClientCallback.o src/Network/AcceptClientCallback.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Network
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Network/AcceptClientCallback.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Werror -Isrc -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Network/AcceptClientCallback_nomain.o src/Network/AcceptClientCallback.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Network/AcceptClientCallback.o ${OBJECTDIR}/src/Network/AcceptClientCallback_nomain.o;\
	fi

${OBJECTDIR}/src/Network/BaseNetworkServer_nomain.o: ${OBJECTDIR}/src/Network/BaseNetworkServer.o src/Network/BaseNetworkServer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Network
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Network/BaseNetworkServer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Werror -Isrc -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Network/BaseNetworkServer_nomain.o src/Network/BaseNetworkServer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Network/BaseNetworkServer.o ${OBJECTDIR}/src/Network/BaseNetworkServer_nomain.o;\
	fi

${OBJECTDIR}/src/Network/BaseServerCallback_nomain.o: ${OBJECTDIR}/src/Network/BaseServerCallback.o src/Network/BaseServerCallback.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Network
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Network/BaseServerCallback.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Werror -Isrc -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Network/BaseServerCallback_nomain.o src/Network/BaseServerCallback.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Network/BaseServerCallback.o ${OBJECTDIR}/src/Network/BaseServerCallback_nomain.o;\
	fi

${OBJECTDIR}/src/Network/ClientReadCallback_nomain.o: ${OBJECTDIR}/src/Network/ClientReadCallback.o src/Network/ClientReadCallback.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Network
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Network/ClientReadCallback.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Werror -Isrc -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Network/ClientReadCallback_nomain.o src/Network/ClientReadCallback.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Network/ClientReadCallback.o ${OBJECTDIR}/src/Network/ClientReadCallback_nomain.o;\
	fi

${OBJECTDIR}/src/Network/DisconnectClientCallback_nomain.o: ${OBJECTDIR}/src/Network/DisconnectClientCallback.o src/Network/DisconnectClientCallback.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Network
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Network/DisconnectClientCallback.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Werror -Isrc -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Network/DisconnectClientCallback_nomain.o src/Network/DisconnectClientCallback.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Network/DisconnectClientCallback.o ${OBJECTDIR}/src/Network/DisconnectClientCallback_nomain.o;\
	fi

${OBJECTDIR}/src/Network/TcpNetworkServer_nomain.o: ${OBJECTDIR}/src/Network/TcpNetworkServer.o src/Network/TcpNetworkServer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Network
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Network/TcpNetworkServer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Werror -Isrc -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Network/TcpNetworkServer_nomain.o src/Network/TcpNetworkServer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Network/TcpNetworkServer.o ${OBJECTDIR}/src/Network/TcpNetworkServer_nomain.o;\
	fi

${OBJECTDIR}/src/main_nomain.o: ${OBJECTDIR}/src/main.o src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Werror -Isrc -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main_nomain.o src/main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/main.o ${OBJECTDIR}/src/main_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
