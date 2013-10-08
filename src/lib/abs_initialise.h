/**
 *
 *  @file abs_initialise.h
 *
 *  @brief  Calibrates all sensors and prepares memory for use
 *
 *  @param calibration_time Tells the robot how long to calibrate
 *
 *  @copyright Copyright 2013, Got Robot! FTC Team 5037
 */
#ifndef TEMPLATE_H
#define TEMPLATE_H

/** macros */
void abs_initialise (int calibration_time)
{
	abs_create_mem();
	g_drift = abs_gyro_cal(CALIBRATION_TIME);
}
/** enumerations */

/** structures */

/** function prototypes */

/** global constant variables */

#endif /* !TEMPLATE_H */
