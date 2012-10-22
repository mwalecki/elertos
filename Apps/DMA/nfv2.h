#ifndef NFV2_H
#define NFV2_H

#ifdef __cplusplus
extern "C" {
#endif

#include <inttypes.h>			    
#include "nfv2_config.h"
#include "mycrc.h"

/*
* Command codes
*/
#define NF_COMMAND_ReadDeviceStatus		0x02
#define NF_COMMAND_ReadDeviceVitals		0x03

#define NF_COMMAND_SetDrivesMode		0x10
#define NF_COMMAND_SetDrivesSpeed		0x11
#define NF_COMMAND_SetDrivesCurrent		0x12
#define NF_COMMAND_SetDrivesPosition	0x13
#define NF_COMMAND_SetDrivesPWM			0x14
#define NF_COMMAND_SetDrivesMaxCurrent	0x15
#define NF_COMMAND_SetDrivesMaxSpeed	0x16
#define NF_COMMAND_SetDrivesMinPosition	0x17
#define NF_COMMAND_SetDrivesMaxPosition	0x18

#define NF_COMMAND_ReadDrivesPosition	0x1A
#define NF_COMMAND_ReadDrivesCurrent	0x1B
#define NF_COMMAND_SetDrivesMisc		0x1E
#define NF_COMMAND_ReadDrivesStatus		0x1F

#define NF_COMMAND_SetCurrentRegulator	0x40
#define NF_COMMAND_SetSpeedRegulator	0x41
#define NF_COMMAND_SetPositionRegulator	0x42

#define NF_COMMAND_SetServosMode		0x20
#define NF_COMMAND_SetServosPosition	0x21
#define NF_COMMAND_SetServosSpeed		0x22
#define NF_COMMAND_SetServosMaxSpeed	0x26
#define NF_COMMAND_SetServosMinPosition	0x27
#define NF_COMMAND_SetServosMaxPosition	0x28
#define NF_COMMAND_SetServosPositionAdj	0x29

#define NF_COMMAND_ReadServosPosition	0x2A
#define NF_COMMAND_ReadServosCurrent	0x2B
#define NF_COMMAND_SetServosMisc		0x2E
#define NF_COMMAND_ReadServosStatus		0x2F

#define NF_COMMAND_ReadDigitalInputs	0x30
#define NF_COMMAND_SetDigitalOutputs	0x31

#define NF_COMMAND_ReadAnalogInputs		0x3E

#define NF_COMMAND_ReadDistance			0x3D

#define NF_COMMAND_SetDisplayMode		0x50
#define NF_COMMAND_SetDisplayText		0x51
#define NF_COMMAND_SetDisplayBacklight	0x52

#define NF_DEFAULT_SetServosPosition	1500
#define NF_DEFAULT_SetServosMinPosition	1300
#define NF_DEFAULT_SetServosMaxPosition	1700
#define NF_DEFAULT_SetServosPositionAdj	0


// ########	Device
// ####		Read Status
#ifdef NF_BUFSZ_ReadDeviceStatus
typedef struct{
	#define NF_DATABYTES_ReadDeviceStatus		2
	int16_t data[NF_BUFSZ_ReadDeviceStatus];
	uint8_t addr[NF_BUFSZ_ReadDeviceStatus];
	uint8_t updated;
} NF_STRUCT_ReadDeviceStatus;
#endif
// ####		Read Vitals
#ifdef NF_BUFSZ_ReadDeviceVitals
typedef struct{
	#define NF_DATABYTES_ReadDeviceVitals		2
	int16_t data[NF_BUFSZ_ReadDeviceVitals];
	uint8_t addr[NF_BUFSZ_ReadDeviceVitals];
	uint8_t updated;
} NF_STRUCT_ReadDeviceVitals;
#endif

// ########	Drives
// ####		Set Mode
#ifdef NF_BUFSZ_SetDrivesMode
typedef struct{
	#define NF_DATABYTES_SetDrivesMode		1
	uint8_t data[NF_BUFSZ_SetDrivesMode];
	uint8_t addr[NF_BUFSZ_SetDrivesMode];
	uint8_t updated;
} NF_STRUCT_SetDrivesMode;
// ##		Possible Values
#define NF_DrivesMode_ERROR			0x00
#define NF_DrivesMode_MANUAL		0x01
#define NF_DrivesMode_SPEED			0x02
#define NF_DrivesMode_CURRENT		0x03
#define NF_DrivesMode_POSITION		0x04
#define NF_DrivesMode_PWM			0x05
#define NF_DrivesMode_SYNC_PWM0		0x10
#endif
// ####		Set Speed
#ifdef NF_BUFSZ_SetDrivesSpeed
typedef struct{
	#define NF_DATABYTES_SetDrivesSpeed		2
	int16_t data[NF_BUFSZ_SetDrivesSpeed];
	uint8_t addr[NF_BUFSZ_SetDrivesSpeed];
	uint8_t updated;
} NF_STRUCT_SetDrivesSpeed;
#endif
// ####		Set Current
#ifdef NF_BUFSZ_SetDrivesCurrent
typedef struct{
	#define NF_DATABYTES_SetDrivesCurrent	2
	int16_t data[NF_BUFSZ_SetDrivesCurrent];
	uint8_t addr[NF_BUFSZ_SetDrivesCurrent];
	uint8_t updated;
} NF_STRUCT_SetDrivesCurrent;
#endif
// ####		Set Position
#ifdef NF_BUFSZ_SetDrivesPosition
typedef struct{
	#define NF_DATABYTES_SetDrivesPosition	4
	int32_t data[NF_BUFSZ_SetDrivesPosition];
	uint8_t addr[NF_BUFSZ_SetDrivesPosition];
	uint8_t updated;
} NF_STRUCT_SetDrivesPosition;
#endif
// ####		Set PWM
#ifdef NF_BUFSZ_SetDrivesPWM
typedef struct{
	#define NF_DATABYTES_SetDrivesPWM		2
	int16_t data[NF_BUFSZ_SetDrivesPWM];
	uint8_t addr[NF_BUFSZ_SetDrivesPWM];
	uint8_t updated;
} NF_STRUCT_SetDrivesPWM;
#endif
// ####		Set Max Current
#ifdef NF_BUFSZ_SetDrivesMaxCurrent
typedef struct{
	#define NF_DATABYTES_SetDrivesMaxCurrent	2
	int16_t data[NF_BUFSZ_SetDrivesMaxCurrent];
	uint8_t addr[NF_BUFSZ_SetDrivesMaxCurrent];
	uint8_t updated;
} NF_STRUCT_SetDrivesMaxCurrent;
#endif
// ####		Set Max Speed
#ifdef NF_BUFSZ_SetDrivesMaxSpeed
typedef struct{
	#define NF_DATABYTES_SetDrivesMaxSpeed	2
	int16_t data[NF_BUFSZ_SetDrivesMaxSpeed];
	uint8_t addr[NF_BUFSZ_SetDrivesMaxSpeed];
	uint8_t updated;
} NF_STRUCT_SetDrivesMaxSpeed;
#endif
// ####		Set Min Position
#ifdef NF_BUFSZ_SetDrivesMinPosition
typedef struct{
	#define NF_DATABYTES_SetDrivesMinPosition	4
	int32_t data[NF_BUFSZ_SetDrivesMinPosition];
	uint8_t addr[NF_BUFSZ_SetDrivesMinPosition];
	uint8_t updated;
} NF_STRUCT_SetDrivesMinPosition;
#endif
// ####		Set Max Position
#ifdef NF_BUFSZ_SetDrivesMaxPosition
typedef struct{
	#define NF_DATABYTES_SetDrivesMaxPosition	4
	int32_t data[NF_BUFSZ_SetDrivesMaxPosition];
	uint8_t addr[NF_BUFSZ_SetDrivesMaxPosition];
	uint8_t updated;
} NF_STRUCT_SetDrivesMaxPosition;
#endif
// ####		Read Position
#ifdef NF_BUFSZ_ReadDrivesPosition
typedef struct{
	#define NF_DATABYTES_ReadDrivesPosition	4
	int32_t data[NF_BUFSZ_ReadDrivesPosition];
	uint8_t addr[NF_BUFSZ_ReadDrivesPosition];
	uint8_t updated;
} NF_STRUCT_ReadDrivesPosition;
#endif
// ####		Read Current
#ifdef NF_BUFSZ_ReadDrivesCurrent
typedef struct{
	#define NF_DATABYTES_ReadDrivesCurrent	2
	int16_t data[NF_BUFSZ_ReadDrivesCurrent];
	uint8_t addr[NF_BUFSZ_ReadDrivesCurrent];
	uint8_t updated;
} NF_STRUCT_ReadDrivesCurrent;
#endif
// ####		Set Misc
#ifdef NF_BUFSZ_SetDrivesMisc
typedef struct{
	#define NF_DATABYTES_SetDrivesMisc		4
	uint32_t data[NF_BUFSZ_SetDrivesMisc];
	uint8_t addr[NF_BUFSZ_SetDrivesMisc];
	uint8_t updated;
} NF_STRUCT_SetDrivesMisc;
// ##		Possible Values (bitwise OR)
#define NF_DrivesMisc_SetSynchronized		(1 << 0)
#define NF_DrivesMisc_ResetSynchronized		(1 << 1)
#endif
// ####		Read Status
#ifdef NF_BUFSZ_ReadDrivesStatus
typedef struct{
	#define NF_DATABYTES_ReadDrivesStatus	2
	uint16_t data[NF_BUFSZ_ReadDrivesStatus];
	uint8_t addr[NF_BUFSZ_ReadDrivesStatus];
	uint8_t updated;
} NF_STRUCT_ReadDrivesStatus;
// ##		Possible Values (bitwise OR)
#define NF_DrivesStatus_LimitSwitchUp		(1 << 0)
#define NF_DrivesStatus_LimitSwitchDown		(1 << 1)
#define NF_DrivesStatus_SynchroSwitch		(1 << 2)
#define NF_DrivesStatus_EncoderIndexSignal	(1 << 3)
#define NF_DrivesStatus_Synchronized		(1 << 4)
#define NF_DrivesStatus_PositionLimit		(1 << 10)
#define NF_DrivesStatus_SpeedLimit			(1 << 11)
#define NF_DrivesStatus_CurrentLimit		(1 << 12)
#define NF_DrivesStatus_Overcurrent			(1 << 13)
#define NF_DrivesStatus_PowerStageFault		(1 << 14)
#define NF_DrivesStatus_Error				(1 << 15)
#endif
	
// ########	Regulators
// ####		Set Current Regulator
//#if (defined NF_BUFSZ_SetCurrentRegulator) || (defined NF_BUFSZ_SetSpeedRegulator) || (defined NF_BUFSZ_SetPositionRegulator)
typedef struct{
	#define NF_DATABYTES_Regulator	8
	uint16_t	p;
	uint16_t	i;
	uint16_t	d;
	uint16_t	t;
} NF_STRUCT_Regulator;
//#endif
#ifdef NF_BUFSZ_SetCurrentRegulator
typedef struct{
	#define NF_DATABYTES_SetCurrentRegulator	8
	NF_STRUCT_Regulator data[NF_BUFSZ_SetCurrentRegulator];
	uint8_t addr[NF_BUFSZ_SetCurrentRegulator];
	uint8_t updated;
} NF_STRUCT_SetCurrentRegulator;
#endif
#ifdef NF_BUFSZ_SetSpeedRegulator
typedef struct{
	#define NF_DATABYTES_SetSpeedRegulator		8
	NF_STRUCT_Regulator data[NF_BUFSZ_SetSpeedRegulator];
	uint8_t addr[NF_BUFSZ_SetSpeedRegulator];
	uint8_t updated;
} NF_STRUCT_SetSpeedRegulator;
#endif
#ifdef NF_BUFSZ_SetPositionRegulator
typedef struct{
	#define NF_DATABYTES_SetPositionRegulator	8
	NF_STRUCT_Regulator data[NF_BUFSZ_SetPositionRegulator];
	uint8_t addr[NF_BUFSZ_SetPositionRegulator];
	uint8_t updated;
} NF_STRUCT_SetPositionRegulator;
#endif
	
// ########	Servos
// ####		Set Mode
#ifdef NF_BUFSZ_SetServosMode
typedef struct{
	#define NF_DATABYTES_SetServosMode		1
	uint8_t data[NF_BUFSZ_SetServosMode];
	uint8_t addr[NF_BUFSZ_SetServosMode];
	uint8_t updated;
} NF_STRUCT_SetServosMode;
#endif
// ####		Set Position
#ifdef NF_BUFSZ_SetServosPosition
typedef struct{
	#define NF_DATABYTES_SetServosPosition	2
	int16_t data[NF_BUFSZ_SetServosPosition];
	uint8_t addr[NF_BUFSZ_SetServosPosition];
	uint8_t updated;
} NF_STRUCT_SetServosPosition;
#endif
// ####		Set Speed
#ifdef NF_BUFSZ_SetServosSpeed
typedef struct{
	#define NF_DATABYTES_SetServosSpeed		2
	int16_t data[NF_BUFSZ_SetServosSpeed];
	uint8_t addr[NF_BUFSZ_SetServosSpeed];
	uint8_t updated;
} NF_STRUCT_SetServosSpeed;
#endif
// ####		Set Max Speed
#ifdef NF_BUFSZ_SetServosMaxSpeed
typedef struct{
	#define NF_DATABYTES_SetServosMaxSpeed	2
	int16_t data[NF_BUFSZ_SetServosMaxSpeed];
	uint8_t addr[NF_BUFSZ_SetServosMaxSpeed];
	uint8_t updated;
} NF_STRUCT_SetServosMaxSpeed;
#endif
// ####		Set Min Position
#ifdef NF_BUFSZ_SetServosMinPosition
typedef struct{
	#define NF_DATABYTES_SetServosMinPosition	2
	int16_t data[NF_BUFSZ_SetServosMinPosition];
	uint8_t addr[NF_BUFSZ_SetServosMinPosition];
	uint8_t updated;
} NF_STRUCT_SetServosMinPosition;
#endif
// ####		Set Max Position
#ifdef NF_BUFSZ_SetServosMaxPosition
typedef struct{
	#define NF_DATABYTES_SetServosMaxPosition	2
	int16_t data[NF_BUFSZ_SetServosMaxPosition];
	uint8_t addr[NF_BUFSZ_SetServosMaxPosition];
	uint8_t updated;
} NF_STRUCT_SetServosMaxPosition;
#endif
// ####		Set Position Adjustment
#ifdef NF_BUFSZ_SetServosPositionAdj
typedef struct{
	#define NF_DATABYTES_SetServosPositionAdj	2
	int16_t data[NF_BUFSZ_SetServosPositionAdj];
	uint8_t addr[NF_BUFSZ_SetServosPositionAdj];
	uint8_t updated;
} NF_STRUCT_SetServosPositionAdj;
#endif
// ####		Read Position
#ifdef NF_BUFSZ_ReadServosPosition
typedef struct{
	#define NF_DATABYTES_ReadServosPosition	2
	int16_t data[NF_BUFSZ_ReadServosPosition];
	uint8_t addr[NF_BUFSZ_ReadServosPosition];
	uint8_t updated;
} NF_STRUCT_ReadServosPosition;
#endif
// ####		Read Current
#ifdef NF_BUFSZ_ReadServosCurrent
typedef struct{
	#define NF_DATABYTES_ReadServosCurrent	2
	int16_t data[NF_BUFSZ_ReadServosCurrent];
	uint8_t addr[NF_BUFSZ_ReadServosCurrent];
	uint8_t updated;
} NF_STRUCT_ReadServosCurrent;
#endif
// ####		Set Misc
#ifdef NF_BUFSZ_SetServosMisc
typedef struct{
	#define NF_DATABYTES_SetServosMisc		4
	uint32_t data[NF_BUFSZ_SetServosMisc];
	uint8_t addr[NF_BUFSZ_SetServosMisc];
	uint8_t updated;
} NF_STRUCT_SetServosMisc;
// ##		Possible Values (bitwise OR)
#define NF_ServosMisc_LearnMinPosition		(1 << 0)
#define NF_ServosMisc_LearnMaxPosition		(1 << 1)
#endif
// ####		Read Status
#ifdef NF_BUFSZ_ReadServosStatus
typedef struct{
	#define NF_DATABYTES_ReadServosStatus	2
	uint16_t data[NF_BUFSZ_ReadServosStatus];
	uint8_t addr[NF_BUFSZ_ReadServosStatus];
	uint8_t updated;
} NF_STRUCT_ReadServosStatus;
// ##		Possible Values (bitwise OR)
#define NF_ServosStatus_PositionLimit		(1 << 10)
#define NF_ServosStatus_Error				(1 << 15)
#endif

// ########	Digital IO
// ####		Read Inputs
#ifdef NF_BUFSZ_ReadDigitalInputs
typedef struct{
	#define NF_DATABYTES_ReadDigitalInputs	1
	int16_t data[NF_BUFSZ_ReadDigitalInputs];
	uint8_t addr[NF_BUFSZ_ReadDigitalInputs];
} NF_STRUCT_ReadDigitalInputs;
#endif
// ####		Set Outputs
#ifdef NF_BUFSZ_SetDigitalOutputs
typedef struct{
	#define NF_DATABYTES_SetDigitalOutputs	1
	int8_t data[NF_BUFSZ_SetDigitalOutputs];
	uint8_t addr[NF_BUFSZ_SetDigitalOutputs];
	uint8_t updated;
} NF_STRUCT_SetDigitalOutputs;
#endif

// ########	Analog IO
// ####		Read Inputs
#ifdef NF_BUFSZ_ReadAnalogInputs
typedef struct{
	#define NF_DATABYTES_ReadAnalogInputs	2
	int16_t data[NF_BUFSZ_ReadAnalogInputs];
	uint8_t addr[NF_BUFSZ_ReadAnalogInputs];
	uint8_t updated;
} NF_STRUCT_ReadAnalogInputs;
#endif

// ########	Sensors
// ####		Read Distance
#ifdef NF_BUFSZ_ReadDistance
typedef struct{
	#define NF_DATABYTES_ReadDistance	2
	uint16_t data[NF_BUFSZ_ReadDistance];
	uint8_t addr[NF_BUFSZ_ReadDistance];
	uint8_t updated;
} NF_STRUCT_ReadDistance;
#endif

// ########	Display
// ####		Set Mode
#ifdef NF_BUFSZ_SetDisplayMode
typedef struct{
	#define NF_DATABYTES_SetDisplayMode	1
	uint8_t data[NF_BUFSZ_SetDisplayMode];
	uint8_t addr[NF_BUFSZ_SetDisplayMode];
	uint8_t updated;
} NF_STRUCT_SetDisplayMode;
#endif
// ####		Set Text
#ifdef NF_BUFSZ_SetDisplayText
typedef struct{
	#define NF_DATABYTES_SetDisplayText	1
	uint8_t data[NF_BUFSZ_SetDisplayText];
	uint8_t addr[NF_BUFSZ_SetDisplayText];
	uint8_t updated;
} NF_STRUCT_SetDisplayText;
#endif
// ####		Set Backlight
#ifdef NF_BUFSZ_SetDisplayBacklight
typedef struct{
	#define NF_DATABYTES_SetDisplayBacklight	1
	uint8_t data[NF_BUFSZ_SetDisplayBacklight];
	uint8_t addr[NF_BUFSZ_SetDisplayBacklight];
	uint8_t updated;
} NF_STRUCT_SetDisplayBacklight;
#endif

typedef struct{
	// ########	Device
	// ####		Read Status
	#ifdef NF_BUFSZ_ReadDeviceStatus
		NF_STRUCT_ReadDeviceStatus	ReadDeviceStatus;
	#endif
	// ####		Read Vitals
	#ifdef NF_BUFSZ_ReadDeviceVitals
		NF_STRUCT_ReadDeviceVitals	ReadDeviceVitals;
	#endif
	
	// ########	Drives
	// ####		Set Mode
	#ifdef NF_BUFSZ_SetDrivesMode
		NF_STRUCT_SetDrivesMode		SetDrivesMode;
	#endif
	// ####		Set Speed
	#ifdef NF_BUFSZ_SetDrivesSpeed
		NF_STRUCT_SetDrivesSpeed		SetDrivesSpeed;
	#endif
	// ####		Set Current
	#ifdef NF_BUFSZ_SetDrivesCurrent
		NF_STRUCT_SetDrivesCurrent	SetDrivesCurrent;
	#endif
	// ####		Set Position
	#ifdef NF_BUFSZ_SetDrivesPosition
		NF_STRUCT_SetDrivesPosition	SetDrivesPosition;
	#endif
	// ####		Set PWM
	#ifdef NF_BUFSZ_SetDrivesPWM
		NF_STRUCT_SetDrivesPWM	SetDrivesPWM;
	#endif
	// ####		Set Max Current
	#ifdef NF_BUFSZ_SetDrivesMaxCurrent
		NF_STRUCT_SetDrivesMaxCurrent	SetDrivesMaxCurrent;
	#endif
	// ####		Set Max Speed
	#ifdef NF_BUFSZ_SetDrivesMaxSpeed
		NF_STRUCT_SetDrivesMaxSpeed	SetDrivesMaxSpeed;
	#endif
	// ####		Set Min Position
	#ifdef NF_BUFSZ_SetDrivesMinPosition
		NF_STRUCT_SetDrivesMinPosition	SetDrivesMinPosition;
	#endif
	// ####		Set Max Position
	#ifdef NF_BUFSZ_SetDrivesMaxPosition
		NF_STRUCT_SetDrivesMaxPosition	SetDrivesMaxPosition;
	#endif
	// ####		Read Position
	#ifdef NF_BUFSZ_ReadDrivesPosition
		NF_STRUCT_ReadDrivesPosition	ReadDrivesPosition;
	#endif
	// ####		Read Current
	#ifdef NF_BUFSZ_ReadDrivesCurrent
		NF_STRUCT_ReadDrivesCurrent	ReadDrivesCurrent;
	#endif
	// ####		Set Misc
	#ifdef NF_BUFSZ_SetDrivesMisc
		NF_STRUCT_SetDrivesMisc	SetDrivesMisc;
	#endif
	// ####		Read Status
	#ifdef NF_BUFSZ_ReadDrivesStatus
		NF_STRUCT_ReadDrivesStatus	ReadDrivesStatus;
	#endif

	// ########	Regulators
	// ####		Set Current Regulator
	#ifdef NF_BUFSZ_SetCurrentRegulator
		NF_STRUCT_SetCurrentRegulator	SetCurrentRegulator;
	#endif
	// ####		Set Speed Regulator
	#ifdef NF_BUFSZ_SetSpeedRegulator
		NF_STRUCT_SetSpeedRegulator		SetSpeedRegulator;
	#endif
	// ####		Set Position Regulator
	#ifdef NF_BUFSZ_SetPositionRegulator
		NF_STRUCT_SetPositionRegulator	SetPositionRegulator;
	#endif

	// ########	Servos
	// ####		Set Mode
	#ifdef NF_BUFSZ_SetServosMode
		NF_STRUCT_SetServosMode		SetServosMode;
	#endif
	// ####		Set Position
	#ifdef NF_BUFSZ_SetServosPosition
		NF_STRUCT_SetServosPosition	SetServosPosition;
	#endif
	// ####		Set Speed
	#ifdef NF_BUFSZ_SetServosSpeed
		NF_STRUCT_SetServosSpeed		SetServosSpeed;
	#endif
	// ####		Set Max Speed
	#ifdef NF_BUFSZ_SetServosMaxSpeed
		NF_STRUCT_SetServosMaxSpeed	SetServosMaxSpeed;
	#endif
	// ####		Set Min Position
	#ifdef NF_BUFSZ_SetServosMinPosition
		NF_STRUCT_SetServosMinPosition	SetServosMinPosition;
	#endif
	// ####		Set Max Position
	#ifdef NF_BUFSZ_SetServosMaxPosition
		NF_STRUCT_SetServosMaxPosition	SetServosMaxPosition;
	#endif
	// ####		Set Position Adjustment
	#ifdef NF_BUFSZ_SetServosPositionAdj
		NF_STRUCT_SetServosPositionAdj	SetServosPositionAdj;
	#endif
	// ####		Read Position
	#ifdef NF_BUFSZ_ReadServosPosition
		NF_STRUCT_ReadServosPosition	ReadServosPosition;
	#endif
	// ####		Read Current
	#ifdef NF_BUFSZ_ReadServosCurrent
		NF_STRUCT_ReadServosCurrent	ReadServosCurrent;
	#endif
	// ####		Set Misc
	#ifdef NF_BUFSZ_SetServosMisc
		NF_STRUCT_SetServosMisc	SetServosMisc;
	#endif
	// ####		Read Status
	#ifdef NF_BUFSZ_ReadServosStatus
		NF_STRUCT_ReadServosStatus	ReadServosStatus;
	#endif
	
	// ########	Digital IO	 
	// ####		Read Inputs
	#ifdef NF_BUFSZ_ReadDigitalInputs
		NF_STRUCT_ReadDigitalInputs	ReadDigitalInputs;
	#endif
	// ####		Set Outputs
	#ifdef NF_BUFSZ_SetDigitalOutputs
		NF_STRUCT_SetDigitalOutputs	SetDigitalOutputs;
	#endif
	
	// ########	Analog IO
	// ####		Read Inputs
	#ifdef NF_BUFSZ_ReadAnalogInputs
		NF_STRUCT_ReadAnalogInputs	ReadAnalogInputs;
	#endif
	
	// ########	Sensors
	// ####		Read Distance
	#ifdef NF_BUFSZ_ReadDistance
		NF_STRUCT_ReadDistance	ReadDistance;
	#endif
	
	// ########	Display
	// ####		Set Mode
	#ifdef NF_BUFSZ_SetDisplayMode
		NF_STRUCT_SetDisplayMode	SetDisplayMode;
	#endif
	// ####		Set Text
	#ifdef NF_BUFSZ_SetDisplayText
		NF_STRUCT_SetDisplayText	SetDisplayText;
	#endif
	// ####		Set Backlight
	#ifdef NF_BUFSZ_SetDisplayBacklight
		NF_STRUCT_SetDisplayBacklight	SetDisplayBacklight;
	#endif

	// ########	Common Fields
	uint8_t myAddress;

	uint8_t dataReceived			:1;
	uint8_t unknownCommandReceived	:1;
	uint8_t unknownCommandRequested	:1;
	uint8_t error					:1;
} NF_STRUCT_ComBuf;



uint8_t NF_Interpreter(NF_STRUCT_ComBuf *NFComBuf, uint8_t *rxBuf, uint8_t *rxPt, uint8_t *commandArray, uint8_t *commandCnt);
uint8_t NF_MakeCommandFrame(NF_STRUCT_ComBuf *NFComBuf, uint8_t *txBuf, const uint8_t *commandArray, uint8_t commandCnt, uint8_t addr);
void NF_ComBufReset(NF_STRUCT_ComBuf *NFComBuf);
void NFv2_Config(NF_STRUCT_ComBuf *NFComBuf, uint8_t myAddress);

#ifdef __cplusplus
}
#endif

#endif //NFV2_H
