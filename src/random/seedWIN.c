// Using the Windows Crypto API for getting a random seed               
// File: randomseedWIN.c
// Version: 1.3
// Last modified: 2010-05-15
// Author: Tobias Jeske
//
// Input: number of bytes
// Output: pointer to a random byte array of length "bytes"
//         return value: result of GetLastError()
static int x = 0;

#include <windows.h>
#include <wincrypt.h>
#include <tchar.h>

#include "random/random_seed.h"


unsigned long getRandomSeed(BYTE *randomdata, unsigned int bytes)
  {
  //--------------------------------------------------------------------
  // Declare and initialize variables.
  HCRYPTPROV hCryptProv = 0;             // Handle for a cryptographic
                                         // provider context.
  TCHAR UserName[] = _T("MyKeyContainer");  // Name of the key container
                                            // to be used.
  //--------------------------------------------------------------------
  // Attempt to acquire a context and a key
  // container. The context will use the default CSP
  // for the RSA_FULL provider type. DwFlags is set to 0
  // to attempt to open an existing key container.

  if(!CryptAcquireContext(
     &hCryptProv,               // Handle to the CSP.
     UserName,                  // Container name.
     NULL,                      // Use the default provider.
     PROV_RSA_FULL,             // Provider type.
     0))                        // Flag values.
    {
    //--------------------------------------------------------------------
    // An error occurred in acquiring the context. This could mean
    // that the key container requested does not exist. In this case,
    // the function can be called again to attempt to create a new key 
    // container. Error codes are defined in winerror.h.
	if (GetLastError() == NTE_BAD_KEYSET)
	  {
		if (!CryptAcquireContext(&hCryptProv, 
								 UserName, 
								 NULL, 
								 PROV_RSA_FULL, 
								 CRYPT_NEWKEYSET))
		  {
		  return(GetLastError());
		  }
	  }
	return(GetLastError());
    }

  // Generate a random initialization vector.
  if(!CryptGenRandom(hCryptProv, bytes, randomdata))
    {
    return(GetLastError());
    }

  // When the handle is no longer needed, it must be freed.
  if (!CryptReleaseContext(hCryptProv,0))
    {
    // The handle could not be freed
    return(GetLastError());
    }

  return 0;
  }

