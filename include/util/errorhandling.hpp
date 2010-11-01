/** \file errorhandling.hpp
 ** \brief contains error handling routines
 **/
#ifndef ERRORHANDLING_HPP
#define ERRORHANDLING_HPP

#include "CodeManagement/ccw/impl/Procedure.hpp"
#include "util/basictypes.hpp"

namespace ZKCompiler {

/** \brief Handles a runtime error.
 ** \param message error message
 **/
#define ZK_HANDLE_ERROR(message) handle_error((message), __FILE__, __LINE__)

/** \brief CodeManagement wrapper for macro ZK_HANDLE_ERROR.
 ** \param message error message
 **/
#define ZK_CMI_HANDLE_ERROR(message) CMI(handle_error((message), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)))

/** \brief CodeManagement wrapper for macro ZK_CMI_HANDLE_ERROR.
 ** \param message error message going to be wrapped with CMV_IN
 **/
#define ZK_CMI_HANDLE_ERROR_CMV_IN(message) ZK_CMI_HANDLE_ERROR(CMV_IN((zk_pcchar_t)(message)))

    /** \brief Handles a runtime error. Use the macro ZK_HANDLE_ERROR.
     ** \param pMessage error message
     ** \param pFileName name of the source file the error occurred in
     ** \param line error number of the line in the source file the error occurred in
     **/
    void handle_error(const char* pMessage, const char* pFileName, int line) /*throw (const char*)*/;

}

CMD_CODE_DEFINITIONS_BLOCK_EX(ZKCompiler)
{
    CMD_PROCEDURE_i3(handle_error, zk_pcchar_t, zk_pcchar_t, zk_int_t, zk_pcchar_t, zk_pcchar_t, zk_int_t)
}

#endif
