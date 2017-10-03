/** ****************************************************************************
** @brief
** <h2>COPYRIGHT &copy; 2017 ESBOK, All Rights Reserved </h2>
**
** The above copyright notice, subsequent disclaimer and any permission notice
** shall be included in all copies or substantial portions of the Template. 
**
*******************************************************************************/

/** ****************************************************************************
** @brief Title          Version Configuration Header File
** @file                 version_cfg.h
** @author               Benjamin Sweet, Teknowledge, LLC
** @date                 8/31/2016
** @version              1.0.0
**
** Module Description:
** @brief
**   This file provides constants for product version information.
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
#ifndef _VERSION_CFG_H_
#define _VERSION_CFG_H_

/*******************************************************************************
* Includes
*******************************************************************************/
/* Project configuration */
#include "..\project_cfg.h"

/** @addtogroup PROJ_SD1
 *  @{
 */

/** @addtogroup VERSION_Module
 *  @{
 */

/******************************************************************************
* Module Configuration Constants
******************************************************************************/

#define USE_VERSION_STRING_FUNCTIONS  /* Set symbol to USE_VERSION_STRING_FUNCTIONS to ENABLE Version String functions */
#define xVERSION_TEST                 /* Set symbol to VERSION_TEST to enable Version Test routines */

#if defined(TARGET_PC)
#pragma message ( "Update version_cfg.h for each released version!" )
#else
#warning Update version_cfg.h for each released version!
#endif


#define MAJOR_VERSION (0x01u)
#define MINOR_VERSION (0x00u)
#define BUILD_VERSION (0x00u)

#define PRODUCT_NAME  "Software Development Assignment 1 - SD1"

#define PRODUCT_NAME_BUFFER_LENGTH (sizeof(PRODUCT_NAME))
#define PRODUCT_VERSION_BUFFER_LENGTH (12)  /* Format: v0xHH.HH.HH\0 - 12 characters */ 

/**
 * @}
 */ // group VERSION_Module

/**
 * @}
 */ // group PROJ_SD1


#endif /* _VERSION_CFG_H_ */

/******************************* END OF FILE **********************************/
