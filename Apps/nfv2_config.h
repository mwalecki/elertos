/*
* External config file.
* Uncomment and update buffers' size [no of param set instances] for commands
* to be supported by module:
*/

#define NF_BroadcastAddress 0
#define NF_RobotAddress     0x01
#define NF_TerminalAddress  123

/*
* Uncomment and update buffers' size [no of param set instances] for commands
* to be supported by module:
*/
	#define NF_BUFSZ_ReadDeviceStatus	8
	#define NF_BUFSZ_ReadDeviceVitals	8

	#define NF_BUFSZ_SetDrivesMode			8
//	#define NF_BUFSZ_SetDrivesSpeed			8
//	#define NF_BUFSZ_SetDrivesCurrent		8
//	#define NF_BUFSZ_SetDrivesPosition		8
	#define NF_BUFSZ_SetDrivesPWM			8
	#define NF_BUFSZ_SetDrivesMaxCurrent	8
	#define NF_BUFSZ_ReadDrivesCurrent		8
	#define NF_BUFSZ_ReadDrivesPosition		8
	#define NF_BUFSZ_SetDrivesMisc			8
	#define NF_BUFSZ_ReadDrivesStatus		8

//	#define NF_BUFSZ_SetServosMode		4
//	#define NF_BUFSZ_SetServosPosition	4
//	#define NF_BUFSZ_SetServosSpeed		4

//	#define NF_BUFSZ_SetDigitalOutputs	1
//	#define NF_BUFSZ_ReadDigitalInputs	1
//	#define NF_BUFSZ_ReadAnalogInputs	8

/*
* Remember to declare:
* extern NF_STRUCT_ComBuf	NFComBuf;
*/
