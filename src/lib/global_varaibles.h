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

bool g_gyro_true = false;

//=========================================================
// Robot constants
//=========================================================

/**
*
*  @def INT_ANGLE_SENSOR_CIRCUMFERENCE
*     Tells the robot the circumference of the angle sensors wheel
*  @def FLOAT_ANGLE_SENSOR_CIRCUMFERENCE
*     Tells the robot the exact circumference of the angle sensors wheel
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
#define INT_ANGLE_SENSOR_CIRCUMFERENCE 18
#define FLOAT_ANGLE_SENSOR_CIRCUMFERENCE 17.6
#define DRIVE_WHEELS_CIRCUMFERENCE 26

#define GRABBER_LEFT_OPEN 3
#define GRABBER_RIGHT_OPEN 245
#define GRABBER_LEFT_MID 60
#define GRABBER_RIGHT_MID 180
#define GRABBER_LEFT_CLOSE 120
#define GRABBER_RIGHT_CLOSE 131

/**
*
* @var g_block_speed_down Tells the robot how fast to move the lift
*
* @var g_block_speed_up Tells the robot how fast to move the lift
*
* @var g_robot_lift_down Tells the robot how fast to move the sky hook
*
* @var g_robot_lift_up Tells the robot how fast to move the sky hook
*
* @var g_flag_speed_down Tells the robot how fast to move the flag lifter
*
* @var g_flag_speed_right Tells the robot how fast to move the flag lifter
*
* @var g_flag_speed_up Tells the robot how fast to move the flag lifter
*
* @var g_flag_speed_left Tells the robot how fast to move the flag lifter
*
* @var g_abdd_up Tells the robot how fast to move the abdd
*
* @var g_abdd_down Tells the robot how fast to move the abdd
*
* @var g_gyro_adjust Multiplyer for gyro adjust
*
*/

/**
 * @def g_block_speed_down Tells the robot how fast to move the block grabber down
 *
 * @def g_block_speed_up Tells the robot how fast to move the block grabber up
 *
 * @def g_robot_lift_down Tells the robot how fast to move the robot lft down
 *
 * @def g_robot_lift_up Tells the robot how fast to move the robot lift up
 *
 * @def g_flag_speed_down Tells the robot how fast to spin the flag lift to make the flag go down
 *
 * @def g_flag_speed_right Tells the robot how fast to spin the robot flag lift right
 *
 * @def g_flag_speed_up Tells the robot how fast to spin the robot flag to make the flag go up
 *
 * @def
 */
const int g_block_speed_down = -60;
const int g_block_speed_up = 100;

const int g_robot_lift_down = -40;
const int g_robot_lift_up = 100;

const int g_flag_speed_down = 90;
const int g_flag_speed_right = 20;
const int g_flag_speed_up = -90;
const int g_flag_speed_left = -20;

const int g_abdd_up = 10;
const int g_abdd_down = 235;

const int g_gyro_adjust = 10;

//=========================================================
// auto selection points
//=========================================================
/**
*  @enum e_auto_selection_points Tells the robot what part it is in the selection program
*  @var e_auto_selection_points::SELECTION_START_POINT
*     Tells the robot to go to this part in the selection program
*  @var e_auto_selection_points::SELECTION_START_DELAY
*     Tells the robot to go to this part in the selection program
*  @var e_auto_selection_points::SELECTION_MISSION_POINT
*     Tells the robot to go to this part in the selection program
*  @var e_auto_selection_points::SELECTION_MISSION_DELAY
*     Tells the robot to go to this part in the selection program
*  @var e_auto_selection_points::SELECTION_END_POINT
*     Tells the robot to go to this part in the selection program
*  @var e_auto_selection_points::SELECTION_SUB_GRABBERS
*     Tells the robot to go to this part in the selection program
*  @var e_auto_selection_points::SELECTION_GYRO_CAL
*     Tells the robot to go to this part in the selection program
*  @var e_auto_selection_points::SELECTION_SELECTION_TYPE
*     Tells the robot to go to this part in the selection program
*  @var e_auto_selection_points::SELECTION_GRAPH_NUMBER_INPUT
*     Tells the robot to go to this part in the selection program
*
*/

typedef enum
{
	SELECTION_START_POINT,
	SELECTION_START_DELAY,
	SELECTION_MISSION_POINT,
	SELECTION_MISSION_DELAY,
	SELECTION_END_POINT,
	SELECTION_SUB_GRABBERS,
	SELECTION_GYRO_CAL,
	SELECTION_SELECTION_TYPE,
	SELECTION_GRAPH_NUMBER_INPUT,
	SELECTION_QUICK_INPUT,
	SELECTION_SUB_RAMP
} e_auto_selection_points;

e_auto_selection_points g_auto_selection_point = SELECTION_START_POINT;

//=========================================================
// auto selection type options
//=========================================================
/**
*  @enum e_selection_types Lets the robot know how you wan to imploment the auto program
*  @var e_auto_selection_points::SELECTION_TYPE_NUMBER
*     Select a program by id
*  @var e_auto_selection_points::SELECTION_TYPE_CUSTOM
*     Select one of the custom programs
*  @var e_auto_selection_points::SELECTION_TYPE_QUICK
*     Select one of the most commenly used progams
*/
typedef enum
{
	SELECTION_TYPE_NUMBER,
	SELECTION_TYPE_CUSTOM,
	SELECTION_TYPE_QUICK
} e_selection_types;

e_selection_types selection_type = SELECTION_TYPE_CUSTOM;

//=========================================================
// auto sub selections
//=========================================================
/**
*  @enum e_direction Tells the robot to drive backwords or forwards onto the ramp
*  @var e_direction::SUB_SELECTION_GRABBERS_OUT
*     turn clockwise drive with the grabbers out
*  @var e_direction::SUB_SELECTION_GRABBERS_IN
*     turn counterclockwise drive with the grabbers in
*/

typedef enum
{
	SUB_SELECTION_GRABBERS_OUT,
	SUB_SELECTION_GRABBERS_IN
} e_auto_sub_selection;

e_auto_sub_selection g_auto_grabber_selections = SUB_SELECTION_GRABBERS_IN;

/**
*  @enum e_auto_sub_selection_ramp Tells the robot to drive onto the ramp and continue or stop
*  @var e_auto_sub_selection_ramp::SUB_SELECTION_RAMP_STOP
*     Stop on the ramp
*  @var e_auto_sub_selection_ramp::SUB_SELECTION_RAMP_CONTINUED
*     Continue on the ramp
*/

typedef enum
{
	SUB_SELECTION_RAMP_STOP,
	SUB_SELECTION_RAMP_CONTINUED
} e_auto_sub_selection_ramp;

e_auto_sub_selection_ramp g_auto_grabber_selection_ramp_options = SUB_SELECTION_RAMP_STOP;

//=========================================================
// auto movements
//=========================================================
int g_to_turn_dist = 0;

bool g_IR_angle_dist_complete = false;

const int g_forward_crate1_to_turn_dist = 135;
const int g_forward_crate2_to_turn_dist = 110;
const int g_forward_crate3_to_turn_dist = 60;
const int g_forward_crate4_to_turn_dist = 35;

const int g_backwards_crate1_to_turn_dist = 45;
const int g_backwards_crate2_to_turn_dist = 70;
const int g_backwards_crate3_to_turn_dist = 120;
const int g_backwards_crate4_to_turn_dist = 145;

//=========================================================
// Smoke test varaibles
//=========================================================

int g_smoke_test_num = 1;
int g_smoke_test_total = 12;
int g_smoke_run = false;
int g_test_value = 0;

//=========================================================
// auto number input variable
//=========================================================

int g_intput_array[6];

//=========================================================
// Misc
//=========================================================

bool LogData = false;
int step = 0;

int g_debug_time_1 = 0;
int g_debug_time_2 = 0;

int g_auto_ending_points = 4;
int g_travel_dist = 0;
int g_auto_starting_points = 4;
int g_auto_missions = 10;
int g_drive_heading = 0;
int g_ir_heading = 5;
bool g_program_done = false;

bool g_joy1_enabled = false;
bool g_joy2_enabled = false;

int g_selection_value = 0;

//=============================================================
// Define user configurable parameters
//=============================================================
int g_end_point = 1;
int g_start_point = 1;
int g_mission_number = 1;
int g_delay = 0;
int g_end_delay = 0;
int g_start_delay = 0;
int g_gyro_cal_time = 5;

//=============================================================
// Gyro variables
//=============================================================
int g_gyro_noise = 0;
long g_start_time = 0;
int g_drift = 0;
float g_const_heading = 0;
float g_rel_heading = 0;
long g_curr_time = 0;
long g_prev_time = 0;
int g_raw_gyro = 0;
int g_recont_heading = 0; //this is the recalculated const gyro heading

/**
* Sensor variables
*
* @var g_light_sensor
*	holds the value of the light sensor
*
* @var g_bearing_ac1
*	the raw value from the first IR sensor
*
* @var g_bearing_ac2
*	the raw value from the second IR sensor
*
* @var g_ir_bearing1
*	the calibrated value from the first IR sensor
*
* @var g_ir_bearing2
*	the calibrated value from the second IR sensor
*/
int g_light_sensor;
int g_bearing_ac1 = 0;
int g_bearing_ac2 = 0;
float g_ir_bearing1 = 0.0;
float g_ir_bearing2 = 0.0;
int g_acs1[5];
int g_acs2[5];
float g_curr_dir1 = 0.0;
float g_curr_dir2 = 0.0;
int g_misc = 0;
bool g_reset_angle = false;

//-----------------------------
// accelermoeter variables
//-----------------------------
int g_accelermoeter_sensor = 0;
int g_x_axis = 0;
int g_y_axis = 0;
int g_z_axis = 0;
const int g_target_angle = 110;
ubyte g_accelermoeter_reads = 0;
int g_accelermoeter_array [] = {0,1,2,3,4,5,6,7,8,9,10,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
ubyte g_accelermoeter_total_value = 0;
int g_accelermoeter_average = 0;

int g_sensor_num = 1;
int g_sensor_max = 4;
int g_sensor_value = 0;
int g_sensor_value2 = 0;
/**
*
*  @def ST_GYRO
*     The reference value for the sensor in smoke test
*  @def ST_IR
*     The reference value for the sensor in smoke test
*  @def ST_ACCELEROMETER
*     The reference value for the sensor in smoke test
*  @def ST_TILT
*     The reference value for the sensor in smoke test
*/

#define ST_GYRO 1
#define ST_IR 2
#define ST_ACCELEROMETER 3
#define ST_TILT 4

bool g_sensor_reference_drive = false;

string g_sensor_list [] = {
	"unknown ",
	"gyro    ",
	"IR   IR2",
	"accel   ",
	"tilt    "};

string g_basic_word_list [] = {
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
*  @def S_CLEAR
*     Tells the robot the screen state number for this screen statestate
*  @def S_MISSION
*     Tells the robot the screen state number for this screen statestate
*  @def S_DELAY
*     Tells the robot the screen state number for this screen statestate
*  @def S_CAL_TIME
*     Tells the robot the screen state number for this screen statestate
*  @def S_GYRO_CAL
*     Tells the robot the screen state number for this screen statestate
*  @def S_READY
*     Tells the robot the screen state number for this screen statestate
*  @def S_DELAY_WAIT
*     Tells the robot the screen state number for this screen statestate
*  @def S_GYRO_SHOW
*     Tells the robot the screen state number for this screen statestate
*  @def S_ERROR
*     Tells the robot the screen state number for this screen statestate
*  @def S_SMOKE_TEST
*     Tells the robot the screen state number for this screen statestate
*  @def S_SMOKE_RUN1
*     Tells the robot the screen state number for this screen statestate
*  @def S_SMOKE_RUN2
*     Tells the robot the screen state number for this screen statestate
*  @def S_SMOKE_RUN3
*     Tells the robot the screen state number for this screen statestate
*  @def S_SCREEN_CALL
*     Tells the robot the screen state number for this screen statestate
*  @def S_IR_SHOW
*     Tells the robot the screen state number for this screen statestate
*  @def S_AC_SHOW
*     Tells the robot the screen state number for this screen statestate
*  @def S_MISC_SHOW
*     Tells the robot the screen state number for this screen statestate
*  @def S_STARTING_POINT
*     Tells the robot the screen state number for this screen statestate
*  @def S_ENDING_POINT
*     Tells the robot the screen state number for this screen statestate
*  @def S_SELECTION_SUB_GRABBERS
*     Tells the robot the screen state number for this screen statestate
*  @def S_ANGLE_SHOW
*     Tells the robot the screen state number for this screen statestate
*  @def S_TIME_SHOW
*     Tells the robot the screen state number for this screen statestate
*  @def S_SELECTION_TYPE
*     Tells the robot the screen state number for this screen statestate
*  @def S_NUMBER_SELECTION
*     Tells the robot the screen state number for this screen statestate
*
*/

#define S_CLEAR 0
#define S_MISSION 1
#define S_DELAY 2
#define S_CAL_TIME 3
#define S_GYRO_CAL 4
#define S_READY 5
#define S_DELAY_WAIT 6
#define S_GYRO_SHOW 7
#define S_ERROR 8
#define S_SMOKE_TEST 9
#define S_SMOKE_RUN1 10
#define S_SMOKE_RUN2 11
#define S_SMOKE_RUN3 12
#define S_SCREEN_CALL 13
#define S_IR_SHOW 14
#define S_AC_SHOW 15
#define S_MISC_SHOW 16
#define S_STARTING_POINT 17
#define S_ENDING_POINT 18
#define S_SELECTION_SUB_GRABBERS 19
#define S_ANGLE_SHOW 20
#define S_TIME_SHOW 21
#define S_SELECTION_TYPE 22
#define S_NUMBER_SELECTION 23
#define S_SELECTION_SUB_RAMP 24
#define S_MISSION_SHOW 25
#define S_QUICK_SELECTION 26

int g_screen_state = 1;

//==============================================================
// Define graph selection variables
//==============================================================

int g_graph_selection_tab = 0;
long g_graph_selection_number = 10000;

//==============================================================
// Define error numbers
//==============================================================
/**
*
*  @def ERR_NONE
*     Tells the robot that theres no error
*  @def ERR_GYRO_CAL
*     Tells the robot that theres a error with the gyro calibrate
*  @def ERR_GYRO_MUX
*     Tells the robot that theres a error with the gyro mux
*  @def ERR_SENSOR_MUX
*     Tells the robot that theres a error with the sensor mux
*  @def ERR_JOYSTICKS
*     Tells the robot that theres a error with the joysticks
*  @def ERR_ACCELERMOETER
*     Tells the robot that theres a error with the accelermoeter
*
*/
#define ERR_NONE 0
#define ERR_GYRO_CAL 1
#define ERR_GYRO_MUX 2
#define ERR_SENSOR_MUX 3
#define ERR_JOYSTICKS 4
#define ERR_ACCELERMOETER 5

int g_error = 0;

typedef enum
{
	ERROR_NONLETHAL,
	ERROR_LETHAL
} e_error_types;

e_error_types g_error_type = ERROR_LETHAL;

//==============================================================================
// Define the text to be displayed for each starting point line 1
//==============================================================================
string g_starting_names1 [] = {
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
string g_starting_names2 [] = {
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
string g_ending_names1 [] = {
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
string g_ending_names2 [] = {
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
string g_mission_names1 [] = {
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
string g_mission_names2 [] = {
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
// Define the text to be displayed for quick selection
//==============================================================================
string g_quick_names1 [] = {
	"Unknown ",
	"S1 IR E1",
	"S1 IR E2",
	"Test 3  ",
	"Test 4  ",
	"Test 5  ",
	"Test 6  "};

string g_quick_names2 [] = {
	"Unknown ",
	"Test 1  ",
	"Test 2  ",
	"Test 3  ",
	"Test 4  ",
	"Test 5  ",
	"Test 6  "};

int g_quick_mission = 1;
int g_max_quick_missions = 6;

//==============================================================================
// Define the text to be displayed for the errors
//==============================================================================
string g_error_list1 [] = {
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

string g_error_list2 [] = {
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
string g_smoke_test1 [] = {
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
string g_smoke_test2 [] = {
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
