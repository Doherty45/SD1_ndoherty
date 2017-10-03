/** ****************************************************************************
** @brief
** <h2>COPYRIGHT &copy; 2017 ESBOK, All Rights Reserved </h2>
**
** The above copyright notice, subsequent disclaimer and any permission notice
** shall be included in all copies or substantial portions of the Template. 
**
*******************************************************************************/

/** ****************************************************************************
** @brief Title          Version Test Module
** @file                 versionTest.c
** @author               Benjamin Sweet, Teknowledge LLC
** @date                 09/01/2016
** @version              01.00.00
**
** Module Description:
** @brief
**   This file provides test routine(s) for prodcut version information.
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

/******************************************************************************
Modification History :
Version      Date         Author            Description
01.00.00     09/01/2016   Benjamin Sweet    Initial release

******************************************************************************/
#define __VERSION_TEST_C__

/******************************************************************************
* Includes
*******************************************************************************/
#include "versionTest.h"

#ifdef VERSION_TEST

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

/* For testing buffer strings longer than source buffer lengths */
#define LONG_NAME_BUFFER_LENGTH    (PRODUCT_NAME_BUFFER_LENGTH + 5)
#define LONG_VERSION_BUFFER_LENGTH (PRODUCT_VERSION_BUFFER_LENGTH + 5)
/* For testing buffer strings shorter than source buffer lengths */
#define SHORT_BUFFER_LENGTH (8)

/*******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/*******************************************************************************
* Module Constants
*******************************************************************************/

/*******************************************************************************
* Module Private Variables
*******************************************************************************/
uint8_t     MajorVersionTest = 0u;
uint8_t     MinorVersionTest = 0u;
uint8_t     BuildVersionTest = 0u;
uint32_t    LongVersionTest = 0ul;

#ifdef USE_VERSION_STRING_FUNCTIONS
char    productNameStringTest_LongBuff[LONG_NAME_BUFFER_LENGTH] = {0};
char    productNameStringTest_ShortBuff[SHORT_BUFFER_LENGTH] = {0};
char    productNameStringTest_ZeroBuff[SHORT_BUFFER_LENGTH] = {0};

char    productVersionStringTest_LongBuff[LONG_VERSION_BUFFER_LENGTH] = {0};
char    productVersionStringTest_ShortBuff[SHORT_BUFFER_LENGTH] = {0};
char    productVersionStringTest_ZeroBuff[SHORT_BUFFER_LENGTH] = {0};

int     stringTestReturnValue = 0;
int     destinationBufferLength = 0;
#endif

/*******************************************************************************
* Module Private Function Prototypes
*******************************************************************************/
void versionTest(void);
void testMajorVersion(void);
void testMinorVersion(void);
void testBuildVersion(void);
void testLongVersion(void);

#ifdef USE_VERSION_STRING_FUNCTIONS
void testVersionStringLong(void);
void testVersionStringShort(void);
void testVersionStringZero(void);
void testVersionStringNull(void);
void testProductNameStringLong(void);
void testProductNameStringShort(void);
void testProductNameStringZero(void); 
void testProductNameStringNull(void); 
#endif /* USE_VERSION_STRING_FUNCTIONS */

/*******************************************************************************
* Module Private Function Definitions
*******************************************************************************/

/**
 * @function testMajorVersion()
 * @brief  Calls getMajorVersion and stores result.
 * @param  None
 * @return None
 */
void testMajorVersion(void)
{
    MajorVersionTest = getMajorVersion();
    return;
}

/**
 * @function testMinorVersion()
 * @brief  Calls getMinorVersion and stores result.
 * @param  None
 * @return None
 */
void testMinorVersion(void)
{
    MinorVersionTest = getMinorVersion();
    return;
}

/**
 * @function testBuildVersion()
 * @brief  Calls getBuildVersion and stores result.
 * @param  None
 * @return None
 */
void testBuildVersion(void)
{
    BuildVersionTest = getBuildVersion();
    return;
}

/**
 * @function testLongVersion()
 * @brief  Calls getVersion and stores result: 32-bit integer value:
 *         00.Major.Minor.Build
 * @param  None
 * @return None
 */
void testLongVersion(void)
{
    LongVersionTest = getVersion();
    return;
}

#ifdef USE_VERSION_STRING_FUNCTIONS
/**
 * @function testVersionStringLong()
 * @brief  Calls getVersionSting() with destination buffer long enough and stores result.
 * @param [in]  None
 * @param [out] stringTestReturnValue return value from getVersionString.
 * @return None
 */
void testVersionStringLong(void)
{
    destinationBufferLength = sizeof(productVersionStringTest_LongBuff);

    stringTestReturnValue = getVersionString(productVersionStringTest_LongBuff, destinationBufferLength);
    return;
}

/**
 * @function testVersionStringShort()
 * @brief  Calls getVersionSting() with destination buffer too short and stores result.
 * @param [in]  None
 * @param [out] stringTestReturnValue return value from getVersionString.
 * @return None
 */
void testVersionStringShort(void)
{
    destinationBufferLength = sizeof(productVersionStringTest_ShortBuff);

    stringTestReturnValue = getVersionString(productVersionStringTest_ShortBuff, destinationBufferLength);
    return;
}

/**
* @function testVersionStringZero()
* @brief  Calls getVersionSting() with zero length destination buffer.
* @param [in]  None
* @param [out] stringTestReturnValue return value from getVersionString - should be 0.
* @return None
*/
void testVersionStringZero(void)
{
    destinationBufferLength = 0;

    stringTestReturnValue = getVersionString(productVersionStringTest_ZeroBuff, destinationBufferLength);
    return;
}

/**
* @function testVersionStringNull()
* @brief  Calls getVersionSting() with NULL destination pointer buffer.
* @param [in]  None
* @param [out] stringTestReturnValue return value from getVersionString - should be 0.
* @return None
*/
void testVersionStringNull(void)
{
    stringTestReturnValue = getVersionString((char*)NULL, SHORT_BUFFER_LENGTH);
    return;
}

/**
 * @function testProductNameStringLong()
 * @brief  Calls getProductNameString() with destination buffer long enough and stores result.
 * @param [in]  None
 * @param [out] stringTestReturnValue return value from getProductNameString.
 * @return None
 */
void testProductNameStringLong(void)
{
    destinationBufferLength = sizeof(productNameStringTest_LongBuff);

    stringTestReturnValue = getProductNameString(productNameStringTest_LongBuff, destinationBufferLength);
    return;
}

/**
 * @function testProductNameStringShort()
 * @brief  Calls getProductNameString() with destination buffer too short and stores result.
 * @param [in]  None
 * @param [out] stringTestReturnValue return value from getProductNameString.
 * @return None
 */
void testProductNameStringShort(void)
{
    destinationBufferLength = sizeof(productNameStringTest_ShortBuff);

    stringTestReturnValue = getProductNameString(productNameStringTest_ShortBuff, destinationBufferLength);
    return;
}

/**
* @function testProductNameStringZero()
* @brief  Calls getProductNameString() with zero length destination buffer.
* @param [in]  None
* @param [out] stringTestReturnValue return value from getProductNameString - should be 0.
* @return None
*/
void testProductNameStringZero(void)
{
    destinationBufferLength = 0;

    stringTestReturnValue = getProductNameString(productNameStringTest_ZeroBuff, destinationBufferLength);
    return;
}

/**
* @function testProductNameStringNull()
* @brief  Calls getProductNameString() with NULL destination pointer buffer.
* @param [in]  None
* @param [out] stringTestReturnValue return value from getProductNameString - should be 0.
* @return None
*/
void testProductNameStringNull(void)
{
    stringTestReturnValue = getProductNameString((char*)NULL, SHORT_BUFFER_LENGTH);
    return;
}
#endif /* USE_VERSION_STRING_FUNCTIONS */

/*******************************************************************************
* Module Public Function Definitions
*******************************************************************************/

 /**
 * @function versionTest()
 * @brief  Runs all Version Tests.
 * @param  None
 * @return None
 */
void versionTest(void)  /*  */
{
    testMajorVersion();             /* Result in: MajorVersionTest */
    testMinorVersion();             /* Result in: MinorVersionTest */
    testBuildVersion();             /* Result in: BuildVersionTest */
    testLongVersion();              /* Result in: LongVersionTest  */

  #ifdef USE_VERSION_STRING_FUNCTIONS
    testVersionStringLong();        /* Result in: productNameStringTest_LongBuff[]      */
    testVersionStringShort();       /* Result in: productNameStringTest_ShortBuff[]     */
    testVersionStringZero();        /* Result in: productNameStringTest_ZeroBuff[] - stringTestReturnValue should be 0      */
    testVersionStringNull();        /* NULL result pointer - stringTestReturnValue should be 0   */
    testProductNameStringLong();    /* Result in: productVersionStringTest_LongBuff[]   */
    testProductNameStringShort();   /* Result in: productVersionStringTest_ShortBuff[]  */
    testProductNameStringZero();    /* Result in: productVersionStringTest_ShortZero[] - stringTestReturnValue should be 0  */
    testProductNameStringNull();    /* NULL result pointer - stringTestReturnValue should be 0   */
  #endif /* USE_VERSION_STRING_FUNCTIONS */

    return;
}


#endif /* VERSION_TEST */

/**
 * @}
 */ // group VERSION_Module

/**
 * @}
 */ // group PROJ_SD1

/******************************* END OF FILE **********************************/
