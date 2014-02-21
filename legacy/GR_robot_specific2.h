#pragma systemFile								// treat as system file to eliminate warnings for unused variables
//
//============================================================
// Define sensor multiplexor connectivity and port allocat ions
//============================================================
//const tMUXSensor HTIRS2 = msensor_S2_4;     // HiTechnic Infrared sensor
////const tMUXSensor LEGOLS = msensor_S2_2;			// LEGO light sensor
//const tMUXSensor LEGOUS = msensor_S2_1;			// LEGO sonar sensor (side mounted)
//const tMUXSensor LEGOUS2 = msensor_S2_3;		// LEGO sonar sensor (rear mounted)
//const tMUXSensor HTGYRO = msensor_S3_3;			// HiTechnic GYRO sensor
//const tMUXSensor HTIRS2_2 = msensor_S4_1;     // HiTechnic Infrared sensor

//==============================================================
// Misc
//==============================================================
#define UP true
#define DOWN false
int IRside;
int leftAngle;
int rightAngle;

//==============================================================
// Conveniently pre-defined servo positions
//==============================================================
#define WRIST_CLOSED 245
#define WRIST_OPEN 130
#define SHOULDER_DOWN 255
#define SHOULDER_UP 0
#define RIGHT_GRIPPER_START 50
#define RIGHT_GRIPPER_MID 140
#define RIGHT_GRIPPER_UP 240
#define LEFT_GRIPPER_START 180
#define LEFT_GRIPPER_MID 90
#define LEFT_GRIPPER_UP 0
#define GRIPPER_JOG_SIZE 10

//==============================================================
// Autonomous return options
//==============================================================
#define STOP 0
#define RED 1
#define BLUE 2
//=========================================================
// Define common sensor related storage and constants
//=========================================================
const float IR_PROPORTION = 100;
const long GYRO_PROPORTION = 5;
const long SONAR_PROPORTION = 3;
const long ROTATION_GAIN = 2;
const int light_threshold = 46;				// the switchpoint on the light sensor for detecting lines // was 36
const int RotationSpeed = 30;					// the default speed used to rotate the robot
const int RotationSpeedFast = 45;
int calibrate = 0;										// used to initiate the GYRO calibration cycle
float rawgyro = 0;										// the raw (analog) reading from the GYOR sensor (typically 620 when stable)
int gyro_noise=0;											// the range of values observed during GYRO calibration (smaller = better)
float constHeading=0;									// the live robot orientation relative to the match start position
float relHeading=0;										// the robot orientation relative to the start of the current move
int bearingAC = 0;										// the raw bearing from the IR beacon (0=no signal, otherwise 1..5
int bearingAC2 = 0;
float IR_Bearing = 0.0;
//float IR_Bearing2 = 0.0; 							// the averaged bearing from the IR beacon (1...9, 5=straight ahead)
int light_normalised = 0;							// the normalised reading from the light sensor (0..100%)
int column = 0;												// the column number thought to be holding the IR beacon
int sonarRaw = 0, sonarLive = 0;			// raw and filtered data from side sonar sensor
int sonarRaw2 = 0, sonarLive2 = 0;		// raw and filtered data from rear sonar sensor
int acS[5];														// the five segment values read from IR sensor
int acS2[5];
bool ir_mux_status, gyro_mux_status;	// status of sensor multiplexors (true=BAD, false=GOOD)
int lifter_speed=0;										// workspace for controlling lifter speed in state machine
int lifter_state;											// control variable for lifter state machine
bool Joy1Enabled = false;
bool Joy2Enabled = false;
float drive_speed;
float drive_angle;
bool wristPosition = false;
bool passedLine = false;
int fieldRed = 0;

//=============================================================
// Define user configurable parameters
//=============================================================
int MissionNumber = 1;				// the program desired to be run
int Start_Delay = 0;					// the time in seconds before the robot starts to move
int gyroCalTime = 5;					// the number of seconds for which we calibrate the GYRO

//==============================================================
// Define screen related variables
//==============================================================
const int MAXMISSIONS=22;							// the maximum number of selectable missions
int RequestedScreen = 0;							// select screen to be displayed at startup
int CurrentScreen = 0;								// workspace to save currently displayed screen number
TNxtButtons button = kNoButton;				// workspace to read NXT button status

//======================================================================================
// Variables associated with the file used to save the GYRO calibration for Tele-Op mode
//======================================================================================
string sFileName = "gotrobot.txt";
TFileIOResult nIoResult;
TFileHandle hFileHandle;
int nFileSize = 100;
float Driver_Cal;
float drift;

//==================================================================================
//Physical mounted angles of each wheel.  This defines the effective drive direction
// when the corresponding wheel is driven at 100% power.  These values are used to
// calculate the power levels for holonomic drive
//===================================================================================
float LF_angle=225;
float RF_angle=315;
float LR_angle=135;
float RR_angle=45;

//==============================================================================
// Define the text to be displayed for each mission to assist the drive team
// There are two lines of text displayed for each mission
//==============================================================================
string MissionNames1 [] = {
	"NOT USED",
	"IR      ",
	"CENTER  ",
	"LEFT    ",
	"RIGHT   ",
	"IR      ",
	"CENTER  ",
	"LEFT    ",
	"RIGHT   ",
	"Defense ",
	"Defense ",
	"Opponent",
	"Opponent",
	"Opponent",
	"Opponent",
	"OponentL",
	"OponentL",
	"OponentL",
	"OponentL",
	"OponentL",
	"OponentL",
	"OponentL",
	"TEST23  "};

string MissionNames2 [] = {
	"NOT USED",
	"PEG     ",
	"PEG     ",
	"PEG     ",
	"PEG     ",
	"SECOND  ",
	"SECOND  ",
	"SECOND  ",
	"SECOND  ",
	"RIGHT   ",
	"LEFT    ",
	"IR      ",
	"CENTER  ",
	"LEFT    ",
	"RIGHT   ",
	"IR      ",
	"CENTER  ",
	"LEFT    ",
	"RIGHT   ",
	"ALY     ",
	"ALY     ",
	"ALY     ",
	"LINE2-W "};

string MissionNames3 [] = {
	"NOT USED",
	"LINE3-B ",
	"LINE3-C ",
	"LINE3-D ",
	"POSITION",
	"LINE3-F ",
	"LINE3-G ",
	"LINE3-H ",
	"LINE3-I ",
	"LINE3-J ",
	"LINE3-K ",
	"LINE3-L ",
	"LINE3-M ",
	"LINE3-N ",
	"LINE3-O ",
	"LINE3-P ",
	"LINE3-Q ",
	"LINE3-R ",
	"LINE3-S ",
	"CENTER  ",
	"LEFT    ",
	"RIGHT   ",
	"LINE3-W "};
