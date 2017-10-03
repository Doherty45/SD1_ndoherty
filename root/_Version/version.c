/** ****************************************************************************
** @brief
** <h2>COPYRIGHT &copy; 2017 ESBOK, All Rights Reserved </h2>
**
** The above copyright notice, subsequent disclaimer and any permission notice
** shall be included in all copies or substantial portions of the Template. 
**
*******************************************************************************/

/**
 *  @defgroup VERSION_Module
 */

/** ****************************************************************************
** @brief Title          Version Module
** @file                 version.c
** @author               Benjamin Sweet, Teknowledge LLC
** @date                 08/31/2016
** @version              01.00.00
**
** Module Description:
** @brief
**   This file provides storage classes and accessors for product version information.
**
** @attention <b>DISCLAIMER:</b>
** THIS SOFTWARE IS PROVIDED BY Teknowledge, LLC "AS IS" AND ANY EXPRESSED OR IMPLIED 
** WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
** OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
** IN NO EVENT SHALL Teknowledge, LLC OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
** INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
** (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
** SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
** HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
** STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
** IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
** THE POSSIBILITY OF SUCH DAMAGE.
**
*******************************************************************************/

/** ****************************************************************************
** @paragraph
** <b> Revision History: </b><br>
Version      Date         Author            Description
01.00.00     08/31/2016   Benjamin Sweet    Initial release

******************************************************************************/
#define __VERSION_C__

/******************************************************************************
* Includes
*******************************************************************************/
#include "version.h"

#ifdef USE_VERSION_STRING_FUNCTIONS
#include <stdio.h>  /* For sprintf() */
#include <string.h> /* For strncpy() */
#endif

/** @addtogroup PROJ_SD1
 *  @{
 */

/** @addtogroup VERSION_Module
 *  @{
 */

/*******************************************************************************
* Module Typedefs
*******************************************************************************/

/*******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/*******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/*******************************************************************************
* Module Constants
*******************************************************************************/
static const uint8_t MajorVersion = MAJOR_VERSION;
static const uint8_t MinorVersion = MINOR_VERSION;
static const uint8_t BuildVersion = BUILD_VERSION;

const char    productNameString[] = PRODUCT_NAME;

/*******************************************************************************
* Module Private Variables
*******************************************************************************/


/*******************************************************************************
* Module Private Function Prototypes
*******************************************************************************/

/*******************************************************************************
* Module Private Function Definitions
*******************************************************************************/

/*******************************************************************************
* Module Public Function Definitions
*******************************************************************************/
/** ****************************************************************************
** @function  getMajorVersion()
**
** @brief <b> Function Description: </b><br>
** - Returns value of MajorVersion.
**
********************************************************************************
** PRE-CONDITIONS:
** - MajorVersion is defined and initialized.
**
** POST-CONDITIONS:
** - MajorVersion value is returned.
**
** @param [in]      none
**
** @param [out]     none
**
** @param [in,out]  none
**
** @return          MajorVersion - uint8_t
**
********************************************************************************
** @description <b> Detailed Description: </b><br>
** Returns integer value (uint8_t) of MajorVersion.
**
********************************************************************************
** <b> Usage Example: </b>
** @code
**     (uint8_t)majorVersion = getMajorVersion();
**
** @endcode
**
********************************************************************************
** Called Functions:
** none
**
*******************************************************************************/
uint8_t  getMajorVersion(void)
{
    return MajorVersion;
}

/** ****************************************************************************
** @function  getMinorVersion()
**
** @brief <b> Function Description: </b><br>
** - Returns value of MinorVersion.
**
********************************************************************************
** PRE-CONDITIONS:
** - MinorVersion is defined and initialized.
**
** POST-CONDITIONS:
** - MinorVersion value is returned.
**
** @param [in]      none
**
** @param [out]     none
**
** @param [in,out]  none
**
** @return          MinorVersion - uint8_t
**
********************************************************************************
** @description <b> Detailed Description: </b><br>
** Returns integer value (uint8_t) of MinorVersion.
**
********************************************************************************
** <b> Usage Example: </b>
** @code
**     (uint8_t)minorVersion = getMinorVersion();
**
** @endcode
**
********************************************************************************
** Called Functions:
** none
**
*******************************************************************************/
 uint8_t  getMinorVersion(void)
{
    return MinorVersion;
}

/** ****************************************************************************
** @function  getBuildVersion()
**
** @brief <b> Function Description: </b><br>
** - Returns value of BuildVersion.
**
********************************************************************************
** PRE-CONDITIONS:
** - BuildVersion is defined and initialized.
**
** POST-CONDITIONS:
** - BuildVersion value is returned.
**
** @param [in]      none
**
** @param [out]     none
**
** @param [in,out]  none
**
** @return          BuildVersion - uint8_t
**
********************************************************************************
** @description <b> Detailed Description: </b><br>
** Returns integer value (uint8_t) of BuildVersion.
**
********************************************************************************
** <b> Usage Example: </b>
** @code
**     (uint8_t)buildVersion = getBuildVersion();
**
** @endcode
**
********************************************************************************
** Called Functions:
** none
**
*******************************************************************************/
uint8_t  getBuildVersion(void)
{
    return BuildVersion;
}

/** ****************************************************************************
** @function  getVersion()
**
** @brief <b> Function Description: </b><br>
** - Returns overall version number - 32-bit integer value:
**   00.MajorVersion.MinorVersion.BuildVersion
**
********************************************************************************
** PRE-CONDITIONS:
** - MajorVersion, MinorVersion and BuildVersion are defined and initialized.
**
** POST-CONDITIONS:
** - 00.MajorVersion.MinorVersion.BuildVersion value is returned.
**
** @param [in]      none
**
** @param [out]     none
**
** @param [in,out]  none
**
** @return          00.MajorVersion.MinorVersion.BuildVersion - uint32_t
**
********************************************************************************
** @description <b> Detailed Description: </b><br>
** Returns long integer value (uint32_t) of 00.MajorVersion.MinorVersion.BuildVersion.
**
********************************************************************************
** <b> Usage Example: </b>
** @code
**     (uint32_t)Version = getVersion();
**
** @endcode
**
********************************************************************************
** Called Functions:
** none
**
*******************************************************************************/
uint32_t getVersion(void)
{
    return ( (MajorVersion << 16) | (MinorVersion << 8) | (BuildVersion) );
}

/** ****************************************************************************
** @function  printVersionNumber()
**
** @brief <b> Function Description: </b><br>
** - Prints the productVesionSting to the standard output.
** - Returns length of productVesionSting (bytes) printed.
**
********************************************************************************
** PRE-CONDITIONS:
** - MajorVersion, MinorVersion and BuildVersion are defined and initialized.
**
** POST-CONDITIONS:
** - Software version string value is printed on standard output.
**
** @param [in]      none
**
** @param [out]     none
**
** @param [in,out]  none
**
** @return          Length of the string (bytes) printed - int
**
********************************************************************************
** @description <b> Detailed Description: </b><br>
** - Prints the productVesionSting to the standard output.
** - Returns length of productVesionSting (bytes) printed.
**
********************************************************************************
** <b> Usage Example: </b>
** @code
**     (int)bytesPrinted = printVersionNumber();
**
** @endcode
**
********************************************************************************
** Called Functions:
** none
**
*******************************************************************************/
int printVersionNumber(void)
{
    int     stringLength = 0;

  #ifdef USE_VERSION_STRING_FUNCTIONS
    int     bufferLength;
    char    productVersionString[PRODUCT_VERSION_BUFFER_LENGTH];

    bufferLength = sizeof(productVersionString);
    stringLength = getVersionString(productVersionString, bufferLength);
    printf("\nProduct Version: %s\n\n", productVersionString);
  #endif // USE_VERSION_STRING_FUNCTIONS

    return stringLength;
}

/** ****************************************************************************
** @function  printProductName()
**
** @brief <b> Function Description: </b><br>
** - Prints the productNameSting to the standard output.
** - Returns length of productNameString (bytes) printed.
**
********************************************************************************
** PRE-CONDITIONS:
** - productNameString[] is defined and initialized.
**
** POST-CONDITIONS:
** - productNameString[] is printed on standard output.
**
** @param [in]      none
**
** @param [out]     none
**
** @param [in,out]  none
**
** @return          Length of the string (bytes) printed - int
**
********************************************************************************
** @description <b> Detailed Description: </b><br>
** - Prints the productNameSting to the standard output.
** - Returns length of productNameString (bytes) printed.
**
********************************************************************************
** <b> Usage Example: </b>
** @code
**     (int)bytesPrinted = printProductName();
**
** @endcode
**
********************************************************************************
** Called Functions:
** none
**
*******************************************************************************/
int printProductName(void)
{
    int     stringLength = 0;

  #ifdef USE_VERSION_STRING_FUNCTIONS
    int     bufferLength;

    char    productNameString[PRODUCT_NAME_BUFFER_LENGTH];

    bufferLength = sizeof(productNameString);
    stringLength = getProductNameString(productNameString, bufferLength);
    printf("\nProduct Name: %s\n\n", productNameString);
  #endif // USE_VERSION_STRING_FUNCTIONS

    return stringLength;
}



#ifdef USE_VERSION_STRING_FUNCTIONS
/** ****************************************************************************
** @function  getVersionString()
**
** @brief <b> Function Description: </b><br>
** - Copies string value of Software Version and Returns the length of the
**   software version string.
**
********************************************************************************
** PRE-CONDITIONS:
** - MajorVersion, MinorVersion and BuildVersion are defined and initialized.
**
** POST-CONDITIONS:
** - Software version string value is copied to destination buffer.
**
** @param [in]      destinationBufferPtr - Pointer to destination for VersionString
** @param [in]      destinationBufferLength - Maximum length of destinationBuffer
**
** @param [out]     none
**
** @param [in,out]  none
**
** @return          stringLength - number of bytes of productVersionString copied
**
********************************************************************************
** @description <b> Detailed Description: </b><br>
** - Copies string value of Software Version to the specified destination buffer
**   and Returns the length of the software version string (number of bytes copied.)
** 
** - Format of Version string:
**   "v0x%02X.%02X.%02X", MajorVersion, MinorVersion, BuildVersion
**
********************************************************************************
** <b> Usage Example: </b>
** @code
**     (int)versionStringLength = getVersionString(destinationBufferPtr, destinationBufferLength);
**
** @endcode
**
********************************************************************************
** Called Functions:
** - sprintf()
** - strncpy()
**
*******************************************************************************/
int getVersionString(char * destinationBufferPtr, int destinationBufferLength)
{
    char    productVersionString[PRODUCT_VERSION_BUFFER_LENGTH];
    int     versionStringLength = 0;
    int     numberCharsToCopy = 0;
    int     returnValue = 0;


    /* Verify non-NULL destinationBufferPtr AND non-zero destinationBufferLength */
    if ( (destinationBufferPtr != (char*)NULL) && (destinationBufferLength > 0) )
    {
        /* Create string for Product Version */
        versionStringLength = sprintf(productVersionString, "v0x%02X.%02X.%02X", MajorVersion, MinorVersion, BuildVersion);
        ++versionStringLength;  /* sprintf() does not account for NULL terminator! */

        if (versionStringLength > 0) /* Product Version string creation successful */
        {
            /* numberCharsToCopy is the smaller of the two buffer lengths*/
            if (destinationBufferLength >= versionStringLength) /* sprintf() returns length without NULL termination */
            {
                numberCharsToCopy = versionStringLength;
                strncpy(destinationBufferPtr, productVersionString, (size_t)numberCharsToCopy);
            }
            else
            {
                numberCharsToCopy = (destinationBufferLength - 1); /* Leave last char for NULL termination */

                strncpy(destinationBufferPtr, productVersionString, (size_t)numberCharsToCopy);
                destinationBufferPtr[numberCharsToCopy] = '\0';     /* NULL termination manually added */
            }

            returnValue = numberCharsToCopy;
        }
        else /* Error: Product Version string length is 0 or negative */
        {
            returnValue = versionStringLength;
        }
    }
    else /* Error: Destination Pointer is NULL -OR- Destination Buffer length is 0 or negative */
    {
        returnValue = 0;
    }

    return returnValue;
}

/** ****************************************************************************
** @function  getProductNameString()
**
** @brief <b> Function Description: </b><br>
** - Copies string value of Software Product Name and Returns the length of the
**   product name string.
**
********************************************************************************
** PRE-CONDITIONS:
** - productNameString[] is defined and initialized.
**
** POST-CONDITIONS:
** - productNameString[] is copied to destination buffer.
**
** @param [in]      destinationBufferPtr - Pointer to destination for productNameString
** @param [in]      destinationBufferLength - Maximum length of destinationBuffer
**
** @param [out]     none
**
** @param [in,out]  none
**
** @return          stringLength - number of bytes of productNameString copied
**
********************************************************************************
** @description <b> Detailed Description: </b><br>
** - Copies string value of Software Product Name to the specified destination buffer
**   and Returns the length of the Software Product Name string (number of bytes copied.)
**
********************************************************************************
** <b> Usage Example: </b>
** @code
**     (int)productNameStringLength = productNameString(destinationBufferPtr, destinationBufferLength);
**
** @endcode
**
********************************************************************************
** Called Functions:
** - strlen()
** - strncpy()
**
*******************************************************************************/
int getProductNameString(char * destinationBufferPtr, int destinationBufferLength)
{
    int     productNameStringLength = 0;
    int     numberCharsToCopy = 0;
    int     returnValue = 0;

    /* Verify non-NULL destinationBufferPtr AND non-zero destinationBufferLength */
    if ( (destinationBufferPtr != (char*)NULL) && (destinationBufferLength > 0) )
    {
        /* Get length of Product Name string */
        productNameStringLength = strlen(productNameString) + 1;  /* strlen does not include NULL terminator! */

        if (productNameStringLength > 0) /* Product Name string is nonzero */
        {
            /* numberCharsToCopy is the smaller of the two buffer lengths*/
            if (destinationBufferLength >= productNameStringLength)
            {
                numberCharsToCopy = productNameStringLength;
                strncpy(destinationBufferPtr, productNameString, (size_t)numberCharsToCopy);
            }
            else
            {
                numberCharsToCopy = (destinationBufferLength - 1); /* Leave last char for NULL termination */

                strncpy(destinationBufferPtr, productNameString, (size_t)numberCharsToCopy);
                destinationBufferPtr[numberCharsToCopy] = '\0';     /* NULL termination manually added */
            }

            returnValue = numberCharsToCopy;
        }
        else /* Error: Product Name string length is 0 or negative */
        {
            returnValue = productNameStringLength;
        }
    }
    else /* Error: Destination Pointer is NULL -OR- Destination Buffer length is 0 or negative */
    {
        returnValue = 0;
    }

    return returnValue;
}

#endif /* USE_VERSION_STRING_FUNCTIONS */


/**
 * @}
 */ // group VERSION_Module

/**
 * @}
 */ // group PROJ_SD1

/******************************* END OF FILE **********************************/
