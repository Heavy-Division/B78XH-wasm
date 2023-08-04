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
#include "ERS.h"
#include <cstdint>
#include <stdexcept>
#include <array>
#include <vector>
#include <unordered_map>
#include "Tools/Console.h"

/*
 * Common Core System
 *
 *
 *  Most of the 787 systems rely on the
	// ARINC 664 spec, but the existence of i/o on the Remote Data Concentrator indicates a necessity to interface between these specs and support ARINC 429.
 */


const enum class DATA_RATE {
	ARINC429_Slow = 12500, // 12.5 Kbps
	ARINC429_Fast = 100000, // 100 Kbps
	ARINC664 = 100000000 // 100 Mbps
};

/*
* ARINC 429 is a standard communication protocol between the various systems onboard aircraft.
* ARINC 429 standard data words are 32-bit words made up of five primary fields:
* 1. Parity (1 bit):
* ARINC uses odd parity as an error check to ensure precise data reception.
* The number of transmitted Logic 1s in each word is an odd number, with bit 32 set or cleared to get the odd count.
* ARINC 429 specifies no method of error correction, only error detection.
* 
* 2. Sign/Status Matrix "SSM" (2-bits):
* Depending on the word Label, which indicates the form of data is being transmitted, the SSM field may provide different information.
* This field can be used to view the word information’s sign or location or to report the operating status of the source system and is dependent on the data type.
* https://cdn.discordapp.com/attachments/821089884591751209/1137014663490576404/image.png
* 
* 
* 3. Data (19 bits):
* ARINC 429 identifies bits 11-29 as those which contain the data information for the word. The data pieces, the entire word of ARINC 429, can be formatted flexibly.
* When the data words are transmitted on the ARINC bus, the mark is transmitted first, MSB first, followed by the remainder of the bit field, LSB first
* 
* 4. Source/Destination Identifier "SDI" (2-bits):
* Bits 9-10 are used by the Source/Destination Identifier-SDI-and are optional under the ARINC 429 specification.
* To determine the receiver, the data is intended for the SDI may be used to identify the source that transmits the data or by several receivers.
* Instead of using them as an SDI sector, bits 9-10 can be used for higher resolution data. The SDI is interpreted as an extension to the term Label when used as an identifier
* 
* 
* 5. Label (8 bits):
* The mark is used to define the word’s data type(BNR, BCD, Discrete, etc.) and may contain instructional or data reporting information.
* Labels can be further refined by using the first 3 - bits of the data field, Bits 11 - 13, as an Equipment Identifier to identify the bus transmission source.
* Equipment IDs are expressed in hexadecimal form as values.
* 
* In an ARINC transmission, the label is always sent first and is a necessary sector, as is the parity bit.
* Labels are first transmitted by MSB, followed by the remainder of the ARINC phrase, first transmitted by LSB.
*/



/**
 * @class ARINC429Word
 * @brief Represents a word within the ARINC 429 Protocol, a standard communication protocol used in aircraft systems.
 */
class ARINC429Word {
public:
	/**
	 * @brief Constructor for ARINC429Word.
	 * @param dataRate data transfer speed (e.g., ARINC429_Slow or ARINC429_Fast).
	 */
	ARINC429Word(DATA_RATE dataRate) : parity(1), dataRate(dataRate) {
		if (dataRate == DATA_RATE::ARINC664) {
			// TODO: This should throw an error at compile time not in the sim
			Console::log("Invalid data rate argument in constructor. Did you mean ARINC429_Slow or ARINC429_Fast?");
		}
	}

	uint32_t parity : 1; ///< Odd parity bit for error checking.
	uint32_t ssm : 2;    ///< Sign/Status Matrix, provides sign or status information depending on label.
	uint32_t data : 19;  ///< Data bits, flexible formatting with MSB transmitted first.
	uint32_t sdi : 2;    ///< Source/Destination Identifier, optional and can determine receiver or source.
	uint32_t label : 8;  ///< Label defines data type and may contain instructional information.

private:
	DATA_RATE dataRate;  ///< Data rate for ARINC 429 protocol, either ARINC429_Slow or ARINC429_Fast.
};




/**
 * @class ARINC664Word
 * @brief Represents a word within the ARINC 664 protocol.
 *
 * This class encapsulates the properties of a word in the ARINC 664 protocol,
 * including the virtual link identifier, sequence number, message type, and the actual data.
 */
class ARINC664Word {


public:
	/**
	 * @brief Constructor for ARINC664Word.
	 * @param virtualLinkID Virtual Link Identifier for the word.
	 * @param sequenceNumber Sequence number for the word.
	 * @param messageType Message type or service code for the word.
	 * @param data 32-bit data value for the word.
	 */
	ARINC664Word(int virtualLinkID, int sequenceNumber, int messageType, uint8_t data[4])
		: virtualLinkID(virtualLinkID), sequenceNumber(sequenceNumber), messageType(messageType) {
		for (int i = 0; i < 4; i++) {
			this->data[i] = data[i];
		}
	}

	uint8_t data[4]; ///< 32-bit data, represented in 4 bytes.
	int virtualLinkID; ///< Virtual Link Identifier (VLID) for the word.
	int sequenceNumber; ///< Sequence number for ordering or fragmentation.
	int messageType; ///< Message type or service code for the word.

private:

	static const DATA_RATE dataRate = DATA_RATE::ARINC664; // 100 Mbps



};

class PowerConditioningModule {
public:
	/**
	* @brief Constructor for PCM
	* @param isOn initial powered state of the module
	*/
	PowerConditioningModule(bool isOn) : isOn(isOn){};

	bool isOn;

	/**
	 * @brief Triggers failure of the Power Conditioning Module
	 * @param failure set failure mode to true or false
	*/
	auto setFailureMode(bool failure) -> void {
		this->failure = failure;
	}

	/**
	 * @brief Converts 28v DC power to 12.5v DC for use in Common Computing Resource Cabinet
	 */
	auto convert() -> void {
		// TODO: Implement
		const double inputPotentialVolts = 28.0;
		const double outputPotentialVolts = 12.5;

		this->outputVoltage = outputPotentialVolts;

	}

	double outputVoltage = 0;

private:
	bool failure = false;
};


// The hosted application software in the GPMs are responsible for:
// • Data calculation and processing
// • Fault monitoring and reporting
// • I/O control

enum HOSTED_APPLICATIONS {
	CABIN_AIR_TEMPERATURE_CONTROL_SYSTEM,
	EQUIPMENT_COOLING_SYSTEM,
	INTEGRATED_COOLING_SYSTEM,
	LOW_PRESSURE_SYSTEM,
	POWER_ELECTRONICS_COOLING_SYSTEM,
	COMMUNICATION_MANAGEMENT_FUNCTION,
	SWITCHES_FLT_DECK_CONTROL_PANELS,
	CIRCUIT_BREAKER_INDICATION_AND_CONTROL,
	ELECTRICAL_POWER_DISTRIBUTION_AND_CONTROL,
	ENGINE_FIRE_PROTECTION_SYSTEM,
	CARGO_FIRE_PROTECTION_SYSTEM,
	FUEL_QUANTITY_SYSTEM,
	HYDRAULIC_SYSTEM_CONTROL,
	WWFDS_EAI_AND_CIPS,
	WINDOW_HEAT_SYSTEM,
	DISPLAY_CREW_ALERTING_SYSTEM,
	LANDING_GEAR_INDICATION_AND_CONTROL,
	LIGHTING_SYSTEMS,
	THRUST_MANAGEMENT_FUNCTION,
	FLIGHT_MANAGEMENT_FUNCTION_AND_NDB,
	WATER_AND_WASTE_SYSTEMS,
	ACMF,
	CENTRAL_MAINTENANCE_COMPUTING_SYSTEM,
	NITROGEN_GENERATION_SYSTEM,
	DOORS_INIDICATION_AND_CONTROL
};


// each Common Computing Resource (CCR) cabinet holds 8 GPMs each with a specific set and amount of hosted applications
// Defining the ints here ensures each GPM module has the appropriate amount of hosted applications

enum GPM_INDEX {
	// Left side modules
	L1 = 12,
	L2 = 2,
	L3 = 1,
	L4 = 7,
	L5 = 3,
	L6 = 5,
	L7 = 3,
	L8 = 3,

	// Right side modules
	R1 = 10,
	R2 = 2,
	R3 = 2,
	R4 = 4,
	R5 = 3,
	R6 = 6,
	R7 = 2,
	R8 = 1
};

class GeneralProcessingModule {
public:
	GeneralProcessingModule(int maxApplications, const std::vector<HOSTED_APPLICATIONS>& applications) {
		if (this->applicationsAmount() != maxApplications) {
			// TODO: This should throw an error at compile time not in the sim
			Console::log("Size mismatch in the constructor");
			return;
		}

		this->applications = applications;
	}

	auto applicationsAmount() -> int {
		return this->applications.size();
	};


private:
	std::vector<HOSTED_APPLICATIONS> applications = {};
};

inline static const std::unordered_map<GPM_INDEX, GeneralProcessingModule> gpmsLeft = {
	{L1, GeneralProcessingModule(12, {
		EQUIPMENT_COOLING_SYSTEM,
		INTEGRATED_COOLING_SYSTEM,
		POWER_ELECTRONICS_COOLING_SYSTEM,
		CIRCUIT_BREAKER_INDICATION_AND_CONTROL,
		ELECTRICAL_POWER_DISTRIBUTION_AND_CONTROL,
		ENGINE_FIRE_PROTECTION_SYSTEM,
		FUEL_QUANTITY_SYSTEM,
		HYDRAULIC_SYSTEM_CONTROL,
		WWFDS_EAI_AND_CIPS,
		WINDOW_HEAT_SYSTEM,
		LANDING_GEAR_INDICATION_AND_CONTROL,
		DOORS_INIDICATION_AND_CONTROL
	})},

	{L2, GeneralProcessingModule(2, {
		DISPLAY_CREW_ALERTING_SYSTEM,
		LIGHTING_SYSTEMS
	})},

	{L3, GeneralProcessingModule(1, {
		DISPLAY_CREW_ALERTING_SYSTEM,
	})},

	{L4, GeneralProcessingModule(7, {
		CABIN_AIR_TEMPERATURE_CONTROL_SYSTEM,
		LOW_PRESSURE_SYSTEM,
		CIRCUIT_BREAKER_INDICATION_AND_CONTROL,
		ELECTRICAL_POWER_DISTRIBUTION_AND_CONTROL,
		HYDRAULIC_SYSTEM_CONTROL,
		DISPLAY_CREW_ALERTING_SYSTEM,
		LIGHTING_SYSTEMS,
	})},

	{L5, GeneralProcessingModule(3, {
		THRUST_MANAGEMENT_FUNCTION,
		FLIGHT_MANAGEMENT_FUNCTION_AND_NDB,
		WATER_AND_WASTE_SYSTEMS,
	})},

	{L6, GeneralProcessingModule(5, {
		SWITCHES_FLT_DECK_CONTROL_PANELS,
		ENGINE_FIRE_PROTECTION_SYSTEM,
		FUEL_QUANTITY_SYSTEM,
		FLIGHT_MANAGEMENT_FUNCTION_AND_NDB,
		WATER_AND_WASTE_SYSTEMS
	})},

	{L7, GeneralProcessingModule(3, {
		LANDING_GEAR_INDICATION_AND_CONTROL,
		CENTRAL_MAINTENANCE_COMPUTING_SYSTEM,
		DOORS_INIDICATION_AND_CONTROL
	})},

	{L8, GeneralProcessingModule(3, {
		COMMUNICATION_MANAGEMENT_FUNCTION,
		ELECTRICAL_POWER_DISTRIBUTION_AND_CONTROL,
		CARGO_FIRE_PROTECTION_SYSTEM
	})}
};

inline static const std::unordered_map<GPM_INDEX, GeneralProcessingModule> gpmsRight = {
	{R1, GeneralProcessingModule(10, {
		CIRCUIT_BREAKER_INDICATION_AND_CONTROL,
		ELECTRICAL_POWER_DISTRIBUTION_AND_CONTROL,
		ENGINE_FIRE_PROTECTION_SYSTEM,
		CARGO_FIRE_PROTECTION_SYSTEM,
		FUEL_QUANTITY_SYSTEM,
		WWFDS_EAI_AND_CIPS,
		LANDING_GEAR_INDICATION_AND_CONTROL,
		WATER_AND_WASTE_SYSTEMS,
		ACMF,
		DOORS_INIDICATION_AND_CONTROL
	})},

	{R2, GeneralProcessingModule(2, {
		INTEGRATED_COOLING_SYSTEM,
		DISPLAY_CREW_ALERTING_SYSTEM
	})},

	{R3, GeneralProcessingModule(2, {
		DISPLAY_CREW_ALERTING_SYSTEM,
		LIGHTING_SYSTEMS
	})},

	{R4, GeneralProcessingModule(4, {
		POWER_ELECTRONICS_COOLING_SYSTEM,
		HYDRAULIC_SYSTEM_CONTROL,
		WINDOW_HEAT_SYSTEM,
		NITROGEN_GENERATION_SYSTEM,
		DOORS_INIDICATION_AND_CONTROL
	})},

	{R5, GeneralProcessingModule(3, {
		WINDOW_HEAT_SYSTEM,
		THRUST_MANAGEMENT_FUNCTION,
		FLIGHT_MANAGEMENT_FUNCTION_AND_NDB
	})},

	{R6, GeneralProcessingModule(6, {
		INTEGRATED_COOLING_SYSTEM,
		LOW_PRESSURE_SYSTEM,
		SWITCHES_FLT_DECK_CONTROL_PANELS,
		DISPLAY_CREW_ALERTING_SYSTEM,
		LIGHTING_SYSTEMS,
		WATER_AND_WASTE_SYSTEMS
	})},

	{R7, GeneralProcessingModule(2, {
		LANDING_GEAR_INDICATION_AND_CONTROL,
		CENTRAL_MAINTENANCE_COMPUTING_SYSTEM
	})},

	{R8, GeneralProcessingModule(1, {
		COMMUNICATION_MANAGEMENT_FUNCTION
	})},
};


class CommmonComputingResource {
public:

	CommmonComputingResource(std::unordered_map<GPM_INDEX, GeneralProcessingModule> gpms) : generalProcessingModules(gpms) {};
	auto isOn() -> bool;

	auto outPutPotential(PowerConditioningModule* pcm) -> double {
		return pcm->outputVoltage;
	};

	auto module(GPM_INDEX index) -> GeneralProcessingModule {
		return this->generalProcessingModules.at(index);
	}

	auto send_429(ARINC429Word* data) -> void {
		// Console::log("{}", data);
	}

	auto receive_429(ARINC429Word* data) -> double {
		return data->data;
	}

	auto send_664(ARINC664Word* data) -> void {
		// Console::log("{}", &data);
	}

	auto receive_664(ARINC664Word* data) -> uint8_t* {
		return data->data;
	}

private:
	PowerConditioningModule pcmA = PowerConditioningModule(false);
	PowerConditioningModule pcmB = PowerConditioningModule(false);

	std::unordered_map<GPM_INDEX, GeneralProcessingModule> generalProcessingModules;

};

class CommonCoreSystem {
	public:
		auto init() -> void;
		auto prepare() -> void;
		auto update(double deltaTime) -> void;
		auto reset(CommmonComputingResource* ccr) -> void;
	private:
		CommmonComputingResource ccrLeft = CommmonComputingResource(gpmsLeft);
		CommmonComputingResource ccrRight = CommmonComputingResource(gpmsRight);
		ERS ers;
		auto updateLVars() -> void;
		auto updateERS(double deltaTime) -> void;
};

