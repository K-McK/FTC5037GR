#pragma systemFile // treat as system file to eliminate warnings for unused variables
/**
*
*  @file global_variables.h
*
*  @brief varaibles that are global
*
*  @param None n/a
*
*  @return \
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
const tMUXSensor LEGOLS = msensor_S3_4;

/**
* @var g_gyro_true
*		Tells the robot if it should use the gyro or not
*/
bool g_gyro_true = false;

//#define DL_LOCATION (strcat(strcat((char*)__FILE__, ":"),(char*)__LINE__))

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
* 	@def LIGHT_SERVO_DOWN
* 		Tells the robot the poision of the light senser servo when its down
* 	@def LIGHT_SERVO_UP
* 		Tells the robot the poision of the light senser servo when its up
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

#define LIGHT_SERVO_DOWN 255
#define LIGHT_SERVO_UP 127

long g_angle_sensor_val = 0;

/**
*
* @var g_block_speed_down
* 		Tells the robot how fast to move the lift
*
* @var g_block_speed_up
* 		 Tells the robot how fast to move the lift
*
* @var g_robot_lift_down
* 		 Tells the robot how fast to move the sky hook
*
* @var g_robot_lift_up
* 		Tells the robot how fast to move the sky hook
*
* @var g_flag_speed_down
* 		Tells the robot how fast to move the flag lifter
*
* @var g_flag_speed_right
* 		Tells the robot how fast to move the flag lifter
*
* @var g_flag_speed_up
* 		 Tells the robot how fast to move the flag lifter
*
* @var g_flag_speed_left
* 		Tells the robot how fast to move the flag lifter
*
* @var g_abdd_up
* 		 Tells the robot how fast to move the abdd
*
* @var g_abdd_down
* 		Tells the robot how fast to move the abdd
*
* @var g_gyro_adjust
* 		Multiplyer for gyro adjust
*
* @var g_block_speed_down
* 		Tells the robot how fast to move the block grabber down
*
* @var g_block_speed_up
* 		Tells the robot how fast to move the block grabber up
*
* @var g_robot_lift_down
* 		Tells the robot how fast to move the robot lft down
*
* @var g_robot_lift_up
* 		Tells the robot how fast to move the robot lift up
*
* @var g_flag_speed_down
* 		Tells the robot how fast to spin the flag lift to make the flag go down
*
* @var g_flag_speed_right
* 		Tells the robot how fast to spin the robot flag lift right
*
* @var g_flag_speed_up
* 		Tells the robot how fast to spin the robot flag to make the flag go up
*
* @var g_flag_speed_left
* 		 Tells the robot how fast to spin the robot flag lift left
*
* @var g_abdd_up
* 		Tells the robot what position to put the servo when puting it up
*
* @var g_abdd_down
* 		Tells the robot what position to put the servo when puting it down
*
* @var g_gyro_adjust
* 		The Multiplyer for gyro calabration
*
* @var g_ground_arm_up
* 		Tells the robot where to put the ground arm when going up
*
* @var g_ground_arm_down
* 		Tells the robot where to put the ground arm when going down
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
int g_original_gyro_val = 0;

const int g_ground_arm_up = 0;

const int g_ground_arm_down = 120;

const int g_light_threshold = 30;

const int g_light_move_min_dist = 70;

//=========================================================
// auto selection points
//=========================================================
/**
* @enum e_auto_selection_points Tells the robot what part it is in the selection program
* @var e_auto_selection_points::SELECTION_START_POINT
*     Tells the robot to go to this part in the selection program
* @var e_auto_selection_points::SELECTION_START_DELAY
*     Tells the robot to go to this part in the selection program
* @var e_auto_selection_points::SELECTION_MISSION_POINT
*     Tells the robot to go to this part in the selection program
* @var e_auto_selection_points::SELECTION_MISSION_DELAY
*     Tells the robot to go to this part in the selection program
* @var e_auto_selection_points::SELECTION_END_POINT
*     Tells the robot to go to this part in the selection program
* @var e_auto_selection_points::SELECTION_SUB_GRABBERS
*     Tells the robot to go to this part in the selection program
* @var e_auto_selection_points::SELECTION_GYRO_CAL
*      Tells the robot to go to this part in the selection program
*  @var e_auto_selection_points::SELECTION_SELECTION_TYPE
*     Tells the robot to go to this part in the selection program
* @var e_auto_selection_points::SELECTION_GRAPH_NUMBER_INPUT
*     Tells the robot to go to this part in the selection program
* @var e_auto_selection_points::SELECTION_QUICK_INPUT
*			Tells the robot to go to this part in the selection program
*	@var e_auto_selection_points::SELECTION_SUB_RAMP
*			Tells the robot to go to this part in the selection program
* @var g_auto_selection_point
*			Tells the robot what phase its in on auto
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
*  @enum e_selection_types Lets the robot know how you want to imploment the auto program
*  @var e_auto_selection_points::SELECTION_TYPE_NUMBER
*     Select a program by id
*  @var e_auto_selection_points::SELECTION_TYPE_CUSTOM
*     Select one of the custom programs
*  @var e_auto_selection_points::SELECTION_TYPE_QUICK
*     Select one of the most commenly used progams
* @var selection_type
*		Tells the robot the selection type
*/
typedef enum
{
	SELECTION_TYPE_NUMBER,
	SELECTION_TYPE_CUSTOM,
	SELECTION_TYPE_QUICK,
	SELECTION_TYPE_OPTIONS
} e_selection_types;

e_selection_types selection_type = SELECTION_TYPE_CUSTOM;

/**
*  @enum e_selection_values Tells the robot what number you are editing
*  @var e_auto_selection_points::SELECTION_VALUE_EMPTY
*     Tells the robot what number you are editing nothing
*  @var e_auto_selection_points::STARTING_POINT
*     Tells the robot what number you are editing the starting point
*  @var e_auto_selection_points::STARTING_DELAY
*     Tells the robot what number you are editing the starting delay
*  @var e_auto_selection_points::SCOREING_POINT
*     Tells the robot what number you are editing the scoring point
*  @var e_auto_selection_points::END_DELAY
*     Tells the robot what number you are editing the delay at the end
*  @var e_auto_selection_points::END_POINT
*     Tells the robot what number you are editing where you end the program
*/

typedef enum
{
	SELECTION_VALUE_EMPTY,
	STARTING_POINT,
	STARTING_DELAY,
	SCOREING_POINT,
	END_DELAY,
	END_POINT
} e_selection_values;

//=========================================================
// auto sub selections
//=========================================================
/**
*  @enum e_direction Tells the robot to drive backwords or forwards onto the ramp
*  @var e_direction::SUB_SELECTION_GRABBERS_OUT
*     turn clockwise drive with the grabbers out
*  @var e_direction::SUB_SELECTION_GRABBERS_IN
*     turn counterclockwise drive with the grabbers in
*	@var g_auto_grabber_selections
*			Tells the robot is the grabbers are in or out
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

/**
*  @enum e_drive_type Tells the robot its corection type
*  @var e_auto_sub_selection_ramp::ENCODER
*     Tells the robot to correct useing a encoder
*  @var e_auto_sub_selection_ramp::GYRO
*     Tells the robot to correct useing a gyro sensor
*  @var e_auto_sub_selection_ramp::NON_SENSOR
*     Tells the robot not to correct
*/
typedef enum
{
	ENCODER,
	GYRO,
	NON_SENSOR
} e_drive_type;

/**
*  @enum e_drive_type Tells the robot if i should stop on the ramp or not
*  @var e_auto_sub_selection_ramp::SUB_SELECTION_RAMP_STOP
*     Tells the robot it should stop on the ramp
*   @var e_auto_sub_selection_ramp::SUB_SELECTION_RAMP_CONTINUED
*    Tells the robot it should not stop on the ramp
*	@var g_auto_grabber_selection_ramp_options
*		Tells the robot if it should continue on the ramp to the other side or not
*/
typedef enum
{
	SUB_SELECTION_RAMP_STOP,
	SUB_SELECTION_RAMP_CONTINUED
} e_auto_sub_selection_ramp;

e_auto_sub_selection_ramp g_auto_grabber_selection_ramp_options = SUB_SELECTION_RAMP_STOP;

typedef enum
{
	RAW,
	CALIBRATED
} e_gyro_val_type;

typedef enum
{
	RELATIVE_ASU,
	RELATIVE_BPU,
	RELATIVE_CENTIMETERS,
	RAW_ASU,
	RAW_BPU,
	RAW_CENTIMETERS
} e_angle_val_type;

typedef enum
{
	SOFT_RESET,
	HARD_RESET
} e_angle_reset_type;

//=========================================================
// auto movements
//=========================================================
/**
* @var g_to_turn_dist
* 		 Tells the robot how far it has gone when doing ir detection
*
* @var g_IR_angle_dist_complete
* 		 Tells the robot when it has reached a the first crate
*
* @var g_forward_crate1_to_turn_dist
* 		 Tells the robot how far it need to go to get to the turn
*
* @var g_forward_crate2_to_turn_dist
* 		 Tells the robot how far it need to go to get to the turn
*
* @var g_forward_crate3_to_turn_dist
* 		 Tells the robot how far it need to go to get to the turn
*
* @var g_forward_crate4_to_turn_dist
*  		 Tells the robot how far it need to go to get to the turn
*
* @var g_backwards_crate1_to_turn_dist
*  		 Tells the robot how far it need to go to get to the turn
*
* @var g_backwards_crate2_to_turn_dist
* 		 Tells the robot how far it need to go to get to the turn
*
* @var g_backwards_crate3_to_turn_dist
* 		 Tells the robot how far it need to go to get to the turn
*
* @var g_backwards_crate4_to_turn_dist
* 		 Tells the robot how far it need to go to get to the turn
*/

int g_to_turn_dist = 0;

bool g_IR_angle_dist_complete = false;

const int g_forward_crate1_to_turn_dist = 130;
const int g_forward_crate2_to_turn_dist = 105;
const int g_forward_crate3_to_turn_dist = 55;
const int g_forward_crate4_to_turn_dist = 30;

const int g_backwards_crate1_to_turn_dist = 40;
const int g_backwards_crate2_to_turn_dist = 65;
const int g_backwards_crate3_to_turn_dist = 115;
const int g_backwards_crate4_to_turn_dist = 140;

//=========================================================
// Smoke test varaibles
//=========================================================
/**
* @var g_smoke_test_num
* 		 Tells the robot what the number is for what its useing smoke test on
*
* @var g_smoke_test_total
* 		  Tells the robot the total number of of smoke test types
*
* @var g_smoke_run
* 		 Tells the robot if its running smoke test or not
*
* @var g_test_value
* 		 Tells the robot what to desply on the screen
*/

int g_smoke_test_num = 1;
int g_smoke_test_total = 12;
bool g_smoke_run = false;
int g_test_value = 0;

//=========================================================
// auto number input variable
//=========================================================
/**
* @def INPUT_ARRAY_SIZE
* 		 Tells the robot the size of the number of selection types
*
* @var g_input_array
* 		 Tells the robot all of the different options for automus
*/

#define INPUT_ARRAY_SIZE 6

int g_input_array[INPUT_ARRAY_SIZE];

//=========================================================
// Datalogging variables
//=========================================================
/**
* @var LogData
*		Tells the robot is if should log data or not
*
* @var dl_step
*		Tells the robot what data login step its on
*
* @var dl_robot_action_state
*		Tells the robot what the action state is
*
* @var dl_change_event
*		Tells the robot if it changes events for data loging
*
* @var dl_ce_detail
*		Tells the robot the details for the data loging
*
* @var dl_robot_action_detail
*		Tells the robot what its action detail is
*
* @var dl_mission_number
*		Tells the robot the data loging mission number
*
* @var dl_speed
*		Tells the robot the speed of the data loging
*
* @var dl_dist
*		Tells the robot the distence of something it should data log
*
* @var dl_gyro_heading
*		Tells the data loging the gyro_heading
*
* @var dl_IR
*		Tells the robot if it should data log IR or not
*
* @var dl_cur_dist
*		Tells the data loging the robots current distence
*
* @var sString
*		Tells the robot the string we are sending to the wright handler
*
* @def DL_MOVE_SPEED
*		Tells the robot how fast its going so it can put it int he data loging
* @def DL_MOVE_DIST
*		Tells the robot how far its move so it can put it in the data loging
*
* @var dl_drive_details
*		Tells the robot the drive details for data loging
*/
const string LogFileName = "DATALOG.txt";
TFileIOResult LogIoResult;
TFileHandle LogFileHandle;
long LogFileSize = 36000;
string sString;
string CRLF = (char)13+(char)10;

bool LogData = false;
int dl_step = 0;
int dl_robot_action_state = 0;
bool dl_change_event = false;
int dl_ce_detail = 0;
int dl_robot_action_detail = 0;
int dl_mission_number = 0;
int dl_speed = 0;
int dl_dist = 0;
int dl_gyro_heading = 0;
bool dl_IR = false;
int dl_cur_dist = 0;
float g_delta_drift = 0;
//string sString;

int dl_dist_method = 0;

#define DL_ANGLE 0
#define DL_LIGHT 1
#define DL_TIME 2
#define DL_IR 3

int dl_move_break = 0;

#define DL_ANGLE_BREAK 0
#define DL_LIGHT_BREAK 1
#define DL_TIME_BREAK 2
#define DL_IR_BREAK 3

#define DL_MOVE_SPEED 0
#define DL_MOVE_DIST 1

int dl_drive_details [] = {0,4};

//---------------
// robot action numbers
//---------------
/**
* @def dl_robot_stop
*		tells the robot to put in this cammand in the data loging files
* @def dl_gyro_move
*		tells the robot to put in this cammand in the data loging files
* @def dl_gyro_turn
*		tells the robot to put in this cammand in the data loging files
* @def dl_run_abdd
*		tells the robot to put in this cammand in the data loging files
* @def dl_wait
*		tells the robot to put in this cammand in the data loging files
* @def dl_change_event
*		tells the robot to put in this cammand in the data loging files
*/
#define dl_robot_stop 0
#define dl_gyro_move 1
#define dl_gyro_turn 2
#define dl_run_abdd 3
#define dl_wait 4

//---------------
// change event details
//---------------

/**
* @def dl_ce_program_start
*		 tell the robot when the robot dose this
* @def dl_ce_start_delay
*		tell the robot when the robot dose this
* @def dl_ce_score_start
*		tell the robot when the robot dose this
* @def dl_ce_end_delay
*		tell the robot when the robot dose this
* @def dl_ce_end_point
*		tell the robot when the robot dose this
*/
#define dl_ce_program_start 1
#define dl_ce_start_delay 2
#define dl_ce_score_start 3
#define dl_ce_end_delay 4
#define dl_ce_end_point 5
#define dl_ce_drive_end 6
#define dl_ce_drive_start 7
#define dl_ce_angle_reset 8
#define dl_ce_turn_end 9
#define dl_ce_turn_start 10

/**
* @var g_datalog_change_event_names
*		The even names that get put into data loging
*/
string g_datalog_change_event_names [] = {
	"none",
	"start",
	"start delay",
	"score",
	"end delay",
	"end",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	""};

//---------------
// robot action details
//---------------

/**
* @def dl_move_stop
*		Put in a details in data loging for this action
* @def dl_move_no_stop
*		Put in a details in data loging for this action
* @def dl_turn_clockwise
*		Put in a details in data loging for this action
* @def dl_turn_counterclockwise
*		Put in a details in data loging for this action
* @def dl_abdd_open
*		Put in a details in data loging for this action
* @def dl_abdd_close
*		Put in a details in data loging for this action
*/
#define dl_move_stop 1
#define dl_move_no_stop 2
#define dl_turn_clockwise 3
#define dl_turn_counterclockwise 4
#define dl_abdd_open 5
#define dl_abdd_close 6

/**
* @var g_datalog_details_names
*		Tells the robot the dataloging name in detail
*
* @var dl_btn_change
*		Tells the robot if the butons that are being press are changed for data loging
*
* @var dl_joy1_btns
*		Tells the robot all of the button numbers for joy 1
*
* @var dl_joy2_btns
*		Tells the robot all of the buton numbers for joy 2
*/
string g_datalog_details_names [] = {
	"none",
	"stop",
	"no stop",
	"clockwise",
	"counterclockwise",
	"abdd open",
	"abdd close"};

//-------------------------
// teleop datalogging varibles
//-------------------------

bool dl_btn_change = false;

int dl_joy1_btns [] = {0,1,2,3,4,5,6,7,8,9,10,11,12};
int dl_joy2_btns [] = {0,1,2,3,4,5,6,7,8,9,10,11,12};

//=========================================================
// Misc
//=========================================================

/**
* @var g_debug_time_1
*		degbug varales fir IR
* @var g_debug_time_2
*		degbug varales fir IR
*
* @var g_auto_ending_points
*		degbuging var for this
* @var g_travel_dist
*		degbuging var for this
* @var g_auto_starting_points
*		degbuging var for this
* @var g_auto_missions
*		degbuging var for this
* @var g_drive_heading
*		degbuging var for this
* @var g_ir_heading
*		degbuging var for this
* @var g_program_done
*		degbuging var for this
*
* @var g_joy1_enabled
*		degbuging var for this
* @var g_joy2_enabled
*		degbuging var for this
*
* @var g_selection_value
*		degbuging var for this
*/

int g_debug_time_1 = 0;
int g_debug_time_2 = 0;

int g_auto_ending_points = 5;
int g_travel_dist = 0;
int g_auto_starting_points = 4;
int g_auto_missions = 10;
int g_drive_heading = 0;
int g_ir_heading = 5;
bool g_program_done = false;

bool g_joy1_enabled = false;
bool g_joy2_enabled = false;

int g_selection_value = 0;

const int g_light_delta_value = 2;
int g_calibrated_light_threshold_val = 0;
int g_end_ramp_lift_speed = 40;
bool g_shift_due_to_ir = false;

bool g_good_gyro = true;

#define GYRO_VALUE_QUEUE_SIZE 3
int g_gyro_values[GYRO_VALUE_QUEUE_SIZE];

bool g_gyro_ran = false;
//Tells the robot the max rate thats possable to happen so we can know if the gyro gliches
#define MAX_TURN_RATE 0.72

#define STAY_ON_RAMP_WAIT_TIME 100
#define LIGHT_SENSOR_CALIBRATION_TIME 2000
#define LIGHT_CALIBRATION_SAMPLE_RATE 100
#define DEFAULT_CALIBRATED_LIGHT_THRESHOLD 9999

//=============================================================
// Define user configurable parameters
//=============================================================

/**
* @var g_end_point
*		Tells the robot its end posion
* @var g_start_point
*		Tells the robot its starting posion
* @var g_mission_number
*		 Tells the robot its mission number
* @var g_delay
*		 Tells the robot how long it needs to delay
* @var g_end_delay
*		Tells the robot how long it needs to delay after it it delivers a block
* @var g_ramp_delay
*		Tells the robot how long it needs to delay before entering the ramp
* @var g_start_delay
*		Tells the robot how long it needs to delay before it does anything
* @var g_gyro_cal_time
*		Tells the robot how long to calibrate
*
* @var g_dist_backwards
*		Tells the robot how far to go backwards
*
* @var START_POINT_MAX_VAL
*		Tells the robot the max numbers of starting points
* @var START_POINT_MIN_VAL
*		Tells the robot the min nuber of starting points
*
* @var g_number_min_limit
*		Tells the robot the maxenum amount of numbers
* @var g_number_max_limit
*		Tells the robot the minunum amount of numbers
*/

#define DELAY_MULTIPLICATION_FACTOR 1000

typedef enum
{
	END_MISSION_FIRST_TURN_REL,
	END_MISSION_FIRST_TURN_CONST
} e_em_first_turn_types;

e_em_first_turn_types g_em_first_turn_type = END_MISSION_FIRST_TURN_REL;

typedef enum
{
	END_MISSION_SECOND_TURN_REL,
	END_MISSION_SECOND_TURN_CONST
} e_em_second_turn_types;

e_em_second_turn_types g_em_second_turn_type = END_MISSION_FIRST_TURN_REL;

int g_selection_turn = 1;

int g_end_point = 1;
int g_start_point = 1;
int g_mission_number = 1;
int g_delay = 0;
int g_end_delay = 0;
int g_ramp_delay = 0;
int g_start_delay = 0;
int g_gyro_cal_time = 5;
bool g_stay_on_ramp = true;

int g_dist_backwards = 0;

int START_POINT_MAX_VAL = 4;
int START_POINT_MIN_VAL = 0;

int g_number_min_limit [] = {0,0,0,0,0,0,0};
int g_number_max_limit [] = {0,4,30,7,30,5};
//=============================================================
// Gyro variables
//=============================================================

/**
* @var g_gyro_noise
*		Tells the robot how much gyro noise there is
* @var g_start_time
*		Tells the robot the start time
* @var g_drift
*		Tells the robot the gyro drift
* @var g_const_heading
*		Tells the robot the const heading
* @var g_rel_heading
*		Tells the robot the relitive heading
* @var g_curr_time
*		Tells the robot the current time
* @var g_prev_time
*		Tells the robot the current time
* @var g_raw_gyro
*		Tells the robt the raw gyro value
* @var g_recont_heading
*		This is the recalculated const gyro heading
*/
int g_gyro_noise = 0;
long g_start_time = 0;
int g_drift = 0;
float g_sacred_const_heading = 0;
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
*		holds the value of the light sensor
*
* @var g_bearing_ac1
*		the raw value from the first IR sensor
*
* @var g_bearing_ac2
*		the raw value from the second IR sensor
*
* @var g_ir_bearing1
*		 the calibrated value from the first IR sensor
*
* @var g_ir_bearing2
*		the calibrated value from the second IR sensor
*
* @var g_acs1
*		The value of the accelermoeter to deplay on the screen
*
* @var g_acs2
*		The value of the accelermoeter to deplay on the screen
*
* @var g_curr_dir1
*		The value of the direction to deplay on the screen
*
* @var g_curr_dir2
*		The value of the direction to deplay on the screen
*
* @var g_misc
*		Tells the robot something to desply on the screen
*
* @var g_reset_angle
*		a varable that tells the robot to reset the angle sensor value
*/

bool dist_record = true;
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

/**
* @var g_accelermoeter_sensor
*		 Tells the robot the volosity its self
* @var g_x_axis
*		Tells the robot its x axis
* @var g_y_axis
*		 Tells the robot its y axis
* @var g_z_axis
*		Tells the robot its z axis
* @var g_target_angle
*		Tells the robot the tegeted posion
* @var g_accelermoeter_reads
*		Tells the robot the the amount of times it read the accelermoeter
* @var g_accelermoeter_array
*		Tells the robot the accelermoeter array
* @var g_accelermoeter_total_value
*		 Tells the robot the value of the accelermoeter
* @var g_accelermoeter_average
*		Tells the robot the avage number for the accelermoeter
*
* @var g_sensor_num
*		 Tells the robot the sensor we are reading
* @var g_sensor_max
*		Tells the robot he max amoun of sensors
* @var g_sensor_value
*		Tells the robot the value of the sensor its reading
* @var g_sensor_value2
*		Tells the robot the second line of the senser its reading
*/
int g_accelermoeter_sensor = 0;
int g_x_axis = 0;
int g_y_axis = 0;
int g_z_axis = 0;
const int g_target_angle = 110;
ubyte g_accelermoeter_reads = 0;
int g_accelermoeter_array [] = {0,30};
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

/**
* @var g_sensor_reference_drive
*		Tells the robot if it should run with sensors enabled
* @var g_sensor_list
*		 Tells the robot the sensors that are on it
* @var g_basic_word_list
*		 Tells the robot the basic word list
*
*/

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

typedef enum
{
	ACTIVE,
	INACTIVE
} e_light_sensor_status;

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
*  @def S_SELECTION_SUB_RAMP
*     Tells the robot the screen state number for this screen statestate
*  @def S_MISSION_SHOW
*     Tells the robot the screen state number for this screen statestate
*  @def S_QUICK_SELECTION
*     Tells the robot the screen state number for this screen statestate
*  @var g_screen_state
*			Tells the robt what it should desply on the screen
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
#define S_END_TURN_OPTIONS 27
#define S_STAY_GROUND_OPTIONS 28

int g_screen_state = 1;

//==============================================================
// Define graph selection variables
//==============================================================
/**
* @var g_graph_selection_tab
*		 Tells the user what number you are selecting
*/
int g_graph_selection_tab = 0;

//==============================================================
// Define error numbers
//==============================================================
/**
*
*  @def ERR_NONE
*     Tells the robot that theres no error
*   @def ERR_GYRO_CAL
*     Tells the robot that theres a error with the gyro calibrate
*  @def ERR_GYRO_MUX
*     Tells the robot that theres a error with the gyro mux
*  @def ERR_SENSOR_MUX
*     Tells the robot that theres a error with the sensor mux
*  @def ERR_JOYSTICKS
*     Tells the robot that theres a error with the joysticks
*  @def ERR_ACCELERMOETER
*     Tells the robot that theres a error with the accelermoeter
*  @var g_error
*			Tells the robot the number for an error
*/
#define ERR_NONE 0
#define ERR_GYRO_CAL 1
#define ERR_GYRO_MUX 2
#define ERR_SENSOR_MUX 3
#define ERR_JOYSTICKS 4
#define ERR_ACCELERMOETER 5

int g_error = 0;

/**
*  @enum e_error_types Tells the robot if a error is leathal or not
*  @var e_auto_sub_selection_ramp::ERROR_NONLETHAL
*     Tells the robot that the error is not leathal
*  @var e_auto_sub_selection_ramp::ERROR_LETHAL
*     Tells the robot that thbe error ios leathal
*
*  @var g_error_type
*		Tells the robot is an error is lethal or not
*/

typedef enum
{
	ERROR_NONLETHAL,
	ERROR_LETHAL
} e_error_types;

e_error_types g_error_type = ERROR_LETHAL;

//==============================================================================
// Define the text to be displayed for each starting point line 1
//==============================================================================
/**
* @var g_starting_names1
*		Tell the robot the names of the starting points
*/

string g_starting_names1 [] = {
	"        ",
	"S1      ",
	"S2      ",
	"S3      ",
	"S4      ",
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
/**
* @var g_starting_names2
*		Tell the robot the names of the second line of the screen when selectimg a starting posion
*/

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
/**
* @var g_ending_names1
*		 Tells the robot the names of the end points
*/

string g_ending_names1 [] = {
	"        ",
	"Stop    ",
	"Ramp 1  ",
	"Ramp 2  ",
	"Ramp 1  ",
	"Ramp 2  ",
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
/**
* @var g_ending_names2
*		 Tells the robot the names of the second line of the end points
*/
string g_ending_names2 [] = {
	"        ",
	"        ",
	"Stop    ",
	"Stop    ",
	"Continue",
	"Continue",
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
/**
* @var g_mission_names1
*		Tells the robot the names of the missions
*/
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
/**
* @var g_mission_names2
*		Tells the robot the second line of the mission
*/
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
/**
* @var g_quick_names1
*		 Tells the robot the quick select program names
*/

string g_quick_names1 [] = {
	"Unknown ",
	"Standard",
	"S Ramp 2",
	"Test 3  ",
	"Test 4  ",
	"Test 5  ",
	"Test 6  "};

/**
* @var g_quick_names2
*		 Tells the robot the quick select program second line names
* @var g_quick_mission
*		Tells the robot the numbers of the quick missions
* @var g_max_quick_missions
*		Tells the robot the max amount of quick names
*/
string g_quick_names2 [] = {
	"Unknown ",
	"10142   ",
	"10143   ",
	"Test 3  ",
	"Test 4  ",
	"Test 5  ",
	"Test 6  "};

int g_quick_mission = 1;
int g_max_quick_missions = 6;

//==============================================================================
// Define the text to be displayed for the errors
//==============================================================================
/**
* @var g_error_list1
*		 Tells the robot the names of the errors
*/
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
/**
* @var g_error_list2
*		Tells the robot the names of the errors for the second line
*/

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
/**
* @var g_smoke_test1
*		Tells the robot the names of the smake test options
*/
string g_smoke_test1 [] = {
	"Unknown ",
	"Jolly   ",
	"Drive   ",
	"Sensor  ",
	"Block   ",
	"Grabbers",
	"sky hook",
	"roger   ",
	"ground  ",
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
/**
* @var g_smoke_test2
*		Tells the robot the names of the smake test options for the second line
*/
string g_smoke_test2 [] = {
	"Unknown ",
	"Roger   ",
	"Train   ",
	"Sensor  ",
	"Lift    ",
	"        ",
	"        ",
	"slide   ",
	"arm     ",
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
