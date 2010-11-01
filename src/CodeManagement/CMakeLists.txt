include_directories(${CodeManagement_INCLUDE_DIR})

add_library(CodeManagement 
    ${CodeManagement_INCLUDE_DIR}/ccr/ACCRVisitor.hpp ccr/ACCRVisitor.cpp
    ${CodeManagement_INCLUDE_DIR}/ccr/ACollectedCodeRepr.hpp ccr/ACollectedCodeRepr.cpp
    ${CodeManagement_INCLUDE_DIR}/ccr/AConstructorCallCCR.hpp ccr/AConstructorCallCCR.cpp
    ${CodeManagement_INCLUDE_DIR}/ccr/ACopyAssignmentCallCCR.hpp ccr/ACopyAssignmentCallCCR.cpp
    ${CodeManagement_INCLUDE_DIR}/ccr/ACopyConstructorCallCCR.hpp ccr/ACopyConstructorCallCCR.cpp
    ${CodeManagement_INCLUDE_DIR}/ccr/ADestructorCallCCR.hpp ccr/ADestructorCallCCR.cpp
    ${CodeManagement_INCLUDE_DIR}/ccr/AExecutableCCR.hpp ccr/AExecutableCCR.cpp
    ${CodeManagement_INCLUDE_DIR}/ccr/AFunctionCallCCR.hpp ccr/AFunctionCallCCR.cpp
    ${CodeManagement_INCLUDE_DIR}/ccr/AInstructionCallCCR.hpp ccr/AInstructionCallCCR.cpp
    ${CodeManagement_INCLUDE_DIR}/ccr/AOperatorCallCCR.hpp ccr/AOperatorCallCCR.cpp
    ${CodeManagement_INCLUDE_DIR}/ccr/AProcedureCallCCR.hpp ccr/AProcedureCallCCR.cpp
    ${CodeManagement_INCLUDE_DIR}/ccr/AVariableCCR.hpp ccr/AVariableCCR.cpp
    ${CodeManagement_INCLUDE_DIR}/ccr/AVarSpecialCallCCR.hpp ccr/AVarSpecialCallCCR.cpp
    ${CodeManagement_INCLUDE_DIR}/ccr/impl/CommentCCR.hpp ccr/impl/CommentCCR.cpp
    ${CodeManagement_INCLUDE_DIR}/ccr/impl/ConstructorCallCCR.hpp ccr/impl/ConstructorCallCCR.cpp
    ${CodeManagement_INCLUDE_DIR}/ccr/impl/CopyableVariableCCR.hpp ccr/impl/CopyableVariableCCR.cpp
    ${CodeManagement_INCLUDE_DIR}/ccr/impl/CopyAssignmentCallCCR.hpp ccr/impl/CopyAssignmentCallCCR.cpp
    ${CodeManagement_INCLUDE_DIR}/ccr/impl/CopyConstructorCallCCR.hpp ccr/impl/CopyConstructorCallCCR.cpp
    ${CodeManagement_INCLUDE_DIR}/ccr/impl/DestructorCallCCR.hpp ccr/impl/DestructorCallCCR.cpp
    ${CodeManagement_INCLUDE_DIR}/ccr/impl/FunctionCallCCR.hpp ccr/impl/FunctionCallCCR.cpp
    ${CodeManagement_INCLUDE_DIR}/ccr/impl/IfBranchCallCCR.hpp ccr/impl/IfBranchCallCCR.cpp
    ${CodeManagement_INCLUDE_DIR}/ccr/impl/OperatorCallCCR.hpp ccr/impl/OperatorCallCCR.cpp
    ${CodeManagement_INCLUDE_DIR}/ccr/impl/ProcedureCallCCR.hpp ccr/impl/ProcedureCallCCR.cpp
    ${CodeManagement_INCLUDE_DIR}/ccr/impl/ProgramCCR.hpp ccr/impl/ProgramCCR.cpp
    ${CodeManagement_INCLUDE_DIR}/ccr/impl/ScopeBlockCCR.hpp ccr/impl/ScopeBlockCCR.cpp
    ${CodeManagement_INCLUDE_DIR}/ccr/impl/VariableCCR.hpp ccr/impl/VariableCCR.cpp
    ${CodeManagement_INCLUDE_DIR}/ccw/AFunction.hpp ccw/AFunction.cpp
    ${CodeManagement_INCLUDE_DIR}/ccw/AInstruction.hpp ccw/AInstruction.cpp
    ${CodeManagement_INCLUDE_DIR}/ccw/AOperator.hpp ccw/AOperator.cpp
    ${CodeManagement_INCLUDE_DIR}/ccw/AProcedure.hpp ccw/AProcedure.cpp
    ${CodeManagement_INCLUDE_DIR}/ccw/AVariable.hpp ccw/AVariable.cpp
    ${CodeManagement_INCLUDE_DIR}/ccw/impl/CopyableVariable.hpp ccw/impl/CopyableVariable.cpp
    ${CodeManagement_INCLUDE_DIR}/ccw/impl/Function.hpp ccw/impl/Function.cpp
    ${CodeManagement_INCLUDE_DIR}/ccw/impl/Operator.hpp ccw/impl/Operator.cpp
    ${CodeManagement_INCLUDE_DIR}/ccw/impl/Procedure.hpp ccw/impl/Procedure.cpp
    ${CodeManagement_INCLUDE_DIR}/ccw/impl/Variable.hpp ccw/impl/Variable.cpp
    ${CodeManagement_INCLUDE_DIR}/exec/AExplicitCSrcInstCaster.hpp exec/AExplicitCSrcInstCaster.cpp
    ${CodeManagement_INCLUDE_DIR}/exec/AImplicitSrcInstCaster.hpp exec/AImplicitSrcInstCaster.cpp
    ${CodeManagement_INCLUDE_DIR}/exec/ASourceInstanceCaster.hpp exec/ASourceInstanceCaster.cpp
    ${CodeManagement_INCLUDE_DIR}/exec/AVariableInstance.hpp exec/AVariableInstance.cpp
    ${CodeManagement_INCLUDE_DIR}/exec/AVariablesTable.hpp exec/AVariablesTable.cpp
    ${CodeManagement_INCLUDE_DIR}/exec/impl/ConstSourceInstance.hpp exec/impl/ConstSourceInstance.cpp
    ${CodeManagement_INCLUDE_DIR}/exec/impl/CopyableVariableInstance.hpp exec/impl/CopyableVariableInstance.cpp
    ${CodeManagement_INCLUDE_DIR}/exec/impl/ExplicitCSrcInstCaster.hpp exec/impl/ExplicitCSrcInstCaster.cpp
    ${CodeManagement_INCLUDE_DIR}/exec/impl/ImplicitSrcInstCaster.hpp exec/impl/ImplicitSrcInstCaster.cpp
    ${CodeManagement_INCLUDE_DIR}/exec/impl/SourceInstance.hpp exec/impl/SourceInstance.cpp
    ${CodeManagement_INCLUDE_DIR}/exec/impl/VariableInstance.hpp exec/impl/VariableInstance.cpp
    ${CodeManagement_INCLUDE_DIR}/exec/impl/VariablesTable.hpp exec/impl/VariablesTable.cpp
    ${CodeManagement_INCLUDE_DIR}/core/ACodeObserver.hpp core/ACodeObserver.cpp
    ${CodeManagement_INCLUDE_DIR}/core/impl/CodeCollector.hpp core/impl/CodeCollector.cpp
    ${CodeManagement_INCLUDE_DIR}/core/impl/CodeManager.hpp core/impl/CodeManager.cpp
    ${CodeManagement_INCLUDE_DIR}/misc/debug/impl/DebugInfo.hpp misc/debug/impl/DebugInfo.cpp
    ${CodeManagement_INCLUDE_DIR}/misc/debug/impl/Exception.hpp misc/debug/impl/Exception.cpp
    ${CodeManagement_INCLUDE_DIR}/misc/stream/AStream.hpp misc/stream/AStream.cpp
    ${CodeManagement_INCLUDE_DIR}/misc/stream/impl/FileStream.hpp misc/stream/impl/FileStream.cpp
    ${CodeManagement_INCLUDE_DIR}/misc/stream/impl/NullStream.hpp misc/stream/impl/NullStream.cpp
    ${CodeManagement_INCLUDE_DIR}/misc/stream/impl/StringStream.hpp misc/stream/impl/StringStream.cpp
    ${CodeManagement_INCLUDE_DIR}/misc/stream/impl/Logger.hpp misc/stream/impl/Logger.cpp
    )
    
       
add_executable (test-CodeManagement-Operator test-CodeManagement-Operator.cpp)
add_test (test-CodeManagement-Operator ${PROJECT_BINARY_DIR}/bin/test-CodeManagement-Operator)
DLL_COPY_TO_BINARY_DIR(test-CodeManagement-Operator)
target_link_libraries (test-CodeManagement-Operator CodeManagement)

add_executable (test-CodeManagement-IfBranch test-CodeManagement-IfBranch.cpp)
add_test (test-CodeManagement-IfBranch ${PROJECT_BINARY_DIR}/bin/test-CodeManagement-IfBranch)
DLL_COPY_TO_BINARY_DIR(test-CodeManagement-IfBranch)
target_link_libraries (test-CodeManagement-IfBranch CodeManagement)

add_executable (test-CodeManagement-Instruction test-CodeManagement-Instruction.cpp)
add_test (test-CodeManagement-Instruction ${PROJECT_BINARY_DIR}/bin/test-CodeManagement-Instruction)
DLL_COPY_TO_BINARY_DIR(test-CodeManagement-Instruction)
target_link_libraries (test-CodeManagement-Instruction CodeManagement)
