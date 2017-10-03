/** ****************************************************************************
** @brief
** <h2>COPYRIGHT &copy; 2017 ESBOK, All Rights Reserved </h2>
**
** The above copyright notice, subsequent disclaimer and any permission notice
** shall be included in all copies or substantial portions of the Template. 
**
*******************************************************************************/

/**
 *  @defgroup HMI_Module
 */

/** ****************************************************************************
** @brief Title          Human-Machine Interface Module
** @file                 Hmi.c
** @author               Benjamin Sweet, Teknowledge LLC
** @date                 09/25/2017
** @version              01.00.00
**
** Module Description:
** @brief
**   This file provides Basic Human-Machine Interface [HMI] functions.
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
01.00.00     09/25/2017   Benjamin Sweet    Initial release

******************************************************************************/
#define __VERSION_C__

/******************************************************************************
* Includes
*******************************************************************************/
/* Function Prototypes/Declaration */
#include "Hmi.h"
#include <stdio.h>
#include <ctype.h>


/** @addtogroup PROJ_SD1
 *  @{
 */

/** @addtogroup HMI_Module
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

/*******************************************************************************
* Module Private Variables
*******************************************************************************/
static bool_t HMI_ContinueState = FALSE;      /* Current state of User request to contine */


/*******************************************************************************
* Module Private Function Prototypes
*******************************************************************************/
static void HMI_Set_ContinueState(bool_t);


/*******************************************************************************
* Module Private Function Definitions
*******************************************************************************/

/*******************************************************************************
* Module Public Function Definitions
*******************************************************************************/


/** ****************************************************************************
** @function  HMI_Init()
**
** @brief <b> Function Description: </b><br>
** - Initializes the HMI states.
**
********************************************************************************
** PRE-CONDITIONS:
** - none
**
** POST-CONDITIONS:
** - HMI states initialized.
**
** @param [in]      none
**
** @param [out]     HMI_ContinueState
**
** @param [in,out]  none
**
** @return          none
**
********************************************************************************
** @description <b> Detailed Description: </b><br>
** Initializes the HMI states.
**
********************************************************************************
** <b> Usage Example: </b>
** @code
**     HMI_Init();
**
** @endcode
**
********************************************************************************
** Called Functions:
** @see HMI_Set_ContinueState()
**
*******************************************************************************/
void MHI_Init(void)
{
    /* Input Signals: */

    /* Output Signals: */
    HMI_Set_ContinueState(FALSE);

    return;
}  /* End: HMI_Init() */


/** ****************************************************************************
** @function  HMI_Task()
**
** @brief <b> Function Description: </b><br>
** - Periodic HMI Task invoked by the System.
**
********************************************************************************
** PRE-CONDITIONS:
** - none
**
** POST-CONDITIONS:
** - Associated actions taken.
**
** @param [in]      none
**
** @param [out]     none
**
** @param [in,out]  none
**
** @return          none
**
********************************************************************************
** @description <b> Detailed Description: </b><br>
** Periodic HMI Task invoked by the System.
**
********************************************************************************
** <b> Usage Example: </b>
** @code
**     HMI_Task();
**
** @endcode
**
********************************************************************************
** Called Functions:
** none
**
*******************************************************************************/
void HMI_Task(void)
{

    return;
}  /* End: HMI_Task() */




/*
**  Definition of Mutator and Accessor methods:
*/

/**
** @fn              HMI_Set_ContinueState()
**
** @brief Mutator method for signal HMI_ContinueState.
**
** @param [in]      SetValue
**
** @param [out]     void
**
** @return          void
*/
static void HMI_Set_ContinueState(bool_t SetValue)
{
   HMI_ContinueState = SetValue;
   return;
}

/**
** @fn             HMI_Get_ContinueState()
**
** @brief Accessor method for signal HMI_ContinueState.
**
** @param [in,out]  void
**
** @return          Hmi_continueState
*/
bool_t HMI_Get_ContinueState(void)
{
   return HMI_ContinueState;
}

/**
** @fn              HMI_Prompt_ContinueState()
**
** @brief Prompt User for value of signal HMI_ContinueState, set the value, and return the value.
**
** @param [in]      none
**
** @param [out]     HMI_ContinueState
**
** @return          HMI_ContinueState
*/
bool_t HMI_Prompt_ContinueState(void)
{
    bool_t continueState_SetValue = FALSE;
    char userResponse[BUFSIZ] = { NULL };  /* Character Array for user response. */

    printf(HMI_PROMPT_CONTINUE);
    /* This "flushes" the keyboard input buffer */
    fflush(stdin);
    scanf_s("%s", userResponse, BUFSIZ);

    if (toupper(userResponse[0]) == 'Y')
    {
        printf("\nGreat!  Glad to hear that!  :-)\n\n");
        continueState_SetValue = TRUE;
    }
    else
    {
        printf("\nThat's too bad.  Very sorry to hear that.  :-(\n\n");
        continueState_SetValue = FALSE;
    }

    /* This "flushes" the keyboard input buffer */
    fflush(stdin);

    HMI_ContinueState = continueState_SetValue;

    return HMI_ContinueState;
}

/**
 * @}
 */ // group HMI_Module

/**
 * @}
 */ // group PROJ_SD1

/******************************* END OF FILE **********************************/
