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


#include "SimulationVariables.h"

std::string sv_to_string(SimulationVariables variable) {
	std::string toReturn;
	switch(variable) {
		case ACCELERATION_BODY_X:
			toReturn += "ACCELERATION_BODY_X";
			break;
		case ACCELERATION_BODY_Y:
			toReturn += "ACCELERATION_BODY_Y";
			break;
		case ACCELERATION_BODY_Z:
			toReturn += "ACCELERATION_BODY_Z";
			break;
		case ACCELERATION_WORLD_X:
			toReturn += "ACCELERATION_WORLD_X";
			break;
		case ACCELERATION_WORLD_Y:
			toReturn += "ACCELERATION_WORLD_Y";
			break;
		case ACCELERATION_WORLD_Z:
			toReturn += "ACCELERATION_WORLD_Z";
			break;
		case ADF_ACTIVE_FREQUENCY:
			toReturn += "ADF ACTIVE FREQUENCY";
			break;
		case ADF_AVAILABLE:
			toReturn += "ADF AVAILABLE";
			break;
		case ADF_CARD:
			toReturn += "ADF CARD";
			break;
		case ADF_EXT_FREQUENCY:
			toReturn += "ADF EXT FREQUENCY";
			break;
		case ADF_FREQUENCY:
			toReturn += "ADF FREQUENCY";
			break;
		case ADF_IDENT:
			toReturn += "ADF IDENT";
			break;
		case ADF_LATLONALT:
			toReturn += "ADF LATLONALT";
			break;
		case ADF_NAME:
			toReturn += "ADF NAME";
			break;
		case ADF_RADIAL:
			toReturn += "ADF RADIAL";
			break;
		case ADF_RADIAL_MAG:
			toReturn += "ADF RADIAL MAG";
			break;
		case ADF_SIGNAL:
			toReturn += "ADF SIGNAL";
			break;
		case ADF_SOUND:
			toReturn += "ADF SOUND";
			break;
		case ADF_STANDBY_AVAILABLE:
			toReturn += "ADF STANDBY AVAILABLE";
			break;
		case ADF_STANDBY_FREQUENCY:
			toReturn += "ADF STANDBY FREQUENCY";
			break;
		case ADF_VOLUME:
			toReturn += "ADF VOLUME";
			break;
		case AI_ANTISTALL_STATE:
			toReturn += "AI ANTISTALL STATE";
			break;
		case AI_AUTOTRIM_ACTIVE:
			toReturn += "AI AUTOTRIM ACTIVE";
			break;
		case AI_AUTOTRIM_ACTIVE_AGAINST_PLAYER:
			toReturn += "AI AUTOTRIM ACTIVE AGAINST PLAYER";
			break;
		case AI_CONTROLS:
			toReturn += "AI CONTROLS";
			break;
		case AI_CURSOR_MODE_ACTIVE:
			toReturn += "AI CURSOR MODE ACTIVE";
			break;
		case AILERON_AVERAGE_DEFLECTION:
			toReturn += "AILERON AVERAGE DEFLECTION";
			break;
		case AILERON_LEFT_DEFLECTION:
			toReturn += "AILERON LEFT DEFLECTION";
			break;
		case AILERON_LEFT_DEFLECTION_PCT:
			toReturn += "AILERON LEFT DEFLECTION PCT";
			break;
		case AILERON_POSITION:
			toReturn += "AILERON POSITION";
			break;
		case AILERON_RIGHT_DEFLECTION:
			toReturn += "AILERON RIGHT DEFLECTION";
			break;
		case AILERON_RIGHT_DEFLECTION_PCT:
			toReturn += "AILERON RIGHT DEFLECTION PCT";
			break;
		case AILERON_TRIM:
			toReturn += "AILERON TRIM";
			break;
		case AILERON_TRIM_DISABLED:
			toReturn += "AILERON TRIM DISABLED";
			break;
		case AILERON_TRIM_PCT:
			toReturn += "AILERON TRIM PCT";
			break;
		case AIRCRAFT_WIND_X:
			toReturn += "AIRCRAFT_WIND_X";
			break;
		case AIRCRAFT_WIND_Y:
			toReturn += "AIRCRAFT_WIND_Y";
			break;
		case AIRCRAFT_WIND_Z:
			toReturn += "AIRCRAFT_WIND_Z";
			break;
		case AIRSPEED_BARBER_POLE:
			toReturn += "AIRSPEED_BARBER_POLE";
			break;
		case AIRSPEED_INDICATED:
			toReturn += "AIRSPEED INDICATED";
			break;
		case AIRSPEED_MACH:
			toReturn += "AIRSPEED_MACH";
			break;
		case AIRSPEED_SELECT_INDICATED_OR_TRUE:
			toReturn += "AIRSPEED SELECT INDICATED OR TRUE";
			break;
		case AIRSPEED_TRUE:
			toReturn += "AIRSPEED_TRUE";
			break;
		case AIRSPEED_TRUE_CALIBRATE:
			toReturn += "AIRSPEED TRUE CALIBRATE";
			break;
		case AIRSPEED_TRUE_RAW:
			toReturn += "AIRSPEED_TRUE_RAW";
			break;
		case ALTERNATE_STATIC_SOURCE_OPEN:
			toReturn += "ALTERNATE STATIC SOURCE OPEN";
			break;
		case ALTERNATOR_BREAKER_PULLED:
			toReturn += "ALTERNATOR_BREAKER_PULLED";
			break;
		case ALTERNATOR_CONNECTION_ON:
			toReturn += "ALTERNATOR_CONNECTION_ON";
			break;
		case AMBIENT_DENSITY:
			toReturn += "AMBIENT_DENSITY";
			break;
		case AMBIENT_IN_CLOUD:
			toReturn += "AMBIENT IN CLOUD";
			break;
		case AMBIENT_PRECIP_RATE:
			toReturn += "AMBIENT_PRECIP_RATE";
			break;
		case AMBIENT_PRECIP_STATE:
			toReturn += "AMBIENT_PRECIP_STATE";
			break;
		case AMBIENT_PRESSURE:
			toReturn += "AMBIENT_PRESSURE";
			break;
		case AMBIENT_TEMPERATURE:
			toReturn += "AMBIENT_TEMPERATURE";
			break;
		case AMBIENT_VISIBILITY:
			toReturn += "AMBIENT_VISIBILITY";
			break;
		case AMBIENT_WIND_DIRECTION:
			toReturn += "AMBIENT_WIND_DIRECTION";
			break;
		case AMBIENT_WIND_VELOCITY:
			toReturn += "AMBIENT_WIND_VELOCITY";
			break;
		case AMBIENT_WIND_X:
			toReturn += "AMBIENT_WIND_X";
			break;
		case AMBIENT_WIND_Y:
			toReturn += "AMBIENT_WIND_Y";
			break;
		case AMBIENT_WIND_Z:
			toReturn += "AMBIENT_WIND_Z";
			break;
		case ANEMOMETER_PCT_RPM:
			toReturn += "ANEMOMETER PCT RPM";
			break;
		case ANGLE_OF_ATTACK_INDICATOR:
			toReturn += "ANGLE OF ATTACK INDICATOR";
			break;
		case ANIMATION_DELTA_TIME:
			toReturn += "ANIMATION_DELTA_TIME";
			break;
		case ANNUNCIATOR_SWITCH:
			toReturn += "ANNUNCIATOR SWITCH";
			break;
		case ANTISKID_BRAKES_ACTIVE:
			toReturn += "ANTISKID BRAKES ACTIVE";
			break;
		case APPLY_HEAT_TO_SYSTEMS:
			toReturn += "APPLY HEAT TO SYSTEMS";
			break;
		case APU_BLEED_PRESSURE_RECEIVED_BY_ENGINE:
			toReturn += "APU_BLEED_PRESSURE_RECEIVED_BY_ENGINE";
			break;
		case APU_GENERATOR_ACTIVE:
			toReturn += "APU_GENERATOR_ACTIVE";
			break;
		case APU_GENERATOR_SWITCH:
			toReturn += "APU_GENERATOR_SWITCH";
			break;
		case APU_ON_FIRE_DETECTED:
			toReturn += "APU_ON_FIRE_DETECTED";
			break;
		case APU_PCT_RPM:
			toReturn += "APU_PCT_RPM";
			break;
		case APU_PCT_STARTER:
			toReturn += "APU_PCT_STARTER";
			break;
		case APU_SWITCH:
			toReturn += "APU_SWITCH";
			break;
		case APU_VOLTS:
			toReturn += "APU_VOLTS";
			break;
		case ARTIFICIAL_GROUND_ELEVATION:
			toReturn += "ARTIFICIAL_GROUND_ELEVATION";
			break;
		case ASSISTANCE_LANDING_ENABLED:
			toReturn += "ASSISTANCE LANDING ENABLED";
			break;
		case ASSISTANCE_TAKEOFF_ENABLED:
			toReturn += "ASSISTANCE TAKEOFF ENABLED";
			break;
		case ATC_AIRLINE:
			toReturn += "ATC AIRLINE";
			break;
		case ATC_AIRPORT_IS_TOWERED:
			toReturn += "ATC AIRPORT IS TOWERED";
			break;
		case ATC_CLEARED_IFR:
			toReturn += "ATC CLEARED IFR";
			break;
		case ATC_CLEARED_LANDING:
			toReturn += "ATC CLEARED LANDING";
			break;
		case ATC_CLEARED_TAKEOFF:
			toReturn += "ATC CLEARED TAKEOFF";
			break;
		case ATC_CLEARED_TAXI:
			toReturn += "ATC CLEARED TAXI";
			break;
		case ATC_CURRENT_WAYPOINT_ALTITUDE:
			toReturn += "ATC CURRENT WAYPOINT ALTITUDE";
			break;
		case ATC_FLIGHTPLAN_DIFF_ALT:
			toReturn += "ATC FLIGHTPLAN DIFF ALT";
			break;
		case ATC_FLIGHTPLAN_DIFF_DISTANCE:
			toReturn += "ATC FLIGHTPLAN DIFF DISTANCE";
			break;
		case ATC_FLIGHTPLAN_DIFF_HEADING:
			toReturn += "ATC FLIGHTPLAN DIFF HEADING";
			break;
		case ATC_FLIGHT_NUMBER:
			toReturn += "ATC FLIGHT NUMBER";
			break;
		case ATC_HEAVY:
			toReturn += "ATC HEAVY";
			break;
		case ATC_ID:
			toReturn += "ATC ID";
			break;
		case ATC_IFR_FP_TO_REQUEST:
			toReturn += "ATC IFR FP TO REQUEST";
			break;
		case ATC_MODEL:
			toReturn += "ATC MODEL";
			break;
		case ATC_ON_PARKING_SPOT:
			toReturn += "ATC ON PARKING SPOT";
			break;
		case ATC_PREVIOUS_WAYPOINT_ALTITUDE:
			toReturn += "ATC_PREVIOUS_WAYPOINT_ALTITUDE";
			break;
		case ATC_RUNWAY_AIRPORT_NAME:
			toReturn += "ATC RUNWAY AIRPORT NAME";
			break;
		case ATC_RUNWAY_DISTANCE:
			toReturn += "ATC RUNWAY DISTANCE";
			break;
		case ATC_RUNWAY_END_DISTANCE:
			toReturn += "ATC RUNWAY END DISTANCE";
			break;
		case ATC_RUNWAY_HEADING_DEGREES_TRUE:
			toReturn += "ATC RUNWAY HEADING DEGREES TRUE";
			break;
		case ATC_RUNWAY_LENGTH:
			toReturn += "ATC RUNWAY LENGTH";
			break;
		case ATC_RUNWAY_RELATIVE_POSITION_X:
			toReturn += "ATC RUNWAY RELATIVE POSITION X";
			break;
		case ATC_RUNWAY_RELATIVE_POSITION_Y:
			toReturn += "ATC RUNWAY RELATIVE POSITION Y";
			break;
		case ATC_RUNWAY_RELATIVE_POSITION_Z:
			toReturn += "ATC RUNWAY RELATIVE POSITION Z";
			break;
		case ATC_RUNWAY_SELECTED:
			toReturn += "ATC RUNWAY SELECTED";
			break;
		case ATC_RUNWAY_START_DISTANCE:
			toReturn += "ATC RUNWAY START DISTANCE";
			break;
		case ATC_RUNWAY_TDPOINT_RELATIVE_POSITION_X:
			toReturn += "ATC RUNWAY TDPOINT RELATIVE POSITION X";
			break;
		case ATC_RUNWAY_TDPOINT_RELATIVE_POSITION_Y:
			toReturn += "ATC RUNWAY TDPOINT RELATIVE POSITION Y";
			break;
		case ATC_RUNWAY_TDPOINT_RELATIVE_POSITION_Z:
			toReturn += "ATC RUNWAY TDPOINT RELATIVE POSITION Z";
			break;
		case ATC_RUNWAY_WIDTH:
			toReturn += "ATC RUNWAY WIDTH";
			break;
		case ATC_SUGGESTED_MIN_RWY_LANDING:
			toReturn += "ATC SUGGESTED MIN RWY LANDING";
			break;
		case ATC_SUGGESTED_MIN_RWY_TAKEOFF:
			toReturn += "ATC SUGGESTED MIN RWY TAKEOFF";
			break;
		case ATC_TAXIPATH_DISTANCE:
			toReturn += "ATC TAXIPATH DISTANCE";
			break;
		case ATC_TYPE:
			toReturn += "ATC TYPE";
			break;
		case ATTITUDE_BARS_POSITION:
			toReturn += "ATTITUDE BARS POSITION";
			break;
		case ATTITUDE_CAGE:
			toReturn += "ATTITUDE CAGE";
			break;
		case ATTITUDE_INDICATOR_BANK_DEGREES:
			toReturn += "ATTITUDE INDICATOR BANK DEGREES";
			break;
		case ATTITUDE_INDICATOR_PITCH_DEGREES:
			toReturn += "ATTITUDE INDICATOR PITCH DEGREES";
			break;
		case AUDIO_PANEL_AVAILABLE:
			toReturn += "AUDIO PANEL AVAILABLE";
			break;
		case AUDIO_PANEL_VOLUME:
			toReturn += "AUDIO PANEL VOLUME";
			break;
		case AUTOBRAKES_ACTIVE:
			toReturn += "AUTOBRAKES ACTIVE";
			break;
		case AUTOPILOT_AIRSPEED_ACQUISITION:
			toReturn += "AUTOPILOT AIRSPEED ACQUISITION";
			break;
		case AUTOPILOT_AIRSPEED_HOLD:
			toReturn += "AUTOPILOT AIRSPEED HOLD";
			break;
		case AUTOPILOT_AIRSPEED_HOLD_CURRENT:
			toReturn += "AUTOPILOT AIRSPEED HOLD CURRENT";
			break;
		case AUTOPILOT_AIRSPEED_HOLD_VAR:
			toReturn += "AUTOPILOT AIRSPEED HOLD VAR";
			break;
		case AUTOPILOT_AIRSPEED_MAX_CALCULATED:
			toReturn += "AUTOPILOT AIRSPEED MAX CALCULATED";
			break;
		case AUTOPILOT_AIRSPEED_MIN_CALCULATED:
			toReturn += "AUTOPILOT AIRSPEED MIN CALCULATED";
			break;
		case AUTOPILOT_ALTITUDE_ARM:
			toReturn += "AUTOPILOT ALTITUDE ARM";
			break;
		case AUTOPILOT_ALTITUDE_LOCK_VAR:
			toReturn += "AUTOPILOT ALTITUDE LOCK VAR";
			break;
		case AUTOPILOT_ALTITUDE_MANUALLY_TUNABLE:
			toReturn += "AUTOPILOT ALTITUDE MANUALLY TUNABLE";
			break;
		case AUTOPILOT_ALTITUDE_SLOT_INDEX:
			toReturn += "AUTOPILOT ALTITUDE SLOT INDEX";
			break;
		case AUTOPILOT_APPROACH_ACTIVE:
			toReturn += "AUTOPILOT APPROACH ACTIVE";
			break;
		case AUTOPILOT_APPROACH_ARM:
			toReturn += "AUTOPILOT APPROACH ARM";
			break;
		case AUTOPILOT_APPROACH_CAPTURED:
			toReturn += "AUTOPILOT APPROACH CAPTURED";
			break;
		case AUTOPILOT_APPROACH_HOLD:
			toReturn += "AUTOPILOT APPROACH HOLD";
			break;
		case AUTOPILOT_APPROACH_IS_LOCALIZER:
			toReturn += "AUTOPILOT APPROACH IS LOCALIZER";
			break;
		case AUTOPILOT_ATTITUDE_HOLD:
			toReturn += "AUTOPILOT ATTITUDE HOLD";
			break;
		case AUTOPILOT_AVAILABLE:
			toReturn += "AUTOPILOT AVAILABLE";
			break;
		case AUTOPILOT_AVIONICS_MANAGED:
			toReturn += "AUTOPILOT AVIONICS MANAGED";
			break;
		case AUTOPILOT_BACKCOURSE_HOLD:
			toReturn += "AUTOPILOT BACKCOURSE HOLD";
			break;
		case AUTOPILOT_BANK_HOLD:
			toReturn += "AUTOPILOT BANK HOLD";
			break;
		case AUTOPILOT_BANK_HOLD_REF:
			toReturn += "AUTOPILOT BANK HOLD REF";
			break;
		case AUTOPILOT_CRUISE_SPEED_HOLD:
			toReturn += "AUTOPILOT CRUISE SPEED HOLD";
			break;
		case AUTOPILOT_DEFAULT_PITCH_MODE:
			toReturn += "AUTOPILOT DEFAULT PITCH MODE";
			break;
		case AUTOPILOT_DEFAULT_ROLL_MODE:
			toReturn += "AUTOPILOT DEFAULT ROLL MODE";
			break;
		case AUTOPILOT_DISENGAGED:
			toReturn += "AUTOPILOT DISENGAGED";
			break;
		case AUTOPILOT_FLIGHT_DIRECTOR_ACTIVE:
			toReturn += "AUTOPILOT FLIGHT DIRECTOR ACTIVE";
			break;
		case AUTOPILOT_FLIGHT_DIRECTOR_BANK:
			toReturn += "AUTOPILOT FLIGHT DIRECTOR BANK";
			break;
		case AUTOPILOT_FLIGHT_DIRECTOR_BANK_EX1:
			toReturn += "AUTOPILOT FLIGHT DIRECTOR BANK EX1";
			break;
		case AUTOPILOT_FLIGHT_DIRECTOR_PITCH:
			toReturn += "AUTOPILOT FLIGHT DIRECTOR PITCH";
			break;
		case AUTOPILOT_FLIGHT_DIRECTOR_PITCH_EX1:
			toReturn += "AUTOPILOT FLIGHT DIRECTOR PITCH EX1";
			break;
		case AUTOPILOT_FLIGHT_LEVEL_CHANGE:
			toReturn += "AUTOPILOT FLIGHT LEVEL CHANGE";
			break;
		case AUTOPILOT_GLIDESLOPE_ACTIVE:
			toReturn += "AUTOPILOT GLIDESLOPE ACTIVE";
			break;
		case AUTOPILOT_GLIDESLOPE_ARM:
			toReturn += "AUTOPILOT GLIDESLOPE ARM";
			break;
		case AUTOPILOT_GLIDESLOPE_HOLD:
			toReturn += "AUTOPILOT GLIDESLOPE HOLD";
			break;
		case AUTOPILOT_HEADING_LOCK:
			toReturn += "AUTOPILOT HEADING LOCK";
			break;
		case AUTOPILOT_HEADING_LOCK_DIR:
			toReturn += "AUTOPILOT HEADING LOCK DIR";
			break;
		case AUTOPILOT_HEADING_MANUALLY_TUNABLE:
			toReturn += "AUTOPILOT HEADING MANUALLY TUNABLE";
			break;
		case AUTOPILOT_HEADING_SLOT_INDEX:
			toReturn += "AUTOPILOT HEADING SLOT INDEX";
			break;
		case AUTOPILOT_MACH_HOLD:
			toReturn += "AUTOPILOT MACH HOLD";
			break;
		case AUTOPILOT_MACH_HOLD_VAR:
			toReturn += "AUTOPILOT MACH HOLD VAR";
			break;
		case AUTOPILOT_MANAGED_INDEX:
			toReturn += "AUTOPILOT MANAGED INDEX";
			break;
		case AUTOPILOT_MANAGED_SPEED_IN_MACH:
			toReturn += "AUTOPILOT MANAGED SPEED IN MACH";
			break;
		case AUTOPILOT_MANAGED_THROTTLE_ACTIVE:
			toReturn += "AUTOPILOT MANAGED THROTTLE ACTIVE";
			break;
		case AUTOPILOT_MASTER:
			toReturn += "AUTOPILOT MASTER";
			break;
		case AUTOPILOT_MAX_BANK:
			toReturn += "AUTOPILOT MAX BANK";
			break;
		case AUTOPILOT_MAX_BANK_ID:
			toReturn += "AUTOPILOT MAX BANK ID";
			break;
		case AUTOPILOT_MAX_SPEED_HOLD:
			toReturn += "AUTOPILOT MAX SPEED HOLD";
			break;
		case AUTOPILOT_NAV1_LOCK:
			toReturn += "AUTOPILOT NAV1 LOCK";
			break;
		case AUTOPILOT_NAV_SELECTED:
			toReturn += "AUTOPILOT NAV SELECTED";
			break;
		case AUTOPILOT_PITCH_HOLD:
			toReturn += "AUTOPILOT PITCH HOLD";
			break;
		case AUTOPILOT_PITCH_HOLD_REF:
			toReturn += "AUTOPILOT PITCH HOLD REF";
			break;
		case AUTOPILOT_RPM_HOLD:
			toReturn += "AUTOPILOT RPM HOLD";
			break;
		case AUTOPILOT_RPM_HOLD_VAR:
			toReturn += "AUTOPILOT RPM HOLD VAR";
			break;
		case AUTOPILOT_RPM_SLOT_INDEX:
			toReturn += "AUTOPILOT RPM SLOT INDEX";
			break;
		case AUTOPILOT_SPEED_SETTING:
			toReturn += "AUTOPILOT SPEED SETTING";
			break;
		case AUTOPILOT_SPEED_SLOT_INDEX:
			toReturn += "AUTOPILOT SPEED SLOT INDEX";
			break;
		case AUTOPILOT_TAKEOFF_POWER_ACTIVE:
			toReturn += "AUTOPILOT TAKEOFF POWER ACTIVE";
			break;
		case AUTOPILOT_THROTTLE_ARM:
			toReturn += "AUTOPILOT THROTTLE ARM";
			break;
		case AUTOPILOT_THROTTLE_MAX_THRUST:
			toReturn += "AUTOPILOT THROTTLE MAX THRUST";
			break;
		case AUTOPILOT_VERTICAL_HOLD:
			toReturn += "AUTOPILOT VERTICAL HOLD";
			break;
		case AUTOPILOT_VERTICAL_HOLD_VAR:
			toReturn += "AUTOPILOT VERTICAL HOLD VAR";
			break;
		case AUTOPILOT_VS_SLOT_INDEX:
			toReturn += "AUTOPILOT VS SLOT INDEX";
			break;
		case AUTOPILOT_WING_LEVELER:
			toReturn += "AUTOPILOT WING LEVELER";
			break;
		case AUTOPILOT_YAW_DAMPER:
			toReturn += "AUTOPILOT YAW DAMPER";
			break;
		case AUTOTHROTTLE_ACTIVE:
			toReturn += "AUTOTHROTTLE ACTIVE";
			break;
		case AUTO_BRAKE_SWITCH_CB:
			toReturn += "AUTO BRAKE SWITCH CB";
			break;
		case AUTO_COORDINATION:
			toReturn += "AUTO COORDINATION";
			break;
		case AUX_WHEEL_ROTATION_ANGLE:
			toReturn += "AUX WHEEL ROTATION ANGLE";
			break;
		case AUX_WHEEL_RPM:
			toReturn += "AUX WHEEL RPM";
			break;
		case AVIONICS_MASTER_SWITCH:
			toReturn += "AVIONICS MASTER SWITCH";
			break;
		case BAGGAGELOADER_ANGLE_CURRENT:
			toReturn += "BAGGAGELOADER_ANGLE_CURRENT";
			break;
		case BAGGAGELOADER_ANGLE_TARGET:
			toReturn += "BAGGAGELOADER_ANGLE_TARGET";
			break;
		case BAGGAGELOADER_END_RAMP_Y:
			toReturn += "BAGGAGELOADER_END_RAMP_Y";
			break;
		case BAGGAGELOADER_END_RAMP_Z:
			toReturn += "BAGGAGELOADER_END_RAMP_Z";
			break;
		case BAGGAGELOADER_PIVOT_Y:
			toReturn += "BAGGAGELOADER_PIVOT_Y";
			break;
		case BAGGAGELOADER_PIVOT_Z:
			toReturn += "BAGGAGELOADER_PIVOT_Z";
			break;
		case BARBER_POLE_MACH:
			toReturn += "BARBER_POLE_MACH";
			break;
		case BAROMETER_PRESSURE:
			toReturn += "BAROMETER_PRESSURE";
			break;
		case BATTERY_BREAKER_PULLED:
			toReturn += "BATTERY_BREAKER_PULLED";
			break;
		case BATTERY_CONNECTION_ON:
			toReturn += "BATTERY_CONNECTION_ON";
			break;
		case BETA_DOT:
			toReturn += "BETA_DOT";
			break;
		case BLAST_SHIELD_POSITION:
			toReturn += "BLAST_SHIELD_POSITION";
			break;
		case BLEED_AIR_APU:
			toReturn += "BLEED_AIR_APU";
			break;
		case BLEED_AIR_ENGINE:
			toReturn += "BLEED AIR ENGINE";
			break;
		case BLEED_AIR_SOURCE_CONTROL:
			toReturn += "BLEED AIR SOURCE CONTROL";
			break;
		case BOARDINGRAMP_ELEVATION_CURRENT:
			toReturn += "BOARDINGRAMP_ELEVATION_CURRENT";
			break;
		case BOARDINGRAMP_ELEVATION_TARGET:
			toReturn += "BOARDINGRAMP_ELEVATION_TARGET";
			break;
		case BOARDINGRAMP_END_POSITION_Y:
			toReturn += "BOARDINGRAMP_END_POSITION_Y";
			break;
		case BOARDINGRAMP_END_POSITION_Z:
			toReturn += "BOARDINGRAMP_END_POSITION_Z";
			break;
		case BOARDINGRAMP_ORIENTATION_CURRENT:
			toReturn += "BOARDINGRAMP_ORIENTATION_CURRENT";
			break;
		case BOARDINGRAMP_ORIENTATION_TARGET:
			toReturn += "BOARDINGRAMP_ORIENTATION_TARGET";
			break;
		case BOARDINGRAMP_START_POSITION_Y:
			toReturn += "BOARDINGRAMP_START_POSITION_Y";
			break;
		case BOARDINGRAMP_START_POSITION_Z:
			toReturn += "BOARDINGRAMP_START_POSITION_Z";
			break;
		case BOMB_AMMO:
			toReturn += "BOMB_AMMO";
			break;
		case BRAKE_DEPENDENT_HYDRAULIC_PRESSURE:
			toReturn += "BRAKE DEPENDENT HYDRAULIC PRESSURE";
			break;
		case BRAKE_INDICATOR:
			toReturn += "BRAKE INDICATOR";
			break;
		case BRAKE_LEFT_POSITION:
			toReturn += "BRAKE LEFT POSITION";
			break;
		case BRAKE_LEFT_POSITION_EX1:
			toReturn += "BRAKE LEFT POSITION EX1";
			break;
		case BRAKE_PARKING_INDICATOR:
			toReturn += "BRAKE PARKING INDICATOR";
			break;
		case BRAKE_PARKING_POSITION:
			toReturn += "BRAKE PARKING POSITION";
			break;
		case BRAKE_RIGHT_POSITION:
			toReturn += "BRAKE RIGHT POSITION";
			break;
		case BRAKE_RIGHT_POSITION_EX1:
			toReturn += "BRAKE RIGHT POSITION EX1";
			break;
		case BREAKER_ADF:
			toReturn += "BREAKER_ADF";
			break;
		case BREAKER_ALTFLD:
			toReturn += "BREAKER_ALTFLD";
			break;
		case BREAKER_AUTOPILOT:
			toReturn += "BREAKER_AUTOPILOT";
			break;
		case BREAKER_AVNBUS1:
			toReturn += "BREAKER_AVNBUS1";
			break;
		case BREAKER_AVNBUS2:
			toReturn += "BREAKER_AVNBUS2";
			break;
		case BREAKER_AVNFAN:
			toReturn += "BREAKER_AVNFAN";
			break;
		case BREAKER_FLAP:
			toReturn += "BREAKER_FLAP";
			break;
		case BREAKER_GPS:
			toReturn += "BREAKER_GPS";
			break;
		case BREAKER_INST:
			toReturn += "BREAKER_INST";
			break;
		case BREAKER_INSTLTS:
			toReturn += "BREAKER_INSTLTS";
			break;
		case BREAKER_LTS_PWR:
			toReturn += "BREAKER_LTS_PWR";
			break;
		case BREAKER_NAVCOM1:
			toReturn += "BREAKER_NAVCOM1";
			break;
		case BREAKER_NAVCOM2:
			toReturn += "BREAKER_NAVCOM2";
			break;
		case BREAKER_NAVCOM3:
			toReturn += "BREAKER_NAVCOM3";
			break;
		case BREAKER_TURNCOORD:
			toReturn += "BREAKER_TURNCOORD";
			break;
		case BREAKER_WARN:
			toReturn += "BREAKER_WARN";
			break;
		case BREAKER_XPNDR:
			toReturn += "BREAKER_XPNDR";
			break;
		case BUS_BREAKER_PULLED:
			toReturn += "BUS_BREAKER_PULLED";
			break;
		case BUS_CONNECTION_ON:
			toReturn += "BUS_CONNECTION_ON";
			break;
		case BUS_LOOKUP_INDEX:
			toReturn += "BUS_LOOKUP_INDEX";
			break;
		case CABIN_NO_SMOKING_ALERT_SWITCH:
			toReturn += "CABIN NO SMOKING ALERT SWITCH";
			break;
		case CABIN_SEATBELTS_ALERT_SWITCH:
			toReturn += "CABIN SEATBELTS ALERT SWITCH";
			break;
		case CABLE_CAUGHT_BY_TAILHOOK:
			toReturn += "CABLE_CAUGHT_BY_TAILHOOK";
			break;
		case CAMERA_ACTION_COCKPIT_VIEW_RESET:
			toReturn += "CAMERA_ACTION_COCKPIT_VIEW_RESET";
			break;
		case CAMERA_ACTION_COCKPIT_VIEW_SAVE:
			toReturn += "CAMERA_ACTION_COCKPIT_VIEW_SAVE";
			break;
		case CAMERA_GAMEPLAY_PITCH_YAW:
			toReturn += "CAMERA_GAMEPLAY_PITCH_YAW";
			break;
		case CAMERA_REQUEST_ACTION:
			toReturn += "CAMERA_REQUEST_ACTION";
			break;
		case CAMERA_STATE:
			toReturn += "CAMERA_STATE";
			break;
		case CAMERA_SUBSTATE:
			toReturn += "CAMERA_SUBSTATE";
			break;
		case CAMERA_VIEW_TYPE_AND_INDEX:
			toReturn += "CAMERA_VIEW_TYPE_AND_INDEX";
			break;
		case CAMERA_VIEW_TYPE_AND_INDEX_MAX:
			toReturn += "CAMERA_VIEW_TYPE_AND_INDEX_MAX";
			break;
		case CANNON_AMMO:
			toReturn += "CANNON_AMMO";
			break;
		case CANOPY_OPEN:
			toReturn += "CANOPY OPEN";
			break;
		case CARB_HEAT_AVAILABLE:
			toReturn += "CARB HEAT AVAILABLE";
			break;
		case CATAPULT_STROKE_POSITION:
			toReturn += "CATAPULT_STROKE_POSITION";
			break;
		case CATEGORY:
			toReturn += "CATEGORY";
			break;
		case CATERINGTRUCK_AIRCRAFT_DOOR_CONTACT_OFFSET_Z:
			toReturn += "CATERINGTRUCK_AIRCRAFT_DOOR_CONTACT_OFFSET_Z";
			break;
		case CATERINGTRUCK_ELEVATION_CURRENT:
			toReturn += "CATERINGTRUCK_ELEVATION_CURRENT";
			break;
		case CATERINGTRUCK_ELEVATION_TARGET:
			toReturn += "CATERINGTRUCK_ELEVATION_TARGET";
			break;
		case CATERINGTRUCK_OPENING_CURRENT:
			toReturn += "CATERINGTRUCK_OPENING_CURRENT";
			break;
		case CATERINGTRUCK_OPENING_TARGET:
			toReturn += "CATERINGTRUCK_OPENING_TARGET";
			break;
		case CENTER_WHEEL_ROTATION_ANGLE:
			toReturn += "CENTER WHEEL ROTATION ANGLE";
			break;
		case CENTER_WHEEL_RPM:
			toReturn += "CENTER WHEEL RPM";
			break;
		case CG_AFT_LIMIT:
			toReturn += "CG_AFT_LIMIT";
			break;
		case CG_FWD_LIMIT:
			toReturn += "CG_FWD_LIMIT";
			break;
		case CG_MAX_MACH:
			toReturn += "CG_MAX_MACH";
			break;
		case CG_MIN_MACH:
			toReturn += "CG_MIN_MACH";
			break;
		case CG_PERCENT:
			toReturn += "CG_PERCENT";
			break;
		case CG_PERCENT_LATERAL:
			toReturn += "CG_PERCENT_LATERAL";
			break;
		case CHASE_CAMERA_HEADLOOK:
			toReturn += "CHASE_CAMERA_HEADLOOK";
			break;
		case CHASE_CAMERA_MOMENTUM:
			toReturn += "CHASE_CAMERA_MOMENTUM";
			break;
		case CHASE_CAMERA_SPEED:
			toReturn += "CHASE_CAMERA_SPEED";
			break;
		case CHASE_CAMERA_ZOOM:
			toReturn += "CHASE_CAMERA_ZOOM";
			break;
		case CHASE_CAMERA_ZOOM_SPEED:
			toReturn += "CHASE_CAMERA_ZOOM_SPEED";
			break;
		case CIRCUIT_AUTOPILOT_ON:
			toReturn += "CIRCUIT_AUTOPILOT_ON";
			break;
		case CIRCUIT_AUTO_BRAKES_ON:
			toReturn += "CIRCUIT_AUTO_BRAKES_ON";
			break;
		case CIRCUIT_AUTO_FEATHER_ON:
			toReturn += "CIRCUIT_AUTO_FEATHER_ON";
			break;
		case CIRCUIT_AVIONICS_ON:
			toReturn += "CIRCUIT_AVIONICS_ON";
			break;
		case CIRCUIT_BREAKER_PULLED:
			toReturn += "CIRCUIT_BREAKER_PULLED";
			break;
		case CIRCUIT_CONNECTION_ON:
			toReturn += "CIRCUIT_CONNECTION_ON";
			break;
		case CIRCUIT_FLAP_MOTOR_ON:
			toReturn += "CIRCUIT_FLAP_MOTOR_ON";
			break;
		case CIRCUIT_GEAR_MOTOR_ON:
			toReturn += "CIRCUIT_GEAR_MOTOR_ON";
			break;
		case CIRCUIT_GEAR_WARNING_ON:
			toReturn += "CIRCUIT_GEAR_WARNING_ON";
			break;
		case CIRCUIT_GENERAL_PANEL_ON:
			toReturn += "CIRCUIT_GENERAL_PANEL_ON";
			break;
		case CIRCUIT_HYDRAULIC_PUMP_ON:
			toReturn += "CIRCUIT_HYDRAULIC_PUMP_ON";
			break;
		case CIRCUIT_MARKER_BEACON_ON:
			toReturn += "CIRCUIT_MARKER_BEACON_ON";
			break;
		case CIRCUIT_NAVCOM_ON1:
			toReturn += "CIRCUIT_NAVCOM_ON1";
			break;
		case CIRCUIT_NAVCOM_ON2:
			toReturn += "CIRCUIT_NAVCOM_ON2";
			break;
		case CIRCUIT_NAVCOM_ON3:
			toReturn += "BREAKER_NAVCOM_ON3";
			break;
		case CIRCUIT_ON:
			toReturn += "CIRCUIT_ON";
			break;
		case CIRCUIT_PITOT_HEAT_ON:
			toReturn += "CIRCUIT_PITOT_HEAT_ON";
			break;
		case CIRCUIT_POWER_SETTING:
			toReturn += "CIRCUIT_POWER_SETTING";
			break;
		case CIRCUIT_PROP_SYNC_ON:
			toReturn += "CIRCUIT_PROP_SYNC_ON";
			break;
		case CIRCUIT_STANDBY_VACUUM_ON:
			toReturn += "CIRCUIT_STANDBY_VACUUM_ON";
			break;
		case CIRCUIT_SWITCH_ON:
			toReturn += "CIRCUIT_SWITCH_ON";
			break;
		case COCKPIT_CAMERA_HEADLOOK:
			toReturn += "COCKPIT_CAMERA_HEADLOOK";
			break;
		case COCKPIT_CAMERA_HEIGHT:
			toReturn += "COCKPIT_CAMERA_HEIGHT";
			break;
		case COCKPIT_CAMERA_INSTRUMENT_AUTOSELECT:
			toReturn += "COCKPIT_CAMERA_INSTRUMENT_AUTOSELECT";
			break;
		case COCKPIT_CAMERA_MOMENTUM:
			toReturn += "COCKPIT_CAMERA_MOMENTUM";
			break;
		case COCKPIT_CAMERA_SIDE:
			toReturn += "COCKPIT_CAMERA_SIDE";
			break;
		case COCKPIT_CAMERA_SPEED:
			toReturn += "COCKPIT_CAMERA_SPEED";
			break;
		case COCKPIT_CAMERA_UPPER_POSITION:
			toReturn += "COCKPIT_CAMERA_UPPER_POSITION";
			break;
		case COCKPIT_CAMERA_ZOOM:
			toReturn += "COCKPIT_CAMERA_ZOOM";
			break;
		case COCKPIT_CAMERA_ZOOM_SPEED:
			toReturn += "COCKPIT_CAMERA_ZOOM_SPEED";
			break;
		case COLLECTIVE_POSITION:
			toReturn += "COLLECTIVE POSITION";
			break;
		case COM1_STORED_FREQUENCY:
			toReturn += "COM1 STORED FREQUENCY";
			break;
		case COM2_STORED_FREQUENCY:
			toReturn += "COM2 STORED FREQUENCY";
			break;
		case COM3_STORED_FREQUENCY:
			toReturn += "COM3 STORED FREQUENCY";
			break;
		case COM_ACTIVE_BEARING:
			toReturn += "COM ACTIVE BEARING";
			break;
		case COM_ACTIVE_DISTANCE:
			toReturn += "COM ACTIVE DISTANCE";
			break;
		case COM_ACTIVE_FREQUENCY:
			toReturn += "COM ACTIVE FREQUENCY";
			break;
		case COM_ACTIVE_FREQ_IDENT:
			toReturn += "COM_ACTIVE_FREQ_IDENT";
			break;
		case COM_ACTIVE_FREQ_TYPE:
			toReturn += "COM_ACTIVE_FREQ_TYPE";
			break;
		case COM_ACTIVE_LATLONALT:
			toReturn += "COM ACTIVE LATLONALT";
			break;
		case COM_AVAILABLE:
			toReturn += "COM AVAILABLE";
			break;
		case COM_LATLONALT:
			toReturn += "COM_LATLONALT";
			break;
		case COM_RECEIVE:
			toReturn += "COM RECEIVE";
			break;
		case COM_RECEIVE_ALL:
			toReturn += "COM RECEIVE ALL";
			break;
		case COM_RECIEVE_ALL:
			toReturn += "COM RECIEVE ALL";
			break;
		case COM_RECEIVE_EX1:
			toReturn += "COM_RECEIVE_EX1";
			break;
		case COM_SPACING_MODE:
			toReturn += "COM SPACING MODE";
			break;
		case COM_STANDBY_FREQUENCY:
			toReturn += "COM STANDBY FREQUENCY";
			break;
		case COM_STANDBY_FREQ_IDENT:
			toReturn += "COM_STANDBY_FREQ_IDENT";
			break;
		case COM_STANDBY_FREQ_TYPE:
			toReturn += "COM_STANDBY_FREQ_TYPE";
			break;
		case COM_STATUS:
			toReturn += "COM STATUS";
			break;
		case COM_TEST:
			toReturn += "COM TEST";
			break;
		case COM_TRANSMIT:
			toReturn += "COM TRANSMIT";
			break;
		case COM_VOLUME:
			toReturn += "COM VOLUME";
			break;
		case CONCORDE_NOSE_ANGLE:
			toReturn += "CONCORDE NOSE ANGLE";
			break;
		case CONCORDE_VISOR_NOSE_HANDLE:
			toReturn += "CONCORDE VISOR NOSE HANDLE";
			break;
		case CONCORDE_VISOR_POSITION_PERCENT:
			toReturn += "CONCORDE VISOR POSITION PERCENT";
			break;
		case CONTACT_POINT_COMPRESSION:
			toReturn += "CONTACT_POINT_COMPRESSION";
			break;
		case CONTACT_POINT_IS_ON_GROUND:
			toReturn += "CONTACT_POINT_IS_ON_GROUND";
			break;
		case CONTACT_POINT_IS_SKIDDING:
			toReturn += "CONTACT_POINT_IS_SKIDDING";
			break;
		case CONTACT_POINT_POSITION:
			toReturn += "CONTACT_POINT_POSITION";
			break;
		case CONTACT_POINT_SKIDDING_FACTOR:
			toReturn += "CONTACT_POINT_SKIDDING_FACTOR";
			break;
		case CONTACT_POINT_WATER_DEPTH:
			toReturn += "CONTACT_POINT_WATER_DEPTH";
			break;
		case CONTRAILS_CONDITIONS_MET:
			toReturn += "CONTRAILS_CONDITIONS_MET";
			break;
		case CONTROLLABLE:
			toReturn += "CONTROLLABLE";
			break;
		case COPILOT_TRANSMITTER_TYPE:
			toReturn += "COPILOT TRANSMITTER TYPE";
			break;
		case COPILOT_TRANSMITTING:
			toReturn += "COPILOT TRANSMITTING";
			break;
		case CRASH_FLAG:
			toReturn += "CRASH_FLAG";
			break;
		case CRASH_SEQUENCE:
			toReturn += "CRASH_SEQUENCE";
			break;
		case DECISION_ALTITUDE_MSL:
			toReturn += "DECISION_ALTITUDE_MSL";
			break;
		case DECISION_HEIGHT:
			toReturn += "DECISION_HEIGHT";
			break;
		case DELEGATE_CONTROLS_TO_AI:
			toReturn += "DELEGATE CONTROLS TO AI";
			break;
		case DELTA_HEADING_RATE:
			toReturn += "DELTA HEADING RATE";
			break;
		case DESIGN_CRUISE_ALT:
			toReturn += "DESIGN_CRUISE_ALT";
			break;
		case DESIGN_SPAWN_ALTITUDE_CRUISE:
			toReturn += "DESIGN_SPAWN_ALTITUDE_CRUISE";
			break;
		case DESIGN_SPAWN_ALTITUDE_DESCENT:
			toReturn += "DESIGN_SPAWN_ALTITUDE_DESCENT";
			break;
		case DESIGN_SPEED_CLIMB:
			toReturn += "DESIGN_SPEED_CLIMB";
			break;
		case DESIGN_SPEED_MIN_ROTATION:
			toReturn += "DESIGN_SPEED_MIN_ROTATION";
			break;
		case DESIGN_SPEED_VC:
			toReturn += "DESIGN_SPEED_VC";
			break;
		case DESIGN_SPEED_VS0:
			toReturn += "DESIGN_SPEED_VS0";
			break;
		case DESIGN_SPEED_VS1:
			toReturn += "DESIGN_SPEED_VS1";
			break;
		case DESIGN_TAKEOFF_SPEED:
			toReturn += "DESIGN_TAKEOFF_SPEED";
			break;
		case DISK_BANK_ANGLE:
			toReturn += "DISK BANK ANGLE";
			break;
		case DISK_BANK_PCT:
			toReturn += "DISK BANK PCT";
			break;
		case DISK_CONING_PCT:
			toReturn += "DISK CONING PCT";
			break;
		case DISK_PITCH_ANGLE:
			toReturn += "DISK PITCH ANGLE";
			break;
		case DISK_PITCH_PCT:
			toReturn += "DISK PITCH PCT";
			break;
		case DME_SOUND:
			toReturn += "DME SOUND";
			break;
		case DRONE_CAMERA_FOCUS:
			toReturn += "DRONE_CAMERA_FOCUS";
			break;
		case DRONE_CAMERA_FOCUS_MODE:
			toReturn += "DRONE_CAMERA_FOCUS_MODE";
			break;
		case DRONE_CAMERA_FOLLOW:
			toReturn += "DRONE_CAMERA_FOLLOW";
			break;
		case DRONE_CAMERA_FOV:
			toReturn += "DRONE_CAMERA_FOV";
			break;
		case DRONE_CAMERA_LOCKED:
			toReturn += "DRONE_CAMERA_LOCKED";
			break;
		case DRONE_CAMERA_SPEED_ROTATION:
			toReturn += "DRONE_CAMERA_SPEED_ROTATION";
			break;
		case DRONE_CAMERA_SPEED_TRAVELLING:
			toReturn += "DRONE_CAMERA_SPEED_TRAVELLING";
			break;
		case DROPPABLE_OBJECTS_COUNT:
			toReturn += "DROPPABLE OBJECTS COUNT";
			break;
		case DROPPABLE_OBJECTS_TYPE:
			toReturn += "DROPPABLE OBJECTS TYPE";
			break;
		case DROPPABLE_OBJECTS_UI_NAME:
			toReturn += "DROPPABLE OBJECTS UI NAME";
			break;
		case DYNAMIC_PRESSURE:
			toReturn += "DYNAMIC_PRESSURE";
			break;
		case ELECTRICAL_AVIONICS_BUS_AMPS:
			toReturn += "ELECTRICAL_AVIONICS_BUS_AMPS";
			break;
		case ELECTRICAL_AVIONICS_BUS_VOLTAGE:
			toReturn += "ELECTRICAL_AVIONICS_BUS_VOLTAGE";
			break;
		case ELECTRICAL_BATTERY_BUS_AMPS:
			toReturn += "ELECTRICAL_BATTERY_BUS_AMPS";
			break;
		case ELECTRICAL_BATTERY_BUS_VOLTAGE:
			toReturn += "ELECTRICAL_BATTERY_BUS_VOLTAGE";
			break;
		case ELECTRICAL_BATTERY_ESTIMATED_CAPACITY_PCT:
			toReturn += "ELECTRICAL_BATTERY_ESTIMATED_CAPACITY_PCT";
			break;
		case ELECTRICAL_BATTERY_LOAD:
			toReturn += "ELECTRICAL_BATTERY_LOAD";
			break;
		case ELECTRICAL_BATTERY_VOLTAGE:
			toReturn += "ELECTRICAL_BATTERY_VOLTAGE";
			break;
		case ELECTRICAL_GENALT_BUS_AMPS:
			toReturn += "ELECTRICAL_GENALT_BUS_AMPS";
			break;
		case ELECTRICAL_GENALT_BUS_VOLTAGE:
			toReturn += "ELECTRICAL_GENALT_BUS_VOLTAGE";
			break;
		case ELECTRICAL_GENALT_LOAD:
			toReturn += "ELECTRICAL_GENALT_LOAD";
			break;
		case ELECTRICAL_HOT_BATTERY_BUS_AMPS:
			toReturn += "ELECTRICAL_HOT_BATTERY_BUS_AMPS";
			break;
		case ELECTRICAL_HOT_BATTERY_BUS_VOLTAGE:
			toReturn += "ELECTRICAL_HOT_BATTERY_BUS_VOLTAGE";
			break;
		case ELECTRICAL_MAIN_BUS_AMPS:
			toReturn += "ELECTRICAL_MAIN_BUS_AMPS";
			break;
		case ELECTRICAL_MAIN_BUS_VOLTAGE:
			toReturn += "ELECTRICAL_MAIN_BUS_VOLTAGE";
			break;
		case ELECTRICAL_MASTER_BATTERY:
			toReturn += "ELECTRICAL_MASTER_BATTERY";
			break;
		case ELECTRICAL_OLD_CHARGING_AMPS:
			toReturn += "ELECTRICAL_OLD_CHARGING_AMPS";
			break;
		case ELECTRICAL_TOTAL_LOAD_AMPS:
			toReturn += "ELECTRICAL_TOTAL_LOAD_AMPS";
			break;
		case ELEVATOR_DEFLECTION:
			toReturn += "ELEVATOR DEFLECTION";
			break;
		case ELEVATOR_DEFLECTION_PCT:
			toReturn += "ELEVATOR DEFLECTION PCT";
			break;
		case ELEVATOR_POSITION:
			toReturn += "ELEVATOR POSITION";
			break;
		case ELEVATOR_TRIM_DISABLED:
			toReturn += "ELEVATOR TRIM DISABLED";
			break;
		case ELEVATOR_TRIM_DOWN_LIMIT:
			toReturn += "ELEVATOR TRIM DOWN LIMIT";
			break;
		case ELEVATOR_TRIM_INDICATOR:
			toReturn += "ELEVATOR TRIM INDICATOR";
			break;
		case ELEVATOR_TRIM_NEUTRAL:
			toReturn += "ELEVATOR TRIM NEUTRAL";
			break;
		case ELEVATOR_TRIM_PCT:
			toReturn += "ELEVATOR TRIM PCT";
			break;
		case ELEVATOR_TRIM_POSITION:
			toReturn += "ELEVATOR TRIM POSITION";
			break;
		case ELEVATOR_TRIM_UP_LIMIT:
			toReturn += "ELEVATOR TRIM UP LIMIT";
			break;
		case ELEVON_DEFLECTION:
			toReturn += "ELEVON DEFLECTION";
			break;
		case ELT_ACTIVATED:
			toReturn += "ELT ACTIVATED";
			break;
		case EMPTY_WEIGHT:
			toReturn += "EMPTY_WEIGHT";
			break;
		case EMPTY_WEIGHT_CROSS_COUPLED_MOI:
			toReturn += "EMPTY_WEIGHT_CROSS_COUPLED_MOI";
			break;
		case EMPTY_WEIGHT_PITCH_MOI:
			toReturn += "EMPTY_WEIGHT_PITCH_MOI";
			break;
		case EMPTY_WEIGHT_ROLL_MOI:
			toReturn += "EMPTY_WEIGHT_ROLL_MOI";
			break;
		case EMPTY_WEIGHT_YAW_MOI:
			toReturn += "EMPTY_WEIGHT_YAW_MOI";
			break;
		case ENGINE_CONTROL_SELECT:
			toReturn += "ENGINE CONTROL SELECT";
			break;
		case ENGINE_PRIMER:
			toReturn += "ENGINE PRIMER";
			break;
		case ENGINE_TYPE:
			toReturn += "ENGINE TYPE";
			break;
		case ENG_ANTI_ICE:
			toReturn += "ENG ANTI ICE";
			break;
		case ENG_COMBUSTION:
			toReturn += "ENG COMBUSTION";
			break;
		case ENG_CYLINDER_HEAD_TEMPERATURE:
			toReturn += "ENG CYLINDER HEAD TEMPERATURE";
			break;
		case ENG_ELECTRICAL_LOAD:
			toReturn += "ENG ELECTRICAL LOAD";
			break;
		case ENG_EXHAUST_GAS_TEMPERATURE:
			toReturn += "ENG EXHAUST GAS TEMPERATURE";
			break;
		case ENG_FAILED:
			toReturn += "ENG FAILED";
			break;
		case ENG_FUEL_FLOW_BUG_POSITION:
			toReturn += "ENG FUEL FLOW BUG POSITION";
			break;
		case ENG_FUEL_FLOW_GPH:
			toReturn += "ENG FUEL FLOW GPH";
			break;
		case ENG_FUEL_FLOW_PPH:
			toReturn += "ENG FUEL FLOW PPH";
			break;
		case ENG_FUEL_FLOW_PPH_SSL:
			toReturn += "ENG FUEL FLOW PPH SSL";
			break;
		case ENG_FUEL_PRESSURE:
			toReturn += "ENG FUEL PRESSURE";
			break;
		case ENG_HYDRAULIC_PRESSURE:
			toReturn += "ENG HYDRAULIC PRESSURE";
			break;
		case ENG_HYDRAULIC_QUANTITY:
			toReturn += "ENG HYDRAULIC QUANTITY";
			break;
		case ENG_MANIFOLD_PRESSURE:
			toReturn += "ENG MANIFOLD PRESSURE";
			break;
		case ENG_MAX_RPM:
			toReturn += "ENG MAX RPM";
			break;
		case ENG_N1_RPM:
			toReturn += "ENG N1 RPM";
			break;
		case ENG_N2_RPM:
			toReturn += "ENG N2 RPM";
			break;
		case ENG_OIL_PRESSURE:
			toReturn += "ENG OIL PRESSURE";
			break;
		case ENG_OIL_QUANTITY:
			toReturn += "ENG OIL QUANTITY";
			break;
		case ENG_OIL_TEMPERATURE:
			toReturn += "ENG OIL TEMPERATURE";
			break;
		case ENG_ON_FIRE:
			toReturn += "ENG ON FIRE";
			break;
		case ENG_PRESSURE_RATIO:
			toReturn += "ENG PRESSURE RATIO";
			break;
		case ENG_PRESSURE_RATIO_GES:
			toReturn += "ENG PRESSURE RATIO GES";
			break;
		case ENG_ROTOR_RPM:
			toReturn += "ENG ROTOR RPM";
			break;
		case ENG_RPM_ANIMATION_PERCENT:
			toReturn += "ENG RPM ANIMATION PERCENT";
			break;
		case ENG_TORQUE:
			toReturn += "ENG TORQUE";
			break;
		case ENG_TORQUE_PERCENT:
			toReturn += "ENG TORQUE PERCENT";
			break;
		case ENG_TRANSMISSION_PRESSURE:
			toReturn += "ENG TRANSMISSION PRESSURE";
			break;
		case ENG_TRANSMISSION_TEMPERATURE:
			toReturn += "ENG TRANSMISSION TEMPERATURE";
			break;
		case ENG_TURBINE_TEMPERATURE:
			toReturn += "ENG TURBINE TEMPERATURE";
			break;
		case ENG_VIBRATION:
			toReturn += "ENG VIBRATION";
			break;
		case ESTIMATED_CRUISE_SPEED:
			toReturn += "ESTIMATED_CRUISE_SPEED";
			break;
		case ESTIMATED_FUEL_FLOW:
			toReturn += "ESTIMATED FUEL FLOW";
			break;
		case EXIT_OPEN:
			toReturn += "EXIT OPEN";
			break;
		case EXIT_POSX:
			toReturn += "EXIT POSX";
			break;
		case EXIT_POSY:
			toReturn += "EXIT POSY";
			break;
		case EXIT_POSZ:
			toReturn += "EXIT POSZ";
			break;
		case EXIT_TYPE:
			toReturn += "EXIT TYPE";
			break;
		case EXTERNAL_POWER_AVAILABLE:
			toReturn += "EXTERNAL_POWER_AVAILABLE";
			break;
		case EXTERNAL_POWER_BREAKER_PULLED:
			toReturn += "EXTERNAL_POWER_BREAKER_PULLED";
			break;
		case EXTERNAL_POWER_CONNECTION_ON:
			toReturn += "EXTERNAL_POWER_CONNECTION_ON";
			break;
		case EXTERNAL_POWER_ON:
			toReturn += "EXTERNAL_POWER_ON";
			break;
		case EXTERNAL_SYSTEM_VALUE:
			toReturn += "EXTERNAL SYSTEM VALUE";
			break;
		case EYEPOINT_POSITION:
			toReturn += "EYEPOINT_POSITION";
			break;
		case FIRE_BOTTLE_DISCHARGED:
			toReturn += "FIRE_BOTTLE_DISCHARGED";
			break;
		case FIRE_BOTTLE_SWITCH:
			toReturn += "FIRE_BOTTLE_SWITCH";
			break;
		case FLAP_DAMAGE_BY_SPEED:
			toReturn += "FLAP_DAMAGE_BY_SPEED";
			break;
		case FLAP_POSITION_SET:
			toReturn += "FLAP_POSITION_SET";
			break;
		case FLAP_SPEED_EXCEEDED:
			toReturn += "FLAP_SPEED_EXCEEDED";
			break;
		case FLAPS_AVAILABLE:
			toReturn += "FLAPS_AVAILABLE";
			break;
		case FLAPS_EFFECTIVE_HANDLE_INDEX:
			toReturn += "FLAPS_EFFECTIVE_HANDLE_INDEX";
			break;
		case FLAPS_HANDLE_INDEX:
			toReturn += "FLAPS_HANDLE_INDEX";
			break;
		case FLAPS_HANDLE_PERCENT:
			toReturn += "FLAPS_HANDLE_PERCENT";
			break;
		case FLAPS_NUM_HANDLE_POSITIONS:
			toReturn += "FLAPS_NUM_HANDLE_POSITIONS";
			break;
		case FLY_ASSISTANT_CANCEL_DESTINATION:
			toReturn += "FLY_ASSISTANT_CANCEL_DESTINATION";
			break;
		case FLY_ASSISTANT_CANCEL_DESTINATION_DISPLAY:
			toReturn += "FLY_ASSISTANT_CANCEL_DESTINATION_DISPLAY";
			break;
		case FLY_ASSISTANT_COM_AI_LOCKED:
			toReturn += "FLY_ASSISTANT_COM_AI_LOCKED";
			break;
		case FLY_ASSISTANT_HAVE_DESTINATION:
			toReturn += "FLY_ASSISTANT_HAVE_DESTINATION";
			break;
		case FLY_ASSISTANT_LANDING_SPEED:
			toReturn += "FLY_ASSISTANT_LANDING_SPEED";
			break;
		case FLY_ASSISTANT_LANDING_SPEED_DISPLAY_MODE:
			toReturn += "FLY_ASSISTANT_LANDING_SPEED_DISPLAY_MODE";
			break;
		case FLY_ASSISTANT_NEAREST_CATEGORY:
			toReturn += "FLY_ASSISTANT_NEAREST_CATEGORY";
			break;
		case FLY_ASSISTANT_NEAREST_COUNT:
			toReturn += "FLY_ASSISTANT_NEAREST_COUNT";
			break;
		case FLY_ASSISTANT_NEAREST_METADATA:
			toReturn += "FLY_ASSISTANT_NEAREST_METADATA";
			break;
		case FLY_ASSISTANT_NEAREST_NAME:
			toReturn += "FLY_ASSISTANT_NEAREST_NAME";
			break;
		case FLY_ASSISTANT_NEAREST_SELECTED:
			toReturn += "FLY_ASSISTANT_NEAREST_SELECTED";
			break;
		case FLY_ASSISTANT_RIBBONS_ACTIVE:
			toReturn += "FLY_ASSISTANT_RIBBONS_ACTIVE";
			break;
		case FLY_ASSISTANT_SET_AS_DESTINATION:
			toReturn += "FLY_ASSISTANT_SET_AS_DESTINATION";
			break;
		case FLY_ASSISTANT_STALL_SPEED:
			toReturn += "FLY_ASSISTANT_STALL_SPEED";
			break;
		case FLY_ASSISTANT_STALL_SPEED_DISPLAY_MODE:
			toReturn += "FLY_ASSISTANT_STALL_SPEED_DISPLAY_MODE";
			break;
		case FLY_ASSISTANT_TAKEOFF_SPEED:
			toReturn += "FLY_ASSISTANT_TAKEOFF_SPEED";
			break;
		case FLY_ASSISTANT_TAKEOFF_SPEED_DISPLAY_MODE:
			toReturn += "FLY_ASSISTANT_TAKEOFF_SPEED_DISPLAY_MODE";
			break;
		case FLY_ASSISTANT_TAKEOFF_SPEED_ESTIMATED:
			toReturn += "FLY_ASSISTANT_TAKEOFF_SPEED_ESTIMATED";
			break;
		case FLY_BY_WIRE_ALPHA_PROTECTION:
			toReturn += "FLY_BY_WIRE_ALPHA_PROTECTION";
			break;
		case FLY_BY_WIRE_ELAC_FAILED:
			toReturn += "FLY_BY_WIRE_ELAC_FAILED";
			break;
		case FLY_BY_WIRE_ELAC_SWITCH:
			toReturn += "FLY_BY_WIRE_ELAC_SWITCH";
			break;
		case FLY_BY_WIRE_FAC_FAILED:
			toReturn += "FLY_BY_WIRE_FAC_FAILED";
			break;
		case FLY_BY_WIRE_FAC_SWITCH:
			toReturn += "FLY_BY_WIRE_FAC_SWITCH";
			break;
		case FLY_BY_WIRE_SEC_FAILED:
			toReturn += "FLY_BY_WIRE_SEC_FAILED";
			break;
		case FLY_BY_WIRE_SEC_SWITCH:
			toReturn += "FLY_BY_WIRE_SEC_SWITCH";
			break;
		case FOLDING_WING_HANDLE_POSITION:
			toReturn += "FOLDING_WING_HANDLE_POSITION";
			break;
		case FOLDING_WING_LEFT_PERCENT:
			toReturn += "FOLDING_WING_LEFT_PERCENT";
			break;
		case FOLDING_WING_RIGHT_PERCENT:
			toReturn += "FOLDING_WING_RIGHT_PERCENT";
			break;
		case FUELSYSTEM_ENGINE_PRESSURE:
			toReturn += "FUELSYSTEM_ENGINE_PRESSURE";
			break;
		case FUELSYSTEM_JUNCTION_SETTING:
			toReturn += "FUELSYSTEM_JUNCTION_SETTING";
			break;
		case FUELSYSTEM_LINE_FUEL_FLOW:
			toReturn += "FUELSYSTEM_LINE_FUEL_FLOW";
			break;
		case FUELSYSTEM_LINE_FUEL_LEVEL:
			toReturn += "FUELSYSTEM_LINE_FUEL_LEVEL";
			break;
		case FUELSYSTEM_LINE_FUEL_PRESSURE:
			toReturn += "FUELSYSTEM_LINE_FUEL_PRESSURE";
			break;
		case FUELSYSTEM_PUMP_ACTIVE:
			toReturn += "FUELSYSTEM_PUMP_ACTIVE";
			break;
		case FUELSYSTEM_PUMP_SWITCH:
			toReturn += "FUELSYSTEM_PUMP_SWITCH";
			break;
		case FUELSYSTEM_TANK_CAPACITY:
			toReturn += "FUELSYSTEM_TANK_CAPACITY";
			break;
		case FUELSYSTEM_TANK_LEVEL:
			toReturn += "FUELSYSTEM_TANK_LEVEL";
			break;
		case FUELSYSTEM_TANK_QUANTITY:
			toReturn += "FUELSYSTEM_TANK_QUANTITY";
			break;
		case FUELSYSTEM_TANK_TOTAL_QUANTITY:
			toReturn += "FUELSYSTEM_TANK_TOTAL_QUANTITY";
			break;
		case FUELSYSTEM_TANK_WEIGHT:
			toReturn += "FUELSYSTEM_TANK_WEIGHT";
			break;
		case FUELSYSTEM_TRIGGER_STATUS:
			toReturn += "FUELSYSTEM_TRIGGER_STATUS";
			break;
		case FUELSYSTEM_VALVE_OPEN:
			toReturn += "FUELSYSTEM_VALVE_OPEN";
			break;
		case FUELSYSTEM_VALVE_SWITCH:
			toReturn += "FUELSYSTEM_VALVE_SWITCH";
			break;
		case FUELTRUCK_HOSE_DEPLOYED:
			toReturn += "FUELTRUCK_HOSE_DEPLOYED";
			break;
		case FUELTRUCK_HOSE_END_POSX:
			toReturn += "FUELTRUCK_HOSE_END_POSX";
			break;
		case FUELTRUCK_HOSE_END_POSZ:
			toReturn += "FUELTRUCK_HOSE_END_POSZ";
			break;
		case FUELTRUCK_HOSE_END_RELATIVE_HEADING:
			toReturn += "FUELTRUCK_HOSE_END_RELATIVE_HEADING";
			break;
		case FUEL_CROSS_FEED:
			toReturn += "FUEL_CROSS_FEED";
			break;
		case FUEL_DUMP_ACTIVE:
			toReturn += "FUEL_DUMP_ACTIVE";
			break;
		case FUEL_DUMP_SWITCH:
			toReturn += "FUEL_DUMP_SWITCH";
			break;
		case FUEL_LEFT_CAPACITY:
			toReturn += "FUEL_LEFT_CAPACITY";
			break;
		case FUEL_LEFT_QUANTITY:
			toReturn += "FUEL_LEFT_QUANTITY";
			break;
		case FUEL_PUMP:
			toReturn += "FUEL_PUMP";
			break;
		case FUEL_RIGHT_CAPACITY:
			toReturn += "FUEL_RIGHT_CAPACITY";
			break;
		case FUEL_RIGHT_QUANTITY:
			toReturn += "FUEL_RIGHT_QUANTITY";
			break;
		case FUEL_SELECTED_QUANTITY:
			toReturn += "FUEL_SELECTED_QUANTITY";
			break;
		case FUEL_SELECTED_QUANTITY_PERCENT:
			toReturn += "FUEL_SELECTED_QUANTITY_PERCENT";
			break;
		case FUEL_SELECTED_TRANSFER_MODE:
			toReturn += "FUEL_SELECTED_TRANSFER_MODE";
			break;
		case FUEL_TANK_CENTER_CAPACITY:
			toReturn += "FUEL_TANK_CENTER_CAPACITY";
			break;
		case FUEL_TANK_CENTER_LEVEL:
			toReturn += "FUEL_TANK_CENTER_LEVEL";
			break;
		case FUEL_TANK_CENTER_QUANTITY:
			toReturn += "FUEL_TANK_CENTER_QUANTITY";
			break;
		case FUEL_TANK_CENTER2_CAPACITY:
			toReturn += "FUEL_TANK_CENTER2_CAPACITY";
			break;
		case FUEL_TANK_CENTER2_LEVEL:
			toReturn += "FUEL_TANK_CENTER2_LEVEL";
			break;
		case FUEL_TANK_CENTER2_QUANTITY:
			toReturn += "FUEL_TANK_CENTER2_QUANTITY";
			break;
		case FUEL_TANK_CENTER3_CAPACITY:
			toReturn += "FUEL_TANK_CENTER3_CAPACITY";
			break;
		case FUEL_TANK_CENTER3_LEVEL:
			toReturn += "FUEL_TANK_CENTER3_LEVEL";
			break;
		case FUEL_TANK_CENTER3_QUANTITY:
			toReturn += "FUEL_TANK_CENTER3_QUANTITY";
			break;
		case FUEL_TANK_EXTERNAL1_CAPACITY:
			toReturn += "FUEL_TANK_EXTERNAL1_CAPACITY";
			break;
		case FUEL_TANK_EXTERNAL1_LEVEL:
			toReturn += "FUEL_TANK_EXTERNAL1_LEVEL";
			break;
		case FUEL_TANK_EXTERNAL1_QUANTITY:
			toReturn += "FUEL_TANK_EXTERNAL1_QUANTITY";
			break;
		case FUEL_TANK_EXTERNAL2_CAPACITY:
			toReturn += "FUEL_TANK_EXTERNAL2_CAPACITY";
			break;
		case FUEL_TANK_EXTERNAL2_LEVEL:
			toReturn += "FUEL_TANK_EXTERNAL2_LEVEL";
			break;
		case FUEL_TANK_EXTERNAL2_QUANTITY:
			toReturn += "FUEL_TANK_EXTERNAL2_QUANTITY";
			break;
		case FUEL_TANK_LEFT_AUX_CAPACITY:
			toReturn += "FUEL_TANK_LEFT_AUX_CAPACITY";
			break;
		case FUEL_TANK_LEFT_AUX_LEVEL:
			toReturn += "FUEL_TANK_LEFT_AUX_LEVEL";
			break;
		case FUEL_TANK_LEFT_AUX_QUANTITY:
			toReturn += "FUEL_TANK_LEFT_AUX_QUANTITY";
			break;
		case FUEL_TANK_LEFT_MAIN_CAPACITY:
			toReturn += "FUEL_TANK_LEFT_MAIN_CAPACITY";
			break;
		case FUEL_TANK_LEFT_MAIN_LEVEL:
			toReturn += "FUEL_TANK_LEFT_MAIN_LEVEL";
			break;
		case FUEL_TANK_LEFT_MAIN_QUANTITY:
			toReturn += "FUEL_TANK_LEFT_MAIN_QUANTITY";
			break;
		case FUEL_TANK_LEFT_TIP_CAPACITY:
			toReturn += "FUEL_TANK_LEFT_TIP_CAPACITY";
			break;
		case FUEL_TANK_LEFT_TIP_LEVEL:
			toReturn += "FUEL_TANK_LEFT_TIP_LEVEL";
			break;
		case FUEL_TANK_LEFT_TIP_QUANTITY:
			toReturn += "FUEL_TANK_LEFT_TIP_QUANTITY";
			break;
		case FUEL_TANK_RIGHT_AUX_CAPACITY:
			toReturn += "FUEL_TANK_RIGHT_AUX_CAPACITY";
			break;
		case FUEL_TANK_RIGHT_AUX_LEVEL:
			toReturn += "FUEL_TANK_RIGHT_AUX_LEVEL";
			break;
		case FUEL_TANK_RIGHT_AUX_QUANTITY:
			toReturn += "FUEL_TANK_RIGHT_AUX_QUANTITY";
			break;
		case FUEL_TANK_RIGHT_MAIN_CAPACITY:
			toReturn += "FUEL_TANK_RIGHT_MAIN_CAPACITY";
			break;
		case FUEL_TANK_RIGHT_MAIN_LEVEL:
			toReturn += "FUEL_TANK_RIGHT_MAIN_LEVEL";
			break;
		case FUEL_TANK_RIGHT_MAIN_QUANTITY:
			toReturn += "FUEL_TANK_RIGHT_MAIN_QUANTITY";
			break;
		case FUEL_TANK_RIGHT_TIP_CAPACITY:
			toReturn += "FUEL_TANK_RIGHT_TIP_CAPACITY";
			break;
		case FUEL_TANK_RIGHT_TIP_LEVEL:
			toReturn += "FUEL_TANK_RIGHT_TIP_LEVEL";
			break;
		case FUEL_TANK_RIGHT_TIP_QUANTITY:
			toReturn += "FUEL_TANK_RIGHT_TIP_QUANTITY";
			break;
		case FUEL_TANK_SELECTOR:
			toReturn += "FUEL_TANK_SELECTOR";
			break;
		case FUEL_TOTAL_CAPACITY:
			toReturn += "FUEL_TOTAL_CAPACITY";
			break;
		case FUEL_TOTAL_QUANTITY:
			toReturn += "FUEL_TOTAL_QUANTITY";
			break;
		case FUEL_TOTAL_QUANTITY_WEIGHT:
			toReturn += "FUEL_TOTAL_QUANTITY_WEIGHT";
			break;
		case FUEL_TRANSFER_PUMP_ON:
			toReturn += "FUEL_TRANSFER_PUMP_ON";
			break;
		case FUEL_WEIGHT_PER_GALLON:
			toReturn += "FUEL_WEIGHT_PER_GALLON";
			break;
		case FULL_THROTTLE_THRUST_TO_WEIGHT_RATIO:
			toReturn += "FULL THROTTLE THRUST TO WEIGHT RATIO";
			break;
		case GAMEPLAY_CAMERA_FOCUS:
			toReturn += "GAMEPLAY_CAMERA_FOCUS";
			break;
		case GEAR_ANIMATION_POSITION:
			toReturn += "GEAR_ANIMATION_POSITION";
			break;
		case GEAR_AUX_POSITION:
			toReturn += "GEAR_AUX_POSITION";
			break;
		case GEAR_AUX_STEER_ANGLE:
			toReturn += "GEAR_AUX_STEER_ANGLE";
			break;
		case GEAR_AUX_STEER_ANGLE_PCT:
			toReturn += "GEAR_AUX_STEER_ANGLE_PCT";
			break;
		case GEAR_CENTER_POSITION:
			toReturn += "GEAR_CENTER_POSITION";
			break;
		case GEAR_CENTER_STEER_ANGLE:
			toReturn += "GEAR_CENTER_STEER_ANGLE";
			break;
		case GEAR_CENTER_STEER_ANGLE_PCT:
			toReturn += "GEAR_CENTER_STEER_ANGLE_PCT";
			break;
		case GEAR_DAMAGE_BY_SPEED:
			toReturn += "GEAR_DAMAGE_BY_SPEED";
			break;
		case GEAR_EMERGENCY_HANDLE_POSITION:
			toReturn += "GEAR_EMERGENCY_HANDLE_POSITION";
			break;
		case GEAR_HANDLE_POSITION:
			toReturn += "GEAR_HANDLE_POSITION";
			break;
		case GEAR_HYDRAULIC_PRESSURE:
			toReturn += "GEAR_HYDRAULIC_PRESSURE";
			break;
		case GEAR_IS_ON_GROUND:
			toReturn += "GEAR_IS_ON_GROUND";
			break;
		case GEAR_IS_SKIDDING:
			toReturn += "GEAR_IS_SKIDDING";
			break;
		case GEAR_LEFT_POSITION:
			toReturn += "GEAR_LEFT_POSITION";
			break;
		case GEAR_LEFT_STEER_ANGLE:
			toReturn += "GEAR_LEFT_STEER_ANGLE";
			break;
		case GEAR_LEFT_STEER_ANGLE_PCT:
			toReturn += "GEAR_LEFT_STEER_ANGLE_PCT";
			break;
		case GEAR_POSITION:
			toReturn += "GEAR_POSITION";
			break;
		case GEAR_RIGHT_POSITION:
			toReturn += "GEAR_RIGHT_POSITION";
			break;
		case GEAR_RIGHT_STEER_ANGLE:
			toReturn += "GEAR_RIGHT_STEER_ANGLE";
			break;
		case GEAR_RIGHT_STEER_ANGLE_PCT:
			toReturn += "GEAR_RIGHT_STEER_ANGLE_PCT";
			break;
		case GEAR_SPEED_EXCEEDED:
			toReturn += "GEAR_SPEED_EXCEEDED";
			break;
		case GEAR_STEER_ANGLE:
			toReturn += "GEAR_STEER_ANGLE";
			break;
		case GEAR_STEER_ANGLE_PCT:
			toReturn += "GEAR_STEER_ANGLE_PCT";
			break;
		case GEAR_TAIL_POSITION:
			toReturn += "GEAR_TAIL_POSITION";
			break;
		case GEAR_TOTAL_PCT_EXTENDED:
			toReturn += "GEAR_TOTAL_PCT_EXTENDED";
			break;
		case GEAR_WARNING:
			toReturn += "GEAR_WARNING";
			break;
		case GEAR_WATER_DEPTH:
			toReturn += "GEAR_WATER_DEPTH";
			break;
		case GENERAL_ENG_ANTI_ICE_POSITION:
			toReturn += "GENERAL ENG ANTI ICE POSITION";
			break;
		case GENERAL_ENG_COMBUSTION:
			toReturn += "GENERAL ENG COMBUSTION";
			break;
		case GENERAL_ENG_COMBUSTION_EX1:
			toReturn += "GENERAL ENG COMBUSTION EX1";
			break;
		case GENERAL_ENG_COMBUSTION_SOUND_PERCENT:
			toReturn += "GENERAL ENG COMBUSTION SOUND PERCENT";
			break;
		case GENERAL_ENG_DAMAGE_PERCENT:
			toReturn += "GENERAL ENG DAMAGE PERCENT";
			break;
		case GENERAL_ENG_ELAPSED_TIME:
			toReturn += "GENERAL ENG ELAPSED TIME";
			break;
		case GENERAL_ENG_EXHAUST_GAS_TEMPERATURE:
			toReturn += "GENERAL ENG EXHAUST GAS TEMPERATURE";
			break;
		case GENERAL_ENG_FAILED:
			toReturn += "GENERAL ENG FAILED";
			break;
		case GENERAL_ENG_FIRE_DETECTED:
			toReturn += "GENERAL ENG FIRE DETECTED";
			break;
		case GENERAL_ENG_FUEL_PRESSURE:
			toReturn += "GENERAL ENG FUEL PRESSURE";
			break;
		case GENERAL_ENG_FUEL_PUMP_ON:
			toReturn += "GENERAL ENG FUEL PUMP ON";
			break;
		case GENERAL_ENG_FUEL_PUMP_SWITCH:
			toReturn += "GENERAL ENG FUEL PUMP SWITCH";
			break;
		case GENERAL_ENG_FUEL_PUMP_SWITCH_EX1:
			toReturn += "GENERAL ENG FUEL PUMP SWITCH EX1";
			break;
		case GENERAL_ENG_FUEL_USED_SINCE_START:
			toReturn += "GENERAL ENG FUEL USED SINCE START";
			break;
		case GENERAL_ENG_FUEL_VALVE:
			toReturn += "GENERAL ENG FUEL VALVE";
			break;
		case GENERAL_ENG_GENERATOR_ACTIVE:
			toReturn += "GENERAL ENG GENERATOR ACTIVE";
			break;
		case GENERAL_ENG_GENERATOR_SWITCH:
			toReturn += "GENERAL ENG GENERATOR SWITCH";
			break;
		case GENERAL_ENG_HOBBS_ELAPSED_TIME:
			toReturn += "GENERAL ENG HOBBS ELAPSED TIME";
			break;
		case GENERAL_ENG_MASTER_ALTERNATOR:
			toReturn += "GENERAL ENG MASTER ALTERNATOR";
			break;
		case GENERAL_ENG_MAX_REACHED_RPM:
			toReturn += "GENERAL ENG MAX REACHED RPM";
			break;
		case GENERAL_ENG_MIXTURE_LEVER_POSITION:
			toReturn += "GENERAL ENG MIXTURE LEVER POSITION";
			break;
		case GENERAL_ENG_OIL_LEAKED_PERCENT:
			toReturn += "GENERAL ENG OIL LEAKED PERCENT";
			break;
		case GENERAL_ENG_OIL_PRESSURE:
			toReturn += "GENERAL ENG OIL PRESSURE";
			break;
		case GENERAL_ENG_OIL_TEMPERATURE:
			toReturn += "GENERAL ENG OIL TEMPERATURE";
			break;
		case GENERAL_ENG_PCT_MAX_RPM:
			toReturn += "GENERAL ENG PCT MAX RPM";
			break;
		case GENERAL_ENG_PROPELLER_LEVER_POSITION:
			toReturn += "GENERAL ENG PROPELLER LEVER POSITION";
			break;
		case GENERAL_ENG_REVERSE_THRUST_ENGAGED:
			toReturn += "GENERAL ENG REVERSE THRUST ENGAGED";
			break;
		case GENERAL_ENG_RPM:
			toReturn += "GENERAL ENG RPM";
			break;
		case GENERAL_ENG_STARTER:
			toReturn += "GENERAL ENG STARTER";
			break;
		case GENERAL_ENG_STARTER_ACTIVE:
			toReturn += "GENERAL ENG STARTER ACTIVE";
			break;
		case GENERAL_ENG_THROTTLE_LEVER_POSITION:
			toReturn += "GENERAL ENG THROTTLE LEVER POSITION";
			break;
		case GENERAL_ENG_THROTTLE_MANAGED_MODE:
			toReturn += "GENERAL ENG THROTTLE MANAGED MODE";
			break;
		case GLASSCOCKPIT_AUTOMATIC_BRIGHTNESS:
			toReturn += "GLASSCOCKPIT_AUTOMATIC_BRIGHTNESS";
			break;
		case GPS_APPROACH_AIRPORT_ID:
			toReturn += "GPS_APPROACH_AIRPORT_ID";
			break;
		case GPS_APPROACH_APPROACH_ID:
			toReturn += "GPS_APPROACH_APPROACH_ID";
			break;
		case GPS_APPROACH_APPROACH_INDEX:
			toReturn += "GPS_APPROACH_APPROACH_INDEX";
			break;
		case GPS_APPROACH_APPROACH_TYPE:
			toReturn += "GPS_APPROACH_APPROACH_TYPE";
			break;
		case GPS_APPROACH_IS_FINAL:
			toReturn += "GPS_APPROACH_IS_FINAL";
			break;
		case GPS_APPROACH_IS_MISSED:
			toReturn += "GPS_APPROACH_IS_MISSED";
			break;
		case GPS_APPROACH_IS_WP_RUNWAY:
			toReturn += "GPS_APPROACH_IS_WP_RUNWAY";
			break;
		case GPS_APPROACH_MODE:
			toReturn += "GPS_APPROACH_MODE";
			break;
		case GPS_APPROACH_SEGMENT_TYPE:
			toReturn += "GPS_APPROACH_SEGMENT_TYPE";
			break;
		case GPS_APPROACH_TIMEZONE_DEVIATION:
			toReturn += "GPS_APPROACH_TIMEZONE_DEVIATION";
			break;
		case GPS_APPROACH_TRANSITION_ID:
			toReturn += "GPS_APPROACH_TRANSITION_ID";
			break;
		case GPS_APPROACH_TRANSITION_INDEX:
			toReturn += "GPS_APPROACH_TRANSITION_INDEX";
			break;
		case GPS_APPROACH_WP_COUNT:
			toReturn += "GPS_APPROACH_WP_COUNT";
			break;
		case GPS_APPROACH_WP_INDEX:
			toReturn += "GPS_APPROACH_WP_INDEX";
			break;
		case GPS_APPROACH_WP_TYPE:
			toReturn += "GPS_APPROACH_WP_TYPE";
			break;
		case GPS_CDI_SCALING:
			toReturn += "GPS CDI SCALING";
			break;
		case GPS_COURSE_TO_STEER:
			toReturn += "GPS_COURSE_TO_STEER";
			break;
		case GPS_DRIVES_NAV1:
			toReturn += "GPS_DRIVES_NAV1";
			break;
		case GPS_ETA:
			toReturn += "GPS_ETA";
			break;
		case GPS_ETE:
			toReturn += "GPS_ETE";
			break;
		case GPS_FLIGHTPLAN_TOTAL_DISTANCE:
			toReturn += "GPS_FLIGHTPLAN_TOTAL_DISTANCE";
			break;
		case GPS_FLIGHT_PLAN_WP_COUNT:
			toReturn += "GPS_FLIGHT_PLAN_WP_COUNT";
			break;
		case GPS_FLIGHT_PLAN_WP_INDEX:
			toReturn += "GPS_FLIGHT_PLAN_WP_INDEX";
			break;
		case GPS_GROUND_MAGNETIC_TRACK:
			toReturn += "GPS_GROUND_MAGNETIC_TRACK";
			break;
		case GPS_GROUND_SPEED:
			toReturn += "GPS_GROUND_SPEED";
			break;
		case GPS_GROUND_TRUE_HEADING:
			toReturn += "GPS_GROUND_TRUE_HEADING";
			break;
		case GPS_GROUND_TRUE_TRACK:
			toReturn += "GPS_GROUND_TRUE_TRACK";
			break;
		case GPS_GSI_SCALING:
			toReturn += "GPS GSI SCALING";
			break;
		case GPS_HAS_GLIDEPATH:
			toReturn += "GPS HAS GLIDEPATH";
			break;
		case GPS_IS_ACTIVE_FLIGHT_PLAN:
			toReturn += "GPS_IS_ACTIVE_FLIGHT_PLAN";
			break;
		case GPS_IS_ACTIVE_WAY_POINT:
			toReturn += "GPS_IS_ACTIVE_WAY_POINT";
			break;
		case GPS_IS_ACTIVE_WP_LOCKED:
			toReturn += "GPS_IS_ACTIVE_WP_LOCKED";
			break;
		case GPS_IS_APPROACH_ACTIVE:
			toReturn += "GPS_IS_APPROACH_ACTIVE";
			break;
		case GPS_IS_APPROACH_LOADED:
			toReturn += "GPS_IS_APPROACH_LOADED";
			break;
		case GPS_IS_ARRIVED:
			toReturn += "GPS_IS_ARRIVED";
			break;
		case GPS_IS_DIRECTTO_FLIGHTPLAN:
			toReturn += "GPS_IS_DIRECTTO_FLIGHTPLAN";
			break;
		case GPS_MAGVAR:
			toReturn += "GPS_MAGVAR";
			break;
		case GPS_OBS_ACTIVE:
			toReturn += "GPS_OBS_ACTIVE";
			break;
		case GPS_OBS_VALUE:
			toReturn += "GPS_OBS_VALUE";
			break;
		case GPS_OVERRIDDEN:
			toReturn += "GPS_OVERRIDDEN";
			break;
		case GPS_POSITION_ALT:
			toReturn += "GPS_POSITION_ALT";
			break;
		case GPS_POSITION_LAT:
			toReturn += "GPS_POSITION_LAT";
			break;
		case GPS_POSITION_LON:
			toReturn += "GPS_POSITION_LON";
			break;
		case GPS_TARGET_ALTITUDE:
			toReturn += "GPS_TARGET_ALTITUDE";
			break;
		case GPS_TARGET_DISTANCE:
			toReturn += "GPS_TARGET_DISTANCE";
			break;
		case GPS_VERTICAL_ANGLE:
			toReturn += "GPS_VERTICAL_ANGLE";
			break;
		case GPS_VERTICAL_ANGLE_ERROR:
			toReturn += "GPS_VERTICAL_ANGLE_ERROR";
			break;
		case GPS_VERTICAL_ERROR:
			toReturn += "GPS_VERTICAL_ERROR";
			break;
		case GPS_WP_BEARING:
			toReturn += "GPS_WP_BEARING";
			break;
		case GPS_WP_CROSS_TRK:
			toReturn += "GPS_WP_CROSS_TRK";
			break;
		case GPS_WP_DESIRED_TRACK:
			toReturn += "GPS_WP_DESIRED_TRACK";
			break;
		case GPS_WP_DISTANCE:
			toReturn += "GPS_WP_DISTANCE";
			break;
		case GPS_WP_ETA:
			toReturn += "GPS_WP_ETA";
			break;
		case GPS_WP_ETE:
			toReturn += "GPS_WP_ETE";
			break;
		case GPS_WP_NEXT_ALT:
			toReturn += "GPS_WP_NEXT_ALT";
			break;
		case GPS_WP_NEXT_ID:
			toReturn += "GPS_WP_NEXT_ID";
			break;
		case GPS_WP_NEXT_LAT:
			toReturn += "GPS_WP_NEXT_LAT";
			break;
		case GPS_WP_NEXT_LON:
			toReturn += "GPS_WP_NEXT_LON";
			break;
		case GPS_WP_PREV_ALT:
			toReturn += "GPS_WP_PREV_ALT";
			break;
		case GPS_WP_PREV_ID:
			toReturn += "GPS_WP_PREV_ID";
			break;
		case GPS_WP_PREV_LAT:
			toReturn += "GPS_WP_PREV_LAT";
			break;
		case GPS_WP_PREV_LON:
			toReturn += "GPS_WP_PREV_LON";
			break;
		case GPS_WP_PREV_VALID:
			toReturn += "GPS_WP_PREV_VALID";
			break;
		case GPS_WP_TRACK_ANGLE_ERROR:
			toReturn += "GPS_WP_TRACK_ANGLE_ERROR";
			break;
		case GPS_WP_TRUE_BEARING:
			toReturn += "GPS_WP_TRUE_BEARING";
			break;
		case GPS_WP_TRUE_REQ_HDG:
			toReturn += "GPS_WP_TRUE_REQ_HDG";
			break;
		case GPS_WP_VERTICAL_SPEED:
			toReturn += "GPS_WP_VERTICAL_SPEED";
			break;
		case GPWS_SYSTEM_ACTIVE:
			toReturn += "GPWS_SYSTEM_ACTIVE";
			break;
		case GPWS_WARNING:
			toReturn += "GPWS_WARNING";
			break;
		case GROUNDPOWERUNIT_HOSE_DEPLOYED:
			toReturn += "GROUNDPOWERUNIT_HOSE_DEPLOYED";
			break;
		case GROUNDPOWERUNIT_HOSE_END_POSX:
			toReturn += "GROUNDPOWERUNIT_HOSE_END_POSX";
			break;
		case GROUNDPOWERUNIT_HOSE_END_POSZ:
			toReturn += "GROUNDPOWERUNIT_HOSE_END_POSZ";
			break;
		case GROUNDPOWERUNIT_HOSE_END_RELATIVE_HEADING:
			toReturn += "GROUNDPOWERUNIT_HOSE_END_RELATIVE_HEADING";
			break;
		case GROUND_ALTITUDE:
			toReturn += "GROUND_ALTITUDE";
			break;
		case GROUND_VELOCITY:
			toReturn += "GROUND_VELOCITY";
			break;
		case GUN_AMMO:
			toReturn += "GUN_AMMO";
			break;
		case GYRO_DRIFT_ERROR:
			toReturn += "GYRO_DRIFT_ERROR";
			break;
		case G_FORCE:
			toReturn += "G_FORCE";
			break;
		case G_LIMITER_SETTING:
			toReturn += "G_LIMITER_SETTING";
			break;
		case HAS_STALL_PROTECTION:
			toReturn += "HAS_STALL_PROTECTION";
			break;
		case HAND_ANIM_STATE:
			toReturn += "HAND ANIM STATE";
			break;
		case HEADING_INDICATOR:
			toReturn += "HEADING_INDICATOR";
			break;
		case HOLDBACK_BAR_INSTALLED:
			toReturn += "HOLDBACK_BAR_INSTALLED";
			break;
		case HSI_BEARING:
			toReturn += "HSI_BEARING";
			break;
		case HSI_BEARING_VALID:
			toReturn += "HSI_BEARING_VALID";
			break;
		case HSI_CDI_NEEDLE:
			toReturn += "HSI_CDI_NEEDLE";
			break;
		case HSI_CDI_NEEDLE_VALID:
			toReturn += "HSI_CDI_NEEDLE_VALID";
			break;
		case HSI_DISTANCE:
			toReturn += "HSI_DISTANCE";
			break;
		case HSI_GSI_NEEDLE:
			toReturn += "HSI_GSI_NEEDLE";
			break;
		case HSI_GSI_NEEDLE_VALID:
			toReturn += "HSI_GSI_NEEDLE_VALID";
			break;
		case HSI_HAS_LOCALIZER:
			toReturn += "HSI_HAS_LOCALIZER";
			break;
		case HSI_SPEED:
			toReturn += "HSI_SPEED";
			break;
		case HSI_STATION_IDENT:
			toReturn += "HSI_STATION_IDENT";
			break;
		case HSI_TF_FLAGS:
			toReturn += "HSI_TF_FLAGS";
			break;
		case HYDRAULIC_PRESSURE:
			toReturn += "HYDRAULIC_PRESSURE";
			break;
		case HYDRAULIC_RESERVOIR_PERCENT:
			toReturn += "HYDRAULIC_RESERVOIR_PERCENT";
			break;
		case HYDRAULIC_SWITCH:
			toReturn += "HYDRAULIC_SWITCH";
			break;
		case HYDRAULIC_SYSTEM_INTEGRITY:
			toReturn += "HYDRAULIC_SYSTEM_INTEGRITY";
			break;
		case IDLE_ANIMATION_ID:
			toReturn += "IDLE_ANIMATION_ID";
			break;
		case INCIDENCE_ALPHA:
			toReturn += "INCIDENCE_ALPHA";
			break;
		case INCIDENCE_BETA:
			toReturn += "INCIDENCE_BETA";
			break;
		case INDICATED_ALTITUDE:
			toReturn += "INDICATED_ALTITUDE";
			break;
		case INDICATED_ALTITUDE_CALIBRATED:
			toReturn += "INDICATED_ALTITUDE_CALIBRATED";
			break;
		case INDICATED_ALTITUDE_EX1:
			toReturn += "INDICATED_ALTITUDE_EX1";
			break;
		case INDUCTOR_COMPASS_HEADING_REF:
			toReturn += "INDUCTOR_COMPASS_HEADING_REF";
			break;
		case INDUCTOR_COMPASS_PERCENT_DEVIATION:
			toReturn += "INDUCTOR_COMPASS_PERCENT_DEVIATION";
			break;
		case INNER_MARKER:
			toReturn += "INNER_MARKER";
			break;
		case INNER_MARKER_LATLONALT:
			toReturn += "INNER_MARKER_LATLONALT";
			break;
		case INSTRUMENTS_AVAILABLE:
			toReturn += "INSTRUMENTS_AVAILABLE";
			break;
		case INTERACTIVE_POINT_BANK:
			toReturn += "INTERACTIVE_POINT_BANK";
			break;
		case INTERACTIVE_POINT_HEADING:
			toReturn += "INTERACTIVE_POINT_HEADING";
			break;
		case INTERACTIVE_POINT_JETWAY_LEFT_BEND:
			toReturn += "INTERACTIVE_POINT_JETWAY_LEFT_BEND";
			break;
		case INTERACTIVE_POINT_JETWAY_LEFT_DEPLOYMENT:
			toReturn += "INTERACTIVE_POINT_JETWAY_LEFT_DEPLOYMENT";
			break;
		case INTERACTIVE_POINT_JETWAY_RIGHT_BEND:
			toReturn += "INTERACTIVE_POINT_JETWAY_RIGHT_BEND";
			break;
		case INTERACTIVE_POINT_JETWAY_RIGHT_DEPLOYMENT:
			toReturn += "INTERACTIVE_POINT_JETWAY_RIGHT_DEPLOYMENT";
			break;
		case INTERACTIVE_POINT_JETWAY_TOP_HORIZONTAL:
			toReturn += "INTERACTIVE_POINT_JETWAY_TOP_HORIZONTAL";
			break;
		case INTERACTIVE_POINT_JETWAY_TOP_VERTICAL:
			toReturn += "INTERACTIVE_POINT_JETWAY_TOP_VERTICAL";
			break;
		case INTERACTIVE_POINT_GOAL:
			toReturn += "INTERACTIVE_POINT_GOAL";
			break;
		case INTERACTIVE_POINT_OPEN:
			toReturn += "INTERACTIVE_POINT_OPEN";
			break;
		case INTERACTIVE_POINT_PITCH:
			toReturn += "INTERACTIVE_POINT_PITCH";
			break;
		case INTERACTIVE_POINT_POSX:
			toReturn += "INTERACTIVE_POINT_POSX";
			break;
		case INTERACTIVE_POINT_POSY:
			toReturn += "INTERACTIVE_POINT_POSY";
			break;
		case INTERACTIVE_POINT_POSZ:
			toReturn += "INTERACTIVE_POINT_POSZ";
			break;
		case INTERACTIVE_POINT_TYPE:
			toReturn += "INTERACTIVE_POINT_TYPE";
			break;
		case INTERCOM_MODE:
			toReturn += "INTERCOM_MODE";
			break;
		case INTERCOM_SYSTEM_ACTIVE:
			toReturn += "INTERCOM_SYSTEM_ACTIVE";
			break;
		case IS_ALTITUDE_FREEZE_ON:
			toReturn += "IS_ALTITUDE_FREEZE_ON";
			break;
		case IS_ANY_INTERIOR_LIGHT_ON:
			toReturn += "IS_ANY_INTERIOR_LIGHT_ON";
			break;
		case IS_ATTACHED_TO_SLING:
			toReturn += "IS_ATTACHED_TO_SLING";
			break;
		case IS_ATTITUDE_FREEZE_ON:
			toReturn += "IS_ATTITUDE_FREEZE_ON";
			break;
		case IS_GEAR_FLOATS:
			toReturn += "IS_GEAR_FLOATS";
			break;
		case IS_GEAR_RETRACTABLE:
			toReturn += "IS_GEAR_RETRACTABLE";
			break;
		case IS_GEAR_SKIDS:
			toReturn += "IS_GEAR_SKIDS";
			break;
		case IS_GEAR_SKIS:
			toReturn += "IS_GEAR_SKIS";
			break;
		case IS_GEAR_WHEELS:
			toReturn += "IS_GEAR_WHEELS";
			break;
		case IS_LATITUDE_LONGITUDE_FREEZE_ON:
			toReturn += "IS_LATITUDE_LONGITUDE_FREEZE_ON";
			break;
		case IS_SLEW_ACTIVE:
			toReturn += "IS_SLEW_ACTIVE";
			break;
		case IS_SLEW_ALLOWED:
			toReturn += "IS_SLEW_ALLOWED";
			break;
		case IS_TAIL_DRAGGER:
			toReturn += "IS_TAIL_DRAGGER";
			break;
		case IS_USER_SIM:
			toReturn += "IS_USER_SIM";
			break;
		case JETWAY_HOOD_LEFT_BEND:
			toReturn += "JETWAY_HOOD_LEFT_BEND";
			break;
		case JETWAY_HOOD_LEFT_DEPLOYMENT:
			toReturn += "JETWAY_HOOD_LEFT_DEPLOYMENT";
			break;
		case JETWAY_HOOD_RIGHT_BEND:
			toReturn += "JETWAY_HOOD_RIGHT_BEND";
			break;
		case JETWAY_HOOD_RIGHT_DEPLOYMENT:
			toReturn += "JETWAY_HOOD_RIGHT_DEPLOYMENT";
			break;
		case JETWAY_HOOD_TOP_HORIZONTAL:
			toReturn += "JETWAY_HOOD_TOP_HORIZONTAL";
			break;
		case JETWAY_HOOD_TOP_VERTICAL:
			toReturn += "JETWAY_HOOD_TOP_VERTICAL";
			break;
		case JETWAY_MOVING:
			toReturn += "JETWAY_MOVING";
			break;
		case JETWAY_WHEEL_ORIENTATION_CURRENT:
			toReturn += "JETWAY_WHEEL_ORIENTATION_CURRENT";
			break;
		case JETWAY_WHEEL_ORIENTATION_TARGET:
			toReturn += "JETWAY_WHEEL_ORIENTATION_TARGET";
			break;
		case JETWAY_WHEEL_SPEED:
			toReturn += "JETWAY_WHEEL_SPEED";
			break;
		case KOHLSMAN_SETTING_HG:
			toReturn += "KOHLSMAN_SETTING_HG";
			break;
		case KOHLSMAN_SETTING_MB:
			toReturn += "KOHLSMAN_SETTING_MB";
			break;
		case KOHLSMAN_SETTING_STD:
			toReturn += "KOHLSMAN_SETTING_STD";
			break;
		case LANDING_LIGHT_PBH:
			toReturn += "LANDING_LIGHT_PBH";
			break;
		case LAUNCHBAR_HELD_EXTENDED:
			toReturn += "LAUNCHBAR_HELD_EXTENDED";
			break;
		case LAUNCHBAR_POSITION:
			toReturn += "LAUNCHBAR_POSITION";
			break;
		case LAUNCHBAR_SWITCH:
			toReturn += "LAUNCHBAR_SWITCH";
			break;
		case LEADING_EDGE_FLAPS_LEFT_ANGLE:
			toReturn += "LEADING_EDGE_FLAPS_LEFT_ANGLE";
			break;
		case LEADING_EDGE_FLAPS_LEFT_INDEX:
			toReturn += "LEADING_EDGE_FLAPS_LEFT_INDEX";
			break;
		case LEADING_EDGE_FLAPS_LEFT_PERCENT:
			toReturn += "LEADING_EDGE_FLAPS_LEFT_PERCENT";
			break;
		case LEADING_EDGE_FLAPS_RIGHT_ANGLE:
			toReturn += "LEADING_EDGE_FLAPS_RIGHT_ANGLE";
			break;
		case LEADING_EDGE_FLAPS_RIGHT_INDEX:
			toReturn += "LEADING_EDGE_FLAPS_RIGHT_INDEX";
			break;
		case LEADING_EDGE_FLAPS_RIGHT_PERCENT:
			toReturn += "LEADING_EDGE_FLAPS_RIGHT_PERCENT";
			break;
		case LEFT_WHEEL_ROTATION_ANGLE:
			toReturn += "LEFT_WHEEL_ROTATION_ANGLE";
			break;
		case LEFT_WHEEL_RPM:
			toReturn += "LEFT_WHEEL_RPM";
			break;
		case LIGHT_BACKLIGHT_INTENSITY:
			toReturn += "LIGHT_BACKLIGHT_INTENSITY";
			break;
		case LIGHT_BEACON:
			toReturn += "LIGHT_BEACON";
			break;
		case LIGHT_BEACON_ON:
			toReturn += "LIGHT_BEACON_ON";
			break;
		case LIGHT_BRAKE_ON:
			toReturn += "LIGHT_BRAKE_ON";
			break;
		case LIGHT_CABIN:
			toReturn += "LIGHT_CABIN";
			break;
		case LIGHT_CABIN_ON:
			toReturn += "LIGHT_CABIN_ON";
			break;
		case LIGHT_CABIN_POWER_SETTING:
			toReturn += "LIGHT_CABIN_POWER_SETTING";
			break;
		case LIGHT_GLARESHIELD:
			toReturn += "LIGHT_GLARESHIELD";
			break;
		case LIGHT_GLARESHIELD_ON:
			toReturn += "LIGHT_GLARESHIELD_ON";
			break;
		case LIGHT_GLARESHIELD_POWER_SETTING:
			toReturn += "LIGHT_GLARESHIELD_POWER_SETTING";
			break;
		case LIGHT_HEADLIGHT_INTENSITY:
			toReturn += "LIGHT_HEADLIGHT_INTENSITY";
			break;
		case LIGHT_HEAD_ON:
			toReturn += "LIGHT_HEAD_ON";
			break;
		case LIGHT_LANDING:
			toReturn += "LIGHT_LANDING";
			break;
		case LIGHT_LANDING_ON:
			toReturn += "LIGHT_LANDING_ON";
			break;
		case LIGHT_LOGO:
			toReturn += "LIGHT_LOGO";
			break;
		case LIGHT_LOGO_ON:
			toReturn += "LIGHT_LOGO_ON";
			break;
		case LIGHT_NAV:
			toReturn += "LIGHT_NAV";
			break;
		case LIGHT_NAV_ON:
			toReturn += "LIGHT_NAV_ON";
			break;
		case LIGHT_ON_STATES:
			toReturn += "LIGHT_ON_STATES";
			break;
		case LIGHT_PANEL:
			toReturn += "LIGHT_PANEL";
			break;
		case LIGHT_PANEL_ON:
			toReturn += "LIGHT_PANEL_ON";
			break;
		case LIGHT_PANEL_POWER_SETTING:
			toReturn += "LIGHT_PANEL_POWER_SETTING";
			break;
		case LIGHT_PEDESTRAL:
			toReturn += "LIGHT_PEDESTRAL";
			break;
		case LIGHT_PEDESTRAL_ON:
			toReturn += "LIGHT_PEDESTRAL_ON";
			break;
		case LIGHT_PEDESTRAL_POWER_SETTING:
			toReturn += "LIGHT_PEDESTRAL_POWER_SETTING";
			break;
		case LIGHT_POTENTIOMETER:
			toReturn += "LIGHT_POTENTIOMETER";
			break;
		case LIGHT_RECOGNITION:
			toReturn += "LIGHT_RECOGNITION";
			break;
		case LIGHT_RECOGNITION_ON:
			toReturn += "LIGHT_RECOGNITION_ON";
			break;
		case LIGHT_STATES:
			toReturn += "LIGHT_STATES";
			break;
		case LIGHT_STROBE:
			toReturn += "LIGHT_STROBE";
			break;
		case LIGHT_STROBE_ON:
			toReturn += "LIGHT_STROBE_ON";
			break;
		case LIGHT_TAXI:
			toReturn += "LIGHT_TAXI";
			break;
		case LIGHT_TAXI_ON:
			toReturn += "LIGHT_TAXI_ON";
			break;
		case LIGHT_WING:
			toReturn += "LIGHT_WING";
			break;
		case LIGHT_WING_ON:
			toReturn += "LIGHT_WING_ON";
			break;
		case LINEAR_CL_ALPHA:
			toReturn += "LINEAR_CL_ALPHA";
			break;
		case MACH_MAX_OPERATE:
			toReturn += "MACH_MAX_OPERATE";
			break;
		case MAGNETIC_COMPASS:
			toReturn += "MAGNETIC_COMPASS";
			break;
		case MAGVAR:
			toReturn += "MAGVAR";
			break;
		case MANUAL_FUEL_PUMP_HANDLE:
			toReturn += "MANUAL_FUEL_PUMP_HANDLE";
			break;
		case MANUAL_INSTRUMENT_LIGHTS:
			toReturn += "MANUAL_INSTRUMENT_LIGHTS";
			break;
		case MARKER_AVAILABLE:
			toReturn += "MARKER_AVAILABLE";
			break;
		case MARKER_BEACON_SENSITIVITY_HIGH:
			toReturn += "MARKER_BEACON_SENSITIVITY_HIGH";
			break;
		case MARKER_BEACON_STATE:
			toReturn += "MARKER_BEACON_STATE";
			break;
		case MARKER_BEACON_TEST_MUTE:
			toReturn += "MARKER_BEACON_TEST_MUTE";
			break;
		case MARKER_SOUND:
			toReturn += "MARKER_SOUND";
			break;
		case MARSHALLER_AIRCRAFT_DIRECTION_PARKINGSPACE:
			toReturn += "MARSHALLER_AIRCRAFT_DIRECTION_PARKINGSPACE";
			break;
		case MARSHALLER_AIRCRAFT_DISTANCE:
			toReturn += "MARSHALLER_AIRCRAFT_DISTANCE";
			break;
		case MARSHALLER_AIRCRAFT_DISTANCE_DIRECTION_Z_PARKINGSPACE:
			toReturn += "MARSHALLER_AIRCRAFT_DISTANCE_DIRECTION_Z_PARKINGSPACE";
			break;
		case MARSHALLER_AIRCRAFT_ENGINE_SHUTDOWN:
			toReturn += "MARSHALLER_AIRCRAFT_ENGINE_SHUTDOWN";
			break;
		case MARSHALLER_AIRCRAFT_HEADING_PARKINGSPACE:
			toReturn += "MARSHALLER_AIRCRAFT_HEADING_PARKINGSPACE";
			break;
		case MARSHALLER_AIRCRAFT_PROJECTION_POINT_PARKINGSPACE:
			toReturn += "MARSHALLER_AIRCRAFT_PROJECTION_POINT_PARKINGSPACE";
			break;
		case MARSHALLER_AIRCRAFT_VELOCITY:
			toReturn += "MARSHALLER_AIRCRAFT_VELOCITY";
			break;
		case MASTER_IGNITION_SWITCH:
			toReturn += "MASTER_IGNITION_SWITCH";
			break;
		case MAX_GROSS_WEIGHT:
			toReturn += "MAX_GROSS_WEIGHT";
			break;
		case MAX_G_FORCE:
			toReturn += "MAX_G_FORCE";
			break;
		case MAX_RATED_ENGINE_RPM:
			toReturn += "MAX RATED ENGINE RPM";
			break;
		case MIDDLE_MARKER:
			toReturn += "MIDDLE_MARKER";
			break;
		case MIDDLE_MARKER_LATLONALT:
			toReturn += "MIDDLE_MARKER_LATLONALT";
			break;
		case MIN_DRAG_VELOCITY:
			toReturn += "MIN_DRAG_VELOCITY";
			break;
		case MIN_G_FORCE:
			toReturn += "MIN_G_FORCE";
			break;
		case MISSION_SCORE:
			toReturn += "MISSION_SCORE";
			break;
		case NAV_ACTIVE_FREQUENCY:
			toReturn += "NAV_ACTIVE_FREQUENCY";
			break;
		case NAV_AVAILABLE:
			toReturn += "NAV_AVAILABLE";
			break;
		case NAV_BACK_COURSE_FLAGS:
			toReturn += "NAV_BACK_COURSE_FLAGS";
			break;
		case NAV_CDI:
			toReturn += "NAV_CDI";
			break;
		case NAV_CLOSE_DME:
			toReturn += "NAV_CLOSE_DME";
			break;
		case NAV_CLOSE_FREQUENCY:
			toReturn += "NAV_CLOSE_FREQUENCY";
			break;
		case NAV_CLOSE_IDENT:
			toReturn += "NAV_CLOSE_IDENT";
			break;
		case NAV_CLOSE_LOCALIZER:
			toReturn += "NAV_CLOSE_LOCALIZER";
			break;
		case NAV_CLOSE_NAME:
			toReturn += "NAV_CLOSE_NAME";
			break;
		case NAV_CODES:
			toReturn += "NAV_CODES";
			break;
		case NAV_DME:
			toReturn += "NAV_DME";
			break;
		case NAV_DMESPEED:
			toReturn += "NAV_DMESPEED";
			break;
		case NAV_DME_LATLONALT:
			toReturn += "NAV_DME_LATLONALT";
			break;
		case NAV_FREQUENCY:
			toReturn += "NAV_FREQUENCY";
			break;
		case NAV_GLIDE_SLOPE:
			toReturn += "NAV_GLIDE_SLOPE";
			break;
		case NAV_GLIDE_SLOPE_ERROR:
			toReturn += "NAV_GLIDE_SLOPE_ERROR";
			break;
		case NAV_GLIDE_SLOPE_LENGTH:
			toReturn += "NAV_GLIDE_SLOPE_LENGTH";
			break;
		case NAV_GSI:
			toReturn += "NAV_GSI";
			break;
		case NAV_GS_FLAG:
			toReturn += "NAV_GS_FLAG";
			break;
		case NAV_GS_LATLONALT:
			toReturn += "NAV_GS_LATLONALT";
			break;
		case NAV_GS_LLAF64:
			toReturn += "NAV_GS_LLAF64";
			break;
		case NAV_HAS_CLOSE_DM:
			toReturn += "NAV_HAS_CLOSE_DM";
			break;
		case NAV_HAS_CLOSE_LOCALIZER:
			toReturn += "NAV_HAS_CLOSE_LOCALIZER";
			break;
		case NAV_HAS_DME:
			toReturn += "NAV_HAS_DME";
			break;
		case NAV_HAS_GLIDE_SLOPE:
			toReturn += "NAV_HAS_GLIDE_SLOPE";
			break;
		case NAV_HAS_LOCALIZER:
			toReturn += "NAV_HAS_LOCALIZER";
			break;
		case NAV_HAS_NAV:
			toReturn += "NAV_HAS_NAV";
			break;
		case NAV_HAS_TACAN:
			toReturn += "NAV_HAS_TACAN";
			break;
		case NAV_IDENT:
			toReturn += "NAV_IDENT";
			break;
		case NAV_LOCALIZER:
			toReturn += "NAV_LOCALIZER";
			break;
		case NAV_LOC_AIRPORT_IDENT:
			toReturn += "NAV_LOC_AIRPORT_IDENT";
			break;
		case NAV_LOC_RUNWAY_DESIGNATOR:
			toReturn += "NAV_LOC_RUNWAY_DESIGNATOR";
			break;
		case NAV_LOC_RUNWAY_NUMBER:
			toReturn += "NAV_LOC_RUNWAY_NUMBER";
			break;
		case NAV_MAGVAR:
			toReturn += "NAV_MAGVAR";
			break;
		case NAV_NAME:
			toReturn += "NAV_NAME";
			break;
		case NAV_OBS:
			toReturn += "NAV_OBS";
			break;
		case NAV_RADIAL:
			toReturn += "NAV_RADIAL";
			break;
		case NAV_RADIAL_ERROR:
			toReturn += "NAV_RADIAL_ERROR";
			break;
		case NAV_RAW_GLIDE_SLOPE:
			toReturn += "NAV_RAW_GLIDE_SLOPE";
			break;
		case NAV_RELATIVE_BEARING_TO_STATION:
			toReturn += "NAV_RELATIVE_BEARING_TO_STATION";
			break;
		case NAV_SIGNAL:
			toReturn += "NAV_SIGNAL";
			break;
		case NAV_SOUND:
			toReturn += "NAV_SOUND";
			break;
		case NAV_STANDBY_FREQUENCY:
			toReturn += "NAV_STANDBY_FREQUENCY";
			break;
		case NAV_TOFROM:
			toReturn += "NAV_TOFROM";
			break;
		case NAV_VOLUME:
			toReturn += "NAV_VOLUME";
			break;
		case NAV_VOR_DISTANCE:
			toReturn += "NAV_VOR_DISTANCE";
			break;
		case NAV_VOR_LATLONALT:
			toReturn += "NAV_VOR_LATLONALT";
			break;
		case NAV_VOR_LLAF64:
			toReturn += "NAV_VOR_LLAF64";
			break;
		case NEW_ELECTRICAL_SYSTEM:
			toReturn += "NEW_ELECTRICAL_SYSTEM";
			break;
		case NEW_FUEL_SYSTEM:
			toReturn += "NEW_FUEL_SYSTEM";
			break;
		case NOSEWHEEL_LOCK_ON:
			toReturn += "NOSEWHEEL_LOCK_ON";
			break;
		case NOSEWHEEL_MAX_STEERING_ANGLE:
			toReturn += "NOSEWHEEL_MAX_STEERING_ANGLE";
			break;
		case NUMBER_OF_CATAPULTS:
			toReturn += "NUMBER_OF_CATAPULTS";
			break;
		case NUMBER_OF_ENGINES:
			toReturn += "NUMBER_OF_ENGINES";
			break;
		case NUM_FUEL_SELECTORS:
			toReturn += "NUM_FUEL_SELECTORS";
			break;
		case NUM_SLING_CABLES:
			toReturn += "NUM_SLING_CABLES";
			break;
		case OIL_AMOUNT:
			toReturn += "OIL_AMOUNT";
			break;
		case ON_ANY_RUNWAY:
			toReturn += "ON_ANY_RUNWAY";
			break;
		case OUTER_MARKER:
			toReturn += "OUTER_MARKER";
			break;
		case OUTER_MARKER_LATLONALT:
			toReturn += "OUTER_MARKER_LATLONALT";
			break;
		case OVERSPEED_WARNING:
			toReturn += "OVERSPEED_WARNING";
			break;
		case PANEL_ANTI_ICE_SWITCH:
			toReturn += "PANEL_ANTI_ICE_SWITCH";
			break;
		case PANEL_AUTO_FEATHER_SWITCH:
			toReturn += "PANEL_AUTO_FEATHER_SWITCH";
			break;
		case PARTIAL_PANEL_ADF:
			toReturn += "PARTIAL_PANEL_ADF";
			break;
		case PARTIAL_PANEL_AIRSPEED:
			toReturn += "PARTIAL_PANEL_AIRSPEED";
			break;
		case PARTIAL_PANEL_ALTIMETER:
			toReturn += "PARTIAL_PANEL_ALTIMETER";
			break;
		case PARTIAL_PANEL_ATTITUDE:
			toReturn += "PARTIAL_PANEL_ATTITUDE";
			break;
		case PARTIAL_PANEL_AVIONICS:
			toReturn += "PARTIAL_PANEL_AVIONICS";
			break;
		case PARTIAL_PANEL_COMM:
			toReturn += "PARTIAL_PANEL_COMM";
			break;
		case PARTIAL_PANEL_COMPASS:
			toReturn += "PARTIAL_PANEL_COMPASS";
			break;
		case PARTIAL_PANEL_ELECTRICAL:
			toReturn += "PARTIAL_PANEL_ELECTRICAL";
			break;
		case PARTIAL_PANEL_ENGINE:
			toReturn += "PARTIAL_PANEL_ENGINE";
			break;
		case PARTIAL_PANEL_FUEL_INDICATOR:
			toReturn += "PARTIAL_PANEL_FUEL_INDICATOR";
			break;
		case PARTIAL_PANEL_HEADING:
			toReturn += "PARTIAL_PANEL_HEADING";
			break;
		case PARTIAL_PANEL_NAV:
			toReturn += "PARTIAL_PANEL_NAV";
			break;
		case PARTIAL_PANEL_PITOT:
			toReturn += "PARTIAL_PANEL_PITOT";
			break;
		case PARTIAL_PANEL_TRANSPONDER:
			toReturn += "PARTIAL_PANEL_TRANSPONDER";
			break;
		case PARTIAL_PANEL_TURN_COORDINATOR:
			toReturn += "PARTIAL_PANEL_TURN_COORDINATOR";
			break;
		case PARTIAL_PANEL_VACUUM:
			toReturn += "PARTIAL_PANEL_VACUUM";
			break;
		case PARTIAL_PANEL_VERTICAL_VELOCITY:
			toReturn += "PARTIAL_PANEL_VERTICAL_VELOCITY";
			break;
		case PAYLOAD_STATION_COUNT:
			toReturn += "PAYLOAD_STATION_COUNT";
			break;
		case PAYLOAD_STATION_NAME:
			toReturn += "PAYLOAD_STATION_NAME";
			break;
		case PAYLOAD_STATION_NUM_SIMOBJECTS:
			toReturn += "PAYLOAD_STATION_NUM_SIMOBJECTS";
			break;
		case PAYLOAD_STATION_OBJECT:
			toReturn += "PAYLOAD_STATION_OBJECT";
			break;
		case PAYLOAD_STATION_WEIGHT:
			toReturn += "PAYLOAD_STATION_WEIGHT";
			break;
		case PILOT_TRANSMITTER_TYPE:
			toReturn += "PILOT_TRANSMITTER_TYPE";
			break;
		case PILOT_TRANSMITTING:
			toReturn += "PILOT_TRANSMITTING";
			break;
		case PITOT_HEAT:
			toReturn += "PITOT_HEAT";
			break;
		case PITOT_HEAT_SWITCH:
			toReturn += "PITOT_HEAT_SWITCH";
			break;
		case PITOT_ICE_PCT:
			toReturn += "PITOT_ICE_PCT";
			break;
		case PLANE_ALTITUDE:
			toReturn += "PLANE_ALTITUDE";
			break;
		case PLANE_ALT_ABOVE_GROUND:
			toReturn += "PLANE_ALT_ABOVE_GROUND";
			break;
		case PLANE_ALT_ABOVE_GROUND_MINUS_CG:
			toReturn += "PLANE_ALT_ABOVE_GROUND_MINUS_CG";
			break;
		case PLANE_BANK_DEGREES:
			toReturn += "PLANE_BANK_DEGREES";
			break;
		case PLANE_HEADING_DEGREES_GYRO:
			toReturn += "PLANE_HEADING_DEGREES_GYRO";
			break;
		case PLANE_HEADING_DEGREES_MAGNETIC:
			toReturn += "PLANE_HEADING_DEGREES_MAGNETIC";
			break;
		case PLANE_HEADING_DEGREES_TRUE:
			toReturn += "PLANE_HEADING_DEGREES_TRUE";
			break;
		case PLANE_IN_PARKING_STATE:
			toReturn += "PLANE_IN_PARKING_STATE";
			break;
		case PLANE_LATITUDE:
			toReturn += "PLANE_LATITUDE";
			break;
		case PLANE_LONGITUDE:
			toReturn += "PLANE_LONGITUDE";
			break;
		case PLANE_PITCH_DEGREES:
			toReturn += "PLANE_PITCH_DEGREES";
			break;
		case PLANE_TOUCHDOWN_BANK_DEGREES:
			toReturn += "PLANE_TOUCHDOWN_BANK_DEGREES";
			break;
		case PLANE_TOUCHDOWN_HEADING_DEGREES_MAGNETIC:
			toReturn += "PLANE_TOUCHDOWN_HEADING_DEGREES_MAGNETIC";
			break;
		case PLANE_TOUCHDOWN_HEADING_DEGREES_TRUE:
			toReturn += "PLANE_TOUCHDOWN_HEADING_DEGREES_TRUE";
			break;
		case PLANE_TOUCHDOWN_LATITUDE:
			toReturn += "PLANE_TOUCHDOWN_LATITUDE";
			break;
		case PLANE_TOUCHDOWN_LONGITUDE:
			toReturn += "PLANE_TOUCHDOWN_LONGITUDE";
			break;
		case PLANE_TOUCHDOWN_NORMAL_VELOCITY:
			toReturn += "PLANE_TOUCHDOWN_NORMAL_VELOCITY";
			break;
		case PLANE_TOUCHDOWN_PITCH_DEGREES:
			toReturn += "PLANE_TOUCHDOWN_PITCH_DEGREES";
			break;
		case PRESSURE_ALTITUDE:
			toReturn += "PRESSURE_ALTITUDE";
			break;
		case PRESSURIZATION_CABIN_ALTITUDE:
			toReturn += "PRESSURIZATION_CABIN_ALTITUDE";
			break;
		case PRESSURIZATION_CABIN_ALTITUDE_GOAL:
			toReturn += "PRESSURIZATION_CABIN_ALTITUDE_GOAL";
			break;
		case PRESSURIZATION_CABIN_ALTITUDE_RATE:
			toReturn += "PRESSURIZATION_CABIN_ALTITUDE_RATE";
			break;
		case PRESSURIZATION_DUMP_SWITCH:
			toReturn += "PRESSURIZATION_DUMP_SWITCH";
			break;
		case PRESSURIZATION_PRESSURE_DIFFERENTIAL:
			toReturn += "PRESSURIZATION_PRESSURE_DIFFERENTIAL";
			break;
		case PROP_AUTO_CRUISE_ACTIVE:
			toReturn += "PROP_AUTO_CRUISE_ACTIVE";
			break;
		case PROP_AUTO_FEATHER_ARMED:
			toReturn += "PROP_AUTO_FEATHER_ARMED";
			break;
		case PROP_BETA:
			toReturn += "PROP_BETA";
			break;
		case PROP_BETA_MAX:
			toReturn += "PROP_BETA_MAX";
			break;
		case PROP_BETA_MIN:
			toReturn += "PROP_BETA_MIN";
			break;
		case PROP_BETA_MIN_REVERSE:
			toReturn += "PROP_BETA_MIN_REVERSE";
			break;
		case PROP_DEICE_SWITCH:
			toReturn += "PROP_DEICE_SWITCH";
			break;
		case PROP_FEATHERED:
			toReturn += "PROP_FEATHERED";
			break;
		case PROP_FEATHERING_INHIBIT:
			toReturn += "PROP_FEATHERING_INHIBIT";
			break;
		case PROP_FEATHER_SWITCH:
			toReturn += "PROP_FEATHER_SWITCH";
			break;
		case PROP_MAX_RPM_PERCENT:
			toReturn += "PROP_MAX_RPM_PERCENT";
			break;
		case PROP_ROTATION_ANGLE:
			toReturn += "PROP_ROTATION_ANGLE";
			break;
		case PROP_RPM:
			toReturn += "PROP_RPM";
			break;
		case PROP_SYNC_ACTIVE:
			toReturn += "PROP_SYNC_ACTIVE";
			break;
		case PROP_SYNC_DELTA_LEVER:
			toReturn += "PROP_SYNC_DELTA_LEVER";
			break;
		case PROP_THRUST:
			toReturn += "PROP_THRUST";
			break;
		case PROPELLER_ADVANCED_SELECTION:
			toReturn += "PROPELLER_ADVANCED_SELECTION";
			break;
		case PUSHBACK_ANGLE:
			toReturn += "PUSHBACK_ANGLE";
			break;
		case PUSHBACK_ATTACHED:
			toReturn += "PUSHBACK_ATTACHED";
			break;
		case PUSHBACK_AVAILABLE:
			toReturn += "PUSHBACK_AVAILABLE";
			break;
		case PUSHBACK_CONTACTX:
			toReturn += "PUSHBACK_CONTACTX";
			break;
		case PUSHBACK_CONTACTY:
			toReturn += "PUSHBACK_CONTACTY";
			break;
		case PUSHBACK_CONTACTZ:
			toReturn += "PUSHBACK_CONTACTZ";
			break;
		case PUSHBACK_STATE:
			toReturn += "PUSHBACK_STATE";
			break;
		case PUSHBACK_WAIT:
			toReturn += "PUSHBACK_WAIT";
			break;
		case RADIOS_AVAILABLE:
			toReturn += "RADIOS_AVAILABLE";
			break;
		case RADIO_HEIGHT:
			toReturn += "RADIO_HEIGHT";
			break;
		case RAD_INS_SWITCH:
			toReturn += "RAD_INS_SWITCH";
			break;
		case REALISM:
			toReturn += "REALISM";
			break;
		case REALISM_CRASH_DETECTION:
			toReturn += "REALISM_CRASH_DETECTION";
			break;
		case REALISM_CRASH_WITH_OTHERS:
			toReturn += "REALISM_CRASH_WITH_OTHERS";
			break;
		case RECIP_CARBURETOR_TEMPERATURE:
			toReturn += "RECIP_CARBURETOR_TEMPERATURE";
			break;
		case RECIP_ENG_ALTERNATE_AIR_POSITION:
			toReturn += "RECIP_ENG_ALTERNATE_AIR_POSITION";
			break;
		case RECIP_ENG_ANTIDETONATION_FLOW_RATE:
			toReturn += "RECIP_ENG_ANTIDETONATION_FLOW_RATE";
			break;
		case RECIP_ENG_ANTIDETONATION_TANK_MAX_QUANTITY:
			toReturn += "RECIP_ENG_ANTIDETONATION_TANK_MAX_QUANTITY";
			break;
		case RECIP_ENG_ANTIDETONATION_TANK_QUANTITY:
			toReturn += "RECIP_ENG_ANTIDETONATION_TANK_QUANTITY";
			break;
		case RECIP_ENG_ANTIDETONATION_TANK_VALVE:
			toReturn += "RECIP_ENG_ANTIDETONATION_TANK_VALVE";
			break;
		case RECIP_ENG_BRAKE_POWER:
			toReturn += "RECIP_ENG_BRAKE_POWER";
			break;
		case RECIP_ENG_COOLANT_RESERVOIR_PERCENT:
			toReturn += "RECIP_ENG_COOLANT_RESERVOIR_PERCENT";
			break;
		case RECIP_ENG_COWL_FLAP_POSITION:
			toReturn += "RECIP_ENG_COWL_FLAP_POSITION";
			break;
		case RECIP_ENG_CYLINDER_HEAD_TEMPERATURE:
			toReturn += "RECIP_ENG_CYLINDER_HEAD_TEMPERATURE";
			break;
		case RECIP_ENG_CYLINDER_HEALTH:
			toReturn += "RECIP_ENG_CYLINDER_HEALTH";
			break;
		case RECIP_ENG_DETONATING:
			toReturn += "RECIP_ENG_DETONATING";
			break;
		case RECIP_ENG_EMERGENCY_BOOST_ACTIVE:
			toReturn += "RECIP_ENG_EMERGENCY_BOOST_ACTIVE";
			break;
		case RECIP_ENG_EMERGENCY_BOOST_ELAPSED_TIME:
			toReturn += "RECIP_ENG_EMERGENCY_BOOST_ELAPSED_TIME";
			break;
		case RECIP_ENG_ENGINE_MASTER_SWITCH:
			toReturn += "RECIP_ENG_ENGINE_MASTER_SWITCH";
			break;
		case RECIP_ENG_FUEL_AVAILABLE:
			toReturn += "RECIP_ENG_FUEL_AVAILABLE";
			break;
		case RECIP_ENG_FUEL_FLOW:
			toReturn += "RECIP_ENG_FUEL_FLOW";
			break;
		case RECIP_ENG_FUEL_NUMBER_TANKS_USED:
			toReturn += "RECIP_ENG_FUEL_NUMBER_TANKS_USED";
			break;
		case RECIP_ENG_FUEL_TANKS_USED:
			toReturn += "RECIP_ENG_FUEL_TANKS_USED";
			break;
		case RECIP_ENG_FUEL_TANK_SELECTOR:
			toReturn += "RECIP_ENG_FUEL_TANK_SELECTOR";
			break;
		case RECIP_ENG_GLOW_PLUG_ACTIVE:
			toReturn += "RECIP_ENG_GLOW_PLUG_ACTIVE";
			break;
		case RECIP_ENG_LEFT_MAGNETO:
			toReturn += "RECIP_ENG_LEFT_MAGNETO";
			break;
		case RECIP_ENG_MANIFOLD_PRESSURE:
			toReturn += "RECIP_ENG_MANIFOLD_PRESSURE";
			break;
		case RECIP_ENG_NITROUS_TANK_MAX_QUANTITY:
			toReturn += "RECIP_ENG_NITROUS_TANK_MAX_QUANTITY";
			break;
		case RECIP_ENG_NITROUS_TANK_QUANTITY:
			toReturn += "RECIP_ENG_NITROUS_TANK_QUANTITY";
			break;
		case RECIP_ENG_NITROUS_TANK_VALVE:
			toReturn += "RECIP_ENG_NITROUS_TANK_VALVE";
			break;
		case RECIP_ENG_NUM_CYLINDERS:
			toReturn += "RECIP_ENG_NUM_CYLINDERS";
			break;
		case RECIP_ENG_NUM_CYLINDERS_FAILED:
			toReturn += "RECIP_ENG_NUM_CYLINDERS_FAILED";
			break;
		case RECIP_ENG_PRIMER:
			toReturn += "RECIP_ENG_PRIMER";
			break;
		case RECIP_ENG_RADIATOR_TEMPERATURE:
			toReturn += "RECIP_ENG_RADIATOR_TEMPERATURE";
			break;
		case RECIP_ENG_RIGHT_MAGNETO:
			toReturn += "RECIP_ENG_RIGHT_MAGNETO";
			break;
		case RECIP_ENG_STARTER_TORQUE:
			toReturn += "RECIP_ENG_STARTER_TORQUE";
			break;
		case RECIP_ENG_TURBINE_INLET_TEMPERATURE:
			toReturn += "RECIP_ENG_TURBINE_INLET_TEMPERATURE";
			break;
		case RECIP_ENG_TURBOCHARGER_FAILED:
			toReturn += "RECIP_ENG_TURBOCHARGER_FAILED";
			break;
		case RECIP_ENG_WASTEGATE_POSITION:
			toReturn += "RECIP_ENG_WASTEGATE_POSITION";
			break;
		case RECIP_MIXTURE_RATIO:
			toReturn += "RECIP_MIXTURE_RATIO";
			break;
		case REJECTED_TAKEOFF_BRAKES_ACTIVE:
			toReturn += "REJECTED_TAKEOFF_BRAKES_ACTIVE";
			break;
		case RELATIVE_WIND_VELOCITY_BODY_X:
			toReturn += "RELATIVE_WIND_VELOCITY_BODY_X";
			break;
		case RELATIVE_WIND_VELOCITY_BODY_Y:
			toReturn += "RELATIVE_WIND_VELOCITY_BODY_Y";
			break;
		case RELATIVE_WIND_VELOCITY_BODY_Z:
			toReturn += "RELATIVE_WIND_VELOCITY_BODY_Z";
			break;
		case RETRACT_FLOAT_SWITCH:
			toReturn += "RETRACT_FLOAT_SWITCH";
			break;
		case RETRACT_LEFT_FLOAT_EXTENDED:
			toReturn += "RETRACT_LEFT_FLOAT_EXTENDED";
			break;
		case RETRACT_RIGHT_FLOAT_EXTENDED:
			toReturn += "RETRACT_RIGHT_FLOAT_EXTENDED";
			break;
		case RIGHT_WHEEL_ROTATION_ANGLE:
			toReturn += "RIGHT_WHEEL_ROTATION_ANGLE";
			break;
		case RIGHT_WHEEL_RPM:
			toReturn += "RIGHT_WHEEL_RPM";
			break;
		case ROCKET_AMMO:
			toReturn += "ROCKET_AMMO";
			break;
		case ROTATION_ACCELERATION_BODY_X:
			toReturn += "ROTATION_ACCELERATION_BODY_X";
			break;
		case ROTATION_ACCELERATION_BODY_Y:
			toReturn += "ROTATION_ACCELERATION_BODY_Y";
			break;
		case ROTATION_ACCELERATION_BODY_Z:
			toReturn += "ROTATION_ACCELERATION_BODY_Z";
			break;
		case ROTATION_VELOCITY_BODY_X:
			toReturn += "ROTATION_VELOCITY_BODY_X";
			break;
		case ROTATION_VELOCITY_BODY_Y:
			toReturn += "ROTATION_VELOCITY_BODY_Y";
			break;
		case ROTATION_VELOCITY_BODY_Z:
			toReturn += "ROTATION_VELOCITY_BODY_Z";
			break;
		case ROTOR_BRAKE_ACTIVE:
			toReturn += "ROTOR_BRAKE_ACTIVE";
			break;
		case ROTOR_BRAKE_HANDLE_POS:
			toReturn += "ROTOR_BRAKE_HANDLE_POS";
			break;
		case ROTOR_CHIP_DETECTED:
			toReturn += "ROTOR_CHIP_DETECTED";
			break;
		case ROTOR_CLUTCH_ACTIVE:
			toReturn += "ROTOR_CLUTCH_ACTIVE";
			break;
		case ROTOR_CLUTCH_SWITCH_POS:
			toReturn += "ROTOR_CLUTCH_SWITCH_POS";
			break;
		case ROTOR_GOV_ACTIVE:
			toReturn += "ROTOR_GOV_ACTIVE";
			break;
		case ROTOR_GOV_SWITCH_POS:
			toReturn += "ROTOR_GOV_SWITCH_POS";
			break;
		case ROTOR_LATERAL_TRIM_PCT:
			toReturn += "ROTOR_LATERAL_TRIM_PCT";
			break;
		case ROTOR_ROTATION_ANGLE:
			toReturn += "ROTOR_ROTATION_ANGLE";
			break;
		case ROTOR_RPM_PCT:
			toReturn += "ROTOR_RPM_PCT";
			break;
		case ROTOR_TEMPERATURE:
			toReturn += "ROTOR_TEMPERATURE";
			break;
		case RUDDER_DEFLECTION:
			toReturn += "RUDDER_DEFLECTION";
			break;
		case RUDDER_DEFLECTION_PCT:
			toReturn += "RUDDER_DEFLECTION_PCT";
			break;
		case RUDDER_PEDAL_INDICATOR:
			toReturn += "RUDDER_PEDAL_INDICATOR";
			break;
		case RUDDER_PEDAL_POSITION:
			toReturn += "RUDDER_PEDAL_POSITION";
			break;
		case RUDDER_POSITION:
			toReturn += "RUDDER_POSITION";
			break;
		case RUDDER_TRIM:
			toReturn += "RUDDER_TRIM";
			break;
		case RUDDER_TRIM_DISABLED:
			toReturn += "RUDDER_TRIM_DISABLED";
			break;
		case RUDDER_TRIM_PCT:
			toReturn += "RUDDER_TRIM_PCT";
			break;
		case SEA_LEVEL_PRESSURE:
			toReturn += "SEA_LEVEL_PRESSURE";
			break;
		case SELECTED_DME:
			toReturn += "SELECTED_DME";
			break;
		case SEMIBODY_LOADFACTOR_X:
			toReturn += "SEMIBODY_LOADFACTOR_X";
			break;
		case SEMIBODY_LOADFACTOR_Y:
			toReturn += "SEMIBODY_LOADFACTOR_Y";
			break;
		case SEMIBODY_LOADFACTOR_YDOT:
			toReturn += "SEMIBODY_LOADFACTOR_YDOT";
			break;
		case SEMIBODY_LOADFACTOR_Z:
			toReturn += "SEMIBODY_LOADFACTOR_Z";
			break;
		case SHUTOFF_VALVE_PULLED:
			toReturn += "SHUTOFF_VALVE_PULLED";
			break;
		case SIGMA_SQRT:
			toReturn += "SIGMA_SQRT";
			break;
		case SIMULATED_RADIUS:
			toReturn += "SIMULATED_RADIUS";
			break;
		case SIM_DISABLED:
			toReturn += "SIM_DISABLED";
			break;
		case SIM_ON_GROUND:
			toReturn += "SIM_ON_GROUND";
			break;
		case SIM_SHOULD_SET_ON_GROUND:
			toReturn += "SIM_SHOULD_SET_ON_GROUND";
			break;
		case SLING_ACTIVE_PAYLOAD_STATION:
			toReturn += "SLING_ACTIVE_PAYLOAD_STATION";
			break;
		case SLING_CABLE_BROKEN:
			toReturn += "SLING_CABLE_BROKEN";
			break;
		case SLING_CABLE_EXTENDED_LENGTH:
			toReturn += "SLING_CABLE_EXTENDED_LENGTH";
			break;
		case SLING_HOIST_PERCENT_DEPLOYED:
			toReturn += "SLING_HOIST_PERCENT_DEPLOYED";
			break;
		case SLING_HOIST_SWITCH:
			toReturn += "SLING_HOIST_SWITCH";
			break;
		case SLING_HOOK_IN_PICKUP_MODE:
			toReturn += "SLING_HOOK_IN_PICKUP_MODE";
			break;
		case SLING_OBJECT_ATTACHED:
			toReturn += "SLING_OBJECT_ATTACHED";
			break;
		case SLOPE_TO_ATC_RUNWAY:
			toReturn += "SLOPE_TO_ATC_RUNWAY";
			break;
		case SMART_CAMERA_ACTIVE:
			toReturn += "SMART_CAMERA_ACTIVE";
			break;
		case SMART_CAMERA_INFO:
			toReturn += "SMART_CAMERA_INFO";
			break;
		case SMART_CAMERA_LIST:
			toReturn += "SMART_CAMERA_LIST";
			break;
		case SMART_CAMERA_LIST_DESCRIPTION:
			toReturn += "SMART_CAMERA_LIST_DESCRIPTION";
			break;
		case SMOKESYSTEM_AVAILABLE:
			toReturn += "SMOKESYSTEM_AVAILABLE";
			break;
		case SMOKE_ENABLE:
			toReturn += "SMOKE_ENABLE";
			break;
		case SPEAKER_ACTIVE:
			toReturn += "SPEAKER_ACTIVE";
			break;
		case SPOILERS_ARMED:
			toReturn += "SPOILERS_ARMED";
			break;
		case SPOILER_AVAILABLE:
			toReturn += "SPOILER_AVAILABLE";
			break;
		case SPOILERS_HANDLE_POSITION:
			toReturn += "SPOILERS_HANDLE_POSITION";
			break;
		case SPOILERS_LEFT_POSITION:
			toReturn += "SPOILERS_LEFT_POSITION";
			break;
		case SPOILERS_RIGHT_POSITION:
			toReturn += "SPOILERS_RIGHT_POSITION";
			break;
		case STALL_ALPHA:
			toReturn += "STALL_ALPHA";
			break;
		case STALL_HORN_AVAILABLE:
			toReturn += "STALL_HORN_AVAILABLE";
			break;
		case STALL_PROTECTION_OFF_LIMIT:
			toReturn += "STALL_PROTECTION_OFF_LIMIT";
			break;
		case STALL_PROTECTION_ON_GOAL:
			toReturn += "STALL_PROTECTION_ON_GOAL";
			break;
		case STALL_PROTECTION_ON_LIMIT:
			toReturn += "STALL_PROTECTION_ON_LIMIT";
			break;
		case STALL_WARNING:
			toReturn += "STALL_WARNING";
			break;
		case STANDARD_ATM_TEMPERATURE:
			toReturn += "STANDARD_ATM_TEMPERATURE";
			break;
		case STATIC_CG_TO_GROUND:
			toReturn += "STATIC_CG_TO_GROUND";
			break;
		case STATIC_PITCH:
			toReturn += "STATIC_PITCH";
			break;
		case STEER_INPUT_CONTROL:
			toReturn += "STEER_INPUT_CONTROL";
			break;
		case STROBES_AVAILABLE:
			toReturn += "STROBES_AVAILABLE";
			break;
		case STROBE_FLASH:
			toReturn += "STROBE_FLASH";
			break;
		case STRUCTURAL_DEICE_SWITCH:
			toReturn += "STRUCTURAL_DEICE_SWITCH";
			break;
		case STRUCTURAL_ICE_PCT:
			toReturn += "STRUCTURAL_ICE_PCT";
			break;
		case STRUC_AIRSPEED_HOLD_PID_CONSTS:
			toReturn += "STRUC_AIRSPEED_HOLD_PID_CONSTS";
			break;
		case STRUC_HEADING_HOLD_PID_CONSTS:
			toReturn += "STRUC_HEADING_HOLD_PID_CONSTS";
			break;
		case STRUCT_AMBIENT_WIND:
			toReturn += "STRUCT_AMBIENT_WIND";
			break;
		case STRUCT_BODY_ROTATION_ACCELERATION:
			toReturn += "STRUCT_BODY_ROTATION_ACCELERATION";
			break;
		case STRUCT_BODY_ROTATION_VELOCITY:
			toReturn += "STRUCT_BODY_ROTATION_VELOCITY";
			break;
		case STRUCT_BODY_VELOCITY:
			toReturn += "STRUCT_BODY_VELOCITY";
			break;
		case STRUCT_DAMAGEVISIBLE:
			toReturn += "STRUCT_DAMAGEVISIBLE";
			break;
		case STRUCT_ENGINE_POSITION:
			toReturn += "STRUCT_ENGINE_POSITION";
			break;
		case STRUCT_EYEPOINT_DYNAMIC_ANGLE:
			toReturn += "STRUCT_EYEPOINT_DYNAMIC_ANGLE";
			break;
		case STRUCT_EYEPOINT_DYNAMIC_OFFSET:
			toReturn += "STRUCT_EYEPOINT_DYNAMIC_OFFSET";
			break;
		case STRUCT_LATLONALT:
			toReturn += "STRUCT_LATLONALT";
			break;
		case STRUCT_LATLONALTPBH:
			toReturn += "STRUCT_LATLONALTPBH";
			break;
		case STRUCT_PBH32:
			toReturn += "STRUCT_PBH32";
			break;
		case STRUCT_REALISM_VARS:
			toReturn += "STRUCT_REALISM_VARS";
			break;
		case STRUCT_SURFACE_RELATIVE_VELOCITY:
			toReturn += "STRUCT_SURFACE_RELATIVE_VELOCITY";
			break;
		case STRUCT_WORLDVELOCITY:
			toReturn += "STRUCT_WORLDVELOCITY";
			break;
		case STRUCT_WORLD_ACCELERATION:
			toReturn += "STRUCT_WORLD_ACCELERATION";
			break;
		case STRUCT_WORLD_ROTATION_VELOCITY:
			toReturn += "STRUCT_WORLD_ROTATION_VELOCITY";
			break;
		case SUCTION_PRESSURE:
			toReturn += "SUCTION_PRESSURE";
			break;
		case SURFACE_CONDITION:
			toReturn += "SURFACE_CONDITION";
			break;
		case SURFACE_INFO_VALID:
			toReturn += "SURFACE_INFO_VALID";
			break;
		case SURFACE_RELATIVE_GROUND_SPEED:
			toReturn += "SURFACE_RELATIVE_GROUND_SPEED";
			break;
		case SURFACE_TYPE:
			toReturn += "SURFACE_TYPE";
			break;
		case SYSTEMS_AVAILABLE:
			toReturn += "SYSTEMS_AVAILABLE";
			break;
		case TACAN_ACTIVE_CHANNEL:
			toReturn += "TACAN_ACTIVE_CHANNEL";
			break;
		case TACAN_ACTIVE_MODE:
			toReturn += "TACAN_ACTIVE_MODE";
			break;
		case TACAN_AVAILABLE:
			toReturn += "TACAN_AVAILABLE";
			break;
		case TACAN_DRIVES_NAV:
			toReturn += "TACAN DRIVES NAV";
			break;
		case TACAN_OBS:
			toReturn += "TACAN OBS";
			break;
		case TACAN_STANDBY_CHANNEL:
			toReturn += "TACAN_STANDBY_CHANNEL";
			break;
		case TACAN_STANDBY_MODE:
			toReturn += "TACAN_STANDBY_MODE";
			break;
		case TACAN_STATION_CDI:
			toReturn += "TACAN STATION CDI";
			break;
		case TACAN_STATION_DISTANCE:
			toReturn += "TACAN_STATION_DISTANCE";
			break;
		case TACAN_STATION_IDENT:
			toReturn += "TACAN STATION IDENT";
			break;
		case TACAN_STATION_LATLONALT:
			toReturn += "TACAN_STATION_LATLONALT";
			break;
		case TACAN_STATION_RADIAL:
			toReturn += "TACAN STATION RADIAL";
			break;
		case TACAN_STATION_RADIAL_ERROR:
			toReturn += "TACAN STATION RADIAL ERROR";
			break;
		case TACAN_STATION_TOFROM:
			toReturn += "TACAN STATION TOFROM";
			break;
		case TACAN_VOLUME:
			toReturn += "TACAN_VOLUME";
			break;
		case TAILHOOK_HANDLE:
			toReturn += "TAILHOOK_HANDLE";
			break;
		case TAILHOOK_POSITION:
			toReturn += "TAILHOOK_POSITION";
			break;
		case TAILWHEEL_LOCK_ON:
			toReturn += "TAILWHEEL_LOCK_ON";
			break;
		case THROTTLE_LOWER_LIMIT:
			toReturn += "THROTTLE_LOWER_LIMIT";
			break;
		case TITLE:
			toReturn += "TITLE";
			break;
		case TOE_BRAKES_AVAILABLE:
			toReturn += "TOE_BRAKES_AVAILABLE";
			break;
		case TOTAL_AIR_TEMPERATURE:
			toReturn += "TOTAL_AIR_TEMPERATURE";
			break;
		case TOTAL_VELOCITY:
			toReturn += "TOTAL_VELOCITY";
			break;
		case TOTAL_WEIGHT:
			toReturn += "TOTAL_WEIGHT";
			break;
		case TOTAL_WEIGHT_CROSS_COUPLED_MOI:
			toReturn += "TOTAL_WEIGHT_CROSS_COUPLED_MOI";
			break;
		case TOTAL_WEIGHT_PITCH_MOI:
			toReturn += "TOTAL_WEIGHT_PITCH_MOI";
			break;
		case TOTAL_WEIGHT_ROLL_MOI:
			toReturn += "TOTAL_WEIGHT_ROLL_MOI";
			break;
		case TOTAL_WEIGHT_YAW_MOI:
			toReturn += "TOTAL_WEIGHT_YAW_MOI";
			break;
		case TOTAL_WORLD_VELOCITY:
			toReturn += "TOTAL_WORLD_VELOCITY";
			break;
		case TOW_CONNECTION:
			toReturn += "TOW_CONNECTION";
			break;
		case TOW_RELEASE_HANDLE:
			toReturn += "TOW_RELEASE_HANDLE";
			break;
		case TRACK_IR_ENABLE:
			toReturn += "TRACK_IR_ENABLE";
			break;
		case TRAILING_EDGE_FLAPS_LEFT_ANGLE:
			toReturn += "TRAILING_EDGE_FLAPS_LEFT_ANGLE";
			break;
		case TRAILING_EDGE_FLAPS_LEFT_INDEX:
			toReturn += "TRAILING_EDGE_FLAPS_LEFT_INDEX";
			break;
		case TRAILING_EDGE_FLAPS_LEFT_PERCENT:
			toReturn += "TRAILING_EDGE_FLAPS_LEFT_PERCENT";
			break;
		case TRAILING_EDGE_FLAPS_RIGHT_ANGLE:
			toReturn += "TRAILING_EDGE_FLAPS_RIGHT_ANGLE";
			break;
		case TRAILING_EDGE_FLAPS_RIGHT_INDEX:
			toReturn += "TRAILING_EDGE_FLAPS_RIGHT_INDEX";
			break;
		case TRAILING_EDGE_FLAPS_RIGHT_PERCENT:
			toReturn += "TRAILING_EDGE_FLAPS_RIGHT_PERCENT";
			break;
		case TRANSPONDER_AVAILABLE:
			toReturn += "TRANSPONDER_AVAILABLE";
			break;
		case TRANSPONDER_CODE:
			toReturn += "TRANSPONDER_CODE";
			break;
		case TRANSPONDER_IDENT:
			toReturn += "TRANSPONDER_IDENT";
			break;
		case TRANSPONDER_STATE:
			toReturn += "TRANSPONDER_STATE";
			break;
		case TRUE_AIRSPEED_SELECTED:
			toReturn += "TRUE_AIRSPEED_SELECTED";
			break;
		case TURB_ENG_AFTERBURNER:
			toReturn += "TURB_ENG_AFTERBURNER";
			break;
		case TURB_ENG_AFTERBURNER_PCT_ACTIVE:
			toReturn += "TURB_ENG_AFTERBURNER_PCT_ACTIVE";
			break;
		case TURB_ENG_AFTERBURNER_STAGE_ACTIVE:
			toReturn += "TURB_ENG_AFTERBURNER_STAGE_ACTIVE";
			break;
		case TURB_ENG_BLEED_AIR:
			toReturn += "TURB_ENG_BLEED_AIR";
			break;
		case TURB_ENG_COMMANDED_N1:
			toReturn += "TURB_ENG_COMMANDED_N1";
			break;
		case TURB_ENG_CONDITION_LEVER_POSITION:
			toReturn += "TURB_ENG_CONDITION_LEVER_POSITION";
			break;
		case TURB_ENG_CORRECTED_FF:
			toReturn += "TURB_ENG_CORRECTED_FF";
			break;
		case TURB_ENG_CORRECTED_N1:
			toReturn += "TURB_ENG_CORRECTED_N1";
			break;
		case TURB_ENG_CORRECTED_N2:
			toReturn += "TURB_ENG_CORRECTED_N2";
			break;
		case TURB_ENG_FREE_TURBINE_TORQUE:
			toReturn += "TURB_ENG_FREE_TURBINE_TORQUE";
			break;
		case TURB_ENG_FUEL_AVAILABLE:
			toReturn += "TURB_ENG_FUEL_AVAILABLE";
			break;
		case TURB_ENG_FUEL_FLOW_PPH:
			toReturn += "TURB_ENG_FUEL_FLOW_PPH";
			break;
		case TURB_ENG_HIGH_IDLE:
			toReturn += "TURB_ENG_HIGH_IDLE";
			break;
		case TURB_ENG_IGNITION_SWITCH:
			toReturn += "TURB_ENG_IGNITION_SWITCH";
			break;
		case TURB_ENG_IGNITION_SWITCH_EX1:
			toReturn += "TURB_ENG_IGNITION_SWITCH_EX1";
			break;
		case TURB_ENG_IS_IGNITING:
			toReturn += "TURB_ENG_IS_IGNITING";
			break;
		case TURB_ENG_ITT:
			toReturn += "TURB_ENG_ITT";
			break;
		case TURB_ENG_JET_THRUST:
			toReturn += "TURB_ENG_JET_THRUST";
			break;
		case TURB_ENG_LOW_IDLE:
			toReturn += "TURB_ENG_LOW_IDLE";
			break;
		case TURB_ENG_MASTER_STARTER_SWITCH:
			toReturn += "TURB_ENG_MASTER_STARTER_SWITCH";
			break;
		case TURB_ENG_MAX_TORQUE_PERCENT:
			toReturn += "TURB_ENG_MAX_TORQUE_PERCENT";
			break;
		case TURB_ENG_N1:
			toReturn += "TURB_ENG_N1";
			break;
		case TURB_ENG_N2:
			toReturn += "TURB_ENG_N2";
			break;
		case TURB_ENG_NUM_TANKS_USED:
			toReturn += "TURB_ENG_NUM_TANKS_USED";
			break;
		case TURB_ENG_PRESSURE_RATIO:
			toReturn += "TURB_ENG_PRESSURE_RATIO";
			break;
		case TURB_ENG_PRIMARY_NOZZLE_PERCENT:
			toReturn += "TURB_ENG_PRIMARY_NOZZLE_PERCENT";
			break;
		case TURB_ENG_REVERSE_NOZZLE_PERCENT:
			toReturn += "TURB_ENG_REVERSE_NOZZLE_PERCENT";
			break;
		case TURB_ENG_TANKS_USED:
			toReturn += "TURB_ENG_TANKS_USED";
			break;
		case TURB_ENG_TANK_SELECTOR:
			toReturn += "TURB_ENG_TANK_SELECTOR";
			break;
		case TURB_ENG_THROTTLE_COMMANDED_N1:
			toReturn += "TURB_ENG_THROTTLE_COMMANDED_N1";
			break;
		case TURB_ENG_VIBRATION:
			toReturn += "TURB_ENG_VIBRATION";
			break;
		case TURN_COORDINATOR_BALL:
			toReturn += "TURN_COORDINATOR_BALL";
			break;
		case TURN_COORDINATOR_BALL_INV:
			toReturn += "TURN_COORDINATOR_BALL_INV";
			break;
		case TURN_INDICATOR_RATE:
			toReturn += "TURN_INDICATOR_RATE";
			break;
		case TURN_INDICATOR_SWITCH:
			toReturn += "TURN_INDICATOR_SWITCH";
			break;
		case TYPICAL_DESCENT_RATE:
			toReturn += "TYPICAL_DESCENT_RATE";
			break;
		case UNLIMITED_FUEL:
			toReturn += "UNLIMITED_FUEL";
			break;
		case UNUSABLE_FUEL_TOTAL_QUANTITY:
			toReturn += "UNUSABLE_FUEL_TOTAL_QUANTITY";
			break;
		case USER_INPUT_ENABLED:
			toReturn += "USER_INPUT_ENABLED";
			break;
		case VARIOMETER_RATE:
			toReturn += "VARIOMETER_RATE";
			break;
		case VARIOMETER_SWITCH:
			toReturn += "VARIOMETER_SWITCH";
			break;
		case VELOCITY_BODY_X:
			toReturn += "VELOCITY_BODY_X";
			break;
		case VELOCITY_BODY_Y:
			toReturn += "VELOCITY_BODY_Y";
			break;
		case VELOCITY_BODY_Z:
			toReturn += "VELOCITY_BODY_Z";
			break;
		case VELOCITY_WORLD_X:
			toReturn += "VELOCITY_WORLD_X";
			break;
		case VELOCITY_WORLD_Y:
			toReturn += "VELOCITY_WORLD_Y";
			break;
		case VELOCITY_WORLD_Z:
			toReturn += "VELOCITY_WORLD_Z";
			break;
		case VERTICAL_SPEED:
			toReturn += "VERTICAL_SPEED";
			break;
		case WAGON_BACK_LINK_LENGTH:
			toReturn += "WAGON_BACK_LINK_LENGTH";
			break;
		case WAGON_BACK_LINK_ORIENTATION:
			toReturn += "WAGON_BACK_LINK_ORIENTATION";
			break;
		case WAGON_BACK_LINK_START_POSZ:
			toReturn += "WAGON_BACK_LINK_START_POSZ";
			break;
		case WAGON_FRONT_LINK_LENGTH:
			toReturn += "WAGON_FRONT_LINK_LENGTH";
			break;
		case WAGON_FRONT_LINK_ORIENTATION:
			toReturn += "WAGON_FRONT_LINK_ORIENTATION";
			break;
		case WAGON_FRONT_LINK_START_POSZ:
			toReturn += "WAGON_FRONT_LINK_START_POSZ";
			break;
		case WARNING_FUEL:
			toReturn += "WARNING_FUEL";
			break;
		case WARNING_FUEL_LEFT:
			toReturn += "WARNING_FUEL_LEFT";
			break;
		case WARNING_FUEL_RIGHT:
			toReturn += "WARNING_FUEL_RIGHT";
			break;
		case WARNING_LOW_HEIGHT:
			toReturn += "WARNING_LOW_HEIGHT";
			break;
		case WARNING_OIL_PRESSURE:
			toReturn += "WARNING_OIL_PRESSURE";
			break;
		case WARNING_VACUUM:
			toReturn += "WARNING_VACUUM";
			break;
		case WARNING_VACUUM_LEFT:
			toReturn += "WARNING_VACUUM_LEFT";
			break;
		case WARNING_VACUUM_RIGHT:
			toReturn += "WARNING_VACUUM_RIGHT";
			break;
		case WARNING_VOLTAGE:
			toReturn += "WARNING_VOLTAGE";
			break;
		case WATER_BALLAST_VALVE:
			toReturn += "WATER_BALLAST_VALVE";
			break;
		case WATER_LEFT_RUDDER_EXTENDED:
			toReturn += "WATER_LEFT_RUDDER_EXTENDED";
			break;
		case WATER_LEFT_RUDDER_STEER_ANGLE:
			toReturn += "WATER_LEFT_RUDDER_STEER_ANGLE";
			break;
		case WATER_LEFT_RUDDER_STEER_ANGLE_PCT:
			toReturn += "WATER_LEFT_RUDDER_STEER_ANGLE_PCT";
			break;
		case WATER_RIGHT_RUDDER_EXTENDED:
			toReturn += "WATER_RIGHT_RUDDER_EXTENDED";
			break;
		case WATER_RIGHT_RUDDER_STEER_ANGLE:
			toReturn += "WATER_RIGHT_RUDDER_STEER_ANGLE";
			break;
		case WATER_RIGHT_RUDDER_STEER_ANGLE_PCT:
			toReturn += "WATER_RIGHT_RUDDER_STEER_ANGLE_PCT";
			break;
		case WATER_RUDDER_HANDLE_POSITION:
			toReturn += "WATER_RUDDER_HANDLE_POSITION";
			break;
		case WHEEL_ROTATION_ANGLE:
			toReturn += "WHEEL_ROTATION_ANGLE";
			break;
		case WHEEL_RPM:
			toReturn += "WHEEL_RPM";
			break;
		case WINDSHIELD_DEICE_SWITCH:
			toReturn += "WINDSHIELD_DEICE_SWITCH";
			break;
		case WINDSHIELD_RAIN_EFFECT_AVAILABLE:
			toReturn += "WINDSHIELD_RAIN_EFFECT_AVAILABLE";
			break;
		case WINDSHIELD_WIND_VELOCITY:
			toReturn += "WINDSHIELD_WIND_VELOCITY";
			break;
		case WING_AREA:
			toReturn += "WING_AREA";
			break;
		case WING_FLEX_PCT:
			toReturn += "WING_FLEX_PCT";
			break;
		case WING_SPAN:
			toReturn += "WING_SPAN";
			break;
		case WISKEY_COMPASS_INDICATION_DEGREES:
			toReturn += "WISKEY_COMPASS_INDICATION_DEGREES";
			break;
		case YAW_STRING_ANGLE:
			toReturn += "YAW_STRING_ANGLE";
			break;
		case YAW_STRING_PCT_EXTENDED:
			toReturn += "YAW_STRING_PCT_EXTENDED";
			break;
		case YOKE_X_INIDICATOR:
			toReturn += "YOKE_X_INIDICATOR";
			break;
		case YOKE_X_POSITION:
			toReturn += "YOKE_X_POSITION";
			break;
		case YOKE_X_POSITION_WITH_AP:
			toReturn += "YOKE_X_POSITION_WITH_AP";
			break;
		case YOKE_Y_INIDICATOR:
			toReturn += "YOKE_Y_INIDICATOR";
			break;
		case YOKE_Y_POSITION:
			toReturn += "YOKE_Y_POSITION";
			break;
		case YOKE_Y_POSITION_WITH_AP:
			toReturn += "YOKE_Y_POSITION_WITH_AP";
			break;
		case ZERO_LIFT_ALPHA:
			toReturn += "ZERO_LIFT_ALPHA";
			break;
	}
	return toReturn;
}
