//    B78XH-wasm
//    Copyright (C) 2022  Heavy Division
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <https://www.gnu.org/licenses/>.


#pragma once
#include <string>

enum SimulationVariableUnits {
	/*
	 * Length
	 */
	METER,
	METER_SCALER_256,
	MILLIMETER,
	CENTIMETER,
	KILOMETER,
	NAUTICAL_MILE,
	DECINMILE,
	INCH,
	FOOT,
	YARD,
	DECIMILE,
	MILE,
	/*
	 * Area
	 */
	SQUARE_INCH,
	SQUARE_FEET,
	SQUARE_MILE,
	SQUARE_MILLIMETER,
	SQUARE_CENTIMETER,
	SQUARE_METER,
	SQUARE_KILOMETER,
	/*
	 * Volume
	 */
	CUBIC_INCH,
	CUBIC_FOOT,
	CUBIC_YARD,
	CUBIC_MILE,
	CUBIC_MILLIMETER,
	CUBIC_CENTIMETER,
	CUBIC_METER,
	CUBIC_KILOMETER,
	LITER,
	GALLON,
	QUART,
	FS7_OIL_QUANTITY,
	/*
	 * Temperature
	 */
	KELVIN,
	RANKINE,
	FARENHEIT,
	CELSIUS,
	CELSIUS_FS7_EGT,
	CELSIUS_FS7_OIL_TEMP,
	CELSIUS_SCALER_1_256,
	CELSIUS_SCALER_256,
	CELSIUS_SCALER_16K,
	/*
	 * Angles
	 */
	RADIAN,
	ROUND,
	DEGREE,
	GRAD,
	ANGL16,
	ANGL32,
	/*
	 * Global position
	 */
	DEGREE_LATITUDE,
	DEGREE_LONGITUDE,
	METER_LATITUDE,
	/*
	 * Angular velocity
	 */
	RADIAN_PER_SECOND,
	REVOLUTION_PER_MINUTE,
	RPM_1_OVER_16k,
	MINUTE_PER_ROUND,
	NICE_MINUTE_PER_ROUND,
	DEGREE_PER_SECOND,
	DEGREE_PER_SECOND_ANG16,
	/*
	 * Angular acceleration
	 */
	RADIAN_PER_SECOND_SQUARED,
	DEGREE_PER_SECOND_SQUARED,
	/*
	 *	Speed
	 */
	METER_PER_SECOND,
	METER_PER_SECOND_SCALER_256,
	METER_PER_MINUTE,
	KILOMETER_HOUR,
	FEET_SECOND,
	FEET_MINUTE,
	MILE_PER_MINUTE,
	KNOT,
	KNOT_SCALER_128,
	MACH,
	MACH_3D2_OVER_64K,
	/*
	 * Acceleration
	 */
	METER_PER_SECOND_SQUARED,
	FEET_PER_SECOND_SQUARED,
	GFORCE,
	GFORCE_624_SCALED,
	/*
	 * Time
	 */
	SECOND,
	MINUTE,
	HOUR,
	DAY,
	HOUR_OVER_10,
	YEAR,
	/*
	 * Power
	 */
	WATT,
	FT_LB_PER_SECOND,
	/*
	 * Volume rate
	 */
	METER_CUBED_PER_SECOND,
	LITER_PER_HOUR,
	GALLON_PER_HOUR,
	/*
	* Weight
	*/
	KILOGRAM,
	POUND,
	POUND_SCALER_256,
	SLUG,
	/*
	 * Weight rate
	 */
	KILOGRAM_PER_SECOND,
	POUND_PER_HOUR,
	/*
	 * Electrical current
	 */
	AMPERE,
	FS7_CHARGING_AMPS,
	/*
	 * Electrical potential
	 */
	VOLT,
	/*
	 * Frequency
	 */
	HERTZ,
	KILOHERTZ,
	MEGAHERTZ,
	FREQUENCY_BCD16,
	FREQUENCY_BCD32,
	FREQUENCY_ADF_BCD32,
	/*
	 * Density
	 */
	KILOGRAM_PER_CUBIC_METER,
	SLUG_PER_CUBIC_FEET,
	POUND_PER_GALLON,
	/*
	 * Pressure
	 */
	PASCAL,
	KILOPASCAL,
	MILLIMETER_OF_MERCURY,
	CENTIMETER_OF_MERCURY,
	INCH_OF_MERCURY,
	INHG_64_OVER_64K,
	NEWTON_PER_SQUARE_METER,
	KILOGRAM_FORCE_PER_SQUARE_CENTIMETER,
	KILOGRAM_METER_SQUARED,
	ATMOSPHERE,
	BAR,
	MILLIBAR,
	MILLIBAR_SCALER_16,
	POUND_FORCE_PER_SQUARE_INCH,
	PSI_SCALER_16K,
	PSI_4_OVER_16K,
	PSI_FS7_OIL_PRESSURE,
	POUND_FORCE_PER_SQUARE_FOOT,
	PSF_SCALER_16K,
	SLUG_FEET_SQUARED,
	BOOST_CMHG,
	BOOST_INHG,
	BOOST_PSI,
	/*
	 * Torque
	 */
	NEWTON_METER,
	FOOT_POUND,
	LBF_FEET,
	KILOGRAM_METER,
	POUNDAL_FEET,
	/*
	 * Miscellaneous Units
	 */
	FRACTIONAL_LAT_LON_DIGITS,
	PART,
	HALF,
	THIRD,
	PERCENT,
	PERCENT_OVER_100,
	PERCENT_SCALER_16K,
	PERCENT_SCALER_32K,
	PERCENT_SCALER_2POW23,
	BEL,
	DECIBEL,
	MORE_THEN_A_HALF,
	TIMES,
	RATIO,
	NUMBER,
	SCALER,
	POSITION,
	ENUM,
	BOOL,
	BCO16,
	MASK,
	FLAGS,
	STRING,
	PER_RADIAN,
	PER_DEGREE,
	KEYFRAME,
	/*
	 * Structs And Other Complex Units
	 */
	XYZ,
	PBH,
	LAT_LON_ALT_PBH,
	LAT_LON_ALT,
	PID_STRUCT,
	GLASS_COCKPIT_SETTINGS,
	FUEL_LEVELS
};

std::string svu_to_string(SimulationVariableUnits unit);