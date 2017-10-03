/** ****************************************************************************
** @brief
** <h2>COPYRIGHT &copy; 2017 ESBOK, All Rights Reserved </h2>
**
** The above copyright notice, subsequent disclaimer and any permission notice
** shall be included in all copies or substantial portions of the Template. 
**
*******************************************************************************/

/**
 *  @defgroup MAIN
 */

/** ****************************************************************************
** @brief Title          Main Code file
** @file                 main.c
** @author               Benjamin D. Sweet, Teknowledge LLC, ESBOK
** @date                 09/26/2017
** @version              2.0.0
**
** Module Description:
** @brief
**   Provides main() function, System_Init() and System_Task() function for project.
**
** @attention <b>DISCLAIMER:</b>
** THIS SOFTWARE IS PROVIDED BY Teknowledge, LLC "AS IS" AND ANY EXPRESSED OR IMPLIED 
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

/** ****************************************************************************
** @paragraph
** <b> Revision History: </b><br>
**
** Revision: 2.0.0  26-Sep-2017   B. Sweet
** - Removed System_Init() and System_Task().
** - Added printProductName() and printVersionNumber().
** - Replaced "Forever" loop [for ( ; ; ) ] with
**   do{}while (HMI_Prompt_ContinueState() == TRUE);
**
** Revision: 1.8.0  18-Mar-2017   B. Sweet
** - Applied ESBOK file format.
**
** Revision: 1.7    16-May-2013   B. Sweet
** - Update comment blocks for Doxygen.
**
** Revision: 1.6    26-May-2012   B. Sweet
** - Move #includes and prototypes to main.h for consistency.
**
** Revision: 1.5    04-May-2012   B. Sweet
** - Add multiple rate System Tasks: 1 ms, 5 ms, 10 ms.
**
** Revision: 1.4    21-Apr-2012   B. Sweet
** - Replace "Dumb" Wait loop with Task Timer.
** - Adjust Path for Driver components (TARGET_S12UB).
**
** Revision: 1.3    26-Sep-2010   B. Sweet
** - For TARGET_PC, before "forever" loop call IO_Mgr_OutputTask() to display
**   initial values for system states, inputs, and outputs.
**
** Revision: 1.2    11-Sep-2010   B. Sweet
** - Add Keyboard Simulation components.
** - Add MMC (Main Machine Controller) application component.
**
** Revision: 1.1    10-Jun-2008   B. Sweet
** - In main(), added varialble "wait" loop after calling System_Task() to 
**   allow for time to pass between Task iterations.
**
** Revision: 1.0     6-Jun-2008   B. Sweet
** - Working baseline.
**
*******************************************************************************/

/******************************************************************************
* Includes
*******************************************************************************/
    #include "main.h"
    #include <stdio.h>

   /*
   ** Access to System components:
   */
    #include "_Version\version.h"
    #include "app\HMI\Hmi.h"


/** @addtogroup PROJ_SD1
 *  @{
 */

/** @addtogroup MAIN
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

/*******************************************************************************
* Module Private Function Prototypes
*******************************************************************************/

/*******************************************************************************
* Module Private Function Definitions
*******************************************************************************/

/*******************************************************************************
* Module Public Function Definitions
*******************************************************************************/


/*******************************************************************************
* Module Public Function Definitions
*******************************************************************************/
/** ****************************************************************************
** @function  main()
**
** @brief <b> Function Description: </b><br>
** - System initialization and "forever" loop.
**
********************************************************************************
** PRE-CONDITIONS:
** - \todo  Update list of Pre-Conditions before executing main().
**
** POST-CONDITIONS:
** - none
**
** @param [in]      None
**
** @param [out]     None
**
** @param [in,out]  None
**
** @return          None
**
********************************************************************************
** @description <b> Detailed Description: </b><br>
** main(): Main program loop.
** - Returns (void)
**
********************************************************************************
** <b> Usage Example: </b>
** @code
**    main();
**
** @endcode
**
********************************************************************************
** Called Functions:
** @see printProductName()
** @see printVersionNumber()
** @see HMI_Prompt_ContinueState()
**
*******************************************************************************/
void main(void)
{
   /*
   ** Local Variables:
   */

   /*
   ** Software Product & Version Identification:
   */
    printProductName();
    printVersionNumber();

   /*
   ** Loop while User wants to continue:
    */
   do
   {
       /*
       ** Put your own code here:
       */


   } while (HMI_Prompt_ContinueState() == TRUE);

   /* Wait for "Enter" key to end the program */
 #if(0)
   printf("\nPress \"Enter\" key to end...");
   fflush(stdin);
   getchar();
 #else
   system("PAUSE");
 #endif

} /* End: main() */


/**
 * @}
 */ // group MAIN

/**
 * @}
 */ // group PROJ_SD1

/******************************* END OF FILE **********************************/
