/**
 *
 *  @file abs_initialize_system()
 *
 *  @brief Calibrates all sensors and prepares memory for use
 *
 *  @copyright Copyright 2013, Got Robot! FTC Team 5037
 */
#ifndef TEMPLATE_H
#define TEMPLATE_H

/** macros */
void abs_initialize_system()
{
	abs_create_mem();
	g_drift = abs_gyro_cal(CALIBRATION_TIME);
}
/** enumerations */

/** structures */

/** function prototypes */

/** global constant variables */

#endif /* !TEMPLATE_H */
