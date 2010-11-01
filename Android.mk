# Copyright (C) 2009 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

TARGET_ARCH := arm
TARGET_PLATFORM := android-8
TARGET_ARCH_ABI := armeabi-v7a
TARGET_ABI := android-8-armeabi-v7a

LOCAL_CPP_EXTENSION := cpp
LOCAL_MODULE    := ZKCompiler

ZKCompiler_SOURCE_DIR := $(LOCAL_PATH)
GMP_INCLUDES := $(LOCAL_PATH)/extern/MPIR/android/include
GMP_LIBRARY  := $(LOCAL_PATH)/extern/MPIR/android/lib

ZKCompiler_INCLUDE_DIR := $(LOCAL_PATH)/include



LOCAL_MODULE     := zkcompiler
LOCAL_C_INCLUDES := $(ZKCompiler_INCLUDE_DIR) $(LOCAL_PATH)/extern/Android $(GMP_INCLUDES)
LOCAL_SRC_FILES  := src/bignum/bignum.cpp \
                    src/bignum/bignum_gmp.cpp \
                    src/CodeManagement/ccr/ACCRVisitor.cpp \
                    src/CodeManagement/ccr/ACollectedCodeRepr.cpp \
                    src/CodeManagement/ccr/AConstructorCallCCR.cpp \
                    src/CodeManagement/ccr/ACopyAssignmentCallCCR.cpp \
                    src/CodeManagement/ccr/ACopyConstructorCallCCR.cpp \
                    src/CodeManagement/ccr/ADestructorCallCCR.cpp \
                    src/CodeManagement/ccr/AExecutableCCR.cpp \
                    src/CodeManagement/ccr/AFunctionCallCCR.cpp \
                    src/CodeManagement/ccr/AInstructionCallCCR.cpp \
                    src/CodeManagement/ccr/AOperatorCallCCR.cpp \
                    src/CodeManagement/ccr/AProcedureCallCCR.cpp \
                    src/CodeManagement/ccr/AVariableCCR.cpp \
                    src/CodeManagement/ccr/AVarSpecialCallCCR.cpp \
                    src/CodeManagement/ccr/impl/CommentCCR.cpp \
                    src/CodeManagement/ccr/impl/ConstructorCallCCR.cpp \
                    src/CodeManagement/ccr/impl/CopyableVariableCCR.cpp \
                    src/CodeManagement/ccr/impl/CopyAssignmentCallCCR.cpp \
                    src/CodeManagement/ccr/impl/CopyConstructorCallCCR.cpp \
                    src/CodeManagement/ccr/impl/DestructorCallCCR.cpp \
                    src/CodeManagement/ccr/impl/FunctionCallCCR.cpp \
                    src/CodeManagement/ccr/impl/IfBranchCallCCR.cpp \
                    src/CodeManagement/ccr/impl/OperatorCallCCR.cpp \
                    src/CodeManagement/ccr/impl/ProcedureCallCCR.cpp \
                    src/CodeManagement/ccr/impl/ProgramCCR.cpp \
                    src/CodeManagement/ccr/impl/ScopeBlockCCR.cpp \
                    src/CodeManagement/ccr/impl/VariableCCR.cpp \
                    src/CodeManagement/ccw/AFunction.cpp \
                    src/CodeManagement/ccw/AInstruction.cpp \
                    src/CodeManagement/ccw/AOperator.cpp \
                    src/CodeManagement/ccw/AProcedure.cpp \
                    src/CodeManagement/ccw/AVariable.cpp \
                    src/CodeManagement/ccw/impl/CopyableVariable.cpp \
                    src/CodeManagement/ccw/impl/Function.cpp \
                    src/CodeManagement/ccw/impl/Operator.cpp \
                    src/CodeManagement/ccw/impl/Procedure.cpp \
                    src/CodeManagement/ccw/impl/Variable.cpp \
                    src/CodeManagement/core/ACodeObserver.cpp \
                    src/CodeManagement/core/impl/CodeCollector.cpp \
                    src/CodeManagement/core/impl/CodeManager.cpp \
                    src/CodeManagement/exec/AExplicitCSrcInstCaster.cpp \
                    src/CodeManagement/exec/AImplicitSrcInstCaster.cpp \
                    src/CodeManagement/exec/ASourceInstanceCaster.cpp \
                    src/CodeManagement/exec/AVariableInstance.cpp \
                    src/CodeManagement/exec/AVariablesTable.cpp \
                    src/CodeManagement/exec/impl/ConstSourceInstance.cpp \
                    src/CodeManagement/exec/impl/CopyableVariableInstance.cpp \
                    src/CodeManagement/exec/impl/ExplicitCSrcInstCaster.cpp \
                    src/CodeManagement/exec/impl/ImplicitSrcInstCaster.cpp \
                    src/CodeManagement/exec/impl/SourceInstance.cpp \
                    src/CodeManagement/exec/impl/VariableInstance.cpp \
                    src/CodeManagement/exec/impl/VariablesTable.cpp \
                    src/CodeManagement/misc/debug/impl/DebugInfo.cpp \
                    src/CodeManagement/misc/debug/impl/Exception.cpp \
                    src/CodeManagement/misc/stream/AStream.cpp \
                    src/CodeManagement/misc/stream/impl/FileStream.cpp \
                    src/CodeManagement/misc/stream/impl/NullStream.cpp \
                    src/CodeManagement/misc/stream/impl/StringStream.cpp \
                    src/CodeManagement/misc/stream/impl/Logger.cpp \
                    src/compiler/ACCRtoCodeCompiler.cpp \
                    src/compiler/AZKProtocol.cpp \
                    src/compiler/CCodeIdentifiers.cpp \
                    src/compiler/ProgramCCRtoCCodeCompiler.cpp \
                    src/compiler/ZKFileToProgramCCRCompiler.cpp \
                    src/compiler/ZKProgramCCRTester.cpp \
                    src/element/element.cpp \
                    src/element/atomic.cpp \
                    src/element/tuple.cpp \
                    src/group/group.cpp \
                    src/group/z.cpp \
                    src/group/z_add_n.cpp \
                    src/group/z_mul_n.cpp \
                    src/hash/hash.cpp \
                    src/hash/sha1.cpp \
                    src/hom/hom.cpp \
                    src/parser/parser.cpp \
                    src/hom/hom.cpp \
                    src/random/random.cpp \
                    src/random/seedLinux.c \
                    src/sigma/and.cpp \
                    src/sigma/gsp.cpp \
                    src/sigma/lipmaa.cpp \
                    src/sigma/or.cpp \
                    src/sigma/phi.cpp \
                    src/sigma/sigma.cpp \
                    src/util/basictypes.cpp \
                    src/util/convert.cpp \
                    src/util/errorhandling.cpp \
                    src/util/foursquares.cpp \
                    src/util/zkprint.cpp \
                    src/zkparser/zkparser.c

include $(BUILD_STATIC_LIBRARY)

LOCAL_MODULE    := test-random
LOCAL_C_INCLUDES := $(ZKCompiler_INCLUDE_DIR) $(GMP_INCLUDES)
LOCAL_STATIC_LIBRARIES := zkcompiler
LOCAL_LDLIBS :=-L$(GMP_LIBRARY) -lmpir
LOCAL_SRC_FILES := src/random/test-random.cpp
include $(BUILD_EXECUTABLE)

LOCAL_MODULE    := test-group-z
LOCAL_C_INCLUDES := $(ZKCompiler_INCLUDE_DIR) $(GMP_INCLUDES)
LOCAL_STATIC_LIBRARIES := zkcompiler
LOCAL_LDLIBS :=-L$(GMP_LIBRARY) -lmpir
LOCAL_SRC_FILES := src/group/test-group-z.cpp
include $(BUILD_EXECUTABLE)

LOCAL_MODULE    := test-parserMult
LOCAL_C_INCLUDES := $(ZKCompiler_INCLUDE_DIR) $(GMP_INCLUDES)
LOCAL_STATIC_LIBRARIES := zkcompiler
LOCAL_LDLIBS :=-L$(GMP_LIBRARY) -lmpir
LOCAL_SRC_FILES := src/parser/test-parserMult.cpp
include $(BUILD_EXECUTABLE)

LOCAL_MODULE    := test-parserAllAndOr
LOCAL_C_INCLUDES := $(ZKCompiler_INCLUDE_DIR) $(GMP_INCLUDES)
LOCAL_STATIC_LIBRARIES := zkcompiler
LOCAL_LDLIBS :=-L$(GMP_LIBRARY) -lmpir
LOCAL_SRC_FILES := src/parser/test-parserAllAndOr.cpp
include $(BUILD_EXECUTABLE)

LOCAL_MODULE    := benchmark
LOCAL_C_INCLUDES := $(ZKCompiler_INCLUDE_DIR) $(GMP_INCLUDES)
LOCAL_STATIC_LIBRARIES := zkcompiler
LOCAL_LDLIBS :=-L$(GMP_LIBRARY) -lmpir
LOCAL_SRC_FILES := src/benchmark.cpp
include $(BUILD_EXECUTABLE)


LOCAL_MODULE    := test-CodeManagement-Operator
LOCAL_C_INCLUDES := $(ZKCompiler_INCLUDE_DIR) $(GMP_INCLUDES)
LOCAL_STATIC_LIBRARIES := zkcompiler
LOCAL_LDLIBS :=-L$(GMP_LIBRARY) -lmpir
LOCAL_SRC_FILES := src/CodeManagement/test-CodeManagement-Operator.cpp
include $(BUILD_EXECUTABLE)

LOCAL_MODULE    := test-CodeManagement-IfBranch
LOCAL_C_INCLUDES := $(ZKCompiler_INCLUDE_DIR) $(GMP_INCLUDES)
LOCAL_STATIC_LIBRARIES := zkcompiler
LOCAL_LDLIBS :=-L$(GMP_LIBRARY) -lmpir
LOCAL_SRC_FILES := src/CodeManagement/test-CodeManagement-IfBranch.cpp
include $(BUILD_EXECUTABLE)

LOCAL_MODULE    := test-CodeManagement-Instruction
LOCAL_C_INCLUDES := $(ZKCompiler_INCLUDE_DIR) $(GMP_INCLUDES)
LOCAL_STATIC_LIBRARIES := zkcompiler
LOCAL_LDLIBS :=-L$(GMP_LIBRARY) -lmpir
LOCAL_SRC_FILES := src/CodeManagement/test-CodeManagement-Instruction.cpp
include $(BUILD_EXECUTABLE)

