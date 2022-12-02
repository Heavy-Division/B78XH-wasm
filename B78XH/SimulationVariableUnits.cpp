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


#include "SimulationVariableUnits.h"

std::string svu_to_string(SimulationVariableUnits unit) {
	std::string toReturn;
	switch(unit) {
		case METER:
			toReturn += "meter";
			break;
		default:
			toReturn += "unknown";
			break;
		case METER_SCALER_256:
			toReturn += "meter scaler 256";
			break;
		case MILLIMETER:
			toReturn += "millimeter";
			break;
		case CENTIMETER:
			toReturn += "centimeter";
			break;
		case KILOMETER:
			toReturn += "kilometer";
			break;
		case NAUTICAL_MILE:
			toReturn += "nautical mile";
			break;
		case DECINMILE:
			toReturn += "decinmile";
			break;
		case INCH:
			toReturn += "inch";
			break;
		case FOOT:
			toReturn += "foot";
			break;
		case YARD:
			toReturn += "yard";
			break;
		case DECIMILE:
			toReturn += "decimile";
			break;
		case MILE:
			toReturn += "mile";
			break;
		case SQUARE_INCH:
			toReturn += "square inch";
			break;
		case SQUARE_FEET:
			toReturn += "square feet";
			break;
		case SQUARE_MILE:
			toReturn += "square mile";
			break;
		case SQUARE_MILLIMETER:
			toReturn += "square millimeter";
			break;
		case SQUARE_CENTIMETER:
			toReturn += "square centimeter";
			break;
		case SQUARE_METER:
			toReturn += "square meter";
			break;
		case SQUARE_KILOMETER:
			toReturn += "square kilometer";
			break;
		case CUBIC_INCH:
			toReturn += "cubic inch";
			break;
		case CUBIC_FOOT:
			toReturn += "cubic foot";
			break;
		case CUBIC_YARD:
			toReturn += "cubic yard";
			break;
		case CUBIC_MILE:
			toReturn += "cubic mile";
			break;
		case CUBIC_MILLIMETER:
			toReturn += "cubic millimeter";
			break;
		case CUBIC_CENTIMETER:
			toReturn += "cubic centimeter";
			break;
		case CUBIC_METER:
			toReturn += "cubic meter";
			break;
		case CUBIC_KILOMETER:
			toReturn += "cubic kilometer";
			break;
		case LITER:
			toReturn += "liter";
			break;
		case GALLON:
			toReturn += "gallon";
		case QUART:
			toReturn += "quart";
			break;
		case FS7_OIL_QUANTITY:
			toReturn += "fs7 oil quantity";
			break;
		case KELVIN:
			toReturn += "kelvin";
			break;
		case RANKINE:
			toReturn += "rankine";
			break;
		case FARENHEIT:
			toReturn += "farenheit";
			break;
		case CELSIUS:
			toReturn += "celsius";
			break;
		case CELSIUS_FS7_EGT:
			toReturn += "celsius fs7 egt";
			break;
		case CELSIUS_FS7_OIL_TEMP:
			toReturn += "celsius fs7 oil temp";
			break;
		case CELSIUS_SCALER_1_256:
			toReturn += "celsius scaler 1/256";
			break;
		case CELSIUS_SCALER_256:
			toReturn += "celsius scaler 256";
			break;
		case CELSIUS_SCALER_16K:
			toReturn += "celsius scaler 16k";
			break;
		case RADIAN:
			toReturn += "radian";
			break;
		case ROUND:
			toReturn += "round";
			break;
		case DEGREE:
			toReturn += "degree";
			break;
		case GRAD:
			toReturn += "grad";
			break;
		case ANGL16:
			toReturn += "angl16";
			break;
		case ANGL32:
			toReturn += "angl32";
			break;
		case DEGREE_LATITUDE:
			toReturn += "degree latitude";
			break;
		case DEGREE_LONGITUDE:
			toReturn += "degree longitude";
			break;
		case METER_LATITUDE:
			toReturn += "meter latitude";
			break;
		case RADIAN_PER_SECOND:
			toReturn += "radian per second";
			break;
		case REVOLUTION_PER_MINUTE:
			toReturn += "revolution per minute";
			break;
		case RPM_1_OVER_16k:
			toReturn += "rpm 1 over 16k";
			break;
		case MINUTE_PER_ROUND:
			toReturn += "minute per round";
			break;
		case NICE_MINUTE_PER_ROUND:
			toReturn += "nice minute per round";
			break;
		case DEGREE_PER_SECOND:
			toReturn += "degree per second";
			break;
		case DEGREE_PER_SECOND_ANG16:
			toReturn += "degree per second ang16";
			break;
		case RADIAN_PER_SECOND_SQUARED:
			toReturn += "radian per second squared";
			break;
		case DEGREE_PER_SECOND_SQUARED:
			toReturn += "degree per second squared";
			break;
		case METER_PER_SECOND:
			toReturn += "meter per second";
			break;
		case METER_PER_SECOND_SCALER_256:
			toReturn += "meter per second scaler 256";
			break;
		case METER_PER_MINUTE:
			toReturn += "meter per minute";
			break;
		case KILOMETER_HOUR:
			toReturn += "kilometer/hour";
			break;
		case FEET_SECOND:
			toReturn += "feet/second";
			break;
		case FEET_MINUTE:
			toReturn += "feet/minute";
			break;
		case MILE_PER_MINUTE:
			toReturn += "mile per hour";
			break;
		case KNOT:
			toReturn += "knot";
			break;
		case KNOT_SCALER_128:
			toReturn += "knot scaler 128";
			break;
		case MACH:
			toReturn += "mach";
			break;
		case MACH_3D2_OVER_64K:
			toReturn += "mach 3d2 over 64k";
			break;
		case METER_PER_SECOND_SQUARED:
			toReturn += "meter per second squared";
			break;
		case FEET_PER_SECOND_SQUARED:
			toReturn += "feet per second squared";
			break;
		case GFORCE:
			toReturn += "Gforce";
			break;
		case GFORCE_624_SCALED:
			toReturn += "G Force 624 scaled";
			break;
		case SECOND:
			toReturn += "second";
			break;
		case MINUTE:
			toReturn += "minute";
			break;
		case HOUR:
			toReturn += "hour";
			break;
		case DAY:
			toReturn += "day";
			break;
		case HOUR_OVER_10:
			toReturn += "hour over 10";
			break;
		case YEAR:
			toReturn += "year";
			break;
		case WATT:
			toReturn += "Watt";
			break;
		case FT_LB_PER_SECOND:
			toReturn += "ft lb per second";
			break;
		case METER_CUBED_PER_SECOND:
			toReturn += "meter cubed per second";
			break;
		case LITER_PER_HOUR:
			toReturn += "liter per hour";
			break;
		case GALLON_PER_HOUR:
			toReturn += "gallon per hour";
			break;
		case KILOGRAM:
			toReturn += "kilogram";
			break;
		case POUND:
			toReturn += "pound";
			break;
		case POUND_SCALER_256:
			toReturn += "pound scaler 256";
			break;
		case SLUG:
			toReturn += "slug";
			break;
		case KILOGRAM_PER_SECOND:
			toReturn += "kilogram per second";
			break;
		case POUND_PER_HOUR:
			toReturn += "pound per hour";
			break;
		case AMPERE:
			toReturn += "ampere";
			break;
		case FS7_CHARGING_AMPS:
			toReturn += "fs7 charging amps";
			break;
		case VOLT:
			toReturn += "volt";
			break;
		case HERTZ:
			toReturn += "Hertz";
			break;
		case KILOHERTZ:
			toReturn += "Kilohertz";
			break;
		case MEGAHERTZ:
			toReturn += "Megahertz";
			break;
		case FREQUENCY_BCD16:
			toReturn += "Frequency BCD16";
			break;
		case FREQUENCY_BCD32:
			toReturn += "Frequency BCD32";
			break;
		case FREQUENCY_ADF_BCD32:
			toReturn += "Frequency ADF BCD32";
			break;
		case KILOGRAM_PER_CUBIC_METER:
			toReturn += "kilogram per cubic meter";
			break;
		case SLUG_PER_CUBIC_FEET:
			toReturn += "Slug per cubic feet";
			break;
		case POUND_PER_GALLON:
			toReturn += "pound per gallon";
			break;
		case PASCAL:
			toReturn += "pascal";
			break;
		case KILOPASCAL:
			toReturn += "kilopascal";
			break;
		case MILLIMETER_OF_MERCURY:
			toReturn += "millimeter of mercury";
			break;
		case CENTIMETER_OF_MERCURY:
			toReturn += "centimeter of mercury";
			break;
		case INCH_OF_MERCURY:
			toReturn += "inch of mercury";
			break;
		case INHG_64_OVER_64K:
			toReturn += "inHg 64 over 64k";
			break;
		case NEWTON_PER_SQUARE_METER:
			toReturn += "Newton per square meter";
			break;
		case KILOGRAM_FORCE_PER_SQUARE_CENTIMETER:
			toReturn += "kilogram force per square centimeter";
			break;
		case KILOGRAM_METER_SQUARED:
			toReturn += "kilogram meter squared";
			break;
		case ATMOSPHERE:
			toReturn += "atmosphere";
			break;
		case BAR:
			toReturn += "bar";
			break;
		case MILLIBAR:
			toReturn += "millibar";
			break;
		case MILLIBAR_SCALER_16:
			toReturn += "millibar scaler 16";
			break;
		case POUND_FORCE_PER_SQUARE_INCH:
			toReturn += "pound-force per square inch";
			break;
		case PSI_SCALER_16K:
			toReturn += "psi scaler 16k";
			break;
		case PSI_4_OVER_16K:
			toReturn += "psi 4 over 16k";
			break;
		case PSI_FS7_OIL_PRESSURE:
			toReturn += "psi fs7 oil pressure";
			break;
		case POUND_FORCE_PER_SQUARE_FOOT:
			toReturn += "pound-force per square foot";
			break;
		case PSF_SCALER_16K:
			toReturn += "psf scaler 16k";
			break;
		case SLUG_FEET_SQUARED:
			toReturn += "slug feet squared";
			break;
		case BOOST_CMHG:
			toReturn += "boost cmHg";
			break;
		case BOOST_INHG:
			toReturn += "boost inHg";
			break;
		case BOOST_PSI:
			toReturn += "boost psi";
			break;
		case NEWTON_METER:
			toReturn += "Newton meter";
			break;
		case FOOT_POUND:
			toReturn += "foot-pound";
			break;
		case LBF_FEET:
			toReturn += "lbf-feet";
			break;
		case KILOGRAM_METER:
			toReturn += "kilogram meter";
			break;
		case POUNDAL_FEET:
			toReturn += "poundal feet";
			break;
		case FRACTIONAL_LAT_LON_DIGITS:
			toReturn += "FractionalLatLonDigits";
			break;
		case PART:
			toReturn += "part";
			break;
		case HALF:
			toReturn += "half";
			break;
		case THIRD:
			toReturn += "third";
			break;
		case PERCENT:
			toReturn += "percent";
			break;
		case PERCENT_OVER_100:
			toReturn += "percent over 100";
			break;
		case PERCENT_SCALER_16K:
			toReturn += "percent scaler 16k";
			break;
		case PERCENT_SCALER_32K:
			toReturn += "percent scaler 32k";
			break;
		case PERCENT_SCALER_2POW23:
			toReturn += "percent scaler 2pow23";
			break;
		case BEL:
			toReturn += "bel";
			break;
		case DECIBEL:
			toReturn += "decibel";
			break;
		case MORE_THEN_A_HALF:
			toReturn += "more_than_a_half";
			break;
		case TIMES:
			toReturn += "times";
			break;
		case RATIO:
			toReturn += "ratio";
			break;
		case NUMBER:
			toReturn += "number";
			break;
		case SCALER:
			toReturn += "scaler";
			break;
		case POSITION:
			toReturn += "position";
			break;
		case ENUM:
			toReturn += "Enum";
			break;
		case BOOL:
			toReturn += "Bool";
			break;
		case BCO16:
			toReturn += "Bco16";
			break;
		case MASK:
			toReturn += "mask";
			break;
		case FLAGS:
			toReturn += "flags";
			break;
		case STRING:
			toReturn += "string";
			break;
		case PER_RADIAN:
			toReturn += "per radian";
			break;
		case PER_DEGREE:
			toReturn += "per degree";
			break;
		case KEYFRAME:
			toReturn += "keyframe";
			break;
		case XYZ:
			toReturn += "XYZ";
			break;
		case PBH:
			toReturn += "PBH";
			break;
		case LAT_LON_ALT_PBH:
			toReturn += "latlonaltpbh";
			break;
		case LAT_LON_ALT:
			toReturn += "latlonalt";
			break;
		case PID_STRUCT:
			toReturn += "PID_STRUCT";
			break;
		case GLASS_COCKPIT_SETTINGS:
			toReturn += "GlassCockpitSettings";
			break;
		case FUEL_LEVELS:
			toReturn += "FuelLevels";
			break;
	}
	return toReturn;

}
