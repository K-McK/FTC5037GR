#pragma systemFile // treat as system file to eliminate warnings for unused variables
/**
*
*  @file global_varaibles.h
*
*  @brief varaibles that are global
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
const tMUXSensor HTANG = msensor_S3_3;
const tMUXSensor LEGOLS = msensor_S3_4;

bool gyroTrue = false;

//=========================================================
// Robot constants
//=========================================================

#define ANGLE_SENSOR_CIRCUMFERENCE 17.6
#define DRIVE_WHEELS_CIRCUMFERENCE 26
#define GRABBER_OPEN 1
#define GRABBER_MID 2
#define GRABBER_CLOSE 3
#define GRABBER_POS_RIGHT_CLOSE 4
#define GRABBER_POS_RIGHT_OPEN 5
#define GRABBER_POS_LEFT_CLOSE 6
#define GRABBER_POS_LEFT_OPEN 7


#define GRABBER_LEFT_OPEN 0
#define GRABBER_RIGHT_OPEN 255
#define GRABBER_LEFT_MID 50
#define GRABBER_RIGHT_MID 180
#define GRABBER_LEFT_CLOSE 180
#define GRABBER_RIGHT_CLOSE 100

const int BLOCK_SPEED_DOWN = -60;
const int BLOCK_SPEED_UP = 100;

const int ROBOT_LIFT_DOWN = -40;
const int ROBOT_LIFT_UP = 100;

const int FLAG_SPEED_DOWN = -90;
const int FLAG_SPEED_RIGHT = -20;
const int FLAG_SPEED_UP = 90;
const int FLAG_SPEED_LEFT = 20;

const int ABDD_UP = 10;
const int ABDD_DOWN = 235;

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

int auto_missions = 4;
int drive_heading = 0;
int IR_heading = 5;
bool program_done = false;

bool Joy1Enabled = false;
bool Joy2Enabled = false;

int selection_value = 0;

//=============================================================
// Define user configurable parameters
//=============================================================
int mission_number = 1;
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
float IR_Bearing = 0.0;
int acS[5];
float currDir = 0.0;
int misc = 0;

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

//-----------------------------
// misc
//-----------------------------
int sensor_num = 1;
int sensor_max = 4;
int sensor_value = 0;

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

//=============================================================
// Define screen related variables
//=============================================================
#define s_clear 0
#define s_mission 1
#define s_start_delay 2
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

int screen_state = 1;

//==============================================================
// Define error numbers
//==============================================================
#define e_none 0
#define e_gyro_cal 1
#define e_gyro_mux 2
#define e_sensor_mux 3
#define e_joysticks 4
#define e_accelermoeter 5

int error = 0;

//==============================================================================
// Define the text to be displayed for each mission
//==============================================================================
string MissionNames1 [] = {
	"        ",
	"IR test ",
	"Test 2 ",
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
// Define the text to be displayed on the second line for each mission
//==============================================================================
string MissionNames2 [] = {
	"        ",
	"IR test ",
	"Motor Test  ",
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
	"Lift    ",
	"Servos  ",
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
// Define the text to be displayed for smoke test line 2
//==============================================================================
string smoke_test2 [] = {
	"Unknown ",
	"Roger   ",
	"Train   ",
	"Sensor  ",
	"        ",
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
