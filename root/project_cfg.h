/** ****************************************************************************
** @brief
** <h2>COPYRIGHT &copy; 2017 ESBOK, All Rights Reserved </h2>
**
** The above copyright notice, subsequent disclaimer and any permission notice
** shall be included in all copies or substantial portions of the Template. 
**
*******************************************************************************/

/** ****************************************************************************
** @brief Title          Project Configuration file
** @file                 project_cfg.h
** @author               Benjamin D. Sweet, Teknowledge LLC, ESBOK
** @date                 03/18/2017
** @version              1.4.1
**
** Module Description:
** @brief
**  - Definition of overal project settings, such as DEBUG.
**  - Mapping of Applicaiton Generic inputs, outputs, and other parameters to
**    target specific resources
**
** @attention <b>DISCLAIMER:</b>
** THIS SOFTWARE IS PROVIDED BY ESBOK "AS IS" AND ANY EXPRESSED OR IMPLIED 
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
#ifndef _PROJECT_CFG_H_
#define _PROJECT_CFG_H_

/** ****************************************************************************
** @paragraph
** <b> Revision History: </b><br>
**
** Revision: 1.4.1  18-Mar-2017   B. Sweet
** - Applied ESBOK file format.
**
** Revision: 1.4    29-Oct-2012   Gabriel Moreno & Leonardo Bueno
** * Included definitions for Target STM32F4 Discovery Board.
**
** Revision: 1.3    06-Jun-2012   B. Sweet
** * Moved definition of InterruptEnable() to mcu_cfg.h.
**
** Revision: 1.2    05-May-2012   B. Sweet
** * Added conditional switch for MICROCONTROLLER_SIM.
**
** Revision: 1.1    20-Jun-2008   B. Sweet
** * Added conditional switch for MXVDEV.
**
** Revision: 1.0    06-Jun-2008   B. Sweet
** * Working prototype for S12UB and PC Target environments.

**
*******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

/*******************************************************************************
* Includes
*******************************************************************************/

/** @addtogroup PROJ_SD1
 *  @{
 */

/** @addtogroup MAIN
 *  @{
 */

/*******************************************************************************
* Module Public Typedefs
*******************************************************************************/

/*******************************************************************************
* Module Public Preprocessor Constants
*******************************************************************************/
/*
** DEBUG option:
**  xDEBUG - For Production (i.e.: NO DEBUG)
**   DEBUG - For Debug
*/
#ifndef MXVDEV  /* DEBUG is defined in the MxVDev project */
  #define DEBUG
#endif

/*
** Define the desired target
**
** Note: The TARGET symbol could be defined in a "Build Script", compiler configuration, or some other means.
**
**       The symbol MXVDEV is defined by the MxVDev Visual Studio project. 
*/

#define xTARGET_S12UB
#define xTARGET_STM32F4
#define TARGET_PC

/*
** Microcontroller Simulation:
**  For Microcontroller Targets, this switch can be used to customize port register
**  configuration for hardware simulaiton environments (such as HC12 Full Chip Simulation).
*/
#if (defined(TARGET_S12UB) || defined(TARGET_STM32F4))
 #define xMICROCONTROLLER_SIM
#endif /* TARGET */

/*
** UPDATE this list as new targets are added
*/
#if (!defined(TARGET_S12UB) && !defined(TARGET_PC) && !defined(TARGET_STM32F4))
   #error "A Target must be specified in project_cfg.h."
#endif


/*
** Project-level Definitions and Configurations: 
*/

/*
** Target Specifc Configurations:
*/

#ifndef MXVDEV
 #if defined TARGET_S12UB
 /*
 ** Target is S12 University Board:
 */
   /*
   ** Target Specific Include files:
   */
   #include <hidef.h>      /* common defines and macros */
   #include <mc9s12dg128.h>     /* derivative information */
   #pragma LINK_INFO DERIVATIVE "mc9s12dg128b"
	 
 #elif defined TARGET_STM32F4
 /*
 ** Target is STM32F4 Discovery Board:
 */
   /*
   ** Target Specific Include files:
   */
   #include "drv\drv_STM32F407\mcu\Utilities\STM32F4-Discovery\stm32f4_discovery.h"     /* derivative information */
	 
	#ifndef DIO_ACTIVE
    #define DIO_ACTIVE			/* Configure General Purpose Digital Input/Output ports */
	#endif
	
	#ifndef ADC_ACTIVE
		#define  xADC_ACTIVE 		/* Configure Analog to Digital Converter ports */
	#endif
	
	#ifndef PWM_ACTIVE
		#define xPWM_ACTIVE			/* Configure Pulse Widht Modulation Timers */
	#endif
	
	#ifndef SENSOR_ACTIVE
		#define SENSOR_ACTIVE		/* Configure External Digital Sensors */
	#endif
	
	#ifndef USB_FLASH_DRIVE_ACTIVE
		#define USB_FLASH_DRIVE_ACTIVE	/* Configure USB Flash Drive commands */
	#endif
	
	#ifndef SERIAL_ACTIVE
		#define SERIAL_ACTIVE		/* Configure Serial ports */
	#endif

	#ifndef GPS_ACTIVE
		#ifdef SERIAL_ACTIVE
			#define GPS_ACTIVE		/* Configure GPS Acquisition */
		#else
			#error "Serial communication must be activated in project_cfg.h."
		#endif
	#endif

 #elif defined TARGET_PC
 /*
 ** Target is PC:
 */
   /*
   ** Target Specific Include files:
   */
// #include "main.h"

   /*
   ** Target-specific mapping to Input and Output Ports & Registers:  
   */
   #define OutputPort   (PortA.byte)
   #define InputPort    (PortB.byte)

   #define PORTA (PortA.byte)
   #define PA0   (PortA.bit.Bit0)
   #define PA1   (PortA.bit.Bit1)
   #define PA2   (PortA.bit.Bit2)
   #define PA3   (PortA.bit.Bit3)
   #define PA4   (PortA.bit.Bit4)
   #define PA5   (PortA.bit.Bit5)
   #define PA6   (PortA.bit.Bit6)
   #define PA7   (PortA.bit.Bit7)

   #define PORTB (PortB.byte)
   #define PB0   (PortB.bit.Bit0)
   #define PB1   (PortB.bit.Bit1)
   #define PB2   (PortB.bit.Bit2)
   #define PB3   (PortB.bit.Bit3)
   #define PB4   (PortB.bit.Bit4)
   #define PB5   (PortB.bit.Bit5)
   #define PB6   (PortB.bit.Bit6)
   #define PB7   (PortB.bit.Bit7)

 #endif /* TARGET */
#endif /* MXVDEV */

/**
 * @}
 */ // group MAIN

/**
 * @}
 */ // group PROJ_SD1

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* _PROJECT_CFG_H_ */

/******************************* END OF FILE **********************************/
