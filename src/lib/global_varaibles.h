#pragma systemFile // treat as system file to eliminate warnings for unused variables
/**
*
*  @file global_varaibles.h
*
*  @brief varaibles that are global
*
*  @param None n/a
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/
//
//============================================================
// Define sensor multiplexor connectivity and port allocations
//============================================================
const tMUXSensor HTIRS2 = msensor_S3_1;     // HiTechnic Infrared sensor
const tMUXSensor HTAC = msensor_S3_2;
const tMUXSensor HTGYRO = msensor_S2_1;	   // HiTechnic GYRO sensor
const tMUXSensor HTIRS2_2 = msensor_S3_3;     // HiTechnic Infrared sensor 2
//const tMUXSensor HTANG = msensor_S3_3;
const tMUXSensor LEGOLS = msensor_S3_4;

bool gyroTrue = false;

//=========================================================
// Robot constants
//=========================================================

/**
*
*  @def ANGLE_SENSOR_CIRCUMFERENCE
*     Tells the robot the circumference of the angle sensors wheel
*  @def DRIVE_WHEELS_CIRCUMFERENCE
*     Tells the robot the cercumference of the drive wheels
*  @def GRABBER_LEFT_OPEN
*     tells the robot where the left block grabber needs to be to be open
*  @def GRABBER_RIGHT_OPEN
*     tells the robot where the right block grabber needs to be to be open
*  @def GRABBER_LEFT_MID
*     tells the robot where the left block grabber needs to be to be in the middle
*  @def GRABBER_RIGHT_MID
*     tells the robot where the right block grabber needs to be to be in the middle
*  @def GRABBER_LEFT_CLOSE
*     tells the robot where the left block grabber needs to be to be closed
*  @def GRABBER_RIGHT_CLOSE
*     tells the robot where the left block grabber needs to be to be closed
*
*/
#define ANGLE_SENSOR_CIRCUMFERENCE 17.6
#define DRIVE_WHEELS_CIRCUMFERENCE 26

#define GRABBER_LEFT_OPEN 3
#define GRABBER_RIGHT_OPEN 245
#define GRABBER_LEFT_MID 60
#define GRABBER_RIGHT_MID 180
#define GRABBER_LEFT_CLOSE 120
#define GRABBER_RIGHT_CLOSE 131

const int BLOCK_SPEED_DOWN = -60;
const int BLOCK_SPEED_UP = 100;

const int ROBOT_LIFT_DOWN = -40;
const int ROBOT_LIFT_UP = 100;

const int FLAG_SPEED_DOWN = 90;
const int FLAG_SPEED_RIGHT = 20;
const int FLAG_SPEED_UP = -90;
const int FLAG_SPEED_LEFT = -20;

const int ABDD_UP = 10;
const int ABDD_DOWN = 235;

const int g_GYRO_ADJUST = 10;

//=========================================================
// auto selection points
//=========================================================

typedef enum
{
	SELECTION_START_POINT,
	SELECTION_START_DELAY,
	SELECTION_MISSION_POINT,
	SELECTION_MISSION_DELAY,
	SELECTION_END_POINT,
	SELECTION_SUB_GRABBERS,
	SELECTION_GYRO_CAL
} auto_selection_points;

auto_selection_points auto_selection_point = SELECTION_START_POINT;

//=========================================================
// auto sub selections
//=========================================================

typedef enum
{
	SUB_SELECTION_GRABBERS_OUT,
	SUB_SELECTION_GRABBERS_IN
} auto_sub_selection;

auto_sub_selection auto_grabber_selections = SUB_SELECTION_GRABBERS_IN;

//=========================================================
// auto movements
//=========================================================
int to_turn_dist = 0;
const int crate1_to_turn_dist = 135;
const int crate2_to_turn_dist = 110;
const int crate3_to_turn_dist = 60;
const int crate4_to_turn_dist = 35;

//=========================================================
// Smoke test varaibles
//=========================================================

int smoke_test_num = 1;
int smoke_test_total = 12;
int smoke_run = false;
int test_value = 0;

//=========================================================
// Misc
//=========================================================

int auto_ending_points = 4;
int travel_dist = 0;
int auto_starting_points = 4;
int auto_missions = 10;
int drive_heading = 0;
int IR_heading = 5;
bool program_done = false;

bool Joy1Enabled = false;
bool Joy2Enabled = false;

int selection_value = 0;

//=============================================================
// Define user configurable parameters
//=============================================================
int end_point = 1;
int start_point = 1;
int mission_number = 1;
int delay = 0;
int end_delay = 0;
int start_delay = 0;
int gyroCalTime = 5;

//=============================================================
// Gyro variables
//=============================================================
int gyro_noise = 0;
long starttime = 0;
int drift = 0;
float constHeading = 0;
float relHeading = 0;
long currtime = 0;
long prevtime = 0;
int rawgyro = 0;
int recont_heading = 0; //this is the recalculated const gyro heading

//=============================================================
// Sensor variables
//=============================================================
const int ac_time_limit = 200;
int bearingAC = 0;
int bearingAC2 = 0;
float IR_Bearing = 0.0;
float IR_Bearing2 = 0.0;
int acS[5];
int acS2[5];
float currDir = 0.0;
float currDir2 = 0.0;
int misc = 0;
bool reset_angle = false;

//-----------------------------
// accelermoeter variables
//-----------------------------
int accelermoeter_sensor = 0;
int _x_axis = 0;
int _y_axis = 0;
int _z_axis = 0;
const int target_angle = 110;
ubyte accelermoeter_reads = 0;
int accelermoeter_array [] = {0,1,2,3,4,5,6,7,8,9,10,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
ubyte accelermoeter_total_value = 0;
int accelermoeter_average = 0;

int sensor_num = 1;
int sensor_max = 4;
int sensor_value = 0;
/**
*
*  @def st_gyro
*     The reference value for the sensor in smoke test
*  @def st_IR
*     The reference value for the sensor in smoke test
*  @def st_accelerometer
*     The reference value for the sensor in smoke test
*  @def st_tilt
*     The reference value for the sensor in smoke test
*/

#define st_gyro 1
#define st_IR 2
#define st_accelerometer 3
#define st_tilt 4

bool sensor_reference_drive = false;

string sensor_list [] = {
	"unknown ",
	"gyro    ",
	"IR      ",
	"accel   ",
	"tilt    "};

	string basic_word_list [] = {
	"unknown ",
	"in      ",
	"out     ",
	"yes     ",
	"no      "};

//=============================================================
// Define screen related variables
//=============================================================
/**
*
*  @def s_clear
*     Tells the robot the screen state number for this screen statestate
*  @def s_mission
*     Tells the robot the screen state number for this screen statestate
*  @def s_delay
*     Tells the robot the screen state number for this screen statestate
*  @def s_cal_time
*     Tells the robot the screen state number for this screen statestate
*  @def s_gyro_cal
*     Tells the robot the screen state number for this screen statestate
*  @def s_ready
*     Tells the robot the screen state number for this screen statestate
*  @def s_delay_wait
*     Tells the robot the screen state number for this screen statestate
*  @def s_gyro_show
*     Tells the robot the screen state number for this screen statestate
*  @def s_error
*     Tells the robot the screen state number for this screen statestate
*  @def s_smoke_test
*     Tells the robot the screen state number for this screen statestate
*  @def s_smoke_run1
*     Tells the robot the screen state number for this screen statestate
*  @def S_smoke_run2
*     Tells the robot the screen state number for this screen statestate
*  @def S_smoke_run3
*     Tells the robot the screen state number for this screen statestate
*  @def s_screen_call
*     Tells the robot the screen state number for this screen statestate
*  @def s_IR_show
*     Tells the robot the screen state number for this screen statestate
*  @def s_ac_show
*     Tells the robot the screen state number for this screen statestate
*  @def s_misc_show
*     Tells the robot the screen state number for this screen statestate
*  @def s_starting_point
*     Tells the robot the screen state number for this screen statestate
*  @def s_ending_point
*     Tells the robot the screen state number for this screen statestate
*
*/

#define s_clear 0
#define s_mission 1
#define s_delay 2
#define s_cal_time 3
#define s_gyro_cal 4
#define s_ready 5
#define s_delay_wait 6
#define s_gyro_show 7
#define s_error 8
#define s_smoke_test 9
#define s_smoke_run1 10
#define S_smoke_run2 11
#define S_smoke_run3 12
#define s_screen_call 13
#define s_IR_show 14
#define s_ac_show 15
#define s_misc_show 16
#define s_starting_point 17
#define s_ending_point 18
#define s_selection_sub_grabbers 19
#define s_angle_show 20

int screen_state = 1;

//==============================================================
// Define error numbers
//==============================================================
/**
*
*  @def err_none
*     Tells the robot that theres no error
*  @def err_gyro_cal
*     Tells the robot that theres a error with the gyro calibrate
*  @def err_gyro_mux
*     Tells the robot that theres a error with the gyro mux
*  @def err_sensor_mux
*     Tells the robot that theres a error with the sensor mux
*  @def err_joysticks
*     Tells the robot that theres a error with the joysticks
*  @def err_accelermoeter
*     Tells the robot that theres a error with the accelermoeter
*
*/
#define err_none 0
#define err_gyro_cal 1
#define err_gyro_mux 2
#define err_sensor_mux 3
#define err_joysticks 4
#define err_accelermoeter 5

int error = 0;

//==============================================================================
// Define the text to be displayed for each starting point line 1
//==============================================================================
string StartingNames1 [] = {
	"        ",
	"S1      ",
	"S2      ",
	"S3      ",
	"S4  ",
	"Test 5  ",
	"Test 6  ",
	"Test 7  ",
	"Test 8  ",
	"Test 9  ",
	"Test 10 ",
	"Test 11 ",
	"Test 12 ",
	"Test 13 ",
	"Test 14 ",
	"Test 15 ",
	"Test 16 ",
	"Test 17 ",
	"Test 18 ",
	"Test 19 ",
	"Test 20 ",
	"Test 21 ",
	"Test 22 "};

//==============================================================================
// Define the text to be displayed for each starting point line 2
//==============================================================================
string StartingNames2 [] = {
	"        ",
	"        ",
	"Test 2  ",
	"Test 3  ",
	"Test 4  ",
	"Test 5  ",
	"Test 6  ",
	"Test 7  ",
	"Test 8  ",
	"Test 9  ",
	"Test 10 ",
	"Test 11 ",
	"Test 12 ",
	"Test 13 ",
	"Test 14 ",
	"Test 15 ",
	"Test 16 ",
	"Test 17 ",
	"Test 18 ",
	"Test 19 ",
	"Test 20 ",
	"Test 21 ",
	"Test 22 "};

//==============================================================================
// Define the text to be displayed for each ending point line 1
//==============================================================================
string EndingNames1 [] = {
	"        ",
	"Stop    ",
	"Ramp 1  ",
	"Ramp 2  ",
	"Test 4  ",
	"Test 5  ",
	"Test 6  ",
	"Test 7  ",
	"Test 8  ",
	"Test 9  ",
	"Test 10 ",
	"Test 11 ",
	"Test 12 ",
	"Test 13 ",
	"Test 14 ",
	"Test 15 ",
	"Test 16 ",
	"Test 17 ",
	"Test 18 ",
	"Test 19 ",
	"Test 20 ",
	"Test 21 ",
	"Test 22 "};

//==============================================================================
// Define the text to be displayed for each ending point line 2
//==============================================================================
string EndingNames2 [] = {
	"        ",
	"        ",
	"        ",
	"Test 3  ",
	"Test 4  ",
	"Test 5  ",
	"Test 6  ",
	"Test 7  ",
	"Test 8  ",
	"Test 9  ",
	"Test 10 ",
	"Test 11 ",
	"Test 12 ",
	"Test 13 ",
	"Test 14 ",
	"Test 15 ",
	"Test 16 ",
	"Test 17 ",
	"Test 18 ",
	"Test 19 ",
	"Test 20 ",
	"Test 21 ",
	"Test 22 "};

//==============================================================================
// Define the text to be displayed for each mission
//==============================================================================
string MissionNames1 [] = {
	"        ",
	"IR crate",
	"crate 4 ",
	"crate 3 ",
	"crate 2 ",
	"crate 1 ",
	"defence ",
	"Test 7  ",
	"Test 8  ",
	"Test 9  ",
	"Test 10 ",
	"Test 11 ",
	"Test 12 ",
	"Test 13 ",
	"Test 14 ",
	"Test 15 ",
	"Test 16 ",
	"Test 17 ",
	"Test 18 ",
	"Test 19 ",
	"Test 20 ",
	"Test 21 ",
	"Test 22 "};

//==============================================================================
// Define the text to be displayed on the second line for each mission
//==============================================================================
string MissionNames2 [] = {
	"        ",
	"Test 1  ",
	"Test 2  ",
	"Test 3  ",
	"Test 4  ",
	"Test 5  ",
	"score 4 ",
	"score 3 ",
	"Test 8  ",
	"Test 9  ",
	"Test 10 ",
	"Test 11 ",
	"Test 12 ",
	"Test 13 ",
	"Test 14 ",
	"Test 15 ",
	"Test 16 ",
	"Test 17 ",
	"Test 18 ",
	"Test 19 ",
	"Test 20 ",
	"Test 21 ",
	"Test 22 "};

//==============================================================================
// Define the text to be displayed for the errors
//==============================================================================
string error_list1 [] = {
	"Unknown ",
	"GyroCal ",
	"Gyro    ",
	"Sensor  ",
	"joystick",
	"Test 5  ",
	"Test 6  ",
	"Test 7  ",
	"Test 8  ",
	"Test 9  ",
	"Test 10 ",
	"Test 11 ",
	"Test 12 ",
	"Test 13 ",
	"Test 14 ",
	"Test 15 ",
	"Test 16 ",
	"Test 17 ",
	"Test 18 ",
	"Test 19 ",
	"Test 20 ",
	"Test 21 ",
	"Test 22 "};

string error_list2 [] = {
	"error   ",
	"Failure ",
	"Mux     ",
	"Mux     ",
	"fail    ",
	"Test 5  ",
	"Test 6  ",
	"Test 7  ",
	"Test 8  ",
	"Test 9  ",
	"Test 10 ",
	"Test 11 ",
	"Test 12 ",
	"Test 13 ",
	"Test 14 ",
	"Test 15 ",
	"Test 16 ",
	"Test 17 ",
	"Test 18 ",
	"Test 19 ",
	"Test 20 ",
	"Test 21 ",
	"Test 22 "};

//==============================================================================
// Define the text to be displayed for smoke test line 1
//==============================================================================
string smoke_test1 [] = {
	"Unknown ",
	"Jolly   ",
	"Drive   ",
	"Sensor  ",
	"Block   ",
	"Grabbers",
	"sky hook",
	"roger   ",
	"Test 8  ",
	"Test 9  ",
	"Test 10 ",
	"Test 11 ",
	"Test 12 ",
	"Test 13 ",
	"Test 14 ",
	"Test 15 ",
	"Test 16 ",
	"Test 17 ",
	"Test 18 ",
	"Test 19 ",
	"Test 20 ",
	"Test 21 ",
	"Test 22 "};

//==============================================================================
// Define the text to be displayed for smoke test line 2
//==============================================================================
string smoke_test2 [] = {
	"Unknown ",
	"Roger   ",
	"Train   ",
	"Sensor  ",
	"Lift    ",
	"        ",
	"        ",
	"slide   ",
	"Test 8  ",
	"Test 9  ",
	"Test 10 ",
	"Test 11 ",
	"Test 12 ",
	"Test 13 ",
	"Test 14 ",
	"Test 15 ",
	"Test 16 ",
	"Test 17 ",
	"Test 18 ",
	"Test 19 ",
	"Test 20 ",
	"Test 21 ",
	"Test 22 "};
