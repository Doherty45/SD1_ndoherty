/** ****************************************************************************
** @brief
** <h2>COPYRIGHT &copy; 2017 ESBOK, All Rights Reserved </h2>
**
** The above copyright notice, subsequent disclaimer and any permission notice
** shall be included in all copies or substantial portions of the Template. 
**
*******************************************************************************/

/** ****************************************************************************
** @brief Title          Human-Machine Interface Header File
** @file                 Hmi.h
** @author               Benjamin Sweet, Teknowledge, LLC
** @date                 9/25/2017
** @version              1.0.0
**
** Module Description:
** @brief
**  Declarations for HMI functions
**  Delcare external functions for General HMI operation.
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
#ifndef _HMI_H_
#define _HMI_H_

#ifdef __cplusplus
extern "C"{
#endif

/*******************************************************************************
* Includes
*******************************************************************************/
/* Project configuration */
#include "..\..\project_cfg.h"
/* Type Definitions */
#include "..\..\Types.h"

/* Module Configuration */
#include "Hmi_cfg.h"

/** @addtogroup PROJ_SD1
 *  @{
 */

/** @addtogroup HMI_Module
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
extern void HMI_Init(void);
extern void HMI_Task(void);

extern bool_t HMI_Get_ContinueState(void);

/**
 * @}
 */ // group HMI_Module

/**
 * @}
 */ // group PROJ_SD1

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* _HMI_H_ */

/******************************* END OF FILE **********************************/
