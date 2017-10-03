/** ****************************************************************************
** @brief
** <h2>COPYRIGHT &copy; 2017 ESBOK, All Rights Reserved </h2>
**
** The above copyright notice, subsequent disclaimer and any permission notice
** shall be included in all copies or substantial portions of the Template. 
**
*******************************************************************************/

/** ****************************************************************************
** @brief Title          Version Header File
** @file                 version.h
** @author               Benjamin Sweet, Teknowledge, LLC
** @date                 8/31/2016
** @version              1.0.0
**
** Module Description:
** @brief
**   This file provides externs and references for product version information.
**
** @attention <b>DISCLAIMER:</b>
** THIS SOFTWARE IS PROVIDED BY TEKNOWLEDGE LLC "AS IS" AND ANY EXPRESSED OR IMPLIED 
** WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
** OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
** IN NO EVENT SHALL THE AUTHOR, TEKNOWLEDGE LLC, ESBOK OR THEIR CONTRIBUTORS
** BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, 
** OR CONSEQUENTIAL DAMAGES
** (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
** SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
** HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
** STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
** IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
** THE POSSIBILITY OF SUCH DAMAGE.
**
*******************************************************************************/
/* Include Guard to prevent recursive inclusion */
#ifndef _VERSION_H_
#define _VERSION_H_

#ifdef __cplusplus
extern "C"{
#endif

/*******************************************************************************
* Includes
*******************************************************************************/
#include "..\Types.h"
//#include <stdint.h>
#include "version_cfg.h"

#ifdef VERSION_TEST
 #include "..\_Version\Test\versionTest.h"
#endif

/** @addtogroup PROJ_SD1
 *  @{
 */

/** @addtogroup VERSION_Module
 *  @{
 */

/*******************************************************************************
* Module Public Typedefs
*******************************************************************************/

/*******************************************************************************
* Module Public Preprocessor Constants
*******************************************************************************/

/*******************************************************************************
* Module Public Preprocessor Macros
*******************************************************************************/

/*******************************************************************************
* Module Public Constants
*******************************************************************************/

/*******************************************************************************
* Module Public/Global Variables
*******************************************************************************/

/*******************************************************************************
* Module Public Function Prototypes
*******************************************************************************/
extern uint8_t  getMajorVersion(void);  /* Returns value of MajorVersion */
extern uint8_t  getMinorVersion(void);  /* Returns value of MinorVersion */
extern uint8_t  getBuildVersion(void);  /* Returns value of BuildVersion */

/* Returns overall version number - 32-bit integer value:
 *  00.MajorVersion.MinorVersion.BuildVersion.
 */
extern uint32_t getVersion(void);

/* Prints the productNameSting to the standard output.
* Returns length of productNameString (bytes) printed.
*/
extern int printProductName(void);

/* Prints the productVesionSting to the standard output.
* Returns length of productVersionString (bytes) printed.
*/
extern int printVersionNumber(void);


#ifdef USE_VERSION_STRING_FUNCTIONS
/* Copies productVersionSting to provided buffer.
 * Returns length of productVersionString (bytes) copied.
 */
extern int getVersionString(char * destinationBufferPtr, int destinationBufferLength);

/* Copies productNameSting to provided buffer.
 * Returns length of productNameString (bytes) copied.
 */
extern int getProductNameString(char * destinationBufferPtr, int destinationBufferLength);

#endif /* USE_VERSION_STRING_FUNCTIONS */

/**
 * @}
 */ // group VERSION_Module

/**
 * @}
 */ // group PROJ_SD1

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* _VERSION_H_ */

/******************************* END OF FILE **********************************/
